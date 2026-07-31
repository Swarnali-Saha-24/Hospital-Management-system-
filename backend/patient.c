#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "patient.h"

static const char *PATIENT_FILE = "patients.dat";

void addPatient() {
    FILE *fp = fopen(PATIENT_FILE, "ab");
    Patient p;
    if (!fp) {
        printf("Unable to open patient database.\n");
        return;
    }

    printf("\n--- Add Patient ---\n");
    printf("Patient ID: ");
    scanf("%d", &p.patientID);

    printf("Name: ");
    scanf(" %49[^\n]", p.name);

    printf("Age: ");
    scanf("%d", &p.age);

    printf("Gender: ");
    scanf(" %9s", p.gender);

    printf("Disease: ");
    scanf(" %49[^\n]", p.disease);

    printf("Phone: ");
    scanf(" %14s", p.phone);

    printf("Address: ");
    scanf(" %99[^\n]", p.address);

    fwrite(&p, sizeof(Patient), 1, fp);
    fclose(fp);

    printf("Patient added successfully.\n");
}

void displayPatients() {
    FILE *fp = fopen(PATIENT_FILE, "rb");
    Patient p;

    if (!fp) {
        printf("No patient records found.\n");
        return;
    }

    printf("\n%-6s %-20s %-4s %-8s %-18s %-15s %-20s\n",
           "ID","Name","Age","Gender","Disease","Phone","Address");

    while (fread(&p, sizeof(Patient), 1, fp) == 1) {
        printf("%-6d %-20s %-4d %-8s %-18s %-15s %-20s\n",
               p.patientID, p.name, p.age, p.gender,
               p.disease, p.phone, p.address);
    }

    fclose(fp);
}

void searchPatient() {
    FILE *fp = fopen(PATIENT_FILE, "rb");
    Patient p;
    int id, found = 0;

    if (!fp) {
        printf("No patient records found.\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(Patient), 1, fp) == 1) {
        if (p.patientID == id) {
            found = 1;
            printf("\nID      : %d\n", p.patientID);
            printf("Name    : %s\n", p.name);
            printf("Age     : %d\n", p.age);
            printf("Gender  : %s\n", p.gender);
            printf("Disease : %s\n", p.disease);
            printf("Phone   : %s\n", p.phone);
            printf("Address : %s\n", p.address);
            break;
        }
    }

    if (!found)
        printf("Patient not found.\n");

    fclose(fp);
}

void updatePatient() {
    FILE *fp = fopen(PATIENT_FILE, "rb");
    FILE *tmp = fopen("temp.dat", "wb");
    Patient p;
    int id, found = 0;

    if (!fp || !tmp) {
        printf("Database error.\n");
        if (fp) fclose(fp);
        if (tmp) fclose(tmp);
        return;
    }

    printf("Enter Patient ID to update: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(Patient), 1, fp) == 1) {
        if (p.patientID == id) {
            found = 1;
            printf("New Name: ");
            scanf(" %49[^\n]", p.name);
            printf("New Age: ");
            scanf("%d", &p.age);
            printf("New Gender: ");
            scanf(" %9s", p.gender);
            printf("New Disease: ");
            scanf(" %49[^\n]", p.disease);
            printf("New Phone: ");
            scanf(" %14s", p.phone);
            printf("New Address: ");
            scanf(" %99[^\n]", p.address);
        }
        fwrite(&p, sizeof(Patient), 1, tmp);
    }

    fclose(fp);
    fclose(tmp);

    remove(PATIENT_FILE);
    rename("temp.dat", PATIENT_FILE);

    printf(found ? "Patient updated successfully.\n"
                 : "Patient ID not found.\n");
}

void deletePatient() {
    FILE *fp = fopen(PATIENT_FILE, "rb");
    FILE *tmp = fopen("temp.dat", "wb");
    Patient p;
    int id, found = 0;

    if (!fp || !tmp) {
        printf("Database error.\n");
        if (fp) fclose(fp);
        if (tmp) fclose(tmp);
        return;
    }

    printf("Enter Patient ID to delete: ");
    scanf("%d", &id);

    while (fread(&p, sizeof(Patient), 1, fp) == 1) {
        if (p.patientID == id) {
            found = 1;
            continue;
        }
        fwrite(&p, sizeof(Patient), 1, tmp);
    }

    fclose(fp);
    fclose(tmp);

    remove(PATIENT_FILE);
    rename("temp.dat", PATIENT_FILE);

    printf(found ? "Patient deleted successfully.\n"
                 : "Patient ID not found.\n");
}
int savePatient(Patient p)
{
    FILE *fp = fopen(PATIENT_FILE, "ab");

    if(fp == NULL)
        return 0;

    fwrite(&p, sizeof(Patient), 1, fp);

    fclose(fp);

    return 1;
}