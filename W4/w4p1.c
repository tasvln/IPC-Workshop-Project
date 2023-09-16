/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
Full Name  : Temitope Oladimeji Samuel Adebayo

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
  int numOfTimes, i;
  char loopType;

  printf("+----------------------+\n");
  printf("Loop application STARTED\n");
  printf("+----------------------+\n\n");

  do
  {
    printf("D = do/while | W = while | F = for | Q = quit\n");
    printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
    scanf(" %c%d", &loopType, &numOfTimes);

    if (loopType == 'D')
    {
      if (numOfTimes >= 3 && numOfTimes <= 20)
      {
        printf("DO-WHILE: ");

        i = 0;

        do
        {
          printf("D");
          i++;
        } while (i < numOfTimes);

        printf("\n\n");
      }
      else
      {
        printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
      }
    }
    else if (loopType == 'W')
    {
      if (numOfTimes >= 3 && numOfTimes <= 20)
      {
        printf("WHILE   : ");

        i = 0;

        while (i < numOfTimes)
        {
          printf("W");
          i++;
        }

        printf("\n\n");
      }
      else
      {
        printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
      }
    }
    else if (loopType == 'F')
    {
      if (numOfTimes >= 3 && numOfTimes <= 20)
      {
        printf("FOR     : ");

        for (i = 0; i < numOfTimes; i++)
        {
          printf("F");
        }

        printf("\n\n");
      }
      else
      {
        printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
      }
    }
    else if (loopType == 'Q')
    {
      if (numOfTimes == 0)
      {
        printf("\n");
        printf("+--------------------+\n");
        printf("Loop application ENDED\n");
        printf("+--------------------+\n\n");
      }
      else
      {
        printf("ERROR: To quit, the number of iterations should be 0!\n\n");
      }
    }
    else
    {
      printf("ERROR: Invalid entered value(s)!\n\n");
    }
  } while (loopType != 'Q' || numOfTimes != 0);

  return 0;
}