#include <stdio.h>

int A[10][10];
int B[10][10];
int C[10][10];
int dimension;

int main() {
 scanf("%d", &dimension);
 if (dimension > 10){
  return 0;
 }
 for (int i = 0; i  < dimension; i++){
  for (int j = 0; j  < dimension; j++){
   scanf("%d", &A[i][j]);
  }
 }
 for (int i = 0; i  < dimension; i++){
  for (int j = 0; j  < dimension; j++){
   scanf("%d", &B[i][j]);
  }
 }


 for (int i = 0; i < dimension; i++){
  for (int j = 0; j < dimension; j++){
   C[i][j] = 0;
   for (int k = 0; k < dimension; k++){
    C[i][j]  = C[i][j] + A[i][k]* B[k][j];
   }
  }
 }

 for (int i = 0; i < dimension; i++){
  for (int j = 0; j < dimension; j++){
   printf("%6d", C[i][j]);
  }
  printf("\n");
 }
}
