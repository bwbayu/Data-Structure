#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan kuis 1 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main()
{
    list llist;
    list llist1, llist2, llist3;
    // buat list
    createList(&llist);
    createList(&llist1);
    createList(&llist2);
    createList(&llist3);
    isiKontainer data;
    // masukan
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %s", data.jenis, data.merk, data.nama);
        addLast(data, &llist);
    }
    // membagi dari 1 list menjadi 3 list
    bagiList(&llist, &llist1, &llist2, &llist3);
    // output
    printEl(llist1);
    printEl(llist2);
    printEl(llist3);

    return 0;
}