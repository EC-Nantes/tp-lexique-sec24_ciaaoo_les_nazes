#include "lexique.h"

int lexique :: read_file(string path){

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