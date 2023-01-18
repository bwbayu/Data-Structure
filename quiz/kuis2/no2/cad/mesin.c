#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan kuis 2 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
void createQueue(queue *Q) // prosedur untuk membuat queue
{
    (*Q).first = NULL;
    (*Q).last = NULL;
}
int isEmpty(queue Q) // fungsi untuk cek queue apakah queue kosong
{
    int hasil = 0;
    if (Q.first == NULL)
    {
        hasil = 1;
    }
    return hasil;
}
int countElement(queue Q) // fungsi untuk menghitung elemen dalam queue
{
    int hasil = 0;
    if (Q.first != NULL) /* queue tidak kosong */
    {

        elemen *bantu;
        /* inisialisasi */
        bantu = Q.first;
        while (bantu != NULL)
        {
            /* proses */
            hasil = hasil + 1;
            /* iterasi */
            bantu = bantu->next;
        }
    }
    return hasil;
}

void push(isiKontainer kontainer, queue *Q) // prosedur untuk menambahkan elemen ke queue
{
    elemen *newptr;                            // deklarasi pointer
    newptr = (elemen *)malloc(sizeof(elemen)); // inisialisasi memori baru
    newptr->kontainer = kontainer;
    newptr->next = NULL;
    if ((*Q).first == NULL) // jika queue masih kosong
    {
        (*Q).first = newptr;
    }
    else // jika queue ada isinya
    {
        (*Q).last->next = newptr;
    }
    (*Q).last = newptr;
    newptr = NULL;
}

void pop(queue *Q) // prosedur untuk mengeluarkan elemen dari queue
{
    if ((*Q).first != NULL) /* jika queue bukan queue kosong */
    {

        elemen *delptr = (*Q).first;
        if (countElement(*Q) == 1) // jika elemen dalam queue hanya 1
        {
            (*Q).first = NULL;
            (*Q).last = NULL;
        }
        else // jika elemen dalam queue > 1
        {
            (*Q).first = (*Q).first->next;
            delptr->next = NULL;
        }

        free(delptr);
    }
}

void popPush(queue *Q1, queue *Q2) // prosedur untuk memindahkan elemen dari satu queue ke queue lain
{
    if ((*Q1).first != NULL) /* jika queue bukan queue kosong */
    {

        elemen *moveptr = (*Q1).first;
        if (countElement(*Q1) == 1) // jika elemen di queue1 hanya 1
        {
            (*Q1).first = NULL;
            (*Q1).last = NULL;
        }
        else // kalau elemen di queue1 > 1
        {
            (*Q1).first = (*Q1).first->next;
            moveptr->next = NULL;
        }

        if ((*Q2).first == NULL) // jika queue2 nya kosong
        {
            (*Q2).first = moveptr;
        }
        else // jika queue2 ada isinya
        {
            (*Q2).last->next = moveptr;
        }
        (*Q2).last = moveptr;
        moveptr = NULL;
    }
}

void printQueue(queue Q) // prosedur untuk menampilkan isi queue
{
    if (Q.first != NULL)
    {
        elemen *bantu = Q.first;
        int i = 1;

        while (bantu != NULL)
        {
            printf("%s %s %d\n", bantu->kontainer.nama, bantu->kontainer.pekerjaan, bantu->kontainer.priority);
            /* iterasi */
            bantu = bantu->next;
            i = i + 1;
        }
    }
}

void addPriority(isiKontainer kontainer, queue *Q) // prosedur untuk menambahkan elemen ke queue berdasarkan prioritasnya
{
    elemen *newptr;                            // deklarasi pointer
    newptr = (elemen *)malloc(sizeof(elemen)); // alokasi memori baru
    newptr->kontainer = kontainer;             // copy data
    newptr->next = NULL;
    if ((*Q).first == NULL) // jika queue masih kosong
    {
        (*Q).first = newptr;
        (*Q).last = newptr;
    }
    else // jika queue ada isinya
    {
        if (kontainer.priority == 1) // jika elemen prioriti di tambahkan di depan
        {
            newptr->next = (*Q).first;
            (*Q).first = newptr;
        }
        else if (kontainer.priority > countElement(*Q)) // jika elemen prioriti di tambahkan di terakhir
        {
            (*Q).last->next = newptr;
            (*Q).last = newptr;
        }
        else // kalau elemen prioriti di tengah
        {
            elemen *bantu = (*Q).first; // inisialisasi pointer ke first
            int i = 1;
            while (bantu != NULL) // mengecek hingga elemen terakhir
            {
                if (i == (kontainer.priority - 1)) // jika ditemukan posisi dari elemen prioriti
                {
                    newptr->next = bantu->next;
                    bantu->next = newptr;
                }
                // iterasi
                bantu = bantu->next;
                i++;
            }
        }
    }
    newptr = NULL;
}