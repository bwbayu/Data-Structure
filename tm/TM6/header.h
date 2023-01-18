#include <stdio.h>
#include <malloc.h>
#include <string.h>
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TM6 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct
{
    char label_harga[100], label_nama[100];
} isiKontainer;

typedef struct elmt *alamatelmt;
typedef struct elmt
{
    isiKontainer kontainer;
    alamatelmt next;
} elemen;

typedef struct
{
    elemen *top;
} stack;

void createStack(stack *S);
int isEmpty(stack S);
int countElement(stack S);
void push(isiKontainer kontainer, stack *S);
void pop(stack *S);
void printStack(stack S);
void moveElement(stack *stackAsal, stack *stackTujuan);