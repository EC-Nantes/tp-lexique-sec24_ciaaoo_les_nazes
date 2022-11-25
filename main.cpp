#include <iostream>
#include <Windows.h>

#include "lexique.h"

int main(int argv, const char * args[]){
    SetConsoleOutputCP(CP_UTF8);

    Lexique lexique;

    lexique.read_file(args[1]);
    lexique.printLexique();

    return 0;
}