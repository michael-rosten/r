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
    long value;
    struct NodeObj* prev;
    struct NodeObj* next;
} NodeObj;

typedef NodeObj* Node;

typedef struct ListObj{
    int length;
    int cursor;
    Node first;
    Node last;
} ListObj;

typedef ListObj* List;

List newList(void);
void freeList(List*  pL);
int length(List L);
int index(List L);
long front(List L);
long back(List L);
long get(List L);
void set(List L, long x);
int _equals(List A, List B);
void clear(List L);
void moveFront(List L);
void moveBack(List L);
void movePrev(List L);
void moveNext(List L);
void prepend(List L, long data);
void append(List L, long data);
void insertBefore(List L, long data);
void insertAfter(List L, long data);
void deleteFront(List L);
void deleteBack(List L);
void delete(List L);
void printList(FILE* out, List L);
List copyList(List L);



#endif /* List_h */
