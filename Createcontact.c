#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include <ctype.h>

//////////////////////////        CREATE CONTACTS        ///////////////////////////////////
void createContact(AddressBook *addressBook)
{
	/* Define the logic to create a Contacts */
    char name[40];
    char phone[20];
    char email[50];
    int found, isDublicate;

    ///////  VALIDATION FOR NAME   /////////
    printf("\n=======================================================================\n");
    printf("|\t\t\t->> Create Contact <<-                        |\n");
    printf("=======================================================================");
    while(1){
        found = 0;
        printf("\n-->>>\t[1].Enter Name     : ");
        while(getchar() != '\n');
        scanf("%[^\n]",name);  

        //Validations for name.
        int len = strlen(name);
        if(name[0] == ' ' || name[len-1] == ' '){
            printf("\n\t ====== XX ====== Name must not Start & End with ' '/space. \"Try Again.\" ====== XX ======\n");
            continue;
        }

        for(int i=0; name[i] != '\0'; i++){
            if(name[i] == ' ' && name[i+1] == ' ')
                found = 1;
        }
        if(found){
            printf("\n\t ====== XX ======Continue Spaces are not allowed in name ====== XX ======\n");
            continue;
        }

        for(int i=0; name[i] != '\0'; i++){
            char ch = name[i];
            if(!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == ' ' || (ch == ' ' && name[i+1] == ' ')))
                found = 1;
        }
        if(found){
            printf("\n\t ====== XX ======Name doesn't have Special character or Digits ====== XX ======\n");
            continue;
        }

        //If all validtions are correct then creat name
        strcpy(addressBook->contacts[addressBook->contactCount].name, name);
        break;
    }

    /////////////////   VALIDATION FOR PHONE NUMBER   //////////////////

    while(1){
        found = 0;
        printf("-->>>\t[2].Enter Phone No.: ");
        while(getchar() != '\n');
        scanf("%[^\n]",phone);

        //Validations for phone no.
        int len = strlen(phone);
        if(len != 10){
            printf("\n\t====== XX ====== Phone No. must be exactly 10 digits only ====== XX ======\n");
            continue;
        }
        for(int i=0; phone[i] != '\0'; i++){
            char ch = phone[i];
            if(!(ch >= '0' && ch <= '9'))
                found = 1;
        }
        if(found){
            printf("\n\t====== XX ======Phone no. must contain only digits ====== XX ======\n");
            continue;
        }

        for(int i=0; i<addressBook->contactCount; i++){
            if(strcmp(addressBook->contacts[i].phone, phone) == 0)
                found = 1; 
        }
        if(found){
            printf("\n\t====== XX ====== Enter No is already exist. Try Another.. ====== XX ======\n");
            continue;
        }

        //if all validation for phone no. are correct then creat
        else{
            strcpy(addressBook->contacts[addressBook->contactCount].phone, phone);
            break;
        }
    }

    ///////////////////////////  VALIDATION FOR EMAIL    ///////////////////////////////

    while(1){
        found = 0;
        printf("-->>>\t[3].Enter Email ID : ");
        while(getchar() != '\n');
        scanf("%[^\n]",email);

        //validations for email
        int len = strlen(email);
        if(len < 7){
            printf("\n\t====== XX ====== Email length should be greter than 7. Try Again..! ====== XX ======\n");
            continue;
        }

        int atIndex=0, atCount=0, dotIndex=0, dotCount=0;
        for(int i=0; email[i] != '\0'; i++){
            if(email[i] == '@'){
                atCount++;
                atIndex = i;
            }
            if(email[i] == '.'){
                dotCount++;
                dotIndex = i;
            }
        }
        if(atCount != 1 || dotCount != 1){
            printf("\n\t====== XX ======'@' or '.' appers more than once or missing. Try Again..! ====== XX ======\n");
            continue;
        }

        for(int i=0; email[i] != '\0'; i++){
            char ch = email[i];
            if(!((ch >= 'a' && ch <= 'z') || ch == '@' || ch == '.' || (ch >= '0' && ch <= '9'))){
                found = 1;
                break;
            }
        }
        if(found){
            printf("\n\t====== XX ====== Error: Email shouldn't contain Special or capital letters ====== XX ====== \n");
            continue;
        }

        for(int i=0; email[i] != '@'; i++){
            if(!(email[i] >= 'a' && email[i] <= 'z')){
                found = 1;
                break;
            }
            else{
                break;
            }
        }
        if(found){
            printf("\n\t====== XX ====== Error: Atleast one Character required before '@' ====== XX ======\n");
            continue;
        }

        if(atIndex > dotIndex || dotIndex - atIndex <= 1){
            printf("\n\t====== XX ====== Invalid Email format. Try Again. ====== XX ======\n");
            continue;
        }

        if(strncmp(&email[len - 4], ".com", 4) != 0){
            printf("\n\t====== XX ====== \".com\" is missing at the end of email. Try Again. ====== XX ======\n");
            continue;
        }

        for(int i=atIndex +1; email[i] != '.'; i++){
            if(!(email[i] >= 'a' && email[i] <= 'z')){
                found = 1;
                break;
            }
        }
        if(found){
            printf("\n\t====== XX ====== Error: After '@' only lower charcters shoulb be their ====== XX ======\n");
            continue;
        }

        for(int i=0; i<addressBook->contactCount; i++){
            if((strcmp(addressBook->contacts[i].email, email)) == 0)
                found = 1;
        }
        if(found){
            printf("\n\t====== XX ====== Email is Already Exist. Try Again. ====== XX ======\n");
            continue;
        }

        //if all above validations are correct then creat email.
        strcpy(addressBook->contacts[addressBook->contactCount].email, email);
        printf("\n\t====== XX ====== Contact Created Successfully!... ====== XX ======\n");
        break;
    }
    addressBook->contactCount++;
}