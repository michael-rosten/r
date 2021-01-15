// Michael Rosten
// mrosten
// pa5
// FindComponents.c: Takes an input file containing data on a digraph and finds the strongly connected components


#include "Graph.h"
#define MAX_LEN 255


void printScc(FILE * out, List * M,int a){
    for(int i = 1; i <= a; i++){
        fprintf(out, "\nComponent %d: ", i);
        printList(out, M[i]);
    }
};

int main(int argc, char* argv[]){
    if(argc != 3){
        fprintf(stderr, "Error: this program takes 2 arguments: input, stdoutput.\n");
        return 0;
    }
    FILE *in, *out;
    char line[MAX_LEN];
    in = fopen((argv[1]), "r");
    out = fopen((argv[2]), "w");
    int size = 0;
    int x = 0;
    int y = 0;
    
    if( in==NULL ){
        fprintf(stderr,"Unable to open file %s for reading\n", argv[1]);
        exit(1);
    }
    if( out==NULL ){
        fprintf(stderr, "Unable to open file %s for writing\n", argv[2]);
        exit(1);
    }
    fgets(line, MAX_LEN, in);
    sscanf(line, "%d", &size);
    
    Graph G = newGraph(size);
    

    while(fgets(line, MAX_LEN, in) != NULL)  {
        x = 0;
        y = 0;
        sscanf(line, "%d %d", &x, &y);

        if(x == 0 && y == 0){
            break;
        }
        addArc(G, x, y);
    }

    List L = newList();
    for (int i = 1; i <= size; i++){
        append(L, i);
    }


    DFS(G, L);
    Graph T = transpose(G);
    DFS(T, L);

    int numScc = 0;
    for (int i = 1; i <= getOrder(T); i++){
        //if the parent of a vertex in a transposition is NIL, it represents a strongly connected component.
        if(getParent(T, i) == NIL){
            numScc++;
        }
    }
    
    fprintf(out, "Adjacency list representation of G:\n");
    printGraph(out, G);
    fprintf(out,  "\n");
    fprintf(out,  "G contains %d strongly connected components:\n", numScc);

    //create and initialize an array of lists so we can store the components properly
    List scc[numScc];
    for (int i = 1; i <= numScc; i++){
        scc[i] = newList();
    }
    
    
    int count = 1;
    int top;
    int last = front(L);
    for (int i = 1; i <= size-1; i++){
        //using our List ADT as a stack, we're going to set the back as the "top"
        top = back(L);
        //pop it off the stack
        deleteBack(L);
        //using our count integer, we prepend it to the corresponding vertex
        prepend(scc[count], top);
        //if we've reached the source, up count so that the next vertices found go to the right component
        if (getParent(T, top) == NIL){
            count++;
        }
    }
    //algorithm misses the last item, fixes that here
    prepend(scc[count], last);

    printScc(out, scc, numScc);
    freeGraph(&G);

    fclose(in);
    fclose(out);

    return(0);

}
