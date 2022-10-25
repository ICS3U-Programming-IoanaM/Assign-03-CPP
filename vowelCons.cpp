// Copyright (c) 2022 Ioana Marinescu All rights reserved.
// Created By: Ioana Marinescu
//
// Date: Oct. 8, 2022
// programs that lets you guess the randomly generated number


#include <iostream>

bool replay() {
    // variables
    std::string yesNo;
    bool repeat, loop;
    loop = true;

    // asks for user input
    std::cout << "Would you like to check another letter? [n/y] ";
    std::cin >> yesNo;

    
    while (loop) {
        if (yesNo == "y" || yesNo == "Y") {
            repeat = true;
            loop = false;
        } else if (yesNo == "n" || yesNo == "N") {
            repeat = false;
            loop = false;
        } else {
            std::cout << "please pick either no or yes.\n";
            std::cout << "Would you like to check another letter? [n/y] ";
            std::cin >> yesNo;
            loop = true;
        }
    }
    return repeat;
}

// gets user input
std::string userInput() {
    // variables
    std::string input;

    // asks for input
    std::cout << "\nEnter a letter: ";
    std::cin >> input;

    // returns input
    return input;
}

// checks if user imputed valid letter
std::string isValid(std::string userString) {
    // variables
    bool repeat = true;

    // loops function until input is valid
    while (repeat) {
        // string is longer than 1 char
        if (userString.length() != 1) {
            std::cout << "Please enter ONE letter.\n";
            userString = userInput();

            // string is 1 char long
        } else {
            // user didn't input a letter
            if (userString[0] < 65 ||
            (userString[0] > 90 && userString[0] < 97)
            || userString[0] > 122) {
                std::cout << userString
                << " is not a letter. Please try again\n";
                userString = userInput();

            // user input is valid
            } else {
                repeat = false;
            }
        }
    }
    return userString;
}

int main() {
    // variables
    std::string userLetter;
    std::string vowels[] = {"a", "A", "e", "E", "i", "I", "o", "O", "u", "U"};
    bool isVowel, repeat;

    // assigning variables (not user input)
    isVowel = false;

    do {
        // getting user input
        userLetter = userInput();

        userLetter = isValid(userLetter);

        // checks if user letter is a vowel
        for (int i = 0; i < 9; i++) {
            if (vowels[i] == userLetter) {
                isVowel = true;
            }
        }

        // checks if user letter is a y
        if (userLetter == "y" || userLetter == "Y") {
            std::cout << userLetter << " is both a vowel and a consonant\n";

            // checks if user letter is a vowel
        } else if (isVowel) {
            std::cout << userLetter << " is a vowel\n";
            isVowel = false;

            // if user letter is a consonant
        } else {
            std::cout << userLetter << " is a consonant\n";
        }

        // if user wants to replay
        replay();
    } while (repeat);
}
