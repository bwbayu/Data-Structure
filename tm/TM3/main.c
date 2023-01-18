#include "header.h"
/*Saya Bayu Wicaksono mengerjakan TM3 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main()
{
    list llist;
    createList(&llist);
    isiKontainer data;
    // masukan
    scanf("%s %s %d", data.nama, data.tgl, &data.sum);
    addFirst(data, &llist);
    scanf("%s %s %d", data.nama, data.tgl, &data.sum);
    addLast(data, &llist);
    scanf("%s %s %d", data.nama, data.tgl, &data.sum);
    addAfter(llist.first, data, &llist);
    printf("Data Kebun Binatang\n");
    printf("===================\n");
    printEl(llist);
    printf("===================\n");
    delAfter(llist.data[llist.first].next, &llist);
    scanf("%s %s %d", data.nama, data.tgl, &data.sum);
    addAfter(llist.first, data, &llist);
    scanf("%s %s %d", data.nama, data.tgl, &data.sum);
    addAfter(llist.data[llist.tail].prev, data, &llist);
    delFirst(&llist);
    printEl(llist);
    printf("===================\n");
    scanf("%s %s %d", data.nama, data.tgl, &data.sum);
    addFirst(data, &llist);
    scanf("%s %s %d", data.nama, data.tgl, &data.sum);
    addAfter(llist.data[llist.first].next, data, &llist);
    delLast(&llist);
    printReverse(llist);
    printf("===================\n");
    delAll(&llist);
    printEl(llist);
    return 0;
}