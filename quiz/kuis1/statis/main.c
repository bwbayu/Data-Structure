#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan kuis 1 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

int main()
{
    list llist1, llist2;
    createList(&llist1);
    createList(&llist2);
    isiKontainer data;
    // masukan
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", data.str, data.str1);
        addLast(data, &llist1);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s", data.str, data.str1);
        addLast(data, &llist2);
    }

    int p;
    scanf("%d", &p);
    tukarEl(&llist1, &llist2, p);
    // printf("list1 \n");
    printEl(llist1);
    // printf("list2 \n");
    printEl(llist2);

    return 0;
}