
#include "mul.h"
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int **mul(int **A, int rA, int cA, int **B, int rB, int cB) {
    if (cA != rB) {
        printf("Incompatible multiplication: %d x %d times a %d x %d\n", rA, cA, rB, cB); exit(-1);
    }

    int **C = newMatrix(rA, cB);
    if (C == NULL) return C;

    int **D = newMatrix(cB, rB);
    if (D == NULL) return C;

    int i, j, k;
    for(i=0;i<cB;i++){
    	for(j=0;j<rB;j++){
    		D[i][j]=B[j][i];
    	}
    }
    int total;
    for (i = 0; i < rA; i++) {
        for (j = 0; j < cB; j++) {
            total = 0;
            for (k = 0; k < cA; k++) {
                total += A[i][k] * D[j][k];
            }
            C[i][j] = total;
        }
    }
    return C;
}


