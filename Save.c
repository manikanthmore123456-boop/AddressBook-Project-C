#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include <ctype.h>

////////////////////////////      SAVE AND EXIT      //////////////////////////////////////////
void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

void saveContactsToFile(AddressBook *addressBook) {
    FILE *fp;
    fp = fopen("contacts.csv","w");
    if(fp == NULL){
        perror("Error");
        return;
    }
    fprintf(fp, "#%d\n",addressBook->contactCount);
    for(int i=0; i<addressBook->contactCount; i++){
        fprintf(fp, "%s,%s,%s\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    fclose(fp);
    //printf("\n=======================================================================\n");
    printf("\n\t   ->> Contacts Saved Successfully.. <<-\n");
    //printf("=======================================================================\n");
    return;
}


