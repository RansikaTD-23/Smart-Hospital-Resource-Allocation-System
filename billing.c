#include <stdio.h>
#include "hospital.h"

float calculateWaitingTime(int specialityId,int queueCount[],int specialityTime[])
{
    float waitingTime = queueCount[specialityId - 1] * specialityTime[specialityId -1];
    return waitingTime ;
}

float calculateEmergencySurcharge(int urgencyLevel,float baseFee)
{
    if(urgencyLevel == 1){
        return 0;
    }
    else if (urgencyLevel == 2){
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
               float grossTotal, float discount, float finalAmount, float waitingTime,int bedNum)
{
    printf("\n============================================================\n");
    printf("              SMART HOSPITAL ADMISSION & BILL\n");
    printf("============================================================\n");
    printf("%-28s: PAT-%d\n", "Patient ID", patientId);
    printf("%-28s: %s\n", "Patient Name", patientName);

    if(age < AGE_YOUNG || age > AGE_ADULT){
        printf("%-28s: %d Years (15%% Subsidy Eligible)\n", "Age", age);
    }
    else {
        printf("%-28s: %d Years\n", "Age", age);
    }

    printf("%-28s: %s\n", "Specialty", specialtyNames[specialtyId-1]);

    if(isAdmitted == 1){
        printf("%-28s: %s (Bed #%02d)\n", "Assigned Ward", wardName[wardId-1], bedNum);
    }
    else {
        printf("%-28s: Not Admitted (OPD)\n", "Assigned Ward");
    }

    if(urgencyLevel == 1){
        printf("%-28s: Level 1 (Normal)\n", "Urgency Level");
    }
    else if(urgencyLevel == 2){
        printf("%-28s: Level 2 (Urgent)\n", "Urgency Level");
    }
    else{
        printf("%-28s: Level 3 (Critical)\n", "Urgency Level");
    }

    printf("------------------------------------------------------------\n");
    printf("%-28s: LKR %.2f\n", "Base Consultation Fee", baseFee);

    if(urgencyLevel == 1){
        printf("%-28s: LKR %.2f\n", "Emergency Surcharge", surcharge);
    }
    else if(urgencyLevel == 2){
        printf("%-28s: LKR %.2f (20%%)\n", "Emergency Surcharge", surcharge);
    }
    else{
        printf("%-28s: LKR %.2f (50%%)\n", "Emergency Surcharge", surcharge);
    }

    if(isAdmitted == 1){
        char wardLabel[30];
        sprintf(wardLabel, "Ward Stay Cost (%d Days)", daysAdmitted);
        printf("%-28s: LKR %.2f\n", wardLabel, wardCost);
    }

    printf("------------------------------------------------------------\n");
    printf("%-28s: LKR %.2f\n", "Gross Total Bill", grossTotal);

    if(discount > 0){
        printf("%-28s: LKR -%.2f (15%%)\n", "Age Subsidy Discount", discount);
    }
    else{
        printf("%-28s: LKR -%.2f\n", "Age Subsidy Discount", discount);
    }

    printf("------------------------------------------------------------\n");
    printf("%-28s: LKR %.2f\n", "Final Payable Amount", finalAmount);

    if(waitingTime == 0){
        printf("%-28s: 0.00 mins (Immediate Attention)\n", "Estimated Waiting Time");
    }
    else {
        printf("%-28s: %.2f mins\n", "Estimated Waiting Time", waitingTime);
    }

    printf("============================================================\n");
}
