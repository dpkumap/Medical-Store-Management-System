
#include <stdio.h>
#include <conio.h>
#include "Stringcmp.h"
#include <string.h>

struct Customer
{
    int cust_id;
    char cust_name[90];
    char city[90];
    long long int mob_no;
    char email[90];
};

FILE *wFptr;
FILE *rFptr;
int select;
struct Customer cust;

char ch, ch2;

void cust_entry()
{

    wFptr = fopen("customerDetilas.txt", "a");
    rFptr = fopen("customerDetilas.txt", "r");

    int sampleID, flags = 1;

    printf("enter Customer Id :");
    scanf("%d", &sampleID);

    while (fscanf(rFptr, "%s %d %lld %s %s", cust.cust_name, &cust.cust_id, &cust.mob_no, cust.city, cust.email) != EOF)
    {

        if (sampleID == cust.cust_id)
        {

            flags = 0;
            printf("\nCustomer Id Already exist ");
            fclose(rFptr);
            fclose(wFptr);
            break;
        }
    }
    if (flags)
    {
        cust.cust_id = sampleID;
        printf("\nenter Customer Name : ");
        scanf("%s", &cust.cust_name);

        printf("\nenter Customer City : ");
        scanf("%s", &cust.city);

        printf("\nenter Customer Email : ");
        scanf("%s", &cust.email);

        printf("enter Customer Mobile No :");
        scanf("%lld", &cust.mob_no);

        fprintf(wFptr, "%s %d %lld %s %s", cust.cust_name, cust.cust_id, cust.mob_no, cust.city, cust.email);
        fputwc('\n', wFptr);

        printf("\n=======================================\n");
        printf("\nCustomer Added Successfully!");

        fclose(wFptr); // it is good practise
    }
}

void searchByCustID()
{
    rFptr = fopen("customerDetilas.txt", "r");
    int sampleId, flag = 0;

    if (rFptr == NULL)
    {

        printf("\n file opening failed !");
    }
    else
    {

        printf("enter Customer Id to be search : ");
        scanf("%d", &sampleId);

        // ch==-1 condition
        while (fscanf(rFptr, "%s %d %lld %s %s", &cust.cust_name, &cust.cust_id, &cust.mob_no, &cust.city, &cust.email) != EOF)
        {

            if (sampleId == cust.cust_id)
            {
                printf("\n=============== Customer Details Found ========================\n");
                printf("\nCustomer Id :%d", cust.cust_id);
                printf("\nCustomer Name :%s", cust.cust_name);
                printf("\nCustomer Mobile No :%lld", cust.mob_no);
                printf("\nCustomer City :%s", cust.city);
                printf("\nCustomer Email :%s", cust.email);
                flag = 1;
                break;
            }
        }

        if (flag == 0)
        {
            printf("\nCustomer Id Does Not Exist !");
        }
        fclose(rFptr);
    }
}

void searchByCustName()
{

    char str[90];
    int flags = 0, rs = 0;

    rFptr = fopen("customerDetilas.txt", "r");

    if (rFptr == NULL)
    {

        printf("\nfile opening failed !");
    }
    else
    {
        printf("enter string :");
        scanf("%s", &str);

        // while fetching data from file make sure that sequence data within file matches the fscanf() parameter

        while (fscanf(rFptr, "%s %d %lld %s %s", cust.cust_name, &cust.cust_id, &cust.mob_no, cust.city, cust.email) != EOF)
        {

            // printf("\nCustomer Name :%s", cust.cust_name);
            rs = strCmp(str, cust.cust_name);
            if (rs == 0)
            {
                printf("\n=============== Customer Details Found ========================\n");
                printf("\nCustomer Id :%d", cust.cust_id);
                printf("\nCustomer Name :%s", cust.cust_name);
                printf("\nCustomer Mobile No :%lld", cust.mob_no);
                printf("\nCustomer City :%s", cust.city);
                printf("\nCustomer Email :%s", cust.email);
                flags = 1;
                break;
            }
        }
        if (flags == 0)
        {

            printf("\ninvalid Customer Name ");
        }
        fclose(rFptr);
    }
}

void cust_list()
{

    rFptr = fopen("customerDetilas.txt", "r");

    if (rFptr == NULL)
    {

        printf("\nfile opening failed !");
    }
    else
    {
        // here no need to specify & operator to char or string cause internally work as pointer but
        // we have to specify the & operator to int,float N other data type value
        printf("\n=============== Customer Details =========================\n");
        while (fscanf(rFptr, "%s %d %lld %s %s", cust.cust_name, &cust.cust_id, &cust.mob_no, cust.city, cust.email) != EOF)
        {
            printf("\nCustomer Id :%d", cust.cust_id);
            printf("\nCustomer Name :%s", cust.cust_name);
            printf("\nCustomer Mobile No :%lld", cust.mob_no);
            printf("\nCustomer City :%s", cust.city);
            printf("\nCustomer Email :%s", cust.email);
            printf("\n");
        }

        fclose(rFptr);
    }
}

void cust_update()
{

    FILE *rrFptr = fopen("customerDetilas.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    int sampleCustId, flag = 0, option;
    long int recordPos = -1;

    if (rrFptr == NULL)
    {

        printf("file opening failed !");
    }
    else
    {

        printf("Enter customer ID to update Info :");
        scanf("%d", &sampleCustId);

        while (fscanf(rrFptr, "%s %d %lld %s %s", cust.cust_name, &cust.cust_id, &cust.mob_no, cust.city, cust.email) != EOF)
        {
            if (sampleCustId == cust.cust_id)
            {
                printf("\n=============== Customer Details Found ========================\n");
                printf("\nCustomer Id :%d", cust.cust_id);
                printf("\nCustomer Name :%s", cust.cust_name);
                printf("\nCustomer Mobile No :%lld", cust.mob_no);
                printf("\nCustomer City :%s", cust.city);
                printf("\nCustomer Email :%s", cust.email);
                printf("\n");

                // file write mode(w) erase all existing data N write new data in it
                // wFptr = fopen("customerDetilas.txt", "a");
                printf("\n=================What Do You Want To Update======================\n");
                printf("\n1.Customer Name \n2.Mobile No : \n3.City \n4.Email \nEnter choice :");
                scanf("%d", &option);

                switch (option)
                {
                case 1:
                    printf("\nEnter New Customer Name : ");
                    scanf("%s", &cust.cust_name);
                    break;
                case 2:
                    printf("Enter New Customer Mobile No :");
                    scanf("%lld", &cust.mob_no);
                    break;
                case 3:
                    printf("\nEnter New Customer City : ");
                    scanf("%s", &cust.city);
                    break;
                case 4:
                    printf("\nEnter New Customer Email : ");
                    scanf("%s", &cust.email);
                    break;

                default:
                    break;
                }

                fprintf(temp, "%s %d %lld %s %s\n", cust.cust_name, cust.cust_id, cust.mob_no, cust.city, cust.email);

                flag = 1;

                // break;
            }
            else
            {
                fprintf(temp, "%s %d %lld %s %s\n", cust.cust_name, cust.cust_id, cust.mob_no, cust.city, cust.email);
            }
        }
    }

    if (flag)
    {
        printf("\nCustomer updated successfully.\n");
    }
    else
    {
        printf("\nCustomer ID Does NOT Exist");
    }

    fclose(rrFptr);

    fclose(temp);

    remove("customerDetilas.txt");
    rename("temp.txt", "customerDetilas.txt");

    // Using a temporary file and renaming it is a safer and
    // more robust approach for updating data within a file in C.
}
