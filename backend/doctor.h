#ifndef DOCTOR_H
#define DOCTOR_H

#define NAME_LENGTH 50
#define SPECIALIZATION_LENGTH 50
#define PHONE_LENGTH 15

typedef struct
{
    int doctorID;
    char name[NAME_LENGTH];
    char specialization[SPECIALIZATION_LENGTH];
    char phone[PHONE_LENGTH];
    int experience;

} Doctor;

/* Doctor Management */

void addDoctor();
void displayDoctors();
void searchDoctor();
void updateDoctor();
void deleteDoctor();

#endif
