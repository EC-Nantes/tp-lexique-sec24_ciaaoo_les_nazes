#include <iostream>
#include "lexique.h"

int main(int argv, const char * args[]){
    Lexique lexique;

    lexique.read_file(args[1]);
    lexique.printLexique();

    return 0;
}