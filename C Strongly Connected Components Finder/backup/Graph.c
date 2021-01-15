// Michael Rosten
// mrosten
// pa5
// Graph.c: Graph ADT

#include "Graph.h"


Graph newGraph(int n){
    Graph new_Graph = (GraphObj *) malloc (sizeof(GraphObj));
    new_Graph->neighbors = calloc(n+1, sizeof(ListObj));
    new_Graph->order = n;
    new_Graph->size = 0;
    new_Graph->time = UNDEF;
    new_Graph->color = (int *)calloc(n+1,sizeof(int));
    new_Graph->discover = (int *)calloc(n+1,sizeof(int));
    new_Graph->parents = (int *)calloc(n+1,sizeof(int));
    new_Graph->finish = (int *)calloc(n+1,sizeof(int));

    for(int i = 1; i <= n; i++){
        new_Graph->neighbors[i] = newList();
        new_Graph->color[i] = 0;
        new_Graph->discover[i] = UNDEF;
        new_Graph->parents[i] = NIL;
        new_Graph->finish[i] = UNDEF;
    }
    return new_Graph;
};
void freeGraph(Graph* pG){
    Graph G = *pG;
    for(int i = 1; i<=getOrder(G); i++){
        freeList(&(G->neighbors[i]));
    }
    free(G->neighbors);
    free(G->parents);
    free(G->discover);
    free(G->color);
    free(G->finish);
    free(*pG);
    *pG = NULL;
};
int getOrder(Graph G){
    if(G == NULL){
        exit(1);
    }
    return G->order;
};
int getSize(Graph G){
    if(G == NULL){
        exit(1);
    }
    return G->size;
};

int getParent(Graph G, int u){
    if(G == NULL){
        exit(1);
    }
    if(1 > u || u > getOrder(G)){
        return 0;
    }
    return G->parents[u];
};
int getDiscover(Graph G, int u){
    if(G == NULL){
        exit(1);
    }

    if(1 > u || u > getOrder(G)){
        exit(1);
    }
    
    return G->discover[u];
};


int getFinish(Graph G, int u){
    if(G == NULL){
        exit(1);
    }
    if(1 > u || u > getOrder(G)){
        exit(1);
    }
    
    return G->finish[u];
};


void addEdge(Graph G, int u, int v){
    if(G == NULL){
        return;
    }
    if(0 > u || u > getOrder(G)){
        return;
    }
    if(0 > v || v > getOrder(G)){
        return;
    }
    
    addArc(G, u, v);
    addArc(G, v, u);
    //decrease the size since each call of addarc will add one to the size
    G->size--;
    
};
void addArc(Graph G, int u, int v){
    if(G == NULL){
        return;
    }
    if(0 > u || u > getOrder(G)){
        return;
    }
    if(0 > v || v > getOrder(G)){
        return;
    }

    List L = G->neighbors[u];
    //if there are no neighbors, then set the point its arcing too as its first one!
    if(length(L) == 0){
        append(L, v);
    //but if there are neighbors, we need to look through them for the right spot to put the new neighbor
    } else {
        moveFront(L);
        while(index(L) != -1){
            //if the new neighbor is the same as the current one we're checking, its already on the list. return.
            if(v == get(L)){
                return;
            //if the new neighbor could possibly go later in the list, move next
            } else if (get(L) < v){
                moveNext(L);
            //if we reach this point, it's at the end but isnt more than the last term. so we add it second to last.
            } else {
                insertBefore(L,v);
                return;
            }
        }
        //if we reach this point, v is higher than everything on our list so we append it
        append(L,v);
    }
    G->size++;
    return;
};

    
Graph transpose(Graph G){
    Graph H = newGraph(getOrder(G));
    for(int i = 1; i <= getOrder(G); i++){
        List A = G->neighbors[i];
        moveFront(A);
        if(length(A) <= 0){
            continue;
        } else {
            while(index(A) != -1){
                addArc(H, get(A), i);
                moveNext(A);
            }
        }
    }
    return H;
};

Graph copyGraph(Graph G){
    Graph H = newGraph(getOrder(G));
    for(int i = 1; i <= getOrder(G); i++){
        List A = G->neighbors[i];
        moveFront(A);
        while(index(A) != -1){
            prepend(H->neighbors[i], get(A));
        }
    }
    return H;
};

//taken from the GraphAlgorithms Handout
void visit(Graph G, List S, int u, int *time){
    //check for invalid parameters
    if (G == NULL || S == NULL){
        exit(1);
    }
    //d[x] == (++time)
    G->discover[u] = ++*time;
    //color[x] = gray
    G->color[u] = GRAY;
    moveFront(G->neighbors[u]);
    //for all y in adj[x]
    for(int i = 0; i < length(G->neighbors[u]); i++){
        int y = get(G->neighbors[u]);
        //if color[y] == white
        if (G->color[y] == WHITE){
            //p[y] = x
            G->parents[y] = u;
            //visit(Y)
            visit(G, S, y, time);
        }
        moveNext(G->neighbors[u]);
    }
    //color[x] = black
    G->color[u] = BLACK;
    //f[x] = (++time)
    G->finish[u] = ++*time;
    if( u != 0){
        prepend(S, u);
    }
};


//taken from the GraphAlgorithms Handout
void DFS(Graph G, List S){
    //check for invalid parameters
     if (G == NULL || S == NULL){
         exit(1);
     }
    //check for incompatible list and graph
     if (length(S) != getOrder(G)){
         exit(1);
     }
    //set up our search by setting every color to white and setting every parent to NIL
    //for all x in V(G)
     for (int i = 1; i <= getOrder(G); i++){
         //color[x] = white
         G->color[i] = WHITE;
         //p[x] = nil
         G->parents[i] = NIL;
     }
    //initialize our time at 0
     int time = 0;
     moveFront(S);
    //for all x in V(G) => iterate over every item in S
     while (index(S) >= 0){
         int u = get(S);
         //if color[x] == white => check if this item needs to be searched via visit()
         if (G->color[u] == WHITE){
             //visit(x)
             visit(G, S, u, &time);
         }
         moveNext(S);
     }
    
     for (int i = 0; i < getOrder(G); i++){
         deleteBack(S);
     }
 };



void printGraph(FILE* out, Graph G){
    int n = G->order;
    for(int i = 1; i <= n; i++){
        fprintf(out, "%d: ", i);
        List A = G->neighbors[i];
        printList(out, A);
        fprintf(out, "\n");
    }
    return;
};
