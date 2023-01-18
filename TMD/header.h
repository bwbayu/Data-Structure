/*
Saya Bayu Wicaksono NIM 2106836 mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.
*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char namaKomponen[200];
} isiKomponen; // struct untuk tampungan data komponen

typedef struct
{
    char namaProduk[200], namaParent[200];
    int nilaiJual, digitNilai;
} isiKontainer; // struct untuk tampungan data node

typedef struct elmt *elAdd; // deklarasi alamat elemen komponen
typedef struct elmt
{
    isiKomponen komponen;
    elAdd next;
} elemen; // struct untuk list komponen

typedef struct smp *alamatsimpul; // deklarasi alamat elemen node
typedef struct smp
{
    isiKontainer kontainer;
    alamatsimpul sibling;
    alamatsimpul child;
    elemen *first;
} simpul; // struct untuk elemen tree

typedef struct
{
    simpul *root;
} tree; // struct untuk tree

void createList(simpul *L);                                                                              // prosedur untuk membuat list
void addLast(isiKomponen komponen, simpul *L);                                                           // prosedur untuk menambahkan elemen list
void makeTree(isiKontainer kontainer, tree *T, simpul *L);                                               // prosedur untuk membuat tree
void addChild(isiKontainer kontainer, simpul *root, simpul *L);                                          // prosedur untuk menambahkan node tree
void delLast(simpul *L);                                                                                 // prosedur untuk menghapus list
void delAllList(simpul *L);                                                                              // prosedur untuk menghapus semua list
void delAll(simpul *root);                                                                               // prosedur untuk menghapus semua node tree dari root tertentu
void delChild(simpul *tujuan, simpul *root);                                                             // prosedur untuk menghapus node tree
simpul *findNode(int batas, simpul *root);                                                               // fungsi untuk mencari node yang nilai_jualnya < batas
simpul *findSimpul(char tujuan[], simpul *root);                                                         // fungsi untuk mencari node berdasarkan tujuan
void printSpasi(int n);                                                                                  // prosedur untuk menampilkan spasi
void printTreePreOrder(simpul *root, int level, int spasi[]);                                            // prosedur untuk menampilkan tree secara pre order
int strInt(char str[]);                                                                                  // fungsi untuk mengubah str menjadi int
void pisahStr(char str[], char nama[], char namaParent[], int *nilai, int *tot, int *n, char delimiter); // prosedur untuk memisahkan str input
int maxLenList(simpul *root);                                                                            // prosedur untuk mencari str terpanjang untuk komponen
void maxSpaceLevel(simpul *root, int level, int space[]);                                                // prosedur untuk mencari str terpanjang untuk setiap level