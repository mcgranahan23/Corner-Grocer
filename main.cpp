#include <iostream>
#include <string>
#include "CompareToFile.h"
#include <fstream>

using namespace std;

void menuPrompt(int select = 0) {

    do {
        cout << "Please enter a selection 1-4." << endl;
        cout << "1.) Search for an item.\n"
                "2.) Print a list of all items purchased.\n"
                "3.) Print items purchased as histogram.\n"
                "4.) Quit." << endl;
        //cin >> select;
        if (select < 0 or select > 4) {
            cout << "Invalid input. Please try again." << endl;
        }
    } while(select < 0 or select > 4);
}

int main() {
    int select, count;
    ifstream inFS;
    string wordSearch;
    inFS.open("Project_Three_Input_File.txt");
    CompareToFile newWord;
    newWord.MakeList();

    cin.exceptions(ios::failbit);

    do {
        try {
            menuPrompt();
            cin >> select;
        } catch (ios_base::failure) {
            cin.clear();
            cin.ignore(1000, '\n');
        }

        switch (select) {
            case 1:
                cout << "Enter a word to search: " << endl;
                cin >> wordSearch;
                count = newWord.CountOcc(wordSearch);
                if (count == 1) {
                    cout << "The word " << wordSearch << " appears in the file " << count << " time.\n" << endl;
                }
                else {
                    cout << "The word " << wordSearch << " appears in the file " << count << " times.\n" << endl;
                }
            break;
            case 2:
                newWord.PrintAllWords();
                break;
            case 3:
                newWord.PrintHisto();
                break;
            case 4:
                cout << "Goodbye." << endl;
                return 0;
            default:
                cout << "Invalid selection." << endl;
                cin.clear();
        }
    } while (select != 4);

    return 0;
}
