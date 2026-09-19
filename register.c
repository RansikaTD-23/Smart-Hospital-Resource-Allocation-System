#include <stdio.h>
#include <string.h>
#include "hospital.h"

int getValidInt(int min, int max, char *word)
{
    int value;
    int valid;

    do{
        printf("%-20s: ", word);
        valid = scanf("%d", &value);

        if(valid != 1){
            printf("  >> Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            value = min - 1;
        }
        else if(value < min || value > max){
            printf("  >> Invalid input. Please enter a number between %d and %d.\n", min, max);
        }
    }while(value < min || value > max);

    return value;
}

void registerPatients(char patientName[][NAME_LENGTH],
                      int patientAge[],
                      int patientEmergencyLevel[],
                      int specialtyId[],
                      int isAdmitted[],
                      int wardId[],
                      int daysAdmitted[],
                      int specialtyQueueCount[],
                      float patientFinalBill[],
                      float patientDiscount[],
                      int *count)
    {
        int i = *count;

        printf("\n============================================================\n");
        printf("                   PATIENT REGISTRATION\n");
        printf("============================================================\n");
        printf("   1. Mr.\n");
        printf("   2. Mrs.\n");
        printf("   3. Miss\n");
        int titleChoice = getValidInt(1, 3, "Title");

        char titleText[10];
        if(titleChoice == 1){
            strcpy(titleText, "Mr.");
        }
        else if(titleChoice == 2){
            strcpy(titleText, "Mrs.");
        }
        else{
            strcpy(titleText, "Miss");
        }

        char fullName[NAME_LENGTH];
        printf("%-20s: ", "Patient Name");
        scanf(" %[^\n]", fullName);

        sprintf(patientName[i], "%s %s", titleText, fullName);

        patientAge[i] = getValidInt(0, 120, "Age of Patient");

        printf("\n------------------------------------------------------------\n");
        printf("                  SELECT EMERGENCY LEVEL\n");
        printf("------------------------------------------------------------\n");
        printf("   1. Normal\n");
        printf("   2. Urgent\n");
        printf("   3. Critical\n");
        patientEmergencyLevel[i] = getValidInt(1, 3, "Emergency Level");

        printf("\n------------------------------------------------------------\n");
        printf("                    SELECT SPECIALTY\n");
        printf("------------------------------------------------------------\n");
        printf("   1. General Practice (OPD)\n");
        printf("   2. Paediatrics\n");
        printf("   3. Cardiology\n");
        printf("   4. Neurology\n");
        specialtyId[i] = getValidInt(1, 4, "Specialty ID");

        printf("\n------------------------------------------------------------\n");
        printf("                   PATIENT ADMISSION\n");
        printf("------------------------------------------------------------\n");
        printf("   1. Admitted\n");
        printf("   0. Not Admitted\n");
        isAdmitted[i] = getValidInt(0, 1, "Admitted (0/1)");

        int bedNum = 0;
        if(isAdmitted[i]==1){
            printf("\n------------------------------------------------------------\n");
            printf("                     SELECT WARD ID\n");
            printf("------------------------------------------------------------\n");
            printf("   1. General Ward\n");
            printf("   2. Paediatric Ward\n");
            printf("   3. Surgical Ward\n");
            printf("   4. ICU (Intensive Care Unit)\n");
            wardId[i] = getValidInt(1, 4, "Ward ID");

            daysAdmitted[i] = getValidInt(1, 9999, "Days Admitted");

            bedNum = allocateBed(wardId[i],bedOccupancy,wardTotalBedCapacity);
            if(bedNum == -1){
                printf("\n  >> Sorry, %s is Full. No beds available.\n", wardName[wardId[i]-1]);
            }

        }else{
            wardId[i]=0;
            daysAdmitted[i]=0;
        }

        printf("\n============================================================\n");
        printf("  Patient Registered Successfully! Patient ID: PAT-%d\n", 1000+(i+1));
        printf("============================================================\n");
        (*count)++;

        //Billing Calculations
        float waitingTime = calculateWaitingTime(specialtyId[i],specialtyQueueCount,specialtyConslationTime);
        specialtyQueueCount[specialtyId[i]-1]++;
        float baseFee = specialtyConslationFee[specialtyId[i]-1];
        float surcharge = calculateEmergencySurcharge(patientEmergencyLevel[i], baseFee);
        float wardCost = calculateTotalWardStayCost(daysAdmitted[i], wardId[i], wardDailyBedRate);
        float grossTotal = calculateGrossTotalBill(baseFee, surcharge, wardCost);
        float discount = calculateSubsidyDiscount(patientAge[i], grossTotal);
        float finalAmount = calculateFinalAmountPayable(grossTotal, discount);

        //Performance Report Print
        patientFinalBill[i] = finalAmount;
        patientDiscount[i] = discount;
        appendPatientRecord(1000+(i+1), patientName[i], finalAmount);

        //Bill Print
        printBill(1000+(i+1), patientName[i], patientAge[i], specialtyId[i], wardId[i], isAdmitted[i],
                  patientEmergencyLevel[i], daysAdmitted[i], baseFee, surcharge, wardCost,
                  grossTotal, discount, finalAmount, waitingTime,bedNum);

        while(getchar() != '\n');
        printf("\nPress Enter to return to the menu...");
        getchar();

    }
