#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan UTS dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main()
{
    list llist;
    isiKontainerRow perusahaan;
    isiKontainerCol obat;
    createList(&llist);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        // masukan nama dan kode perusahaan
        scanf("%s %s", perusahaan.kode, perusahaan.nama);
        // dimasukkan ke row list dengan addlast
        addLastRow(perusahaan, &llist);
        // tanda row untuk data kolom
        Row *tanda;
        if (i == 0)
            tanda = llist.first;
        else
            tanda = tanda->nextRow;
        int m;
        scanf("%d", &m);
        // masukan kode dan nama perusahaan serta bulan dan tahun dari obat
        for (int j = 0; j < m; j++)
        {
            scanf("%s %s %d %d", obat.kode, obat.nama, &obat.bulan, &obat.tahun);
            addLastCol(obat, tanda);
        }
    }
    // organisasi pengawas
    strcpy(perusahaan.kode, "org");
    strcpy(perusahaan.nama, "OrganisasiPengawas");
    addLastRow(perusahaan, &llist);
    // mencari list terakhir
    Row *bantu = llist.first;
    while (bantu->nextRow != NULL)
    {
        bantu = bantu->nextRow;
    }
    // printf("------------%s %s\n", bantu->kontainerRow.kode, bantu->kontainerRow.nama);
    // obat terlarang
    int x;
    scanf("%d", &x);
    isiKontainerCol obatBahaya;
    for (int i = 0; i < x; i++)
    {
        scanf("%s %d %d", obatBahaya.nama, &obatBahaya.bulan, &obatBahaya.tahun);
        Row *rowElemen;
        while (findElement(&rowElemen, obatBahaya, llist, bantu) != NULL)
        {
            // printf("%s\n", rowElemen->kontainerRow.kode);
            pindahElemen(obatBahaya, rowElemen, bantu);
        }
    }

    // menampilkan isi list
    printElement(llist);
    return 0;
}
