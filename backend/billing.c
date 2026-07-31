#include <stdio.h>
#include "billing.h"

static const char *BILL_FILE="bills.dat";

void createBill(){
    FILE *fp=fopen(BILL_FILE,"ab");
    Bill b;
    if(!fp){ printf("Unable to open billing database.\n"); return; }

    printf("\n--- Create Bill ---\n");
    printf("Bill ID: "); scanf("%d",&b.billID);
    printf("Patient ID: "); scanf("%d",&b.patientID);
    printf("Doctor Fee: "); scanf("%f",&b.doctorFee);
    printf("Medicine Fee: "); scanf("%f",&b.medicineFee);
    printf("Test Fee: "); scanf("%f",&b.testFee);

    b.total=b.doctorFee+b.medicineFee+b.testFee;

    fwrite(&b,sizeof(Bill),1,fp);
    fclose(fp);

    printf("Bill created successfully.\n");
    printf("Total Bill: %.2f\n",b.total);
}

void displayBills(){
    FILE *fp=fopen(BILL_FILE,"rb");
    Bill b;
    if(!fp){ printf("No billing records found.\n"); return; }

    printf("\n%-8s %-10s %-12s %-12s %-10s %-10s\n",
           "BillID","Patient","DoctorFee","Medicine","Test","Total");

    while(fread(&b,sizeof(Bill),1,fp)==1){
        printf("%-8d %-10d %-12.2f %-12.2f %-10.2f %-10.2f\n",
               b.billID,b.patientID,b.doctorFee,b.medicineFee,b.testFee,b.total);
    }
    fclose(fp);
}

void searchBill(){
    FILE *fp=fopen(BILL_FILE,"rb");
    Bill b;
    int id,found=0;

    if(!fp){ printf("No billing records found.\n"); return; }

    printf("Enter Bill ID: ");
    scanf("%d",&id);

    while(fread(&b,sizeof(Bill),1,fp)==1){
        if(b.billID==id){
            found=1;
            printf("\nBill ID      : %d\n",b.billID);
            printf("Patient ID   : %d\n",b.patientID);
            printf("Doctor Fee   : %.2f\n",b.doctorFee);
            printf("Medicine Fee : %.2f\n",b.medicineFee);
            printf("Test Fee     : %.2f\n",b.testFee);
            printf("Total        : %.2f\n",b.total);
            break;
        }
    }

    fclose(fp);

    if(!found)
        printf("Bill not found.\n");
}