#include <iostream>
#include <fstream>
using namespace std;

bool isIdentifier(string s) {
    if(s.length() == 0) return false;

    // First character check
    if (!((s[0] >= 'A' && s[0] <= 'Z') ||
          (s[0] >= 'a' && s[0] <= 'z') ||
          s[0] == '_'))
        return false;

    // Remaining characters check
    for (int i = 1; i < s.length(); i++) {
        if (!((s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] >= 'a' && s[i] <= 'z') ||
              (s[i] >= '0' && s[i] <= '9') ||
              s[i] == '_'))
            return false;
    }
    return true;
}

int main() {

    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile) {
        cout << "input.txt file not found!" << endl;
        return 0;
    }

    string input;
    inFile >> input;   // file theke read

    cout << "Read from input.txt: " << input << endl;

    if (isIdentifier(input)) {
        cout << "It is a valid identifier." << endl;
        outFile << "Valid Identifier" << endl;
    }
    else {
        cout << "It is not a valid identifier." << endl;
        outFile << "Invalid Identifier" << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}

