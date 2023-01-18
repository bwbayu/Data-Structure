#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan kuis 1 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

// prosedur untuk membuat dynamic list
void createList(list *L)
{
    (*L).first = NULL; // inisialisasi pointer first
}
// prosedur untuk melakukan penambahan data di depan
void addFirst(isiKontainer kontainer, list *L)
{
    elemen *newPtr;                            // deklarasi pointer baru
    newPtr = (elemen *)malloc(sizeof(elemen)); // pointer newPtr akan menunjuk pada alokasi baru di memori

    newPtr->kontainer = kontainer; // copy data

    if ((*L).first == NULL)        // kondisi ketika list kosong
        newPtr->next = NULL;       // pointer next pada elemen yang ditunjuk oleh pointer newPtr di NULL kan
    else                           // kondisi ketika ada elemen dalam list
        newPtr->next = (*L).first; // pointer next pada elemen yang ditunjuk oleh pointer newPtr, menunjuk ke elemen pertama dalam list

    (*L).first = newPtr; // pointer first menunjuk pada elemen baru
    newPtr = NULL;       // pointer baru di NULL kan
}

// prosedur untuk melakukan penambahan data setelah elemen tertentu
void addAfter(elemen *prev, isiKontainer kontainer, list *L)
{
    elemen *newPtr;                            // deklarasi pointer baru
    newPtr = (elemen *)malloc(sizeof(elemen)); // pointer newPtr akan menunjuk pada alokasi baru di memori
    newPtr->kontainer = kontainer;             // copy data
    if (prev->next == NULL)                    // kondisi ketika menambahkan elemen baru sebagai elemen terakhir
        newPtr->next = NULL;                   // pointer next pada elemen yang ditunjuk oleh pointer newPtr di NULL kan
    else                                       // kondisi ketika menambahkan elemen baru sebagai elemen pada index tertentu
        newPtr->next = prev->next;             // pointer next pada elemen yang ditunjuk oleh pointer newPtr, menunjuk ke elemen yang ditunjuk oleh pointer prev->next

    prev->next = newPtr; // pointer next pada elemen yang ditunjuk oleh pointer prev, menunjuk ke elemen yang ditunjuk oleh pointer newPtr
    newPtr = NULL;       // pointer baru di NULL kan
}
// prosedur untuk menambahkan data sebagai elemen terakhir
void addLast(isiKontainer kontainer, list *L)
{
    if ((*L).first == NULL)     // kondisi jika list kosong
        addFirst(kontainer, L); // menjalankan addFirst
    else                        // jika ada elemen dalam list
    {
        elemen *prev = (*L).first;    // pointer prev menunjuk pada elemen pertama dalam list
        while (prev->next != NULL)    // mencari elemen terakhir
            prev = prev->next;        // iterasi
        addAfter(prev, kontainer, L); // menjalankan prosedur addAfter kondisi if
    }
}
// prosedur untuk menampilkan seluruh elemen
void printEl(list L)
{
    if (L.first != NULL) // jika list tidak kosong
    {
        elemen *ptr = L.first; // inisialisasi pointer ptr dengan elemen pertama dalam list
        int i = 1;             // inisialisai variabel i
        while (ptr != NULL)    // selama elemen tsb bukan NULL, maka data dalam kontainernya ditampilkan
        {
            printf("%s %s %s\n", ptr->kontainer.jenis, ptr->kontainer.merk, ptr->kontainer.nama);
            // iterasi
            ptr = ptr->next;
            i++;
        }
    }
}
// prosedur untuk membagi dari 1 list menjadi 3 list
void bagiList(list *L, list *L1, list *L2, list *L3)
{
    if ((*L).first != NULL) // jika list tidak kosong
    {
        while ((*L).first != NULL) // selama list tidak kosong
        {
            if (strcmp((*L).first->kontainer.jenis, "action_figure") == 0) // jika jenisnya action_figure
            {
                if ((*L1).first == NULL) // jika list 1 masih kosong
                {
                    (*L1).first = (*L).first;      // pointer first dari list 1 akan menunjuk ke elemen yang ditunjuk oleh pointer first dari list
                    (*L).first = (*L).first->next; // pointer first dari list akan menunjuk ke elemen selanjutnya
                    (*L1).first->next = NULL;      // pointer next pada elemen yang ditunjuk oleh pointer first dari list 1 di NULL kan
                }
                else // jika list tidak kosong
                {
                    elemen *curr = (*L).first;     // inisialisasi pointer yang menunjuk ke elemen pertama
                    (*L).first = (*L).first->next; // pointer first dari list akan menunjuk ke elemen selanjutnya
                    curr->next = (*L1).first;      // pointer next pada elemen yang ditunjuk oleh pointer curr, menunjuk ke elemen yang ditunjuk oleh pointer first dari list 1
                    (*L1).first = curr;            // pointer first dari list 1 menunjuk ke elemen yang ditunjuk oleh pointer curr
                    curr = NULL;                   // pointer curr di NULL kan
                }
            }
            else if (strcmp((*L).first->kontainer.jenis, "sepatu") == 0) // jika jenisnya sepatu
            {
                if ((*L2).first == NULL) // jika list 2 masih kosong
                {
                    (*L2).first = (*L).first;      // pointer first dari list 2 akan menunjuk ke elemen yang ditunjuk oleh pointer first dari list
                    (*L).first = (*L).first->next; // pointer first dari list akan menunjuk ke elemen selanjutnya
                    (*L2).first->next = NULL;      // pointer next pada elemen yang ditunjuk oleh pointer first dari list 2 di NULL kan
                }
                else // jika list 2 ada isinya
                {
                    elemen *curr = (*L).first;     // inisialisasi pointer yang menunjuk ke elemen pertama
                    (*L).first = (*L).first->next; // pointer first dari list akan menunjuk ke elemen selanjutnya
                    curr->next = (*L2).first;      // pointer next pada elemen yang ditunjuk oleh pointer curr, menunjuk ke elemen yang ditunjuk oleh pointer first dari list 2
                    (*L2).first = curr;            // pointer first dari list 2 menunjuk ke elemen yang ditunjuk oleh pointer curr
                    curr = NULL;                   // pointer curr di NULL kan
                }
            }
            else if (strcmp((*L).first->kontainer.jenis, "sepeda") == 0) // jika jenisnya sepeda
            {
                if ((*L3).first == NULL) // jika list 3 masih kosong
                {
                    (*L3).first = (*L).first;      // pointer first dari list 3 akan menunjuk ke elemen yang ditunjuk oleh pointer first dari list
                    (*L).first = (*L).first->next; // pointer first dari list akan menunjuk ke elemen selanjutnya
                    (*L3).first->next = NULL;      // pointer next pada elemen yang ditunjuk oleh pointer first dari list 3 di NULL kan
                }
                else // jika list 3 sudah ada isinya
                {
                    elemen *curr = (*L).first;     // inisialisasi pointer yang menunjuk ke elemen pertama
                    (*L).first = (*L).first->next; // pointer first dari list akan menunjuk ke elemen selanjutnya
                    curr->next = (*L3).first;      // pointer next pada elemen yang ditunjuk oleh pointer curr, menunjuk ke elemen yang ditunjuk oleh pointer first dari list 3
                    (*L3).first = curr;            // pointer first dari list 3 menunjuk ke elemen yang ditunjuk oleh pointer curr
                    curr = NULL;                   // pointer curr di NULL kan
                }
            }
        }
    }
}