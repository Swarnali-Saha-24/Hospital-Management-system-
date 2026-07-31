#include <stdio.h>
#include <stdlib.h>
#include "appointment.h"

static const char *APPOINTMENT_FILE="appointments.dat";

void addAppointment(){
    FILE *fp=fopen(APPOINTMENT_FILE,"ab");
    Appointment a;
    if(!fp){printf("Unable to open appointment database.\n");return;}

    printf("\n--- Book Appointment ---\n");
    printf("Appointment ID: "); scanf("%d",&a.appointmentID);
    printf("Patient ID: "); scanf("%d",&a.patientID);
    printf("Doctor ID: "); scanf("%d",&a.doctorID);
    printf("Date (DD/MM/YYYY): "); scanf("%14s",a.date);
    printf("Time (HH:MM): "); scanf("%9s",a.time);

    fwrite(&a,sizeof(Appointment),1,fp);
    fclose(fp);
    printf("Appointment booked successfully.\n");
}

void displayAppointments(){
    FILE *fp=fopen(APPOINTMENT_FILE,"rb");
    Appointment a;
    if(!fp){printf("No appointment records found.\n");return;}

    printf("\n%-8s %-10s %-10s %-15s %-10s\n",
           "App.ID","Patient","Doctor","Date","Time");

    while(fread(&a,sizeof(Appointment),1,fp)==1){
        printf("%-8d %-10d %-10d %-15s %-10s\n",
               a.appointmentID,a.patientID,a.doctorID,a.date,a.time);
    }
    fclose(fp);
}

void searchAppointment(){
    FILE *fp=fopen(APPOINTMENT_FILE,"rb");
    Appointment a; int id,found=0;
    if(!fp){printf("No appointment records found.\n");return;}

    printf("Enter Appointment ID: ");
    scanf("%d",&id);

    while(fread(&a,sizeof(Appointment),1,fp)==1){
        if(a.appointmentID==id){
            found=1;
            printf("\nAppointment ID : %d\n",a.appointmentID);
            printf("Patient ID     : %d\n",a.patientID);
            printf("Doctor ID      : %d\n",a.doctorID);
            printf("Date           : %s\n",a.date);
            printf("Time           : %s\n",a.time);
            break;
        }
    }
    fclose(fp);
    if(!found) printf("Appointment not found.\n");
}

void deleteAppointment(){
    FILE *fp=fopen(APPOINTMENT_FILE,"rb");
    FILE *tmp=fopen("tempappointment.dat","wb");
    Appointment a; int id,found=0;
    if(!fp||!tmp){
        printf("Database error.\n");
        if(fp) fclose(fp);
        if(tmp) fclose(tmp);
        return;
    }

    printf("Enter Appointment ID to cancel: ");
    scanf("%d",&id);

    while(fread(&a,sizeof(Appointment),1,fp)==1){
        if(a.appointmentID==id){
            found=1;
            continue;
        }
        fwrite(&a,sizeof(Appointment),1,tmp);
    }

    fclose(fp);
    fclose(tmp);
    remove(APPOINTMENT_FILE);
    rename("tempappointment.dat",APPOINTMENT_FILE);

    printf(found?"Appointment cancelled successfully.\n":"Appointment ID not found.\n");
}