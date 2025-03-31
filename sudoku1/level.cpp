#include "level.h"
#include <iostream>
using namespace std;

level::level(QObject *parent):QObject(parent),currentlevel(1),board(nullptr)  {
    generateBoard(currentlevel);
}

level::~level(){
    delete[] board;
}

Q_INVOKABLE int level::getcurrentlevel() const{
    cout<<"22"<<endl;
    return currentlevel;
}

Q_INVOKABLE void level::setCurrentlevel(int level){
    if(currentlevel!=level){
        loadlevel(level);
    }
}

Q_INVOKABLE QVector<int> level::getBoard()const{
    return QVector<int>(board,board+81);
}

void level::loadlevel(int level){
    try{
        generateBoard(level);   //creer une tableau
        currentlevel=level;
        cout<<"11"<<endl;
        emit levelChanged();
        emit boardChanged();
    }catch (int currentlevel){
        if (currentlevel>4){
            cout<<"Board level out of bound"<<endl;
            }
    }
}

void level::generateBoard(int level){//ici, on génère et change les grilles
    if (board) {
        delete[] board;
    }

    board = new int[81];

    switch (level) {
    case 1: {
        int tempBoard[81] = {
            5, 3, 0, 0, 7, 0, 0, 0, 0,
            6, 0, 0, 1, 9, 5, 0, 0, 0,
            0, 9, 8, 0, 0, 0, 0, 6, 0,
            8, 0, 0, 0, 6, 0, 0, 0, 3,
            4, 0, 0, 8, 0, 3, 0, 0, 1,
            7, 0, 0, 0, 2, 0, 0, 0, 6,
            0, 6, 0, 0, 0, 0, 2, 8, 0,
            0, 0, 0, 4, 1, 9, 0, 0, 5,
            0, 0, 0, 0, 8, 0, 0, 7, 9
        };
        memcpy(board, tempBoard, 81 * sizeof(int));
        break;
    }
    case 2: {
        int tempBoard[81] = {
            8, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 3, 6, 0, 0, 0, 0, 0,
            0, 7, 0, 0, 9, 0, 2, 0, 0,
            0, 5, 0, 0, 0, 7, 0, 0, 0,
            0, 0, 0, 0, 4, 5, 7, 0, 0,
            0, 0, 0, 1, 0, 0, 0, 3, 0,
            0, 0, 1, 0, 0, 0, 0, 6, 8,
            0, 0, 8, 5, 0, 0, 0, 1, 0,
            0, 9, 0, 0, 0, 0, 4, 0, 0
        };
        memcpy(board, tempBoard, 81 * sizeof(int));
        break;
    }
    case 3: {
        int tempBoard[81] = {
            0, 0, 0, 0, 0, 0, 2, 0, 0,
            0, 0, 0, 6, 0, 0, 0, 0, 3,
            0, 0, 0, 0, 0, 0, 0, 9, 0,
            0, 0, 1, 0, 0, 5, 0, 0, 8,
            0, 0, 0, 0, 0, 0, 0, 4, 0,
            0, 0, 0, 3, 0, 0, 0, 0, 6,
            0, 0, 0, 2, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 9, 0, 0, 0,
            0, 0, 4, 0, 0, 0, 0, 0, 0
        };
        memcpy(board, tempBoard, 81 * sizeof(int));
        break;
    }
    case 4: {
        int tempBoard[81] = {
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 3, 0, 8, 5,
            0, 0, 1, 0, 2, 0, 0, 0, 0,
            0, 0, 0, 5, 0, 7, 0, 0, 0,
            0, 0, 4, 0, 0, 0, 1, 0, 0,
            0, 9, 0, 0, 0, 0, 0, 0, 0,
            5, 0, 0, 0, 0, 0, 0, 7, 3,
            0, 0, 2, 0, 1, 0, 0, 0, 0,
            0, 0, 0, 0, 4, 0, 0, 0, 9
        };
        memcpy(board, tempBoard, 81 * sizeof(int));
        break;
    }
    default:
        std::cerr << "Invalid level selected!" << std::endl;
        memset(board, 0, 81 * sizeof(int));  // clavier null
        break;
    }
}


