#include <stdio.h>
#include <string.h>
#define MAX 5

/*Saya Bayu Wicaksono mengerjakan TM dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

typedef struct
{
    int lvl;
    char nama[100], asal[100];
    // float num;
} isiKontainer;

typedef struct
{
    isiKontainer kontainer;
    int next;
} element;

typedef struct
{
    element data[MAX];
    int first;
} list;

void createlist(list *L);
int countElement(list L);
int emptyElement(list L);
void addFirst(isiKontainer masukan, list *l);
void addAfter(int prev, isiKontainer masukan, list *l);
void addLast(isiKontainer masukan, list *l);
void delFirst(list *L);
void delAfter(int prev, list *L);
void delLast(list *L);
void printEl(list l);
void delAll(list *L);