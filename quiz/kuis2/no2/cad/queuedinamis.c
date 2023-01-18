#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan kuis 2 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main()
{
    queue Q1, Q2;
    createQueue(&Q1);
    createQueue(&Q2);
    isiKontainer data;
    // input
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d", data.nama, data.pekerjaan, &data.priority);
        addPriority(data, &Q1); // menggunakan prosedur addpriority untuk menambahkan data berdasarkan posisi prioritasnya
    }
    int m;
    scanf("%d", &m);

    // solve
    for (int i = 0; i < m; i++) // perulangan untuk banyak pekerjaan yang telah selesai
    {
        popPush(&Q1, &Q2); // memanggil prosedur untuk memindahkan ke queue lain
    }

    // output
    printf("pekerjaan yang telah selesai:\n");
    printQueue(Q2);

    printf("\npekerjaan yang masih menanti:\n");
    printQueue(Q1);

    return 0;
}