#ifndef medicineOperation_H
#define medicineOperation_H
#include <stdio.h>
#include <time.h>
#include <string.h>

struct Medicine
{
    int id;
    char med_name[90];
    char com_name[90];
    int rack;
    int cabnit;
    int quantity;
    // int sales;
    float total;
    int units;
    float cost;
    int profit;
    int buy;
    int sale;
    char supp_name[90];
    char mfgdate[12];
    char expdate[12];
};

struct Bill
{
    int billno;
    char cname[90];
    char mediname[90];
    int medi_qty;
    int medi_rate;
    float total;
    int day;
    int month;
    int year;
};

//

struct Medicine med;
struct Bill b;

FILE *wFptr;
FILE *rFptr;
FILE *rFptr5;

void update_stock()
{

    // FILE *temp1 = fopen("tempFile.txt", "w");
    rFptr5 = fopen("medicineDetails.txt", "r");

    int sampleId, sampleQty, op;
    int flag = 0;

    printf("\nEnter medicine id to be update: ");
    scanf("%d", &sampleId);
    FILE *temp1 = fopen("tempFile.txt", "w");
    while (fscanf(rFptr5, "%d %s %d %d %s %s %d %d %d %s %s", &med.id, med.med_name, &med.rack, &med.cabnit, med.com_name, med.supp_name, &med.units, &med.sale, &med.quantity, med.mfgdate, med.expdate) != EOF)
    {

        if (sampleId == med.id)
        {
            // FILE *temp1 = fopen("tempFile.txt", "w");
            printf("\n===============Medicine Id=%d========================\n", med.id);
            printf("\nMedicine Name : %s", med.med_name);
            printf("\nQuantity in stock : %d", med.quantity);
            printf("\n company Name : %s", med.com_name);
            printf("\n Supplier Name : %s", med.supp_name);
            printf("\n MFG.Date :%s", med.mfgdate);
            printf("\n EXP.Date :%s", med.expdate);
            printf("\nUnit Cost : %d", med.units);
            printf("\nsale Cost : %d", med.sale);

            printf("\n==================What Do You Want To Update=======================\n");

            printf("\n1.Medicine Name\n2.Quantity in stock\n3.company Name\n4.Supplier Name\n5.MFG.Date \n6.EXP.Date\n7.unit Cost\n8.Sale cost ");
            printf("\nEnter your choice :");
            scanf("%d", &op);

            switch (op)
            {
            case 1:
                printf("\nenter new Medicine Name : ");
                scanf("%s", &med.med_name);

                break;
            case 2:
                printf("\nenter new quantitiy :");
                scanf("%d", &med.quantity);
                break;
            case 3:
                printf("\nenter new company name :");
                scanf("%s", &med.com_name);
                break;
            case 4:
                printf("\nenter new supplier name :");
                scanf("%s", &med.supp_name);
                break;
            case 5:
                printf("\nenter new MFG Date :");
                scanf("%s", &med.mfgdate);
                break;
            case 6:
                printf("\nenter new EXP Date :");
                scanf("%s", &med.expdate);
                break;
            case 7:
                printf("\nenter new unit Cost :");
                scanf("%d", &med.units);
                break;
            case 8:
                printf("\nenter new Sale Cost :");
                scanf("%d", &med.sale);
                break;

            default:
                printf("\ninvalid choice");
                break;
            }
            flag = 1;
            fprintf(temp1, "%d %s %d %d %s %s %d %d %d %s %s\n", med.id, med.med_name, med.rack, med.cabnit, med.com_name, med.supp_name, med.units, med.sale, med.quantity, med.mfgdate, med.expdate);
        }
        else
        {
            fprintf(temp1, "%d %s %d %d %s %s %d %d %d %s %s\n", med.id, med.med_name, med.rack, med.cabnit, med.com_name, med.supp_name, med.units, med.sale, med.quantity, med.mfgdate, med.expdate);
        }
    }
    fclose(rFptr5);
    fclose(temp1);

    remove("medicineDetails.txt");
    rename("tempFile.txt", "medicineDetails.txt");

    if (flag)
    {
        printf("\n=======================================\n");
        printf("\nStock Updated Successfully!");
    }
    else
    {
        printf("\nInvalid Medicine ID");
    }
}
void medi_entry()
{

    int sampleID, flag = 1;
    wFptr = fopen("medicineDetails.txt", "a");
    rFptr = fopen("medicineDetails.txt", "r");

    printf("enter medicine ID: ");
    scanf("%d", &sampleID);

    while (fscanf(rFptr, "%d %s %d %d %s %s %d %d %d %s %s", &med.id, med.med_name, &med.rack, &med.cabnit, med.com_name, med.supp_name, &med.units, &med.sale, &med.quantity, med.mfgdate, med.expdate) != EOF)
    {
        if (sampleID == med.id)
        {

            printf("\nId Already Exist!");
            flag = 0;
            fclose(rFptr);
            break;
        }
    }
    if (flag)
    {

        med.id = sampleID;

        printf("enter Medicine Name : ");
        scanf("%s", &med.med_name);

        printf("enter Medicine rack no :");
        scanf("%d", &med.rack);

        printf("enter Medicine cabinet");
        scanf("%d", &med.cabnit);

        printf("enter Company Name : ");
        scanf("%s", &med.com_name);

        printf("enter supplier Name : ");
        scanf("%s", &med.supp_name);

        printf("enter Medicine unit cost");
        scanf("%d", &med.units);

        printf("enter sale cost ");
        scanf("%d", &med.sale);

        printf("enter Medicine quantity");
        scanf("%d", &med.quantity);

        printf("\nenter MFG.Date(dd-mm-yyyy): ");
        scanf("%s", &med.mfgdate);

        printf("enter EXP.Date(dd-mm-yyyy): ");
        scanf("%s", &med.expdate);

        fprintf(wFptr, "%d %s %d %d %s %s %d %d %d %s %s\n", med.id, med.med_name, med.rack, med.cabnit, med.com_name, med.supp_name, med.units, med.sale, med.quantity, med.mfgdate, med.expdate);

        printf("\n medicine inserted successfully!");
        printf("\n==========================================\n");
    }

    fclose(wFptr);
    fclose(rFptr);
}

