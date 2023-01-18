#include "header.h"
/*Saya Bayu Wicaksono mengerjakan TM7 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main()
{
    queue Q1, Q2;
    createQueue(&Q1);
    createQueue(&Q2);
    isiKontainer data;
    scanf("%s %d", data.nama, &data.rating);
    push(data, &Q1);
    scanf("%s %d", data.nama, &data.rating);
    push(data, &Q1);
    scanf("%s %d", data.nama, &data.rating);
    addPriority(data, 2, &Q1);
    printf("******************\n");
    printf("Queue 1\n");
    printQueue(Q1);
    popPush(&Q1, &Q2);
    printf("******************\n");
    printf("Queue 1\n");
    printQueue(Q1);
    printf("******************\n");
    printf("Queue 2\n");
    printQueue(Q2);
    printf("******************\n");
    scanf("%s %d", data.nama, &data.rating);
    addPriority(data, 1, &Q1);
    scanf("%s %d", data.nama, &data.rating);
    addPriority(data, 99, &Q1);
    printf("Queue 1\n");
    printQueue(Q1);
    printf("******************\n");
    popPush(&Q1, &Q2);
    popPush(&Q1, &Q2);
    scanf("%s %d", data.nama, &data.rating);
    push(data, &Q1);
    printf("Queue 1\n");
    printQueue(Q1);
    printf("******************\n");
    printf("Queue 2\n");
    printQueue(Q2);
    printf("******************\n");

    return 0;
}
// printQueue(Q);
//     printf("=================\n");
//     strcpy(mhs.nim, "13507701");
//     strcpy(mhs.nama, "Nana");
//     mhs.nilai = 64.75;
//     push(mhs, &Q);
//     strcpy(mhs.nim, "13507702");
//     strcpy(mhs.nama, "Rudi");
//     mhs.nilai, 75.11;
//     push(mhs, &Q);
//     strcpy(mhs.nim, "13507703");
//     strcpy(mhs.nama, "Dea");
//     mhs.nilai, 84.63;
//     push(mhs, &Q);
//     printQueue(Q);
//     printf("=================\n");
//     pop(&Q);
//     pop(&Q);
//     printQueue(Q);
//     printf("=================\n");