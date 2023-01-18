#include "header.h"
/*Saya Bayu Wicaksono NIM 2106836 mengerjakan TM4 dalam mata kuliah struktur data untuk keberkahanNya
maka saya tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin.*/
void createList(list *L)
{
    (*L).first = NULL;
    (*L).tail = NULL;
}

int countEl(list L)
{
    int sum = 0;
    if (L.first != NULL)
    {
        elemen *ptr;
        ptr = L.first;
        while (ptr != NULL)
        {
            sum++;
            ptr = ptr->next;
        }
    }
    return sum;
}

void addFirst(isiKontainer kontainer, list *L)
{
    elemen *newPtr;
    newPtr = (elemen *)malloc(sizeof(elemen));

    newPtr->kontainer = kontainer;

    if ((*L).first == NULL)
    {
        newPtr->next = NULL;
        newPtr->prev = NULL;
        (*L).tail = newPtr;
    }
    else
    {
        newPtr->next = (*L).first;
        newPtr->prev = NULL;
        (*L).first->prev = newPtr;
    }

    (*L).first = newPtr;
    newPtr = NULL;
}

void addAfter(elemen *before, isiKontainer kontainer, list *L)
{
    elemen *newPtr;
    newPtr = (elemen *)malloc(sizeof(elemen));

    newPtr->kontainer = kontainer;

    if (before->next == NULL)
    {
        newPtr->next = NULL;
        (*L).tail = newPtr;
    }
    else
    {
        newPtr->next = before->next;
        newPtr->next->prev = newPtr;
    }
    newPtr->prev = before;
    before->next = newPtr;
    newPtr = NULL;
}

void addLast(isiKontainer kontainer, list *L)
{
    if ((*L).first == NULL)
        addFirst(kontainer, L);
    else
    {
        addAfter((*L).tail, kontainer, L);
    }
}

void addBefore(elemen *before, isiKontainer kontainer, list *L)
{
    if (before == (*L).first)
    {
        addFirst(kontainer, L);
    }
    else
    {
        addAfter(before->prev, kontainer, L);
    }
}

void delFirst(list *L)
{
    if ((*L).first != NULL)
    {
        elemen *delPtr = (*L).first;
        if (countEl(*L) == 1)
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else
        {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            delPtr->next = NULL;
        }

        free(delPtr);
    }
}

void delAfter(elemen *before, list *L)
{
    if (before != NULL)
    {
        elemen *delPtr = before->next;
        if (delPtr != NULL)
        {
            if (delPtr->next == NULL)
            {
                (*L).tail = before;
                before->next = NULL;
            }
            else
            {
                before->next = delPtr->next;
                delPtr->next->prev = before;
                delPtr->next = NULL;
            }
            delPtr->prev = NULL;
            free(delPtr);
        }
    }
}

void delLast(list *L)
{
    if ((*L).first != NULL)
    {
        if (countEl(*L) == 1)
            delFirst(L);
        else
        {
            delAfter((*L).tail->prev, L);
        }
    }
}

void printEl(list L)
{
    if (L.first != NULL)
    {
        elemen *ptr = L.first;
        int i = 1;
        while (ptr != NULL)
        {
            printf("%s %s %s\n", ptr->kontainer.nama, ptr->kontainer.nim, ptr->kontainer.gol);
            ptr = ptr->next;
            i++;
        }
    }
    else
        printf("List Kosong\n");
}

void printRev(list L)
{
    if (L.first != NULL)
    {
        elemen *ptr = L.tail;
        int i = 1;
        while (ptr != NULL)
        {
            printf("%s %s %s\n", ptr->kontainer.nama, ptr->kontainer.nim, ptr->kontainer.gol);
            ptr = ptr->prev;
            i++;
        }
    }
    else
        printf("List Kosong\n");
}

void delAll(list *L)
{
    if (countEl(*L) != 0)
        for (int i = countEl(*L); i >= 1; i--)
            delLast(L);
}

void switchEl(list *L)
{
    elemen *front = (*L).first;
    elemen *back = (*L).tail;
    isiKontainer temp;
    for (int i = 0; i < (countEl(*L) / 2); i++)
    {
        temp = front->kontainer;
        front->kontainer = back->kontainer;
        back->kontainer = temp;

        front = front->next;
        back = back->prev;
    }
}