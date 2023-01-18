#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TP5 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main()
{
    graph G;
    createEmpty(&G);
    isiKontainer source, dest;
    int beban;
    //
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c %c %d", &source.node, &dest.node, &beban);
        if (findSimpul(source.node, G) == NULL)
        {
            source.visited = 0;
            addSimpul(source, &G);
            // x++;
        }
        if (findSimpul(dest.node, G) == NULL)
        {
            dest.visited = 0;
            addSimpul(dest, &G);
            // x++;
        }
        simpul *asal = findSimpul(source.node, G);
        simpul *tujuan = findSimpul(dest.node, G);
        addJalur(asal, tujuan, beban);
    }
    scanf(" %c %c", &source.node, &dest.node);
    // printGraph(G);
    char path[n];
    int idx = 0, total = 0;
    simpul *begin = findSimpul(source.node, G);
    simpul *end = findSimpul(dest.node, G);
    findPath(begin, end, &total, path, idx);
    return 0;
}