#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TP2 dalam mata kuliah Struktur Data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

// prosedur untuk membuat dynamic list ganda
void createList(list *L)
{
    // deklarasi pointer first dan tail
    (*L).first = NULL;
    (*L).tail = NULL;
}

// fungsi untuk menghitung elemen dalam list
int countEl(list L)
{
    int sum = 0;
    if (L.first != NULL) // jika bukan list kosong
    {
        elemen *ptr;
        ptr = L.first;      // inisialisasi pointer menunjuk ke elemen pertama dalam list
        while (ptr != NULL) // selama elemen dalam list tsb bukan null
        {
            // iterasi
            sum++;
            ptr = ptr->next;
        }
    }
    return sum; // mengembalikan nilai jumlah elemen dalam list
}

// prosedur untuk melakukan penambahan data di depan
void addFirst(isiKontainer kontainer, list *L)
{
    elemen *newPtr;                            // deklarasi pointer baru
    newPtr = (elemen *)malloc(sizeof(elemen)); // pointer newPtr akan menunjuk pada alokasi baru di memori

    newPtr->kontainer = kontainer; // copy data

    if ((*L).first == NULL) // kondisi ketika list kosong
    {
        // pointer next dan prev pada elemen yang ditunjuk oleh pointer newPtr di NULL kan
        newPtr->next = NULL;
        newPtr->prev = NULL;
        // pointer tail akan menunjuk ke elemen baru
        (*L).tail = newPtr;
    }
    else // kondisi ketika ada elemen dalam list
    {
        newPtr->next = (*L).first; // pointer next pada elemen yang ditunjuk oleh pointer newPtr, menunjuk ke elemen pertama dalam list
        newPtr->prev = NULL;       // pointer prev pada elemen yang ditunjuk oleh pointer newPtr di NULL kan
        (*L).first->prev = newPtr; // pointer prev dari elemen pertama menunjuk ke elemen baru
    }

    (*L).first = newPtr; // pointer first menunjuk pada elemen baru
    newPtr = NULL;       // pointer baru di null kan
}

// prosedur untuk melakukan penambahan data setelah elemen tertentu
void addAfter(elemen *before, isiKontainer kontainer, list *L)
{
    elemen *newPtr;                            // deklarasi pointer baru
    newPtr = (elemen *)malloc(sizeof(elemen)); // pointer newPtr akan menunjuk pada alokasi baru di memori

    newPtr->kontainer = kontainer; // copy data

    if (before->next == NULL) // kondisi ketika menambahkan elemen baru sebagai elemen terakhir
    {
        newPtr->next = NULL; // pointer next dari elemen baru di NULL kan
        (*L).tail = newPtr;  // pointer tail menunjuk ke elemen baru
    }
    else // kondisi ketika menambahkan elemen baru setelah elemen tertentu
    {
        newPtr->next = before->next; // pointer next dari elemen baru menunjuk ke elemen yang ditunjuk oleh pointer next dari elemen yang ditunjuk oleh pointer before
        newPtr->next->prev = newPtr; // pointer next prev dari elemen baru menunjuk ke elemen baru
    }
    newPtr->prev = before; // pointer prev dari elemen baru menunjuk ke elemen yang ditunjuk oleh pointer before
    before->next = newPtr; // pointer next dari elemen yang ditunjuk oleh pointer before menunjuk ke elemen baru
    newPtr = NULL;         // elemen baru di NULL kan
}

// prosedur untuk menambahkan data sebagai elemen terakhir
void addLast(isiKontainer kontainer, list *L)
{
    if ((*L).first == NULL)     // jika list kosong
        addFirst(kontainer, L); // menjalankan addFirst
    else                        // jika list ada isinya
    {
        addAfter((*L).tail, kontainer, L); // menjalankan addAfter
    }
}

// prosedur untuk menghapus data pada elemen pertama
void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        elemen *delPtr = (*L).first; // inisialisasi pointer del yang menunjuk ke elemen pertama
        if (countEl(*L) == 1)        // jika elemen dalam list hanya 1
        {
            // inisialisasi pointer head dan tail
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else // jika elemen dalam list banyak
        {
            (*L).first = (*L).first->next; // pointer first menunjuk ke elemen selanjutnya
            (*L).first->prev = NULL;       // pointer prev dari elemen pertama di NULL kan
            delPtr->next = NULL;           // pointer next dari elemen del di NULL kan
        }

        free(delPtr); // free memory
    }
}

