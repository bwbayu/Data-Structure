#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan UTS dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
void createList(list *L)
{
    (*L).first = NULL;
}

int countRowEl(list L)
{
    int c = 0;
    if (L.first != NULL)
    {
        Row *ptr;
        ptr = L.first;
        //
        while (ptr != NULL)
        {
            c++;
            ptr = ptr->nextRow;
        }
    }
    return c;
}

int countColEl(Row Lr)
{
    int c = 0;
    if (Lr.firstCol != NULL)
    {
        Column *ptr;
        ptr = Lr.firstCol;
        //
        while (ptr != NULL)
        {
            c++;
            ptr = ptr->nextCol;
        }
    }
    return c;
}

// add

void addFirstRow(isiKontainerRow kontainer, list *L)
{
    Row *newPtr;
    newPtr = (Row *)malloc(sizeof(Row));
    //
    newPtr->kontainerRow = kontainer;
    //
    newPtr->firstCol = NULL;
    if ((*L).first == NULL)
    {
        newPtr->nextRow = NULL;
    }
    else
    {
        newPtr->nextRow = (*L).first;
    }
    //
    (*L).first = newPtr;
    newPtr = NULL;
}

void addFirstCol(isiKontainerCol kontainer, Row *Lr)
{
    Column *newPtr;
    newPtr = (Column *)malloc(sizeof(Column));
    //
    newPtr->kontainerCol = kontainer;
    //
    if ((*Lr).firstCol == NULL)
    {
        newPtr->nextCol = NULL;
    }
    else
    {
        newPtr->nextCol = (*Lr).firstCol;
    }
    (*Lr).firstCol = newPtr;
    newPtr = NULL;
}

void addAFterRow(Row *prevRow, isiKontainerRow kontainer)
{
    Row *newPtr;
    newPtr = (Row *)malloc(sizeof(Row));
    //
    newPtr->kontainerRow = kontainer;
    //
    newPtr->firstCol = NULL;
    if (prevRow->nextRow == NULL)
    {
        newPtr->nextRow = NULL;
    }
    else
    {
        newPtr->nextRow = prevRow->nextRow;
    }
    prevRow->nextRow = newPtr;
    newPtr = NULL;
}

void addAfterCol(Column *prevCol, isiKontainerCol kontainer)
{
    Column *newPtr;
    newPtr = (Column *)malloc(sizeof(Column));
    //
    newPtr->kontainerCol = kontainer;
    //
    if (prevCol->nextCol == NULL)
    {
        newPtr->nextCol = NULL;
    }
    else
    {
        newPtr->nextCol = prevCol->nextCol;
    }
    prevCol->nextCol = newPtr;
    newPtr = NULL;
}

void addLastRow(isiKontainerRow kontainer, list *L)
{
    if ((*L).first == NULL)
    {
        addFirstRow(kontainer, L);
    }
    else
    {
        Row *last = (*L).first;
        while (last->nextRow != NULL)
        {
            last = last->nextRow;
        }
        addAFterRow(last, kontainer);
    }
}

void addLastCol(isiKontainerCol kontainer, Row *Lr)
{
    if ((*Lr).firstCol == NULL)
    {
        addFirstCol(kontainer, Lr);
    }
    else
    {
        Column *last = (*Lr).firstCol;
        while (last->nextCol != NULL)
        {
            last = last->nextCol;
        }
        addAfterCol(last, kontainer);
    }
}

// print element
void printElement(list L)
{
    if (L.first != NULL)
    {
        Row *ptr = L.first;
        int i = 1;
        //
        while (ptr != NULL)
        {
            printf("%s %s\n", ptr->kontainerRow.kode, ptr->kontainerRow.nama);

            Column *eCol = ptr->firstCol;
            while (eCol != NULL)
            {
                printf("- %s %s %d %d\n", eCol->kontainerCol.kode, eCol->kontainerCol.nama, eCol->kontainerCol.bulan, eCol->kontainerCol.tahun);
                eCol = eCol->nextCol;
            }
            ptr = ptr->nextRow;
            i += 1;
        }
    }
}

