#include "lexique.h"

int Lexique :: read_file(string path){

    string content; // file's content

    readFileIntoString(path, content);  // reading the file in content
    
    // Was the file empty ?
    if(content.size() == 0){
        return 1;   // file empty
    }

    string word;

    // Reading the file, spliting it word by word, and adding it to the lexique
    for(int i = 0; i < content.size(); i++){
        if(content[i] == ' ' || content[i] == '\n'){
            addWord(word);
            word = "";
        } else {
            word += content[i];
        }
    }

    return 0;
}

void Lexique :: printLexique(void){

    map<string, int>::iterator it;

    cout << "Lexique :" << endl;

    for(it = words.begin(); it != words.end(); it++){
        cout << it -> first << " : " << it -> second << endl;
    }

    cout << "finished" << endl;
}

int Lexique::addWord(string word) {
    int occurence;
    if(words.find(word) == words.end()){
        words.insert({ word, 1 });
    }
    else{
        occurence = words.at(word);
        occurence += 1;
        words.insert({word, occurence});
    }
}