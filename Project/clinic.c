/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
Full Name  : Temitope Oladimeji Samuel Adebayo

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// include the standard input/output library
#include <stdio.h>
// include the string library
#include <string.h>
// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
  printf("Pat.# Name            Phone#\n"
         "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient *patient, int fmt)
{
  if (fmt == FMT_FORM)
  {
    printf("Name  : %s\n"
           "Number: %05d\n"
           "Phone : ",
           patient->name, patient->patientNumber);
    displayFormattedPhone(patient->phone.number);
    printf(" (%s)\n", patient->phone.description);
  }
  else
  {
    printf("%05d %-15s ", patient->patientNumber,
           patient->name);
    displayFormattedPhone(patient->phone.number);
    printf(" (%s)\n", patient->phone.description);
  }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date *date, int isAllRecords)
{
  printf("Clinic Appointments for the Date: ");

  if (isAllRecords)
  {
    printf("<ALL>\n\n");
    printf("Date       Time  Pat.# Name            Phone#\n"
           "---------- ----- ----- --------------- --------------------\n");
  }
  else
  {
    printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
    printf("Time  Pat.# Name            Phone#\n"
           "----- ----- --------------- --------------------\n");
  }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient *patient,
                         const struct Appointment *appoint,
                         int includeDateField)
{
  if (includeDateField)
  {
    printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
           appoint->date.day);
  }
  printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
         patient->patientNumber, patient->name);

  displayFormattedPhone(patient->phone.number);

  printf(" (%s)\n", patient->phone.description);
}

//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData *data)
{
  int selection;

  do
  {
    printf("Veterinary Clinic System\n"
           "=========================\n"
           "1) PATIENT     Management\n"
           "2) APPOINTMENT Management\n"
           "-------------------------\n"
           "0) Exit System\n"
           "-------------------------\n"
           "Selection: ");
    selection = inputIntRange(0, 2);
    putchar('\n');
    switch (selection)
    {
    case 0:
      printf("Are you sure you want to exit? (y|n): ");
      selection = !(inputCharOption("yn") == 'y');
      putchar('\n');
      if (!selection)
      {
        printf("Exiting system... Goodbye.\n\n");
      }
      break;
    case 1:
      menuPatient(data->patients, data->maxPatient);
      break;
    case 2:
      menuAppointment(data);
      break;
    }
  } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
  int selection;

  do
  {
    printf("Patient Management\n"
           "=========================\n"
           "1) VIEW   Patient Data\n"
           "2) SEARCH Patients\n"
           "3) ADD    Patient\n"
           "4) EDIT   Patient\n"
           "5) REMOVE Patient\n"
           "-------------------------\n"
           "0) Previous menu\n"
           "-------------------------\n"
           "Selection: ");
    selection = inputIntRange(0, 5);
    putchar('\n');
    switch (selection)
    {
    case 1:
      displayAllPatients(patient, max, FMT_TABLE);
      suspend();
      break;
    case 2:
      searchPatientData(patient, max);
      break;
    case 3:
      addPatient(patient, max);
      suspend();
      break;
    case 4:
      editPatient(patient, max);
      break;
    case 5:
      removePatient(patient, max);
      suspend();
      break;
    }
  } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient *patient)
{
  int selection;

  do
  {
    printf("Edit Patient (%05d)\n"
           "=========================\n"
           "1) NAME : %s\n"
           "2) PHONE: ",
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf("\n"
           "-------------------------\n"
           "0) Previous menu\n"
           "-------------------------\n"
           "Selection: ");
    selection = inputIntRange(0, 2);
    putchar('\n');

    if (selection == 1)
    {
      printf("Name  : ");
      inputCString(patient->name, 1, NAME_LEN);
      putchar('\n');
      printf("Patient record updated!\n\n");
    }
    else if (selection == 2)
    {
      inputPhoneData(&patient->phone);
      printf("Patient record updated!\n\n");
    }

  } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData *data)
{
  int selection;

  do
  {
    printf("Appointment Management\n"
           "==============================\n"
           "1) VIEW   ALL Appointments\n"
           "2) VIEW   Appointments by DATE\n"
           "3) ADD    Appointment\n"
           "4) REMOVE Appointment\n"
           "------------------------------\n"
           "0) Previous menu\n"
           "------------------------------\n"
           "Selection: ");
    selection = inputIntRange(0, 4);
    putchar('\n');
    switch (selection)
    {
    case 1:
      viewAllAppointments(data); // ToDo: You will need to create this function!
      suspend();
      break;
    case 2:
      viewAppointmentSchedule(data); // ToDo: You will need to create this function!
      suspend();
      break;
    case 3:
      addAppointment(data->appointments, data->maxAppointments,
                     data->patients, data->maxPatient); // ToDo: You will need to create this function!
      suspend();
      break;
    case 4:
      removeAppointment(data->appointments, data->maxAppointments,
                        data->patients, data->maxPatient); // ToDo: You will need to create this function!
      suspend();
      break;
    }
  } while (selection);
}

// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
  int i, eligibility = 0;

  // Check if fmt is FMT_TABLE, then display the table header
  if (fmt == FMT_TABLE)
  {
    displayPatientTableHeader();
  }

  // Loop through the patient array and display each patient data or display a message if no patient is found
  for (i = 0; i < max; i++)
  {
    if (patient[i].patientNumber != 0)
    {
      displayPatientData(&patient[i], fmt);
      eligibility = 1;
    }
  }

  if (eligibility == 0)
  {
    printf("*** No records found ***\n\n");
  }

  putchar('\n');
}

// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
  int option, flag = 0;

  // loop until the user selects 0 to exit
  while (flag == 0)
  {
    // Search option menu
    printf("Search Options\n");
    printf("==========================\n");
    printf("1) By patient number\n");
    printf("2) By phone number\n");
    printf("..........................\n");
    printf("0) Previous menu\n");
    printf("..........................\n");
    printf("Selection: ");
    option = inputIntRange(0, 2);
    putchar('\n');

    if (option == 1)
    {
      searchPatientByPatientNumber(patient, max);
      suspend();
    }
    else if (option == 2)
    {
      searchPatientByPhoneNumber(patient, max);
      suspend();
    }
    else
    {
      flag = 1;
    }
  }
}

// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
  int i = 0, index = 0, newPatientNumber;
  int flag = 0;

  // Check if there is an empty space in the patient array

  while (i < max && flag == 0)
  {
    if (patient[i].patientNumber == 0)
    {
      index = i;
      flag = 1;
    }
    i++;
  }

  // If there is no empty space display a message else add a new patient record
  if (flag == 1)
  {
    newPatientNumber = nextPatientNumber(patient, max);
    patient[index].patientNumber = newPatientNumber;
    inputPatient(&patient[index]);
    printf("*** New patient record added ***\n\n");
  }
  else
  {
    printf("ERROR: Patient listing is FULL!\n\n");
  }
}

// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
  int patientNumber, index;

  printf("Enter the patient number: ");
  patientNumber = inputIntPositive();

  putchar('\n');

  if (findPatientIndexByPatientNum(patientNumber, patient, max) != -1)
  {
    index = findPatientIndexByPatientNum(patientNumber, patient, max);
    menuPatientEdit(&patient[index]);
  }
  else
  {
    printf("ERROR: Patient record not found!\n\n");
  }
}

// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
  int patientNumber, index;
  char confirm;
  struct Patient emptyPatient = {0};

  printf("Enter the patient number: ");
  patientNumber = inputIntPositive();

  putchar('\n');

  if (findPatientIndexByPatientNum(patientNumber, patient, max) != -1)
  {
    index = findPatientIndexByPatientNum(patientNumber, patient, max);
    printf("Name  : %s\n", patient[index].name);
    printf("Number: %05d\n", patient[index].patientNumber);
    printf("Phone : ");
    displayFormattedPhone(patient[index].phone.number);
    printf(" (%s)\n\n", patient[index].phone.description);

    // Check if the user wants to remove the patient record
    printf("Are you sure you want to remove this patient record? (y/n): ");
    confirm = inputCharOption("yn");

    if (confirm == 'y')
    {
      patient[index] = emptyPatient;
      printf("Patient record has been removed!\n\n");
    }
    else if (confirm == 'n')
    {
      printf("Operation aborted.\n\n");
    }
  }
  else
  {
    printf("ERROR: Patient record not found!\n\n");
  }
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(const struct ClinicData *data)
{
  int i, j;

  // Sort the appointment array
  sortApt(data->appointments, data->maxAppointments);

  // Display the appointment table header
  displayScheduleTableHeader(NULL, FMT_FORM);

  // Loop through the appointment and patient data and display the appointment data
  for (i = 0; i < data->maxAppointments; i++)
  {
    for (j = 0; j < data->maxPatient; j++)
    {
      if (data->appointments[i].patientNumber && data->patients[j].patientNumber)
      {
        if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
        {
          displayScheduleData(&data->patients[j], &data->appointments[i], FMT_FORM);
        }
      }
    }
  }

  putchar('\n');
}

