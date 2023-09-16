/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Temitope Oladimeji Samuel Adebayo

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_WISH_ITEMS 1
#define MAX_WISH_ITEMS 10
#define MIN_PRIORITY 1
#define MAX_PRIORITY 3

int main(void)
{
  const double minIncome = 500, maxIncome = 400000, minCost = 100;
  double netIncome, costSum = 0;
  int wishItems, i, flag;

  double cost[MAX_WISH_ITEMS] = {0};
  int priority[MAX_WISH_ITEMS] = {0};
  char financeOpt[MAX_WISH_ITEMS] = {0};

  printf("+--------------------------+\n");
  printf("+   Wish List Forecaster   |\n");
  printf("+--------------------------+\n\n");

  flag = 0;
  do
  {
    printf("Enter your monthly NET income: $");
    scanf("%lf", &netIncome);

    if (netIncome < minIncome)
    {
      printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", minIncome);
    }
    if (netIncome > maxIncome)
    {
      printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", maxIncome);
    }
    if (netIncome >= minIncome && netIncome <= maxIncome)
    {
      flag = 1;
    }

  } while (flag == 0);

  putchar('\n');

  flag = 0;
  do
  {
    printf("How many wish list items do you want to forecast?: ");
    scanf("%d", &wishItems);

    if (!(wishItems >= MIN_WISH_ITEMS && wishItems <= MAX_WISH_ITEMS))
    {
      printf("ERROR: List is restricted to between %d and %d items.\n\n", MIN_WISH_ITEMS, MAX_WISH_ITEMS);
    }
    else
    {
      flag = 1;
    }

  } while (flag == 0);

  putchar('\n');

  for (i = 0; i < wishItems; i++)
  {
    printf("Item-%d Details:\n", (i + 1));

    flag = 0;
    do
    {
      printf("   Item cost: $");
      scanf("%lf", &cost[i]);

      if (cost[i] < minCost)
      {
        printf("      ERROR: Cost must be at least $%.2lf\n", minCost);
      }
      else
      {
        costSum += cost[i];
        flag = 1;
      }
    } while (flag == 0);

    flag = 0;
    do
    {
      printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
      scanf("%d", &priority[i]);

      if (!(priority[i] >= MIN_PRIORITY && priority[i] <= MAX_PRIORITY))
      {
        printf("      ERROR: Value must be between %d and %d\n", MIN_PRIORITY, MAX_PRIORITY);
      }
      else
      {
        flag = 1;
      }

    } while (flag == 0);

    flag = 0;
    do
    {
      printf("   Does this item have financing options? [y/n]: ");
      scanf(" %c", &financeOpt[i]);

      if (financeOpt[i] != 'y' && financeOpt[i] != 'n')
      {
        printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
      }
      else
      {
        flag = 1;
      }

    } while (flag == 0);

    putchar('\n');
  }

  printf("Item Priority Financed        Cost\n");
  printf("---- -------- -------- -----------\n");

  for (i = 0; i < wishItems; i++)
  {
    printf("%3d  %5d    %5c    %11.2lf\n", i + 1, priority[i], financeOpt[i], cost[i]);
  }

  printf("---- -------- -------- -----------\n");
  printf("                      $%11.2lf\n\n", costSum);

  printf("Best of luck in all your future endeavours!\n\n");

  return 0;
}