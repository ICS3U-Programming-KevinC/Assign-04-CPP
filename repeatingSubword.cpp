// Copyright (c) 2022 Kevin Csiffary All rights reserved.
//
// Created by: Kevin Csiffary
// Date: Nov. 23, 2022
// This program asks the user for a string, the length of the subword,
// and how many times to repeat it, then cuts out the subword and repeats it
// the correct number of times

#include <iostream>

// initialize all required integers
int numRepeatInt;
int subwordLenInt;

// initialize all required floats
float numRepeatFloat;
float subwordLenFloat;



void Loop(std::string string) {
    // loop through and repeat the sub word the user specified amount of times
    for (int counter = 0; counter < numRepeatInt; counter++) {
        std::cout << string;
    }
    // once the loop has completed add extra line
    std::cout << "\n";
}

std::string GetSubword(std::string string) {
    // cuts everything beyond the subword length
    string.erase(subwordLenInt, 9999999);
    return string;
}

// calls all of the functions in the correct order
int main() {
    // initialize all required strings
    std::string userString;
    std::string numRepeatStr;
    std::string subwordLenStr;

    //// INPUT ////
    // get the user string
    std::cout << "Please enter a string: ";
    std::cin >> userString;

    // get the amount of times the word should be repeated
    std::cout << "Please enter the number of copies: ";
    std::cin >> numRepeatStr;

    // get the length of the subword
    std::cout << "Please enter the length of the subword: ";
    std::cin >> subwordLenStr;

    //// ERROR CHECKING ////
    try {
        // casts the user inputs to integers
        numRepeatInt = std::stoi(numRepeatStr);
        subwordLenInt = std::stoi(subwordLenStr);

        // casts the user inputs to floats
        numRepeatFloat = std::stof(numRepeatStr);
        subwordLenFloat = std::stof(subwordLenStr);

        // checks if the inputted number is a decimal
        if ((numRepeatFloat != numRepeatInt) |
            (subwordLenFloat != subwordLenInt)) {
            std::cout << "Please enter a valid integer\n";
            exit(0);
        } else {
            // checks if the inputted number is negative
            if ((numRepeatInt <= 0) | (subwordLenInt <= 0)) {
                std::cout << "Please enter a positive integer\n";
                exit(0);
            }
        }
        // catch errors
    } catch (std::invalid_argument) {
        std::cout << "Please enter a valid integer\n";
        exit(0);
    }
    std::string shortString = GetSubword(userString);
    Loop(shortString);
}
