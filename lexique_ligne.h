#include "lexique.h"
#include <vector>

class Lexique_lignes : public Lexique {
    protected :
        map<string, vector<int>> lexique_lignes;

    public :
        Lexique_lignes();
        int addWord(string word, int line);
        int removeWord(string word);
        int read_files(string path);
        void printLexique();
};