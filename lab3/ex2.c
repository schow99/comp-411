/* Example: analysis of text */

#include <stdio.h>
#include <string.h>

#define MAX 1000 /* The maximum number of characters in a line of input */

int main()
{
  char text[MAX], c;
  int i, j, k, counter = 0;
  int lowercase, uppercase, digits, other;
  int length;
  
  puts("Type some text (then ENTER):");
  
  /* Save typed characters in text[]: */
    
  fgets(text, MAX, stdin);
  length = strlen(text);
  
  /* Analyse contents of text[]: */
  char inverse[length];

  for (i = 0; text[i] != '\0'; i++){
   k = i - 1;
  }
  for (j = 0; j < i; j++){
   inverse[j] = text[k];
   k--;
  }
  printf("Your input in reverse is:\n%s\n", inverse);
  for (i = 0; i < length - 1; i++){
   if (text[i] == inverse[i]){
    counter++;
   }
  }
  if (counter == length-1){
   printf("Found a palindrome!\n");
  }
}
