#include <stdio.h>
#include<stdlib.h>
#include "Customer.h"
#include "Medicine.h"
#include "supplier.h"
#include "Bill.h"
#include "About.h"

void main()
{

    int choice;
    long int pass;
    char cho;

    printf("enter Password :");
    scanf("%d", &pass);
    printf("\t\n======== Welcome To Medical Store ========");
    do
    {
        printf("\t\n\n\n1. Customer Info"
               "\t\n2. Medicine "
               "\t\n3. Supplier Info"
               "\t\n4. Billing"
               "\t\n5. About"
               "\t\n6. Exit");

        printf("\t\nEnter Choice :");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
            customer();
            break;
        case 2:
            Medicine();
            break;

        case 3:
            supplier();
            break;

        case 4:
            bills();
            break;

        case 5:
            about();
            break;
        case 6:
        exit(0);
        break;
        }

        printf("\n\n\n do you want to perform more operation [Y/N]:");
        cho = getch();

    } while (cho == 'y' || cho == 'Y');
}