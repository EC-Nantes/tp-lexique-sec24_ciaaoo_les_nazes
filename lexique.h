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

    int read_file(string path);        // Reading the specified file and adding it's words
};