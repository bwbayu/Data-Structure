#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TM2 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main()
{
    list llist;
    createList(&llist);
    isiKontainer data;
    scanf("%s %s %s", data.nama, data.gender, data.asal);
    addFirst(data, &llist);
    scanf("%s %s %s", data.nama, data.gender, data.asal);
    addLast(data, &llist);
    scanf("%s %s %s", data.nama, data.gender, data.asal);
    addAfter(llist.first->next, data, &llist);
    printf("--------------------\n");
    printEl(llist);

    printf("--------------------\n");
    delAfter(llist.first->next, &llist);
    delFirst(&llist);
    delLast(&llist);
    printEl(llist);

    printf("--------------------\n");
    scanf("%s %s %s", data.nama, data.gender, data.asal);
    addFirst(data, &llist);
    scanf("%s %s %s", data.nama, data.gender, data.asal);
    addFirst(data, &llist);
    delLast(&llist);
    printEl(llist);

    printf("--------------------\n");
    delAll(&llist);
    printEl(llist);

    printf("--------------------\n");
    scanf("%s %s %s", data.nama, data.gender, data.asal);
    addLast(data, &llist);
    printEl(llist);

    printf("--------------------\n");

    return 0;
}