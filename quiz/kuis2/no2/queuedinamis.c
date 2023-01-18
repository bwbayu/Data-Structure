#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan kuis 2 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main()
{
    queue Q1, Q2;
    createQueue(&Q1);
    createQueue(&Q2);
    isiKontainer data;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d", data.nama, data.pekerjaan, &data.priority);
        addPriority(data, &Q1);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        popPush(&Q1, &Q2);
    }
    printf("pekerjaan yang telah selesai:\n");
    printQueue(Q2);

    printf("\npekerjaan yang masih menanti:\n");
    printQueue(Q1);

    return 0;
}