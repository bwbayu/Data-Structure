#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*Saya Bayu Wicaksono mengerjakan TM7 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct
{
    char nama[100];
    int rating;
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
void addPriority(isiKontainer kontainer, int priority, queue *Q);