#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doctor.h"

static const char *DOCTOR_FILE = "doctors.dat";

void addDoctor() {
    FILE *fp = fopen(DOCTOR_FILE,"ab");
    Doctor d;
    if(!fp){ printf("Unable to open doctor database.\n"); return; }

    printf("\n--- Add Doctor ---\n");
    printf("Doctor ID: "); scanf("%d",&d.doctorID);
    printf("Name: "); scanf(" %49[^\n]",d.name);
    printf("Specialization: "); scanf(" %49[^\n]",d.specialization);
    printf("Phone: "); scanf(" %14s",d.phone);
    printf("Experience (years): "); scanf("%d",&d.experience);

    fwrite(&d,sizeof(Doctor),1,fp);
    fclose(fp);
    printf("Doctor added successfully.\n");
}

void displayDoctors() {
    FILE *fp=fopen(DOCTOR_FILE,"rb");
    Doctor d;
    if(!fp){ printf("No doctor records found.\n"); return; }

    printf("\n%-6s %-20s %-20s %-15s %-5s\n",
           "ID","Name","Specialization","Phone","Exp");

    while(fread(&d,sizeof(Doctor),1,fp)==1){
        printf("%-6d %-20s %-20s %-15s %-5d\n",
               d.doctorID,d.name,d.specialization,d.phone,d.experience);
    }
    fclose(fp);
}

void searchDoctor() {
    FILE *fp=fopen(DOCTOR_FILE,"rb");
    Doctor d; int id,found=0;
    if(!fp){ printf("No doctor records found.\n"); return; }

    printf("Enter Doctor ID: "); scanf("%d",&id);

    while(fread(&d,sizeof(Doctor),1,fp)==1){
        if(d.doctorID==id){
            found=1;
            printf("\nID:%d\nName:%s\nSpecialization:%s\nPhone:%s\nExperience:%d years\n",
                   d.doctorID,d.name,d.specialization,d.phone,d.experience);
            break;
        }
    }
    fclose(fp);
    if(!found) printf("Doctor not found.\n");
}

void updateDoctor() {
    FILE *fp=fopen(DOCTOR_FILE,"rb");
    FILE *tmp=fopen("tempdoctor.dat","wb");
    Doctor d; int id,found=0;
    if(!fp||!tmp){ printf("Database error.\n"); if(fp)fclose(fp); if(tmp)fclose(tmp); return; }

    printf("Enter Doctor ID to update: "); scanf("%d",&id);

    while(fread(&d,sizeof(Doctor),1,fp)==1){
        if(d.doctorID==id){
            found=1;
            printf("New Name: "); scanf(" %49[^\n]",d.name);
            printf("New Specialization: "); scanf(" %49[^\n]",d.specialization);
            printf("New Phone: "); scanf(" %14s",d.phone);
            printf("New Experience: "); scanf("%d",&d.experience);
        }
        fwrite(&d,sizeof(Doctor),1,tmp);
    }
    fclose(fp); fclose(tmp);
    remove(DOCTOR_FILE); rename("tempdoctor.dat",DOCTOR_FILE);
    printf(found?"Doctor updated successfully.\n":"Doctor ID not found.\n");
}

void deleteDoctor() {
    FILE *fp=fopen(DOCTOR_FILE,"rb");
    FILE *tmp=fopen("tempdoctor.dat","wb");
    Doctor d; int id,found=0;
    if(!fp||!tmp){ printf("Database error.\n"); if(fp)fclose(fp); if(tmp)fclose(tmp); return; }

    printf("Enter Doctor ID to delete: "); scanf("%d",&id);

    while(fread(&d,sizeof(Doctor),1,fp)==1){
        if(d.doctorID==id){ found=1; continue; }
        fwrite(&d,sizeof(Doctor),1,tmp);
    }
    fclose(fp); fclose(tmp);
    remove(DOCTOR_FILE); rename("tempdoctor.dat",DOCTOR_FILE);
    printf(found?"Doctor deleted successfully.\n":"Doctor ID not found.\n");
}