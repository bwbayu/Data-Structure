#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*Saya Bayu Wicaksono NIM 2106836 mengerjakan kuis 1 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

// struct untuk menampung data inputan dan data list
typedef struct
{
    char jenis[100], merk[100], nama[100];
} isiKontainer;
// struct pointer
typedef struct elmt *elAdd;

// struct elemen
typedef struct elmt
{
    isiKontainer kontainer;
    elAdd next;
} elemen;

// struct list
typedef struct
{
    elemen *first;
} list;

void createList(list *L);                                     // prosedur untuk membuat dynamic list
void addFirst(isiKontainer kontainer, list *L);               // prosedur untuk melakukan penambahan data di depan
void addAfter(elemen *prev, isiKontainer kontainer, list *L); // prosedur untuk melakukan penambahan data setelah elemen tertentu
void addLast(isiKontainer kontainer, list *L);                // prosedur untuk menambahkan data sebagai elemen terakhir
void printEl(list L);                                         // prosedur untuk menampilkan seluruh elemen
void bagiList(list *L, list *L1, list *L2, list *L3);         // prosedur untuk membagi dari 1 list menjadi 3 list