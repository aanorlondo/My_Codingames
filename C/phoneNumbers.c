#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct node { //some tree structure for our phone diary
    char value;
    int nbchildren;
    struct node ** children;
} Node;
typedef Node * Tree; //we'll be handling references to avoid heap/stack collisions

Tree newNode() { //memory allocation for a new node of the tree
    Tree branch = malloc(sizeof(Tree));
    branch->children = malloc(sizeof(Tree));
    branch->nbchildren = 0;
    return branch;
}

bool isChild(char val, Tree tree) { //checking if a digit is already a successor of a given digit
    if (tree->nbchildren == 0) return false;
    for (int i = 0; i < tree->nbchildren ; i++) {
        if (tree->children[i]->value == val) return true;
    }
    return false;
}

Tree move(char to, Tree from) { //move to the cell holding the next digit if it is already a successor
    if (from->nbchildren != 0 && isChild(to,from)) { //double protection for isChild, not optimal but good for general purpose reuse :)
        for (int i = 0 ; i < from->nbchildren; i++ ) {
            if (from->children[i]->value == to) {
                Tree ptr = newNode(); 
                ptr = from->children[i];
                return ptr;
            }
        }
    }
    return from;
}

void freeAll(Tree rep) { //freeing all the space
    if (rep->nbchildren == 0) free(rep);
    else 
        for (int i = 0 ; i < rep->nbchildren ; i++) 
            freeAll(rep->children[i]);
}

int main()
{
    int N;
    scanf("%d", &N);
    Tree rep = newNode(); //the diary
    Tree cursor; //a cursor to cruise along the diary
    int entries = 0; //our output, starts at 0 (captain obvious)
    for (int i = 0; i < N; i++) {
        char telephone[21];
        scanf("%s", telephone);
        fprintf(stderr, "phone %d is %s length %lu\n",i+1,telephone,strlen(telephone));
        cursor = rep; //cursor goes at diary root at each number
        for (int j = 0; j < strlen(telephone) ; j++ ) {
            //for each phone number, we build the tree on the fly
            if (! isChild(telephone[j], cursor)) { //if digit is not a successor from current position
                cursor->children = realloc(cursor->children, sizeof(Tree)*cursor->nbchildren+1); //realloc branches tree from a root cell to allow one more
                cursor->children[cursor->nbchildren] = newNode(); //create a branch holding the successor
                cursor->children[cursor->nbchildren]->value = telephone[j];
                cursor->nbchildren++;
                cursor = cursor->children[cursor->nbchildren-1]; //move to the freshly created cell
                entries++;
            }
            else {
                if (j + 1 < strlen(telephone)) {
                    //if a digit is known from current root, move to the cell holding that digit
                    cursor = move(telephone[j],cursor);
                }
            }
        }
        fprintf(stderr, "\tentries after phone %d : %d\n",i+1,entries);
    }
    printf("%d\n",entries);
    //freeing all the space
    cursor = rep; freeAll(rep); free(cursor);
    return 0;
}
