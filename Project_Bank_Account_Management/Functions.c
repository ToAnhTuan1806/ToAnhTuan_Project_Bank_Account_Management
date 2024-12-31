#include <stdio.h>
#include "Functions.h"
#include <string.h>
#include <stdbool.h>

void menuStart() {
	printf("\n***Bank Management System Using C***\n");
	printf("\n    CHOOSE YOUR ROLE\n");
	printf("========================\n");
	printf("[1] Admin.\n");
	printf("[2] User.\n");
	printf("[0] Exit the Program.\n");
	printf("========================\n");
}

void menuAdmin() {
	printf("\n***Bank Management System Using C***\n");
	printf("\n    MENU");
	printf("\n========================\n");
	printf("[1] Add A New user.\n");
	printf("[2] Show All users.\n");
	printf("[3] Show detail an user.\n");
	printf("[4] Lock (Unkock) an user.\n");
	printf("[5] User Guideline.\n");
	printf("[6] About Us.\n");
	printf("[7] Soft users by name.\n");
	printf("[8] Search users by name.\n");
	printf("[0] Exit the program.\n");
	printf("\n========================\n");				
}

void addUsers(struct User users[], int *length) {
printf("*** Add a new user ***\n");
    int numUsers;
    printf("Add number of Users: ");
    scanf("%d", &numUsers);
    getchar();  

    int i, j;
    for (i=0; i<numUsers; i++) {
        int check;
        do {
            check=1;
            printf("\nEnter the ID (up to 10 characters): ");
            if(scanf("%10s", users[*length].userId)!=1) {
                printf("Invalid input. Try again!\n");
                getchar();
                check=0;
            } else {
                if(strlen(users[*length].userId)>=10) {
                    printf("ID must be up to 10 characters. Try again!\n");
                    getchar();  
                    check=0;
                } else {
                    for (j=0; j<*length; j++) {
                        if (strcmp(users[j].userId, users[*length].userId)==0) {
                            printf("Duplicate ID. Try again!\n");
                            check=0;
                            break;
                        }
                    }
                }
            }
            fflush(stdin); 
        } while (check==0);

        do {
            check=1;
            printf("Enter the name: ");
            fgets(users[*length].name, sizeof(users[*length].name), stdin);
            users[*length].name[strcspn(users[*length].name, "\n")] = '\0';  
            if(strlen(users[*length].name)==0) {
                printf("Name can't be empty. Try again!\n");
                check=0;
            } else {
                    for (j=0; j<*length; j++) {
                        if (strcmp(users[j].name, users[*length].name)==0) {
                            printf("Duplicate name. Try again!\n");
                            check=0;
                            break;
                        }
                    }
                }
            fflush(stdin); 
        } while(check==0);

        do {
            check=1;
            printf("Enter the gender (1 is male, 0 is female): ");
            char genderInput[2];
            fgets(genderInput, sizeof(genderInput), stdin);
            if(genderInput[0]=='1') {
                users[*length].gender=true;
            } else if(genderInput[0]=='0') {
                users[*length].gender=false;
            } else {
                printf("Invalid input. Enter 1 or 0!\n");
                check=0;
            }
            fflush(stdin); 
        } while(check==0);

        do {
            check=1;
            printf("Enter the email: ");
            fgets(users[*length].email, sizeof(users[*length].email), stdin);
            users[*length].email[strcspn(users[*length].email, "\n")] = '\0';

            if(strlen(users[*length].email)==0) {
                printf("Email can't be empty. Try again!\n");
                check = 0;
            } else if(users[*length].email[0]=='@'){
				printf("Email can not start with'@'. Try again!\n");
				check=0;			
			} else {
                for(j=0; j<*length; j++) {
                    if(strcmp(users[j].email, users[*length].email)==0) {
                        printf("Duplicate email. Try again!\n");
                        check=0;
                        break;
                    }
                }
            }
            fflush(stdin); 
        } while(check==0);

        do {
            check=1;
            printf("Enter the phone (exactly 10 characters): ");
            if(scanf("%10s", users[*length].phone)!=1) {
                printf("Invalid input. Try again!\n");
                getchar();
                check=0;
            } else {
                if(strlen(users[*length].phone)!=10) {
                    printf("Phone must be exactly 10 characters. Try again!\n");
                    getchar();  
                    check=0;
                } else {
                    for(j = 0; j<*length; j++) {
                        if (strcmp(users[j].phone, users[*length].phone) == 0) {
                            printf("Duplicate phone number. Try again!\n");
                            check = 0;
                            break;
                        }
                    }
                }
            }
            fflush(stdin); 
        } while(check==0);
    	
    	do {
    		check=1;
    		printf("Enter the date of birth (dd/mm/yyyy):\n");
    		printf("   Enter the day: ");
    		scanf("%d", &users[*length].dateOfBirth.day);
    		printf("   Enter the month: ");
    		scanf("%d", &users[*length].dateOfBirth.month);
    		printf("   Enter the year: ");
    		scanf("%d", &users[*length].dateOfBirth.year);
    		getchar();
    		switch(users[*length].dateOfBirth.month){
		    	case 2:
		    		if(users[*length].dateOfBirth.year%4==0 && users[*length].dateOfBirth.year%100!=0 || users[*length].dateOfBirth.year%400==0){
			            if(users[*length].dateOfBirth.day>0 && users[*length].dateOfBirth.day<=29){
	           	            break;
	           	        }else{
	           		        printf("Invalid. Try again.\n");
	           		        check=0;
				        }
			        }else{
				        if(users[*length].dateOfBirth.day>0 && users[*length].dateOfBirth.day<=28){
	           	            break;
	           	        }else{
	           		        printf("Invalid. Try again.\n");
	           		        check=0;
				        }
			        }
			        break;
			    case 1:
			    case 3:
			    case 5:
			    case 7:
			    case 8:
			    case 10:
			    case 12:
			    	if(users[*length].dateOfBirth.day>0 && users[*length].dateOfBirth.day<=31){
	           	        break;
	           	    }else{
	           		    printf("Invalid. Try again.\n");
	           		    check=0;
				    }
				    break;
				case 4:
				case 6:
				case 9:
				case 11:
					if(users[*length].dateOfBirth.day>0 && users[*length].dateOfBirth.day<=30){
	           	        break;
	           	    }else{
	           		    printf("Invalid. Try again.\n");
	           		    check=0;
				    }
				    break;
			}      
		} while(check==0);
		
		do {
            check=1;
            printf("Enter the Username: ");
            fgets(users[*length].userName, sizeof(users[*length].userName), stdin);
            users[*length].userName[strcspn(users[*length].userName, "\n")] = '\0';  
            if(strlen(users[*length].userName)==0) {
                printf("User name can't be empty. Try again!\n");
                check=0;
            } else {
                    for (j=0; j<*length; j++) {
                        if (strcmp(users[j].userName, users[*length].userName)==0) {
                            printf("Duplicate user name. Try again!\n");
                            check=0;
                            break;
                        }
                    }
                }
            fflush(stdin); 
        } while(check==0);

        strcpy(users[*length].password, users[*length].phone);  
        strcpy(users[*length].status, "Open");

        (*length)++;
        printf("\nUser added successfully!\n");
    }
}
//done
void showUsersData(struct User users[], int length) {
	if (length == 0) {  
        printf("No users available.\n");  
        return;  
    }  
	printf("|============|=================|======================|============|========|\n");
	printf("| %-10s | %-15s | %-20s | %-10s | %-6s |\n", "ID", "Name", "Email", "Phone", "Status");  
    printf("|============|=================|======================|============|========|\n");
 
  	int i;
    for (i=0; i<length; i++) {  
        printf("| %-10s | %-15s | %-20s | %-10s | %-6s |\n",   
                users[i].userId, users[i].name, users[i].email, users[i].phone, users[i].status);  
        printf("|------------|-----------------|----------------------|------------|--------|\n"); 
    }  
}

