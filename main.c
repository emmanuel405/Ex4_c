# include <stdio.h>
# include "trie.h"
# include <string.h>
# include <strings.h>
# include <stdlib.h>
# define WORD 100
# define TOLOWERCASE 32
/*
    ASCII:
A = 65, Z = 90
a = 97, z = 122
*/

int main(int argc,char* argv[]){
   node* head= (node*)malloc(sizeof(node));
   (head->parent)=NULL;
   for(int i=0; i<NUM_LETTERS; i++)
        (head->children[i])=NULL;
   char w[WORD];
   int i=0;
   char c=1;
   while(c!='\n'&& c1!='.' && '\r'){
     if(scanf("%c", &c)==1){
         printf("%c ", c);
         if (c>='a' && c<='z')
         {
           w[i]=c;
           ++i; 
         }
         else if(c>='A' && c<='Z'){
             w[i]=c+TOLOWERCASE;
             ++i;
         }
         else if(c==' ' || c==' ' || c=='.' || c=='\n' || c=='\r' || c==EOF){
             addWord(w,head);
             printf("%s ", w);
             bzero(w,strlen(w));
             printf("i was hear");
             i=0;
         }
     }
   }   
    printf("i was hear");
    printDown(head);
    //free(head);
}