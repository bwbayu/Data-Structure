#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TP4 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
int main()
{
    tree T;
    isiKontainer data, parent;
    char query[100]; // tapungan query
    int output = 0;  // nomor output

    scanf("%s", query);
    // selama inputan query bukan DONE;
    while (strcmp(query, "DONE;") != 0)
    {
        if (strcmp(query, "MAKETREE") == 0) // query buat tree
        {
            scanf("%s", data.nama);
            // menghilangkan ;
            int temp = strlen(data.nama);
            if (data.nama[temp - 1] == ';')
            {
                data.nama[temp - 1] = '\0';
            }
            makeTree(data, &T);
        }
        else if (strcmp(query, "CHILD") == 0) // query menambahkan node
        {
            scanf("%s %s", data.nama, parent.nama);
            // menghilangkan ;
            int temp = strlen(parent.nama);
            if (parent.nama[temp - 1] == ';')
            {
                parent.nama[temp - 1] = '\0';
            }
            simpul *bantu = findSimpul(parent.nama, T.root); // mencari parent dari node
            addChild(data, bantu);
        }
        else if (strcmp(query, "PREORDER;") == 0) // query menampilkan tree
        {
            output++;
            printf("Output %d:\n=========\n", output);
            int panah = 0;
            printTreePreOrder(T.root, panah);
        }
        else if (strcmp(query, "DELLCHILD") == 0) // query menghapus node
        {
            scanf("%s %s", data.nama, parent.nama);
            // menghilangkan ;
            int temp = strlen(parent.nama);
            if (parent.nama[temp - 1] == ';')
            {
                parent.nama[temp - 1] = '\0';
            }
            simpul *cariParent = findSimpul(parent.nama, T.root); // mencari parent dari node
            simpul *cariAnak = findSimpul(data.nama, T.root);     // mencari node yang mau dihapus
            delChild(cariAnak, cariParent);
        }
        //
        scanf("%s", query);
    }
    printf("=========\n");

    return 0;
}
