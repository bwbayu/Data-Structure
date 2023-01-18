#include "header.h"
/*Saya Bayu Wicaksono mengerjakan TM9 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main()
{
    tree T;
    isiKontainer data;

    scanf("%s %d", data.k, &data.nilai);
    makeTree(data, &T);
    //
    scanf("%s %d", data.k, &data.nilai);
    addChild(data, T.root);
    //
    scanf("%s %d", data.k, &data.nilai);
    addChild(data, T.root);
    //
    scanf("%s %d", data.k, &data.nilai);
    addChild(data, T.root);
    //
    scanf("%s %d", data.k, &data.nilai);
    addChild(data, T.root->child);
    //
    scanf("%s %d", data.k, &data.nilai);
    addChild(data, T.root->child);
    //
    printf("Step 1:\n");
    printf("================\n");
    //
    int idx = 0, batas = 6;
    printTreePreOrder(T.root, &idx, batas);
    //
    printf("\n");
    idx = 0;
    printTreePostOrder(T.root, &idx, batas);
    //
    delChild(T.root->child->child->sibling, T.root->child);
    //
    printf("\n");
    idx = 0, batas = 5;
    printTreePreOrder(T.root, &idx, batas);
    //
    printf("\n");
    idx = 0;
    printTreePostOrder(T.root, &idx, batas);
    printf("\n");
    //
    scanf("%s %d", data.k, &data.nilai);
    addChild(data, T.root->child->sibling);
    //
    scanf("%s %d", data.k, &data.nilai);
    addChild(data, T.root->child->sibling);
    //
    scanf("%s %d", data.k, &data.nilai);
    addChild(data, T.root->child->sibling->sibling);
    //
    idx = 0, batas = 8;
    printTreePreOrder(T.root, &idx, batas);

    return 0;
}
