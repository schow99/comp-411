
#include <stdio.h>
void main(){
 int i, num;
 int inputs[6];
 printf("Enter six integers:\n");
 for (i = 0; i <6; i++) {
  scanf("%d", &num);
  inputs[i] = num;
 }
 printf("1234567890bb1234567890\n");
 printf("%10d%12d\n", inputs[0], inputs[1]);
 printf("%10d%12d\n", inputs[2], inputs[3]);
 printf("%10d%12d\n", inputs[4], inputs[5]);
}

