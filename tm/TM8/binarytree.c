#include "header.h"
/*Saya Bayu Wicaksono mengerjakan TM8 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main()
{
    tree T;
    isiKontainer huruf;
    // A
    scanf(" %c", &huruf.node);
    makeTree(huruf, &T);
    // B
    scanf(" %c", &huruf.node);
    addLeft(huruf, T.root);
    // C
    scanf(" %c", &huruf.node);
    addRight(huruf, T.root);
    // D
    scanf(" %c", &huruf.node);
    addLeft(huruf, T.root->right);
    // E
    scanf(" %c", &huruf.node);
    addRight(huruf, T.root->left);
    // F
    scanf(" %c", &huruf.node);
    addRight(huruf, T.root->right);
    // G
    scanf(" %c", &huruf.node);
    addLeft(huruf, T.root->left->right);
    // H
    scanf(" %c", &huruf.node);
    addRight(huruf, T.root->right->left);
    // I
    scanf(" %c", &huruf.node);
    addRight(huruf, T.root->left->right);
    // J
    scanf(" %c", &huruf.node);
    addRight(huruf, T.root->right->right);
    // K
    scanf(" %c", &huruf.node);
    addLeft(huruf, T.root->right->right);
    // L
    scanf(" %c", &huruf.node);
    addLeft(huruf, T.root->left->right->left);
    // M
    scanf(" %c", &huruf.node);
    addLeft(huruf, T.root->right->left->right);
    // N
    scanf(" %c", &huruf.node);
    addRight(huruf, T.root->right->left->right);
    //
    int total = 14;
    int idx = 0;
    printf("Pre Order:\n");
    printTreePreOrder(T.root, &idx, total);
    //
    delLeft(T.root->left->right->left);
    total -= 1;
    idx = 0;
    printf("\nIn Order:\n");
    printTreeInOrder(T.root, &idx, total);
    //
    delRight(T.root->right->right);
    total -= 1;
    idx = 0;
    printf("\nPost Order:\n");
    printTreePostOrder(T.root, &idx, total);
    printf("\n");
    return 0;
}