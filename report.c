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
