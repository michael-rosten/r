//
//  List.h
//  hw1
//
//  Created by Michael Rosten on 10/10/19.
//  Copyright © 2019 Michael Rosten. All rights reserved.
//

#ifndef List_h
#define List_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeObj{
    int value;
    struct NodeObj* prev;
    struct NodeObj* next;
} NodeObj;

typedef NodeObj* Node;

typedef struct ListObj{
    int length;
    int index;
    Node cursor;
    Node first;
    Node last;
} ListObj;

typedef ListObj* List;

List newList(void);
void freeList(List*  pL);
int length(List L);
int index(List L);
int front(List L);
int back(List L);
int get(List L);
void set(List L, int x);
int equals(List A, List B);
void clear(List L);
void moveFront(List L);
void moveBack(List L);
void movePrev(List L);
void moveNext(List L);
void prepend(List L, int data);
void append(List L, int data);
void insertBefore(List L, int data);
void insertAfter(List L, int data);
void deleteFront(List L);
void deleteBack(List L);
void delete(List L);
void printList(FILE* out, List L);
List copyList(List L);



#endif /* List_h */
