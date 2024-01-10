#pragma once
#include "graph.h"
#include "maze.h"
#include <queue>
#include <iostream>

using namespace std;

Graph::Graph(Maze maze) {
    int mazeLength = maze.getMazeLength();
    graphLength_ = mazeLength * mazeLength;
    vector<vector<int>> adjList;

    // Initializing adj list
    for (unsigned int i = 0; i < graphLength_; i++) {
        vector<int> temp;
        adjList.push_back(temp);
    }
    adjList_ = adjList;
    maze_ = maze;
    
    // Create edges for legal moves
    for (int row = 0; row < mazeLength; row++) {
        for (int col = 0; col < mazeLength; col++) {
            int value = maze.mazeValue(row, col);
            // If within the boundaries of the board, create edge going down by the value of the current square
            if (row + value < mazeLength) {
                adjList_[row * mazeLength + col].push_back((row + value) * mazeLength + col);
            }
            // If within the boundaries of the board, create edge going up by the value of the current square
            if (row - value >= 0) { 
                adjList_[row * mazeLength + col].push_back((row - value) * mazeLength + col);
            }
            // If within the boundaries of the board, create edge going right by the value of the current square
            if (col + value < mazeLength) {
                adjList_[row * mazeLength + col].push_back(row * mazeLength + (col + value));
            }
            // If within the boundaries of the board, create edge going left by the value of the current square
            if (col - value >= 0) {
                adjList_[row * mazeLength + col].push_back(row * mazeLength + (col - value));
            }
        }
    }
}

vector<int> Graph::BFS() {

    // Keeps track of visited vertices
    vector<bool> visited(graphLength_, false);

    // Queues up vertices and their outgoing edges
    queue<int> queue;

    // Keeps track of which vertex we took an outgoing edge from to reach our current vertex
    vector<int> predecessor_path(graphLength_, -1);

    // The vector the function will return that holds the shortest path in order 
    vector<int> shortest_path;

    // The target is the bottom rightmost vertex (graphLength - 1) and our start is the top leftmost vertex (0)
    int target = graphLength_ - 1; 
    int start = 0;

    visited[start] = true;
    queue.push(start);

    while (!queue.empty()) {
        // Make the front of the queue our current value and remove it from the queue
        int curr = queue.front();
        queue.pop();

        if (curr == target) {
            // Since the predecessor was stored in the predecessor_path vector, we can simply follow it backwards until we hit -1
            // This works as reaching -1 means the vertex has reached the start as it has no predecessor 
            int vertex = target;
            while (vertex != -1) {
                shortest_path.push_back(vertex);
                vertex = predecessor_path[vertex];
            }
            // We then reverse our vector so that the start and end points line up correctly
            reverse(shortest_path.begin(), shortest_path.end());
            return shortest_path;
        }

        // Iterate through our current vertex's adjacency list
        // If the vertex has not been visited, add their neighbors to the queue, and mark them as visited
        for (int vertex : adjList_[curr]) {
            if (!visited[vertex]) { 
                queue.push(vertex);
                visited[vertex] = true;

                // Store the predecessor (our current value) in path[x] so that we can backtrack when we find our target
                predecessor_path[vertex] = curr; 
            }
        }
    }
    return shortest_path;
}


vector<vector<int>> Graph::getAdjList() {
    return adjList_;
}

void Graph::printAdjList() {
    cout << "AdjList: " << endl;
    cout << "graphLength_: " << graphLength_ << " sqrt: " << sqrt(graphLength_) << endl;
    for (unsigned int row = 0; row < sqrt(graphLength_); row++) {
        for (unsigned int col = 0; col < sqrt(graphLength_); col++) {
            cout << maze_.mazeValue(row, col) << " -> ";
            vector<int> temp = adjList_[row * sqrt(graphLength_) + col];
            for (unsigned int i = 0; i < temp.size(); i++) {
                int r = temp[i] / sqrt(graphLength_); // row
                int c = temp[i] % (int) sqrt(graphLength_); // col
                cout << temp[i] << " " << "[" << r << "," << c << "] = " << maze_.mazeValue(r,c) << " ";
            }
            cout << "\n" << endl;
        }
    }
}

