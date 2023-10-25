#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void displayLines(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File '" << filename << "' not found" << endl;
        return;
    }

    string line;
    int lineCount = 0;

    while (getline(file, line)) {
        cout << line << endl;
        lineCount++;

        if (lineCount % 24 == 0) {
            cout << "Press Enter to continue..." << endl;
            cin.get(); // Wait for the user to press Enter
        }
    }

    file.close();
}

int main() {
    while (true) {
        string filename;

        cout << "Enter File Name : ";
        getline(cin, filename);

        displayLines(filename);

        char cont;
        cout << "Press Enter to continue or enter 'q' to exit: ";
        cin.get(cont);
        if (cont == 'q') {
            break;
        }
    }

    return (0) ;
}
