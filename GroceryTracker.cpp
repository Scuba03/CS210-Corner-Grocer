// GroceryTracker.cpp
// Implementation of the GroceryTracker class methods.

#include "GroceryTracker.h"

// Constructor calls LoadData to read file and populate map
GroceryTracker::GroceryTracker(const std::string& inputFileName) {
    LoadData(inputFileName);
}

// Private method: reads each word from the input file and tallies counts
void GroceryTracker::LoadData(const std::string& inputFileName) {
    std::ifstream inputFile(inputFileName);
    std::string item;

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open input file: " << inputFileName << std::endl;
        return;
    }

    // Read each word (item) and increment its count in the map
    while (inputFile >> item) {
        frequencyMap[item]++;
    }

    inputFile.close();
}

// Menu Option 1: search for a specific item's frequency
int GroceryTracker::GetItemFrequency(const std::string& item) const {
    // Use .find() to safely check if the item exists in the map
    auto it = frequencyMap.find(item);
    if (it != frequencyMap.end()) {
        return it->second;
    }
    return 0; // Item not found
}

// Menu Option 2: print each item and its numeric frequency
void GroceryTracker::PrintFrequencyList() const {
    std::cout << "\n--- Item Frequency List ---\n";
    for (const auto& pair : frequencyMap) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    std::cout << "---------------------------\n";
}

// Menu Option 3: print a text-based histogram using asterisks
void GroceryTracker::PrintHistogram() const {
    std::cout << "\n--- Item Frequency Histogram ---\n";
    for (const auto& pair : frequencyMap) {
        std::cout << pair.first << " ";
        // Print one asterisk per occurrence
        for (int i = 0; i < pair.second; i++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    std::cout << "--------------------------------\n";
}

// Creates backup file frequency.dat with item-frequency pairs
void GroceryTracker::CreateBackupFile(const std::string& outputFileName) const {
    std::ofstream outputFile(outputFileName);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Could not create backup file: " << outputFileName << std::endl;
        return;
    }

    for (const auto& pair : frequencyMap) {
        outputFile << pair.first << " " << pair.second << std::endl;
    }

    outputFile.close();
    std::cout << "Backup file 'frequency.dat' created successfully.\n";
}