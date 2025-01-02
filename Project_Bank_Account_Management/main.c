#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Functions.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int currentLength = 0;
    int choice, usChoice, adChoice;
	loadUsersFromFile(users, &currentLength);	
	
    do {
    	system("cls");
        menuStart();
        printf("Enter The Choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1:
                break;

            case 2:
                do {
                	system("cls");
                    menuAdmin();
                    printf("Enter The Choice: ");
                    scanf("%d", &adChoice);
                    getchar();

                    switch(adChoice) {
                        case 1:
                        	system("cls");
                        	printf("*** Add a new user ***\n");
                            addUsers(users, &currentLength);
							saveUsersToFile(users, currentLength);					          
                            break;
                        case 2:
                        	system("cls");
                        	printf("*** Show All users ***\n");
                            showUsersData(users, currentLength);
                            
                            break;
                        case 3:
                        	system("cls");
                        	printf("*** Show detail an user ***\n");
                        	showDigitalUsersData(users, currentLength);                      	
                            break;
                        case 4:
                        	system("cls");
                        	lockUnlockUsers(users, currentLength);
                        	saveUsersToFile(users, currentLength);
                            break;
                        case 5:
                        	system("cls");
                    		printf("*** Search users by name ***\n");
                    		searchUsersByName(users, currentLength);
                            break;
                        case 6:
                        	system("cls");
                        	printf("*** Search users by Id ***\n");
                        	searchUsersById(users, currentLength);                      	
                            break;
                        case 7:
                        	system("cls");
                        	printf("*** Soft users by name ***\n");
                        	softUsersByName(users, currentLength);
                        	saveUsersToFile(users, currentLength);
                        	break;
                        case 0:
                            printf("\nExiting Admin Menu...\n");
                            break;
                        default: 
                            printf("\nInvalid. Try again!\n");                    
                    }
                } while(adChoice != 0);
                
                break;

            case 0:
                printf("\n========= Thank You =========\n");
                printf("========= See You Soon ======\n");
                break;      

            default:
                printf("Invalid. Try again!\n");
        }
    } while(choice != 0);

    return 0;
}

