#include "medicineOperation.h"
int ch5;
void Medicine()
{

    printf("\t\n======== Medicine Menu ========\n");
    printf("\t\n1.Update Stock"
           "\t\n2.Medicine Entry"
           "\t\n3.Medicine Sale"
           "\t\n4.medicine Search"
           "\t\n5.Stock");
    printf("\t\nenter choice :");
    scanf("%d", &ch5);

    switch (ch5)
    {
    case 1:
        update_stock();
        break;
    case 2:
        medi_entry();
        break;

    case 3:
        medi_sale();
        break;
    case 4:
        medi_search();
        break;
    case 5:
        stock();
        break;

    default:
        break;
    }
}