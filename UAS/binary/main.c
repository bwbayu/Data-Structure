/*Saya Bayu Wicaksono NIM 2106836 mengerjakan UAS dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
#include "header.h"

int main()
{
    tree T;
    isiKontainer data;
    // masukan
    scanf("%d", &data.node);
    makeTree(data.node, &T);     // memanggil prosedur untuk membuat pohon
    generate(data.node, T.root); // memanggil prosedur untuk membuat simpul anak dari pohon
    int sign = 0;
    printTreePostOrder(T.root, &sign); // prosedur untuk print pohon
    printf("\n");
    return 0;
}