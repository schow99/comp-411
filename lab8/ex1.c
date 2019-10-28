#include<stdio.h>

int NchooseK(int n, int k);

int main() {

  int n, k, result;

    while (!(n==0 && k==0)) {
        scanf("%d", &n);
        scanf("%d", &k);
        result = NchooseK(n, k);
        printf("%d\n", result);
    }
}



int NchooseK(int n, int k) {
    if (k == 0 || n == 0 || k == n){
        return 1;
    }
    return NchooseK(n-1, k-1) + NchooseK(n-1, k);
}
