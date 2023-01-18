#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TM dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

// prosedur membuat list kosong
void createlist(list *L)
{
    (*L).first = -1; // deklarasi null untuk pointer first
    for (int i = 0; i < MAX; i++)
        // inisialisasi pointer next
        (*L).data[i].next = -2;
}

// menghitung banyak elemen dalam list
int countElement(list L)
{
    int hasil = 0;
    if (L.first != -1)
    {
        int hitung = L.first;
        while (hitung != -1)
        {
            // iterasi
            hasil += 1;
            hitung = L.data[hitung].next;
        }
    }
    return hasil;
}
// mencari "index" untuk elemen kosong
int emptyElement(list L)
{
    int hasil = -1;
    if (countElement(L) < MAX)
    {
        int find = 0, i = 0;
        while (find == 0 && i < MAX)
        {
            if (L.data[i].next == -2)
            {
                hasil = i;
                find = 1;
            }
            else
                i += 1;
        }
    }
    return hasil;
}

void addFirst(isiKontainer masukan, list *l)
{
    if (countElement(*l) < MAX)
    {
        // bikin pointer baru
        int baru = emptyElement(*l);
        // copy data
        strcpy((*l).data[baru].kontainer.nama, masukan.nama);
        (*l).data[baru].kontainer.lvl = masukan.lvl;
        strcpy((*l).data[baru].kontainer.asal, masukan.asal);
        // cek elemen dalam list
        if ((*l).first == -1) // jika list kosong
            (*l).data[baru].next = -1;
        else // jika sudah ada elemen dalam list
            (*l).data[baru].next = (*l).first;
        // pointer first menunjuk pointer baru
        (*l).first = baru;
    }
    // else
    // {
    //     // error handling
    //     printf("gabisa bang.\n");
    // }
}

void addAfter(int prev, isiKontainer masukan, list *l)
{
    if (countElement(*l) < MAX)
    {
        // bikin pointer baru
        int baru = emptyElement(*l);
        // copy data
        strcpy((*l).data[baru].kontainer.nama, masukan.nama);
        (*l).data[baru].kontainer.lvl = masukan.lvl;
        strcpy((*l).data[baru].kontainer.asal, masukan.asal);

        // penambahan elemen di belakang
        if ((*l).data[prev].next == -1)
            (*l).data[baru].next = -1;
        else // penambahan elemen di antara 2 elemen
            (*l).data[baru].next = (*l).data[prev].next;
        (*l).data[prev].next = baru;
    }
    // else
    //     printf("gabisa bang\n");
}

void addLast(isiKontainer masukan, list *l)
{
    // jika list masih kosong
    if ((*l).first == -1)
        addFirst(masukan, l);
    else // jika sudah ada elemen
    {
        if (countElement(*l) < MAX)
        {
            int prev = (*l).first;
            while ((*l).data[prev].next != -1)
                prev = (*l).data[prev].next;
            addAfter(prev, masukan, l);
        }
        // else
        //     printf("gabisa bang\n");
    }
}

void delFirst(list *L)
{
    if ((*L).first != -1)
    {
        int hapus = (*L).first;

        if (countElement(*L) == 1)
        {
            (*L).first = -1;
        }
        else
        {
            (*L).first = (*L).data[hapus].next;
        }

        (*L).data[hapus].next = -2;
    }
    // else
    // {
    //     printf("lsit kosong\n");
    // }
}

void delAfter(int prev, list *L)
{
    int hapus = (*L).data[prev].next;

    if (hapus != -1)
    {
        if ((*L).data[hapus].next == -1)
        {
            (*L).data[prev].next = -1;
        }
        else
        {
            (*L).data[prev].next = (*L).data[hapus].next;
        }
        (*L).data[hapus].next = -2;
    }
}

void delLast(list *L)
{
    if ((*L).first != -1)
    {
        if (countElement(*L) == 1)
        {
            // proses jika list hanya berisi satu elemen
            delFirst(L);
        }
        else
        {
            int hapus = (*L).first;
            int prev;

            while ((*L).data[hapus].next != -1)
            {
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }
            // elemen sebelum elemen terakhir menjadi elemen terakhir
            delAfter(prev, L);
        }
    }
    // else
    // {
    //     printf("list kosong\n");
    // }
}

void printEl(list l)
{
    if (l.first != -1)
    {
        int begin = l.first;
        int i = 1;
        while (begin != -1)
        {
            printf("- %s %d %s\n", l.data[begin].kontainer.nama, l.data[begin].kontainer.lvl, l.data[begin].kontainer.asal);
            begin = l.data[begin].next;
            i += 1;
        }
    }
    else
    {
        printf("List Kosong.\n");
    }
}

void delAll(list *L)
{
    int i;
    for (i = countElement(*L); i >= 1; i--)
        delLast(L);
}