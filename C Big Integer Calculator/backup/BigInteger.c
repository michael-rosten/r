#include "BigInteger.h"
#define BASE 1000000000
#define POWER 9

void newMakeZero(BigInteger * N){
    long zero = 0;
    BigInteger K = * N;
    List A = K->bigint;
    prepend(A, zero);
    moveFront(A);
    clear(A);
    return;
}
BigInteger newBigInteger(){
    BigInteger newBig = malloc(sizeof(BigIntegerObj));
    newBig->bigint = newList();
    newBig->sign = 1;
    newMakeZero(&newBig);
    return newBig;
};

void freeBigInteger(BigInteger* pN){
    BigInteger new = * pN;
    if(pN == NULL ){
        return;
    }
    if(new == NULL){

        return;
    }
    
    freeList(&(new->bigint));
    
    pN = NULL;
    free(pN);
    free(new);
    return;
};
int sign(BigInteger N){
    return N->sign;
};

int lenHelper(long x)
{
    if(x < 0){
        x = x * -1;
    }


    if(x>=1000000000) return 10;
    if(x>=100000000) return 9;
    if(x>=10000000) return 8;
    if(x>=1000000) return 7;
    if(x>=100000) return 6;
    if(x>=10000) return 5;
    if(x>=1000) return 4;
    if(x>=100) return 3;
    if(x>=10) return 2;
    return 1;
}

long pow(long A, int B){
    long final = 1;
    if(B == 0){
        return A;
    }
    while (B > 0){
        final = final * 10;
        B--;
    }
    return final * A;
};


void normalize(BigInteger N){
    List A = N->bigint;
    long remainder = 0;
    moveFront(A);
    if(get(A) < 0){
        negate(N);
        N->sign = -1;
    }
    moveBack(A);
    long max = pow(1,POWER);

    while(index(A) != -1){
        long AA = get(A);
        if(AA >= max){
            remainder = AA - max;
            set(A, remainder);
            if(index(A) == 0){
                prepend(A, 1);
//                N->sign = 1;
                A->cursor = 0;
                remainder = 0;
            } else {
                movePrev(A);
                AA = get(A);
                set(A, AA + 1);
                remainder = 0;
                moveNext(A);
            }
        } else if(AA < 0){
            remainder = AA + max;
                set(A, remainder);
            if(index(A) == 0){
                prepend(A, 1);
//                N->sign = -1;
                A->cursor = 0;
                remainder = 0;
            } else {
                movePrev(A);
                AA = get(A);
                set(A, AA - 1);
                moveNext(A);
                remainder = 0;
            }
            
        }
        movePrev(A);
    }
    if(remainder > 0){
        prepend(A, remainder);
    }
    return;
};

int compare(BigInteger A, BigInteger B){
    if (sign(A) != sign(B)){
        if (sign(A) > sign(B)){
            return 1;
        } else if (sign(B) > sign(A)){
            return -1;
        }
    }
    List listA = A->bigint;
    List listB = B->bigint;
    moveFront(listA);
    moveFront(listB);
    long getA;
    long getB;

    while(index(listA) != -1 && index(listB) != -1){
        getA = get(listA);
        getB = get(listB);
        if(getA > getB){
            return 1;
        } else if (getA < getB){
            return -1;
        }
        moveNext(listA);
        moveNext(listB);
    }
    return 0;
    
};

int equals(BigInteger A, BigInteger B){
    List listA = A->bigint;
    List listB = B->bigint;
    moveFront(listA);
    moveFront(listB);
    return _equals(listA,listB);

};
void makeZero(BigInteger N){
    N->sign = 0;
    clear(N->bigint);
    return;
};

void negate(BigInteger N){
    List NN = N->bigint;
    moveFront(NN);
    while(index(NN) != -1){
        long M = get(NN) * -1;
        set(NN, M);
        moveNext(NN);
    }
    moveFront(NN);
    long getN = get(NN);
    if(getN >= 0){
        N->sign = 1;
    } else if (getN < 0){
        N->sign = -1;
    }
    return;
};

BigInteger stringToBigInteger(char* s){
    BigInteger new_BigInt = newBigInteger();
    int i = 0;
    if(s[0] == '+'){
        new_BigInt->sign = 1;
        i = 1;
    } else if (s[0] == '-'){
        new_BigInt->sign = -1;
        i = 1;
    } else {
        new_BigInt->sign = 1;
    }

    int length = strlen(s)-i;
    int prependlength = POWER-1;
    long digit = 0;
    long new;
    while(length % POWER != 0){
        prependlength--;
        length++;
    }
    length = strlen(s);
    for (i; i < length; i++){
        new = s[i] - '0';
        new = pow(new, prependlength);

        digit = digit + new;
        if(prependlength > 0){
            prependlength--;
        } else if (prependlength == 0){
            append(new_BigInt->bigint, digit);
            digit = 0;
            prependlength = POWER-1;
        }
    }
    if(digit != 0){
        for(int i = 0; i <= prependlength; i++){
            digit /= 10;
        }
        append(new_BigInt->bigint, digit);
    }
    return new_BigInt;
};

