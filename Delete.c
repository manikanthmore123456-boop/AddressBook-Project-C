#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include <ctype.h>

///////////////////////////     DELETE CONTACT      ///////////////////////// 
void deleteContact(AddressBook *addressBook)
{
	/* Define the logic for deletecontact */

    int flag = 0, select = 0, arr[addressBook->contactCount], k=1; 
    char confirm;

    if(addressBook == NULL || addressBook->contactCount == 0){
        printf("\n\t====== XX ====== No Contacts Available To Delete ====== XX ====== \n");
        return;
    }
    do{
        printf("\n\n=======================================================================\n");
        printf("|\t\t ->> Search Contact To Delete <<-                     |\n");
        printf("=======================================================================\n");
        searchContactde(addressBook, &flag, &select, arr, &k);
        
        if(flag == -1)
            break;

        if(flag > 1){
            printf("\n-->>>\tEnter the Sl.No. which u want to Delete : ");
            while(getchar() != '\n');
            scanf("%d",&select);
            select = arr[select];
        }

        if(select < 1 || select > addressBook->contactCount){
            printf("\n\t====== XX ====== Invalid Choice ====== XX ====== \n");
            continue;
        }

        if(flag > 1){
            printf("\n\t====== XX ====== You selected  ====== XX ====== \n");
            printf("======================================================================================================\n");
            printf("| %-8s | %-35s | %-16s | %-20s\n","Sl.No", "Name", "Phone", "Email");
            printf("======================================================================================================\n");
            printf("| %-8d | %-35s | %-16s | %-20s\n", select, addressBook->contacts[select-1].name,addressBook->contacts[select-1].phone,addressBook->contacts[select-1].email);
            printf("======================================================================================================\n");
        }

        printf("\n\n-->>>\tDo you want to delete the contact? (y/n) : ");
        while(getchar() != '\n');
        scanf("%c",&confirm);

        if(confirm == 'y' || confirm == 'Y'){
            for (int i = select - 1; i < addressBook->contactCount - 1; i++) {
                addressBook->contacts[i] = addressBook->contacts[i + 1];
            }
            addressBook->contactCount--;
            printf("\n\t====== XX ====== Contact Deleted Successfully... ====== XX ====== \n");
        }

        else{
            printf("\n\t====== XX ====== Delete Operation Cancelled ====== XX ====== \n");
        }
        break;
    }while(1);

}
