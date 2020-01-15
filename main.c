# include <stdio.h>
# include "trie.h"
# include <string.h>
# include <strings.h>
# define WORD 30
# define TOLOWERCASE 32
/*
    ASCII:
A = 65, Z = 90
a = 97, z = 122
*/
int main(char arg){
  node* head = (node*)malloc(sizeof(node));
  if(NULL == head){
    printf("ERROR\n");
    return -1;
  }
  head->children=NULL;
  char[WORD] w;
  int i=0;
  char c=1;
  while(c!=EOF){
    if(scanf("%c", c)==1){
       if (c>='a' && c<='z')
       {
         w[i]=c;
         i++; 
       }
       else if(c>='A' && c<='Z'){
           w[i]=c+TOLOWERCASE;
           i++;
       }
       else if(c==' ' || c=='.' || c=='\n' || c=='\r' || c==EOF){
           addWord(w,head);
           bzero(w,strlen(w));
           i=0;
       }
         
    }
  }
char[] word = "";
printf("write your word here: ");
scanf("%s", word);


char *word2print = (char*)malloc(sizeof(char)*10);
if(NULL == word2print){
  print("ERROR\n");
  return;
}
strcat(word2print, "");

/*
**************************************************
we need to check what is the input and print בהתאם
*/
void printDown(node* head, char* word2print);

void printUp(node* trie, char* word2print);
  
free(word2print);
free(head);
return 0;
}