// prosedur untuk menghapus data setelah elemen tertentu
void delAfter(elemen *before, list *L)
{
    elemen *delPtr = before->next; // inisialisasi pointer del menunjuk ke elemen yang ditunjuk oleh pointer next dari elemen before
    if (delPtr != NULL)            // mengecek elemen yang ditunjuk oleh pointer del
    {
        if (delPtr->next == NULL) // kondisi jika yang dihapus merupakan elemen terakhir
        {
            (*L).tail = before;  // pointer tail menunjuk ke elemen before
            before->next = NULL; // pointer next dari elemen before di NULL kan
        }
        else // kondisi jika elemen yang dihapus ada di tengah
        {
            before->next = delPtr->next; // pointer next dari elemen before menunjuk ke elemen yang ditunjuk oleh pointer next dari elemen del
            delPtr->next->prev = before; // pointer next prev dari elemen del menunjuk ke elemen before
            delPtr->next = NULL;         // pointer next dari elemen del di NULL kan
        }
        delPtr->prev = NULL; // pointer prev dari elemen del di NULL kan
        free(delPtr);        // free memory
    }
}

// prosedur untuk menampilkan bahan makanan secara terbalik
void printRev(list L)
{
    if (L.first != NULL) // jika list tidak kosong
    {
        elemen *ptr = L.tail; // inisialisasi pointer ptr menunjuk ke elemen yang ditunjuk oleh pointer tail
        int i = 1;
        while (ptr != NULL) // selama elemen ptr bukan NULL
        {
            if (ptr->kontainer.tgl < 10) // jika tanggalnya kurang dari 10
                printf("0");

            printf("%d %s\n", ptr->kontainer.tgl, ptr->kontainer.nama);
            // iterasi
            ptr = ptr->prev;
            i++;
        }
    }
    else
        printf("-\n");
}

// prosedur untuk menampilkan bahan makanan sisa
void printEl(list L)
{
    if (L.first != NULL) // jika list tidak kosong
    {
        elemen *ptr = L.first; // inisialisasi pointer ptr ke elemen pertama dalam list
        int i = 1;
        while (ptr != NULL) // selama elemen tsb bukan NULL, maka data dalam kontainernya ditampilkan
        {
            if (ptr->kontainer.tgl < 10) // jika tanggalnya kurang dari 10
                printf("0");

            printf("%d %s\n", ptr->kontainer.tgl, ptr->kontainer.nama);
            // iterasi
            ptr = ptr->next;
            i++;
        }
    }
}

// prosedur untuk menampilkan bahan makanan yang kadaluarsa
void print_bahan_ood(list *L)
{
    elemen *ptr = (*L).tail; // inisialisasi pointer ptr ke elemen terakhir
    // iterasi pointer ptr selama bahan makanan tsb belum kadaluarsa
    while (ptr != NULL && ptr->kontainer.tgl >= curr_date)
    {
        ptr = ptr->prev;
    }
    if (ptr == NULL) // cek elemen dalam list, jika elemen tsb null maka tidak ada bahan makanan yang kadaluarsa
    {
        printf("-\n");
    }
    else // jika tidak
    {
        // selama bahan makanan tsb kadaluarsa dan elemen yang ditunjuk pointer ptr bukan NULL
        while (ptr != NULL && ptr->kontainer.tgl < curr_date)
        {
            if (ptr->kontainer.tgl < 10) // jika tanggal kurang dari 10
                printf("0");
            printf("%d %s\n", ptr->kontainer.tgl, ptr->kontainer.nama);
            // iterasi mundur
            ptr = ptr->prev;
            if (ptr != NULL) // jika elemen yang ditunjuk pointer ptr bukan null
            {
                delAfter(ptr, L); // menjalankan delafter
            }
            else // jika elemen tsb null
            {
                delFirst(L); // menjalankan delfirst
            }
        }
    }
}

