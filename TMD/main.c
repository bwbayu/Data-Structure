/*
Saya Bayu Wicaksono NIM 2106836 mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.
*/
#include "header.h"

int main()
{
    tree T;
    simpul S;
    isiKontainer kontainer;
    isiKomponen temp;
    char str[200];

    int n, nKomponen = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", str);
        pisahStr(str, kontainer.namaProduk, kontainer.namaParent, &kontainer.nilaiJual, &kontainer.digitNilai, &nKomponen, '#');
        //
        createList(&S);
        for (int j = 0; j < nKomponen; j++)
        {
            scanf("%s", temp.namaKomponen);
            addLast(temp, &S);
        }

        if (strcmp(kontainer.namaParent, "null") == 0)
        {
            makeTree(kontainer, &T, &S);
        }
        else
        {
            simpul *node = findSimpul(kontainer.namaParent, T.root);
            if (node)
            {
                addChild(kontainer, node, &S);
            }
        }
    }
    int batas;
    scanf("%d", &batas);
    //
    int spaceLevel[n];
    memset(spaceLevel, 0, n * sizeof(spaceLevel[0]));
    int level = 0;
    maxSpaceLevel(T.root, level, spaceLevel);
    int spasi[n];
    int idx = 1;
    while (spaceLevel[idx] != 0)
    {
        if (idx == 1)
        {
            spasi[idx] = spaceLevel[idx - 1];
        }
        else
        {
            spasi[idx] = spaceLevel[idx - 1] + spasi[idx - 1];
        }
        idx++;
    }
    spasi[0] = 0;

    int lvl = 0;
    printTreePreOrder(T.root, lvl, spasi);
    //
    simpul *node;
    simpul *parent;
    do
    {
        node = findNode(batas, T.root);
        if (node != NULL)
        {
            parent = findSimpul(node->kontainer.namaParent, T.root);
            delChild(node, parent);
        }
    } while (node != NULL);
    int lvl1 = 0;
    //
    printf("\n");
    printTreePreOrder(T.root, lvl1, spasi);

    return 0;
}
// printf("%s\n", T.root->kontainer.namaProduk);
// printf("%s %s\n", T.root->first->komponen.namaKomponen, T.root->first->next->komponen.namaKomponen);

// printf("%s %s\n", T.root->child->kontainer.namaProduk, T.root->child->kontainer.namaParent);
// printf("%s %s %s\n", T.root->child->first->komponen.namaKomponen, T.root->child->first->next->komponen.namaKomponen, T.root->child->first->next->next->komponen.namaKomponen);