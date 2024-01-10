# Procedurally-Generated-Maze-Game
C++ project using Object Oriented Programming, Graph Implementation through adjacency lists, modified Breadth First Search algorithm, and terminal animations. (Version 2 will have a dedicated GUI using QT C++ framework)

## How to play
This game works by randomly generating a number maze of N x N size, with the goal of navigating from the top left square, to the bottom right square.
Each square has a number which represents the distance you're able to move in one of 4 directions: up, down, left, or right.
A move is only valid if you remain within the bounds of the grid.
For example, if the square you're in is labeled 4, you can move four squares up, down, left, or right, as long as you remain within the grid.
The maze is guranteed to have at least one solution, but will often have several different paths.
This program will always output the most efficient solution, that is the one that solves the maze in the least number of moves.

It becomes a lot more clear with an example, check out this video of me playing the game! (The instructions are also presented in the program)

## How to run

1) Download the program

   I recommend cloning the repository using the Github CLI:
   > gh repo clone Alex-Ishmael/Procedurally-Generated-Maze-Game

   You can also clone by copy and pasting this command in your terminal:
   > git clone https://github.com/Alex-Ishmael/Procedurally-Generated-Maze-Game.git

2) Build the program by compiling the files in the workspace folder and running main.cpp:

   This can be done by any C++ compiler.
   
   If you do not have a C++ compiler installed I recommend using VS code and this [guide](https://code.visualstudio.com/docs/languages/cpp)
    
   Once installed you can run the program by clicking the play button in the top right corner (the correct json task settings are included in the .vscode folder):
   
   ![image](https://github.com/Alex-Ishmael/Procedurally-Generated-Maze-Game/assets/92725864/b0c123b8-a3c7-4903-b191-3e5554d6f509)

   You can also run from the terminal using this command (if you followed the guide above)
   > cl /EHsc main.cpp maze.cpp graph.cpp utilities.cpp
   > main

4) Follow the instructions on the screen once the executable opens

## How it works

The program constructs a Maze object of a user defined size, which is constructed from a N x N matrix with randomly generated values filling each entry. Since the generation is random, not every maze has a solution, so the maze object is ran with the solving function and regenerated until a maze with a valid solution is generated. The Maze object is then converted into an undirected, unweighted graph, using the graph constructor from the Graph class which takes a Maze object as the input. The graph implementation is done through an adjacency list. This data structure was chosen as it allows the program to conserve space and easily represent the edge relationships between different vertices. There are four possible movement options from each square in the maze, up, down, left, or right. Depending on the value and location of the current square not all these moves are legal as they may put the player out of bounds, so edges are only created if a move keeps the player within bounds.

The program then runs the Breadth First Search algorithm which is the ideal algorithm for finding shortest paths in undirected, unweighted graphs. BFS allows every vertex of the graph to be explored allowing the computer to try every possibility of moves. This is the only way to find the shortest move as relying on greedy algorithms such as employing a strategy where you prioritize squares with the largest value to traverse the most distance, are proven to not work in all cases and can often provide innacurate answers. BFS allows the computer to try all possible moves to ensure that we have the most optimal answer. The BFS algorithm is modified to keep track of each vertex's predecessor by pushing it into a vector, so that when the target vertex is found, it can follow the predecessor vector to work its way backwards to the start. The vector is then reveresed and returned.

The program then allows the user to view an animation of the most optimal solution. This is achieved through clever use of colored text, sleeping the program, and repeatedly printing the board and clearing the screen to simulate movement.

BFS allows the program to find solutions in O(V + E) time, which in the context of this program is O(2n) => O(n). 
   

   

