#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "BigInteger.h"

#define MAX_LEN 10000
int main(int argc, char* argv[]){
    if(argc != 3){
        fprintf(stderr, "Error: this program takes 2 arguments: input, output.\n");
        return 0;
    }
    FILE *in, *out;
    BigInteger A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,X,Y,Z;
    int size;
    char * token;
    char line[MAX_LEN];
    int count = 0;
    in = fopen((argv[1]), "r");
    out = fopen((argv[2]), "w");
    
    if( in==NULL ){
       printf("Unable to open file %s for reading\n", argv[1]);
       exit(1);
    }
    if( out==NULL ){
       printf("Unable to open file %s for writing\n", argv[2]);
       exit(1);
    }
    while( fgets(line, MAX_LEN, in) != NULL)  {
        token = strtok(line, "\n");
        if(count == 0){
            size = atoi(token);
            count++;
        } else if(count == 1){
            A = stringToBigInteger(token);
            count++;
        } else if(count == 2){
            size = atoi(token);
            count++;
        } else if(count == 3){
            B = stringToBigInteger(token);
            count++;
        } else {
            break;
        }
    }
//    X = stringToBigInteger("-112122223333");
//    Y = stringToBigInteger("-111122223333");
//    Z = diff(Y,X);
//    X = stringToBigInteger("+111122223333");
//    Y = stringToBigInteger("-111122223333");
//    Z = sum(X,Y);
//    printBigInteger(out, Z);
//    printf("%d\n", equals(X,Y));
//    printf("%d\n", sign(X));
//    printf("%d\n", sign(Y));
//
//    printf("%d\n", sign(Z));
    
    printBigInteger(out, A);
    printBigInteger(out, B);

    C = newBigInteger();
    add(C, A, B);
    printBigInteger(out, C);


    D = newBigInteger();
    subtract(D, A, B);
    printBigInteger(out, D);



    E = newBigInteger();
    subtract(E, A, A);
    printBigInteger(out, E);

    F = stringToBigInteger("3");
    G = stringToBigInteger("2");

    H = newBigInteger();
    multiply(H, A, F);


    I = newBigInteger();
    multiply(I, B, G);



    J = newBigInteger();
    subtract(J, H, I);
    printBigInteger(out, J);


    K = newBigInteger();
    multiply(K, A, B);
    printBigInteger(out, K);


    L = newBigInteger();
    multiply(L, A, A);
    printBigInteger(out, L);


    M = newBigInteger();
    multiply(M, B, B);
    printBigInteger(out, M);


    multiply(L, L, A);
    multiply(L, L, A);


    N = stringToBigInteger("9");
    multiply(L, L, N);

//    multiply(M, M, M);
    multiply(M, M, B);
    multiply(M, M, B);
    multiply(M, M, B);
    O = stringToBigInteger("16");
    multiply(M, M, O);
    P = newBigInteger();
    add(P, M, L);
    printBigInteger(out, P);
    
    freeBigInteger(&A);
    freeBigInteger(&B);
    freeBigInteger(&C);
    freeBigInteger(&D);
    freeBigInteger(&E);
    freeBigInteger(&F);
    freeBigInteger(&G);
    freeBigInteger(&H);
    freeBigInteger(&I);
    freeBigInteger(&J);
    freeBigInteger(&K);
    freeBigInteger(&L);
    freeBigInteger(&M);
    freeBigInteger(&N);
    freeBigInteger(&O);
    freeBigInteger(&P);

    fclose(in);
    fclose(out);
    return 0;

}
