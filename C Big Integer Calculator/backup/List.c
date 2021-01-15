//
//  List.c
//  hw1
//
//  Created by Michael Rosten on 10/10/19.
//  Copyright © 2019 Michael Rosten. All rights reserved.
//
#include "List.h"
#include<assert.h>




// Constructors-Destructors ---------------------------------------------------
List newList(void){
    
    List new_list = malloc(sizeof(ListObj));
    assert(new_list);
    new_list->cursor = -1;
    new_list->length = 0;
    return new_list;
};


Node newNode(long data){
    Node new_node;
    new_node = malloc (sizeof(NodeObj));
    assert(new_node);
    new_node->value = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return(new_node);
}


void setLength(List L, int data){
    L->length = data;
    return;
}
void _freeList(List pL){
    Node new_node = pL->first;
    Node new_node2 = pL->first;
    while(new_node!=NULL){
        new_node = new_node->next;
        free(new_node2);
        new_node2 = new_node;
    }
    free(new_node);
    free(new_node2);
    return;
};
void freeList(List*  pL){
    List newList = *pL;
    if(newList->first != NULL){
        _freeList(newList);
        pL = NULL;
        free(pL);
        free(newList);
    }
    else {
        pL = NULL;
        free(pL);
        free(newList);
    }
    return;
};

void set(List L, long data){
    Node new_node;
    new_node = L->first;
    for(int i = 0; i < index(L); i++){
        new_node = new_node->next;
    }
    new_node->value = data;
    return;
}
// Creates and returns a new empty List.
// Frees all heap memory associated with *pL, and sets
// *pL to NULL->
// Access functions
int length(List L){
    if(L == NULL){
        return 0;
    }
    return L->length;
};
int index(List L){
    return L->cursor;
};
long front(List L){
    return L->first->value;
};
long back(List L){
    return L->last->value;
};
long get(List L){
    if(index(L) < 0){
//        fprintf(stderr, "Error: you are trying to get from a cursor that is uninitialized or is not on an item on the list.");
        return 0;
    }
    if(index(L) == length(L)){
//        fprintf(stderr, "Error: you are trying to get from an index one past the last item on the list.");
        L->cursor = -1;
        return 0;
    }
    if(index(L) > length(L)){
//        fprintf(stderr, "Error: you are trying to pull from an index past the end of the list.");
        return 0;
    }
    Node new_node;
    new_node = L->first;
    for(int i = 0; i < index(L); i++){
        new_node = new_node->next;
}
    return new_node->value;
};
int _equals(List A, List B){
    if(A->first == NULL || B->first == NULL){
        return 1;
    }
    if(A->length == 0 || B->length == 0){
        return 1;
    }
    Node new_node;
    new_node = A->first;
    Node new_node2;
    new_node2 = B->first;

    if(A->length == B->length){
        for(int i = 0; i < A->length-1; i++){
            if(new_node->value == new_node2->value){
                new_node = new_node->next;
                new_node2 = new_node2->next;
            } else {
                new_node = NULL;
                new_node2 = NULL;
                free(new_node);
                free(new_node2);
                return 0;
            }
        }
    } else {
        new_node = NULL;
        new_node2 = NULL;
        free(new_node);
        free(new_node2);
        return 0;
    }
    new_node = NULL;
    new_node2 = NULL;
    free(new_node);
    free(new_node2);
    return 1;
};
 // Returns true (1) iff Lists A and B are in same
