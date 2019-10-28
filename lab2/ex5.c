
#include <stdio.h>
void main(){
 int x, y, i, j, width=1, height=1;
 while (width!=0 | height!=0){
  printf("Please enter width and height:\n");
  scanf("%d", &width);
  if(width == 0){
   printf("End\n");
   break;
  }
  else {
  scanf("%d", &height);
   for(i=1; i<=width; i++){
   if(i==width){
     printf("+\n");
    }
    else if(i==1){
     printf("+");
    }
    else{
     printf("-");
    }
   }
   for(j=1; j<height-1; j++){
    for(x=1; x<=width; x++){
     if(x==width){
      printf("|\n");
     }
     else if(x==1){
      printf("|");
     }
     else{
      printf("~");
     }
    }
   }
   if(height>1){
    for(y=1; y<=width; y++){
    if(y==width){
     printf("+\n");
    }
    else if(y==1){
      printf("+");
    }
     else{
      printf("-");
     }
    }
   }
  }
 }
}
