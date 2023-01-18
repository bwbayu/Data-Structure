#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan kuis 2 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct
{
    char nama[100], pekerjaan[100];
    int priority;
} isiKontainer; // struct untuk tampungan data

typedef struct elm *alamatelmt; // deklarasi alamat elemen
typedef struct elm
{
    isiKontainer kontainer;
    alamatelmt next;
} elemen; // struct untuk elemen queue

typedef struct
{
    elemen *first;
    elemen *last;
} queue; // struct untuk queue

void createQueue(queue *Q);                         // prosedur untuk membuat queue
int isEmpty(queue Q);                               // fungsi untuk cek queue apakah queue kosong
int countElement(queue Q);                          // fungsi untuk menghitung elemen dalam queue
void push(isiKontainer kontainer, queue *Q);        // prosedur untuk menambahkan elemen ke queue
void pop(queue *Q);                                 // prosedur untuk mengeluarkan elemen dari queue
void popPush(queue *Q1, queue *Q2);                 // prosedur untuk memindahkan elemen dari satu queue ke queue lain
void printQueue(queue Q);                           // prosedur untuk menampilkan isi queue
void addPriority(isiKontainer kontainer, queue *Q); // prosedur untuk menambahkan elemen ke queue berdasarkan prioritasnya