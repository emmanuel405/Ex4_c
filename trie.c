# include <stdio.h>
# include "trie.h"
# include <string.h>
# include <stdlib.h>
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
    //make a new node.
    node* add=(node*)malloc(sizeof(node));
    if(NULL == add){
        printf("ERROR\n");
        return NULL;
    }
    //if the letter not exist yet.
    if(n->children[letter-FROMASCIITOZERO]==NULL){
        //printf("%c ", letter);        
        //insert to the new node.
        add->letter=letter;
        add->count=0;
        add->parent=n;
        for(int i=0; i<NUM_LETTERS; i++)
           (add->children[i])=NULL;
        //insert the new node to the parent
        (n->children[letter-FROMASCIITOZERO])= add;
        return add;

        /*
        need to :=> free(add);
        */
    }
    else { 
        //printf("%c ", letter);
        return (n->children[letter-FROMASCIITOZERO]);
    }
    free(add);
}

int inorder(node *trie, char *word2print);
int disorder(node *trie, char *word2print);
char* subString(char *w, int i);

/*
This method print the 'trie' in ascending alphabet order.
node:
letter, count, children [*]
*/
int printUp(node* trie, char* word2print){
    if(NULL == trie){
        printf("ERROR, the trie is null !\n");
        return -1;
    }
    else
        inorder(trie, &word2print);
}
/*
This method print the 'trie' in descending alphabet order.
*/
int printDown(node* trie, char* word2print){
     if(NULL == trie){
        printf("ERROR, the trie is null !\n");
        return -1;
    }
    else
        disorder(trie, &word2print);
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
int inorder(node *trie, char *word2print){
    if(NULL == trie->children){ // he is a leaf
        if(trie->count != 0) {
            printf("%s -> %ld\n", word2print, trie->count); // print the word & num how many time it's writted
        }
        if(strlen(word2print) >= 1)
            subString(word2print, 1);
        return 0;
    }
    else{
        for(int i = 0; trie->children[i] != NULL; i++){ // while he has a children, we need to go over them
            node *n = trie->children[i];
            char lettre = n->letter;
            strcat(word2print, lettre); // attach the lettre to word2print
            if(n->count != 0){
                printf("%s %ld\n", word2print, n->count); 
            }
            inorder(n, word2print); // rekursia  
        }
        if(strlen(word2print) >= 1) {subString(word2print, 1);}
        return 0;
    }
}

int numOfChildren(node*);
/*
 * check what the word that we need to print
 */
int disorder(node *trie, char *word2print){
    if(NULL == trie) return NULL;
    if(NULL == trie->children){ // he is a leaf
        if(trie->count != 0) {
            printf("%s -> %ld\n", word2print, trie->count); // print the word & num how many time it's writted
        }
        if(strlen(word2print) >= 1)
            subString(word2print, 1);
        return 0;
    }
    else{
        for(int i = numOfChildren(trie); i > -1; i--){ // we need to go over all children
            node *n = trie->children[i];
            char lettre = n->letter;
            strcat(word2print, lettre); // attach the letter to word2print
            if(n->count != 0){
                printf("%s %ld\n", word2print, n->count); 
            }
            disorder(n, word2print); // rekursia 
        }
        if(strlen(word2print) >= 1) {subString(word2print, 1);}
        return 0;
    }
}
int numOfChildren(node* trie){
    if(NULL == trie->children) return 0;
    int number_chilren = 0;
    for (int i=0; trie->children[i] != NULL; i++){
        number_chilren++;
    }
    return number_chilren;
}


///////////*****************************************************************************///////////

// int isALeaf(node* n){
//     //printf("i was hear");
//     if(n==NULL)
//         return FALSE;
//         //printf("i was hear");
//     for(int i=0; i<NUM_LETTERS; i++){
//         if(n->children[i]!=NULL)
//             return FALSE;
//     }
//     return TRUE;
// }
// void printDown(node* trie){
//     node* head=trie;
//     int index=0;
//     char word[WORD];
//     printf("\ni was hear" );
//     printDownHelper(head, word, index);    
// }
// void printDownHelper(node* child, char* word, int index ){
//     //printf("%s ", word );
//     if (isALeaf(child))
//     {
//         freeNodesAndPrint(child, word, index);
//         //printf("%s ", word );
//         return;
        
//     }
//     for(int i=SUMOFLETTER-1; i>=0; i--){
//         if((child->children[i])!=NULL)
//         {
//             word[index]= child->children[i]->letter;
//             index++;
//             //printf("%s ", word );
//             printDownHelper(child->children[i],&word[index], index );
//         }
//     }
// }
// void freeNodesAndPrint(node* n, char* word, int index){
//     node* temp=NULL;
//     //printf("%s ", word);
//     if(isALeaf(n)){
//         if((n->count)!=0){
//             printf("%s  %ld", word, n->count );
//             word[index]=0;
//             index--;
//         }
//         char letter=(n->letter);
//         temp=n->parent;
//         free(n);
//         (temp->children[letter-FROMASCIITOZERO])=NULL;
//         freeNodesAndPrint(temp,word, index);
//     }
//     else 
//         printDownHelper(n,word,index);
//         //printf("%s ", word);
