#include <stdio.h>
void  main(){
 int i;
 double num, product = 1 , sum = 0, min, max;
 printf("Enter 10 floating-point numbers:\n");
 for (i = 1; i <= 10; i++) {
  scanf("%lf", &num);
  sum += num;
  product =  product * num;
  if(i==1) {
   max = num;
   min = num; 
  }
  if (num > max){
   max = num;
  }
  if (num < min) {
   min = num;
  }
 }
 printf("Sum is %.5lf\nMin is %.5lf\nMax is %.5lf\nProduct is %.5lf\n", sum, min,max, product); 

}
