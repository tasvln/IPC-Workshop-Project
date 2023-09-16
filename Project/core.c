/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Temitope Oladimeji Samuel Adebayo

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// Standard Input/Output Library
#include <stdio.h>

// String Library
#include <string.h>

// Core Header
#include "core.h"

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void)
{
  // Discard all remaining char's from the standard input buffer:
  while (getchar() != '\n')
  {
    ; // do nothing!
  }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
  printf("<ENTER> to continue...");
  clearInputBuffer();
  putchar('\n');
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Validate the input for an integer
int inputInt(void)
{
  int intValue, flag = 0;
  char newLine;

  while (flag == 0)
  {
    scanf("%d%c", &intValue, &newLine);

    if (newLine != '\n')
    {
      clearInputBuffer();
      printf("Error! Input a whole number: ");
    }
    else
    {
      flag = 1;
    }
  }

  return intValue;
}

//  Validate the input if it's a positive integer
int inputIntPositive(void)
{
  int positiveInt, flag = 0;

  while (flag == 0)
  {
    positiveInt = inputInt();
    if (positiveInt <= 0)
    {
      printf("ERROR! Value must be > 0: ");
    }
    else
    {
      flag = 1;
    }
  }

  return positiveInt;
}

// Validate the input if it's within a range
int inputIntRange(int lower, int upper)
{
  int rangeInt, flag = 0;

  while (flag == 0)
  {
    rangeInt = inputInt();
    if (rangeInt >= lower && rangeInt <= upper)
    {
      flag = 1;
    }
    else
    {
      printf("ERROR! Value must be between %d and %d inclusive: ", lower, upper);
    }
  }

  return rangeInt;
}

// Validate the input of a character
char inputCharOption(const char validChars[])
{
  int flag = 1, i, count = 0;
  char charOption[STR_LEN];
  char fmt[STR_LEN + 1];

  while (flag == 1)
  {
    sprintf(fmt, "%%%d[^\n]", STR_LEN);
    scanf(fmt, charOption);
    clearInputBuffer();

    for (i = 0; charOption[i] != '\0'; i++)
    {
      count = i + 1;
    }

    if (count > 1)
    {
      flag = 1;
    }
    else
    {
      for (i = 0; validChars[i] != '\0'; i++)
      {
        if (charOption[0] == validChars[i])
        {
          flag = 0;
        }
      }
    }

    if (flag == 1)
    {
      printf("ERROR: Character must be one of [%s]: ", validChars);
    }
  }

  return charOption[0];
}

// Validate the input of a string
void inputCString(char *str, int min, int max)
{
  int flag = 0, strLen;
  char inputStr[STR_LEN + 1];
  char fmt[STR_LEN + 1];

  while (flag == 0)
  {
    sprintf(fmt, "%%%d[^\n]", STR_LEN);
    scanf(fmt, inputStr);
    clearInputBuffer();

    strLen = strlen(inputStr);

    if (min == max && strLen != min)
    {
      printf("ERROR: String length must be exactly %d chars: ", min);
    }
    else if (strLen < min)
    {
      printf("ERROR: String length must be between %d and %d chars: ", min, max);
    }
    else if (strLen > max)
    {
      printf("ERROR: String length must be no more than %d chars: ", max);
    }
    else
    {
      strcpy(str, inputStr);
      flag = 1;
    }
  }
}

// Validate the input of a number string
void inputCStringNum(char *str, int min, int max)
{
  int flag = 0, strLen;
  char inputStr[STR_LEN + 1];
  char fmt[STR_LEN + 1];

  while (flag == 0)
  {
    sprintf(fmt, "%%%d[^\n]", STR_LEN);
    scanf(fmt, inputStr);
    clearInputBuffer();

    strLen = strlen(inputStr);

    if (min == max && strLen != min)
    {
      printf("Invalid %d-digit number! Number: ", min);
    }
    else
    {
      strcpy(str, inputStr);
      flag = 1;
    }
  }
}

// Validate and display the input of a formatted phone number
void displayFormattedPhone(const char *ptrPhoneNum)
{
  int i, ptrLen = 0;

  if (ptrPhoneNum != NULL)
  {
    ptrLen = strlen(ptrPhoneNum);

    if (ptrLen == PHONE_LEN)
    {
      for (i = 0; i < ptrLen; i++)
      {
        if (i == 0)
        {
          printf("(%c", ptrPhoneNum[i]);
        }
        else if (i == 3)
        {
          printf(")%c", ptrPhoneNum[i]);
        }
        else if (i == 6)
        {
          printf("-%c", ptrPhoneNum[i]);
        }
        else
        {
          printf("%c", ptrPhoneNum[i]);
        }
      }
    }
    else
    {
      printf("(___)___-____");
    }
  }
  else
  {
    printf("(___)___-____");
  }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////