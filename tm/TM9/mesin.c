#include "header.h"
/*Saya Bayu Wicaksono mengerjakan TM9 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
void makeTree(isiKontainer kontainer, tree *T)
{
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    node->kontainer = kontainer;
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(isiKontainer kontainer, simpul *root)
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong, berarti dapat ditambahkan simpul anak */
        simpul *baru;
        baru = (simpul *)malloc(sizeof(simpul));
        //
        baru->kontainer = kontainer;
        //
        baru->child = NULL;
        if (root->child == NULL)
        {
            /* jika simpul root belum memiliki simpul anak maka simpul baru menjadi anak pertama */
            baru->sibling = NULL;
            root->child = baru;
        }
        else
        {
            if (root->child->sibling == NULL)
            {
                /* jika simpul root memiliki anak yang belum memiliki saudara, maka simpul baru menjadi anak kedua */
                baru->sibling = root->child;
                root->child->sibling = baru;
            }
            else
            {
                simpul *last = root->child;
                /* mencari simpul anak terakhir karena akan dikaitkan dengan simpul baru sebagai simpul anak terakhir yang
               baru, simpul anak terakhir adalah yang memiliki sibling simpul anak pertama, maka selama belum sampai pada simpul
               anak terakhir, penunjuk last akan berjalan ke simpul anak berikutnya */
                while (last->sibling != root->child)
                {
                    last = last->sibling;
                }
                baru->sibling = root->child;
                last->sibling = baru;
            }
        }
    }
}

void delAll(simpul *root)
{
    if (root != NULL)
    {
        /* jika simpul root tidak kosong */
        if (root->child != NULL)
        {
            if (root->child->sibling == NULL)
            {
                /* jika hanya memiliki satu simpul anak */
                delAll(root->child);
                free(root);
            }
            else
            {
                simpul *bantu;
                simpul *proses;
                bantu = root->child;
                while (bantu->sibling != root->child)
                {
                    proses = bantu;
                    bantu = bantu->sibling;
                    delAll(proses);
                }
                if (bantu != NULL)
                {
                    delAll(proses);
                }
                free(root);
            }
        }
        else
        {
            free(root);
        }
    }
}

// void delChild(simpul *tujuan, simpul *root)
// {
//     if (root != NULL)
//     {
//         simpul *hapus = root->child;
//         if (hapus != NULL)
//         {
//             if (hapus->sibling == NULL)
//             {
//                 /*jika hanya mempunyai satu anak*/
//                 if (root->child == tujuan)
//                 {
//                     delAll(root->child);
//                     root->child = NULL;
//                 }
//                 else
//                 {
//                     printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
//                 }
//             }
//             else
//             {
//                 /*jika memiliki lebih dari satu simpul anak*/
//                 simpul *prev = NULL;
//                 /*mencari simpul yang akan dihapus*/
//                 int ketemu = 0;
//                 while ((hapus->sibling != root->child) && (ketemu == 0))
//                 {
//                     if (hapus == tujuan)
//                     {
//                         ketemu = 1;
//                     }
//                     else
//                     {
//                         prev = hapus;
//                         hapus = hapus->sibling;
//                     }
//                 }
//                 /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
//                 if ((ketemu == 0) && hapus == tujuan)
//                 {
//                     ketemu = 1;
//                 }
//                 if (ketemu == 1)
//                 {
//                     simpul *last = root->child;
//                     /* mencari simpul anak terakhir untuk membantu proses atau pemeriksaan jika yang dihapus nantinya anak terakhir */
//                     while (last->sibling != root->child)
//                     {
//                         last = last->sibling;
//                     }
//                     if (prev == NULL)
//                     {
//                         /*jika simpul yang dihapus anak pertama*/
//                         if ((hapus->sibling == last) && (last->sibling == root->child))
//                         {
//                             /*jika hanya ada dua anak*/
//                             root->child = last;
//                             last->sibling = NULL;
//                         }
//                         else
//                         {
//                             /* jika memiliki simpul anak
//                             lebih dari dua simpul */
//                             root->child = hapus->sibling;
//                             last->sibling = root->child;
//                         }
//                     }
//                     else
//                     {
//                         if ((prev == root->child) && (last->sibling == root->child))
//                         {
//                             /* jika hanya ada dua simpul anak dan yang dihapus adalah simpul anak kedua */
//                             root->child->sibling = NULL;
//                         }
//                         else
//                         {
//                             /* jika yang dihapus bukan simpul anak pertama dan simpul root memiliki simpul anak lebih dari dua simpul */
//                             prev->sibling = hapus->sibling;
//                             hapus->sibling = NULL;
//                         }
//                     }
//                     delAll(hapus);
//                 }
//                 else
//                 {
//                     printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
//                 }
//             }
//         }
//     }
// }