void clear(List L){
    if(L->first == NULL){
//        fprintf(stderr, "Error: this list is empty.");
        return;
    }
    Node new_node = L->first;
    Node new_node2 = L->first;
    while(new_node!=NULL){
        new_node = new_node->next;
        free(new_node2);
        new_node2 = new_node;
    }
    free(new_node);
    free(new_node2);
    L->cursor = -1;
    L->first = NULL;
    L->last = NULL;
    L->length = 0;
    return;
};
void moveFront(List L){
    if(L == NULL){
        return;
    }
    L->cursor = 0;
    return;
};
void moveBack(List L){
    if(L->first == NULL){
//        fprintf(stderr, "Error: this list is empty.");
        return;
    }
    L->cursor = L->length-1;
    return;
};
void movePrev(List L){
    if(L->first == NULL){
//        fprintf(stderr, "Error: this list is empty.");
        return;
    }
    if(index(L)==0){
        L->cursor = -1;
        return;
    }
    if(index(L) < 0){
        L->cursor = -1;
    }
    L->cursor--;
    return;
};
void moveNext(List L){
    if(L->length == 0){
//        fprintf(stderr, "Error: this list is empty.");
        return;
    }
    if(index(L) == -1){
        return;
    }
    if(index(L)==length(L)){
        L->cursor = -1;
        return;
    }
    if(index(L)==length(L)-1){
        L->cursor = -1;
        return;
    }
    L->cursor++;
    return;
};
// Resets L to its original empty state.
// If L is non-empty, sets cursor under the front element, // otherwise does nothing.
// If L is non-empty, sets cursor under the back element, // otherwise does nothing.
// If cursor is defined and not at front, move cursor one // step toward the front of L; if cursor is defined and at // front, cursor becomes undefined; if cursor is undefined // do nothing
// If cursor is defined and not at back, move cursor one // step toward the back of L; if cursor is defined and at // back, cursor becomes undefined; if cursor is undefined // do nothing
// Returns the number of elements in L->
// Returns index of cursor element if defined, -1 otherwise. // Returns front element of L-> Pre: length()>0
// Returns back element of L-> Pre: length()>0
// Returns cursor element of L-> Pre: length()>0, index()>=0
// state, and returns false (0) otherwise.
// Manipulation procedures ----------------------------------------------------
void prepend(List L, long data){
    if (length(L) == 0){
        Node new_node = newNode(data);
        L->first = new_node;
        L->last = new_node;
        setLength(L, length(L) + 1);
        L->cursor++;
        return;
    } else {
        Node new_node = newNode(data);
        L->first->prev = new_node;
        new_node->next = L->first;
        new_node->prev = NULL;
        L->first = new_node;
        setLength(L, length(L) + 1);
        L->cursor++;
        return;
    }
}; // Insert new element into L-> If L is non-empty, // insertion takes place before front element.
void append(List L, long data){
    Node new_node = newNode(data);
    if (length(L) == 0){
        L->first = new_node;
        L->last = new_node;
        L->length++;
    }
    else {
        L->last->next = new_node;
        new_node->prev = L->last;
        L->last = new_node;
        L->length++;
    }
    return;
}; // Insert new element into L-> If L is non-empty, // insertion takes place after back element.
void insertBefore(List L, long data){
    if(L->length < 0){
        return;
    }

    
    Node iterator = L->first;
    for(int i = 0; i < index(L); i++){
        if(iterator->next != NULL){
            iterator = iterator->next;
        }
    }
    if(L->length == 1 || index(L) == 0){
        prepend(L, data);
        return;
    }
    Node new_node = newNode(data);
    new_node->prev = iterator->prev;
    new_node->next = iterator;
    iterator->prev->next = iterator;
    iterator->prev = new_node;
    L->cursor++;
    L->length++;
    return;

}; // Insert new element before cursor. // Pre: length()>0, index()>=0
void insertAfter(List L, long data){
    if(length(L) <= 0){
//        fprintf(stderr, "Error: You are trying to insert after in an empty list.");
        return;
    }
    if(index(L) < 0){
//        fprintf(stderr, "Error: You are trying to insert after an uninitialized pointer.");
        return;
    }
    Node iterator = L->first;
    for(int i = 0; i < index(L); i++){
        if(iterator->next != NULL){
            iterator = iterator->next;
        }
    }
    
    Node new_node = newNode(data);
    if(L->length == index(L)+1){
        L->last->next = new_node;
        new_node->prev = L->last;
        L->last = new_node;
    } else {
        Node iterator2 = iterator->next;
        iterator2->prev = new_node;
        new_node->next = iterator2;
        new_node->prev = iterator;
        iterator->next = new_node;
    }
    L->length++;
    return;
    
    }; // Insert new element before cursor. // Pre: length()>0, index()>=0
void deleteFront(List L){
    if(L->length <= 0){
        return;
    }
    if(index(L) == 0){
        L->cursor = -1;
    }
    Node new_node;
    new_node = (NodeObj *) malloc (sizeof(NodeObj));
    new_node = L->first;
    L->first = L->first->next;
    free(new_node);
    new_node = NULL;
    L->length = L->length - 1;
    if(index(L) > -1){
        L->cursor--;
    }
    return;
};
void deleteBack(List L){
    if(L->length <= 0){
        return;
    }
    if(index(L) == L->length-1){
        L->cursor = -1;
    }
    Node new_node;
    new_node = (NodeObj *) malloc (sizeof(NodeObj));
    new_node = L->last;
    L->last = new_node->prev;
    free(new_node);
    new_node = NULL;
    L->length = L->length -1;
    return;
};
void delete(List L){
    if(L->length <= 0 || index(L) < 0){
        return;
    }
    Node new_node;
    new_node = L->first;
    
    if(index(L) == 0){
        deleteFront(L);
        L->cursor = -1;
        return;
    }
    if(index(L) == L->length-1){
        deleteBack(L);
        L->cursor = -1;
        return;
    }
    for(int i = 0; i < index(L); i++){
        new_node = new_node->next;
    }
    new_node->prev->next = new_node->next;
    new_node->next->prev = new_node->prev;
    free(new_node);
    new_node = NULL;
    L->length = L->length -1;
    L->cursor = -1;
    return;
};
// Delete the front element. Pre: length()>0
// Delete the back element. Pre: length()>0
// Delete cursor element, making cursor undefined. // Pre: length()>0, index()>=0
// Other operations -----------------------------------------------------------
void  printList(FILE* out, List L){
    Node new_node = L->first;
    while(new_node != NULL){
        fprintf(out, "%d ", (new_node)->value);
        new_node = new_node->next;
    }
    free(new_node);
    fprintf(out, "\n");
    return;
}
// Prints to the file pointed to by out, a string representation of L consisting of a space separated sequence of integers, // with front on left.
List _copyList(List L, List A){
    Node new_node = L->first;
    while(new_node != NULL){
        append(A, new_node->value);
        new_node = new_node->next;
    }
    return A;

};
List copyList(List L){
    List NewList = newList();
    printList(stdout, NewList);
    return _copyList(L, NewList);
};

// Returns a new List representing the same integer
// sequence as L-> The cursor in the new list is undefined,
// regardless of the state of the cursor in L-> The state // of L is unchanged.

