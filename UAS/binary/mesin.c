/*Saya Bayu Wicaksono NIM 2106836 mengerjakan UAS dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

void makeTree(int data, tree *T) // prosedur untuk membuat tree
{
    // deklarasi pointer dan inisialisasi memori
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    // copy
    baru->kontainer.node = data;
    //
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    baru = NULL;
}

void addRight(int data, simpul *root) // prosedur untuk menambahkan elemen di kanan tree
{
    if (root != NULL)
    {
        if (root->right == NULL) /*jika sub pohon kanan kosong*/
        {
            simpul *baru;
            baru = (simpul *)malloc(sizeof(simpul));
            //
            baru->kontainer.node = data;
            baru->right = NULL;
            baru->left = NULL;
            root->right = baru;
            baru = NULL;
        }
    }
}

void addLeft(int data, simpul *root) // prosedur untuk menambahkan elemen di kiri tree
{
    if (root != NULL)
    {
        if (root->left == NULL) /*jika sub pohon kiri kosong*/
        {
            simpul *baru;
            baru = (simpul *)malloc(sizeof(simpul));
            //
            baru->kontainer.node = data;
            baru->right = NULL;
            baru->left = NULL;
            root->left = baru;
            //
            baru = NULL;
        }
    }
}

void generate(int data, simpul *root) // prosedur untuk mengenerate simpul anak
{
    data = sqrt(data); // mencari akar kuadrat dari data parent
    if (data > 1)      // jika nilai data lebih dari 1, maka simpul anak akan ditambahkan dan pohon akan di generate lagi
    {
        if (data % 2 == 0) // jika genap
        {
            addRight(data, root);
            generate(data, root->right);
        }
        else // jika ganjil
        {
            addLeft(data, root);
            generate(data, root->left);
        }
    }
    else if (data == 1) // jika nilai data sama dengan 1, maka simpul anak akan ditambahkan dan pohon tidak akan di generate lagi
    {
        if (data % 2 == 0) // jika genap
        {
            addRight(data, root);
        }
        else // jika ganjil
        {
            addLeft(data, root);
        }
    }
}

void printTreePostOrder(simpul *root, int *sign) // prosedur untuk menampilkan pohon biner secara postorder
{
    if (root != NULL)
    {
        printTreePostOrder(root->left, sign);
        printTreePostOrder(root->right, sign);
        if (*sign == 0)
        {
            printf("%d", root->kontainer.node);
            *sign = 1;
        }
        else
        {
            printf(" %d", root->kontainer.node);
        }
    }
}