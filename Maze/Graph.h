#pragma once
#ifndef Graph_h
#define Graph_h

#include <vector>
#include "Maze.h"

using namespace std;

class Graph {
    public:

        // Graph constructor
        Graph(Maze maze);

        // Modified BFS search to find and return the shortest path 
        vector<int> BFS();

        // Returns the adjacency list
        vector<vector<int>> getAdjList();

        // Prints the adjacency list
        void printAdjList();

    private:
        vector<vector<int>> adjList_;
        int graphLength_ = 0;
        Maze maze_;
};

#endif