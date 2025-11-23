#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include <ctype.h>

//////////////////////////////     FUNCTION CALL FOR EDIT FUNCTION       /////////////////////////////
void my_edit(int select, AddressBook *addressBook){
    int edit, found;
    char ename[40], ephone[20], eemail[50], confirm;
    printf("\n-->>>\tWhat you want to edit: \n");
    do{
        printf("========================================================\n");
        printf("|\t[1]. -> Name : \n");
        printf("|\t[2]. -> Phone: \n");
        printf("|\t[3]. -> Email: \n");
        printf("|\t[4]. -> Exit :\n");
        printf("========================================================\n");
        printf("-->>>\tEnter Choice: ");
        if(scanf("%d",&edit) != 1){
            printf("\n\t====== XX ======You Entered Invalid Choice. Try Again ====== XX ======\n");
            while(getchar() != '\n');
                continue;
        }

        switch (edit){
            case 1:{
                found = 0;
                while(1){
                    printf("-->>>\tEnter New Name: ");
                    getchar();
                    scanf("%[^\n]", ename);

                    int len = strlen(ename);
                    if(ename[0] == ' ' || ename[len-1] == ' '){
                        printf("\n\t====== XX ====== Error: First & End Character Should not be Space. Please Try again! ====== XX ======\n");
                        continue;
                    }
                    for(int i=0; ename[i] != '\0'; i++){
                        char ch = ename[i];
                        if(!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == ' ')){
                            found = 1;
                            break;
                        }
                        if(ch == ' ' && ename[i + 1] == ' '){
                            found = 1;
                            break;
                        }
                    }
                    if(found){
                        printf("\n\t====== XX ====== Invalid Name, Try Again!.. ====== XX ======\n\n");
                        printf("-->>>\tDo you want to continue? (y/n)!: \n");
                        getchar();
                        scanf("%c",&confirm);
                        if(confirm == 'y' || confirm == 'Y'){
                            continue;
                        }
                        edit = 4;
                        break;
                    }

                    strcpy(addressBook->contacts[select-1].name, ename);
                    printf("\n\t\t====== XX ====== Contact Edited & Saved Successfully  ====== XX ======\n");
                    printf("======================================================================================================\n");
                    printf("| %-8s | %-35s | %-16s | %-20s\n","Sl.No", "Name", "Phone", "Email");
                    printf("======================================================================================================\n");        
                    printf("| %-8d | %-35s | %-16s | %-20s\n",select,addressBook->contacts[select-1].name, addressBook->contacts[select-1].phone, addressBook->contacts[select-1].email);
                    printf("======================================================================================================\n");
                    edit = 4;
                    break;
                }
                break;
            }
                        
            case 2:{
                found = 0;
                while(1){
                    printf("\n-->>>\tEnter New Phone No: ");
                    while(getchar() != '\n');
                    scanf("%[^\n]", ephone);
                    int len = strlen(ephone);

                    if(len < 10 || len > 10){
                        printf("\n\t====== XX ====== Invalid Phone No. \"Try Again\". ====== XX ======\n");
                        continue;
                    }
                                
                    for(int i=0; i<addressBook->contactCount; i++){
                        if(strcmp(addressBook->contacts[i].phone, ephone) == 0){
                            found = 1;       
                            break;                        
                        }
                    }

                    if(found){
                        printf("\n\t====== XX ====== Phone No. Already Exist. Try Another No. ====== XX ======\n");
                        continue;
                    }

                    for(int i=0; ephone[i] != '\0'; i++){
                        char ch = ephone[i];
                        if(!(ch >= '0' && ch <= '9')){
                            found = 1;
                            break;
                        }
                    }

                    if(found){
                        printf("\n\t====== XX ======Invalid Phone No. \"Try Again\" ====== XX ======\n");
                        printf("\n-->>>\tDo you want to continue? (y/n)!: ");
                        while(getchar() != '\n');
                        scanf(" %c",&confirm);
                        if(confirm == 'y' || confirm == 'Y'){
                            continue;
                        }
                        edit = 4;
                        break;
                    }
                    strcpy(addressBook->contacts[select-1].phone, ephone);
                    printf("\n\t====== XX ====== Contact Edited & Saved Successfully.. ====== XX ======\n");
                    printf("======================================================================================================\n");
                    printf("| %-8s | %-35s | %-16s | %-20s\n","Sl.No", "Name", "Phone", "Email");
                    printf("======================================================================================================\n");        
                    printf("| %-8d | %-35s | %-16s | %-20s\n",select,addressBook->contacts[select-1].name, addressBook->contacts[select-1].phone, addressBook->contacts[select-1].email);
                    printf("======================================================================================================\n");
                    edit = 4;
                    break;
                }
                break;
            }

            case 3:{
                while(1){
                    found = 0;
                    printf("\n-->>>\tEnter New Email ID: ");
                    while(getchar() != '\n');
                    scanf("%[^\n]",eemail);

                    int len = strlen(eemail);
                    if(len < 7){
                        printf("\n\t====== XX ====== Email length is to Small. Try Again. ====== XX ======\n");
                        continue;
                    }

                    int atIndex=0, dotIndex=0, atCount=0, dotCount=0;
                    for(int i=0; eemail[i] != '\0'; i++){
                        if(eemail[i] == '@'){
                            atCount++;
                            atIndex = i;
                        }
                        if(eemail[i] == '.'){
                            dotCount++;
                            dotIndex = i;
                        }
                    }
                    if(atCount != 1 || dotCount != 1){
                        printf("\n\t====== XX ====== '@' or '.' occurs more than once or is missing. \"Try Again.!\" ====== XX =====\n");
                        continue;
                    }

                    for(int i=0; eemail[i] != '\0'; i++){
                        char ch = eemail[i];
                        if(!((ch >= 'a' && ch <= 'z') || ch == '@' || ch == '.' || (ch >= '0' && ch <= '9'))){
                            found = 1;
                            break;
                        }
                    }
                    if(found){
                        printf("\n\t===== XX ===== Error: Email should not contain Special or capital letters. ====== XX =====\n");
                        continue;
                    }

                    for(int i=0; eemail[i] != '@'; i++){
                        if(!(eemail[i] >= 'a' && eemail[i] <= 'z')){
                            found = 1;
                            continue;
                        }
                        else{
                            found = 0;
                            break;
                        }
                    }
                    if(found){
                        printf("\n\t====== XX ====== Error: Atleast one Character required before '@' ====== XX ======\n");
                        continue;
                    }            

                    if(strncmp(&eemail[len-4], ".com", 4) != 0){
                        printf("\n\t====== XX ======Email must end with \".com\". Try Again.. ====== XX ======\n");
                        continue;
                    }

                    if(atIndex > dotIndex || dotIndex - atIndex <= 1) {
                        printf("\n\t====== XX ====== Invalid Email structure. Try Again.====== XX ======\n");
                        continue;
                    }

                    for(int i=atIndex+1; eemail[i] != '\0' && eemail[i] != '.'; i++){
                        if(!(eemail[i] >= 'a' && eemail[i] <= 'z')){
                            found = 1;
                            break;
                        }
                    }
                    if(found){
                        printf("\n\t====== XX ====== Error: After '@' Their should be only lowercase charcters only. ====== XX ====== \n");
                        continue;
                    }

                    for(int i=0; i<addressBook->contactCount; i++){
                        if(strcmp(addressBook->contacts[i].email, eemail) == 0){
                            found = 1;
                            break;
                        }
                    }
                    if(found){
                        printf("\n\t====== XX ====== This Email is already Existed. Try Again..  ====== XX ====== \n");
                        continue;
                    }

                    strcpy(addressBook->contacts[select-1].email, eemail);
                    printf("\n\t====== XX ====== Email Edited Successfully..  ====== XX ====== \n");
                    printf("======================================================================================================\n");
                    printf("| %-8s | %-35s | %-16s | %-20s\n","Sl.No", "Name", "Phone", "Email");
                    printf("======================================================================================================\n");        
                    printf("| %-8d | %-35s | %-16s | %-20s\n",select,addressBook->contacts[select-1].name, addressBook->contacts[select-1].phone, addressBook->contacts[select-1].email);
                    printf("======================================================================================================\n");
                    edit = 4;
                    break;
                    }
            break;
            }

            case 4:{
                printf("\n\t====== XX ====== Exited Successfully...  ====== XX ====== \n");
                break;
            }

            default:
                printf("\n\t====== XX ====== Invalid Edit Choice.  ====== XX ====== \n");
        }
    }while(edit != 4);

}


/////////////////////////////    EDIT CONTACT     ///////////////////////

void editContact(AddressBook *addressBook)
{
	/* Define the logic for Editcontact */
    int choice;
    int flag = 0, select = 0, arr[addressBook->contactCount], k=1;

    do{
        printf("\n\n=======================================================================\n");
        printf("|\t\t ->> Search Contact To Edit <<-                       |\n");
        printf("=======================================================================\n");
        searchContactde(addressBook, &flag, &select, arr, &k);
        
        if(flag == -1)
            break;
        if(flag > 1){
            printf("\n-->>>\tEnter the Sl.No. which u want to edit : ");
            while(getchar() != '\n');
            scanf("%d",&select);
            select = arr[select];
        }
        my_edit(select, addressBook);
        break;

    }while(1);
    
}