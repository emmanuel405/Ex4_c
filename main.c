# include <stdio.h>
# include "trie.h"
# include <string.h>
# include <strings.h>
# include <stdlib.h>

# define WORD 100
# define TOLOWERCASE 32

int main(int argc, char* argv[]){
  int lengthMaxWord = 0;
  node* head= (node*)malloc(sizeof(node));
  if(NULL == head){
    printf("ERROR\n");
    return -1;
  }
  (head->parent) = NULL;
  for(int i=0; i<NUM_LETTERS; i++)
       (head->children[i])=NULL;
  char w[WORD];
  int i=0;
  char c=1;
  while(c!='\n'&& c!='.' && '\r'){
    if(scanf("%c", &c)==1){
        printf("%c ", c);
        if (c>='a' && c<='z'){
          w[i]=c;
          ++i; 
        }
        else if(c>='A' && c<='Z'){
          w[i]=c+TOLOWERCASE;
          ++i;
        }
        else if(c==' ' || c==' ' || c=='.' || c=='\n' || c=='\r' || c==EOF){
            addWord(w,head);
            if(strlen(w) > lengthMaxWord) lengthMaxWord = strlen(w);
            printf("%s ", w);
            bzero(w,strlen(w));
            printf("I was hear");
            i=0;
        }
    }
  }
   // printf("\n%s", argv[1]);
  if(argc==2){
    char* word2print = (char*)malloc(sizeof(char)*lengthMaxWord);
    if(NULL == word2print){
      printf("ERROR !");
      return -1;
    }
    strcpy(word2print, "");

    if(argv[1]=="r"){
      printDown(head, word2print);
      printf("\n%s", argv[1]);
    }
    else{
      printUp(head, word2print);
      printf("\n%s", argv[1]);
      return 0;
    }  
    free(word2print);
  }
free(head);
return 0;
}

// int main(char arg){
//   node* head = (node*)malloc(sizeof(node));
//   if(NULL == head){
//     printf("ERROR\n");
//     return -1;
//   }
//   head->children=NULL;
//   char[WORD] w;
//   int i=0;
//   char c=1;
//   while(c!=EOF){
//     if(scanf("%c", c)==1){
//        if (c>='a' && c<='z')
//        {
//          w[i]=c;
//          i++; 
//        }
//        else if(c>='A' && c<='Z'){
//            w[i]=c+TOLOWERCASE;
//            i++;
//        }
//        else if(c==' ' || c=='.' || c=='\n' || c=='\r' || c==EOF){
//            addWord(w,head);
//            bzero(w,strlen(w));
//            i=0;
//        }
         
//     }
//   }