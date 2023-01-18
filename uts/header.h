#include <stdio.h>
#include <string.h>
#include <malloc.h>
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan UTS dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
typedef struct
{
    char kode[20], nama[50];
} isiKontainerRow;

typedef struct
{
    char kode[20], nama[50];
    int bulan, tahun;
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
    Column *firstCol;
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
//
void printElement(list L);
//
Row *findElement(Row **rowTujuan, isiKontainerCol obatTujuan, list L, Row *batas);
Column *getAlamatKolom(isiKontainerCol obatTujuan, Row *ptrRow);
void pindahElemen(isiKontainerCol obatTujuan, Row *rowAsal, Row *rowTujuan);