// prosedur sorting asc berdasarkan tanggal kadaluarsa
void sortTgl(list *L)
{
    int swap = 0; // inisialisasi tanda ada pertukaran
    do
    {
        swap = 0;
        elemen *curr = (*L).first; // inisialisasi pointer curr pada elemen pertama list
        while (curr->next != NULL) // selama elemen yang ditunjuk pointer pointer next dari curr bukan NULL
        {
            int last = 0;                                        // tanda adanya pertukaran 2 elemen di akhir list
            if (curr->kontainer.tgl > curr->next->kontainer.tgl) // cek tanggal
            {
                swap = 1;               // tanda adanya pertukaran
                if (curr == (*L).first) // jika pointer curr ada di elemen pertama
                {
                    (*L).first = curr->next; // pointer first menunjuk ke elemen yang ditunjuk oleh pointer next dari elemen curr
                    curr->next->prev = NULL; // pointer next prev dari elemen curr di NULL kan
                }
                else // jika pointer curr bukan di elemen pertama
                {
                    curr->next->prev = curr->prev; // pointer next prev dari elemen curr menunjuk ke elemen yang ditunjuk oleh pointer prev dari elemen curr
                    curr->prev->next = curr->next; // pointer prev next dari elemen curr menunjuk ke elemen yang ditunjuk oleh pointer next dari elemen curr
                }
                if (curr->next == (*L).tail) // kondisi untuk pertukaran 2 elemen terakhir
                {
                    curr->prev = curr->next; // pointer prev dari elemen curr menunjuk ke elemen yang ditunjuk oleh pointer next dari elemen curr
                    curr->next->next = curr; // pointer next next dari elemen curr menunjuk ke elemen curr
                    curr->next = NULL;       // pointer next dari elemen curr di NULL kan
                    (*L).tail = curr;        // pointer tail menunjuk ke elemen curr
                    last = 1;                // tanda adanya pertukaran elemen diakhir
                }
                if (last == 0) // jika pertukaran terjadi di awal atau tengah list
                {
                    curr->next = curr->next->next; // pointer next dari elemen curr menunjuk ke elemen yang ditunjuk oleh pointer next next dari elemen curr
                    curr->prev = curr->next->prev; // pointer prev dari elemen curr menunjuk ke elemen yang ditunjuk oleh pointer next prev dari elemen curr
                    curr->next->prev = curr;       // pointer next prev dari elemen curr menunjuk ke elemen curr
                    curr->prev->next = curr;       // pointer prev next dari elemen curr menunjuk ke elemen curr
                }
            }
            else // jika tanggal di elemen curr lebih kecil dari pada tanggal di elemen yang ditunjuk oleh pointer next dari elemen curr
            {
                curr = curr->next; // iterasi
            }
        }
    } while (swap == 1); // selama terjadi pertukaran
}

// prosedur sorting asc berdasarkan nama bahan makanan
void sortNama(list *L)
{
    int swap = 0; // inisialisasi tanda ada pertukaran
    do
    {
        swap = 0;
        elemen *curr = (*L).first; // inisialisasi pointer curr pada elemen pertama list
        while (curr->next != NULL) // selama elemen yang ditunjuk pointer pointer next dari curr bukan NULL
        {
            int last = 0;                                                     // tanda adanya pertukaran 2 elemen di akhir list
            if (strcmp(curr->kontainer.nama, curr->next->kontainer.nama) > 0) // cek tanggal
            {
                swap = 1;               // tanda adanya pertukaran
                if (curr == (*L).first) // jika pointer curr ada di elemen pertama
                {
                    (*L).first = curr->next; // pointer first menunjuk ke elemen yang ditunjuk oleh pointer next dari elemen curr
                    curr->next->prev = NULL; // pointer next prev dari elemen curr di NULL kan
                }
                else // jika pointer curr bukan di elemen pertama
                {
                    curr->next->prev = curr->prev; // pointer next prev dari elemen curr menunjuk ke elemen yang ditunjuk oleh pointer prev dari elemen curr
                    curr->prev->next = curr->next; // pointer prev next dari elemen curr menunjuk ke elemen yang ditunjuk oleh pointer next dari elemen curr
                }
                if (curr->next == (*L).tail) // kondisi untuk pertukaran 2 elemen terakhir
                {
                    curr->prev = curr->next; // pointer prev dari elemen curr menunjuk ke elemen yang ditunjuk oleh pointer next dari elemen curr
                    curr->next->next = curr; // pointer next next dari elemen curr menunjuk ke elemen curr
                    curr->next = NULL;       // pointer next dari elemen curr di NULL kan
                    (*L).tail = curr;        // pointer tail menunjuk ke elemen curr
                    last = 1;                // tanda adanya pertukaran elemen diakhir
                }
                if (last == 0) // jika pertukaran terjadi di awal atau tengah list
                {
                    curr->next = curr->next->next; // pointer next dari elemen curr menunjuk ke elemen yang ditunjuk oleh pointer next next dari elemen curr
                    curr->prev = curr->next->prev; // pointer prev dari elemen curr menunjuk ke elemen yang ditunjuk oleh pointer next prev dari elemen curr
                    curr->next->prev = curr;       // pointer next prev dari elemen curr menunjuk ke elemen curr
                    curr->prev->next = curr;       // pointer prev next dari elemen curr menunjuk ke elemen curr
                }
            }
            else // jika tanggal di elemen curr lebih kecil dari pada tanggal di elemen yang ditunjuk oleh pointer next dari elemen curr
            {
                curr = curr->next; // iterasi
            }
        }
    } while (swap == 1); // selama terjadi pertukaran
}