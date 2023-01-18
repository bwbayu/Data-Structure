#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan kuis 2 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct
{
    char nama[100], pekerjaan[100];
    int priority;
} isiKontainer;

typedef struct elm *alamatelmt;
typedef struct elm
{
    isiKontainer kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *first;
    elemen *last;
} queue;

void createQueue(queue *Q);
int isEmpty(queue Q);
int countElement(queue Q);
void push(isiKontainer kontainer, queue *Q);
void pop(queue *Q);
void popPush(queue *Q1, queue *Q2);
void printQueue(queue Q);
void addPriority(isiKontainer kontainer, queue *Q);