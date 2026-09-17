#include <stdio.h>
#include "hospital.h"

float calculateWaitingTime(int specialityId,int queueCount[],int specialityTime[])
{
    float waitingTime = queueCount[specialityId - 1] * specialityTime[specialityId -1];
    return waitingTime ;
}

float calculateEmergencySurcharge(int urgencyLevel,float baseFee)
{
    if(urgencyLevel == 0){
        return 0;
    }
    else if (urgencyLevel == 1){
        return baseFee * 0.20;
    }
    else{
        return baseFee * 0.50;
    }
}

float calculateTotalWardStayCost(int daysAdmitted,int wardId,float wardRate[])
{
    if (daysAdmitted == 0)
    {
        return 0;
    }
    else
    {
        return daysAdmitted * wardRate[wardId - 1];
    }
}

float calculateGrossTotalBill(float baseConsultanFee,float emegencySurcharge,float totalWardCost)
{
    float grossTotal = baseConsultanFee + emegencySurcharge + totalWardCost;
    return grossTotal;
}

float calculateSubsidyDiscount(int age, float grossTotal)
{
    float discount;
    if(age < AGE_YOUNG || age > AGE_ADULT){
        discount = grossTotal * (SUBSIDY_PERCENT / 100.0);
    }
    else{
        discount = 0;
    }
    return discount;
}

float calculateFinalAmountPayable(float grossTotal,float discount)
{
    float finalAmountPayable = grossTotal - discount;
    return finalAmountPayable;
}

void printBill(int patientId, char patientName[], int age, int specialtyId, int wardId, int isAdmitted,
               int urgencyLevel, int daysAdmitted, float baseFee, float surcharge, float wardCost,
               float grossTotal, float discount, float finalAmount, float waitingTime)
{
    printf("\n==================================================\n");
    printf("             SMART HOSPITAL ADMISSION & BILL        \n");
    printf("---------------------------------------------------\n");
    printf("Patient ID                 : PAT - %d\n", patientId);
    printf("Patient Name               : %s\n", patientName);

    if(age < AGE_YOUNG || age > AGE_ADULT){
        printf("Age                        : %d Years (15%% Subsidy Eligible)\n", age);
    }
    else {
        printf("Age                        : %d Years\n", age);
    }

    printf("Specialty                  : %s\n", specialtyNames[specialtyId-1]);

    if(isAdmitted == 1){
        printf("Assigned Ward              : %s (Bed #0%d)\n", wardName[wardId-1], patientId-1000);
    }
    else {
        printf("Assigned Ward              :Not Admitted (OPD)\n");
    }

    if(urgencyLevel == 1){
        printf("Urgency Level              : Level 1 (Normal)\n");
    }
    else if(urgencyLevel == 2){
        printf("Urgency Level              : Level 2 (Urgent)\n");
    }
    else{
        printf("Urgency Level              : Level 3 (Critical)\n");
    }

    printf("------------------------------------------------------\n");
    printf("Base Consultation Fee      : LKR %.2f\n", baseFee);
    if(urgencyLevel == 1){
    printf("Emergency Surcharge        : LKR %.2f\n", surcharge);
    }
    else if(urgencyLevel == 2){
    printf("Emergency Surcharge        : LKR %.2f (20%%)\n", surcharge);
    }
    else{
    printf("Emergency Surcharge        : LKR %.2f (50%%)\n", surcharge);
    }

    if(isAdmitted == 1){
        printf("Ward Stay Cost (%d Days)    : LKR %.2f\n", daysAdmitted, wardCost);
    }

    printf("-------------------------------------------------------\n");
    printf("Gross Total Bill           : LKR %.2f\n", grossTotal);
    if(discount > 0){
    printf("Age Subsidy Discount       : LKR -%.2f (15%%)\n", discount);
    }
    else{
    printf("Age Subsidy Discount       : LKR -%.2f\n", discount);
    }
    printf("-------------------------------------------------------\n");
    printf("Final Payable Amount       : LKR %.2f\n", finalAmount);

    if(waitingTime == 0){
        printf("Estimated Waiting Time     : 0.00 mins (Immediate Attention)\n");
    }
    else {
        printf("Estimated Waiting Time     : %.2f mins\n", waitingTime);
    }

    printf("====================================================\n");
}





