#include <stdio.h>
#include <string.h>
#define MAX 100
/*Saya Bayu Wicaksono mengerjakan TM3 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct
{
    char jenis[100], merk[100], nama[100];
} isiKontainer;

typedef struct
{
    isiKontainer kontainer;
    int prev, next;
} elemen;

typedef struct
{
    int first, tail;
    elemen data[MAX];
} list;

void createList(list *L);
int countEl(list L);
int emptyEl(list L);
void addFirst(isiKontainer kontainer, list *L);
void addAfter(int before, isiKontainer kontainer, list *L);
void addLast(isiKontainer kontainer, list *L);
void delFirst(list *L);
void delAfter(int before, list *L);
void delLast(list *L);
void printEl(list L);
void delAll(list *L);
void tukarEl(list *L);
void printReverse(list L);
