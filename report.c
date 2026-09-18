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
    printf("\n===================PATIENTS BY PRIORITY======================\n");
    for(j=0;j<count;j++){
        int index = sortedIndex[j];
        printf("PAT-%d | %-20s | Urgency: Level %d\n",1000+index+1,patientName[index],patientEmergencyLevel[index]);
    }
    printf("===============================================================\n");
}

void generateSummaryReport(int patientEmergencyLevel[], float patientFinalBill[], float patientDiscount[],
                            char patientName[][NAME_LENGTH], int count,
                            int bedOccupancy[][MAX_BED_PER_WARD], int wardCapacity[])
{
    int k, w, b;

    printf("\n=========== HOSPITAL PERFORMANCE REPORT ===========\n");

    // a) Urgency Level Count
    int normalCount=0, urgentCount=0, criticalCount=0;
    for(k=0; k<count; k++){
        if(patientEmergencyLevel[k]==1) normalCount++;
        else if(patientEmergencyLevel[k]==2) urgentCount++;
        else criticalCount++;
    }
    printf("\nTotal Patients Registered: %d\n", count);
    printf("  Normal   : %d\n", normalCount);
    printf("  Urgent   : %d\n", urgentCount);
    printf("  Critical : %d\n", criticalCount);

    // b) Total Revenue & Discount
    float totalRevenue=0, totalDiscount=0;
    for(k=0; k<count; k++){
        totalRevenue += patientFinalBill[k];
        totalDiscount += patientDiscount[k];
    }
    printf("\nTotal Revenue Earned: LKR %.2f\n", totalRevenue);
    printf("Total Discounts Granted: LKR %.2f\n", totalDiscount);

    // c) Bed Occupancy Per Ward
    printf("\nBed Occupancy Percentage:\n");
    for(w=0; w<NUM_WARD; w++){
        int occupied=0;
        for(b=0; b<wardCapacity[w]; b++){
            if(bedOccupancy[w][b]==1) occupied++;
        }
        float percent = (occupied * 100.0) / wardCapacity[w];
        printf("  %s: %.2f%%\n", wardName[w], percent);
    }

    // d) Highest Paying Patient
    if(count > 0){
        int highestIdx=0;
        for(k=1; k<count; k++){
            if(patientFinalBill[k] > patientFinalBill[highestIdx]){
                highestIdx = k;
            }
        }
        printf("\nHighest Paying Patient: %s - LKR %.2f\n", patientName[highestIdx], patientFinalBill[highestIdx]);
    }

    printf("\n=====================================================\n");
}
