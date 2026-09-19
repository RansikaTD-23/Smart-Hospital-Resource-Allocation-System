#include <stdio.h>
#include "hospital.h"

void sortAndDisplayByPriority(char patientName[][NAME_LENGTH],int patientEmergencyLevel[],int count)
{
    int sortedIndex[MAX_PATIENTS];
    int i,j,k,maxId;

    for(i=0;i < count;i++)
    {
        sortedIndex[i] = i;
    }

    for (j = 0; j< count-1;j++)
    {
        maxId = j;
        for(i = j+1;i<count;i++){
            if(patientEmergencyLevel[sortedIndex[i]]>patientEmergencyLevel[sortedIndex[maxId]]){
                maxId = i;
            }
        }
        k = sortedIndex[j];
        sortedIndex[j]=sortedIndex[maxId];
        sortedIndex[maxId] = k ;
    }

    printf("\n============================================================\n");
    printf("                 PATIENTS BY PRIORITY\n");
    printf("============================================================\n");
    printf("%-10s| %-20s| %s\n", "Patient ID", "Name", "Urgency Level");
    printf("------------------------------------------------------------\n");
    for(j=0;j<count;j++){
        int index = sortedIndex[j];
        char patId[10];
        sprintf(patId, "PAT-%d", 1000+index+1);
        printf("%-10s| %-20s| Level %d\n", patId, patientName[index], patientEmergencyLevel[index]);
    }
    printf("============================================================\n");

    while(getchar() != '\n');
    printf("\nPress Enter to return to the menu...");
    getchar();
}

void generateSummaryReport(int patientEmergencyLevel[], float patientFinalBill[], float patientDiscount[],
                            char patientName[][NAME_LENGTH], int count,
                            int bedOccupancy[][MAX_BED_PER_WARD], int wardCapacity[])
{
    int k, w, b;

    printf("\n============================================================\n");
    printf("               HOSPITAL PERFORMANCE REPORT\n");
    printf("============================================================\n");

    // Urgency Level Count
    int normalCount=0, urgentCount=0, criticalCount=0;
    for(k=0; k<count; k++){
        if(patientEmergencyLevel[k]==1) normalCount++;
        else if(patientEmergencyLevel[k]==2) urgentCount++;
        else criticalCount++;
    }
    printf("\n%-28s: %d\n", "Total Patients Registered", count);
    printf("%-28s: %d\n", "  Normal", normalCount);
    printf("%-28s: %d\n", "  Urgent", urgentCount);
    printf("%-28s: %d\n", "  Critical", criticalCount);

    //Total Revenue & Discount
    float totalRevenue=0, totalDiscount=0;
    for(k=0; k<count; k++){
        totalRevenue += patientFinalBill[k];
        totalDiscount += patientDiscount[k];
    }
    printf("\n%-28s: LKR %.2f\n", "Total Revenue Earned", totalRevenue);
    printf("%-28s: LKR %.2f\n", "Total Discounts Granted", totalDiscount);

    //Bed Occupancy Per Ward
    printf("\n------------------------------------------------------------\n");
    printf("Bed Occupancy Percentage:\n");
    printf("------------------------------------------------------------\n");
    for(w=0; w<NUM_WARD; w++){
        int occupied=0;
        for(b=0; b<wardCapacity[w]; b++){
            if(bedOccupancy[w][b]==1) occupied++;
        }
        float percent = (occupied * 100.0) / wardCapacity[w];
        printf("%-28s: %.2f%%\n", wardName[w], percent);
    }

    //Highest Paying Patient
    if(count > 0){
        int highestIdx=0;
        for(k=1; k<count; k++){
            if(patientFinalBill[k] > patientFinalBill[highestIdx]){
                highestIdx = k;
            }
        }
        printf("\n%-28s: %s - LKR %.2f\n", "Highest Paying Patient", patientName[highestIdx], patientFinalBill[highestIdx]);
    }

        printf("\n============================================================\n");

        while(getchar() != '\n');
        printf("\nPress Enter to return to the menu...");
        getchar();
}
