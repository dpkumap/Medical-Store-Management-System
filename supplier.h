#include "supplierOperation.h"
int ch7;

void supplier(){

    printf("\t\n======== Supplier Menu ========\n");
    printf("\n1.Supplier entry :\n2.supplier List\n3.suppiler Update\n4.search By ID\n5.search By Name\nEnter YOur Choice :");
    scanf("%d",&ch7);

    switch (ch7)
    {
    case 1:
        supp_entry();
        break;
        case 2:
        supp_list();
        break;
        case 3:
        supp_update();
        break;
        case 4:
        search_id();
        break;
        case 5:
        search_name();
        break;
    
    default:
        break;
    }
}