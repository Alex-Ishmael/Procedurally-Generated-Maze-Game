#include "maze.h"
#include "graph.h"
#include "utilities.h"
#include <chrono>
#include <thread> 

using namespace std;

int main() {

    // Prints introduction, rules, and returns the user defined size for their maze (see utilities for more info)
    int maze_size = intro();
    system("cls");

    Maze user_defined_maze(maze_size);
    bool solution = user_defined_maze.solve();

    // Mazes that are generated may be unsolveable, so the program continues to generate mazes until it finds a solveable one
    while (!solution) {
        this_thread::sleep_for(1s);
        user_defined_maze.generateMaze();
        solution = user_defined_maze.solve();
    }

    user_defined_maze.printMaze();
    this_thread::sleep_for(15s); // Time to let the user figure the maze out
    user_defined_maze.animate(0);


    
    return 0;
}