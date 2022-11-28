#include <iostream>
#include <Windows.h>

#include "lexique.h"

int main(int argv, const char * args[]){
    SetConsoleOutputCP(CP_UTF8);

    Lexique lexique;
    Lexique lexique2;

    lexique.read_file(args[1]);
    lexique2.read_file(args[1]);

    lexique+=lexique2;

    lexique.printLexique();
    lexique2.printLexique();
    return 0;
}