# Projet_Sudoku

Membres du projet: Beilin XU, PADRON SIFUENTES Adriana, NAHMIAS Eva

## Name
Jeu du sudoku

## Description
Le jeu a été développé soigneusement en utilisant le code Cpp et la plateforme Qt creator. La grille du jeu a été conçu à partir du langage QML et l'interaction entre Cpp et l'interface se basent sur le fichier level.cpp. Dans le fichier de level.cpp, on a utiliser les bonnes pratiques de développement présentées durant les cours (gestion propre de la mémoire allouée dynamiquement, gestion des exceptions…).

Le code complet est sous le dossier de sudoku1, où le .gitignore se situe. Il faut le QT creator pour le complier.
Par contre, Le logiciel peut être lancé tout seul en démarrant le fichier appsudoku1.exe sur le dossier de Logiciel(Si jamais vous n'arrivez pas à compiler le code).

## Visuals

L'interface de jeu est comme suit. 
！[image](https://github.com/billy480/Sudoku/blob/main/img/interface.png)

En haut du jeu, on a l'explication des intructions pour jouer. En bas, on a 4 boutons jaunes pour choisir le niveau de difficulté des grilles.
！[image](https://github.com/billy480/Sudoku/blob/main/img/choose_level.png)

Lorsque l'on choisit une case, les autres cases concernées deviennent grises comme un hint.
！[image](https://github.com/billy480/Sudoku/blob/main/img/chosen.png)

Lorsque l'on note un chiffre sur la case, la case devient rouge si les chiffres de la grille ne remplissent pas les contraintes du jeu.
！[image](https://github.com/billy480/Sudoku/blob/main/img/false.png)

L'utilisateur est aussi capable de vérifier si la partie est gagnée ou erronée en cliquant sur le bouton 'envoyer le résultat' en bas de l'interface.
！[image](https://github.com/billy480/Sudoku/blob/main/img/envoyer_res.png)



## Installation
Ouvrez le fichier sudoku1 sous la plateforme de Qt. 
Démarrez 'release' ou 'debug', le jeu marche tout simplement.

## Acknowledgment
Merci pour l'aide du prof S. Derrode pendant les séances du BE. Son enseignement nous a permis d'acquérir des connaissances indispensables pour commencer à coder en Cpp et en Qt creator. Mieux encore, c'est lui qui nous a donné l'idée originale de faire ce jeu.

## Project status
Terminé pour l'instant.

Dans le futur, on cherche à ajouter une autre fonctionnalité, celle de sauvegarder une partie en cours pour la continuer plus tard. Une autre fonctionnalité serait celle de concevoir un outil IA pour générer la grille.


