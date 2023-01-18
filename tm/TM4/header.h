#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TM4 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct
{
    char nama[100], nim[100], gol[10];
} isiKontainer;

typedef struct elmt *elAdd;

typedef struct elmt
{
    isiKontainer kontainer;
    elAdd next;
    elAdd prev;
} elemen;

typedef struct
{
    elemen *first;
    elemen *tail;
} list;

void createList(list *L);
int countEl(list L);
void addFirst(isiKontainer kontainer, list *L);
void addAfter(elemen *prev, isiKontainer kontainer, list *L);
void addLast(isiKontainer kontainer, list *L);
void addBefore(elemen *before, isiKontainer kontainer, list *L);
void delFirst(list *L);
void delAfter(elemen *prev, list *L);
void delLast(list *L);
void printEl(list L);
void printRev(list L);
void delAll(list *L);
void switchEl(list *L);