/*
Saya Bayu Wicaksono NIM 2106836 mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.
*/
#include "header.h"

void createList(simpul *L) // prosedur untuk membuat list
{
    (*L).first = NULL; // inisialisasi pointer first
}

void addLast(isiKomponen komponen, simpul *L) // prosedur untuk menambahkan elemen list
{
    elemen *newptr = (elemen *)malloc(sizeof(elemen)); // alokasi memori
    newptr->komponen = komponen;                       // copy data
    //
    if ((*L).first == NULL) // jika list kosong
    {
        newptr->next = (*L).first;
        (*L).first = newptr;
    }
    else // jika list ada isinya
    {
        elemen *prev = (*L).first;
        while (prev->next != NULL) // mencari list terakhir
            prev = prev->next;
        newptr->next = NULL;
        prev->next = newptr;
    }
    newptr = NULL;
}

void makeTree(isiKontainer kontainer, tree *T, simpul *L) // prosedur untuk membuat tree
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul)); // alokasi memori

    node->kontainer = kontainer; // copy data

    // setting pointer tree
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
    // setting pointer list
    (*T).root->first = (*L).first;
    (*L).first = NULL;
}

void addChild(isiKontainer kontainer, simpul *root, simpul *L) // prosedur untuk menambahkan node tree
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong, berarti dapat ditambahkan simpul anak */
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul)); // alokasi memori

        baru->kontainer = kontainer; // copy data
        // setting pointer list
        baru->first = (*L).first;
        (*L).first = NULL;

        // setting pointer tree
        baru->child = NULL;
        if (root->child == NULL)
        {
            /* jika simpul root belum memiliki simpul anak maka simpul baru menjadi anak pertama */
            baru->sibling = NULL;
            root->child = baru;
        }
        else
        {
            if (root->child->sibling == NULL)
            {
                /* jika simpul root memiliki anak yang belum memiliki saudara, maka simpul baru menjadi anak kedua */
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
            else
            {
                simpul *last = root->child;
                /* mencari simpul anak terakhir karena akan dikaitkan dengan simpul baru sebagai simpul anak terakhir yang
               baru, simpul anak terakhir adalah yang memiliki sibling simpul anak pertama, maka selama belum sampai pada simpul
               anak terakhir, penunjuk last akan berjalan ke simpul anak berikutnya */
                while (last->sibling != root->child)
                {
                    last = last->sibling;
                }
                baru->sibling = root->child;
                last->sibling = baru;
            }
        }
    }
}

void delLast(simpul *L) // prosedur untuk menghapus list
{
    if ((*L).first != NULL) // jika list tidak kosong
    {
        elemen *delptr = (*L).first;
        if (delptr->next == NULL) // jika elemen list hanya 1
        {
            (*L).first = NULL;
        }
        else // jika elemen list > 1
        {
            elemen *prev;
            while (delptr->next != NULL) // mencari elemen terakhir
            {
                prev = delptr;
                delptr = delptr->next;
            }
            prev->next = NULL;
        }
        free(delptr); // free memori
    }
}

void delAllList(simpul *L) // prosedur untuk menghapus semua list
{
    if ((*L).first != NULL)        // jika elemen list tidak kosong
        while ((*L).first != NULL) // selama list tidak kosong
            delLast(L);            // menghapus dari elemen terakhir
}

void delAll(simpul *root) // prosedur untuk menghapus semua node tree dari root tertentu
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong */
        if (root->child != NULL) // jika memiliki simpul child
        {
            if (root->child->sibling == NULL)
            {
                /* jika hanya memiliki satu simpul anak */
                delAll(root->child); // rekursif
                delAllList(root);    // menghapus semua komponen dari root
                free(root);          // free memori
            }
            else // jika child > 1
            {
                simpul *last = root->child;
                while (last->sibling != root->child) // mencari sibling terakhir
                {
                    last = last->sibling;
                }
                simpul *bantu;
                simpul *proses;
                bantu = root->child;
                // menelusuri semua sibling dari child dan mengatur pointernya
                while (bantu->sibling != root->child && bantu->sibling != NULL)
                {
                    proses = bantu;
                    bantu = bantu->sibling;
                    root->child = proses->sibling;
                    proses->sibling = NULL;
                    if (last == root->child)
                    {
                        last->sibling = NULL;
                    }
                    else
                    {
                        last->sibling = root->child;
                    }
                    delAll(proses); // rekursif
                }
                if (bantu != NULL)
                {
                    root->child = NULL;
                    proses = bantu;
                    delAll(proses); // rekursif
                }
                delAllList(root); // menghapus semua komponen dari node
                free(root);       // free memori
            }
        }
        else // jika tidak memiliki simpul child
        {
            delAllList(root); // menghapus semua komponen dari node
            free(root);       // free memori
        }
    }
}

