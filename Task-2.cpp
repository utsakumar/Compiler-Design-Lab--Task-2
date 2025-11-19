#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
 using namespace std;
 int main() {
    ifstream inFile("sample.txt");
    ofstream outFile("output.txt");
    if (!inFile) {
        cout << "sample.txt file not found!" << endl;
        return 0;
    }
    vector<string> tokens;
    char c;
    string temp = "";
    // -------- Tokenize process -------
    while (inFile.get(c)) {
        if (isspace(c)) {
            if (!temp.empty()) {
                tokens.push_back(temp);
                temp = "";
            }
        }
        else if (isalnum(c) || c == '_') {
            temp += c;
        }
        else {
            if (!temp.empty()) {
                tokens.push_back(temp);
                temp = "";
            }
            string s(1, c);
            tokens.push_back(s);  // symbol
        }
    }
    if (!temp.empty())
        tokens.push_back(temp);
    // ------------ OUTPUT -------------
    cout << "TOKENS:\n";
    outFile << "TOKENS:\n";
    for (string t : tokens) {
        cout << t << endl;
        outFile << t << endl;
    }
    cout << "\nSYMBOL TABLE:\n";
    outFile << "\nSYMBOL TABLE:\n";
    // ------------- Symbol Table ------------
    for (string t : tokens) {
        if (t == "int" || t == "return" || t == "cout" || t == "main")
        {
            cout << t << "  --> Keyword\n";
            outFile << t << "  --> Keyword\n";
        }
        else if (isdigit(t[0]))
        {
            cout << t << "  --> Number\n";
            outFile << t << "  --> Number\n";
        }
        else if (t.size() == 1 && !isalnum(t[0]))
        {
            cout << t << "  --> Symbol\n";
            outFile << t << "  --> Symbol\n";
        }
        else
        {
            cout << t << "  --> Word\n";
            outFile << t << "  --> Word\n";
        }
    }
    inFile.close();
    outFile.close();
    return 0;
}

