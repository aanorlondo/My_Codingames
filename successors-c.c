#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct person {
    char name[41]; 
    char parent[41];
    int birth; 
    char death[5];
    char religion[11]; 
    char gender[2];
    int nbchildren;
    struct person ** children;        
} Person;
typedef Person * Tree; //we'll be handling references to avoid heap/stack collisions

Tree newTree() {
    return malloc(sizeof(Tree));
}

Tree newNode(char*name, char*parent, int birth, char*death, char*religion, char*gender) {
    //memory allocation for a new node of the tree
    Tree branch = malloc(sizeof(Tree));
    branch->children = malloc(sizeof(Tree));
    branch->nbchildren = 0;
    strcat(branch->name, name);
    strcat(branch->parent, parent);
    branch->birth = birth;
    strcat(branch->death, death);
    strcat(branch->religion, religion);
    strcat(branch->gender, gender);
    branch->nbchildren = 0;
    return branch;
}

bool isChild(Tree c, Tree p) { //checking if c is child of p
    if (c->parent == p->name) return true;
    return false;
}

void addChild(Tree p, Tree c) {
    if (c->parent == p->name) {
        p->nbchildren++;
        p->children = realloc(p->children, sizeof(Tree) * p->nbchildren);
        p->children[p->nbchildren-1] = c;
    }
}

Tree findParent(Tree root, Tree p) {
    Tree cursor = root;
    for (int i=0; i<cursor->nbchildren; i++) {
        if (isChild(p,cursor->children[i])) return cursor->children[i];
        if (cursor->children[i]->nbchildren != 0) {
            cursor = cursor->children[i];
            findParent(cursor,p);
        }
    } 
    return NULL;
}

int main() {
    int n; scanf("%d", &n);
    Tree tree = newTree(); //the big tree
    Tree cursor = newTree(); //the tree cruiser
    for (int i = 0; i < n; i++) {
        cursor = tree;
        char name[41]; char parent[41]; int birth; char death[5]; char religion[11]; char gender[2];
        scanf("%s%s%d%s%s%s", name, parent, &birth, death, religion, gender);
        Tree person = newNode(name, parent, birth, death, religion, gender);
        if (strcmp(person->parent, "-")==0) tree = person;
        else {
            if (isChild(person,tree)) addChild(tree,person);
            else {
                cursor = findParent(tree,person);
                if (cursor != NULL) addChild(cursor,person);
            } 
        }
    }

    printf("orDeroFsucceSsion\n");

    return 0;
}
