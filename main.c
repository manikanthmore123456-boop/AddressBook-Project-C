/*  
Name    : Manikanth M More
Project : Address Book
*/
#include <stdio.h>
#include "contact.h"

int main() {
    int choice;
    int sortChoice;
    AddressBook addressBook;
    initialize(&addressBook); // Initialize the address book

    do {
        printf("\n\n=======================================================================\n");
        printf("|\t     ->> Welcome To Address Book Application <<-              |\n");
        printf("=======================================================================\n");
        printf("|\t[1]. -> Create contact\n");
        printf("|\t[2]. -> Search contact\n");
        printf("|\t[3]. -> Edit contact\n");
        printf("|\t[4]. -> Delete contact\n");
        printf("|\t[5]. -> List all contacts\n");
    	printf("|\t[6]. -> Save contacts\n");		
        printf("|\t[7]. -> Exit\n");
        printf("=======================================================================\n");
        printf("-->>>\tEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createContact(&addressBook);
                break;
            case 2:
                searchContact(&addressBook);
                break;
            case 3:
                editContact(&addressBook);
                break;
            case 4:
                deleteContact(&addressBook);
                break;
            case 5:          
                listContacts(&addressBook, sortChoice);
                break;
            case 6:
                //printf("Saving and Exiting...\n");
                saveContactsToFile(&addressBook);
                break;
            case 7:
                printf("\n\t====== XX ====== Successfully Exited... ====== XX ======\n\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
    
       return 0;
}
