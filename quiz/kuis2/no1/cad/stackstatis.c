#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan kuis 2 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main()
{
    stack s;           // deklarasi stack
    createStack(&s);   // membuat stack kosong
    isiKontainer data; // membuat tampungan data masukan
    //
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %s %d", data.nama, data.jenis, data.wilayah, &data.berat);
        push(data, &s);
    }

    int m;
    scanf("%d", &m);
    stack s1[m];
    isiKontainer pengiriman[m];
    for (int i = 0; i < m; i++)
    {
        createStack(&s1[i]);
        scanf("%s", pengiriman[i].jenis);
    }

    //
    for (int i = s.top; i >= 0; i--)
    {
        int sign = 0, j = 0;
        while (j < m && sign == 0)
        {
            if (strcmp(s.data[i].jenis, pengiriman[j].jenis) == 0 && sign == 0)
            {
                sign = 1;
                popPush(&s, &s1[j]);
            }
            j++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        printf("stack %s:\n", pengiriman[i].jenis);
        printStack(s1[i]);
        if (i < m - 1)
        {
            printf("\n");
        }
    }

    return 0;
}