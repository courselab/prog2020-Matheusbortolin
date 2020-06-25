/* m008.c - Lastname-Names.

   This program reads the name of a person from the standard input
   in the form 'First-name middle-names last-name' and outputs the 
   name in the form 'LAST-NAME, first-name middle-names'.
   The name should be entered using only ASCII characters (26 letter 
   of latim alphabet, no diacrictics).


   E.g.

      command line    : m008
      standard input  : John Little Bill Doe 
      expected output : DOE, John Little Bill

   Directions:

      Please, edit function lasname();
      do no not change function main().

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

/* Converts the string 's' from first-middle-last name 
   form into LAST-first-middle form. */

void lastname (char *s)
{
  int i=0;
  int d=0;
  int e=0;
  int x=0;


  char t[MAX];

  strcpy(t, s);

    while (*(t+i)!= 0)
      {
        if ((*(t+i) == 32) || (*(t+i) == 9))
          {
          d = i;
          i++;
          }
        else
          i++;
      }
      
    while(*(t+d+e+1)!= 0)
    {
      if ((*(t+d+1+e) <= 90) && (*(t+d+1+e) >= 65))
        {
          *(s+e) = *(t+d+1+e);
          e++;
        }
      else
        if ((*(t+d+1+e) <= 122) && (*(t+d+1+e) >= 97))
          {
            *(s+e) = (*(t+d+1+e) - 32);
            e++;
          }
        else
          e++;
    }
    *(s+e-1) = 44;
    *(s+e) = 32;

    while (x<d)
        {
        *(s+e+1) = *(t+x);
        e++;
        x++;
        }



  
}



/* Do not edit this function. */

int main (int argc, char **argv)
{
  int n;
  char name[MAX];

  fgets (name, MAX-1, stdin);
  
  lastname (name);

  printf ("%s\n", name);
  
  return 0;
}
