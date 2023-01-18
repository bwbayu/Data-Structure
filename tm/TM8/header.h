#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*Saya Bayu Wicaksono mengerjakan TM8 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct
{
    char node;
} isiKontainer; // struct untuk data tampungan

typedef struct smp *alamatsimpul; // deklarasi alamat elemen
typedef struct smp
{
    // char kontainer;
    isiKontainer kontainer;
    alamatsimpul right;
    alamatsimpul left;
} simpul; // struct untuk elemen tree

typedef struct
{
    simpul *root;
} tree; // struct untuk tree

void makeTree(isiKontainer kontainer, tree *T);             // prosedur untuk membuat tree
void addRight(isiKontainer kontainer, simpul *root);        // prosedur untuk menambahkan elemen di kanan tree
void addLeft(isiKontainer kontainer, simpul *root);         // prosedur untuk menambahkan elemen di kiri tree
void delAll(simpul *root);                                  // prosedur untuk menghapus semua elemen dalam tree
void delRight(simpul *root);                                // prosedur untuk menghapus semua elemen di kanan suatu elemen
void delLeft(simpul *root);                                 // prosedur untuk menghapus semua elemen di kiri suatu elemen
void printTreePreOrder(simpul *root, int *idx, int batas);  // menampilkan elemen tree dengan metode penelusuran preorder (dfs)
void printTreeInOrder(simpul *root, int *idx, int batas);   // menampilkan elemen tree dengan metode penelusuran inorder (dfs tapi printnya terbalik)
void printTreePostOrder(simpul *root, int *idx, int batas); // menampilkan elemen tree dengan metode penelusuran postorder
void copyTree(simpul *root1, simpul **root2);               // prosedur untuk menyalin elemen dari satu tree ke tree lain
int isEqual(simpul *root1, simpul *root2);                  // prosedur untuk mengecek kesamaan elemen dari 2 tree