#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TP4 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct
{
    char nama[100];
} isiKontainer; // struct untuk data

typedef struct smp *alamatsimpul; // alamat node
typedef struct smp
{
    // char kontainer;
    isiKontainer kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
} simpul; // struct node

typedef struct
{
    simpul *root;
} tree; // struct tree

void makeTree(isiKontainer kontainer, tree *T);      // prosedur untuk membuat tree
void addChild(isiKontainer kontainer, simpul *root); // prosedur untuk menambahkan node pada tree
void delAll(simpul *root);                           // prosedur untuk menghapus semua node dibawahnya dari suatu node
void delChild(simpul *tujuan, simpul *root);         // prosedur untuk menghapus child dari suatu node
simpul *findSimpul(char tujuan[], simpul *root);     // fungsi untuk mencari suatu node
void printTreePreOrder(simpul *root, int panah);     // prosedur untuk menampilkan tree secara preorder / dfs (klo ga salah)