// main.cpp
// Entry point for the Corner Grocer item-tracking program.
// Displays a menu and processes user choices using the GroceryTracker class.

#include "GroceryTracker.h"
#include <iostream>
#include <string>
#include <limits>

// Displays the main menu options to the user
void DisplayMenu() {
    std::cout << "\n========== Corner Grocer Menu ==========\n";
    std::cout << "1. Search for item frequency\n";
    std::cout << "2. Display all item frequencies\n";
    std::cout << "3. Display histogram\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice (1-4): ";
}

int main() {
    // Create a GroceryTracker object, which loads data from input file
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt");

    // Automatically create the backup frequency.dat file at program start
    tracker.CreateBackupFile("frequency.dat");

    int choice = 0;

    // Main program loop ? runs until user selects option 4 to exit
    while (choice != 4) {
        DisplayMenu();

        // Input validation: ensure the user enters a valid integer
        if (!(std::cin >> choice)) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Flush bad input
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        if (choice == 1) {
            // Option 1: Search for a specific item
            std::string searchItem;
            std::cout << "Enter the item to search for: ";
            std::cin >> searchItem;

            int freq = tracker.GetItemFrequency(searchItem);
            if (freq > 0) {
                std::cout << searchItem << " was purchased " << freq << " time(s).\n";
            }            else {
                std::cout << searchItem << " was not found in today's records.\n";
            }

        }        else if (choice == 2) {
            // Option 2: Print full frequency list
            tracker.PrintFrequencyList();

        }        else if (choice == 3) {
            // Option 3: Print histogram
            tracker.PrintHistogram();

        }        else if (choice == 4) {
            // Option 4: Exit
            std::cout << "Exiting program. Goodbye!\n";

        }        else {
            // Handle out-of-range numbers
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}