#pragma once
#ifndef Utilities_h
#define Utilities_h

#include <string>

using namespace std;

// Utility function to print text out with a smooth animation
void textScroller(string input);

// Function that prints the introduction to the program including the rules and an animated example maze to demonstrate how the game works. 
// The function also reads the user input for the size of their puzzle and returns it at the end of the execution.
int intro();

#endif