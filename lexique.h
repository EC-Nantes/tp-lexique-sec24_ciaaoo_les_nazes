#define lexique_h
#include <stdio.h>
#include <iostream>
using namespace std;
#include <map>

class lexique{
protected:
    map<string, int> words;

public:

    read_file();
};