#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TP2 dalam mata kuliah Struktur Data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main()
{
    list llist;         // deklarasi list
    createList(&llist); // membuat list
    isiKontainer data;  // deklarasi struct untuk menyimpan data
    // input
    int s = 0;
    do
    {
        scanf("%s", data.nama);
        if (strcmp(data.nama, "--stop--") != 0)
        {
            scanf("%d", &data.tgl);
            addLast(data, &llist);
        }
        else
            s = 1;
    } while (s == 0);
    // output
    // sorting berdasarkan tanggal
    sortTgl(&llist);
    printf("==== Inventory Dapur ====\n");
    printf("List semua bahan:\n");
    printRev(llist);

    printf("\nList bahan kadaluarsa:\n");
    print_bahan_ood(&llist);

    printf("\nList bahan sisa:\n");
    // mengecek elemen dalam list
    if (llist.first != NULL)
    {
        sortNama(&llist);
        printEl(llist);
    }
    else
    {
        printf("-\n");
    }

    printf("=========================\n");
    return 0;
}