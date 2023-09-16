/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
Full Name  : Temitope Oladimeji Samuel Adebayo

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *ptrInt)
{
  int flag, value;

  flag = 1;
  do
  {
    scanf("%d", &value);
    if (value <= 0)
    {
      printf("ERROR: Enter a positive value: ");
    }
    else
    {
      if (ptrInt)
      {
        *ptrInt = value;
      }
      flag = 0;
    }
  } while (flag == 1);
  return value;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *ptrDouble)
{
  int flag;
  double value;

  flag = 1;
  do
  {
    scanf("%lf", &value);
    if (value <= 0)
    {
      printf("ERROR: Enter a positive value: ");
    }
    else
    {
      if (ptrDouble)
      {
        *ptrDouble = value;
      }
      flag = 0;
    }
  } while (flag == 1);
  return value;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProducts)
{
  printf("Cat Food Cost Analysis\n"
         "======================\n\n");
  printf("Enter the details for %d dry food bags of product data for analysis.\n"
         "NOTE: A 'serving' is %dg\n\n",
         numProducts, GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int product)
{
  struct CatFoodInfo prod = {0};

  printf("Cat Food Product #%d\n"
         "--------------------\n",
         product);

  printf("SKU           : ");
  getIntPositive(&prod.sku);
  printf("PRICE         : $");
  getDoublePositive(&prod.price);
  printf("WEIGHT (LBS)  : ");
  getDoublePositive(&prod.weight);
  printf("CALORIES/SERV.: ");
  getIntPositive(&prod.caloriesPerServ);
  printf("\n");
  return prod;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
  printf("SKU         $Price    Bag-lbs Cal/Serv\n");
  printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int id, const double price, const int cal, const double weight)
{
  printf("%07d %10.2lf %10.1lf %8d\n", id, price, weight, cal);
}

// 7. Logic entry point
void start()
{
  struct CatFoodInfo mainProd[MAX_PRODUCTS] = {{0}};
  int i;

  openingMessage(MAX_PRODUCTS);

  for (i = 0; i < MAX_PRODUCTS; i++)
  {
    mainProd[i] = getCatFoodInfo(i + 1);
  }

  displayCatFoodHeader();

  for (i = 0; i < MAX_PRODUCTS; i++)
  {
    displayCatFoodData(mainProd[i].sku, mainProd[i].price, mainProd[i].caloriesPerServ, mainProd[i].weight);
  }
}
