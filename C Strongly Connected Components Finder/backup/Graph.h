// Michael Rosten
// mrosten
// pa5
// Graph.h: Header file for Graph ADT

#ifndef Graph_h
#define Graph_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

#define UNDEF -5
#define INF -4
#define NIL -3
#define WHITE -1
#define GRAY 0
#define BLACK 1

typedef struct GraphObj{
    List * neighbors;
    
    int * color;
    int * parents;
    int * discover;
    int * finish;
    int order;
    int size;
    int time;
} GraphObj;

typedef GraphObj * Graph;

Graph newGraph(int n);
void freeGraph(Graph* pG);
int getOrder(Graph G);
int getSize(Graph G);
int getParent(Graph G, int u);
int getDiscover(Graph G, int u);
int getFinish(Graph G, int u);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void printGraph(FILE* out, Graph G);
void DFS(Graph G, List S);
Graph transpose(Graph G);
Graph copyGraph(Graph G);

#endif
