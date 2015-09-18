//
// Created by Aadam on 8/20/2015.
//

#include "BarChart.h"

using namespace std;

int BarChart::getIndex(const char &character) {
    int charValue = int(character); //get the ASCII numeric value
    return charValue - startingValue; //return the correct index value
}

bool BarChart::readFile() {
    ifstream infile (filePath);
    if (infile) {
        cout << "Reading file!" << endl;
        char character;
        while (infile.get(character)) {
            ++numOfCharacters;
            int index = getIndex(character); //get the index for the character
            //so that characters like newline etc. can be ignored
            if (index >= 0 && index <= sizeOfArray) { ++numOfFrequency[index]; }
        }
        infile.close();
        cout << "File read complete!" << endl  << endl;
        return true;
    }
    else if (filePath == "") {
        cout << "You didn't provide a path to the file." << endl
        << "Please provide the path by using setPath() data member." << endl;
    }
    else { cout << "Can't Open File : " << filePath <<  endl; }
    return false;
}

void BarChart::setPath() {
    cout << "Please provide the full path to the desired file." << endl;
    char character;
    string path;
    //We need to format the path so that every '\' is replaced with '\\'
    while (cin.get(character)) {
        if (character == '\\') { path.push_back(character); } //if we encounter a '\', it will be pushed back two time
        if (character == '\n') break;
        path.push_back(character);
    }
    filePath = path;
}

void BarChart::setPath(const string &path) {
    filePath = path;
}

void BarChart::compareCharacters(const string &string1) {
    string valid = validString(string1); //remove the duplicates from the string
    int max = getMaxFrequency(valid); //get the greatest frequency number
    printBars(valid, max); //print bars according to the max, it is dynamic or you can say relative to the frequency
    cout << "Press Enter to continue.....";
    if (cin.get() != '\n') { cin.ignore(100, '\n'); } //wait for user to see, discard junk
    cout << string(75,'\n'); //Clear Screen
}

string BarChart::validString(const string &string1) {
    string valid;
    char character;
    valid.push_back(string1[0]); //enter first character,in reverse find, we dont't have to search its duplicate
    for (auto i = 1; i < string1.length(); i++) {
        character = string1[i];
        //find the duplicate from the current index to the start, reverse find
        if (string1.rfind(character, (unsigned long) (i-1)) == string::npos) {
            valid.push_back(character);
        }
    }
    return valid;
}

int BarChart::getMaxFrequency(const string &string1) {
    int max = 0;
    int frequency = 0;
    char character;
    for (auto i = 0; i < string1.size(); i ++) {
        character = string1[i];
        frequency = numOfFrequency[getIndex(character)];
        if (frequency > max) {
            max = frequency;
        }
    }
    return max;
}

void BarChart::printBars(const string &string1, const int &max) {
    const double maxBarLength = 60;
    double multiple = maxBarLength/max; //how much one bar represents
    int barLength = 0; //bar length for individual character
    int index;
    cout << endl << endl << string((unsigned long) (maxBarLength + 15), '-') << endl; //outer border
    for (auto i = 0; i < string1.length(); i++) {
        index = getIndex(string1[i]); //get the index of character
        barLength = int(round(numOfFrequency[index] * multiple)); //calculate the length of bar for this character
        string bar ((unsigned long) barLength,'='); //generate the bar
        cout << "|  " << string1[i] << " : " << setw(int(maxBarLength)) << left << bar << "  " << setw(4) << numOfFrequency[index] << " |"<< endl;
    }
    cout << string((unsigned long) (maxBarLength + 15), '-') << endl << endl; //outer border
}

void BarChart::help() {
    cout << "This program will read a file, whose path will be provided by you," << endl
    << "and it will process it to see how many characters are present in the file" << endl
    << "and how many times a character is used. Then it will prompt you to enter a" << endl
    <<  "sequence of characters. You will input the characters which you want to" << endl
    << "compare.  Then it will generate a simple bar to show the frequency of the" << endl
    << "characters. The bar will be created relatively, according to the frequency" << endl
    << "of the characters that you typed." << endl
    << "One more thing, when you give the path of the file using setPath(string) , " << endl
    << "Remeber to put double '\\' between the paths. e.g setPath (D:\\\\Workspace\\\\Clion\\\\file.txt)" << endl
    << "If you want to see this menu again, simply type 'help'" << endl
    << "If you want to QUIT the program, simplty type 'quit'" << endl << endl;
}