Row *findElement(Row **rowTujuan, isiKontainerCol obatTujuan, list L, Row *batas)
{
    if (L.first != NULL)
    {
        Row *ptrRow = L.first;
        while (ptrRow != NULL && ptrRow != batas)
        {
            // printf("%s %s\n", ptrRow->kontainerRow.kode, ptrRow->kontainerRow.nama);
            Column *ptrCol = ptrRow->firstCol;
            while (ptrCol != NULL)
            {
                if (strcmp(ptrCol->kontainerCol.nama, obatTujuan.nama) == 0 &&
                    ptrCol->kontainerCol.bulan == obatTujuan.bulan &&
                    ptrCol->kontainerCol.tahun == obatTujuan.tahun)
                {
                    // printf("%s %s\n", ptrRow->kontainerRow.kode, ptrRow->kontainerRow.kode);
                    *rowTujuan = ptrRow;
                    return ptrRow;
                }
                // printf("- %s %s %d %d\n", ptrCol->kontainerCol.kode, ptrCol->kontainerCol.nama, ptrCol->kontainerCol.bulan, ptrCol->kontainerCol.tahun);
                ptrCol = ptrCol->nextCol;
            }
            ptrRow = ptrRow->nextRow;
        }
    }
    return NULL;
}

Column *getAlamatKolom(isiKontainerCol obatTujuan, Row *ptrRow)
{
    Column *ptrCol = ptrRow->firstCol;
    while (ptrCol != NULL)
    {
        if (strcmp(ptrCol->kontainerCol.nama, obatTujuan.nama) == 0 &&
            ptrCol->kontainerCol.bulan == obatTujuan.bulan &&
            ptrCol->kontainerCol.tahun == obatTujuan.tahun)
        {
            return ptrCol;
        }
        ptrCol = ptrCol->nextCol;
    }
}

void pindahElemen(isiKontainerCol obatTujuan, Row *rowAsal, Row *rowTujuan)
{
    // printf("------------%s %s\n", rowTujuan->kontainerRow.kode, rowTujuan->kontainerRow.nama);
    // ambil alamat kolom asal
    Column *currAsal = getAlamatKolom(obatTujuan, rowAsal);
    Column *prevAsal;
    //
    if (rowTujuan->firstCol == NULL) // jika kolom pertama dari baris tujuan kosong
    {
        // printf("masuk1\n");
        if (currAsal == rowAsal->firstCol) // jika kolom yang dipindahkan adalah kolom pertama
        {
            rowAsal->firstCol = currAsal->nextCol;
            // currAsal->nextCol = NULL;
            // rowTujuan->firstCol = currAsal;
        }
        else // jika bukan kolom pertama
        {
            // cari kolom sebelum kolom yang mau di pindahkan
            prevAsal = rowAsal->firstCol;
            while (prevAsal->nextCol != currAsal)
            {
                prevAsal = prevAsal->nextCol;
            }
            //
            prevAsal->nextCol = currAsal->nextCol;
        }
        currAsal->nextCol = NULL;
        rowTujuan->firstCol = currAsal;
    }
    else // kolom pertama dari baris tujuan tidak kosong
    {
        // printf("else\n");
        //
        if (currAsal == rowAsal->firstCol) // jika kolom yang dipindahkan adalah kolom pertama
        {
            // printf("if\n");
            rowAsal->firstCol = currAsal->nextCol;
            // currAsal->nextCol = NULL;
            // lastColTujuan = currAsal;
        }
        else // jika kolom yang dipindahkan bukan kolom pertama
        {
            // printf("else\n");
            // cari kolom sebelum kolom yang mau di pindahkan
            prevAsal = rowAsal->firstCol;
            while (prevAsal->nextCol != currAsal)
            {
                prevAsal = prevAsal->nextCol;
            }
            //
            prevAsal->nextCol = currAsal->nextCol;
        }
        currAsal->nextCol = NULL;
        // cari kolom terakhir di baris tujuan
        Column *temp = rowTujuan->firstCol;
        while (temp->nextCol != NULL)
        {
            temp = temp->nextCol;
        }
        temp->nextCol = currAsal;
    }
}