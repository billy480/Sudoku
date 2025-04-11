import QtQuick 2.15
import QtQuick.Controls 2.15

Window {
    visible: true
    width: 400
    height: 700
    property int level: 1
    property int selected_level:1

    ListModel{
        id:sudokuModel
        property int selectedIndex: -1 // indice du case choisi
        property int level:1

        Component.onCompleted:{
            let board =[
                5, 3, 0, 0, 7, 0, 0, 0, 0,
                6, 0, 0, 1, 9, 5, 0, 0, 0,
                0, 9, 8, 0, 0, 0, 0, 6, 0,
                8, 0, 0, 0, 6, 0, 0, 0, 3,
                4, 0, 0, 8, 0, 3, 0, 0, 1,
                7, 0, 0, 0, 2, 0, 0, 0, 6,
                0, 6, 0, 0, 0, 0, 2, 8, 0,
                0, 0, 0, 4, 1, 9, 0, 0, 5,
                0, 0, 0, 0, 8, 0, 0, 7, 9
            ];
            for (let i = 0; i < 81; i++) {
                sudokuModel.append({ "value": board[i], "isFixed": board[i] !== 0 ,"isError": false,"highlighted": false});
            }
        }
    }

    function checkErrors() {
            let rows = Array(9).fill().map(() => []);
            let cols = Array(9).fill().map(() => []);
            let blocks = Array(9).fill().map(() => []);

            // vider tous les marques d'erreurs
            for (let i = 0; i < 81; i++) {
                sudokuModel.set(i, { value: sudokuModel.get(i).value,isFixed:sudokuModel.get(i).isFixed, isError: false });
            }

            // Parcours le tableau et notez les numéros de cases
            for (let j = 0; j < 81; j++) {
                let val = sudokuModel.get(j).value;
                if (val === 0) continue; // négliger les cases nulls

                let row = Math.floor(j / 9);
                let col = j % 9;
                let block = Math.floor(row / 3) * 3 + Math.floor(col / 3);

                // marquer les positions que les numéros apparaissent
                rows[row].push({ val, index: j });
                cols[col].push({ val, index: j });
                blocks[block].push({ val, index: j });
            }

            //Signaler les doublons
            function markDuplicates(groupArray) {
                for (let group of groupArray) {
                    let map = {}; //Pour enregistrer l'emplacement de chaque valeur dans ce groupe
                    for (let cell of group) {
                        //si aucun enregistrement n'existe déjà pour ce numéro
                        if (!map[cell.val]) {
                            map[cell.val] = [cell.index];
                        } else {
                            map[cell.val].push(cell.index);
                        }
                    }
                    for (let val in map) {
                        if (map[val].length > 1) {
                            for (let idx of map[val]) {
                                let item = sudokuModel.get(idx);
                                sudokuModel.set(idx, {
                                                    value: item.value,
                                                    isFixed: item.isFixed,
                                                    isError: true,
                                                    highlighted: item.highlighted
                                                });
                            }
                        }
                    }
                }
            }

            // marquer erreur
            markDuplicates(rows);
            markDuplicates(cols);
            markDuplicates(blocks);
        }



    Grid {
        anchors.centerIn: parent
        columns: 9
        spacing: 0

        Repeater {
            model: sudokuModel
            delegate: Rectangle {
                width: 40
                height: 40

                property int row: index / 9
                property int col: index % 9

                border.color: "black"
                color: model.isError ? "red":(model.highlighted?"lightgray":"white")

                property bool isFocused: false  // Focalisation du case

                // les cotes du 3*3
                Rectangle {
                    anchors.fill: parent
                    color: model.isError ? "red" : (model.highlighted ? "lightgray" : "white")
                    border.color: "black"
                    border.width: 1
                }

                // top
                Rectangle {
                    visible: row % 3 === 0
                    anchors.top: parent.top
                    anchors.left: parent.left
                    anchors.right: parent.right
                    height: 2
                    color: "black"
                }

                // bot
                Rectangle {
                    visible: (row + 1) % 3 === 0
                    anchors.bottom: parent.bottom
                    anchors.left: parent.left
                    anchors.right: parent.right
                    height: 2
                    color: "black"
                }

                // gauche
                Rectangle {
                    visible: col % 3 === 0
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    width: 2
                    color: "black"
                }

                // droite
                Rectangle {
                    visible: (col + 1) % 3 === 0
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom
                    width: 2
                    color: "black"
                }


                Text {
                    anchors.centerIn: parent
                    text: model.value !== 0 ? model.value : ""
                    font.pointSize: 14
                    color: model.isFixed ? "black":"blue"
                    font.bold: true
                }

                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.LeftButton | Qt.RightButton
                    onClicked:(mouse)=> {
                        sudokuModel.selectedIndex = index;
                        if (mouse.button === Qt.RightButton) { // 'mouse' is a MouseEvent argument passed into the onClicked signal handler
                            if (sudokuModel.get(index).isFixed===false)
                                sudokuModel.get(index).value=0;
                                checkErrors();
                        } else if (mouse.button === Qt.LeftButton) {
                            if (sudokuModel.get(index).isFixed===false){
                                parent.forceActiveFocus(); // Focaliser rectangle actuel
                                parent.isFocused = true;
                                updateHighlighting();
                            }else{
                                parent.forceActiveFocus(); // Focaliser rectangle actuel
                                parent.isFocused = false;
                            }
                        }
                    }
                }
                Keys.onPressed: (event) => {
                    if (isFocused) {
                        let newValue = model.value;
                        let key = event.key - Qt.Key_0;

                        if (event.key === Qt.Key_Up) {
                            newValue = Math.min(model.value + 1, 9);
                        } else if (event.key === Qt.Key_Down) {
                            newValue = Math.max(model.value - 1, 0);
                        } else if (key >= 0 && key <= 9) {  // entrez par le clavier
                            newValue = key;
                        }else if (event.key=== Qt.Key_Backspace) {  // entrez par le clavier
                            if (sudokuModel.get(index).isFixed===false)
                                newValue=0;

                        }

                        sudokuModel.set(index, { value: newValue, isError: false }); // changez le numéro au case
                        checkErrors(); // vérifier si le case a été répété
                    }
                }
            }
        }
    }

    Rectangle {
        id: rectangle
        x: 140
        y: 650
        width: 120
        height: 40
        color: "#1ef03c"
        focus: true
        Text {
            anchors.centerIn: parent
            text: 'Envoyer le resultat'
            font.pointSize: 9
        }

        MouseArea {
            anchors.fill: parent
            focus:true
            onClicked: {
                checkwin();
            }
        }
    }

    function updateHighlighting() {
            if (sudokuModel.selectedIndex === -1) return;

            let selectedRow = Math.floor(sudokuModel.selectedIndex / 9);
            let selectedCol = sudokuModel.selectedIndex % 9;
            let selectedBlock = Math.floor(selectedRow / 3) * 3 + Math.floor(selectedCol / 3);

            for (let i = 0; i < 81; i++) {
                let row = Math.floor(i / 9);
                let col = i % 9;
                let block = Math.floor(row / 3) * 3 + Math.floor(col / 3);

                let shouldHighlight = (row === selectedRow || col === selectedCol || block === selectedBlock);
                sudokuModel.set(i, {
                    highlighted: shouldHighlight});
            }
    }




    function checkwin(){
        for (let i = 0; i < 81; i++) {
            if (sudokuModel.get(i).value===0 || sudokuModel.get(i).isError===true) {
                lostDialog.open()
                return;
            }
        }
        victoryDialog.open()
    }


    Dialog {
        id: victoryDialog
        title: "🎉 Il a gagné!"
        modal: true
        standardButtons: Dialog.Ok  // button de OK
        contentItem: Text {
            text: "🎉 Il a gagné wowowowowowowow!"
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
        }

        onAccepted: {
            console.log("le joueur a dit OK");
            // reset le jeux
        }
    }

    Dialog {
        id: lostDialog
        title: "C'est mort ~_~"
        modal: true
        standardButtons: Dialog.Ok  // button de OK
        contentItem: Text {
            text: "C'est mort ~_~"
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
        }

        onAccepted: {
            console.log("le joueur a dit OK");
            // reset le jeux
        }
    }

    Rectangle {
        id: rectangle1
        x: 18
        y: 12
        width: 364
        height: 83
        color: "#ffffff"
        border.width: 1

        Text {
            id: _text1
            anchors.fill: parent
            anchors.leftMargin: 107
            anchors.rightMargin: -90
            anchors.topMargin: 0
            anchors.bottomMargin: 66
            text: qsTr("C'est un jeu de sudoku. ")
            font.pixelSize: 12
            lineHeight: 1.1
        }

        Text {
            id: _text2
            x: 39
            y: 40
            width: 317
            height: 16
            text: qsTr(" Changez les en tapant les flèches haut et bas")
            font.pixelSize: 12
        }

        Text {
            id: _text3
            x: 81
            y: 23
            text: qsTr("Cliquez gauche pour choisir le case")
            font.pixelSize: 12
        }

        Text {
            id: _text4
            x: 95
            y: 62
            text: qsTr("Cliquez droite pour éliminer")
            font.pixelSize: 12
            horizontalAlignment: Text.AlignHCenter
        }
    }

    Rectangle {
        id: level1
        x: 50
        y: 575
        width: 60
        height: 40
        color: "#eeefe034"
        focus: true
        Text {
            text: "débutant"
            anchors.centerIn: parent
            color: selected_level === 1 ? "red" : "black"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                levelnow.getcurrentlevel();
                levelnow.setCurrentlevel(1);
                selected_level=1;
            }
            focus: true
        }
    }

    Rectangle {
        id: level2
        x: 130
        y: 575
        width: 60
        height: 40
        color: "#eeefe034"
        focus: true
        Text {
            text: "facile"
            anchors.centerIn: parent
            color: selected_level === 2 ? "red" : "black"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                levelnow.getcurrentlevel();
                levelnow.setCurrentlevel(2);
                selected_level=2;
            }
            focus: true
        }
    }

    Rectangle {
        id: level3
        x: 210
        y: 575
        width: 60
        height: 40
        color: "#eeefe034"
        focus: true
        Text {
            text: "normale"
            anchors.centerIn: parent
            color: selected_level === 3 ? "red" : "black"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                levelnow.getcurrentlevel();
                levelnow.setCurrentlevel(3);
                selected_level=3;
            }
            focus: true
        }
    }

    Rectangle {
        id: level4
        x: 290
        y: 575
        width: 60
        height: 40
        color: "#eeefe034"
        focus: true
        Text {
            text: "expert"
            anchors.centerIn: parent
            color: selected_level === 4 ? "red" : "black"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                levelnow.getcurrentlevel();
                levelnow.setCurrentlevel(4);
                selected_level=4;
            }
            focus: true
        }
    }

    Connections {
        target: levelnow
        function onBoardChanged() {
            sudokuModel.clear();
            let newBoard = levelnow.getBoard();  // obtenir nouveau tableau

            for (let i = 0; i < 81; i++) {
                sudokuModel.append({
                    "value": newBoard[i],
                    "isFixed": newBoard[i] !== 0,
                    "isError": false,
                    "highlighted": false
                });
            }
        }
    }
}



