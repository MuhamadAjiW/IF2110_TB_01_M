#include <stdio.h>
#include <stdlib.h>
#include "prioqueue.h"
#include "../makanan/makanan.h"

boolean IsEmpty (PrioQueue Q) {
    return (Head(Q) == NIL && Tail(Q) == NIL);
}

boolean IsFull (PrioQueue Q) {
    return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (PrioQueue Q) {
    if (IsEmpty(Q)) {
        return 0;
    }
    else if  (Head(Q) <= Tail(Q)) {
        return Tail(Q) - Head(Q) + 1;
    }
    else {
        return MaxEl(Q) - Head(Q) + Tail(Q) + 1;
    }
}

void MakeEmpty (PrioQueue * Q, int Max) {
    (*Q).T = (makanan *) malloc((Max + 1) * sizeof(makanan));
    if ((*Q).T != NULL) {
        MaxEl(*Q) = Max;
        Head(*Q) = NIL;
        Tail(*Q) = NIL;
    }
    else {
        MaxEl(*Q) = 0;
    }
}

void DeAlokasi(PrioQueue * Q) {
    MaxEl(*Q) = 0;
    free((*Q).T);
}

void Enqueue (PrioQueue * Q, makanan X) {
    PrioQueue q;

    if (IsEmpty(*Q)) {
        Head(*Q) = 0;
        Tail(*Q) = 0;
    }
    else {
        if (Tail(*Q) == MaxEl(*Q)-1) {
            Tail(*Q) = 0;
        }
        else {
            Tail(*Q) += 1;
        }
    }
    InfoTail(*Q) = X;

    int i = Tail(*Q);
    int j;
    if (i == 0) {
        j = MaxEl(*Q) - 1;
    }
    else {
        j = i -1;
    }
    while (i != Head(*Q) && TLT(Time(*Q, i), Time(*Q, j))) {
        makanan temp = Elmt(*Q, i);
        if (i == 0) {
            Elmt(*Q, i) = Elmt(*Q, j);
            Elmt(*Q, j) = temp;
            i = j;
        }
        else {
            Elmt(*Q, i) = Elmt(*Q, i-1);
            Elmt(*Q, i-1) = temp;
            i -= 1;
        }

        if (j == 0) {
            j = MaxEl(*Q) - 1;
        }
        else {
            j -= 1;
        }
    }
}

void Dequeue (PrioQueue * Q, makanan * X) {
    *X = InfoHead(*Q);
    if (NBElmt(*Q) == 1) {
        Head(*Q) = NIL;
        Tail(*Q) = NIL;
    }
    else {
        if (Head(*Q) == MaxEl(*Q)-1) {
            Head(*Q) = 0;
        }
        else {
            Head(*Q) += 1;
        }
    }
}

void PrintPrioQueue (PrioQueue Q) {

    int i = 0;
    int j = Head(Q);
    while (i < NBElmt(Q)) {
        printf("%s", Name(Q, j));
        printTime(Time(Q, j));
        printf("\n");
        if (j == MaxEl(Q)-1) {
            j = 0;
        }
        else {
            j += 1;
        }
        i += 1;
    }
}