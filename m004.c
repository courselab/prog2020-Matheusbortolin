/* m004.c - Binary to decimal.

   This program takes a string read as a command line argument and,
   interpreting it as a positive binary integer, outputs its 
   corresponding value in decimal base.


   E.g.

      command line    : m004 0011 
      expected output : 3

   Directions:

      Please, edit function decimal();
      do no not change function main().

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Return the value in decimal base of the string b, interpreted
   as the a positive binary number. If the string contains any
   characters other than '1's and '0's, truncate the string
   right before the spurious character (eg. truncate 110x001
   into 110); an empty string means zero. */

int elevado (int l)
  {
    int x,y;
    x = 0;
    y = 1;
    while (x<l)
      {
       y = y * 2;
       x++;
      }
    return y;
  }

int decimal (char *b)
{
  int n,i,v;
  int d;
  
  n = strlen(b);
  v = 0;
  i = 0;
  d = n-1;

  while (i<n)
    { 

    v = v + (b[i]-'0')* elevado(d);  
    i++;
    d--;
    }
return v;
}
 

#define USAGE "m004 <string>\n"

/* Do not edit this function. */

int main (int argc, char **argv)
{
  int n;

  if (argc < 2)
    {
      printf (USAGE);
      exit(1);
    }

  n = decimal (argv[1]);

  printf ("%d\n", n);
  
  return 0;
}