// View appointment schedule for the user input date
void viewAppointmentSchedule(const struct ClinicData *data)
{
  int i, j, maxDays = TOTAL_MAX_DAYS;
  struct Date date;

  printf("Year        : ");
  date.year = inputIntPositive();

  printf("Month (1-%d): ", TOTAL_MONTHS);
  date.month = inputIntRange(1, TOTAL_MONTHS);

  if (date.month == 4 || date.month == 9 || date.month == 11)
  {
    maxDays = TOTAL_MIN_DAYS;
  }
  if (date.month == 2)
  {
    maxDays = 28;
  }
  if (date.year % 4 == 0 && date.month == 2)
  {
    maxDays = 29;
  }

  printf("Day (1-%d)  : ", maxDays);
  date.day = inputIntRange(1, maxDays);

  // Sort the appointment array
  sortApt(data->appointments, data->maxAppointments);

  putchar('\n');

  // Display the appointment table header
  displayScheduleTableHeader(&date, 0);

  // Loop through the appointment and patient data and display the appointment data
  for (i = 0; i < data->maxAppointments; i++)
  {
    for (j = 0; j < data->maxPatient; j++)
    {
      if (data->appointments[i].patientNumber && data->patients[j].patientNumber)
      {
        if (data->appointments[i].patientNumber == data->patients[j].patientNumber)
        {
          if (data->appointments[i].date.year == date.year && data->appointments[i].date.month == date.month && data->appointments[i].date.day == date.day)
          {
            displayScheduleData(&data->patients[j], &data->appointments[i], 0);
          }
        }
      }
    }
  }

  putchar('\n');
}

// Add an appointment record to the appointment array
void addAppointment(struct Appointment *apt, int maxApt, struct Patient *patient, int maxPat)
{
  struct Time time;
  struct Date date;
  int patientNumber, index, isSlotAvail;
  int flag = 0, maxDays = TOTAL_MAX_DAYS;

  printf("Patient Number: ");
  patientNumber = inputIntPositive();
  index = findPatientIndexByPatientNum(patientNumber, patient, maxPat);

  if (index >= 0)
  {
    while (flag == 0)
    {
      printf("Year        : ");
      date.year = inputIntPositive();

      printf("Month (1-%d): ", TOTAL_MONTHS);
      date.month = inputIntRange(1, TOTAL_MONTHS);

      if (date.month == 4 || date.month == 9 || date.month == 11)
      {
        maxDays = TOTAL_MIN_DAYS;
      }
      if (date.month == 2)
      {
        maxDays = 28;
      }
      if (date.year % 4 == 0 && date.month == 2)
      {
        maxDays = 29;
      }

      printf("Day (1-%d)  : ", maxDays);
      date.day = inputIntRange(1, maxDays);

      printf("Hour (0-%d)  : ", TOTAL_HRS);
      time.hour = inputIntRange(0, TOTAL_HRS);

      printf("Minute (0-%d): ", TOTAL_MINS);
      time.min = inputIntRange(0, TOTAL_MINS);

      isSlotAvail = validateTimeSlot(apt, date, time, maxApt);

      if (!isSlotAvail)
      {
        do
        {
          printf("ERROR: Time must be between %02d:00 and %02d:00 in %02d minute intervals.\n\n", START_HR, END_HR, MIN_INTERVAL);
          printf("Hour (0-%d)  : ", TOTAL_HRS);
          time.hour = inputIntRange(0, TOTAL_HRS);
          printf("Minute (0-%d): ", TOTAL_MINS);
          time.min = inputIntRange(0, TOTAL_MINS);
        } while ((time.hour < START_HR ||
                  time.hour > END_HR) ||
                 (time.hour == END_HR && time.min > 0) ||
                 (time.min % MIN_INTERVAL != 0));

        flag = 1;
      }
      else
      {
        putchar('\n');
        printf("ERROR: Appointment timeslot is not available!\n\n");
      }
    }

    index = nextAptSlot(apt, maxApt);
    apt[index].patientNumber = patientNumber;
    apt[index].date = date;
    apt[index].time = time;

    putchar('\n');
    printf("*** Appointment scheduled! ***\n\n");
  }
}

// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment *apt, int maxApt, struct Patient *patient, int maxPat)
{
  struct Date date;
  int patientNumber, index, aptIndex, maxDays = 0;
  char option;

  printf("Patient Number: ");
  patientNumber = inputIntPositive();
  index = findPatientIndexByPatientNum(patientNumber, patient, maxPat);

  if (index >= 0)
  {
    printf("Year        : ");
    date.year = inputIntPositive();

    printf("Month (1-%d): ", TOTAL_MONTHS);
    date.month = inputIntRange(1, TOTAL_MONTHS);

    if (date.month == 4 || date.month == 9 || date.month == 11)
    {
      maxDays = TOTAL_MIN_DAYS;
    }
    if (date.month == 2)
    {
      maxDays = 28;
    }
    if (date.year % 4 == 0 && date.month == 2)
    {
      maxDays = 29;
    }

    printf("Day (1-%d)  : ", maxDays);
    date.day = inputIntRange(1, maxDays);

    aptIndex = validateApt(apt, patientNumber, date, maxApt);

    if (aptIndex >= 0)
    {
      putchar('\n');
      displayPatientData(&patient[index], FMT_FORM);
      printf("Are you sure you want to remove this appointment (y,n): ");

      option = inputCharOption("yn");

      if (option == 'y')
      {
        apt[aptIndex].patientNumber = 0;
        putchar('\n');
        printf("Appointment record has been removed!\n\n");
      }
    }
    else
    {
      printf("ERROR: Appointment record not found!\n\n");
    }
  }
  else
  {
    printf("ERROR: Patient record not found!\n\n");
  }
}

//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
  int patientNumber, index;

  printf("Search by patient number: ");
  patientNumber = inputIntPositive();

  putchar('\n');

  if (findPatientIndexByPatientNum(patientNumber, patient, max) != -1)
  {
    index = findPatientIndexByPatientNum(patientNumber, patient, max);
    displayPatientData(&patient[index], FMT_FORM);
    putchar('\n');
  }
  else
  {
    printf("*** No records found ***\n\n");
  }
}

// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{
  int i, flag = 0;
  char phoneNumber[PHONE_LEN + 1];
  char fmt[PHONE_LEN + 1];

  printf("Search by phone number: ");
  sprintf(fmt, "%%%ds", PHONE_LEN);
  scanf(fmt, phoneNumber);
  clearInputBuffer();

  putchar('\n');

  displayPatientTableHeader();

  // Loop through the patient array and display the patient records that match the phone number
  for (i = 0; i < max; i++)
  {
    if (strcmp(phoneNumber, patient[i].phone.number) == 0)
    {
      displayPatientData(&patient[i], FMT_TABLE);
      flag = 1;
    }
  }

  putchar('\n');

  if (flag == 0)
  {
    printf("*** No records found ***\n\n");
  }
}

// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
  int i, highPatNum, nxtPatNum;

  // Loop through the patient array and get the highest patient number
  highPatNum = patient[0].patientNumber;
  for (i = 0; i < max; i++)
  {
    if (patient[i].patientNumber > highPatNum)
    {
      highPatNum = patient[i].patientNumber;
    }
  }

  // Add 1 to the highest patient number to get the next highest patient number
  nxtPatNum = highPatNum + 1;

  return nxtPatNum;
}

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber,
                                 const struct Patient patient[], int max)
{
  int i, index, isTrue = 0;

  // Loop through the patient array and find the patient array index
  for (i = 0; i < max; i++)
  {
    if (patient[i].patientNumber == patientNumber)
    {
      index = i;
      isTrue = 1;
    }
  }

  if (isTrue == 0)
  {
    index = -1;
  }

  return index;
}

// Sort the appointment array by the total minutes
void sortApt(struct Appointment apt[], int max)
{
  int i, j;
  struct Appointment temp;

  // Calculate the total minutes for each appointment
  for (i = 0; i < max; i++)
  {
    apt[i].time.min = (apt[i].date.year * 12 * 30 * 24 * 60) + (apt[i].date.month * 30 * 24 * 60) + (apt[i].date.day * 24 * 60) + (apt[i].time.hour * 60) + apt[i].time.min;
  }

  // Sort the appointment array by total minutes
  for (i = max - 1; i > 0; i--)
  {
    for (j = 0; j < i; j++)
    {
      if (apt[j].time.min > apt[j + 1].time.min)
      {
        temp = apt[j];
        apt[j] = apt[j + 1];
        apt[j + 1] = temp;
      }
    }
  }

  // Convert the total minutes back to date and time
  for (i = 0; i < max; i++)
  {
    apt[i].time.min = apt[i].time.min - (apt[i].date.year * 12 * 30 * 24 * 60) - (apt[i].date.month * 30 * 24 * 60) - (apt[i].date.day * 24 * 60) - (apt[i].time.hour * 60);
  }
}

