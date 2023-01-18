#include <stdio.h>
#include <string.h>
#define MAX 50
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan kuis 2 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct
{
    char nama[100], jenis[100], wilayah[100];
    int berat;
} isiKontainer;

typedef struct
{
    int top;
    isiKontainer data[MAX];
} stack;

void createStack(stack *S);
int isEmpty(stack S);
int isFull(stack S);
void push(isiKontainer kontainer, stack *S);
void pop(stack *S);
void printStack(stack S);
void popPush(stack *Sasal, stack *Stujuan);
int cariElemen(isiKontainer pelanggan[], stack *Sasal, int m);