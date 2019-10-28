#include <stdio.h>
#include <string.h>

char animals[20][15];
char lyrics[20][60];
int  number;
int finished = 0;

void nurseryrhyme(int current) {
 if (current == number){
  finished = 1; 
 }
 if (current >= 20 || current == number){
  return;
 }                         // print "current" number of spaces
 if (current == 0){
  printf("There was an old lady who swallowed a %s;\n", animals[current]);
  nurseryrhyme(current+1);
 }
 else if (0 < current < number){
  for (int i = 0; i < current; i++) {
   printf(" ");
  }
  printf("She swallowed the %s to catch the %s;\n", animals[current-1], animals[current]);
  nurseryrhyme(current+1);
  for (int i = 0; i < current; i++){
   printf(" ");
  }
 }
 if (finished == 1){
  printf("I don't know why she swallowed a %s - %s", animals[current], lyrics[current]);



 }



 } 
                                                // print something before the recursive call
                                                // you need to check if the current level is 0
                                                //   if so, print "There was an old lady..."
                                                //   or if it is > 0, print "She swallowed ..."

 /* if(current < number-1)                        // if we are not at the last animal, make the recursive call
    nurseryrhyme(current+1);

                                                // print something after the recursive call

}*/


int main() {
  int i=0;

  while (1) {
    fgets(animals[i], 15, stdin);
    animals[i][strlen(animals[i])-1] = '\0';                                    // read the next animal name
    fgets(lyrics[i], 60, stdin);
    if (strcmp(animals[i], "END") == 0)  {     // if it is "END\n", we are done reading
      break;
    }                                            // determine the length of the string read
                                                // strip the newline at the end
                                                // read the lyric corresponding to the animal
    i++;
  }

  number = i;

  nurseryrhyme(0);
}
