#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

const string charSet = "CharacterSet.csv";

static char convertToLower(string text) {
    // Function to take first character of string and convert it to lowercase
    char charToConvert = text[0];
    return tolower(charToConvert);
};

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
                break;
            case 't':
                cout << "Not implemented!";
                break;
            default:
                continue;
        }
    }
}