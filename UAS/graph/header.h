/*Saya Bayu Wicaksono NIM 2106836 mengerjakan UAS dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include <stdio.h>
#include <malloc.h>

typedef struct
{
    char node;
    int visited;
} isiKontainer; // kontainer node

typedef struct smp *alamatsimpul; // alamat node
typedef struct jlr *alamatjalur;  // alamat arc
typedef struct smp
{
    isiKontainer kontainer;
    alamatsimpul next;
    alamatjalur arc;
} simpul; // struct node

typedef struct jlr
{
    int kontainerJalur;
    alamatjalur nextJalur;
    simpul *tujuan;
} jalur; // struct arc

typedef struct
{
    simpul *first;
} graph; // struct graph

void createEmpty(graph *G);                                        // prosedur untuk membuat graph kosong
void addSimpul(isiKontainer kontainer, graph *G);                  // prosedur untuk menambahkan node ke graph
void addJalur(simpul *awal, simpul *tujuan, int beban);            // prosedur untuk menambahkan jalur dari satu node ke node lain
simpul *findSimpul(char node, graph G);                            // fungsi untuk mencari node
void findPath(simpul *source, simpul *dest, int *max, int *total); // prosedur untuk mencari jalur paling panjang dari simpul asal ke simpul tujuan