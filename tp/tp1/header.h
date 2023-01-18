#include <stdio.h>
#include <malloc.h>
#include <string.h>

/*Saya Bayu Wicaksono mengerjakan TP1 dalam mata kuliah Struktur Data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

// tipe bungkusan untuk data
typedef struct
{
    char judul[100], prod[100];
    float rate;
} isiKontainer;

typedef struct elmt *elAdd;
// tipe bungkusan untuk elemen list
typedef struct elmt
{
    isiKontainer kontainer;
    elAdd next;
} elemen;

typedef struct
{
    elemen *first;
} list;

void createList(list *L);                                     // prosedur untuk membuat dynamic list
int countEl(list L);                                          // fungsi untuk menghitung elemen dalam list
void addFirst(isiKontainer kontainer, list *L);               // prosedur untuk melakukan penambahan data di depan
void addAfter(elemen *prev, isiKontainer kontainer, list *L); // prosedur untuk melakukan penambahan data setelah elemen tertentu
void addLast(isiKontainer kontainer, list *L);                // prosedur untuk menambahkan data sebagai elemen terakhir
void delFirst(list *L);                                       // prosedur untuk menghapus data pada elemen pertama
void delAfter(elemen *prev, list *L);                         // prosedur untuk menghapus data setelah elemen tertentu
void delLast(list *L);                                        // prosedur untuk menghapus data yang ada di elemen terakhir
void printEl(list L);                                         // prosedur untuk menampilkan seluruh elemen
void judulAsc(isiKontainer kontainer, list *L);               // prosedur untuk mengurutkan list berdasarkan judul secara ascending
void judulDesc(isiKontainer kontainer, list *L);              // prosedur untuk mengurutkan list berdasarkan judul secara descending
void rateAsc(isiKontainer kontainer, list *L);                // prosedur untuk mengurutkan list berdasarkan rating secara ascending
void rateDesc(isiKontainer kontainer, list *L);               // prosedur untuk mengurutkan list berdasarkan rating secara descending
void delAll(list *L);                                         // prosedur untuk menghapus semua elemen dalam list