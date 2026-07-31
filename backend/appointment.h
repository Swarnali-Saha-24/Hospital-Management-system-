#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#define DATE_LENGTH 15
#define TIME_LENGTH 10

typedef struct
{
    int appointmentID;
    int patientID;
    int doctorID;
    char date[DATE_LENGTH];
    char time[TIME_LENGTH];

} Appointment;

void addAppointment();
void displayAppointments();
void searchAppointment();
void deleteAppointment();

#endif
