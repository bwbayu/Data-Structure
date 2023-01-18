#include "header.h"
/*Saya Bayu Wicaksono mengerjakan TM3 dalam mata kuliah struktur data untuk keberkahanNya
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

int emptyEl(list L)
{
    int hasil = -1;

    if (countEl(L) < MAX)
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

void addFirst(isiKontainer kontainer, list *L)
{
    if (countEl(*L) < MAX)
    {
        int newPtr = emptyEl(*L);

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
        printf("gabisa bang, MAX nya udh mentok\n");
    }
}

void addAfter(int before, isiKontainer kontainer, list *L)
{
    if (countEl(*L) < MAX && before != -1)
    {
        int newPtr = emptyEl(*L);

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
        printf("gabisa bang udh mentok\n");
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

void delFirst(list *L)
{
    if ((*L).first != -1)
    {
        int delPtr = (*L).first;
        if (countEl(*L) == 1) // jika hanya ada 1 elemen
        {
            (*L).first = -1; // 2
            (*L).tail = -1;  // 2
        }
        else
        {
            (*L).first = (*L).data[delPtr].next; // 2
            (*L).data[(*L).first].prev = -1;     // 3
        }

        (*L).data[delPtr].prev = -2; // 3
        (*L).data[delPtr].next = -2; // 3
    }
    else
    {
        printf("list kosong\n");
    }
}

void delAfter(int before, list *L)
{
    int delPtr = (*L).data[before].next; // 1
    if (delPtr != -1 && before != -1)
    {
        if ((*L).data[delPtr].next == -1) // jika menghapus elemen terakhir
        {
            (*L).tail = before;          // 2
            (*L).data[before].next = -1; // 2
        }
        else // jika menghapus elemen tengah
        {
            (*L).data[before].next = (*L).data[delPtr].next; // 2
            (*L).data[(*L).data[delPtr].next].prev = before; // 3
        }

        (*L).data[delPtr].prev = -2; // 3 (kondisi 1) && 4 (kondisi 2)
        (*L).data[delPtr].next = -2; // 4 (kondisi 1 && 2)
    }
}

void delLast(list *L)
{

    if ((*L).first != -1)
    {
        if (countEl(*L) == 1) // jika elemen dalam list hanya 1
        {
            delFirst(L);
        }
        else // jika elemennya banyak
        {
            delAfter((*L).data[(*L).tail].prev, L);
        }
    }
    else
    {
        printf("list kosong\n");
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
            printf("%s %s %d\n", L.data[bantu].kontainer.jenis, L.data[bantu].kontainer.merk, L.data[bantu].kontainer.nama);
            bantu = L.data[bantu].next;
            i += 1;
        }
    }
    else
    {
        printf("List Kosong.\n");
    }
}

void printReverse(list L)
{
    if (L.first != -1)
    {
        int bantu = L.tail;
        int i = 1;
        while (bantu != -1)
        {
            // printf("%s %s %d\n", L.data[bantu].kontainer.tgl, L.data[bantu].kontainer.nama, L.data[bantu].kontainer.sum);
            bantu = L.data[bantu].prev;
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
    for (int i = countEl(*L); i >= 1; i--)
        delLast(L);
}

void tukarEl(list *L)
{
    int front = (*L).first;
    int back = (*L).tail;
    isiKontainer temp;
    for (int i = 0; i < countEl(*L) / 2; i++)
    {
        temp = (*L).data[front].kontainer;
        (*L).data[front].kontainer = (*L).data[back].kontainer;
        (*L).data[back].kontainer = temp;

        front = (*L).data[front].next;
        back = (*L).data[back].prev;
    }
}