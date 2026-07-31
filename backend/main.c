#include <stdio.h>
#include "login.h"
#include "patient.h"
#include "doctor.h"
#include "appointment.h"
#include "billing.h"
#include "file.h"

void patientMenu();
void doctorMenu();
void appointmentMenu();
void billingMenu();

int main()
{
    int choice;

    initializeDatabase();

    if(!login())
    {
        printf("\nAccess Denied!\n");
        return 0;
    }

    while(1)
    {
        printf("\n==============================\n");
        printf(" HOSPITAL MANAGEMENT SYSTEM\n");
        printf("==============================\n");
        printf("1. Patient Management\n");
        printf("2. Doctor Management\n");
        printf("3. Appointment Management\n");
        printf("4. Billing Management\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: patientMenu(); break;
            case 2: doctorMenu(); break;
            case 3: appointmentMenu(); break;
            case 4: billingMenu(); break;
            case 5: printf("Thank you!\n"); return 0;
            default: printf("Invalid choice.\n");
        }
    }
}

void patientMenu()
{
    int ch;
    do{
        printf("\n--- Patient Management ---\n");
        printf("1.Add Patient\n2.View Patients\n3.Search Patient\n4.Update Patient\n5.Delete Patient\n6.Back\n");
        printf("Choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:addPatient();break;
            case 2:displayPatients();break;
            case 3:searchPatient();break;
            case 4:updatePatient();break;
            case 5:deletePatient();break;
        }
    }while(ch!=6);
}

void doctorMenu()
{
    int ch;
    do{
        printf("\n--- Doctor Management ---\n");
        printf("1.Add Doctor\n2.View Doctors\n3.Search Doctor\n4.Update Doctor\n5.Delete Doctor\n6.Back\n");
        printf("Choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:addDoctor();break;
            case 2:displayDoctors();break;
            case 3:searchDoctor();break;
            case 4:updateDoctor();break;
            case 5:deleteDoctor();break;
        }
    }while(ch!=6);
}

void appointmentMenu()
{
    int ch;
    do{
        printf("\n--- Appointment Management ---\n");
        printf("1.Book Appointment\n2.View Appointments\n3.Search Appointment\n4.Cancel Appointment\n5.Back\n");
        printf("Choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:addAppointment();break;
            case 2:displayAppointments();break;
            case 3:searchAppointment();break;
            case 4:deleteAppointment();break;
        }
    }while(ch!=5);
}

void billingMenu()
{
    int ch;
    do{
        printf("\n--- Billing Management ---\n");
        printf("1.Create Bill\n2.View Bills\n3.Search Bill\n4.Back\n");
        printf("Choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:createBill();break;
            case 2:displayBills();break;
            case 3:searchBill();break;
        }
    }while(ch!=4);
}