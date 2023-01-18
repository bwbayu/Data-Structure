#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TM dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main()
{
    list llist;
    createlist(&llist);
    isiKontainer masukan;
    scanf("%s %d %s", &masukan.nama, &masukan.lvl, &masukan.asal);
    addFirst(masukan, &llist);
    scanf("%s %d %s", &masukan.nama, &masukan.lvl, &masukan.asal);
    addFirst(masukan, &llist);
    scanf("%s %d %s", &masukan.nama, &masukan.lvl, &masukan.asal);
    addAfter(llist.first, masukan, &llist);
    printEl(llist);
    printf("--------------------\n");
    delLast(&llist);
    scanf("%s %d %s", &masukan.nama, &masukan.lvl, &masukan.asal);
    addAfter(llist.data[llist.first].next, masukan, &llist);
    scanf("%s %d %s", &masukan.nama, &masukan.lvl, &masukan.asal);
    addLast(masukan, &llist);
    printEl(llist);
    printf("--------------------\n");
    delAfter(llist.data[llist.first].next, &llist);
    delFirst(&llist);
    delLast(&llist);
    printEl(llist);
    printf("--------------------\n");
    delLast(&llist);
    printEl(llist);
    printf("--------------------\n");

    return 0;
}