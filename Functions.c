#include <stdio.h>
#include "Functions.h"

void menuStart() {
	printf("\n***Bank Management System Using C***\n");
	printf("\n    CHOOSE YOUR ROLE\n");
	printf("========================\n");
	printf("[1] Admin.\n");
	printf("[2] User.\n");
	printf("[0] Exit the Program.\n");
	printf("========================\n");
}

void login() {
	printf("\n***Bank Management System Using C***\n");
	printf("\n    LOGIN\n");
	printf("========================\n");
	printf("Email: ");
	printf("\nPassword: ");
	printf("\n========================\n");
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
	printf("[0] Exit the program.\n");
	printf("\n========================\n");				
}

void addUsers(int *length, struct User users[]) {
	printf("Add number of User: ");
	scanf("%d", length);
	getchar();
	int i;
	for(i=0; i<*length; i++){
		printf("Enter the ID: ");
		fgets(users[i].userId, sizeof(users[i].userId), stdin);
		users[i].userId[strcspn(users[i].userId, "\n")]=0;
		if(strlen(users[i].userId)<10) {
			printf("Error: ID can not be less than 10 characters.");
		}
		
		printf("Enter the name: ");
		fgets(users[i].name, sizeof(users[i].name), stdin);
		users[i].name[strcspn(users[i].name, "\n")]=0;
		
		printf("Enter the gender (1 is male, 0 is fmale)");
		char genderInput[2];
		fgets(genderInput, sizeof(genderInput), stdin);
		if(genderInput[0]=='1') {
			users[i].gender=true;
		} else {
			users[i].gender=false;
		}
		
		printf("Enter the email: ");
		fgets(users[i].email, sizeof(users[i].email), stdin);
		users[i].email[strcspn(users[i].email, "\n")]=0;
		
		printf("Enter the phone: ");
		fgets(users[i].phone, sizeof(users[i].phone), stdin);
		users[i].phone[strcspn(users[i].phone, "\n")]=0;
		(*length)++;
	}
		
	
}