BigInteger copy(BigInteger N){
    BigInteger new_BigInt = newBigInteger();
    new_BigInt->sign = sign(N);
    
    List copy = N->bigint;
    List tocopy = new_BigInt->bigint;
    moveFront(copy);
    while(index(copy) != -1){
        append(tocopy, get(copy));
        moveNext(copy);
    }
    return new_BigInt;
    
};

void add(BigInteger S, BigInteger A, BigInteger B){
    if(A == NULL || length(A->bigint) == 0){
        S->bigint = B->bigint;
        S->sign = B->sign;
        return;
    } else if (B == NULL || length(B->bigint) == 0){
        S->bigint = A->bigint;
        S->sign = A->sign;
        return;
    }
        
    if( length(B->bigint) > length(A->bigint)){
        while(length(B->bigint) != length(A->bigint)){
            prepend(A->bigint, 0);
        }
    } else if (length(A->bigint) > length(B->bigint)){
        while(length(B->bigint) != length(A->bigint)){
            prepend(B->bigint, 0);
        }
    }
    if(equals(A,B) == 1){
        if((sign(A) == 1 && sign(B) == -1) || (sign(A) == -1 && sign(B) == 1)){
            BigInteger F = newBigInteger();
            S->bigint = F->bigint;
            S->sign = 0;
            return;
        }
    }
    BigInteger L = sum(A,B);
    S->bigint = L->bigint;
    S->sign = sign(L);
};
// sum()
// Returns a reference to a new BigInteger object representing A + B.
BigInteger sum(BigInteger A, BigInteger B){
    BigInteger new_BigInt = newBigInteger();
    BigInteger newA = A;
    BigInteger newB = B;
    int Asign = sign(A);
    int Bsign = sign(B);
    List AA = newA->bigint;
    List BB = newB->bigint;
    if(equals(A,B) == 1){
        if((sign(A) == 1 && sign(B) == -1) || (sign(A) == -1 && sign(B) == 1)){
            new_BigInt->sign = 0;
            return new_BigInt;
        }
    }
    moveFront(AA);
    moveFront(BB);

    while(index(AA) != -1 && index(BB) != -1){
        if(Asign == -1 && Bsign == 1){
            long new = (get(AA)*-1) + get(BB);

            append(new_BigInt->bigint, new);

            moveNext(AA);
            moveNext(BB);
        } else if(Bsign == -1 && Asign == 1){

            long new = get(AA) + (get(BB)*-1);
            append(new_BigInt->bigint, new);

            moveNext(AA);
            moveNext(BB);
        } else if(Bsign == -1 && Asign == -1){
            
            long new = (get(AA)*-1) + (get(BB)*-1);
            append(new_BigInt->bigint, new);

            moveNext(AA);
            moveNext(BB);
            
        } else {
            long new = get(AA) + get(BB);
            append(new_BigInt->bigint, new);
            moveNext(AA);
            moveNext(BB);
        }
                  
    }
    
    
    normalize(new_BigInt);
    return new_BigInt;
};
void subtract(BigInteger D, BigInteger A, BigInteger B){
    if(A == NULL || length(A->bigint) == 0){
        D->bigint = B->bigint;
        D->sign = B->sign;
        return;
    } else if (B == NULL || length(B->bigint) == 0){
        D->bigint = A->bigint;
        D->sign = A->sign;
        return;
    } else if (equals(A,B) == 1){
        makeZero(D);
        return;
    }
        
    if( length(B->bigint) > length(A->bigint)){
        while(length(B->bigint) != length(A->bigint)){
            prepend(A->bigint, 0);
        }
    } else if (length(A->bigint) > length(B->bigint)){
        while(length(B->bigint) != length(A->bigint)){
            prepend(B->bigint, 0);
        }
    }
    if(equals(A,B) == 1){
        if((sign(A) == 1 && sign(B) == 1) || (sign(A) == -1 && sign(B) == -1)){
            BigInteger F = newBigInteger();
            D->bigint = F->bigint;
            D->sign = 0;
            return;
        }
    }
    BigInteger L = diff(A,B);
    D->bigint = L->bigint;
    D->sign = sign(L);
    
    return;
};
BigInteger diff(BigInteger A, BigInteger B){
    BigInteger new_BigInt = newBigInteger();
    BigInteger newA = A;
    BigInteger newB = B;
    int Asign = sign(A);
    int Bsign = sign(B);
    List AA = newA->bigint;
    List BB = newB->bigint;
    if(equals(A,B) == 1){
        if((sign(A) == 1 && sign(B) == 1) || (sign(A) == -1 && sign(B) == -1)){
            BigInteger F = newBigInteger();
            F->sign = 0;
            return F;
        }
    }

    
    moveFront(AA);
    moveFront(BB);
    
    
    if(Asign == -1 && Bsign == 1){
        new_BigInt->sign = -1;
        while(index(AA) != -1 && index(BB) != -1){
            long new = (get(AA) + get(BB));
            append(new_BigInt->bigint, new);
            moveNext(AA);
            moveNext(BB);
        }
    } else if(Asign == 1 && Bsign == -1){
        new_BigInt->sign = 1;
        while(index(AA) != -1 && index(BB) != -1){
            long new = get(AA) + (get(BB));
            append(new_BigInt->bigint, new);
            moveNext(AA);
            moveNext(BB);
        }
    } else if(Asign == -1 && Bsign == -1){
        if(compare(A,B) == 1){
            new_BigInt->sign = -1;
            while(index(AA) != -1 && index(BB) != -1){
                long new = get(AA) - get(BB);
                append(new_BigInt->bigint, new);
                moveNext(AA);
                moveNext(BB);
            }
        } else if(compare(A,B) == -1){
            new_BigInt->sign = 1;
            while(index(AA) != -1 && index(BB) != -1){
                long new = get(BB) - get(AA);
                append(new_BigInt->bigint, new);
                moveNext(AA);
                moveNext(BB);
            }
        }
    } else if(Asign == 1 && Bsign == 1){
                if(compare(A,B) == 1){
                    new_BigInt->sign = 1;
                    while(index(AA) != -1 && index(BB) != -1){
                        long new = get(AA) - get(BB);
                        append(new_BigInt->bigint, new);
                        moveNext(AA);
                        moveNext(BB);
                    }
                } else if(compare(A,B) == -1){
                    new_BigInt->sign = -1;
                    while(index(AA) != -1 && index(BB) != -1){
                        long new = get(BB) - get(AA);
                        append(new_BigInt->bigint, new);
                        moveNext(AA);
                        moveNext(BB);
                    }
                }
    }
    normalize(new_BigInt);
    return new_BigInt;
};

