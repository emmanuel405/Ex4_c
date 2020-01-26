# include <stdio.h>
# include "trie.h"
# include <string.h>
# include <strings.h>
# include <stdlib.h>

# define WORD 50
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
  char* word2print = (char*)malloc(sizeof(char)*WORD);
  if(NULL == word2print){
      printf("ERROR !\n");
      return -1;
    }
    strcpy(word2print, "");
  int i=0;
  int times=1; // for realloc 'word2print' I want to increase it to WORD value
  char c=1;
  while(c!='\n' && c!='.' && '\r'){
    if(scanf("%c", &c) == 1){
      if(i == times*(WORD-1)){
        times++;
        char* word2print = realloc(word2print, sizeof(char)*(times*WORD));
        if(NULL == word2print){
          printf("ERROR !\n");
          return -1;
        }
      }
      if (c>='a' && c<='z'){
        word2print[i]=c;
        ++i; 
      }
      else if(c>='A' && c<='Z'){
        word2print[i]=c+TOLOWERCASE;
        ++i;
      }
      else if(c==' ' || c==' ' || c=='.' || c=='\n' || c=='\r' || c==EOF){
  printf("4\n");
        
          addWord(word2print,head);
          bzero(word2print, strlen(word2print));
          i=0;
      }
    }
  }
  if(*argv[1] == 'r'){
    printDown(head, word2print);
    printf("\nprint1 - %s\n", argv[1]);
  }
  else{
    printUp(head, word2print);
    printf("\nprint2 - %s\n", argv[1]);
  }  
  free(word2print);
  free(head);
  return 0;
}

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