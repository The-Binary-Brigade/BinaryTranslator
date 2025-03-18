#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

const string charSet = "CharacterSet.csv";

static char convertToLower(string text) {
    // Function to take first character of string and convert it to lowercase
    char charToConvert = text[0];
    return tolower(charToConvert);
};

// Function to Translate binary to text

static void convertToText() {
    string binaryToCovert;

    //recive Inputs
    cout << "Enter the ASCII binary that you want to convert: ";
    getline(cin, binaryToCovert);
    cout << endl;

    ifstream File(charSet);

    //Remove Whitespace from the binary
    binaryToCovert.erase(remove_if(binaryToCovert.begin(), binaryToCovert.end(), 
    [](unsigned char c) { return std::isspace(c); }), binaryToCovert.end());

    for (size_t i = 0; i < binaryToCovert.size(); i += 8) {
        string c = binaryToCovert.substr(i, 8);

        string Line;
        string Text;
        string Binary;
        
        File.clear();
        File.seekg(0, ios::beg);

        while (getline(File, Line)) {
            stringstream StringStream(Line);

            getline(StringStream, Text, ',');
            getline(StringStream, Binary, ',');

            if (Binary == c) {
                cout << Text;
                break;
            }
        }
    }

    cout << endl;
    
}
// Function to Translate to binary

static void convertToBinary() {
    // Function to Translate to binary
    string textToConvert;

    // Receive Inputs
    cout << "Enter the text you want to convert to binary: ";
    getline(cin, textToConvert);
    ifstream File(charSet);

    for (char& c : textToConvert) {
        string Line;
        string Binary;
        string SymbolStr;
        char Symbol;

        File.clear();
        File.seekg(0, ios::beg);

        // Search the file for the Symbol

        while (getline(File, Line)) {
            stringstream StringStream(Line);

            getline(StringStream, SymbolStr, ',');
            char Symbol = SymbolStr[0];
            getline(StringStream, Binary, ',');

            // if the correct symbol is found, output the binary
            if (Symbol == c) {
                cout << Binary << " ";
            }
        }
    }

    cout << endl;

};

int main() {
    string modeSelection;

    cout << "Select the mode you'd like to use!" << endl;
    while (true) {
        cout << "Valid modes are 'B' (text to binary) and 'T' (binary to text)" << endl;
        cout << "Selection: ";
        getline(cin, modeSelection);
        switch (convertToLower(modeSelection)) {
            case 'b':
                convertToBinary();
                return 0;
            case 't':
                convertToText();
                return 0;
            default:
                continue;
        }
    }
}