void multiply(BigInteger P, BigInteger A, BigInteger B){
    if(length(A->bigint) == 0 || length(B->bigint) == 0){
        prepend(P->bigint, 0);
        return;
    }
    if(A == NULL || B == NULL || length(B->bigint) == 0 || length(A->bigint) == 0){
        BigInteger L = newBigInteger();
        P->bigint = L->bigint;
        P->sign = sign(P);
        return;
    }
    BigInteger L;
    if(equals(A,B) == 1){
        BigInteger new = copy(A);
        L = prod(A,new);
    } else {
        L = prod(A,B);
    }
    P->bigint = L->bigint;
    P->sign = sign(L);
    return;
};
// prod()
// Returns a reference to a new BigInteger object representing A*B
BigInteger prod(BigInteger A, BigInteger B){
    BigInteger new_BigInt = newBigInteger();
    int Asign = sign(A);
    int Bsign = sign(B);
    List AA = A->bigint;
    List BB = B->bigint;

    moveBack(AA);
    moveBack(BB);
    int countA = 0;
    int countB = 0;
    int s = 0;
    BigInteger temp;
    if((Asign == -1 && Bsign == 1) || (Asign == 1 && Bsign == -1)){
        s = -1;
    }
    while(index(AA) != -1){

        long final = 0;
        long Aget = get(AA);

        while(index(BB) != -1){
            long Bget = get(BB);
            final = (Aget * Bget);
            temp = newBigInteger();
            int len = lenHelper(final);
            if(len >= POWER){
                int max = pow(1,POWER);
                int count = len / POWER;
                for (int i = 0; i < count; i++){
                        long new = final % max;
                        prepend(temp->bigint, new);
                        final /= max;
                    }
            } else {
                prepend(temp->bigint, final);
                final = 0;
            }
            for(int i = 0; i < countB + countA; i++){
                append(temp->bigint, 0);
            }
            if(final != 0){
                prepend(temp->bigint, final);
            }
            add(new_BigInt, new_BigInt, temp);
            movePrev(BB);
            countB++;
            final = 0;
        }
    movePrev(AA);
    moveBack(BB);
    countA++;
    final = 0;
    countB = 0;
    }
    if(s == -1){
        new_BigInt->sign = -1;
    }
    return new_BigInt;
};
void printBigInteger(FILE* out, BigInteger N){
    if(sign(N) == -1){
        fprintf(out, "-");
    }
    List A = N->bigint;
    moveFront(A);
    int numcheck = 0;
    int hasprinted = 0;
    while(index(A) != -1){
        long d = get(A);
        if(numcheck == 0 && d == 0){
            moveNext(A);
        } else if(hasprinted == 0){
            numcheck = 1;
            hasprinted = 1;
            fprintf(out, "%ld", d);
            moveNext(A);
        } else {
            numcheck = 1;
            int i = lenHelper(d);
            if(i <  POWER && index(A) != 0){
                while (i < POWER){
                    fprintf(out, "0");
                    i++;
                }
            }
            fprintf(out, "%ld", d);
            moveNext(A);
        }
    }
    if(numcheck == 0){
        fprintf(out, "0");
    }
    fprintf(out, "\n\n");
    return;
};


