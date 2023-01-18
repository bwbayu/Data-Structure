#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP1 dalam mata kuliah Struktur Data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

// prosedur untuk membuat dynamic list
void createList(list *L)
{
    (*L).first = NULL;
}

// fungsi untuk menghitung elemen dalam list
int countEl(list L)
{
    // inisialisasi untuk tampungan jumlah elemen di list
    int sum = 0;
    if (L.first != NULL)
    {
        elemen *ptr;   // deklarasi pointer
        ptr = L.first; // pointer menunjuk elemen di pointer first
        while (ptr != NULL)
        {
            sum++;
            ptr = ptr->next; // pointer mengarahkan pada elemen selanjutnya melalui pointer next
        }
    }
    return sum; // mengembalikan nilai
}

// prosedur untuk melakukan penambahan data di depan
void addFirst(isiKontainer kontainer, list *L)
{
    elemen *newPtr; // deklarasi pointer baru
    newPtr = (elemen *)malloc(sizeof(elemen));
    // copy data
    strcpy(newPtr->kontainer.judul, kontainer.judul);
    strcpy(newPtr->kontainer.prod, kontainer.prod);
    newPtr->kontainer.rate = kontainer.rate;

    if ((*L).first == NULL) // kondisi ketika list kosong
        newPtr->next = NULL;
    else // kondisi ketika ada elemen dalam list
        newPtr->next = (*L).first;

    (*L).first = newPtr; // pointer first menunjuk pada elemen baru
    newPtr = NULL;       // pointer baru di NULL kan
}

// prosedur untuk melakukan penambahan data setelah elemen tertentu
void addAfter(elemen *prev, isiKontainer kontainer, list *L)
{
    elemen *newPtr; // deklarasi pointer baru
    newPtr = (elemen *)malloc(sizeof(elemen));
    // copy data
    strcpy(newPtr->kontainer.judul, kontainer.judul);
    strcpy(newPtr->kontainer.prod, kontainer.prod);
    newPtr->kontainer.rate = kontainer.rate;

    if (prev->next == NULL) // kondisi ketika menambahkan elemen baru sebagai elemen terakhir
        newPtr->next = NULL;
    else // kondisi ketika menambahkan elemen baru sebagai elemen pada index tertentu
        newPtr->next = prev->next;

    prev->next = newPtr; // pointer prev.next menunjuk pada elemen baru
    newPtr = NULL;       // pointer baru di NULL kan
}

// prosedur untuk menambahkan data sebagai elemen terakhir
void addLast(isiKontainer kontainer, list *L)
{
    if ((*L).first == NULL) // kondisi jika list kosong
        addFirst(kontainer, L);
    else // jika ada elemen dalam list
    {
        elemen *prev = (*L).first;    // pointer prev menunjuk pada elemen yang ditunjuk oleh pointer first
        while (prev->next != NULL)    // mencari elemen terakhir
            prev = prev->next;        // iterasi
        addAfter(prev, kontainer, L); // menjalankan prosedur addAfter kondisi 1
    }
}

// prosedur untuk menghapus data pada elemen pertama
void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        elemen *delPtr = (*L).first; // pointer hapus menunjuk pada elemen yang ditunjuk oleh pointer first
        // jika elemen dalam list hanya 1
        if (countEl(*L) == 1)
            (*L).first = NULL; // pointer first di NULL kan
        else                   // jika elemen dalam list > 1
        {
            (*L).first = (*L).first->next; // pointer first menunjuk pada elemen yang ditunjuk oleh pointer first.next
            delPtr->next = NULL;           // pointer hapus.next di NULL kan
        }
        free(delPtr); // free memory
    }
}

// prosedur untuk menghapus data setelah elemen tertentu
void delAfter(elemen *prev, list *L)
{
    elemen *delPtr = prev->next; // menginisialisasi pointer hapus pada elemen yang ditunjuk pointer prev.next
    if (delPtr != NULL)
    {
        // kondisi jika yang dihapus merupakan elemen terakhir
        if (delPtr->next == NULL)
            prev->next = NULL; // pointer prev.next di NULL kan
        else                   // kondisi jika elemen yang dihapus ada di tengah
        {
            prev->next = delPtr->next; // pointer prev.next menunjuk pada elemen yang ditunjuk oleh pointer hapus.next
            delPtr->next = NULL;       // pointer hapus.next di NULL kan
        }
        free(delPtr); // free memory
    }
}

