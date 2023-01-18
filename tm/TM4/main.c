#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TM4 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main()
{
    list llist;
    createList(&llist);
    isiKontainer data;

    scanf("%s %s %s", data.nama, data.nim, data.gol);
    addLast(data, &llist);
    scanf("%s %s %s", data.nama, data.nim, data.gol);
    addFirst(data, &llist);
    scanf("%s %s %s", data.nama, data.nim, data.gol);
    addBefore(llist.first->next, data, &llist);
    printf("Data Golongan Darah\n");
    printf("===================\n");
    printEl(llist);

    printf("===================\n");
    scanf("%s %s %s", data.nama, data.nim, data.gol);
    addAfter(llist.first->next, data, &llist);
    delAfter(llist.first, &llist);
    scanf("%s %s %s", data.nama, data.nim, data.gol);
    addAfter(llist.first, data, &llist);
    scanf("%s %s %s", data.nama, data.nim, data.gol);
    addBefore(llist.tail, data, &llist);
    delFirst(&llist);
    printEl(llist);
    printf("===================\n");

    delLast(&llist);
    delAfter(llist.first, &llist);
    scanf("%s %s %s", data.nama, data.nim, data.gol);
    addLast(data, &llist);
    printRev(llist);
    printf("===================\n");

    delAll(&llist);
    printEl(llist);

    return 0;
}
// scanf("%s %s %s", data.nim, data.nama, data.nilai);
// addLast(data, &llist);
// scanf("%s %s %s", data.nim, data.nama, data.nilai);
// addLast(data, &llist);
// scanf("%s %s %s", data.nim, data.nama, data.nilai);
// addLast(data, &llist);

// scanf("%s %s %s", data.nim, data.nama, data.nilai);
// addBefore(llist.tail, data, &llist);

// printEl(llist);