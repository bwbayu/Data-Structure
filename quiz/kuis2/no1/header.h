#include <stdio.h>
#include <string.h>
#define MAX 50 // deklarasi global maks stack
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan kuis 2 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct
{
    char nama[100], jenis[100], wilayah[100];
    int berat;
} isiKontainer; // struct untuk tampungan data

typedef struct
{
    int top;
    isiKontainer data[MAX];
} stack; // struct untuk stack

void createStack(stack *S);                  // prosedur untuk membuat stack
int isEmpty(stack S);                        // fungsi untuk cek apakah stack kosong
int isFull(stack S);                         // fungsi untuk cek apakah stack penuh
void push(isiKontainer kontainer, stack *S); // prosedur untuk menambahkan elemen ke stack
void pop(stack *S);                          // prosedur untuk mengeluarkan elemen ke stack
void printStack(stack S);                    // prosedur untuk menampilkan isi stack
void popPush(stack *Sasal, stack *Stujuan);  // prosedur untuk memindahkan dari satu stack ke stack lain