simpul *findSimpul(char tujuan[], simpul *root)
{
    simpul *hasil = NULL;
    if (root != NULL)
    {
        if (strcmp(root->kontainer.k, tujuan) == 0)
        {
            hasil = root;
        }
        else
        {
            simpul *bantu = root->child;
            if (bantu != NULL)
            {
                if (bantu->sibling == NULL)
                {
                    /*jika memiliki satu simpul anak*/
                    if (strcmp(bantu->kontainer.k, tujuan) == 0)
                    {
                        hasil = bantu;
                    }
                    else
                    {
                        hasil = findSimpul(tujuan, bantu);
                    }
                }
                else
                {
                    /*jika memiliki banyak simpul anak*/
                    int ketemu = 0;
                    while ((bantu->sibling != root->child) && (ketemu == 0))
                    {
                        if (strcmp(bantu->kontainer.k, tujuan) == 0)
                        {
                            hasil = bantu;
                            ketemu = 1;
                        }
                        else
                        {
                            hasil = findSimpul(tujuan, bantu);
                            bantu = bantu->sibling;
                            if (hasil != 0)
                            {
                                ketemu = 1;
                            }
                        }
                    }
                    if (ketemu == 0)
                    {
                        if (strcmp(bantu->kontainer.k, tujuan) == 0)
                        {
                            hasil = bantu;
                        }
                        else
                        {
                            hasil = findSimpul(tujuan, bantu);
                        }
                    }
                }
            }
        }
    }
    return hasil;
}

// void printTreePreOrder(simpul *root, int *idx, int batas)
// {
//     if (root != NULL)
//     {
//         printf("%s %d", root->kontainer.k, root->kontainer.nilai);
//         *idx = *idx + 1;
//         if (*idx != batas)
//         {
//             printf("-");
//         }
//         simpul *bantu = root->child;
//         if (bantu != NULL)
//         {
//             if (bantu->sibling == NULL)
//             {
//                 /*jika memiliki satu simpul anak*/
//                 printTreePreOrder(bantu, idx, batas);
//             }
//             else
//             {
//                 /*jika memiliki banyak simpul anak*/
//                 /*mencetak simpul anak*/
//                 while (bantu->sibling != root->child)
//                 {
//                     printTreePreOrder(bantu, idx, batas);
//                     bantu = bantu->sibling;
//                 }
//                 /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
//                 printTreePreOrder(bantu, idx, batas);
//             }
//         }
//     }
// }

// void printTreePostOrder(simpul *root, int *idx, int batas)
// {
//     if (root != NULL)
//     {
//         simpul *bantu = root->child;
//         if (bantu != NULL)
//         {
//             if (bantu->sibling == NULL)
//             {
//                 /*jika memiliki satu simpul anak*/
//                 printTreePostOrder(bantu, idx, batas);
//             }
//             else
//             {
//                 /*jika memiliki banyak simpul anak*/
//                 /*mencetak simpul anak*/
//                 while (bantu->sibling != root->child)
//                 {
//                     printTreePostOrder(bantu, idx, batas);
//                     bantu = bantu->sibling;
//                 }
//                 /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
//                 printTreePostOrder(bantu, idx, batas);
//             }
//         }
//         printf("%s %d", root->kontainer.k, root->kontainer.nilai);
//         *idx = *idx + 1;
//         if (*idx != batas)
//         {
//             printf("-");
//         }
//     }
// }