// Validate Time Slot
int validateTimeSlot(const struct Appointment *apt, struct Date date, struct Time time, int maxApt)
{
  int i, isAvail = 0;

  // Loop through the appointment array and check if the appointment time slot is available
  for (i = 0; i < maxApt; i++)
  {
    if (apt[i].date.day == date.day && apt[i].date.month == date.month && apt[i].date.year == date.year && apt[i].time.hour == time.hour && apt[i].time.min == time.min)
    {
      isAvail = 1;
    }
  }

  return isAvail;
}

// Validate an appointment
int validateApt(const struct Appointment *apt, int patNum, struct Date date, int maxApt)
{
  int i, isAvail = 0;

  // Loop through the appointment array and check if the appointment exists
  for (i = 0; i < maxApt; i++)
  {
    if ((apt[i].patientNumber == patNum) && (apt[i].date.day == date.day) && (apt[i].date.month == date.month) && (apt[i].date.year == date.year))
    {
      isAvail = i;
    }
  }

  return isAvail;
}

// Check for the next appointment slot available
int nextAptSlot(const struct Appointment *apt, int maxApt)
{
  int i, nextSlot = 0;

  // Loop through the appointment array and check for the next available appointment slot
  for (i = 0; i < maxApt; i++)
  {
    if (apt[i].patientNumber < 1)
    {
      nextSlot = i;
    }
  }

  return nextSlot;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient *patient)
{
  printf("Patient Data Input\n"
         "------------------\n");
  printf("Number: %05d\n", patient->patientNumber);

  printf("Name  : ");
  inputCString(patient->name, 1, NAME_LEN);

  putchar('\n');

  inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
void inputPhoneData(struct Phone *phone)
{
  int selection;
  char phoneNum[PHONE_LEN + 1];

  // Get user input for phone data
  printf("Phone Information\n");
  printf("-----------------\n");
  printf("How will the patient like to be contacted?\n");
  printf("1. Cell\n");
  printf("2. Home\n");
  printf("3. Work\n");
  printf("4. TBD\n");
  printf("Selection: ");
  selection = inputIntRange(1, 4);

  if (selection == 1)
  {
    putchar('\n');
    strcpy(phone->description, "CELL");
    printf("Contact: %s\n", phone->description);
    printf("Number : ");
    inputCStringNum(phoneNum, PHONE_LEN, PHONE_LEN);
    strcpy(phone->number, phoneNum);
  }
  else if (selection == 2)
  {
    putchar('\n');
    strcpy(phone->description, "HOME");
    printf("Contact: %s\n", phone->description);
    printf("Number : ");
    inputCStringNum(phoneNum, PHONE_LEN, PHONE_LEN);
    strcpy(phone->number, phoneNum);
  }
  else if (selection == 3)
  {
    putchar('\n');
    strcpy(phone->description, "WORK");
    printf("Contact: %s\n", phone->description);
    printf("Number : ");
    inputCStringNum(phoneNum, PHONE_LEN, PHONE_LEN);
    strcpy(phone->number, phoneNum);
  }
  else if (selection == 4)
  {
    strcpy(phone->description, "TBD");
    *phone->number = 0;
  }

  putchar('\n');
}

//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char *datafile, struct Patient patients[], int max)
{
  int i, count = 0;

  FILE *fp = NULL;
  fp = fopen(datafile, "r");

  if (fp != NULL)
  {
    for (i = 0; i < max && fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]",
                                  &patients[i].patientNumber,
                                  patients[i].name,
                                  patients[i].phone.description,
                                  patients[i].phone.number) != EOF;
         i++)
    {
      count = i + 1;
    }

    fclose(fp);
  }
  else
  {
    printf("ERROR: Cannot open file\n\n");
  }

  return count;
}

// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char *datafile, struct Appointment appoints[], int max)
{
  int i, count = 0;

  FILE *fp = NULL;
  fp = fopen(datafile, "r");

  if (fp != NULL)
  {
    for (i = 0; i < max && fscanf(fp, "%d,%d,%d,%d,%d,%d",
                                  &appoints[i].patientNumber,
                                  &appoints[i].date.year,
                                  &appoints[i].date.month,
                                  &appoints[i].date.day,
                                  &appoints[i].time.hour,
                                  &appoints[i].time.min) != EOF;
         i++)
    {
      count = i + 1;
    }

    fclose(fp);
  }
  else
  {
    printf("ERROR: Cannot open file\n\n");
  }

  return count;
}
