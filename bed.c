#include <stdio.h>
#include "hospital.h"

int allocateBed(int wardId, int bedOccupancy[][MAX_BED_PER_WARD], int wardCapacity[])
{
    int bedNum;
    for(bedNum = 0; bedNum < wardCapacity[wardId-1]; bedNum++){
        if(bedOccupancy[wardId-1][bedNum] == 0){
            bedOccupancy[wardId-1][bedNum] = 1;
            return bedNum + 1;
        }
    }
    return -1;
}

void checkBedStatus(int bedOccupancy[][MAX_BED_PER_WARD], int wardCapacity[])
{
    int ward, bed, occupiedCount;

    printf("\n============================================================\n");
    printf("                   BED OCCUPANCY STATUS\n");
    printf("============================================================\n");

    for(ward = 0; ward < NUM_WARD; ward++){
        occupiedCount = 0;
        for(bed = 0; bed < wardCapacity[ward]; bed++){
            if(bedOccupancy[ward][bed] == 1){
                occupiedCount++;
            }
        }
        printf("\n%s\n", wardName[ward]);
        printf("------------------------------------------------------------\n");
        printf("%-20s: %d\n", "Total Beds", wardCapacity[ward]);
        printf("%-20s: %d\n", "Occupied", occupiedCount);
        printf("%-20s: %d\n", "Available", wardCapacity[ward] - occupiedCount);
    }
        printf("\n============================================================\n");

        while(getchar() != '\n');
        printf("\nPress Enter to return to the menu...");
        getchar();
}
