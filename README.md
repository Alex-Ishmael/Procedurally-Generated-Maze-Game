# Procedurally-Generated-Maze-Game
C++ project using Object Oriented Programming, Graphs Implementation, and a modified BFS algorithm.

## How to play
This game works by randomly generating a number maze of N x N size, with the goal of navigating from the top left square, to the bottom right square.
Each square has a number which represents the distance you're able to move in one of 4 directions: up, down, left, or right.
A move is only valid if you remain within the bounds of the grid.
For example, if the square you're in is labeled 4, you can move four squares up, down, left, or right, as long as you remain within the grid.
The maze is guranteed to have at least one solution, but will often have several different paths.
This program will always output the most efficient solution, that is the one that solves the maze in the least number of moves.

It becomes a lot more clear with an example, check out this video of me playing the game!

## How to run

1) Download the program

I recommend cloning the repository using the Github CLI:
> gh repo clone Alex-Ishmael/Procedurally-Generated-Maze-Game

You can also clone by copy and pasting this command in your terminal:
>git clone https://github.com/Alex-Ishmael/Procedurally-Generated-Maze-Game.git

2) Build the program by compiling the files in the workspace folder and running main.cpp:

   If you do not have a C++ compiler installed I recommend using VS code and this [guide] (https://code.visualstudio.com/docs/languages/cpp)   
   Once installed you can run the program by clicking the play button in the top right corner (the correct json task settings are included in the .vscode folder):
   ![image](https://github.com/Alex-Ishmael/Procedurally-Generated-Maze-Game/assets/92725864/b0c123b8-a3c7-4903-b191-3e5554d6f509)

   You can also run from the terminal using this command (if you followed the guide above)
   > cl /EHsc main.cpp maze.cpp graph.cpp utilities.cpp
   > main

   
   

   

