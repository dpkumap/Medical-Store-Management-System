#include "CustomersOperation.h"
int chj;
char chw;
void customer()
{
    
    printf("\t\n======== Customer Menu ========\n");
        printf("\t\n1.search Customer By id"
               "\t\n2.search Customer By name"
               "\t\n3.customer entry"
               "\t\n4.customers list"
               "\t\n5.customer update");
        printf("\t\nenter choice : ");
        scanf("%d", &chj);

        switch (chj)
        {
        case 1:
            searchByCustID();
            break;

        case 2:
            searchByCustName();
            break;
        case 3:

            cust_entry();
            break;
        case 4:
            cust_list();
            break;
        case 5:
            cust_update();
            break;

       
        }

     
}