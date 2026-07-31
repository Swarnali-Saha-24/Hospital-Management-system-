#ifndef PATIENT_H
#define PATIENT_H

#define NAME_LENGTH 50
#define GENDER_LENGTH 10
#define DISEASE_LENGTH 50
#define PHONE_LENGTH 15
#define ADDRESS_LENGTH 100

typedef struct
{
    int patientID;
    char name[NAME_LENGTH];
    int age;
    char gender[GENDER_LENGTH];
    char disease[DISEASE_LENGTH];
    char phone[PHONE_LENGTH];
    char address[ADDRESS_LENGTH];

} Patient;

/* Patient Management */

void addPatient();
void displayPatients();
void searchPatient();
void updatePatient();
void deletePatient();
int savePatient(Patient p);
#endif