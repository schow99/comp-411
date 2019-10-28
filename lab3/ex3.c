
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 1000 /* The maximum number of characters in a line of input */

void main()
{
  char text[MAX], c;
  int i, j, k, l=0, counter = 0, index = 0;
  int lowercase, uppercase, digits, other;
  int length, invlen;
  
  puts("Type some text (then ENTER):");
  
  /* Save typed characters in text[]: */
    
  fgets(text, MAX, stdin);
  length = strlen(text);
  
  /* Analyse contents of text[]: */
  char inverse[100], newinv[100], upinv[100];
  for (i = 0; text[i] != '\0'; i++){
   k = i - 1;
  }
  for (j = 0; j < i; j++){
   inverse[j] = text[k];
   k--;
  }
  for (i = 0; i < length; i++){
   if(!ispunct(inverse[i])){
    if(!isspace(inverse[i])){
     newinv[index] = inverse[i];
     index++;
    }
   }
  }
  while(l < index) {
   upinv[l] = toupper(newinv[l]);
   l++;
  }
  printf("Your input in reverse is:\n%s\n", inverse);
  bool palindrome = true;
  int h = 0, count = strlen(upinv) - 1;
  while (count >= 0){
   if (upinv[h] != upinv[count]){
    palindrome = false;
   } 
   h++;
   count--;
  }

  if (palindrome){
   printf("Found a palindrome!\n");
  }
 
}
