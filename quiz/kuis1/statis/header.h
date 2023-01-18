#include <stdio.h>
#include <string.h>
#define MAX 100
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan kuis 1 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

typedef struct
{
    char str[51], str1[51];
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
int emptyElement(list L);
void addFirst(isiKontainer kontainer, list *L);
void addAfter(int before, isiKontainer kontainer, list *L);
void addLast(isiKontainer kontainer, list *L);
void printEl(list L);
void tukarEl(list *L1, list *L2, int p);