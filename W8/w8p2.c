/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : Temitope Oladimeji Samuel Adebayo

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *prdLbs, double *prdKg)
{
  double kg;
  kg = *prdLbs / LBS_TO_KG;
  if (prdKg)
  {
    *prdKg = kg;
  }
  return kg;
};

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *prdLbs, int *prdG)
{
  double kg;
  int g;
  kg = convertLbsKg(prdLbs, &kg);
  g = kg * 1000;
  if (prdG)
  {
    *prdG = g;
  }
  return g;
};

// 10. convert lbs: kg and g
void convertLbs(const double *prdLbs, double *prdKg, int *prdG)
{
  double kg;
  int g;
  kg = convertLbsKg(prdLbs, prdKg);
  g = convertLbsG(prdLbs, prdG);
  if (prdKg)
  {
    *prdKg = kg;
  }
  if (prdG)
  {
    *prdG = g;
  }
};

// 11. calculate: servings based on gPerServ
double calculateServings(const int servSizeG, const int prdTotalG, double *noOfServ)
{
  double serv;
  serv = (float)prdTotalG / (float)servSizeG;
  if (noOfServ)
  {
    *noOfServ = serv;
  }
  return serv;
};

// 12. calculate: cost per serving
double calculateCostPerServing(const double *prdPrice, const double *noOfServ, double *costPerServ)
{
  double cost;
  cost = *prdPrice / *noOfServ;
  if (costPerServ)
  {
    *costPerServ = cost;
  }
  return cost;
};

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *prdPrice, const double *prdTotalCal, double *costPerCal)
{
  double cost;
  cost = *prdPrice / *prdTotalCal;
  if (costPerCal)
  {
    *costPerCal = cost;
  }
  return cost;
};

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo prdInfo)
{
  double prodKg = 0, prodTotalServ = 0, prodCostPerServ = 0, prodCostOfCalPerServ = 0, totalCal;
  int prodG = 0;
  struct ReportData report = {0};

  report.sku = prdInfo.sku;
  report.price = prdInfo.price;
  report.caloriesPerServ = prdInfo.caloriesPerServ;
  report.prodLbs = prdInfo.weight;
  report.prodKg = convertLbsKg(&prdInfo.weight, &prodKg);
  report.prodGram = convertLbsG(&prdInfo.weight, &prodG);
  report.totalServing = calculateServings(GRAMS, report.prodGram, &prodTotalServ);
  report.costPerServing = calculateCostPerServing(&prdInfo.price, &report.totalServing, &prodCostPerServ);
  totalCal = prdInfo.caloriesPerServ * report.totalServing;
  report.costOfCalPerServing = calculateCostPerCal(&prdInfo.price, &totalCal, &prodCostOfCalPerServ);

  return report;
};

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
  printf("Analysis Report (Note: Serving = %dg)\n", GRAMS);
  printf("---------------\n");
  printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
  printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData prdReport, const int isCheapest)
{
  printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
         prdReport.sku, prdReport.price, prdReport.prodLbs, prdReport.prodKg,
         prdReport.prodGram, prdReport.caloriesPerServ, prdReport.totalServing,
         prdReport.costPerServing, prdReport.costOfCalPerServing);
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapProd)
{
  printf("Final Analysis\n");
  printf("--------------\n");
  printf("Based on the comparison data, the PURRR-fect economical option is:\n"
         "SKU:%07d Price: $%.2lf\n\n",
         cheapProd.sku, cheapProd.price);
  printf("Happy shopping!\n\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
  struct CatFoodInfo mainProd[MAX_PRODUCTS] = {{0}};
  struct ReportData mainReport[MAX_PRODUCTS] = {{0}};
  int cheapId;
  int i, j;

  openingMessage(MAX_PRODUCTS);

  for (i = 0; i < MAX_PRODUCTS; i++)
  {
    mainProd[i] = getCatFoodInfo(i + 1);
  }

  displayCatFoodHeader();

  for (i = 0; i < MAX_PRODUCTS; i++)
  {
    displayCatFoodData(mainProd[i].sku, mainProd[i].price, mainProd[i].caloriesPerServ, mainProd[i].weight);
    mainReport[i] = calculateReportData(mainProd[i]);

    for (j = 0; j < MAX_PRODUCTS; j++)
    {
      if (mainReport[j].costPerServing < mainReport[i].costPerServing)
      {
        cheapId = j;
      }
    }
  }

  putchar('\n');

  displayReportHeader();

  for (i = 0; i < MAX_PRODUCTS; i++)
  {
    displayReportData(mainReport[i], cheapId);
    if (cheapId == i)
    {
      printf(" ***");
    }
    printf("\n");
  }

  putchar('\n');

  displayFinalAnalysis(mainProd[cheapId]);
}
