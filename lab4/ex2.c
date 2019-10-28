/* Example: bubble sort strings in array */

#include <stdio.h>  /* Need for standard I/O functions */
#include <string.h> /* Need for strlen() */
#include <stdbool.h>

#define NUM 25   /* number of strings */
#define LEN 1000  /* max length of each string */

char input[LEN];
int i;
bool same;

  /* Write code here to compare string1 and string2, character by character.
     WITHOUT USING ANY C STRING LIBRARY FUNCTIONS.

     The max length of the strings is LEN, though they may be shorter so look
     for the string terminators.

     This function should return:
      -1 if string1 comes before string2 in alphabetical order
       0 if string1 is the same as string2
      +1 if string1 comes after string2 in alphabetical order

      Here, alphabetical order is defined simply by the numerical value
      of the characters in the string, from left to right.  See the writeup
      for more details.
  */



  /* Write code here to swap the contents of string1 and string2, one
     character at a time, WITHOUT USING ANY C STRING LIBRARY FUNCTIONS.

     The max length of the strings is LEN, though they may be shorter, so look
     for the string terminators.
  */


int main()
{
  char Strings[NUM][LEN];
  int j;
  printf("Please enter %d strings, one per line:\n", NUM);
  for (int i = 0; i < NUM; i++){
   fgets(Strings[i], LEN, stdin);
  }
  /* Write a for loop here to read NUM strings.

     Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length.  Note that the
     newline and NULL characters will be included in LEN.
  */

  puts("\nHere are the strings in the order you entered:");
  for (int i = 0; i < NUM; i++){
   printf("%s", Strings[i]);
  }

  /* Write a for loop here to print all the strings. */


  /* Bubble sort */
  /* Write code here to bubble sort the strings in ascending alphabetical order

     Use the function my_compare_strings() to compare two strings.  If they are out of order,
     use the function my_swap_strings() to swap their contents.

  */
  char tempstring[LEN];
  for (int i = 0 ; i < NUM; i++){
   for (j = i + 1; j < NUM; j++){
    if(strcmp(Strings[i], Strings[j]) > 0){ 
     strcpy(tempstring, Strings[i]);
     strcpy(Strings[i], Strings[j]);
     strcpy(Strings[j], tempstring);
    }
   }
  }
  
  /* Output sorted list */
  
  puts("\nIn alphabetical order, the strings are:");
 /* for (int i = 0; i < NUM; i++){
   char *p = Strings[i];
   while(*p != '\0'){
    printf("%c", *p++);
   }
  }*/
  for (int i = 0; i <  NUM; i++){
   printf("%s", Strings[i]);
  }

  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */

}
