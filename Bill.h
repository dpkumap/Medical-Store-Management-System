#include "medicineOperation.h"

struct Bill b1;

FILE *rFptr7;

void bills()
{
    int d, m, y;
    rFptr7 = fopen("bill.txt", "r");
    printf("\t\n======== Bill Menu ========\n");
    printf("\t\n=================Bill Details ======================\n");
    while (fscanf(rFptr7, "%d %s %s %d %d %f %d %d %d", &b1.billno, b1.cname, b1.mediname, &b1.medi_qty, &b1.medi_rate, &b1.total, &b1.day, &b1.month, &b1.year) != EOF)
    {

        printf("\nBill No : %d", b1.billno);
        printf("\nCustomer Name : %s", b1.cname);
        printf("\nMedicine Name : %s", b1.mediname);
        printf("\nQuantity : %d", b1.medi_qty);
        printf("\nRate : %d", b1.medi_rate);
        printf("\nToTal : %.2f", b1.total);
        d = b1.day;
        m = b1.month;
        y = b1.year;
        printf("\nDate : %d-%d-%d", d, m, y);
        printf("\n=======================================\n");
    }
    fclose(rFptr7);
}