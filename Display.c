#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include <ctype.h>

/////////////////////////////  SORT CONTACTS  //////////////////////////

void sortContacts(AddressBook *addressBook, int sortCriteria) {
    int i, j;
    Contact temp;

    for (i = 0; i < addressBook->contactCount - 1; i++) {
        for (j = i + 1; j < addressBook->contactCount ; j++) {
            int cmp = 0;

            switch (sortCriteria) {
                case 1:
                    cmp = strcasecmp(addressBook->contacts[i].name, addressBook->contacts[j].name);
                    break;
                case 2:
                    cmp = strcasecmp(addressBook->contacts[i].phone, addressBook->contacts[j].phone);
                    break;
                case 3:
                    cmp = strcasecmp(addressBook->contacts[i].email, addressBook->contacts[j].email);
                    break;
                default:
                    printf("\nInvalid sort choice!\n");
                    return;
            }

            if (cmp > 0) {
                temp = addressBook->contacts[i];
                addressBook->contacts[i] = addressBook->contacts[j];
                addressBook->contacts[j] = temp;
            }
        }
    }
}


////////////////////////////     LIST OF THE CONTACTS          ///////////////////////////////
void listContacts(AddressBook *addressBook, int sortCriteria) 
{
    // Sort contacts based on the chosen criteria
    if (addressBook->contactCount == 0) {
        printf("\n\t====== XX ====== No contacts found! ====== XX ====== \n");
        return;
    }

    char choice;
    printf("\n-->>>\tDo you want to sort the contacts? (Y/N): ");
    scanf(" %c", &choice);

    if (choice == 'Y' || choice == 'y') {
        printf("\n\n=======================================================================\n");
        printf("|\t\t       ->> Sort Contacts <<-                          |\n");
        printf("=======================================================================\n");
        printf("|\t[1]. -> Name\n");
        printf("|\t[2]. -> Phone\n");
        printf("|\t[3]. -> Email\n");
        printf("=======================================================================\n");
        printf("-->>>\tEnter your choice: ");
        scanf("%d", &sortCriteria);

        sortContacts(addressBook, sortCriteria);

        switch (sortCriteria) {
            case 1: printf("\nContacts sorted by Name!\n"); break;
            case 2: printf("\nContacts sorted by Phone!\n"); break;
            case 3: printf("\nContacts sorted by Email!\n"); break;
            default: printf("\nInvalid sort choice! Showing unsorted list.\n"); break;
        }
    }

    printf("\n\t====== XX ====== List Of All Contacts  ====== XX ====== \n");
    printf("======================================================================================================\n");
    printf("| %-8s | %-35s | %-16s | %-20s\n","Sl.No", "Name", "Phone", "Email");
    printf("======================================================================================================\n");
    for(int i=0; i<addressBook->contactCount; i++){
        printf("| %-8d | %-35s | %-16s | %-20s\n",i+1,addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    printf("======================================================================================================\n");
}