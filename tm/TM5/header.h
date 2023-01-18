#include <stdio.h>
#include <string.h>
#include <malloc.h>
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TM5 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct
{
    char label[100], kode[100];
} isiKontainerRow;

typedef struct
{
    char nama[100];
} isiKontainerCol;

typedef struct AddCol *alamateKolom;

typedef struct AddCol
{
    isiKontainerCol kontainerCol;
    alamateKolom nextCol;
} Column;

typedef struct AddRow *alamateBaris;

typedef struct AddRow
{
    isiKontainerRow kontainerRow;
    Column *toCol;
    alamateBaris nextRow;
} Row;

typedef struct
{
    Row *first;
} list;

void createList(list *L);
int countRowEl(list L);
int countColEl(Row Lr);
// add
void addFirstRow(isiKontainerRow kontainer, list *L);
void addFirstCol(isiKontainerCol kontainer, Row *Lr);
void addAFterRow(Row *prevRow, isiKontainerRow kontainer);
void addAfterCol(Column *prevCol, isiKontainerCol kontainer);
void addLastRow(isiKontainerRow kontainer, list *L);
void addLastCol(isiKontainerCol kontainer, Row *Lr);
// del kolom
void delFirstCol(Row *Lr);
void delAfterCol(Column *prevCol);
void delLastCol(Row *Lr);
void delAllCol(Row *Lr);
// del row
void delFirstRow(list *L);
void delAfterRow(Row *prevRow);
void delLastRow(list *L);
void delAllRow(list *L);
//
void printElement(list L);
