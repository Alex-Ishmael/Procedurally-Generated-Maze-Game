#pragma once
#include "maze.h"
#include "graph.h"
#include "utilities.h"

#include <stdlib.h>
#include <chrono>
#include <thread> 
#include <conio.h>
#include <set>
#include <utility>
#include <cstdlib> 
#include <iostream> 
#include <time.h> 
#include <string>

Maze::Maze() {}

Maze::Maze(int N) {
    vector<vector<int>> user_maze (N, vector<int> (N, 0));
    mazeLength_ = N;
    maze_ = user_maze;
    generateMaze();
}

void Maze::generateMaze() {
    srand(time(0));
    int range;

    // To put a ceiling on the highest possible square value
    if (mazeLength_ > 10) {
        range = 10;
    } else {
        range = mazeLength_;
    }
    for (int row = 0; row < mazeLength_; row++) {
        for (int col = 0; col < mazeLength_; col++) {
            int value = rand() % range; // Randomizes each square of our maze
            while (value == 0) {    // If value is set to 0, we randomize until it is set to a different int, as 0 is not a legal move
                value = rand() % range;
            }
            maze_[row][col] = value;
        }
    }
}

void Maze::printMaze() {
     for (int row = 0; row < mazeLength_; row++) {
        for (int j = 0; j < mazeLength_; j++) {
            if (row == 0) {
                if (j == 0) {
                    cout << "+---";
                } else{
                    cout << "----";
                }
            } else {
                cout << "+---";
            }
        }
        cout << "+" << endl;
        for (int col = 0; col < mazeLength_ ; col++) {
            if (col == 0) {
                cout << "| " << maze_[row][col] << " | ";
            } else {
                cout << maze_[row][col] << " | ";
            }
        }
        cout << " " << endl;
    }
    for (int j = 0; j < mazeLength_; j++) {
        if (j == 0) {
            cout << "+---";
        } else{
            cout << "----";
        }
    }
    cout << "+" << endl;
}

int Maze::getMazeLength() {
    return mazeLength_;
}

int Maze::mazeValue(int row, int col) {
    return maze_[row][col];
}

bool Maze::solve() {
    Graph g(*this); 
    solution_ = g.BFS();

    // If the returned solution path is empty we know there is not possible solutions
    if (solution_.empty()) {
        return false;
    }
    return true;
}

// Animates the solution; 'skip' is used to avoid printing out certain pieces of text in the introduction
void Maze::animate(bool skip) {
    #define RESET   "\033[0m"
    #define RED     "\033[31m"    
    #define BLINK   "\033[5m"      

    string yes_or_no;
    if (skip) {
        goto skipped;
    }

    cout << "\n\n "<< endl;
    textScroller("Would you like to see the shortest solution? (Type 'yes' or 'no'): ");
    cin >> yes_or_no;

    for (auto& i : yes_or_no) {
        i = tolower(i);
    }

    // Returns if the user requests to not see the animated solution
    if (yes_or_no != "yes") {
        textScroller("Have a lovely day!");
        return;
    } 

    skipped:

    system("cls");  
    printMaze();
    this_thread::sleep_for(1s);
    system("cls");

    set<pair<int, int>> coords;

    // Repeatedly prints and clears the terminal, while highlighting the current square in red to animate the solution in the terminal
    for (unsigned int i = 0; i < solution_.size(); i++) {
        int solution_row = solution_[i] / mazeLength_;  // The row of the current solution square
        int solution_col = solution_[i] % mazeLength_;  // The col of the current solution square

        pair<int, int> temp(solution_row, solution_col);
        coords.insert(temp);
        for (int row = 0; row < mazeLength_; row++) {
            for (int j = 0; j < mazeLength_; j++) {
                if (row == 0) {
                    if (j == 0) {
                        cout << "+---";
                    } else{
                        cout << "----";
                    }
                } else {
                    cout << "+---";
                }
            }
            cout << "+" << endl;
            for (int col = 0; col < mazeLength_ ; col++) {

                // Checks to see if the current row and col match the solution row and column and if true prints the value in red
                if (col == 0) {
                    if (solution_row == row && solution_col == col) {
                        cout << "| " << RED << maze_[row][col] << RESET <<" | ";
                        continue;

                    }
                    cout << "| " << maze_[row][col] << " | ";
                } else {
                    if (solution_row == row && solution_col == col) {
                        cout << RED << maze_[row][col] << RESET <<" | ";
                        continue;
                    }
                    cout << maze_[row][col] << " | ";
                }
            }
            cout << " " << endl;
        }
        for (int j = 0; j < mazeLength_; j++) {
            if (j == 0) {
                cout << "+---";
            } else{
                cout << "----";
            }
        }
        cout << "+" << endl;
        this_thread::sleep_for(1.25s);
        system("cls");  
    }    

        
    for (int row = 0; row < mazeLength_; row++) {
        for (int j = 0; j < mazeLength_; j++) {
            if (row == 0) {
                if (j == 0) {
                    cout << "+---";
                } else{
                    cout << "----";
                }
            } else {
                cout << "+---";
            }
        }
        cout << "+" << endl;
        for (int col = 0; col < mazeLength_ ; col++) {
            pair<int, int> curr(row,col);
            if (col == 0) {
                if (coords.find(curr) != coords.end()) {
                    cout << "| " << RED << maze_[row][col] << RESET <<" | ";
                    continue;

                }
                cout << "| " << maze_[row][col] << " | ";
            } else {
                 if (coords.find(curr) != coords.end()) {
                    cout << RED << maze_[row][col] << RESET <<" | ";
                    continue;
                }
                cout << maze_[row][col] << " | ";
            }
        }
        cout << " " << endl;
    }
    for (int j = 0; j < mazeLength_; j++) {
        if (j == 0) {
            cout << "+---";
        } else{
            cout << "----";
        }
    }
    cout << "+" << endl;

    textScroller("\nThis maze was solveable in ");
    cout << RED << solution_.size() << RESET; 
    textScroller(" moves!\n");

    // Avoid printing the thanks for playing in the tutorial example
    if (skip == true) {
        return;
    }
    textScroller("Thanks for playing and have a nice day :D\n");
}

