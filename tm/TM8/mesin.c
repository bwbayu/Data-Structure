#include "header.h"
/*Saya Bayu Wicaksono mengerjakan TM8 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
void makeTree(isiKontainer kontainer, tree *T) // prosedur untuk membuat tree
{
    // deklarasi pointer dan inisialisasi memori
    simpul *baru;
    baru = (simpul *)malloc(sizeof(simpul));
    // copy
    baru->kontainer = kontainer;
    //
    baru->right = NULL;
    baru->left = NULL;
    (*T).root = baru;
    baru = NULL;
}

void addRight(isiKontainer kontainer, simpul *root) // prosedur untuk menambahkan elemen di kanan tree
{
    if (root != NULL)
    {
        if (root->right == NULL) /*jika sub pohon kanan kosong*/
        {
            simpul *baru;
            baru = (simpul *)malloc(sizeof(simpul));
            //
            baru->kontainer = kontainer;
            baru->right = NULL;
            baru->left = NULL;
            root->right = baru;
            baru = NULL;
        }
        else
        {
            printf("sub pohon kanan telah terisi \n");
        }
    }
}

void addLeft(isiKontainer kontainer, simpul *root) // prosedur untuk menambahkan elemen di kiri tree
{
    if (root != NULL)
    {
        if (root->left == NULL) /*jika sub pohon kiri kosong*/
        {
            simpul *baru;
            baru = (simpul *)malloc(sizeof(simpul));
            //
            baru->kontainer.node = kontainer.node;
            baru->right = NULL;
            baru->left = NULL;
            root->left = baru;
            //
            baru = NULL;
        }
        else
        {
            printf("sub pohon kiri telah terisi \n");
        }
    }
}

void delAll(simpul *root) // prosedur untuk menghapus semua elemen dalam tree
{
    if (root != NULL)
    {
        delAll(root->left);
        delAll(root->right);
        free(root);
    }
}

void delRight(simpul *root) // prosedur untuk menghapus semua elemen di kanan suatu elemen
{
    if (root != NULL)
    {
        if (root->right != NULL)
        {
            delAll(root->right);
            root->right = NULL;
        }
    }
}

void delLeft(simpul *root) // prosedur untuk menghapus semua elemen di kiri suatu elemen
{
    if (root != NULL)
    {
        if (root->left != NULL)
        {
            delAll(root->left);
            root->left = NULL;
        }
    }
}

void printTreePreOrder(simpul *root, int *idx, int batas) // menampilkan elemen tree dengan metode penelusuran preorder (dfs)
{
    if (root != NULL)
    {
        printf("%c", root->kontainer.node);
        *idx = *idx + 1;
        if (*idx != batas)
        {
            printf(" - ");
        }
        printTreePreOrder(root->left, idx, batas);
        printTreePreOrder(root->right, idx, batas);
    }
}

void printTreeInOrder(simpul *root, int *idx, int batas) // menampilkan elemen tree dengan metode penelusuran inorder (dfs tapi printnya terbalik)
{
    if (root != NULL)
    {
        printTreeInOrder(root->left, idx, batas);
        printf("%c", root->kontainer.node);
        *idx = *idx + 1;
        if (*idx != batas)
        {
            printf(" - ");
        }
        printTreeInOrder(root->right, idx, batas);
    }
}

void printTreePostOrder(simpul *root, int *idx, int batas) // menampilkan elemen tree dengan metode penelusuran postorder
{
    if (root != NULL)
    {
        printTreePostOrder(root->left, idx, batas);
        printTreePostOrder(root->right, idx, batas);
        printf("%c", root->kontainer.node);
        *idx = *idx + 1;
        if (*idx != batas)
        {
            printf(" - ");
        }
    }
}

void copyTree(simpul *root1, simpul **root2) // prosedur untuk menyalin elemen dari satu tree ke tree lain
{
    if (root1 != NULL)
    {
        (*root2) = (simpul *)malloc(sizeof(simpul));
        (*root2)->kontainer.node = root1->kontainer.node;
        if (root1->left != NULL)
        {
            copyTree(root1->left, &(*root2)->left);
        }
        if (root1->right != NULL)
        {
            copyTree(root1->right, &(*root2)->right);
        }
    }
}

int isEqual(simpul *root1, simpul *root2) // prosedur untuk mengecek kesamaan elemen dari 2 tree
{

    if ((root1 != NULL) && (root2 != NULL)) /* jika simpul pohon 1 dan pohon 2 sama sama tidak NULL */
    {
        if (root1->kontainer.node != root2->kontainer.node) /* jika isi kontainer simpul pohon 1 dan pohon 2 tidak sama */
        {
            return 0;
        }
        else /* jika isi kontainer simpul pohon 1 dan simpul pohon 2 sama, maka telusuri simpul selanjutnya */
        {
            if (isEqual(root1->left, root2->left) == 0 || isEqual(root1->right, root2->right) == 0)
            {
                return 0;
            }
        }
    }
    else
    {
        if ((root1 != NULL) || (root2 != NULL)) /* jika salah satu simpul ada yang NULL */
        {
            return 0;
        }
    }
    return 1;
}