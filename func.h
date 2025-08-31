#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
typedef struct node
{
    int data;
    struct node *next;
} NODE;

void CreateList ();
void InsertAtBeginning ();
void InsertAtEnd ();
void InsertAnywhere ();
void DeleteFirstNode ();
void DeleteLastNode ();
void DeleteAnyNode ();
void ModifyList ();
bool SearchList ();
void PrintList ();
bool IsListEmpty ();
void ReverseList ();
void FreeList ();
bool Palindrome ();

#endif