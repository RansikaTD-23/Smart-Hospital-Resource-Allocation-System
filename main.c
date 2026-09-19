#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "hospital.h"

    //Doctor Specialty Data
    char specialtyNames[NUM_SPECIALITY][NAME_LENGTH]={"General Practice(OPD)","Paediatrics","Cardiology","Neurology"};
    float specialtyConslationFee[NUM_SPECIALITY]={1500.00,2500.00,4500.00,5000.00};
    int specialtyConslationTime[NUM_SPECIALITY]={15,20,30,30};
    int specialtyPatientsCapacity[NUM_SPECIALITY]={30,20,12,10};

    //Hospital Ward Data
    char wardName[NUM_WARD][NAME_LENGTH]={"General Ward","Paediatric Ward","Surgical Ward","ICU"};
    float wardDailyBedRate[NUM_WARD]={3000.00,6000.00,12000.00,25000.00};
    int wardTotalBedCapacity[NUM_WARD]={20,10,10,05};

    //Bed Status
    int bedOccupancy[NUM_WARD][MAX_BED_PER_WARD]={0};

    //Patient Tracking
    int patientCount = 0;

    //Waiting Time
    int specialtyQueueCount[NUM_SPECIALITY] = {0};

    //Performance Report
    float patientFinalBill[MAX_PATIENTS];
    float patientDiscount[MAX_PATIENTS];

int main()
{
    int choice;

    //
    char patientName[MAX_PATIENTS][NAME_LENGTH];
    int patientAge[MAX_PATIENTS];
    int patientEmergencyLevel[MAX_PATIENTS];
    int specialtyId[MAX_PATIENTS];
    int isAdmitted[MAX_PATIENTS];
    int wardId[MAX_PATIENTS];
    int daysAdmitted[MAX_PATIENTS];

    //File Handling
    loadBedStatus(bedOccupancy, wardTotalBedCapacity);

    do{

    //main menu
    printf("\n============================================================\n");
    printf("          SMART HOSPITAL & RESOURCE ALLOCATION SYSTEM\n");
    printf("============================================================\n");
    printf("   1. Register Patient\n");
    printf("   2. Check Bed Status\n");
    printf("   3. View Patients by Priority\n");
    printf("   4. Generate Performance Report\n");
    printf("   5. Exit\n");
    printf("============================================================\n");
    printf("Please Enter Your Choice: ");
    scanf("%d",&choice);

        switch(choice){
            case 1:
                   registerPatients(patientName,patientAge,patientEmergencyLevel,specialtyId,isAdmitted,wardId,
                                    daysAdmitted,specialtyQueueCount,patientFinalBill,patientDiscount,&patientCount);//patient registration
                   break;
            case 2:
                   checkBedStatus(bedOccupancy, wardTotalBedCapacity);//checking bed status
                   break;
            case 3:
                   sortAndDisplayByPriority(patientName, patientEmergencyLevel, patientCount);//sorting by priority
                   break;
            case 4:
                   generateSummaryReport(patientEmergencyLevel, patientFinalBill, patientDiscount,
                          patientName, patientCount, bedOccupancy, wardTotalBedCapacity);//Performance Report
                   break;
            case 5:
                   saveBedStatus(bedOccupancy, wardTotalBedCapacity);//save files
                   printf("\nThank you for using Smart Hospital System....\n");//exit
                   break;
            default:
                   printf("\n  >> Invalid choice. Please try again.\n");
        }
    }while(choice != 5);

    return 0;
}
