/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Temitope Oladimeji Samuel Adebayo

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
  int apples = 0, oranges = 0, pears = 0, tomatoes = 0, cabbages = 0;
  int picked, shopSession = 1;

  do
  {
    printf("Grocery Shopping\n");
    printf("================\n");

    do
    {
      printf("How many APPLES do you need? : ");
      scanf(" %d", &apples);

      if (apples < 0)
      {
        printf("ERROR: Value must be 0 or more.\n");
      }
      else
      {
        putchar('\n');
      }

    } while (apples < 0);

    do
    {
      printf("How many ORANGES do you need? : ");
      scanf(" %d", &oranges);

      if (oranges < 0)
      {
        printf("ERROR: Value must be 0 or more.\n");
      }
      else
      {
        putchar('\n');
      }

    } while (oranges < 0);

    do
    {
      printf("How many PEARS do you need? : ");
      scanf(" %d", &pears);

      if (pears < 0)
      {
        printf("ERROR: Value must be 0 or more.\n");
      }
      else
      {
        putchar('\n');
      }

    } while (pears < 0);

    do
    {
      printf("How many TOMATOES do you need? : ");
      scanf(" %d", &tomatoes);

      if (tomatoes < 0)
      {
        printf("ERROR: Value must be 0 or more.\n");
      }
      else
      {
        putchar('\n');
      }

    } while (tomatoes < 0);

    do
    {
      printf("How many CABBAGES do you need? : ");
      scanf(" %d", &cabbages);

      if (cabbages < 0)
      {
        printf("ERROR: Value must be 0 or more.\n");
      }
      else
      {
        putchar('\n');
      }

    } while (cabbages < 0);

    printf("--------------------------\n");
    printf("Time to pick the products!\n");
    printf("--------------------------\n\n");

    if (apples > 0)
    {
      do
      {
        printf("Pick some APPLES... how many did you pick? : ");
        scanf(" %d", &picked);
        if (picked < 1)
        {
          printf("ERROR: You must pick at least 1!\n");
        }
        else if (picked > apples)
        {
          printf("You picked too many... only %d more APPLE(S) are needed.\n", apples);
        }
        else if (picked < apples)
        {
          apples -= picked;
          printf("Looks like we still need some APPLES...\n");
        }
        else if (picked == apples)
        {
          apples -= picked;
          printf("Great, that's the apples done!\n\n");
        }
      } while (apples >= 1);
    }

    picked = 0;

    if (pears > 0)
    {
      do
      {
        printf("Pick some PEARS... how many did you pick? : ");
        scanf(" %d", &picked);
        if (picked < 1)
        {
          printf("ERROR: You must pick at least 1!\n");
        }
        else if (picked > pears)
        {
          printf("You picked too many... only %d more PEAR(S) are needed.\n", pears);
        }
        else if (picked < pears)
        {
          pears -= picked;
          printf("Looks like we still need some PEARS...\n");
        }
        else if (picked == pears)
        {
          pears -= picked;
          printf("Great, that's the pears done!\n\n");
        }
      } while (pears >= 1);
    }

    picked = 0;

    if (cabbages > 0)
    {
      do
      {
        printf("Pick some CABBAGES... how many did you pick? : ");
        scanf(" %d", &picked);
        if (picked < 1)
        {
          printf("ERROR: You must pick at least 1!\n");
        }
        else if (picked > cabbages)
        {
          printf("You picked too many... only %d more CABBAGE(S) are needed.\n", cabbages);
        }
        else if (picked < cabbages)
        {
          cabbages -= picked;
          printf("Looks like we still need some CABBAGES...\n");
        }
        else if (picked == cabbages)
        {
          cabbages -= picked;
          printf("Great, that's the cabbages done!\n\n");
        }
      } while (cabbages >= 1);
    }

    picked = 0;

    if (oranges > 0)
    {
      do
      {
        printf("Pick some ORANGES... how many did you pick? : ");
        scanf(" %d", &picked);
        if (picked < 1)
        {
          printf("ERROR: You must pick at least 1!\n");
        }
        else if (picked > oranges)
        {
          printf("You picked too many... only %d more ORANGE(S) are needed.\n", oranges);
        }
        else if (picked < oranges)
        {
          oranges -= picked;
          printf("Looks like we still need some ORANGES...\n");
        }
        else if (picked == oranges)
        {
          oranges -= picked;
          printf("Great, that's the oranges done!\n\n");
        }
      } while (oranges >= 1);
    }

    picked = 0;

    if (tomatoes > 0)
    {
      do
      {
        printf("Pick some TOMATOES... how many did you pick? : ");
        scanf(" %d", &picked);
        if (picked < 1)
        {
          printf("ERROR: You must pick at least 1!\n");
        }
        else if (picked > tomatoes)
        {
          printf("You picked too many... only %d more TOMATO(ES) are needed.\n", tomatoes);
        }
        else if (picked < tomatoes)
        {
          tomatoes -= picked;
          printf("Looks like we still need some TOMATOES...\n");
        }
        else if (picked == tomatoes)
        {
          tomatoes -= picked;
          printf("Great, that's the tomatoes done!\n\n");
        }
      } while (tomatoes >= 1);
    }

    picked = 0;

    printf("All the items are picked!\n\n");

    printf("Do another shopping? (0=NO): ");
    scanf(" %d", &shopSession);

    putchar('\n');

  } while (shopSession != 0);

  if (shopSession == 0)
  {
    printf("Your tasks are done for today - enjoy your free time!\n\n");
  }

  return 0;
}