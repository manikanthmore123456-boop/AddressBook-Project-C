#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include <ctype.h>

/////////////////////////////      LOAD SAVED DATA FROM THE FILE     /////////////////////////
void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    
    loadContactsFromFile(addressBook);
}

void loadContactsFromFile(AddressBook *addressBook) {
    FILE *fp;
    fp = fopen("contacts.csv","r");
    if(fp == NULL){
        perror("Error");
        return;
    }
    fscanf(fp, "#%d\n",&addressBook->contactCount);
    for(int i=0; i<addressBook->contactCount; i++){
        fscanf(fp, "%[^,],%[^,],%[^\n]\n",addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
    }
    fclose(fp);
    return;
}