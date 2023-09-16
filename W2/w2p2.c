/*
/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
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
  const char patSize = 'S', salSize = 'M', tomSize = 'L';

  int salesSubTotalInCents, salesTaxesInCents, salesTotalInCents;

  int patTaxInCents, salTaxInCents, tomTaxInCents;
  int patTotalInCents, salTotalInCents, tomTotalInCents;
  int patSubTotalInCents, salSubTotalInCents, tomSubTotalInCents;

  int smallShirtInCents, mediumShirtInCents, largeShirtInCents;

  int tooniesCount, looniesCount, quartersCount, dimesCount, nickelsCount, penniesCount;
  int tooniesBal, looniesBal, quartersBal, dimesBal, nickelsBal, penniesBal;

  int numberOfPatShirts, numberOfTomShirts, numberOfSalShirts;

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
  printf("LARGE  : $%.2lf\n", largeShirtInDollars);

  putchar('\n');

  printf("Patty's shirt size is \'%c\'\n", patSize);
  printf("Number of shirts Patty is buying: ");
  scanf("%i", &numberOfPatShirts);

  putchar('\n');

  printf("Tommy's shirt size is \'%c\'\n", tomSize);
  printf("Number of shirts Tommy is buying: ");
  scanf("%i", &numberOfTomShirts);

  putchar('\n');

  printf("Sally's shirt size is \'%c\'\n", salSize);
  printf("Number of shirts Sally is buying: ");
  scanf("%i", &numberOfSalShirts);

  putchar('\n');

  smallShirtInCents = (int)((smallShirtInDollars + 0.005) * 100);
  mediumShirtInCents = (int)((mediumShirtInDollars + 0.005) * 100);
  largeShirtInCents = (int)((largeShirtInDollars + 0.005) * 100);

  patSubTotalInCents = smallShirtInCents * numberOfPatShirts;
  patTaxInCents = (int)(((smallShirtInDollars * TAX * numberOfPatShirts) + 0.005) * 100);
  patTotalInCents = patSubTotalInCents + patTaxInCents;

  salSubTotalInCents = mediumShirtInCents * numberOfSalShirts;
  salTaxInCents = (int)(((mediumShirtInDollars * TAX * numberOfSalShirts) + 0.005) * 100);
  salTotalInCents = salSubTotalInCents + salTaxInCents;

  tomSubTotalInCents = largeShirtInCents * numberOfTomShirts;
  tomTaxInCents = (int)(((largeShirtInDollars * TAX * numberOfTomShirts) + 0.005) * 100);
  tomTotalInCents = tomSubTotalInCents + tomTaxInCents;

  salesSubTotalInCents = patSubTotalInCents + salSubTotalInCents + tomSubTotalInCents;
  salesTaxesInCents = patTaxInCents + salTaxInCents + tomTaxInCents;
  salesTotalInCents = patTotalInCents + salTotalInCents + tomTotalInCents;

  printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
  printf("-------- ---- ----- --- --------- --------- ---------\n");
  printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, smallShirtInDollars, numberOfPatShirts, (double)patSubTotalInCents / 100, patTaxInCents / (double)100, patTotalInCents / 100.0);
  printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, mediumShirtInDollars, numberOfSalShirts, (double)salSubTotalInCents / 100, salTaxInCents / (double)100, salTotalInCents / 100.0);
  printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, largeShirtInDollars, numberOfTomShirts, (double)tomSubTotalInCents / 100, tomTaxInCents / (double)100, tomTotalInCents / 100.0);
  printf("-------- ---- ----- --- --------- --------- ---------\n");
  printf("%33.4lf %9.4lf %9.4lf\n\n", (double)salesSubTotalInCents / 100, salesTaxesInCents / (double)100, salesTotalInCents / 100.0);

  printf("Daily retail sales represented by coins\n");
  printf("=======================================\n");

  putchar('\n');

  tooniesCount = salesSubTotalInCents / 200;
  tooniesBal = salesSubTotalInCents % 200;

  looniesCount = tooniesBal / 100;
  looniesBal = tooniesBal % 100;

  quartersCount = looniesBal / 25;
  quartersBal = looniesBal % 25;

  dimesCount = quartersBal / 10;
  dimesBal = quartersBal % 10;

  nickelsCount = dimesBal / 5;
  nickelsBal = dimesBal % 5;

  penniesCount = nickelsBal / 1;
  penniesBal = nickelsBal % 1;

  printf("Sales EXCLUDING tax\n");
  printf("Coin     Qty   Balance\n");
  printf("-------- --- ---------\n");
  printf("%22.4lf\n", (double)salesSubTotalInCents / 100);
  printf("Toonies  %3d %9.4lf\n", tooniesCount, tooniesBal / 100.0);
  printf("Loonies  %3d %9.4lf\n", looniesCount, looniesBal / 100.0);
  printf("Quarters %3d %9.4lf\n", quartersCount, quartersBal / 100.0);
  printf("Dimes    %3d %9.4lf\n", dimesCount, dimesBal / 100.0);
  printf("Nickels  %3d %9.4lf\n", nickelsCount, nickelsBal / 100.0);
  printf("Pennies  %3d %9.4lf\n", penniesCount, penniesBal / 100.0);

  putchar('\n');

  printf("Average cost/shirt: $%.4lf\n", (salesSubTotalInCents / 100.0) / (numberOfPatShirts + numberOfSalShirts + numberOfTomShirts));

  putchar('\n');

  tooniesCount = salesTotalInCents / 200;
  tooniesBal = salesTotalInCents % 200;

  looniesCount = tooniesBal / 100;
  looniesBal = tooniesBal % 100;

  quartersCount = looniesBal / 25;
  quartersBal = looniesBal % 25;

  dimesCount = quartersBal / 10;
  dimesBal = quartersBal % 10;

  nickelsCount = dimesBal / 5;
  nickelsBal = dimesBal % 5;

  penniesCount = nickelsBal / 1;
  penniesBal = nickelsBal % 1;

  printf("Sales INCLUDING tax\n");
  printf("Coin     Qty   Balance\n");
  printf("-------- --- ---------\n");
  printf("%22.4lf\n", (double)salesTotalInCents / 100);
  printf("Toonies  %3d %9.4lf\n", tooniesCount, tooniesBal / 100.0);
  printf("Loonies  %3d %9.4lf\n", looniesCount, looniesBal / 100.0);
  printf("Quarters %3d %9.4lf\n", quartersCount, quartersBal / 100.0);
  printf("Dimes    %3d %9.4lf\n", dimesCount, dimesBal / 100.0);
  printf("Nickels  %3d %9.4lf\n", nickelsCount, nickelsBal / 100.0);
  printf("Pennies  %3d %9.4lf\n", penniesCount, penniesBal / 100.0);

  putchar('\n');

  printf("Average cost/shirt: $%.4lf\n", (salesTotalInCents / 100.0) / (numberOfPatShirts + numberOfSalShirts + numberOfTomShirts));

  putchar('\n');

  return 0;
}