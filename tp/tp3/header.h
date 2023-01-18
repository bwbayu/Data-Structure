#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TP3 dalam mata kuliah Struktur Data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct
{
    char judul[100], nama[100];
    int tahun;
} isiKontainer;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    isiKontainer kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *top;
} stack;

void createStack(stack *S);                             // prosedur untuk membuat stack
int isEmpty(stack S);                                   // fungsi untuk cek apakah stack kosong
int countElement(stack S);                              // fungsi untuk menghitung jumlah elemen dalam stack
void push(isiKontainer kontainer, stack *S);            // prosedur untuk menambahkan elemen baru ke stack
void pop(stack *S);                                     // prosedur untuk mengeluarkan elemen dari stack
void printStack(stack S);                               // prosedur untuk menampilkan elemen dalam stack
int toAscii(char judulMusik[100]);                      // fungsi yang mengembalikan nilai ascii dari string
void moveElement(stack *stackAsal, stack *stackTujuan); // prosedur untuk memindahkan elemen dalam stack ke stack lain