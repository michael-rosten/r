// Michael Rosten
// mrosten
// pa5
// GraphTest.c: Tests Graph ADT
#include "Graph.h"

int main(int argc, char* argv[]){
//    if(argc != 3){
//        fprintf(stderr, "Error: this program takes 2 arguments: input, output.\n");
//        return 0;
//    }
//
//    FILE *in, *out;

    Graph A = newGraph(4);
    int B, C, D, E, F, G;
    List H;
    B = getOrder(A);
    C = getSize(A);
    D = getSource(A);
    fprintf(stdout, "%d %d %d\n", B,C,D);
//    printGraph(stdout, A);

    addEdge(A, 1, 2);
    addArc(A, 2, 3);
    addEdge(A, 3, 4);
    
//    printGraph(stdout, A);

    BFS(A,1);
    
//    E = getParent(A, 2);
//    F = getDist(A, 2);
    H = newList();
    getPath(H, A, 2);
//    printList(stdout, H);
//    printGraph(stdout, A);
    return 1;
}
