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
    char wardName[NUM_WARD][NAME_LENGTH]={"General Ward","Paediatric Ward","Surgical Ward","ICU(Intensive Care Unit)"};
    float wardDailyBedRate[NUM_WARD]={3000.00,6000.00,12000.00,25000.00};
    int wardTotalBedCapacity[NUM_WARD]={20,10,10,05};

    //Bed Status
    int bedOccupancy[NUM_WARD][MAX_BED_PER_WARD]={0};

    //Patient Tracking
    int patientCount = 0;

int main()
{
    //Main Menu
    int choice;
    do{
        printf("===========================================================\n");
        printf("        Smart Hospital & Resource Allocation System        \n");
        printf("===========================================================\n");
        printf("%30s\n","1.Register Patient");
        printf("%30s\n","2.Check Bed Status");
        printf("%41s\n","3.Generate Performance Report");
        printf("%18s\n\n","4.Exit");

        printf("Please Select the Choice: ");
        scanf("%d",&choice);
    }
    while(choice != 4);

    return 0;
}
