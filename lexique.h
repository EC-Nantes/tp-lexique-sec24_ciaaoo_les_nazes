#define lexique_h

#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

class lexique{
protected:
    map<string, int> words;

public:
    lexique();
    int addWord(string);
    int removeWord(string);
    read_file();
};