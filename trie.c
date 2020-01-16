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
        //printf("%c ", letter);
        //make a new node.
        node* add=(node*)malloc(sizeof(node));
        //insert to the new node.
        add->letter=letter;
        add->count=0;
        add->parent=n;
        for(int i=0; i<NUM_LETTERS; i++)
           (add->children[i])=NULL;
        //insert the new node to the parent
        (n->children[letter-FROMASCIITOZERO])= add;
        return add;
    }
    else { 
        //printf("%c ", letter);
        return (n->children[letter-FROMASCIITOZERO]);
    }

}

void inorder(node *trie, char *word2print);
void disorder(node *trie, char *word2print);

char* subString(char *w, int i);

/*
This method print the 'trie' in ascending alphabet order.
node:
letter, count, children [*]
*/
// void printUp(node* trie){
//     if(NULL == trie){
//         print("ERROR, the trie is null !\n");
//         break;
//     }
//     else{
//         char *word2print = (char*)malloc(sizeof(char)*50);
//         if(NULL = word2print){
//             print("ERROR\n");
//             return;
//         }
//         strcat(word2print, "");
//         void inorder(trie, word2print);
//         free(word2print);
//     }
      
// }
/*
This method print the 'trie' in descending alphabet order.
*/
// void printDown(node* trie){
//      if(NULL == trie){
//         print("ERROR, the trie is null !\n");
//         break;
//     }
//     else{
//         char *word2print = (char*)malloc(sizeof(char)*50);
//         if(NULL = word2print){
//             print("ERROR\n");
//             return;
//         }
//         strcat(word2print, "");
//         void disorder(trie, word2print);
//         free(word2print);
//     }
      
// }
////////////////////////////
//*** private methodes ***//
////////////////////////////

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
 * 
 */
void inorder(node *trie, char *word2print){
    int numOfChild = strlen(trie->children);
    if(numOfChild == 0){ // he is a leaf
        if(trie->count != 0) {
            printf("%s", word2print);
        }
        if(strlen(word2print) > 1)
            subString(word2print, 1);
        return;
    }
    else{
        int i = 0;
        node *n = trie->children[i];
        while(i<numOfChild){
            if(n->count == 0){
                strcat(word2print, n->letter);
                inorder(n, word2print);
            }
            else{
                printf("%s", word2print);
                subString(word2print, 1);
                return;
            }
        i++;
        }
    }
}
int isALeaf(node* n){
    //printf("i was hear");
    if(n==NULL)
        return FALSE;
        //printf("i was hear");
    for(int i=0; i<NUM_LETTERS; i++){
        if(n->children[i]!=NULL)
            return FALSE;
    }
    return TRUE;
}
void printDown(node* trie){
    node* head=trie;
    int index=0;
    char word[WORD];
    printf("\ni was hear" );
    printDownHelper(head, word, index);    
}
void printDownHelper(node* child, char* word, int index ){
    //printf("%s ", word );
    if (isALeaf(child))
    {
        freeNodesAndPrint(child, word, index);
        //printf("%s ", word );
        return;
        
    }
    for(int i=SUMOFLETTER-1; i>=0; i--){
        if((child->children[i])!=NULL)
        {
            word[index]= child->children[i]->letter;
            index++;
            //printf("%s ", word );
            printDownHelper(child->children[i],&word[index], index );
        }
    }
}
void freeNodesAndPrint(node* n, char* word, int index){
    node* temp=NULL;
    //printf("%s ", word);
    if(isALeaf(n)){
        if((n->count)!=0){
            printf("%s  %ld", word, n->count );
            word[index]=0;
            index--;
        }
        char letter=(n->letter);
        temp=n->parent;
        free(n);
        (temp->children[letter-FROMASCIITOZERO])=NULL;
        freeNodesAndPrint(temp,word, index);
    }
    else 
        printDownHelper(n,word,index);
        //printf("%s ", word);

}
void disorder(node *trie, char *word2print){
    int numOfChild = strlen(trie->children);
    if(numOfChild == 0){ // he is a leaf
        if(trie->count != 0) {
            printf("%s", word2print);
        }
        if(strlen(word2print) > 1)
            subString(word2print, 1);
        return;
    }
    else{

    }
}

