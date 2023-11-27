/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 2
Full Name  : Bruno Amaral
Student ID#: 143766228
Email      : bamaral2@myseneca.ca
Section    : ZFF

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
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
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
            "Number: %05d\n"
            "Phone : ", patient->name, patient->patientNumber);
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


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
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
            printf("<<< Feature not yet available >>>\n\n");
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
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
void menuPatientEdit(struct Patient* patient)
{

    int selection;

    do {
        printf("Edit Patient (%05d)\n"
            "=========================\n"
            "1) NAME : %s\n"
            "2) PHONE: ", patient->patientNumber, patient->name);

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

// ---------------------------------------------------------------------------
// !!! Put all the remaining function definitions below !!!
// Note: Maintain the same order/sequence as it is listed in the header file
// ---------------------------------------------------------------------------

// Display's all patient data in the FMT_FORM | FMT_TABLE format
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {

    displayPatientTableHeader();

    int i, totalRecords = 0;

    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber != 0) {
            displayPatientData(&patient[i], fmt);
            totalRecords++;
        }
    } // end for
    printf("\n");
    if (totalRecords == 0) {
        printf("*** No records found ***\n");
    }
}


// Search for a patient record based on patient number or phone number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientData(const struct Patient patient[], int max) {
    int option;
    char suspendChar;
    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            searchPatientByPatientNumber(patient, max);
            suspend();
            break;
        case 2:
            searchPatientByPhoneNumber(patient, max);
            suspend();
            break;
        }
        scanf("%c", &suspendChar); // suspend the program after the message "<ENTER> to continue...'
    } while (option != 0);

    printf("\n");
}


// Add a new patient record to the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void addPatient(struct Patient patient[], int max) {

    int i, freeIndex = -1;
    // New patient
    struct Patient newPatient = { 0, "", {" "," "} };

    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber == 0) {
            freeIndex = i;
            break;
        }
    }

    if (freeIndex == -1) {
        printf("ERROR: Patient listing is FULL!\n\n");
        return;
    }

    // Creating new patient number
    int nextNumber = nextPatientNumber(patient, max);
    // Add patient number to the new patient
    newPatient.patientNumber = nextNumber;
    // Add the new patient to the array of patients
    patient[freeIndex] = newPatient;

    inputPatient(&patient[freeIndex]);

    printf("\n*** New patient record added ***\n");
    
    printf("\n");
}

// Edit a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void editPatient(struct Patient patient[], int max) {
    int patientNumber;

    printf("Enter the patient number: ");
    patientNumber = inputIntPositive();
    printf("\n");
    int index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1) {
        printf("ERROR: Patient record not found!\n\n");
        return;
    }

    menuPatientEdit(&patient[index]);
}

// Remove a patient record from the patient array
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void removePatient(struct Patient patient[], int max) {
    int patientNumber;
    char confirm;

    printf("Enter the patient number: ");
    patientNumber = inputIntPositive();
    printf("\n");
    int index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1) {
        printf("ERROR: Patient record not found!\n\n");
        return;
    }

    displayPatientData(&patient[index], FMT_FORM);

    printf("\nAre you sure you want to remove this patient record? (y/n): ");
    confirm = inputCharOption("yYnN");

    if (confirm == 'y' || confirm == 'Y') {
        patient[index].patientNumber = 0;
        strcpy(patient[index].name, "");
        strcpy(patient[index].phone.description, "");
        strcpy(patient[index].phone.number, "");
        //printf("\n");
        printf("Patient record has been removed!\n");
    }
    else {
        printf("Operation aborted.\n");
    }
    printf("\n");
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {

    int patientNumber;

    printf("\n");
    printf("Search by patient number: ");
    scanf("%d", &patientNumber);
    printf("\n");
    int index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index != -1) {
        printf("Name  : %s\n", patient[index].name);
        printf("Number: %05d\n", patient[index].patientNumber);
        printf("Phone : ");
        displayFormattedPhone(patient[index].phone.number);
        printf(" (%s)\n", patient[index].phone.description);
    }
    else {
        printf("*** No records found ***\n");
    }

    printf("\n");
}

// Search and display patient records by phone number (tabular)
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {

    int i;
    char searchNumber[PHONE_LEN + 1];

    printf("\n");
    printf("Search by phone number: ");
    scanf("%s", searchNumber);
    printf("\n");
    int foundRecords = 0;

    displayPatientTableHeader();

    for (i = 0; i < max; i++) {
        if (strcmp(searchNumber, patient[i].phone.number) == 0) {
            displayPatientData(&patient[i], FMT_TABLE);
            foundRecords++;
        }
    }

    if (foundRecords == 0) {
        printf("\n");
        printf("*** No records found ***\n");
    }
    printf("\n");

}

// Get the next highest patient number
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
int nextPatientNumber(const struct Patient patient[], int max) {

    int i, maxNumber = 0;

    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber > maxNumber) {
            maxNumber = patient[i].patientNumber;
        }
    }
    return maxNumber + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i;
    for (i = 0; i < max; i++) {
        if (patientNumber == patient[i].patientNumber) {
            return i;
        }
    }
    return -1;
}

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPatient(struct Patient* patient) {

    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");
    inputCString(patient->name, 1, NAME_LEN);
    putchar('\n');

    inputPhoneData(&patient->phone);
}

// Get user input for phone contact information
// (ToDo: PUT THE FUNCTION DEFINITION BELOW)
void inputPhoneData(struct Phone* phone) {

    int select;
    char value[PHONE_DESC_LEN + 1];

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");

    select = inputIntRange(1, 4);

    switch (select)
    {
    case 1:
        strcpy(value, "CELL");
        break;
    case 2:
        strcpy(value, "HOME");
        break;
    case 3:
        strcpy(value, "WORK");
        break;
    case 4:
        strcpy(value, "TBD");
        break;
    }

    strcpy(phone->description, value);

    if (select != 4) { // don't ask phone number for TBA
        printf("\nContact: %s", value);
        printf("\nNumber : ");

        inputCString(phone->number, (PHONE_LEN), (PHONE_LEN));
    }
    printf("\n");
}