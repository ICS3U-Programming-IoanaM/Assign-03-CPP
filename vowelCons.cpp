// Copyright (c) 2022 Ioana Marinescu All rights reserved.
// Created By: Ioana Marinescu
//
// Date: Oct. 8, 2022
// programs that lets you guess the randomly generated number


#include <iostream>

/*
# tells user if their input is valid
def is_valid(user_input):
    # variables
    invalid = True

    while invalid:
        # if user imputed multiple letters or symbols
        if len(user_input) > 1:
            print("Please input ONE character.")
            user_input = input("\nEnter a letter: ")

        # if user doesn't input anything
        elif len(user_input) == 0:
            print("Please type in a letter.")
            user_input = input("\nEnter a letter: ")

        else:
            character = ord(user_input)
            # checks if character is not a letter
            if character < 65 or (character > 90 and character < 97) or character > 122:
                print(f"{user_input} is not a letter. Please try again")
                user_input = input("\nEnter a letter: ")

            # checks if character is an accented letter
            elif character >= 192 and character <= 383:
                print("Letters can't be accented. Please try again.")
                user_input = input("\nEnter a letter: ")

            else:
                invalid = False
                return user_input
reference:
https://www.w3schools.com/cpp/cpp_strings_access.asp#:~:\
text=Note%3A%20String%20indexes%20start%20with,
is%20the%20second%20character%2C%20etc.
*/
std::string userInput() {
    std::string input;
    std::cout << "Enter a letter: ";
    std::cin >> input;
    return input;
}

bool isValid(std::string userString) {
    // string is longer than 1 char
    if (userString.length() != 1) {
        std::cout << "Please enter ONE letter.\n";

        // string is 1 char long 
    } else {
        // user didn't input a letter
        if (userString[0] < 65 || (userString[0] > 90 && userString[0] < 97) || userString[0] > 122) {
            std::cout << userString << " is not a letter. Please try again\n";
            userInput();

            // if user imputed an accented letter 
        } else if (userString[0] >= 192 && userString[0] <= 383) {
            std::cout << "Letters can't be accented. Please try again.\n";
            userInput();
        }
    }
    return true;
}

int main() {
    // variables
    std::string userLetter;
    std::string vowels[] = {"a", "A", "e", "E", "i", "I", "o", "O", "u", "U"};
    bool isVowel = false;

    // getting user input
    userLetter = userInput();

    isValid(userLetter);

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

    // if user letter is a consonant
    } else {
        std::cout << userLetter << " is a consonant\n";
    }
}
