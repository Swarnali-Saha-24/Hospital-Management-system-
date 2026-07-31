#include <stdio.h>
#include "file.h"

void initializeDatabase()
{
    FILE *fp;

    fp = fopen("patients.dat","ab");
    if(fp) fclose(fp);

    fp = fopen("doctors.dat","ab");
    if(fp) fclose(fp);

    fp = fopen("appointments.dat","ab");
    if(fp) fclose(fp);

    fp = fopen("bills.dat","ab");
    if(fp) fclose(fp);

    fp = fopen("admin.txt","a");
    if(fp) fclose(fp);
}