void medi_sale()
{
    rFptr = fopen("medicineDetails.txt", "r");
    wFptr = fopen("bill.txt", "a");

    FILE *RfilePtr = fopen("medicineDetails.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    int sampleMedId, sampleqty, d1, m, y, flag = 0, flag2 = 0;
    int t, qty;
    float bye, c;

    time_t tt = time(0); // get time now
    struct tm *now = localtime(&tt);
    d1 = now->tm_mday;
    m = now->tm_mon + 1;
    y = now->tm_year + 1900;

    printf("enter medicine Id to be sold :");
    scanf("%d", &sampleMedId);

    while (fscanf(rFptr, "%d %s %d %d %s %s %d %d %d %s %s", &med.id, med.med_name, &med.rack, &med.cabnit, med.com_name, med.supp_name, &med.units, &med.sale, &med.quantity, med.mfgdate, med.expdate) != EOF)
    {

        if (sampleMedId == med.id)
        {

            printf("\nMedicine Name : %s", med.med_name);
            printf("\nQuantity in stock : %d", med.quantity);
            printf("\nsales Price : %d", med.sale);

            printf("\nEnter Bill No :");
            scanf("%d", &b.billno);

            printf("\nEnter customer name :");
            scanf("%s", &b.cname);

            printf("\nEnter medicine quantity :");
            scanf("%d", &sampleqty);

            if (sampleqty > med.quantity)
            {
                printf("\nenter valid quentity!");
                flag2 = 1;
                fclose(temp);
                fclose(RfilePtr);
                break;
            }
            else
            {
                flag = 1;
                qty = med.quantity;
                qty = qty - sampleqty;

                t = (med.quantity * med.sale);
                c = (med.quantity * med.units);
                bye = (med.sale * sampleqty);

                strcpy(b.mediname, med.med_name);

                b.medi_qty = sampleqty;
                b.medi_rate = med.sale;
                b.total = med.sale * sampleqty;

                b.day = d1;
                b.month = m;
                b.year = y;

                fprintf(wFptr, "%d %s %s %d %d %.2f %d %d %d\n", b.billno, b.cname, b.mediname, b.medi_qty, b.medi_rate, b.total, b.day, b.month, b.year);

                fclose(rFptr);
                fclose(wFptr);
            }
        }
    }

    /// writing new data in customerDetails file(i.e quantity)
    while (fscanf(RfilePtr, "%d %s %d %d %s %s %d %d %d %s %s", &med.id, med.med_name, &med.rack, &med.cabnit, med.com_name, med.supp_name, &med.units, &med.sale, &med.quantity, med.mfgdate, med.expdate) != EOF)
    {

        if (sampleMedId == med.id)
        {

            med.quantity = qty;
            med.total = t;
            med.cost = c;
            med.buy = bye;

            fprintf(temp, "%d %s %d %d %s %s %d %d %d %s %s\n", med.id, med.med_name, med.rack, med.cabnit, med.com_name, med.supp_name, med.units, med.sale, med.quantity, med.mfgdate, med.expdate);
        }
        else
        {

            fprintf(temp, "%d %s %d %d %s %s %d %d %d %s %s\n", med.id, med.med_name, med.rack, med.cabnit, med.com_name, med.supp_name, med.units, med.sale, med.quantity, med.mfgdate, med.expdate);
        }
    }

    fclose(temp);
    fclose(RfilePtr);

    remove("medicineDetails.txt");
    rename("temp.txt", "medicineDetails.txt");

    if (flag)
    {

        printf("\n========Sold Success========\n");
        printf("\nPrice Paid by customer : %.2f", bye);

        printf("\nQuantity sold : %d", sampleqty);
    }
    else
    {
        if (flag2)
        {
            printf("\n========not Sold ========\n");
        }
        else
        {
            printf("\ninvalid id ");
        }
    }
}
void medi_search()

{
    rFptr = fopen("medicineDetails.txt", "r");

    int sampleId;
    int flag = 0;

    printf("\nEnter medicine id to be Search: ");
    scanf("%d", &sampleId);

    while (fscanf(rFptr, "%d %s %d %d %s %s %d %d %d %s %s", &med.id, med.med_name, &med.rack, &med.cabnit, med.com_name, med.supp_name, &med.units, &med.sale, &med.quantity, med.mfgdate, med.expdate) != EOF)
    {

        if (sampleId == med.id)
        {
            flag = 1;
            printf("\n=======================================\n");
            printf("\nMedicine Name : %s", med.med_name);
            printf("\nQuantity in stock : %d", med.quantity);
            printf("\ncompany Name : %s", med.com_name);
            printf("\ncompany Name : %s", med.supp_name);
            printf("\nUnit Price : %d", med.units);
            printf("\nSale Price : %d", med.sale);
            printf("\nMFG.Date :%s", med.mfgdate);
            printf("\nEXP.Date :%s", med.expdate);
            printf("\nCabinet No : %d", med.cabnit);
            printf("\nRack No : %d", med.rack);

            break;
        }
    }
    if (flag == 0)
    {

        printf("\ninvalid ID ");
    }
    fclose(rFptr);
}
void stock()
{

    rFptr = fopen("medicineDetails.txt", "r");
    if (rFptr == NULL)
    {

        printf("\nfile opening falied!");
    }
    else
    {
        printf("\n=================Available Stocks======================\n");
        while (fscanf(rFptr, "%d %s %d %d %s %s %d %d %d %s %s", &med.id, med.med_name, &med.rack, &med.cabnit, med.com_name, med.supp_name, &med.units, &med.sale, &med.quantity, med.mfgdate, med.expdate) != EOF)
        {

            printf("\nMedicine Id : %d", med.id);
            printf("\nMedicine Name : %s", med.med_name);
            printf("\nQuentity : %d", med.quantity);
            printf("\nSupplier Name : %s", med.supp_name);
            printf("\nEXP Date : %s", med.expdate);
            printf("\n=======================================\n");
        }
    }
    fclose(rFptr);
}
#endif