// prosedur untuk menghapus data yang ada di elemen terakhir
void delLast(list *L)
{
    if ((*L).first != NULL)
    {
        // jika elemen hanya ada 1
        if (countEl(*L) == 1)
            delFirst(L); // menjalankan prosedur delFirst kondisi 1
        else
        {
            elemen *delPtr = (*L).first; // inisialisasi pointer hapus pada elemen yang ditunjuk oleh pointer first
            elemen *prev;                // deklarasi pointer prev
            while (delPtr->next != NULL) // mencari elemen terakhir
            {
                prev = delPtr;         // pointer prev akan menempati elemen yang ditunjuk oleh pointer hapus
                delPtr = delPtr->next; // pointer hapus menunjuk pada elemen yang ditunjuk oleh pointer hapus.next
            }
            delAfter(prev, L);
        }
    }
}

// prosedur untuk menampilkan seluruh elemen
void printEl(list L)
{
    elemen *ptr = L.first; // inisialisasi pointer ptr untuk list yang akan ditampilkan
    int i = 1;
    while (ptr != NULL) // selama elemen dalam list tsb bukan NULL, maka data akan ditampilkan
    {
        printf("%s - %s\n", ptr->kontainer.judul, ptr->kontainer.prod);
        ptr = ptr->next;
        i++;
    }
}

// ------------------------NOTE--------------------------
// parameter kontainer itu untuk menampung elemen pada dynamic list yang belum terurut, kita sebut saja ini list tidak terurut
// parameter *L itu untuk menampung elemen yang sudah diurutkan, kita sebut saja ini list terurut
// ------------------------------------------------------

