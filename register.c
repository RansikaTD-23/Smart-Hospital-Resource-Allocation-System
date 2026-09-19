#include <stdio.h>
#include "hospital.h"

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
        printf("%-20s: ", "Patient Name");
        scanf(" %[^\n]",patientName[i]);

        do{
            printf("%-20s: ", "Age of Patient");
            scanf("%d",&patientAge[i]);
            if(patientAge[i]<0 || patientAge[i]>120){
                printf("  >> Invalid Age. Please enter a realistic age.\n");
            }
        }while(patientAge[i]<0 || patientAge[i]>120);

        do
        {
            printf("\n------------------------------------------------------------\n");
            printf("                  SELECT EMERGENCY LEVEL\n");
            printf("------------------------------------------------------------\n");
            printf("   1. Normal\n");
            printf("   2. Urgent\n");
            printf("   3. Critical\n");
            printf("%-20s: ", "Emergency Level");
            scanf("%d",&patientEmergencyLevel[i]);
            if(patientEmergencyLevel[i]<1 || patientEmergencyLevel[i]>3){
                printf("  >> Invalid input. Please enter 1, 2, or 3.\n");
            }
        }while(patientEmergencyLevel[i]<1 || patientEmergencyLevel[i]>3);

        do
        {
            printf("\n------------------------------------------------------------\n");
            printf("                    SELECT SPECIALTY\n");
            printf("------------------------------------------------------------\n");
            printf("   1. General Practice (OPD)\n");
            printf("   2. Paediatrics\n");
            printf("   3. Cardiology\n");
            printf("   4. Neurology\n");
            printf("%-20s: ", "Specialty ID");
            scanf("%d",&specialtyId[i]);
            if(specialtyId[i]<1 || specialtyId[i]>4){
                printf("  >> Invalid input. Please enter 1, 2, 3, or 4.\n");
            }
        }while(specialtyId[i]<1 || specialtyId[i]>4);

        do
        {
            printf("\n------------------------------------------------------------\n");
            printf("                   PATIENT ADMISSION\n");
            printf("------------------------------------------------------------\n");
            printf("   1. Admitted\n");
            printf("   0. Not Admitted\n");
            printf("%-20s: ", "Admitted (0/1)");
            scanf("%d",&isAdmitted[i]);
            if(isAdmitted[i]<0 || isAdmitted[i]>1){
                printf("  >> Invalid input. Please enter 0 or 1.\n");
            }
        }while(isAdmitted[i]<0 || isAdmitted[i]>1);

        int bedNum = 0;
        if(isAdmitted[i]==1){
            do
            {
                printf("\n------------------------------------------------------------\n");
                printf("                     SELECT WARD ID\n");
                printf("------------------------------------------------------------\n");
                printf("   1. General Ward\n");
                printf("   2. Paediatric Ward\n");
                printf("   3. Surgical Ward\n");
                printf("   4. ICU (Intensive Care Unit)\n");
                printf("%-20s: ", "Ward ID");
                scanf("%d",&wardId[i]);
                if(wardId[i]<1 || wardId[i]>4){
                    printf("  >> Invalid input. Please enter 1, 2, 3, or 4.\n");
                }
            }while(wardId[i]<1 || wardId[i]>4);

            do{
                printf("%-20s: ", "Days Admitted");
                scanf("%d",&daysAdmitted[i]);
                if(daysAdmitted[i]<=0){
                    printf("  >> Invalid. Days must be greater than 0.\n");
                }
            }while(daysAdmitted[i]<=0);

            bedNum = allocateBed(wardId[i],bedOccupancy,wardTotalBedCapacity);
            if(bedNum == -1){
                printf("\n  >> Sorry, %s is FULL. No beds available.\n", wardName[wardId[i]-1]);
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

    }
