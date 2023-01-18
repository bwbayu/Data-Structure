#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TM5 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main()
{
    list llist;
    isiKontainerRow box;
    isiKontainerCol barang;
    createList(&llist);
    //
    int n;
    scanf("%d", &n);
    // Row *tanda = llist.first;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", box.label, box.kode);
        addLastRow(box, &llist);
        //
        Row *tandaRow;
        if (i == 0)
            tandaRow = llist.first;
        else
            tandaRow = tandaRow->nextRow;
        //
        scanf("%s", barang.nama);
        addFirstCol(barang, tandaRow);
        scanf("%s", barang.nama);
        addLastCol(barang, tandaRow);
        scanf("%s", barang.nama);
        addAfterCol(tandaRow->toCol->nextCol, barang);
        scanf("%s", barang.nama);
        addFirstCol(barang, tandaRow);
        // tanda = tanda->nextRow;
    }
    delAfterCol(llist.first->nextRow->toCol->nextCol);
    delFirstRow(&llist);
    delFirstCol(llist.first);
    printElement(llist);
    delAllRow(&llist);
    printElement(llist);

    return 0;
}