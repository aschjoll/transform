/*
** Name: Amberlyn Schjoll
** CS270 Project 1
** Due: 9/14/18
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
  char input[1025];
  int value;
  char *p;
  bool commentExists = false;
  int length,i;

  const char lowerHex[] = "0x";
  const char upperHex[] = "0X";
  const char firstComment[] = "/*";
  const char lastComment[] = "*/";
  const char decadecimal[] = "0x0A";
  const char decimal[] = "10";
  const int  min = 0;
  const int max = 225;

  while (!feof(stdin))
  {
  	// read in the line and make sure it was successful
  	if (fgets(input, 1024, stdin) != NULL)
  	{
      p = strtok(input," \t\r\n,.-");

      while (p != NULL)
      {
        //printf("Char: %s\n", p);
        // checks if the token is the start of a comment
        if (strstr(p, firstComment) != NULL)
        {
          commentExists = true;
        }
        // checks if the token is the end comment
        else if (strstr(p, lastComment) != NULL)
        {
          commentExists = false;
        }
        // handles breaking if we are looping through a comment
        else if (commentExists == true)
        {}
        // handles new lines
        else if (p == decimal || p == decadecimal)
        {
            printf("\n");
        }
        // checks to see if the token is a hex
        else if ((strstr(p, lowerHex) != NULL) || (strstr(p, upperHex) != NULL))
        {
          sscanf(p,"%x",&value);
          printf("%c", value);   // prints char conversion of  decimal value
        }
        else
        {
          // blah
          length = strlen(p);
          int workaround = 0;
          for (i = 0; i < length; i++)
          {
              if (!isdigit(p[i]))
              {
                  workaround = 1;
                  printf("<Error: %s>", p); // prints error
                  break;
              }
            }
          if (workaround == 1)
          {
            p = strtok(NULL, " \t\n,.-");
            continue;
          }

          sscanf(p, "%d", &value);  // makes value a decimal
          // validates the decimal is between the desired min and max int values
          if (value >= min && value <= max)
          {
            printf("%c", value);   // prints char conversion of  decimal value
          }
          else
          {
            return 0;
          }
        }
        p = strtok(NULL, " \t\n,.-");
      }
    }
    else
      return 0;
  }
}
