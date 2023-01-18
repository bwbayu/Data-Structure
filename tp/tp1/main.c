#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP1 dalam mata kuliah Struktur Data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main()
{
    // membuat dynamic list untuk menampung masukan
    list llist;
    createList(&llist);
    int s = 0;         // deklarasi variabel untuk memberhentikan masukan elemen list
    isiKontainer data; // deklarasi tipe bungkusan untuk menampung data
    while (s == 0)
    {
        scanf("%s", data.judul);
        if (strcmp(data.judul, "-") == 0) // ketika bertemu "-" maka masukan playlist akan berhenti
            s = 1;
        if (s == 0) // untuk mengecek apakah masukan playlist berhenti atau lanjut
        {
            scanf("%s %f", data.prod, &data.rate);
            addLast(data, &llist);
        }
    }
    // masukan konten dan jenis sorting
    char bsort[50], csort[50];
    scanf("%s %s", bsort, csort);

    // deklarasi dynamic list baru untuk menampung elemen yang sudah di sorting
    list slist;
    createList(&slist);
    // pointer untuk dynamic list tampungan
    elemen *index = llist.first;
    // mengecek playlist tersebut akan disorting berdasarkan konten apa dan jenis sorting apa
    if (strcmp(bsort, "judul") == 0) // jika konten sortingnya judul
    {
        if (strcmp(csort, "asc") == 0) // jika list tsb disorting secara ascending
        {
            // perulangan untuk elemen yang ada di list tampungan
            while (index != NULL)
            {
                judulAsc(index->kontainer, &slist);
                index = index->next; // iterasi
            }
        }
        else // jika list tsb disorting secara descending
        {
            // perulangan untuk elemen yang ada di list tampungan
            while (index != NULL)
            {
                judulDesc(index->kontainer, &slist);
                index = index->next; // iterasi
            }
        }
    }
    else // jika konten sortingnya rating
    {
        if (strcmp(csort, "asc") == 0) // jika list tsb disorting secara ascending
        {
            // perulangan untuk elemen yang ada di list tampungan
            while (index != NULL)
            {
                rateAsc(index->kontainer, &slist);
                index = index->next; // iterasi
            }
        }
        else // jika list tsb disorting secara descending
        {
            // perulangan untuk elemen yang ada di list tampungan
            while (index != NULL)
            {
                rateDesc(index->kontainer, &slist);
                index = index->next; // iterasi
            }
        }
    }
    delAll(&llist); // menghapus list yang tidak terurut
    printEl(slist); // menampilkan semua data yang ada di dalam dynamic list yang telah di urutkan

    return 0;
}