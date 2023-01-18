#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TP3 dalam mata kuliah Struktur Data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main()
{
    stack sMusik, sRock, sPop; // deklarasi stack
    // membuat stack kosong
    createStack(&sMusik);
    createStack(&sRock);
    createStack(&sPop);
    // membuat tampungan data masukan
    isiKontainer data;
    //
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %s %s", &data.tahun, data.judul, data.nama);
        push(data, &sMusik);
    }

    for (int i = 0; i < n; i++)
    {
        if (toAscii(sMusik.top->kontainer.judul) % 2 == 0) // jika genap maka masuk musik rock
        {
            moveElement(&sMusik, &sRock);
        }
        else // jika ganjil maka masuk musik pop
        {
            moveElement(&sMusik, &sPop);
        }
        //
    }

    //
    printf("Playlist Musik Rock:\n");
    printf("===================\n");
    if (isEmpty(sRock)) // cek elemen dalam stack
    {
        printf("BUKAN ANAK ROCK!\n");
    }
    else
    {
        printStack(sRock);
    }
    printf("\n");
    printf("Playlist Musik Pop:\n");
    printf("===================\n");
    if (isEmpty(sPop)) // cek elemen dalam stack
    {
        printf("BUKAN ANAK POP!\n");
    }
    else
    {
        printStack(sPop);
    }

    return 0;
}