#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan kuis 1 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

void createList(list *L)
{
    (*L).first = -1;
    (*L).tail = -1;

    for (int i = 0; i < MAX; i++)
    {
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    }
}

int countEl(list L)
{
    int hasil = 0;
    if (L.first != -1)
    {
        int bantu = L.first;

        while (bantu != -1)
        {
            hasil += 1;
            bantu = L.data[bantu].next;
        }
    }
    return hasil;
}

// mencari "index" untuk elemen kosong
int emptyElement(list L)
{
    int hasil = -1; // inisialisasi variabel untuk index elemen kosong
    if (countEl(L) < MAX)
    {
        int find = 0, i = 0;         // inisialisasi variabel
        while (find == 0 && i < MAX) // melakukan pencarian elemen kosong dalam list hingga elemen terakhir
        {
            if (L.data[i].next == -2) // jika menemukan pointer next yang bernilai -2 artinya ada elemen yang masih kosong
            {
                hasil = i;
                find = 1;
            }
            else // jika belum ditemukan maka akan di iterasi
                i += 1;
        }
    }
    return hasil; // mengembalikan nilai
}

void addFirst(isiKontainer kontainer, list *L)
{
    if (countEl(*L) < MAX)
    {
        int newPtr = emptyElement(*L);

        // copy data
        (*L).data[newPtr].kontainer = kontainer;
        // end of copy data

        if ((*L).first == -1) // jika list kosong
        {
            (*L).data[newPtr].prev = -1; // 1
            (*L).data[newPtr].next = -1; // 1
            (*L).tail = newPtr;          // 2
        }
        else // jika list ada isinya
        {
            (*L).data[newPtr].prev = -1;         // 1
            (*L).data[newPtr].next = (*L).first; // 2
            (*L).data[(*L).first].prev = newPtr; // 3
        }
        (*L).first = newPtr; // 1 (kondisi 1) && 4 (kondisi 2)
    }
    else
    {
        printf("Sudah tidak dapat ditambah\n");
    }
}

void addAfter(int before, isiKontainer kontainer, list *L)
{
    if (countEl(*L) < MAX && before != -1)
    {
        int newPtr = emptyElement(*L);

        // copy data
        (*L).data[newPtr].kontainer = kontainer;
        // end of copy data
        if ((*L).data[before].next != -1) // jika penambahan elemen di tengah
        {
            (*L).data[newPtr].next = (*L).data[before].next; // 2
            (*L).data[newPtr].prev = before;                 // 2
            (*L).data[before].next = newPtr;                 // 3
            (*L).data[(*L).data[newPtr].next].prev = newPtr; // 4
        }
        else // jika penambahan elemen di terakhir
        {
            (*L).data[newPtr].next = -1;     // 1
            (*L).data[before].next = newPtr; // 2
            (*L).data[newPtr].prev = before; // 3
            (*L).tail = newPtr;              // 4
        }
    }
    else
    {
        printf("Sudah tidak dapat ditambah\n");
    }
}

void addLast(isiKontainer kontainer, list *L)
{
    if ((*L).first == -1) // jika list kosong
    {
        addFirst(kontainer, L);
    }
    else // jika list ada isinya
    {
        addAfter((*L).tail, kontainer, L);
    }
}

void printEl(list L)
{
    if (L.first != -1)
    {
        int bantu = L.first;
        int i = 1;
        while (bantu != -1)
        {
            printf("%s %s\n", L.data[bantu].kontainer.str, L.data[bantu].kontainer.str1);
            bantu = L.data[bantu].next;
            i += 1;
        }
    }
    else
    {
        printf("List Kosong.\n");
    }
}

void tukarEl(list *L1, list *L2, int p)
{
    int front = (*L1).first;
    int back = (*L1).tail;
    int depan = (*L2).first;
    int belakang = (*L2).tail;
    isiKontainer temp1, temp2, temp;
    for (int i = 0; i < p; i++)
    {
        temp = (*L1).data[front].kontainer;
        (*L1).data[front].kontainer = (*L2).data[depan].kontainer;
        (*L2).data[depan].kontainer = temp;
        front = (*L1).data[front].next;
        depan = (*L2).data[depan].next;
        // // belakang
        temp = (*L1).data[back].kontainer;
        (*L1).data[back].kontainer = (*L2).data[belakang].kontainer;
        (*L2).data[belakang].kontainer = temp;
        back = (*L1).data[back].prev;
        belakang = (*L2).data[belakang].prev;
    }
}