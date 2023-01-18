#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*Saya Bayu Wicaksono mengerjakan TM9 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct
{
    char k[100];
    int nilai;
} isiKontainer;

typedef struct smp *alamatsimpul;
typedef struct smp
{
    // char kontainer;
    isiKontainer kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul;

typedef struct
{
    simpul *root;
} tree;

void makeTree(isiKontainer kontainer, tree *T);
void addChild(isiKontainer kontainer, simpul *root);
void delAll(simpul *root);
void delChild(simpul *tujuan, simpul *root);
simpul *findSimpul(char tujuan[], simpul *root);
void printTreePreOrder(simpul *root, int *idx, int batas);
void printTreePostOrder(simpul *root, int *idx, int batas);
void copyTree(simpul *root1, simpul **root2);
int isEqual(simpul *root1, simpul *root2);
// void printTreePreOrder(simpul *root, int level, int space[]);