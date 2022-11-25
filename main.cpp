#include <iostream>
#include <Windows.h>

#include "lexique_ligne.h"

int main(int argv, const char * args[]){
    SetConsoleOutputCP(CP_UTF8);

    Lexique_lignes lexique;


    lexique.read_files(args[1]);
    lexique.printLexique();

    return 0;
}