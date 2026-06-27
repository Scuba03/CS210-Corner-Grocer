// GroceryTracker.h

// Header file defining the GroceryTracker class with public and private sections.



#ifndef GROCERYTRACKER_H

#define GROCERYTRACKER_H



#include <iostream>

#include <fstream>

#include <map>

#include <string>



class GroceryTracker {

public:

    // Constructor: reads input file and builds frequency map

    GroceryTracker(const std::string& inputFileName);



    // Menu option 1: returns frequency of a specific item

    int GetItemFrequency(const std::string& item) const;



    // Menu option 2: prints all items with their frequencies

    void PrintFrequencyList() const;



    // Menu option 3: prints histogram of all items

    void PrintHistogram() const;



    // Creates the backup frequency.dat file

    void CreateBackupFile(const std::string& outputFileName) const;



private:

    // Map to store item name and its frequency count

    std::map<std::string, int> frequencyMap;



    // Reads the input file and populates frequencyMap

    void LoadData(const std::string& inputFileName);

};



#endif#pragma once
