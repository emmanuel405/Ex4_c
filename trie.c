# include <stdio.h>
# include "trie.h"
# include <string.h>
# define FROMASCIITOZERO 97
# define SUMOFLETTER 26
# define WORD 30
/*
    ASCII:
A = 65 ... Z = 90
a = 97 ... z = 122
*/


/*
the method recived a word and node* to the head of the trie and insert the word to the trie.
*/
void addWord(char* word, node* trie){
    int i;
    node* n=trie;
    for(i=0; i<strlen(word); i++){
        n= addLetter(word[i], n);
    }
    // the counter of the word in the node thet represent the last letter in the word so add 1 to count.
    ++(n->count);
}
/*
the method recived a letter and node* and insert this letter to children if not exist 
and return node* to the new chidren. else return node* to the exist children.
*/ 
node* addLetter(char letter, node* n){
    //if the letter not exist yet.
    if(n->children[letter-FROMASCIITOZERO]==NULL){
        //make a new node.
        node* add=(node*)malloc(sizeof(node));
        //insert to the new node.
        add->letter=letter;
        add->count=0;
        add->children=NULL;
        //insert the new node to the parent
        &(n->children[letter-FROMASCIITOZERO])= add;
        return add;
    }
    else return &(n->children[letter-FROMASCIITOZERO]);

    }

}

void printUp(node* trie){

}

void printDown(node* trie){
    node* head=trie;
    char[WORD] word;
    if ((trie->children)==null)
    {
        if((trie->count)!=0){
            printf("%s  %d",word,trie->count );

        }
    }
    
    for(int i=SUMOFLETTER-1; i>=0; i--){
        while ((head->children)!=null)
        {
                 
        }
        
        head->children[i]
    }
    
}
void printDownHelper(node* parent,node* Child, char* word ){
    
}
