/*Saya Bayu Wicaksono NIM 2106836 mengerjakan UAS dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

int main()
{
    graph G;
    createEmpty(&G);
    isiKontainer source, dest;
    // masukan
    int n, beban;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c %c %d", &source.node, &dest.node, &beban);
        if (findSimpul(source.node, G) == NULL) // jika node asal belum ada
        {
            source.visited = 0;
            addSimpul(source, &G);
        }
        if (findSimpul(dest.node, G) == NULL) // jika node tujuan belum ada
        {
            dest.visited = 0;
            addSimpul(dest, &G);
        }
        // mencari simpul asal dan simpul tujuan
        simpul *asal = findSimpul(source.node, G);
        simpul *tujuan = findSimpul(dest.node, G);
        if (asal != NULL && tujuan != NULL)
            addJalur(asal, tujuan, beban);
    }
    scanf(" %c %c", &source.node, &dest.node);
    // mencari simpul asal dan simpul tujuan yang dicari
    simpul *begin = findSimpul(source.node, G);
    simpul *end = findSimpul(dest.node, G);
    int total = 0, max = 0; // inisialisasi variabel total untuk menampung panjang jalur suatu path dan max untuk menampung jalur terpanjang
    findPath(begin, end, &max, &total);
    printf("%d\n", max);

    return 0;
}