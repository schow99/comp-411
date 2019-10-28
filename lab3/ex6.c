#include <stdio.h>
#include <stdlib.h>

int n = 1, k = 1;
int NchooseK(int n, int k){
 if (k == 0 || n == 0 || k == n){
  return 1;
 }
 return NchooseK(n-1, k-1) + NchooseK(n-1, k);
}

void main (){
 while (!(n==0 && k==0)){
  printf("Enter two integers (for n and k) separated by space:\n");
  scanf("%d%d", &n, &k);
  printf("%d\n", NchooseK(n, k));
 }
}

