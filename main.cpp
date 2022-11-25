#include <iostream>
#include "lexique.h"

int main(){
    Lexique lexique;

    lexique.read_file("tp-Lexique-fichiers/lesMiserables_A.txt");
    lexique.printLexique();
}