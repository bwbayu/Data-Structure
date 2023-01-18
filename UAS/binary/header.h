/*Saya Bayu Wicaksono NIM 2106836 mengerjakan UAS dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include <stdio.h>
#include <malloc.h>
#include <math.h>

typedef struct
{
    int node;
} isiKontainer; // struct untuk data tampungan

typedef struct smp *alamatsimpul; // deklarasi alamat elemen
typedef struct smp
{
    isiKontainer kontainer;
    alamatsimpul right;
    alamatsimpul left;
} simpul; // struct untuk elemen tree

typedef struct
{
    simpul *root;
} tree; // struct untuk tree

void makeTree(int data, tree *T);                 // prosedur untuk membuat tree
void addRight(int data, simpul *root);            // prosedur untuk menambahkan elemen di kanan tree
void addLeft(int data, simpul *root);             // prosedur untuk menambahkan elemen di kiri tree
void generate(int data, simpul *root);            // prosedur untuk mengenerate simpul anak
void printTreePostOrder(simpul *root, int *sign); // prosedur untuk menampilkan pohon biner secara postorder