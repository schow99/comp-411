
#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

int main () {

  char buf[MAX_BUF];
  int length, i;
  // other stuff

  do {
   fgets(buf, MAX_BUF, stdin);
   length = strlen(buf);     // calculate its length
   if (length == 1){
   // buf[0] = '\0';
    break;
   }
   for (i = 0; i < length; i++) {   // modify the line by switching characters
    if (buf[i] == 'E' || buf[i] == 'e'){
     buf[i] = '3';
    }
    if (buf[i] == 'I' || buf[i] == 'i'){
     buf[i] = '1';
    }
    if (buf[i] == 'O' || buf[i] == 'o'){
     buf[i] = '0';
    }
    if (buf[i] == 'S' || buf[i] == 's'){
     buf[i] = '5';
    }
   }

   for (i = 0; i < length; i++){
    printf("%c", buf[i]); //print the modified line
   }

  } while (length > 1);

}
