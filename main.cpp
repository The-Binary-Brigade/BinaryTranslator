#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    string Text = "";
    string Filename = "Charaterset.csv";

    // Receive Inputs
    cout << "Enter The Text you want converting: \n";
    getline(cin, Text);

    // Function to Translate to binary
    ifstream File(Filename);

    for (char& c : Text) {
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
}