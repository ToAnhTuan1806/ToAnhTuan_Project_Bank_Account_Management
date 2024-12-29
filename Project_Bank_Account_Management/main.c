#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Functions.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    int currentLength = 0;
    int choice, usChoice, adChoice;
    
    do {
        menuStart();
        printf("Enter The Choice: ");
        scanf("%d", &choice);
        getchar();
        
        switch(choice) {
            case 1:
                break;

            case 2:
                do {
                    menuAdmin();
                    printf("Enter The Choice: ");
                    scanf("%d", &adChoice);
                    getchar();

                    switch(adChoice) {
                        case 1:
                            addUsers(users, &currentLength);
                            break;
                        case 2:
                            showUsersData(users, currentLength);
                            break;
                        case 3:
                        	softUsersByName(users, currentLength);
                            break;
                        case 4:
                        	searchUsersByName(users, currentLength);
                            break;
                        case 5:
                            break;
                        case 6:
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

