#include "header.h"

/*Saya Bayu Wicaksono mengerjakan TP1 dalam mata kuliah Struktur Data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

// prosedur untuk membuat dynamic list
void createList(list *L)
{
    (*L).first = NULL;
}

// prosedur untuk melakukan penambahan data di depan
void addFirst(isiKontainer kontainer, list *L)
{
    elemen *newPtr;                            // deklarasi pointer baru
    newPtr = (elemen *)malloc(sizeof(elemen)); // pointer newPtr akan menunjuk pada alokasi baru di memori
    // copy data
    strcpy(newPtr->kontainer.judul, kontainer.judul);
    strcpy(newPtr->kontainer.prod, kontainer.prod);
    newPtr->kontainer.rate = kontainer.rate;
    // end of copy data

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
    // copy data
    strcpy(newPtr->kontainer.judul, kontainer.judul);
    strcpy(newPtr->kontainer.prod, kontainer.prod);
    newPtr->kontainer.rate = kontainer.rate;
    // end of copy data

    if (prev->next == NULL)        // kondisi ketika menambahkan elemen baru sebagai elemen terakhir
        newPtr->next = NULL;       // pointer next pada elemen yang ditunjuk oleh pointer newPtr di NULL kan
    else                           // kondisi ketika menambahkan elemen baru sebagai elemen pada index tertentu
        newPtr->next = prev->next; // pointer next pada elemen yang ditunjuk oleh pointer newPtr, menunjuk ke elemen yang ditunjuk oleh pointer prev->next

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
            prev = prev->next;        // increment pointer
        addAfter(prev, kontainer, L); // menjalankan prosedur addAfter kondisi if
    }
}

// prosedur untuk menampilkan seluruh elemen
void printEl(list L)
{
    elemen *ptr = L.first; // inisialisasi pointer ptr pada elemen pertama dalam list
    int i = 1;
    while (ptr != NULL) // selama elemen tsb bukan NULL, maka data dalam kontainer akan ditampilkan
    {
        printf("%s - %s\n", ptr->kontainer.judul, ptr->kontainer.prod);
        ptr = ptr->next; // increment pointer
        i++;             // increment variabel
    }
}

// prosedur untuk mengurutkan list berdasarkan judul secara ascending
void judulAsc(list *L)
{
    int swap = 0; // inisialisasi variabel sebagai tanda proses sorting masih berlanjut
    do
    {
        swap = 0;                        // inisialisasi ulang variabel swap
        elemen *prev = (*L).first;       // inisialisasi pointer prev dengan menunjuk elemen yang ditunjuk oleh pointer first
        elemen *move = (*L).first->next; // inisialisasi pointer move dengan menunjuk elemen yang ditunjuk oleh pointer first->next
        elemen *temp;                    // inisialisasi pointer prev
        while (move != NULL)             // perulangan hingga pointer move menunjuk NULL
        {
            if (strcmp(prev->kontainer.judul, move->kontainer.judul) > 0) // jika data judul pada pointer prev > data judul pada pointer move
            {
                if (prev == (*L).first) // jika pointer prev ada di elemen pertama list maka
                    (*L).first = move;  // pointer first menunjuk elemen yang ditunjuk oleh pointer move
                else                    // jika pointer prev tidak menunjuk pada elemen pertama list maka
                    temp->next = move;  // pointer next pada elemen yang ditunjuk oleh pointer temp, menunjuk ke elemen yang ditunjuk oleh pointer move

                prev->next = move->next; // pointer next pada elemen yang ditunjuk oleh pointer prev, menunjuk ke elemen yang ditunjuk oleh pointer move->next
                move->next = prev;       // pointer next pada elemen yang ditunjuk oleh pointer move, menunjuk ke elemen yang ditunjuk oleh pointer prev

                temp = move;       // pointer temp menempati elemen yang ditunjuk oleh pointer move
                move = prev->next; // pointer move menunjuk elemen yang ditunjuk oleh pointer prev->next
                swap = 1;          // jika swap == 1 maka menandakan bahwa proses sorting masih berlanjut
            }
            else
            {                      // jika data judul pada pointer prev <= data judul pada pointer move
                temp = prev;       // pointer temp menempati elemen yang ditunjuk oleh pointer prev
                prev = prev->next; // pointer prev menunjuk elemen yang ditunjuk oleh pointer prev->next
                move = prev->next; // pointer move menunjuk elemen yang ditunjuk oleh pointer prev->next
                // ya intinya ini setiap pointer di geser ke elemen selanjutnya
            }
        }
    } while (swap == 1); // perulangan terjadi selama adanya tanda bahwa proses sorting masih berlanjut
}
// prosedur untuk mengurutkan list berdasarkan judul secara descending
void judulDesc(list *L)
{
    int swap = 0; // inisialisasi variabel sebagai tanda proses sorting masih berlanjut
    do
    {
        swap = 0;                        // inisialisasi ulang variabel swap
        elemen *prev = (*L).first;       // inisialisasi pointer prev dengan menunjuk elemen yang ditunjuk oleh pointer first
        elemen *move = (*L).first->next; // inisialisasi pointer move dengan menunjuk elemen yang ditunjuk oleh pointer first->next
        elemen *temp;                    // inisialisasi pointer prev
        while (move != NULL)             // perulangan hingga pointer move menunjuk NULL
        {
            if (strcmp(prev->kontainer.judul, move->kontainer.judul) < 0) // jika data judul pada pointer prev < data judul pada pointer move
            {
                if (prev == (*L).first) // jika pointer prev ada di elemen pertama list maka
                    (*L).first = move;  // pointer first menunjuk elemen yang ditunjuk oleh pointer move
                else                    // jika pointer prev tidak menunjuk pada elemen pertama list maka
                    temp->next = move;  // pointer next pada elemen yang ditunjuk oleh pointer temp, menunjuk ke elemen yang ditunjuk oleh pointer move

                prev->next = move->next; // pointer next pada elemen yang ditunjuk oleh pointer prev, menunjuk ke elemen yang ditunjuk oleh pointer move->next
                move->next = prev;       // pointer next pada elemen yang ditunjuk oleh pointer move, menunjuk ke elemen yang ditunjuk oleh pointer prev

                temp = move;       // pointer temp menempati elemen yang ditunjuk oleh pointer move
                move = prev->next; // pointer move menunjuk elemen yang ditunjuk oleh pointer prev->next
                swap = 1;          // jika swap == 1 maka menandakan bahwa proses sorting masih berlanjut
            }
            else
            {                      // jika data judul pada pointer prev >= data judul pada pointer move
                temp = prev;       // pointer temp menempati elemen yang ditunjuk oleh pointer prev
                prev = prev->next; // pointer prev menunjuk elemen yang ditunjuk oleh pointer prev->next
                move = prev->next; // pointer move menunjuk elemen yang ditunjuk oleh pointer prev->next
                // ya intinya ini setiap pointer di geser ke elemen selanjutnya
            }
        }
    } while (swap == 1); // perulangan terjadi selama adanya tanda bahwa proses sorting masih berlanjut
}
// prosedur untuk mengurutkan list berdasarkan rating secara ascending
void rateAsc(list *L)
{
    int swap = 0; // inisialisasi variabel sebagai tanda proses sorting masih berlanjut
    do
    {
        swap = 0;                        // inisialisasi ulang variabel swap
        elemen *prev = (*L).first;       // inisialisasi pointer prev dengan menunjuk elemen yang ditunjuk oleh pointer first
        elemen *move = (*L).first->next; // inisialisasi pointer move dengan menunjuk elemen yang ditunjuk oleh pointer first->next
        elemen *temp;                    // inisialisasi pointer prev
        while (move != NULL)             // perulangan hingga pointer move menunjuk NULL
        {
            if (prev->kontainer.rate > move->kontainer.rate) // jika data rating pada pointer prev > data rating pada pointer move
            {
                if (prev == (*L).first) // jika pointer prev ada di elemen pertama list maka
                    (*L).first = move;  // pointer first menunjuk elemen yang ditunjuk oleh pointer move
                else                    // jika pointer prev tidak menunjuk pada elemen pertama list maka
                    temp->next = move;  // pointer next pada elemen yang ditunjuk oleh pointer temp, menunjuk ke elemen yang ditunjuk oleh pointer move

                prev->next = move->next; // pointer next pada elemen yang ditunjuk oleh pointer prev, menunjuk ke elemen yang ditunjuk oleh pointer move->next
                move->next = prev;       // pointer next pada elemen yang ditunjuk oleh pointer move, menunjuk ke elemen yang ditunjuk oleh pointer prev

                temp = move;       // pointer temp menempati elemen yang ditunjuk oleh pointer move
                move = prev->next; // pointer move menunjuk elemen yang ditunjuk oleh pointer prev->next
                swap = 1;          // jika swap == 1 maka menandakan bahwa proses sorting masih berlanjut
            }
            else
            {                      // jika data rating pada pointer prev <= data rating pada pointer move
                temp = prev;       // pointer temp menempati elemen yang ditunjuk oleh pointer prev
                prev = prev->next; // pointer prev menunjuk elemen yang ditunjuk oleh pointer prev->next
                move = prev->next; // pointer move menunjuk elemen yang ditunjuk oleh pointer prev->next
                // ya intinya ini setiap pointer di geser ke elemen selanjutnya
            }
        }
    } while (swap == 1); // perulangan terjadi selama adanya tanda bahwa proses sorting masih berlanjut
}
// prosedur untuk mengurutkan list berdasarkan rating secara descending
void rateDesc(list *L)
{
    int swap = 0; // inisialisasi variabel sebagai tanda proses sorting masih berlanjut
    do
    {
        swap = 0;                        // inisialisasi ulang variabel swap
        elemen *prev = (*L).first;       // inisialisasi pointer prev dengan menunjuk elemen yang ditunjuk oleh pointer first
        elemen *move = (*L).first->next; // inisialisasi pointer move dengan menunjuk elemen yang ditunjuk oleh pointer first->next
        elemen *temp;                    // inisialisasi pointer prev
        while (move != NULL)             // perulangan hingga pointer move menunjuk NULL
        {
            if (prev->kontainer.rate < move->kontainer.rate) // jika data rating pada pointer prev < data rating pada pointer move
            {
                if (prev == (*L).first) // jika pointer prev ada di elemen pertama list maka
                    (*L).first = move;  // pointer first menunjuk elemen yang ditunjuk oleh pointer move
                else                    // jika pointer prev tidak menunjuk pada elemen pertama list maka
                    temp->next = move;  // pointer next pada elemen yang ditunjuk oleh pointer temp, menunjuk ke elemen yang ditunjuk oleh pointer move

                prev->next = move->next; // pointer next pada elemen yang ditunjuk oleh pointer prev, menunjuk ke elemen yang ditunjuk oleh pointer move->next
                move->next = prev;       // pointer next pada elemen yang ditunjuk oleh pointer move, menunjuk ke elemen yang ditunjuk oleh pointer prev

                temp = move;       // pointer temp menempati elemen yang ditunjuk oleh pointer move
                move = prev->next; // pointer move menunjuk elemen yang ditunjuk oleh pointer prev->next
                swap = 1;          // jika swap == 1 maka menandakan bahwa proses sorting masih berlanjut
            }
            else
            {                      // jika data rating pada pointer prev >= data rating pada pointer move
                temp = prev;       // pointer temp menempati elemen yang ditunjuk oleh pointer prev
                prev = prev->next; // pointer prev menunjuk elemen yang ditunjuk oleh pointer prev->next
                move = prev->next; // pointer move menunjuk elemen yang ditunjuk oleh pointer prev->next
                // ya intinya ini setiap pointer di geser ke elemen selanjutnya
            }
        }
    } while (swap == 1); // perulangan terjadi selama adanya tanda bahwa proses sorting masih berlanjut
}