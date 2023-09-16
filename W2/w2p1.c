/*
/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Temitope Oladimeji Samuel Adebayo

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
  const double TAX = 0.13;
  const char patSize = 'S';

  int numberOfShirts;
  int taxes, total, subtotal;

  double smallShirtInDollars, mediumShirtInDollars, largeShirtInDollars;

  printf("Set Shirt Prices\n");
  printf("================\n");

  printf("Enter the price for a SMALL shirt: $");
  scanf("%lf", &smallShirtInDollars);
  printf("Enter the price for a MEDIUM shirt: $");
  scanf("%lf", &mediumShirtInDollars);
  printf("Enter the price for a LARGE shirt: $");
  scanf("%lf", &largeShirtInDollars);
  putchar('\n');

  printf("Shirt Store Price List\n");
  printf("======================\n");
  printf("SMALL  : $%.2lf\n", smallShirtInDollars);
  printf("MEDIUM : $%.2lf\n", mediumShirtInDollars);
  printf("LARGE  : $%.2lf\n\n", largeShirtInDollars);

  printf("Patty's shirt size is \'%c\'\n", patSize);
  printf("Number of shirts Patty is buying: ");
  scanf("%d", &numberOfShirts);
  putchar('\n');

  subtotal = (int)(((smallShirtInDollars * numberOfShirts) + 0.005) * 100);
  taxes = (int)((((smallShirtInDollars * numberOfShirts) * TAX) + 0.005) * 100);
  total = subtotal + taxes;

  printf("Patty's shopping cart...\n");
  printf("Contains : %d shirts\n", numberOfShirts);
  printf("Sub-total: $%8.4lf\n", subtotal / (double)100);
  printf("Taxes    : $%8.4lf\n", taxes / (double)100);
  printf("Total    : $%8.4lf\n\n", total / (double)100);

  return 0;
}