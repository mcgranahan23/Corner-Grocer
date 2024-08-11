//
// Created by Miles Mcgranahan on 8/7/24.
//

#include "CompareToFile.h"
#include <iostream>
#include <string>
using namespace std;
ofstream outFS;

void CompareToFile::SetWord(const string &word) { setWord = word; }

void CompareToFile::MakeList() {
    inFS.open("Project_Three_Input_File.txt");
    if (!inFS) {
        cerr << "Failed to open file." << endl;
    return; }

    while (!inFS.fail()) {
        inFS >> addWord;
        if (wordFreq.count(addWord) == 0) {
            wordFreq.emplace(addWord, 1);
            wordStar[addWord] = 1;
        }
        else if (wordFreq.count(addWord) == 1) {
            ++wordFreq.at(addWord);
            wordStar[addWord]++;
        }
    }
    inFS.close();
    outFS.open("frequency.dat");
    for (auto it=wordFreq.begin(); it!=wordFreq.end(); ++it) {
        outFS << it->first << " => " << it->second << '\n';
    }
    outFS.close();
}


int CompareToFile::CountOcc(const string &occ) {
    int countWord = 0;
    string addWord;
    inFS.open("Project_Three_Input_File.txt");
    if (!inFS) {
        cerr << "Failed to open file." << endl;
        return -1; }
    while (inFS >> addWord) {
        if (addWord == occ) {
            ++countWord;
        }
    }
    inFS.close();
    return countWord;
    }

void CompareToFile::PrintHisto() {


    for (auto &pair : wordStar) {
        cout << pair.first << " => ";
        for(int i = 0; i < pair.second; i++) {
            cout << '*';
        }
        cout << '\n';
    }
    cout << endl;

}
void CompareToFile::PrintAllWords() {

    for (auto it=wordFreq.begin(); it!=wordFreq.end(); ++it) {
        cout << it->first << " => " << it->second << '\n';

    }
    cout << endl;
    inFS.close();
    }


