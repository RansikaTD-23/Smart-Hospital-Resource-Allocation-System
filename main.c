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
    int choice;

    //
    char patientName[MAX_PATIENTS][NAME_LENGTH];
    int patientAge[MAX_PATIENTS];
    int patientEmergencyLevel[MAX_PATIENTS];
    int specialtyId[MAX_PATIENTS];
    int isAdmitted[MAX_PATIENTS];
    int wardId[MAX_PATIENTS];
    int daysAdmitted[MAX_PATIENTS];

    do{

    //main menu
    printf("\n===========================================================\n");
    printf("        Smart Hospital & Resource Allocation System        \n");
    printf("===========================================================\n");
    printf("%30s\n","1.Register Patient");
    printf("%30s\n","2.Check Bed Status");
    printf("%41s\n","3.Generate Performance Report");
    printf("%18s\n\n","4.Exit");

    printf("Please Select the Choice: ");
    scanf("%d",&choice);

        switch(choice){
            case 1:
                   registerPatients(patientName,patientAge,patientEmergencyLevel,specialtyId,isAdmitted,wardId,
                                    daysAdmitted,&patientCount);//patient registration
                   break;
            case 2:
                   break;
            case 3:
                   break;
            case 4:
                   printf("Thank you....");
                   break;
            default:
                   printf("Invalid...Please Try Again...");
        }
    }while(choice != 4);
    return 0;
}

void registerPatients(char patientName[][NAME_LENGTH],
                      int patientAge[],
                      int patientEmergencyLevel[],
                      int specialtyId[],
                      int isAdmitted[],
                      int wardId[],
                      int daysAdmitted[],
                      int *count)
    {
        int i = *count;

        printf("\n-----------Patient Registration---------------");
        printf("\nPatient Name: ");
        scanf(" %[^\n]",patientName[i]);

        do{printf("\nAge of Patient: ");
        scanf("%d",&patientAge[i]);
        if(patientAge[i]<0 || patientAge[i]>120){
            printf("\nInvalid Age...Please Enter Realistic Age\n");
            }
        }while(patientAge[i]<0 || patientAge[i]>120);

        do
        {
            printf("\n-----------Select the Emergency Level-----------");
            printf("\n            1.Normal");
            printf("\n            2.Urgent");
            printf("\n            3.Critical");
            printf("\nEmergency Level: ");
            scanf("%d",&patientEmergencyLevel[i]);
            if(patientEmergencyLevel[i]<1 || patientEmergencyLevel[i]>3){
                printf("\nInvalid Input...Please Enter 1,2 or 3!!!!\n");
            }

        }while(patientEmergencyLevel[i]<1 || patientEmergencyLevel[i]>3);

        do
        {
            printf("\n-----------Select the Speciality-------------");
            printf("\n             1.General Practice(OPD)");
            printf("\n             2.Paeditrics");
            printf("\n             3.Cardiology");
            printf("\n             4.Neurology");
            printf("\nSpeciality Id: ");
            scanf("%d",&specialtyId[i]);
            if(specialtyId[i]<1 || specialtyId[i]>4){
                printf("\nInvalid Input...Please Enter 1,2,3 or 4!!!!\n");
            }
        }while(specialtyId[i]<1 || specialtyId[i]>4);

        do
        {
            printf("\n-------------Patient Admission------------------");
            printf("\n               Admitted     - 1");
            printf("\n               Not Admitted - 0");
            printf("\nPatient Admitted or not?: ");
            scanf("%d",&isAdmitted[i]);
            if(isAdmitted[i]<0 || isAdmitted[i]>1){
                printf("\nInvalid Input...Please Enter 0 or 1!!!!\n");
            }
        }while(isAdmitted[i]<0 || isAdmitted[i]>1);


        if(isAdmitted[i]==1){
            do
            {
                printf("\n-----------Select Ward ID-----------");
                printf("\n            1.General Ward");
                printf("\n            2.Paeditrics Ward");
                printf("\n            3.Surgical Ward");
                printf("\n            4.ICU(Intensive Care Unit)");
                printf("\nWard Id:");
                scanf("%d",&wardId[i]);
                if(wardId[i]<1 || wardId[i]>4){
                    printf("\nInvalid Input...Please Enter 1,2,3 or 4!!!!\n");
                }

            }while(wardId[i]<1 || wardId[i]>4);


            do{
                printf("\nPlease Days of Admitted :");
                scanf("%d",&daysAdmitted[i]);
                if(daysAdmitted[i]<=0){
                printf("Invalid...Days must be greater than 0\n ");
                }
            }while(daysAdmitted[i]<=0);

        }else{
            wardId[i]=0;
            daysAdmitted[i]=0;
        }

        printf("\nPatient Registration is Succesfully! \n");
        printf("Patient Id: PAT - %d\n",1000+(i+1));
        (*count)++;



    }


