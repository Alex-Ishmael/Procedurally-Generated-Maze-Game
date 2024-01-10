#pragma once
#include "Utilities.h"
#include "Maze.h"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

void textScroller(string input) {
    for (unsigned int i = 0; i < input.size(); i++) {
        cout << input[i];
        this_thread::sleep_for(25ms);
    }
}

// The introduction, split up into smaller strings, to ensure that sentences display nicely without cutoff.
static const string INTRO_1 = "\nHello!\n\n";
static const string INTRO_2 = "Would you like to see the instructions (Type 'yes' or 'no') ";
static const string INTRO_3 = "\nThis game works by randomly generating a number maze of N x N size, with the goal of navigating from the top left square, to the bottom right square.\n"; 
static const string INTRO_4 = "Each square has a number which represents the distance you're able to move in one of 4 directions: up, down, left, or right.\n";
static const string INTRO_4A = "\nA move is only valid if you remain within the bounds of the grid.\n";
static const string INTRO_4B = "For example, if the square you're in is labeled 4, you can move four squares up, down, left, or right, as long as you remain within the grid.\n";
static const string INTRO_4C = "\nThe maze is guranteed to have at least one solution, but will often have several different paths.\n";
static const string INTRO_4D = "This program will always output the most efficient solution, that is the one that solves the maze in the least number of moves.\n"; 
static const string INTRO_4E = "\nHere is an exmaple of a 5 x 5 maze that will be randomly generated and solved:\n\n";
static const string INTRO_5 = "\nOk your turn!\n";
static const string INTRO_6 = "\nPlease select the size of your maze by inputing a number between 3 - 100. The maze will be of size N x N, where N is the number inputed.\n";
static const string INTRO_6A = "It is recommended to start off on smaller mazes before working up to larger sizes!\n\n";
static const string INTRO_7 = "Size:";
static const string INTRO_8 = "\nGood luck :)";




int intro() {

    textScroller(INTRO_1);
    textScroller(INTRO_2);

    // Asks if the user would like to skip the instructions and example
    string yes_or_no;
    cin >> yes_or_no; 
    for (auto& i : yes_or_no) { // makes the input lowercase to account for case sensitivity
        i = tolower(i);
    }

    Maze example_maze(5);
    if (yes_or_no != "yes") {
        goto skip;
    }
    system("cls");
    textScroller(INTRO_3);
    textScroller(INTRO_4);
    textScroller(INTRO_4A);
    textScroller(INTRO_4B);
    textScroller(INTRO_4C);
    textScroller(INTRO_4D);
    textScroller(INTRO_4E);

    // Creates the example maze
    bool solution = example_maze.solve(); 

    // Mazes that are generated may be unsolveable, so the program continues to generate mazes until it finds a solveable one
    while (!solution) { 
        this_thread::sleep_for(1s);
        example_maze.generateMaze();
        solution = example_maze.solve();
    }

    this_thread::sleep_for(5s); // Sleep to allow users to read the instructions
    example_maze.printMaze();
    this_thread::sleep_for(10s);
    example_maze.animate(true); 

    textScroller(INTRO_5);

skip:
    
    textScroller(INTRO_6);
    textScroller(INTRO_6A);
    textScroller(INTRO_7);

    // Asks user for the size of their maze
    int user_defined_size = 0;
    cin >> user_defined_size;
    textScroller(INTRO_8);
    this_thread::sleep_for(1s);

    return user_defined_size;
}