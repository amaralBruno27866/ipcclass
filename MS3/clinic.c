/*/////////////////////////////////////////////////////////////////////////
                        Assignment 1 - Milestone 3
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

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
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
void displayScheduleData(const struct Patient* patient,
    const struct Appointment* appoint,
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


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
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
            viewAllAppointments(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 2:
            viewAppointmentSchedule(data);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
            suspend();
            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                data->patients, data->maxPatient);  // ToDo: You will need to create this function!
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
// (Copy your code from MS#2)
void displayAllPatients(const struct Patient patient[], int max, int fmt) {

    int totalRecords = 0;
    int i;

    displayPatientTableHeader();

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
// (Copy your code from MS#2)
void searchPatientData(const struct Patient patient[], int max) {
    
    int option;

    do {
        printf("Search Options\n");
        printf("==========================\n");
        printf("1) By patient number\n");
        printf("2) By phone number\n");
        printf("..........................\n");
        printf("0) Previous menu\n");
        printf("..........................\n");
        printf("Selection: ");
        option = inputIntRange(0,2);

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
    } while (option != 0);

    printf("\n");
}

// Add a new patient record to the patient array
// (Copy your code from MS#2)
void addPatient(struct Patient patient[], int max) {
    int i;
    int firstFreeIndex = -1;
    // New patient
    struct Patient newPatient = { 0, "", {" "," "} };

    for (i = 0; i < max; i++) {
        if (firstFreeIndex == -1 && patient[i].patientNumber == 0) { // executed only once
            firstFreeIndex = i;
        }
    }

    if (firstFreeIndex == -1) {
        printf("ERROR: Patient listing is FULL!\n\n");

    }
    else {

        // Creating new patient number
        int nextNumber = nextPatientNumber(patient, max);
        // Add patient number to the new patient
        newPatient.patientNumber = nextNumber;
        // Add the new patient to the array of patients
        patient[firstFreeIndex] = newPatient;

        inputPatient(&patient[firstFreeIndex]);

        printf("*** New patient record added ***\n");
        printf("\n");
    }
}

// Edit a patient record from the patient array
// (Copy your code from MS#2)
void editPatient(struct Patient patient[], int max) {
    int patientNumber;

    printf("Enter the patient number: ");
    patientNumber = inputIntPositive();
    printf("\n");
    int index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1) {
        printf("ERROR: Patient record not found!\n\n");
    }
    else {
        menuPatientEdit(&patient[index]);
    }
}

// Remove a patient record from the patient array
// (Copy your code from MS#2)
void removePatient(struct Patient patient[], int max) {
    int patientNumber;
    char confirm;

    printf("Enter the patient number: ");
    patientNumber = inputIntPositive();
    printf("\n");
    int index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1) {
        printf("ERROR: Patient record not found!\n\n");
    }
    else {

        displayPatientData(&patient[index], FMT_FORM);

        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        confirm = inputCharOption("yn"); // prompt user to type y or n

        if (confirm == 'y' || confirm == 'Y') {
            patient[index].patientNumber = 0;
            strcpy(patient[index].name, "");
            strcpy(patient[index].phone.description, "");
            strcpy(patient[index].phone.number, "");

            printf("Patient record has been removed!\n\n");
        }
        else {
            printf("Operation aborted.\n\n");
        }
    } // end else (index == -1)
}

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// Milestone #3 mandatory functions...
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
// Todo:
void viewAllAppointments(struct ClinicData* data) {

    int i;
    int index;

    sortArrayOfAppointments((*data).appointments, (*data).maxAppointments);

    displayScheduleTableHeader(NULL, 1);

    // Iterate the appointments
    for (i = 0; i < data->maxAppointments; i++) { // iterate the list of Appointment

        // Find a patient by Patient number.
        index = findPatientIndexByPatientNum(
            data->appointments[i].patients.patientNumber, // patient number inside the Appointment structure
            data->patients, // list of patients
            data->maxPatient
        );

        if (index >= 0) {
            displayScheduleData(&data->patients[index], &data->appointments[i], 1);
        }
    }
    printf("\n");
}

// View appointment schedule for the user input date
// Todo:
void viewAppointmentSchedule(struct ClinicData* data) {

    int i;
    int indexPatient;
    int year;
    int month;
    int day;
    int maxDayOfTheMonth;

    printf("Year        : ");
    year = inputIntRange(2023, 2030);
    printf("Month (1-12): ");
    month = inputIntRange(1, 12);
    maxDayOfTheMonth = handleDayMax(year, month);

    printf("Day (1-%d)  : ", maxDayOfTheMonth);
    day = inputIntRange(1, maxDayOfTheMonth);

    printf("\n");

    // Print the header
    struct Date date = { year, month, day }; // this struct was created only to pass year, month and day
    //   to the function that print the header.
    // Note that the function that print the header requires a 
    //   a input parameter of type struct Date

    displayScheduleTableHeader(&date, 0); // the flag zero means to print header only for time

    // Iterate the appointment
    for (i = 0; i < data->maxAppointments; i++) { // iterate the list of Appointment
        if ((*data).appointments[i].date.year == year &&   // comparing appointment year with the year provided by the user
            (*data).appointments[i].date.month == month &&  // comparing appointment month with the month provided by the user
            (*data).appointments[i].date.day == day) {    // comparing appointment day with the day provided by the user

            // Find the patient that has the appointment we have just found
            indexPatient = findPatientIndexByPatientNum(
                (*data).appointments[i].patients.patientNumber,
                (*data).patients,
                (*data).maxPatient
            );
            // Display the appointments that have same year, month and day
            displayScheduleData(&data->patients[indexPatient], &data->appointments[i], 0);
        }
    }

    printf("\n");
}

// Add an appointment record to the appointment array
// Todo:
void addAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient) {

    int i;
    int patientNumber;
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int maxDayOfTheMonth;

    int valid;  // 0: valid / 1: invalid
    int timeslotAvailable; // 1: timeslot available  / 0:
    int indexPatient; // to check if patient exists

    int firstFreeIndexForAppointment = -1; // we will add appointments to the first free index

    printf("Patient Number: ");
    patientNumber = inputInt();
    indexPatient = findPatientIndexByPatientNum(patientNumber, patients, maxPatient);
    if (indexPatient == -1) {
        printf("ERROR: Patient not found.\n\n");
        return; // stop the method aqui
    }

    do {
        printf("Year        : ");
        year = inputIntRange(2023, 2030);

        printf("Month (1-12): ");
        month = inputIntRange(1, 12);
        maxDayOfTheMonth = handleDayMax(year, month);

        printf("Day (1-%d)  : ", maxDayOfTheMonth);
        day = inputIntRange(1, maxDayOfTheMonth);

        do {
            printf("Hour (0-23)  : ");
            hour = inputInt();
            printf("Minute (0-59): ");
            minute = inputInt();

            valid = 1;
            if ((hour < START_HOUR || hour>END_HOUR) ||
                (minute != 0 && minute % MINUTE_INTERVAL != 0) ||
                (hour == END_HOUR && minute > 0)
                ) {
                valid = 0;
                printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n",
                    START_HOUR,
                    END_HOUR,
                    MINUTE_INTERVAL
                );
            }

        } while (valid == 0);

        // Check if the timeslot is available
        timeslotAvailable = 1;
        // Iterate the appointment to check if timeslot is available
        for (i = 0; i < maxAppointments; i++) { // iterate the list of Appointment
            if (appointments[i].date.year == year &&    // comparing appointment year with the year provided by the user
                appointments[i].date.month == month &&  // comparing appointment month with the month provided by the user
                appointments[i].date.day == day &&      // comparing appointment day with the day provided by the user
                appointments[i].time.hour == hour &&   // comparing appointment hour with the hour provided by the user
                appointments[i].time.min == minute      // comparing appointment minute with the minute provided by the user
                ) {
                timeslotAvailable = 0;
                printf("\nERROR: Appointment timeslot is not available!\n\n");
            }
        }

    } while (timeslotAvailable == 0);


    // Add a new appointment 
    for (i = 0; i < maxAppointments; i++) {
        if (firstFreeIndexForAppointment == -1 && appointments[i].patients.patientNumber == 0) { // executed only once
            firstFreeIndexForAppointment = i;
        }
    }

    if (firstFreeIndexForAppointment == -1) {
        printf("ERROR: Appointment listing is FULL!\n\n");
    }
    else {

        // Creating new patient number
        struct Appointment newAppointment = { 0, {year,month,day},{hour,minute}, {patientNumber} };
        appointments[firstFreeIndexForAppointment] = newAppointment;

        printf("\n*** Appointment scheduled! ***");
        printf("\n");
    }


    printf("\n");
}


// Remove an appointment record from the appointment array
// Todo:
void removeAppointment(struct Appointment* appointments, int maxAppointments, struct Patient* patients, int maxPatient) {

    int i;
    int patientNumber;
    int year;
    int month;
    int day;
    int maxDayOfTheMonth;
    int indexPatient; // to check if patient exists
    char confirm;

    printf("Patient Number: ");
    patientNumber = inputInt();
    indexPatient = findPatientIndexByPatientNum(patientNumber, patients, maxPatient);
    if (indexPatient == -1) {
        printf("ERROR: Patient record not found!\n\n");
        return; // stop the method aqui
    }

    printf("Year        : ");
    year = inputIntRange(2023, 2030);

    printf("Month (1-12): ");
    month = inputIntRange(1, 12);
    maxDayOfTheMonth = handleDayMax(year, month);

    printf("Day (1-%d)  : ", maxDayOfTheMonth);
    day = inputIntRange(1, maxDayOfTheMonth);

    printf("\n");
    printf("Name  : %s\n", patients[indexPatient].name);
    printf("Number: %05d\n", patientNumber);
    printf("Phone : ");
    displayFormattedPhone(patients[indexPatient].phone.number);
    printf(" (%s)\n", patients[indexPatient].phone.description);

    printf("Are you sure you want to remove this appointment (y,n): ");
    confirm = inputCharOption("yn"); // prompt user to type y or n

    if (confirm == 'y' || confirm == 'Y') {

        // Iterate the appointment to find the appointment
        for (i = 0; i < maxAppointments; i++) { // iterate the list of Appointment
            if (appointments[i].patients.patientNumber == patientNumber &&    // comparing patient number
                appointments[i].date.year == year &&    // comparing appointment year with the year provided by the user
                appointments[i].date.month == month &&  // comparing appointment month with the month provided by the user
                appointments[i].date.day == day      // comparing appointment day with the day provided by the user
                ) {

                // remove appointment
                struct Appointment emptyAppointment = { 0 };
                appointments[i] = emptyAppointment;

            }
        }
        printf("\nAppointment record has been removed!\n");
        printf("\n");
    }
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
// (Copy your code from MS#2)
void searchPatientByPatientNumber(const struct Patient patient[], int max) {

    int patientNumber;

    printf("\n");
    printf("Search by patient number: ");
    patientNumber = inputIntPositive();
    printf("\n");

    int index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index != -1) {
        //printf("Patient Number: %d\n", patient[index].patientNumber);
        //printf("Patient Name: %s\n", patient[index].name);
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
// (Copy your code from MS#2)
void searchPatientByPhoneNumber(const struct Patient patient[], int max) {

    char searchNumber[PHONE_LEN + 1];
    int totalRecords = 0;
    int i;

    printf("\n");
    printf("Search by phone number: ");
    inputCString(searchNumber, PHONE_LEN, PHONE_LEN);
    printf("\n");

    displayPatientTableHeader();

    for (i = 0; i < max; i++) {
        if (strcmp(searchNumber, patient[i].phone.number) == 0) {
            displayPatientData(&patient[i], FMT_TABLE);
            totalRecords++;
        }
    }

    if (totalRecords == 0) {
        printf("\n");
        printf("*** No records found ***\n");
    }
    printf("\n");

}

// Get the next highest patient number
// (Copy your code from MS#2)
int nextPatientNumber(const struct Patient patient[], int max) {
    int maxNumber = 0;
    int i;

    for (i = 0; i < max; i++) {
        if (patient[i].patientNumber > maxNumber) {
            maxNumber = patient[i].patientNumber;
        }
    }
    return maxNumber + 1;
}

// Find the patient array index by patient number (returns -1 if not found)
// (Copy your code from MS#2)
int findPatientIndexByPatientNum(int patientNumber, const struct Patient patient[], int max) {
    int i;
    for (i = 0; i < max; i++) {
        if (patientNumber == patient[i].patientNumber) {
            return i;
        }
    }
    return -1;
}

// Implementation of Selection Sort algorithm to show appointments in order by year, month, day, hour, min
// This function is called inside viewAllAppointments()
// Reference for this algorightm: https://en.wikipedia.org/wiki/Selection_sort
void sortArrayOfAppointments(struct Appointment* appointments, int maxAppointments) {

    int i;
    int j;
    int invert; // 1: true, 2: false
    struct Appointment tempAppointment;

    // order the list of appointments by year, month, day, hour and minute
     // Using Selection Sort
    for (i = 0; i < maxAppointments; i++)  // first Loop of the selection sort algorithm
    {
        if (appointments[i].patients.patientNumber != 0) { // check only element of the array that are not empty

            for (j = i + 1; j < maxAppointments; j++) { // second Loop of the selection sort algorithm

                invert = 0; // false
                if (appointments[j].patients.patientNumber != 0) { // check only element of the array that are not empty
                    // Check year
                    if (appointments[i].date.year > appointments[j].date.year) { // comparing year with next element
                        invert = 1;
                    }
                    else if (appointments[i].date.year == appointments[j].date.year) { // comparing year with next element
                        // check the mont
                        if (appointments[i].date.month > appointments[j].date.month) { // comparing month with next element
                            invert = 1;
                        }
                        else if (appointments[i].date.month == appointments[j].date.month) { // comparing month with next element
                            // check day
                            if (appointments[i].date.day > appointments[j].date.day) { // comparing day with next element
                                invert = 1;
                            }
                            else if (appointments[i].date.day == appointments[j].date.day) { // comparing day with next element
                                // check hour
                                if (appointments[i].time.hour > appointments[j].time.hour) { // comparing hour with next element
                                    invert = 1;
                                }
                                else if (appointments[i].time.hour == appointments[j].time.hour) { // comparing hour with next element
                                    // check minute
                                    if (appointments[i].time.min > appointments[j].time.min) { // comparing time with next element
                                        invert = 1;
                                    } // end if for minute
                                } // end if hour
                            } // end if day
                        } // end if month
                    }// end if year

                    if (invert) {
                        // swap elements
                        tempAppointment = appointments[i];
                        appointments[i] = appointments[j];
                        appointments[j] = tempAppointment;
                    }
                }
            } //end for (j)
        }
    } // end of sorting function
} //end function


//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
// (Copy your code from MS#2)
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
// (Copy your code from MS#2)
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

    // inputIntRange already validate the range and print error message. No need to create a do/while here 
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

    // Note: The function inputIntRange(1, 4) above guarantees the input range is 1 - 4

    // add phone type
    strcpy(phone->description, value);

    if (select != 4) { // don't ask phone number for TBD
        printf("\nContact: %s", value);
        printf("\nNumber : ");
        inputPhoneNumber(phone->number, PHONE_LEN);
    }
    printf("\n");
}


//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
/// ToDo:
int importPatients(const char* datafile, struct Patient patients[], int max) {

    FILE* fp = NULL;

    int i = 0; // total lines. Starting in zero. This is the return of the method

    char line[1024]; // representes each line of the file
    int j = 0; // Used to iterate each character of the line

// When we break the line in small substrings, the 1st string is the pacient number, 
//  the 2nd is the patient name, the 3rd one is the phone description and the last one
//  is the phone number. So we will use this variable 'countToken' to represent that.
    int countToken; // 1: Pacient Number, 2: name, 3: phone description, 4: phone number
    int initialPosition = 0; // The position of the first pipe character
    int finalPosition;    // The position of the last character

    // Open the file
    fp = fopen(datafile, "r"); // dataFile is the file name, for example: "patientData.txt"

    if (fp != NULL) {

        while (i < max && fgets(line, 1024, fp) != NULL) {

            countToken = 1;
            initialPosition = 0;

            for (j = 0; line[j] != '\0'; j++) {

                if (line[j] == '|' || line[j] == '\n') {
                    char token[99] = ""; // We will break the line in the pipe character. 
                    // The token represents each substring between pipe

                    finalPosition = j;
                    // Copying the substring to the variable token
                    strncpy(token, line + initialPosition, finalPosition - initialPosition);

                    switch (countToken) {
                    case 1:
                        patients[i].patientNumber = convertStringToNumber(token);
                        break;
                    case 2:
                        strcpy(patients[i].name, token);
                        break;
                    case 3:
                        strcpy(patients[i].phone.description, token);
                        break;
                    case 4:
                        strcpy(patients[i].phone.number, token);
                        break;
                    } // end switch
                    countToken++;
                    initialPosition = j + 1;
                }//end if

            }//end while
            //cleanString(line); // clean the string
            i++;
        }
        fclose(fp);

    }
    else {
        printf("Failed to open file\n");
    }
    return i;
}

// Import appointment data from file into an Appointment array (returns # of records read)
// ToDo:
int importAppointments(const char* datafile, struct Appointment appoints[], int max) {

    int i = 0;

    FILE* appointmentList = NULL;

    appointmentList = fopen(datafile, "r");

    if (appointmentList != NULL) {
        while (i < max && fscanf(appointmentList, "%d,%d,%d,%d,%d,%d",
            &appoints[i].patients.patientNumber,
            &appoints[i].date.year,
            &appoints[i].date.month,
            &appoints[i].date.day,
            &appoints[i].time.hour,
            &appoints[i].time.min) == 6) {
            i++;
        }
        fclose(appointmentList);
        return i; 
    }
    else {
        printf("Failed to open file\n");
        return -1; 
    }
}
