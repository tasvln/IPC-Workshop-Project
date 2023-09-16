/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : Temitope Oladimeji Samuel Adebayo

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// ----------------------------------------------------------------------------
// defines/macros
#define GRAMS 64
#define MAX_PRODUCTS 3
#define LBS_TO_KG 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
  int sku;
  double price;
  int caloriesPerServ;
  double weight;
};

struct ReportData
{
  int sku;
  double price;
  int caloriesPerServ;
  double prodLbs;
  double prodKg;
  int prodGram;
  double totalServing;
  double costPerServing;
  double costOfCalPerServing;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *ptrInt);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *ptrDouble);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProducts);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int product);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int id, const double price, const int cal, const double weight);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double *prdLbs, double *prdKg);

// 9. convert lbs: g
int convertLbsG(const double *prdLbs, int *prdG);

// 10. convert lbs: kg / g
void convertLbs(const double *prdLbs, double *prdKg, int *prdG);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servSizeG, const int prdTotalG, double *noOfServ);

// 12. calculate: cost per serving
double calculateCostPerServing(const double *prdPrice, const double *noOfServ, double *costPerServ);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *prdPrice, const double *prdTotalCal, double *costPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo prdInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData prdReport, const int isCheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo cheapProd);

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void);
