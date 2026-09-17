#ifndef HOSPITAL_H
#define HOSPITAL_H

//Lookup Data & Hospital Wards Data
#define MAX_PATIENTS 100     //assume: maximum patients the hospital can handle
#define NUM_SPECIALITY 4     //fixed: according to speciality table
#define NUM_WARD 4           //fixed: according to ward table
#define MAX_BED_PER_WARD 20  //fixed: according to largest ward capacity (general ward)
#define NAME_LENGTH 50          //assume: maximum length of name

//Emergency(Triage Level)
#define URGENCY_NORMAL 1   //triage level 1
#define URGENCY_URGENT 2   //triage level 2
#define URGRNCY_CRITICAL 3 //triage level 3

//Billing - Surcharge
#define SURCHARGE_URGENT 20   //20% base fee
#define SURCHARGE_CRITICAL 50  //50% base fee

//Billing - Age Subsidy
#define AGE_YOUNG 5 //age 5 below
#define AGE_ADULT 65 //age 65 up
#define SUBSIDY_PERCENT 15 //15% discount

//Doctor Specialty Data
extern char specialtyNames[NUM_SPECIALITY][NAME_LENGTH];
extern float specialtyConslationFee[NUM_SPECIALITY];
extern int specialtyConslationTime[NUM_SPECIALITY];
extern int specialtyPatientsCapacity[NUM_SPECIALITY];

//Register Patients & collect data
void registerPatients(
                        char patientName[][NAME_LENGTH],
                        int patientAge[],
                        int patientEmergencyLevel[],
                        int specialtyId[],
                        int isAdmitted[],
                        int wardId[],
                        int daysAdmitted[],
                        int *count);



#endif
