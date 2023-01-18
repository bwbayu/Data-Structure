#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TP5 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

void createEmpty(graph *G) // prosedur untuk membuat graph kosong
{
    (*G).first = NULL;
}

void addSimpul(isiKontainer kontainer, graph *G) // prosedur untuk menambahkan node ke graph
{
    // alokasi memori
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    // copy data
    baru->kontainer = kontainer;
    // setting pointer
    baru->next = NULL;
    baru->arc = NULL;
    if ((*G).first == NULL)
    {
        /*jika graf kosong*/
        (*G).first = baru;
    }
    else
    {
        /*menambahkan simpul baru pada akhir graph*/
        simpul *last = (*G).first;
        while (last->next != NULL)
        {
            last = last->next;
        }

        last->next = baru;
    }
}

void addJalur(simpul *awal, simpul *tujuan, int beban) // prosedur untuk menambahkan jalur dari satu node ke node lain
{
    // alokasi memori
    jalur *baru;
    baru = (jalur *)malloc(sizeof(jalur));
    // copy data
    baru->kontainerJalur = beban;
    // setting pointer
    baru->nextJalur = NULL;
    baru->tujuan = tujuan;
    if (awal->arc == NULL)
    {
        /*jika list jalur kosong*/
        awal->arc = baru;
    }
    else
    {
        /*menambahkan jalur baru pada akhir list jalur*/
        jalur *last = awal->arc;

        while (last->nextJalur != NULL)
        {
            last = last->nextJalur;
        }

        last->nextJalur = baru;
    }
}

simpul *findSimpul(char node, graph G) // fungsi untuk mencari node
{
    simpul *hasil = NULL;
    simpul *bantu = G.first;
    int ketemu = 0;
    while ((bantu != NULL) && (ketemu == 0)) // mencari hingga node terakhir dan berhenti ketika node yang dicari ditemukan
    {
        if (bantu->kontainer.node == node) // jika node yang dicari ditemukan
        {
            hasil = bantu;
            ketemu = 1;
        }
        else // jika belum ditemukan
        {
            bantu = bantu->next;
        }
    }

    return hasil; // mengembalikan alamat node
}

void findPath(simpul *source, simpul *dest, int *beban, char path[], int idx) // prosedur untuk mencari semua path dari node asal ke node tujuan
{
    // node ditandai dengan mengubah variabel visited menjadi true dan menyimpannya di path
    source->kontainer.visited = 1;
    path[idx] = source->kontainer.node;
    idx++;

    //
    if (source->kontainer.node == dest->kontainer.node) // jika current source node adalah node tujuan
    {
        for (int i = 0; i < idx; i++) // path akan di print
        {
            printf("%c ", path[i]);
        }
        printf("%d\n", *beban);
    }
    else // jika current source node bukan node tujuan
    {
        jalur *bantu = source->arc; // pointer ke jalur dari node
        while (bantu != NULL)       // menelusuri semua jalur dari node
        {
            if (bantu->tujuan->kontainer.visited == 0) // untuk mencegah cycle
            {
                *beban = *beban + bantu->kontainerJalur;
                findPath(bantu->tujuan, dest, beban, path, idx);
                *beban = *beban - bantu->kontainerJalur;
            }
            bantu = bantu->nextJalur;
        }
    }
    // menghapus current node dari path dengan mengurangi indexnya dan mengubah tanda variabel visitednya menjadi false
    idx--;
    source->kontainer.visited = 0;
}