// void copyTree(simpul *root1, simpul **root2)
// {
//     if (root1 != NULL)
//     {
//         (*root2) = (simpul *)malloc(sizeof(simpul));
//         (*root2)->kontainer = root1->kontainer;
//         (*root2)->sibling = NULL;
//         (*root2)->child = NULL;
//         if (root1->child != NULL)
//         {
//             if (root1->child->sibling == NULL)
//             {
//                 /*jika memiliki satu simpul anak*/
//                 copyTree(root1->child, &(*root2)->child);
//             }
//             else
//             {
//                 /*jika memiliki banyak simpul anak*/
//                 simpul *bantu1 = root1->child;
//                 simpul *bantu2 = (*root2)->child;
//                 while (bantu1->sibling != root1->child)
//                 {
//                     copyTree(bantu1, &bantu2);
//                     bantu1 = bantu1->sibling;
//                     bantu2 = bantu2->sibling;
//                 }
//                 /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
//                 copyTree(bantu1, &bantu2);
//             }
//         }
//     }
// }

// int isEqual(simpul *root1, simpul *root2)
// {
//     int hasil = 1;
//     if ((root1 != NULL) && (root2 != NULL))
//     {
//         if (strcmp(root1->kontainer.k, root2->kontainer.k) != 0)
//         {
//             hasil = 0;
//         }
//         else
//         {
//             if ((root1->child != NULL) && (root2->child != NULL))
//             {
//                 if (root1->child->sibling == NULL)
//                 {
//                     /*jika memiliki satu simpul anak*/
//                     hasil = isEqual(root1->child, root2->child);
//                 }
//                 else
//                 {
//                     /*jika memiliki banyak simpul
//                    anak*/
//                     simpul *bantu1 = root1->child;
//                     simpul *bantu2 = root2->child;
//                     while (bantu1->sibling != root1->child)
//                     {
//                         if ((bantu1 != NULL) && (bantu2 != NULL))
//                         {
//                             hasil = isEqual(bantu1, bantu2);
//                             bantu1 = bantu1->sibling;
//                             bantu2 = bantu2->sibling;
//                         }
//                         else
//                         {
//                             hasil = 0;
//                             break;
//                         }
//                     }
//                     /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
//                     hasil = isEqual(bantu1, bantu2);
//                 }
//             }
//         }
//     }
//     else
//     {
//         if ((root1 != NULL) || (root2 != NULL))
//         {
//             hasil = 0;
//         }
//     }
//     return hasil;
// }

void printTreePreOrder(simpul *root, int level, int space[])
{
    if (root != NULL)
    {
        int tempSpace = strlen(root->kontainer.k);
        if (tempSpace > space[level])
        {
            space[level] = tempSpace;
        }
        printf(" %s %d %d\n", root->kontainer.k, level, space[level]);
        simpul *bantu = root->child;
        if (bantu != NULL)
        {
            if (bantu->sibling == NULL)
            {
                /*jika memiliki satu simpul anak*/
                printTreePreOrder(bantu, ++level, space);
                --level;
            }
            else
            {
                /*jika memiliki banyak simpul anak*/
                /*mencetak simpul anak*/
                while (bantu->sibling != root->child)
                {

                    printTreePreOrder(bantu, ++level, space);
                    --level;

                    bantu = bantu->sibling;
                }
                /*memproses simpul anak terakhir karena belum terproses dalam pengulangan*/
                printTreePreOrder(bantu, ++level, space);
                --level;
            }
        }
    }
}