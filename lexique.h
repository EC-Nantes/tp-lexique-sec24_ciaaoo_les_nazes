#define lexique_h

#include <stdio.h>
#include <iostream>
#include <map>
#include "utilitaire.hpp"

using namespace std;

class Lexique{
protected:
    map<string, int> words;

public:
    Lexique();
    int addWord(string word);
    int removeWord(string word);
    int read_file(string path);        // Reading the specified file and adding it's words
    void printLexique(void);        // Printing every word in words 
    Lexique operator+=(Lexique lexique2);

    // accesseurs en lecture
    map<string, int> getWords(){ return words;}

};

