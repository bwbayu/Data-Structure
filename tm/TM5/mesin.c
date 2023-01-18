#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TM5 dalam mata kuliah struktur data untuk keberkahanNya
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
    if (Lr.toCol != NULL)
    {
        Column *ptr;
        ptr = Lr.toCol;
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
    newPtr->toCol = NULL;
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
    if ((*Lr).toCol == NULL)
    {
        newPtr->nextCol = NULL;
    }
    else
    {
        newPtr->nextCol = (*Lr).toCol;
    }
    (*Lr).toCol = newPtr;
    newPtr = NULL;
}

void addAFterRow(Row *prevRow, isiKontainerRow kontainer)
{
    Row *newPtr;
    newPtr = (Row *)malloc(sizeof(Row));
    //
    newPtr->kontainerRow = kontainer;
    //
    newPtr->toCol = NULL;
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
    if ((*Lr).toCol == NULL)
    {
        addFirstCol(kontainer, Lr);
    }
    else
    {
        Column *last = (*Lr).toCol;
        while (last->nextCol != NULL)
        {
            last = last->nextCol;
        }
        addAfterCol(last, kontainer);
    }
}

// del kolom

void delFirstCol(Row *Lr)
{
    if ((*Lr).toCol != NULL)
    {
        Column *delPtr = (*Lr).toCol;
        if (countColEl(*Lr) == 1)
        {
            (*Lr).toCol = NULL;
        }
        else
        {
            (*Lr).toCol = (*Lr).toCol->nextCol;
            delPtr->nextCol = NULL;
        }
        free(delPtr);
    }
}

void delAfterCol(Column *prevCol)
{
    Column *delPtr = prevCol->nextCol;
    if (delPtr != NULL)
    {
        if (delPtr->nextCol == NULL)
        {
            prevCol->nextCol = NULL;
        }
        else
        {
            prevCol->nextCol = delPtr->nextCol;
            delPtr->nextCol = NULL;
        }
        free(delPtr);
    }
}

void delLastCol(Row *Lr)
{
    if ((*Lr).toCol != NULL)
    {
        if (countColEl(*Lr) == 1)
        {
            delFirstCol(Lr);
        }
        else
        {
            Column *last = (*Lr).toCol;
            Column *before_last;

            while (last->nextCol != NULL)
            {
                before_last = last;
                last = last->nextCol;
            }
            delAfterCol(before_last);
        }
    }
}

void delAllCol(Row *Lr)
{
    if (countColEl(*Lr) != 0)
    {
        for (int i = countColEl(*Lr); i >= 1; i--)
        {
            delLastCol(Lr);
        }
    }
}

// del baris
void delFirstRow(list *L)
{
    if ((*L).first != NULL)
    {
        Row *delPtr = (*L).first;

        if (delPtr->toCol != NULL)
        {
            delAllCol(delPtr);
        }
        //
        if (countRowEl(*L) == 1)
        {
            (*L).first = NULL;
        }
        else
        {
            (*L).first = (*L).first->nextRow;
        }
        delPtr->nextRow = NULL;
        free(delPtr);
    }
    else
    {
        printf("list kosong");
    }
}

void delAfterRow(Row *prevRow)
{
    if (prevRow != NULL)
    {
        Row *delPtr = prevRow->nextRow;
        if (delPtr != NULL)
        {
            if (delPtr->toCol != NULL)
            {
                delAllCol(delPtr);
            }
            //
            if (delPtr->nextRow == NULL)
            {
                prevRow->nextRow = NULL;
            }
            else
            {
                prevRow->nextRow = delPtr->nextRow;
            }
            delPtr->nextRow = NULL;
            free(delPtr);
        }
    }
}

void delLastRow(list *L)
{
    if ((*L).first != NULL)
    {
        if (countRowEl(*L) == 1)
        {
            delFirstRow(L);
        }
        else
        {
            Row *last = (*L).first;
            Row *before_last;
            while (last->nextRow != NULL)
            {
                before_last = last;
                last = last->nextRow;
            }
            delAfterRow(before_last);
        }
    }
}

void delAllRow(list *L)
{
    if (countRowEl(*L) != 0)
    {
        for (int i = countRowEl(*L); i >= 1; i--)
        {
            delLastRow(L);
        }
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
            printf("%s %s\n", ptr->kontainerRow.label, ptr->kontainerRow.kode);

            Column *eCol = ptr->toCol;
            while (eCol != NULL)
            {
                printf("- %s\n", eCol->kontainerCol.nama);
                eCol = eCol->nextCol;
            }
            printf("==================\n");
            ptr = ptr->nextRow;
            i += 1;
        }
    }
    else
    {
        printf("list kosong\n");
    }
}