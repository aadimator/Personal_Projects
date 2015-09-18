//
// Created by Aadam on 8/20/2015.
//

#ifndef BARCHART_P_2_6_BARCHART_H
#define BARCHART_P_2_6_BARCHART_H

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

class BarChart {
public:
    BarChart() {}; //default constructor
    BarChart(const std::string& path) { filePath = path;} //initialize filePath
    bool readFile(); //read characters from file and strore their frequency in numOfFrequency[]
    void setPath(); //set filePath using console, it will automatically add '\\'
    void setPath(const std::string& pathToFile); //remeber to put double '\\' between the directories
    void compareCharacters(const std::string &); //compare the characters of the string, see which one has greater frequency
    void help(); //to show help menu
    int getNumOfCharacters() const { return numOfCharacters; } //num of characters in the file

private: //helper functions
    int getIndex(const char &); //It will return the index for the particular character for numOfFrequency[]
    std::string validString(const std::string&); //It will remove duplicate characters
    int getMaxFrequency (const std::string& ); //It will return the max amount od frequency of the characters
    void printBars(const std::string &, const int &); //It will print the Bars according to the max and frequencies

private: //data members
    int numOfCharacters = 0; //how many characters were processed from the file
    const int startingValue = 32; //32 = Space, ASCII Printable characters
    static const int sizeOfArray = 94; //There are 94 printable ASCII characters starting from 32 to 126
    int numOfFrequency [sizeOfArray] = {0}; //32(Space) is at index 0 of Array
    std::string filePath; //store path to the file
};


#endif //BARCHART_P_2_6_BARCHART_H
