# define NUM_LETTERS 26

typedef enum {FALSE = 0, TRUE = 1} boolean;

typedef struct node{
    char letter;
    long unsigned int count;
    struct node* children[NUM_LETTERS];
} node;

void addWord(char*, node*);

node* addLetter(char, node*);

void printUp(node*);

void printDown(node*);