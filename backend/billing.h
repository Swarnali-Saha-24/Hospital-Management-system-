#ifndef BILLING_H
#define BILLING_H

typedef struct
{
    int billID;
    int patientID;
    float doctorFee;
    float medicineFee;
    float testFee;
    float total;

} Bill;

void createBill();
void displayBills();
void searchBill();

#endif
