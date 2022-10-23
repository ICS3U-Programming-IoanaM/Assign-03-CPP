// Copyright (c) 2022 Ioana Marinescu All rights reserved.
// Created By: Ioana Marinescu
//
// Date: Oct. 8, 2022
// programs that lets you guess the randomly generated number


#include <iostream>

int main() {
    // variables
    std::string userLetter;
    std::string vowels[] = {"a", "A", "e", "E", "i", "I", "o", "O", "u", "U"};
    bool isVowel = false;

    // getting user input
    std::cout << "\nEnter a letter: ";
    std::cin >> userLetter;

    // checks if user letter is a vowel
    for (int i = 0; i < 9; i++) {
        if (vowels[i] == userLetter) {
            isVowel = true;
        }
    }

    // checks if user letter is a y
    if (userLetter == "y" || userLetter == "Y") {
        std::cout << userLetter << " is both a vowel and a consonant";

        // checks if user letter is a vowel
    } else if (isVowel) {
        std::cout << userLetter << " is a vowel";

    // if user letter is a consonant 
    } else {
        std::cout << userLetter << " is a consonant";
    }
}