// prosedur untuk mengurutkan list berdasarkan judul secara ascending
void judulAsc(isiKontainer kontainer, list *L)
{
    elemen *prev = (*L).first; // inisialisasi pointer prev untuk list yang sudah diurutkan
    // jika list tsb kosong atau
    // jika judul pada elemen list terurut pertama >= judul pada elemen list tidak terurut
    // maka akan menjalankan prosedur addFirst
    if (prev == NULL || strcmp(prev->kontainer.judul, kontainer.judul) >= 0)
    {
        addFirst(kontainer, L);
    }
    else
    {
        elemen *curr; // deklarasi pointer
        // perulangan untuk mencari tempat suatu elemen pada list terurut
        // perulangan terjadi selama judul pada elemen list terurut < judul pada elemen list tidak terurut
        while (prev->next != NULL && strcmp(prev->kontainer.judul, kontainer.judul) < 0)
        {
            curr = prev;       // pointer curr akan menempati elemen yang ditunjuk oleh pointer prev
            prev = prev->next; // iterasi pointer prev
        }
        // ketika while sudah berhenti, program akan mengecek hal berikut:
        // jika judul pada elemen list terurut > judul pada elemen list tidak terurut maka akan menjalankan addafter dengan parameter prevnya adalah posisi pointer curr
        if (strcmp(prev->kontainer.judul, kontainer.judul) > 0)
            addAfter(curr, kontainer, L);
        else // selain itu, maka akan menjalankan addafter dengan parameter prevnya adalah posisi pointer prev
            addAfter(prev, kontainer, L);
    }
}
// prosedur untuk mengurutkan list berdasarkan judul secara descending
void judulDesc(isiKontainer kontainer, list *L)
{
    elemen *prev = (*L).first; // inisialisasi pointer prev untuk list yang sudah diurutkan
    // jika list tsb kosong atau
    // jika judul pada elemen list terurut pertama <= judul pada elemen list tidak terurut
    // maka akan menjalankan prosedur addFirst
    if (prev == NULL || strcmp(prev->kontainer.judul, kontainer.judul) <= 0)
    {
        addFirst(kontainer, L);
    }
    else
    {
        elemen *curr; // deklarasi pointer
        // perulangan untuk mencari tempat suatu elemen pada list terurut
        // perulangan terjadi selama judul pada elemen list terurut > judul pada elemen list tidak terurut
        while (prev->next != NULL && strcmp(prev->kontainer.judul, kontainer.judul) > 0)
        {
            curr = prev;       // pointer curr akan menempati elemen yang ditunjuk oleh pointer prev
            prev = prev->next; // iterasi pointer prev
        }
        // ketika while sudah berhenti, program akan mengecek hal berikut:
        // jika judul pada elemen list terurut < judul pada elemen list tidak terurut maka akan menjalankan addafter dengan parameter prevnya adalah posisi pointer curr
        if (strcmp(prev->kontainer.judul, kontainer.judul) < 0)
            addAfter(curr, kontainer, L);
        else // selain itu, maka akan menjalankan addafter dengan parameter prevnya adalah posisi pointer prev
            addAfter(prev, kontainer, L);
    }
}
// prosedur untuk mengurutkan list berdasarkan rating secara ascending
void rateAsc(isiKontainer kontainer, list *L)
{
    elemen *prev = (*L).first; // inisialisasi pointer prev untuk list yang sudah diurutkan
    // jika list tsb kosong atau
    // jika rating pada elemen list terurut pertama >= rating pada elemen list tidak terurut
    // maka akan menjalankan prosedur addFirst
    if (prev == NULL || prev->kontainer.rate >= kontainer.rate)
    {
        addFirst(kontainer, L);
    }
    else
    {
        elemen *curr; // deklarasi pointer
        // perulangan untuk mencari tempat suatu elemen pada list terurut
        // perulangan terjadi selama rating pada elemen list terurut < rating pada elemen list tidak terurut
        while (prev->next != NULL && prev->kontainer.rate < kontainer.rate)
        {
            curr = prev;       // pointer curr akan menempati elemen yang ditunjuk oleh pointer prev
            prev = prev->next; // iterasi pointer prev
        }
        // ketika while sudah berhenti, program akan mengecek hal berikut:
        // jika rating pada elemen list terurut > rating pada elemen list tidak terurut maka akan menjalankan addafter dengan parameter prevnya adalah posisi pointer curr
        if (prev->kontainer.rate > kontainer.rate)
            addAfter(curr, kontainer, L);
        else // selain itu, maka akan menjalankan addafter dengan parameter prevnya adalah posisi pointer prev
            addAfter(prev, kontainer, L);
    }
}
// prosedur untuk mengurutkan list berdasarkan rating secara descending
void rateDesc(isiKontainer kontainer, list *L)
{
    elemen *prev = (*L).first; // inisialisasi pointer prev untuk list yang sudah diurutkan
    // jika list tsb kosong atau
    // jika rating pada elemen list terurut pertama <= rating pada elemen list tidak terurut
    // maka akan menjalankan prosedur addFirst
    if (prev == NULL || prev->kontainer.rate <= kontainer.rate)
    {
        addFirst(kontainer, L);
    }
    else
    {
        elemen *curr; // deklarasi pointer
        // perulangan untuk mencari tempat suatu elemen pada list terurut
        // perulangan terjadi selama rating pada elemen list terurut > rating pada elemen list tidak terurut
        while (prev->next != NULL && prev->kontainer.rate > kontainer.rate)
        {
            curr = prev;       // pointer curr akan menempati elemen yang ditunjuk oleh pointer prev
            prev = prev->next; // iterasi pointer prev
        }
        // ketika while sudah berhenti, program akan mengecek hal berikut:
        // jika rating pada elemen list terurut < rating pada elemen list tidak terurut maka akan menjalankan addafter dengan parameter prevnya adalah posisi pointer curr
        if (prev->kontainer.rate < kontainer.rate)
            addAfter(curr, kontainer, L);
        else // selain itu, maka akan menjalankan addafter dengan parameter prevnya adalah posisi pointer prev
            addAfter(prev, kontainer, L);
    }
}
// prosedur untuk menghapus semua elemen dalam list
void delAll(list *L)
{
    if (countEl(*L) != 0)
    {
        for (int i = 0; i < countEl(*L); i++)
        {
            delLast(L); // menghapus dari elemen terakhir
        }
    }
}