void showDigitalUsersData(struct User users[], int length) {
	if(length==0) {  
        printf("No users available.\n");  
        return;  
    }  
    printf("|============|=================|======================|============|========|========|=============|=================|\n");
    printf("| %-10s | %-15s | %-20s | %-10s | %-6s | %-6s | %-11s | %-15s |\n", "ID", "Name", "Email", "Phone", "Gender", "Status", "Birth Date", "Username");  
    printf("|============|=================|======================|============|========|========|=============|=================|\n");
 
    int i;
    for (i=0; i<length; i++) {  
        printf("| %-10s | %-15s | %-20s | %-10s | %-6s | %-6s | %02d/%02d/%04d  | %-15s |\n",   
                users[i].userId, users[i].name, users[i].email, users[i].phone, 
                (users[i].gender==1 ? "Male" : "Female"), users[i].status, 
                users[i].dateOfBirth.day, users[i].dateOfBirth.month, users[i].dateOfBirth.year,
                users[i].userName);  
        printf("|------------|-----------------|----------------------|------------|--------|--------|-------------|-----------------|\n"); 
    }  
}


//done
void softUsersByName(struct User users[], int length) {
	printf("\n***Sort Order***\n");
    printf("====================\n");
    printf("[1] Ascending.\n");
    printf("[2] Descending.\n");
    printf("[0] Exit Sorting.\n");
    printf("====================\n");
	int choice;
	printf("Enter the choice: ");
	scanf("%d", &choice);
	getchar();
	
	if(choice==1 || choice==2) {
		int i, j;
		for(i=0; i<length-1; i++){
			for(j=i+1; j<length; j++){
				int comparison=strcmp(users[i].name, users[j].name);
				if((choice==1&&comparison>0) || (choice==2&&comparison<0)) {
					temp=users[i];
					users[i]=users[j];
					users[j]=temp;
				}
			}
		}
		printf("\nSoft successfully.\n");
		showUsersData(users, length);
	} else if(choice==0) {
		printf("\nExit sort menu\n");
	} else {
		printf("Invalid choice.");
	}
} 
//done
void searchUsersByName(struct User users[], int length) { 
	char searchName[50];
	int found=-1;
	printf("Enter the name to search: ");
	fgets(searchName, sizeof(searchName), stdin);
	searchName[strcspn(searchName, "\n")]=0;
	int i;
	for(i=0; i<length; i++){
		if(strstr(users[i].name, searchName)!=NULL) {
			if(found==-1) {
				printf("|============|=================|======================|============|========|\n");
			    printf("| %-10s | %-15s | %-20s | %-10s | %-6s |\n", "ID", "Name", "Email", "Phone", "Status");  
			    printf("|============|=================|======================|============|========|\n");
			}
		printf("| %-10s | %-15s | %-20s | %-10s | %-6s |\n", users[i].userId, users[i].name, users[i].email, users[i].phone, users[i].status);  
        printf("|------------|-----------------|----------------------|------------|--------|\n");
        found = 1;
        }
    }
        if(found ==-1){
		printf("\nNo users found with the name containing \"%s\".\n", searchName);
		
	}
}	

void lockUnlockUsers(struct User users[], int length) {
	char id[11], choice;
	int found=0;
	printf("Enter the user ID to lock/unlock: ");
	scanf("%10s", id);
	int i;
	for(i=0; i<length; i++){
		if(strcmp(users[i].userId, id)==0){
			found=1;
			if(strcmp(users[i].status, "Open")==0){
				printf("");
			}
		}
	}
	
}
		

void loadUsersFromFile();

