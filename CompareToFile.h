//
// Created by Miles Mcgranahan on 8/7/24.
//

#ifndef COMPARETOFILE_H
#define COMPARETOFILE_H
#include <fstream>
#include <map>
//#include <iostream>
#include <string>
using namespace std;

class CompareToFile {
    map<string, int> wordFreq;
    map<string, int> wordStar;
    ifstream inFS;



public:
    void SetWord(const string &word);

    int CountOcc(const string &occ);

    void PrintAllWords();
    void PrintHisto();
    auto MakeList() -> void;




private:
    string setWord;
    int countWord = 0;
    int countAll = -1;
    char histo = '*';
    string addWord;



};



#endif //COMPARETOFILE_H
