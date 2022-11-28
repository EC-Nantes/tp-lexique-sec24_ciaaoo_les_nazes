#include "lexique.h"

Lexique :: Lexique(){

}

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
                addWord(word);
                word = "";
            }
        } else {
            word += content[i];
        }
    }

    if(word.size() != 0){
        addWord(word);
    }

    return 0;
}

void Lexique :: printLexique(void){

    map<string, int>::iterator it;
    int size = 0;

    cout << "Lexique :" << endl;

    for(it = words.begin(); it != words.end(); it++){
        size++;
        cout << it -> first << " : " << it -> second << endl;
    }

    cout << "Total entries : " << size << " words" << endl;
}

int Lexique::addWord(string word) {
    int occurence;

        if(words.find(word) == words.end()){
        words.insert({ word, 1 });
    }
    else{
        occurence = words.at(word) + 1;
        removeWord(word);
        words.insert({word, occurence});
    }
    return occurence;
}

int Lexique::removeWord(string word){
     if(words.find(word) != words.end()){
        words.erase(word);
        return 0;
    }
    else 
        return 1;
}

void Lexique::operator+=(Lexique lexique2){
    map<string, int>::iterator it;
    for(it = lexique2.getWords().begin(); it != lexique2.getWords().end(); it++){
        string word = it->first;
        int occurence = it-> second;
        if(this -> words.find(word) !=  this -> words.end()){
                occurence += this -> words.at(word);
                int booli = removeWord (word);
                words.insert({word, occurence});
        }
        else{
            words.insert({word, occurence});
        }
    }
}