#include <stdio.h>
#include "Stringcmp.h"

struct Supplier
{
    int supp_id;
    char supp_name[90];
    long long int mob_no;
    char city[90];
    char email[90];
};

FILE *wFptr3;
FILE *rFptr3;

struct Supplier s;

void supp_entry()
{

    wFptr3 = fopen("supplierDetails.txt", "a");
    rFptr3 = fopen("supplierDetails.txt", "r");

    int sampleId, flag = 1;

    printf("\nenter supplier id :");
    scanf("%d", &sampleId);
    printf("======");
    while (fscanf(rFptr3, "%d %s %lld %s %s", &s.supp_id, s.supp_name, &s.mob_no, s.city, s.email) != EOF)
    {

        if (sampleId == s.supp_id)
        {

            printf("\nSupplier Id Already exist ");
            flag = 0;
            fclose(rFptr3);
            fclose(wFptr3);
            break;
        }
    }
    if (flag)
    {

        s.supp_id = sampleId;
        // flag = 1;
        printf("\nenter Supplier Name :");
        scanf("%s", &s.supp_name);
        printf("\nenter contact No :");
        scanf("%lld", &s.mob_no);
        printf("\nenter city :");
        scanf("%s", &s.city);
        printf("\nenter Supplier Email");
        scanf("%s", &s.email);

        fprintf(wFptr3, "%d %s %lld %s %s\n", s.supp_id, s.supp_name, s.mob_no, s.city, s.email);
        printf("\nsuccessfull!");
    }

    fclose(wFptr3);
    fclose(rFptr3);
}

void supp_list()
{

    rFptr3 = fopen("supplierDetails.txt", "r");

    if (rFptr3 == NULL)
    {

        printf("\nopening failed!");
    }
    else
    {
        printf("\n=================Supplier Details ======================\n");
        while (fscanf(rFptr3, "%d %s %lld %s %s", &s.supp_id, s.supp_name, &s.mob_no, s.city, s.email) != EOF)
        {
            printf("\nSupplier ID : %d", s.supp_id);
            printf("\nSupplier Name : %s", s.supp_name);
            printf("\nMobile No : %lld", s.mob_no);
            printf("\nCity : %s", s.city);
            printf("\nEmail : %s", s.email);
            printf("\n=======================================\n");
        }
    }
    fclose(rFptr3);
}

void supp_update()
{
    FILE *temp3 = fopen("tempFile2.txt", "w");
    rFptr3 = fopen("supplierDetails.txt", "r");

    int sampleId, op, flag = 0;

    printf("\nenter Supplier ID to update :");
    scanf("%d", &sampleId);

    while (fscanf(rFptr3, "%d %s %lld %s %s", &s.supp_id, s.supp_name, &s.mob_no, s.city, s.email) != EOF)
    {
        if (sampleId == s.supp_id)
        {
            printf("\n===============Supplier Id=%2d========================\n", sampleId);
            printf("\nSupplier Name : %s", s.supp_name);
            printf("\nMobile No : %lld", s.mob_no);
            printf("\nCity : %s", s.city);
            printf("\nEmail : %s", s.email);

            printf("\n=================What Do You Want To Update======================\n");
            printf("\n1.Update Supplier Name \n2.Update Supplier Mobile \n3.update city \n4.update email\nEnter Your Choice");
            scanf("%d", &op);
            flag = 1;
            switch (op)
            {
            case 1:
                printf("\nEnter New Supplier Name: ");
                scanf("%s", &s.supp_name);
                break;
            case 2:
                printf("\nEnter New Supplier Mobile ");
                scanf("%lld", &s.mob_no);
                break;
            case 3:
                printf("\nEnter New city :");
                scanf("%s", &s.city);
                break;
            case 4:
                printf("\nEnter New EMail :");
                scanf("%s", &s.email);
                break;

            default:
                printf("\ninvalid choice ");
                break;
            }

            fprintf(temp3, "%d %s %lld %s %s\n", s.supp_id, s.supp_name, s.mob_no, s.city, s.email);
        }
        else
        {

            fprintf(temp3, "%d %s %lld %s %s\n", s.supp_id, s.supp_name, s.mob_no, s.city, s.email);
        }
    }

    if (flag == 0)
    {

        printf("\ninvalid Supplier ID");
    }
    else
    {

        printf("\nSupplier Updated Successfully!");
    }

    fclose(rFptr3);
    fclose(temp3);

    remove("supplierDetails.txt");
    rename("tempFile2.txt", "supplierDetails.txt");
}

void search_id()
{

    rFptr3 = fopen("supplierDetails.txt", "r");

    int sampleId, flag = 0;

    printf("\nenter Supplier To be search :");
    scanf("%d", &sampleId);

    while (fscanf(rFptr3, "%d %s %lld %s %s", &s.supp_id, s.supp_name, &s.mob_no, s.city, s.email) != EOF)
    {
        if (sampleId == s.supp_id)
        {

            printf("\n===============Supplier Id=%2d========================\n", sampleId);
            printf("\nSupplier Name : %s", s.supp_name);
            printf("\nMobile No : %lld", s.mob_no);
            printf("\nCity : %s", s.city);
            printf("\nEmail : %s", s.email);
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {

        printf("\nInvalid supplier ID");
    }else{
        printf("\nSupplier Details Found!");
    }

    fclose(rFptr3);
}

void search_name(){

    rFptr3=fopen("supplierDetails.txt", "r");

    char ch[90];
    int v,flag=0;

    printf("enter Supllier name to be Search :");
    scanf("%s",ch);

    while(fscanf(rFptr3, "%d %s %lld %s %s", &s.supp_id, s.supp_name, &s.mob_no, s.city, s.email) != EOF){

        v=strCmp(s.supp_name,ch);

        if(v==0){
            printf("\n===============Supplier Name=%s========================\n", s.supp_name);
            printf("\nSupplier Id : %d", s.supp_id);
            printf("\nMobile No : %lld", s.mob_no);
            printf("\nCity : %s", s.city);
            printf("\nEmail : %s", s.email);
            flag=1;
        }

    }

    if(flag==0){

        printf("\nInvalid Supplier Name");
    }else{

        printf("\nSupplier Details Found!");
    }

    fclose(rFptr3);
}