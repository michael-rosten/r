// Michael Rosten
// mrosten
// pa5
// List.c: List ADT

#include "List.h"
#include<assert.h>




// Constructors-Destructors ---------------------------------------------------
List newList(void){
    
    List new_list = malloc(sizeof(ListObj));
    assert(new_list);
    new_list->cursor = NULL;
    new_list->length = 0;
    new_list->index = -1;
    return new_list;
};


Node newNode(int data, Node newprev, Node newnext){
    Node new_node = malloc(sizeof(NodeObj));
    assert(new_node);
    new_node->value = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    if(newprev!= NULL){
        new_node->prev = newprev;
    }
    if(newnext != NULL){
        new_node->next = newnext;
    }
    return new_node;
}

void freeNode(Node* pN) {
    if(pN != NULL && *pN != NULL) {
        free(*pN);
        *pN = NULL;
    }
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

void set(List L, int data){
    L->cursor->value = data;
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
    return L->index;
};
int front(List L){
    return L->first->value;
};
int back(List L){
    return L->last->value;
};
int get(List L){
    if(index(L) < 0){
//        fprintf(stderr, "Error: you are trying to get from a cursor that is uninitialized or is not on an item on the list.");
        return 0;
    }
    if(index(L) == length(L)){
//        fprintf(stderr, "Error: you are trying to get from an index one past the last item on the list.");
//        L->cursor = -1;
        return 0;
    }
    if(index(L) > length(L)){
//        fprintf(stderr, "Error: you are trying to pull from an index past the end of the list.");
        return 0;
    }
    return L->cursor->value;
};
int equals(List A, List B){
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
        L->index = -1;
        L->length = 0;
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
    L->cursor = NULL;
    L->first = NULL;
    L->last = NULL;
    L->length = 0;
    L->index = -1;
    return;
};
void moveFront(List L){
    if(L == NULL){
        return;
    }
    L->cursor = L->first;
    L->index = 0;
    return;
};
void moveBack(List L){
    if(L->first == NULL){
//        fprintf(stderr, "Error: this list is empty.");
        return;
    }
    L->cursor = L->last;
    L->index = L->length -1;
    return;
};
void movePrev(List L){
    if(L->first == NULL){
//        fprintf(stderr, "Error: this list is empty.");
        return;
    }
    if(L->cursor != NULL && index(L) != 0){
        L->cursor = L->cursor->prev;
        L->index--;
        return;
    } else if(L->cursor != NULL && L->index == 0){
        L->cursor = NULL;
        L->index = -1;
        return;
    }
};
void moveNext(List L){
    if(L->length == 0){
//        fprintf(stderr, "Error: this list is empty.");
        return;
    }
    if(index(L) == -1 || L->cursor == NULL){
        return;
    }
    if(L->cursor != NULL && L->index != length(L) - 1){
        L->cursor = L->cursor->next;
        L->index++;
    } else if(L->cursor != NULL && L->index == L->length - 1) {
        L->cursor = NULL;
        L->index = -1;
    }
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
void prepend(List L, int data){
    Node new_node = newNode(data, NULL, L->first);
    if(L->first == NULL){
        L->last = new_node;
    } else {
        L->first->prev = new_node;
        L->index++;
    }
    L->first = new_node;
    L->length++;
    return;
}; // Insert new element into L-> If L is non-empty, // insertion takes place before front element.
void append(List L, int data){
    Node new_node = newNode(data, L->last, NULL);
    if(L->first == NULL){
        L->first = new_node;
    } else {
        L->last->next = new_node;
    }
    L->last = new_node;
    L->length++;
    return;
}; // Insert new element into L-> If L is non-empty, // insertion takes place after back element.
void insertBefore(List L, int data){
    if(L->length < 0){
        return;
    }
    Node new_node = newNode(data, L->cursor->prev, L->cursor);
    if(L->cursor->prev != NULL){
        L->cursor->prev->next = new_node;
    } else {
        L->first = new_node;
    }
    L->cursor->prev = new_node;
    L->length++;
    L->index++;
    return;

}; // Insert new element before cursor. // Pre: length()>0, index()>=0
void insertAfter(List L, int data){
    if(length(L) <= 0){
//        fprintf(stderr, "Error: You are trying to insert after in an empty list.");
        return;
    }
    if(index(L) < 0){
//        fprintf(stderr, "Error: You are trying to insert after an uninitialized pointer.");
        return;
    }
    Node new_node = newNode(data, L->cursor, L->cursor->next);
    
    if(L->cursor->next != NULL){
        L->cursor->next->prev = new_node;
    } else {
        L->last = new_node;
    }
    L->cursor->next = new_node;
    L->length++;
}; // Insert new element before cursor. // Pre: length()>0, index()>=0
void deleteFront(List L){
    if(L->length <= 0){
        return;
    }
    if(L->cursor == L->first){
        L->cursor = NULL;
        L->index = -1;
    } else {
        L->index--;
    }
    
    Node new_node = L->first;
    L->first = L->first->next;
    L->first->prev = NULL;
    L->length--;
    freeNode(&new_node);
    return;
};
void deleteBack(List L){
    if(L->length <= 0){
        return;
    }
    if(L->cursor == L->last){
        L->cursor = NULL;
        L->index = -1;
    }
    
    if(L->last == L->first){
        L->first = NULL;
    }
    
    Node new_node = L->last;
    if(L->last->prev != NULL){
        L->last = L->last->prev;
    }
    L->last->next = NULL;
    L->length--;
    freeNode(&new_node);
    return;
};
void delete(List L){
    if(L->length <= 0 || index(L) < 0){
        return;
    }
    if(L->cursor == L->last){
        deleteBack(L);
    } else if(L->cursor == L->first){
        deleteFront(L);
    } else {
        Node new_node = L->cursor;
        L->cursor->prev->next = L->cursor->next;
        L->cursor->next->prev = L->cursor->prev;
        L->cursor = NULL;
        L->index = -1;
        L->length--;
        freeNode(&new_node);
    }
};
// Delete the front element. Pre: length()>0
// Delete the back element. Pre: length()>0
// Delete cursor element, making cursor undefined. // Pre: length()>0, index()>=0
// Other operations -----------------------------------------------------------
void  printList(FILE* out, List L){
    Node new_node = L->first;
    while(new_node != NULL){
        fprintf(out,"%d ", (new_node)->value);
        new_node = new_node->next;
    }
    free(new_node);
//    fprintf(out, "\n");
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
//    printList(stdout, NewList);
    return _copyList(L, NewList);
};

// Returns a new List representing the same integer
// sequence as L-> The cursor in the new list is undefined,
// regardless of the state of the cursor in L-> The state // of L is unchanged.

