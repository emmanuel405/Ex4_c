# include <stdio.h>
# include "trie.h"
# include <string.h>
# define FROMASCIITOZERO 97
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
    node* n = trie;
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
        if(NULL == add){
            printf("ERROR\n");
            return NULL;
        }
        //insert to the new node.
        add->letter=letter;
        add->count=0;
        add->children=NULL;
        //insert the new node to the parent
        &(n->children[letter-FROMASCIITOZERO])= add;
        return add;

        /*
        need to :=> free(add);
        */
    }
    else return &(n->children[letter-FROMASCIITOZERO]);

    }

void inorder(node *trie, char *word2print);
void disorder(node *trie, char *word2print);
char* subString(char *w, int i);

/*
This method print the 'trie' in ascending alphabet order.
node:
letter, count, children [*]
*/
void printUp(node* trie, char* word2print){
    if(NULL == trie){
        print("ERROR, the trie is null !\n");
        return;
    }
    else
        void inorder(trie, word2print);
}
/*
This method print the 'trie' in descending alphabet order.
*/
void printDown(node* trie, char* word2print){
     if(NULL == trie){
        print("ERROR, the trie is null !\n");
        return;
    }
    else
        void disorder(trie, word2print);
}
////////////////////////////
//*** private methodes ***//
////////////////////////////

/*
This method decrease 'i' letter from string 'w' by the end.
*/
char* subString(char *w, int i){
    int length = strlen(w);
    if(i <= length){
        int diff = length - i;
        w[diff] = '\0';
        return w;
    }
    return NULL;
}
/*
 * check what the word that we need to print
 */
void inorder(node *trie, char *word2print){
    int numOfChild = strlen(trie->children);
    if(numOfChild == 0){ // he is a leaf
        if(trie->count != 0) {
            printf("%s %d\n", word2print, trie->count); // print the word & num how many time it's writted
        }
        if(strlen(word2print) > 1)
            subString(word2print, 1);
        return;
    }
    else{
        int i = 0;
        while(i<numOfChild){ // while he has a children, we need to go over them
            if(strlen(word2print) ){

            }
            node *n = trie->children[i];
            strcat(word2print, n->letter); // attach the letter to word2print
            if(n->count != 0){
                printf("%s %d\n", word2print, n->count); 
            }
            if(strlen(n->children) > 0){inorder(n, word2print);} // rekursia
            subString(word2print, 1);
            i++;
        }
        if(i == numOfChild){ // if we pass over all child, we can to return this father
            return;
        }
    }

}

/*
 * check what the word that we need to print
 */
void disorder(node *trie, char *word2print){
    int numOfChild = strlen(trie->children);
    if(numOfChild == 0){ // he is a leaf
        if(trie->count != 0) {
            printf("%s %d\n", word2print, trie->count); // print the word & num how many time it's writted
        }
        if(strlen(word2print) > 1)
            subString(word2print, 1);
        return;
    }
    else{
        int i = (numOfChild-1);
        while(i >= 0){ // while he has a children, we need to go over them
            node *n = trie->children[i];
            strcat(word2print, n->letter); // attach the letter to word2print
            if(n->count != 0){
                printf("%s %d\n", word2print, n->count); 
            }
            if(strlen(n->children) > 0){disorder(n, word2print);} // rekursia
            subString(word2print, 1);
            i--;
        }
        if(i == -1){ // if we pass over all child, we can to return this father
            return;
        }
    }
}