void delChild(simpul *tujuan, simpul *root) // prosedur untuk menghapus node tree
{
    if (root != NULL)
    {
        simpul *hapus = root->child;
        if (hapus != NULL)
        {
            if (hapus->sibling == NULL)
            {
                /*jika hanya mempunyai satu anak*/
                if (root->child == tujuan)
                {
                    delAll(root->child);
                    root->child = NULL;
                }
            }
            else
            {
                /*jika memiliki lebih dari satu simpul anak*/
                simpul *prev = NULL;
                /*mencari simpul yang akan dihapus*/
                int ketemu = 0;
                while ((hapus->sibling != root->child) && (ketemu == 0))
                {
                    if (hapus == tujuan)
                    {
                        ketemu = 1;
                    }
                    else
                    {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                if ((ketemu == 0) && (hapus == tujuan))
                {
                    ketemu = 1;
                }
                if (ketemu == 1)
                {
                    simpul *last = root->child;
                    /* mencari simpul anak terakhir untuk membantu proses atau pemeriksaan jika yang dihapus nantinya anak terakhir */
                    while (last->sibling != root->child)
                    {
                        last = last->sibling;
                    }
                    if (prev == NULL)
                    {
                        /*jika simpul yang dihapus anak pertama*/
                        if ((hapus->sibling == last) && (last->sibling == root->child))
                        {
                            /*jika hanya ada dua anak*/
                            root->child = last;
                            last->sibling = NULL;
                        }
                        else
                        {
                            /* jika memiliki simpul anak lebih dari dua simpul */
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                            hapus->sibling = NULL; // tambahan (!)
                        }
                    }
                    else
                    {
                        if ((prev == root->child) && (last->sibling == root->child) && (hapus == last))
                        {
                            /* jika hanya ada dua simpul anak dan yang dihapus adalah simpul anak kedua */
                            root->child->sibling = NULL;
                            hapus->sibling = NULL; // tambahan (!)
                        }
                        else
                        {
                            /* jika yang dihapus bukan simpul anak pertama dan simpul root memiliki simpul anak lebih dari dua simpul */
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAll(hapus); // menghapus node dan childnya jika ada
                }
            }
        }
    }
}

simpul *findNode(int batas, simpul *root) // fungsi untuk mencari node yang nilai_jualnya < batas
{
    simpul *hasil = NULL;
    if (root != NULL)
    {
        if (root->kontainer.nilaiJual < batas) // cek root
        {
            hasil = root;
        }
        else // cek child/sibling
        {
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {
                    /*jika memiliki satu simpul anak*/
                    if (bantu->kontainer.nilaiJual < batas)
                    {
                        hasil = bantu;
                    }
                    else
                    {
                        hasil = findNode(batas, bantu);
                    }
                }
                else
                {
                    /*jika memiliki banyak simpul anak*/
                    int ketemu = 0;
                    while (bantu->sibling != root->child && ketemu == 0)
                    {
                        if (bantu->kontainer.nilaiJual < batas)
                        {
                            hasil = bantu;
                            ketemu = 1;
                        }
                        else
                        {
                            hasil = findNode(batas, bantu);
                            if (hasil != 0)
                            {
                                ketemu = 1;
                            }
                            bantu = bantu->sibling;
                        }
                    }
                    if (ketemu == 0)
                    {
                        if (bantu->kontainer.nilaiJual < batas)
                        {
                            hasil = bantu;
                        }
                        else
                        {
                            hasil = findNode(batas, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}

simpul *findSimpul(char tujuan[], simpul *root) // fungsi untuk mencari node berdasarkan tujuan
{
    simpul *hasil = NULL;
    if (root != NULL)
    {
        if (strcmp(root->kontainer.namaProduk, tujuan) == 0) // cek root
        {
            hasil = root;
        }
        else // cek child/sibling
        {
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {
                    /*jika memiliki satu simpul anak*/
                    if (strcmp(bantu->kontainer.namaProduk, tujuan) == 0)
                    {
                        hasil = bantu;
                    }
                    else
                    {
                        hasil = findSimpul(tujuan, bantu);
                    }
                }
                else
                {
                    /*jika memiliki banyak simpul anak*/
                    int ketemu = 0;
                    while ((bantu->sibling != root->child) && (ketemu == 0))
                    {

                        if (strcmp(bantu->kontainer.namaProduk, tujuan) == 0)
                        {
                            hasil = bantu;
                            ketemu = 1;
                        }
                        else
                        {
                            hasil = findSimpul(tujuan, bantu);
                            if (hasil != 0)
                            {
                                // jika ditemukan dalam rekursif
                                ketemu = 1; // tandai
                            }
                            bantu = bantu->sibling;
                        }
                    }
                    if (ketemu == 0)
                    {
                        if (strcmp(bantu->kontainer.namaProduk, tujuan) == 0)
                        {
                            hasil = bantu;
                        }
                        else
                        {
                            hasil = findSimpul(tujuan, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}

void printSpasi(int n) // prosedur untuk menampilkan spasi
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void printTreePreOrder(simpul *root, int level, int spasi[]) // prosedur untuk menampilkan tree secara pre order
{
    if (root != NULL)
    {
        // print kontainer
        printSpasi(spasi[level]);
        printf("|%s - %d", root->kontainer.namaProduk, root->kontainer.nilaiJual);
        // print komponen
        elemen *ptr = root->first;
        while (ptr != NULL)
        {
            printf("\n");
            printSpasi(spasi[level]);
            printf(" - %s", ptr->komponen.namaKomponen);
            ptr = ptr->next;
        }
        printf("\n");
        //
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            printf("\n");
            if (bantu->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                printTreePreOrder(bantu, ++level, spasi);
                --level;
            }
            else
            {
                /*jika memiliki banyak simpul anak*/
                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    printTreePreOrder(bantu, ++level, spasi);
                    --level;
                    bantu = bantu->sibling;
                    printf("\n");
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                printTreePreOrder(bantu, ++level, spasi);
                --level;
            }
        }
    }
}

int strInt(char str[]) // fungsi untuk mengubah str menjadi int
{
    int res = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        res = res * 10 + str[i] - '0';
    }
    return res;
}

void pisahStr(char str[], char nama[], char namaParent[], int *nilai, int *tot, int *n, char delimiter) // prosedur untuk memisahkan str input
{
    // inisialisasi variabel tampungan
    char temp1[100], temp2[100];
    int sign = 0, idx = 0, idx1 = 0, idx2 = 0, idx3 = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == delimiter) // jika delimiter maka akan dilewati
        {
            sign++;
            continue;
        }
        if (sign == 0) // untuk nama simpul
        {
            nama[idx] = str[i];
            idx++;
        }
        else if (sign == 1) // untuk simpul parentnya
        {
            namaParent[idx1] = str[i];
            idx1++;
        }
        else if (sign == 2) // untuk nilai jualnya
        {
            temp1[idx2] = str[i];
            idx2++;
        }
        else // untuk jumlah komponen
        {
            temp2[idx3] = str[i];
            idx3++;
        }
    }
    // yang tipenya string index terakhirnya di null
    nama[idx] = '\0';
    namaParent[idx1] = '\0';
    temp1[idx2] = '\0';
    temp2[idx3] = '\0';
    // yang tipenya int, memanggil fungsi untuk mengubah string menjadi integer
    *nilai = strInt(temp1);
    *n = strInt(temp2);

    *tot = idx2; // untuk menyimpan panjang digit nilai jual
}

int maxLenList(simpul *root) // prosedur untuk mencari str terpanjang untuk komponen
{
    int temp = 0;
    elemen *bantu = root->first;
    while (bantu != NULL) // menelusuri semua elemen list
    {
        // menghitung panjang untuk tiap elemen list
        int lenList = strlen(bantu->komponen.namaKomponen) + 4;
        if (lenList > temp) // di replace jika nilainya lebih besar
        {
            temp = lenList;
        }
        bantu = bantu->next;
    }
    return temp;
}

void maxSpaceLevel(simpul *root, int level, int space[]) // prosedur untuk mencari str terpanjang untuk setiap level
{
    if (root != NULL)
    {
        // panjang len kontainer node
        int lenKontainer = strlen(root->kontainer.namaProduk) + root->kontainer.digitNilai + 5;
        if (lenKontainer > space[level])
        {
            space[level] = lenKontainer;
        }
        // max len komponen
        int maxLenKom = maxLenList(root);
        if (maxLenKom > space[level])
        {
            space[level] = maxLenKom;
        }
        //
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                maxSpaceLevel(bantu, ++level, space);
                --level;
            }
            else
            {
                /*jika memiliki banyak simpul anak*/
                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {
                    maxSpaceLevel(bantu, ++level, space);
                    --level;
                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                maxSpaceLevel(bantu, ++level, space);
                --level;
            }
        }
    }
}