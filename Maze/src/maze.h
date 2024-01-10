#pragma once
#ifndef maze_H
#define maze_H

#include <vector>

using namespace std;

class Maze {
    public:
        Maze();

        // Maze constructor that makes a maze of size N x N
        Maze(int N); 

        // Generates the maze
        void generateMaze();

        // Returns the mazeLength
        int getMazeLength();

        // Returns the value in the maze square
        int mazeValue(int row, int col);

        // Solves the maze by converting it into an adjacency list graph representation and running a modified BFS search (see Graph class)
        // Returns if its solveable or not
        bool solve();

        // Animates the solution; 'skip' is used to avoid printing out certain pieces of text in the introduction
        void animate(bool skip);

        // Prins the Maze
        void printMaze();

    private:
        vector<vector<int>> maze_;
        int mazeLength_;      // N x N
        vector<int> solution_;
};

#endif