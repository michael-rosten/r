#include "BigInteger.h"

int main(){
    BigInteger BigA = stringToBigInteger("-511");
    BigInteger BigB = stringToBigInteger("411");
    BigInteger BigC = newBigInteger();
    BigInteger BigD = stringToBigInteger("0");
    BigInteger BigE = copy(BigA);

    multiply(BigC, BigA, BigB);
    
    printBigInteger(stdout, BigA);
    printBigInteger(stdout, BigB);
    printBigInteger(stdout, BigC);
//
//    fprintf(stdout, "%d\n", compare(BigA, BigB));
//    fprintf(stdout, "%d\n", compare(BigB, BigA));
//    fprintf(stdout, "%d\n", compare(BigA, BigA));
//
//    fprintf(stdout, "%d\n", equals(BigA, BigB));
//    fprintf(stdout, "%d\n", equals(BigA, BigA));
//
//    makeZero(BigC);
//    printBigInteger(stdout, BigC);
//
//    makeZero(BigD);
//    printBigInteger(stdout, BigD);
//
//    printBigInteger(stdout, BigE);
//
//    freeBigInteger(&BigA);
//    freeBigInteger(&BigB);
//    freeBigInteger(&BigC);
//    freeBigInteger(&BigD);
//    freeBigInteger(&BigE);

    return 0;
}
