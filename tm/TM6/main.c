#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TM6 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main()
{
    stack s1, s2;     // deklarasi stack
    createStack(&s1); // membuat stack kosong
    createStack(&s2);
    isiKontainer makanan; // membuat tampungan data masukan
    printf("S1:\n");
    printStack(s1);
    printf("S2:\n");
    printStack(s2);
    printf("==================\n");
    scanf("%s %s", makanan.label_nama, makanan.label_harga);
    push(makanan, &s1);
    scanf("%s %s", makanan.label_nama, makanan.label_harga);
    push(makanan, &s2);
    scanf("%s %s", makanan.label_nama, makanan.label_harga);
    push(makanan, &s2);
    printf("S1:\n");
    printStack(s1);
    printf("S2:\n");
    printStack(s2);
    printf("==================\n");
    pop(&s1);
    moveElement(&s2, &s1);
    scanf("%s %s", makanan.label_nama, makanan.label_harga);
    push(makanan, &s1);
    scanf("%s %s", makanan.label_nama, makanan.label_harga);
    push(makanan, &s2);
    scanf("%s %s", makanan.label_nama, makanan.label_harga);
    push(makanan, &s1);
    pop(&s2);
    moveElement(&s1, &s2);
    printf("S1:\n");
    printStack(s1);
    printf("S2:\n");
    printStack(s2);
    printf("==================\n");

    return 0;
}