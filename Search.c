#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include <ctype.h>

//////////////////////////  SEARCH CONTACTS   //////////////////////////

void searchContact(AddressBook *addressBook) 
{
    /* Define the logic for search */
    int choice, flag, k=1;
    char name[50];
    char phone[20];
    char email[50];

    do{
        printf("\n\n=======================================================================\n");
        printf("|\t\t\t->> Search Contact <<-                        |\n");
        printf("=======================================================================\n");
        printf("|\t[1]. -> By Name   \n");
        printf("|\t[2]. -> By Phone  \n");
        printf("|\t[3]. -> By Email  \n");
        printf("|\t[4]. -> Exit.   \n");
        printf("=======================================================================\n");
        printf("-->>>\tEnter Choice : ");
        if(scanf("%d",&choice) != 1){
            printf("\n\t====== XX ====== You Entered Invalid Choice. Try Again ====== XX ====== \n");
            while(getchar() != '\n');
            continue;
        }

        switch (choice){
            case 1:{      //Seraching by name
                printf("\n-->>>\tEnter Name : ");
                while(getchar() != '\n');
                scanf("%[^\n]",name);
                flag = 0;
                for(int i=0; i<addressBook->contactCount; i++){
                    if(strcasestr(addressBook->contacts[i].name, name) != NULL){
                        if(flag == 0){
                            printf("======================================================================================================\n");
                            printf("| %-8s | %-35s | %-16s | %-20s\n","Sl.No", "Name", "Phone", "Email");
                            printf("======================================================================================================\n");
                        }
                        flag++;
                        printf("| %-8d | %-35s | %-16s | %-20s\n",k++,addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);
                        
                    }
                }
                if(flag > 0){
                    printf("======================================================================================================\n");
                    printf("\t====== XX ====== Contact Found Successfully ====== XX ======\n");
                    choice = 4;
                    break;
                }
                if(flag == 0){
                    printf("\n\t====== XX ======  Contact Not Found  ====== XX ======\n");
                }
                break;
            }

            case 2:{    //Searching by phone no.
                printf("\n-->>>\tEnter Phone No. : ");
                while(getchar() != '\n');
                scanf("%[^\n]",phone);
                flag = 0;
                for(int i=0; i<addressBook->contactCount; i++){
                    if(strstr(addressBook->contacts[i].phone, phone) != NULL){
                        if(flag == 0){
                            printf("======================================================================================================\n");
                            printf("| %-8s | %-35s | %-16s | %-20s\n","Sl.No", "Name", "Phone", "Email");
                            printf("======================================================================================================\n");
                        }
                        flag++;
                        printf("| %-8d | %-35s | %-16s | %-20s\n",k++,addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);

                    }
                }
                if(flag > 0){
                    printf("======================================================================================================\n");
                    printf("\t====== XX ====== Contact Found Successfully ====== XX ======\n");
                    choice = 4;
                    break;
                }
                if(flag == 0){
                    printf("\n\t====== XX ===== Contact Not Found ====== XX ======\n");
                }
                break;
            }

            case 3:{   //Searching by email.id
                printf("\n-->>>\tEnter Email : ");
                while(getchar() != '\n');
                scanf("%[^\n]",email);
                flag = 0;
                for(int i=0; i<addressBook->contactCount; i++){
                    if(strstr(addressBook->contacts[i].email, email) != NULL){
                        if(flag = 0){
                        printf("======================================================================================================\n");
                        printf("| %-8s | %-35s | %-16s | %-20s\n","Sl.No", "Name", "Phone", "Email");
                        printf("======================================================================================================\n");
                        }
                        flag++;
                        printf("| %-8d | %-35s | %-16s | %-20s\n",k++,addressBook->contacts[i].name, addressBook->contacts[i].phone, addressBook->contacts[i].email);

                    }
                }
                if(flag > 0){
                    printf("======================================================================================================\n");
                    printf("\t====== XX ====== Contact Found Successfully ====== XX ======\n");
                    choice = 4;
                    break;
                }
                if(flag == 0){
                    printf("\n\t====== XX ====== Contact Not Found ====== XX ====== \n");
                }
                break;
            }
        
            case 4:
                printf("\n\t====== XX ====== Exited Successfully.. ====== XX ======\n");
                break;

            default: 
                printf("\n\t====== XX ====== Invalid Search ====== XX ======\n"); 
        }
    }while(choice != 4);
}