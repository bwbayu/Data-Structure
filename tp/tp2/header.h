#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define curr_date 9 // deklarasi variabel batas tanggal kadaluarsa
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TP2 dalam mata kuliah Struktur Data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

// struct untuk menampung data dalam list / data inputan
typedef struct
{
    char nama[100];
    int tgl;
} isiKontainer;

// struct untuk pointer
typedef struct elmt *elAdd;

// struct untuk elemen list
typedef struct elmt
{
    isiKontainer kontainer;
    elAdd next;
    elAdd prev;
} elemen;

// struct untuk list
typedef struct
{
    elemen *first;
    elemen *tail;
} list;

// deklarasi prosedur dan fungsi
void createList(list *L);                                     // prosedur untuk membuat dynamic list ganda
int countEl(list L);                                          // fungsi untuk menghitung elemen dalam list
void addFirst(isiKontainer kontainer, list *L);               // prosedur untuk melakukan penambahan data di depan
void addAfter(elemen *prev, isiKontainer kontainer, list *L); // prosedur untuk melakukan penambahan data setelah elemen tertentu
void addLast(isiKontainer kontainer, list *L);                // prosedur untuk menambahkan data sebagai elemen terakhir
void delFirst(list *L);                                       // prosedur untuk menghapus data pada elemen pertama
void delAfter(elemen *prev, list *L);                         // prosedur untuk menghapus data setelah elemen tertentu
void printRev(list L);                                        // prosedur untuk menampilkan bahan makanan secara terbalik
void printEl(list L);                                         // prosedur untuk menampilkan bahan makanan sisa
void print_bahan_ood(list *L);                                // prosedur untuk menampilkan bahan makanan yang kadaluarsa
void sortTgl(list *L);                                        // prosedur sorting asc berdasarkan tanggal kadaluarsa
void sortNama(list *L);                                       // prosedur sorting asc berdasarkan nama bahan makanan