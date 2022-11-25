#include "lexique_ligne.h"

Lexique_lignes :: Lexique_lignes() : Lexique() {

}

int Lexique_lignes :: addWord(string word, int line){
    Lexique::addWord(word);

    vector<int> lignes;

    if(lexique_lignes.find(word) != lexique_lignes.end()){
        lignes = lexique_lignes.at(word);
    }

    lignes.push_back(line);
    removeWord(word);
    lexique_lignes.insert({word, lignes});

    return 0;
}

void Lexique_lignes :: printLexique(){
    map<string, vector<int>>::iterator it;
    vector<int>::iterator lines_iterator;
    int size = 0;

    cout << "Lexique :" << endl;

    for(it = lexique_lignes.begin(); it != lexique_lignes.end(); it++){
        size++;
        cout << it -> first << " : ";
        for(lines_iterator = (it -> second).begin(); lines_iterator != (it -> second).end(); lines_iterator++){
            if(lines_iterator != (it -> second).begin()){
                cout << ", " ;
            }
            cout << *lines_iterator;
        }
        cout << endl;
    }

    cout << "Total entries : " << size << " words" << endl;

}

int Lexique_lignes :: removeWord(string word){
    lexique_lignes.erase(word);
    return 0;
}

int Lexique_lignes :: read_files(string path){

    string content; // file's content

    readFileIntoString(path, content);  // reading the file in content
    
    // Was the file empty ?
    if(content.size() == 0){
        return 0;;
    }

    string word;
    int line = 1;

    // Reading the file, spliting it word by word, and adding it to the lexique
    for(int i = 0; i < content.size(); i++){
        if(content[i] == ' ' 
        || content[i] == '\n' 
        || content[i] == ';' 
        || content[i] == '.' 
        || content[i] == ',' 
        || content[i] == '!' 
        || content[i] == '?'
        || content[i] == '_'
        || content[i] == '"'
        || content[i] == '{'
        || content[i] == '}'
        || content[i] == '('
        || content[i] == ')'
        || content[i] == '-'
        || content[i] == ':'
        || content[i] == '\''
        ){
            if(word.size() != 0){
                addWord(word, line);
                word = "";
            }
        } else {
            word += content[i];
        }

        if(content[i] == '\n'){
            line++;
        }
    }

    if(word.size() != 0){
        addWord(word, line);
    }

    return 0;
}