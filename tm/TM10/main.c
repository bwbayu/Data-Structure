#include "header.h"

int main()
{
    graph G;
    createEmpty(&G);
    isiKontainer data, hapus;
    scanf("%d", &hapus.nomor);
    //
    data.nomor = 1;
    addSimpul(data, &G);
    data.nomor = 2;
    addSimpul(data, &G);
    data.nomor = 3;
    addSimpul(data, &G);
    data.nomor = 4;
    addSimpul(data, &G);
    data.nomor = 5;
    addSimpul(data, &G);
    data.nomor = 6;
    addSimpul(data, &G);
    data.nomor = 7;
    addSimpul(data, &G);
    data.nomor = 8;
    addSimpul(data, &G);
    //
    data.nomor = 5;
    simpul *begin = findSimpul(data, G);
    data.nomor = 6;
    simpul *end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }
    //
    data.nomor = 6;
    begin = findSimpul(data, G);
    data.nomor = 3;
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }
    //
    data.nomor = 3;
    begin = findSimpul(data, G);
    data.nomor = 8;
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }
    //
    data.nomor = 8;
    begin = findSimpul(data, G);
    data.nomor = 1;
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }
    //
    data.nomor = 3;
    begin = findSimpul(data, G);
    data.nomor = 1;
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }
    //
    data.nomor = 8;
    begin = findSimpul(data, G);
    data.nomor = 6;
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }
    //
    data.nomor = 3;
    begin = findSimpul(data, G);
    data.nomor = 7;
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }
    //
    data.nomor = 7;
    begin = findSimpul(data, G);
    data.nomor = 4;
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }
    //
    data.nomor = 4;
    begin = findSimpul(data, G);
    data.nomor = 2;
    end = findSimpul(data, G);
    if ((begin != NULL) && (end != NULL))
    {
        addJalur(begin, end);
    }
    //
    printGraph(G);
    printf("==============\n");

    delSimpul(hapus, &G);
    printGraph(G);

    return 0;
}

// data.node = 'A';
// addSimpul(data, &G);
// data.node = 'B';
// addSimpul(data, &G);
// data.node = 'C';
// addSimpul(data, &G);
// data.node = 'D';
// addSimpul(data, &G);
// data.node = 'E';
// addSimpul(data, &G);
// data.node = 'F';
// addSimpul(data, &G);
// //
// data.node = 'A';
// simpul *begin = findSimpul(data, G);
// data.node = 'B';
// simpul *end = findSimpul(data, G);
// if ((begin != NULL) && (end != NULL))
// {
//     addJalur(begin, end, 3);
// }
// //
// data.node = 'B';
// begin = findSimpul(data, G);
// data.node = 'D';
// end = findSimpul(data, G);
// if ((begin != NULL) && (end != NULL))
// {
//     addJalur(begin, end, 3);
// }
// //
// data.node = 'E';
// end = findSimpul(data, G);
// if ((begin != NULL) && (end != NULL))
// {
//     addJalur(begin, end, 7);
// }
// //
// data.node = 'C';
// begin = findSimpul(data, G);
// data.node = 'A';
// end = findSimpul(data, G);
// if ((begin != NULL) && (end != NULL))
// {
//     addJalur(begin, end, 3);
// }
// //
// data.node = 'D';
// begin = findSimpul(data, G);
// if ((begin != NULL) && (end != NULL))
// {
//     addJalur(begin, end, 8);
// }
// //
// data.node = 'C';
// end = findSimpul(data, G);
// if ((begin != NULL) && (end != NULL))
// {
//     addJalur(begin, end, 3);
// }
// //
// data.node = 'E';
// begin = findSimpul(data, G);
// data.node = 'D';
// end = findSimpul(data, G);
// if ((begin != NULL) && (end != NULL))
// {
//     addJalur(begin, end, 4);
// }
// //
// data.node = 'F';
// end = findSimpul(data, G);
// if ((begin != NULL) && (end != NULL))
// {
//     addJalur(begin, end, 4);
// }
// //
// data.node = 'F';
// begin = findSimpul(data, G);
// data.node = 'D';
// end = findSimpul(data, G);
// if ((begin != NULL) && (end != NULL))
// {
//     addJalur(begin, end, 2);
// }
// printf("=================\n");
// printGraph(G);
// printf("\n=================\n");
// data.node = 'G';
// begin = findSimpul(data, G);
// if (begin != NULL)
// {
//     delJalur('B', begin);
// }
// printf("=================\n");
// printf("setelah dihapus\n");
// printGraph(G);
// printf("\n=================\n");