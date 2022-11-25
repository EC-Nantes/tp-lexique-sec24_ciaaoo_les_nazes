#define lexique_h

#include <stdio.h>
#include <iostream>
#include <map>
#include "utilitaire.hpp"

using namespace std;

class lexique{
protected:
    map<string, int> words;

public:
    lexique();
    int addWord(string);
int removeWord(string);
    int read_file(string path);        // Reading the specified file and adding it's words
};