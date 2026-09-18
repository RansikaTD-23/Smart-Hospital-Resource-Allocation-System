#include <stdio.h>
#include "hospital.h"

void saveBedStatus(int bedOccupancy[][MAX_BED_PER_WARD], int wardCapacity[])
{
    FILE *fp = fopen("beds_status.txt", "w");
    if(fp == NULL){
        printf("Error: Could not save bed status.\n");
        return;
    }

    int w, b;
    for(w = 0; w < NUM_WARD; w++){
        for(b = 0; b < wardCapacity[w]; b++){
            fprintf(fp, "%d ", bedOccupancy[w][b]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void loadBedStatus(int bedOccupancy[][MAX_BED_PER_WARD], int wardCapacity[])
{
    FILE *fp = fopen("beds_status.txt", "r");
    if(fp == NULL){
        return;
    }

    int w, b;
    for(w = 0; w < NUM_WARD; w++){
        for(b = 0; b < wardCapacity[w]; b++){
            fscanf(fp, "%d", &bedOccupancy[w][b]);
        }
    }

    fclose(fp);
}

void appendPatientRecord(int patientId, char name[], float finalAmount)
{
    FILE *fp = fopen("patient_records.txt", "a");
    if(fp == NULL){
        printf("Error: Could not save patient record.\n");
        return;
    }

    fprintf(fp, "PAT-%d | %s | LKR %.2f\n", patientId, name, finalAmount);

    fclose(fp);
}
