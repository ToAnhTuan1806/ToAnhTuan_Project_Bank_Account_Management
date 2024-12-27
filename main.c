#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct User users[100];
	int length=0;
	int choice;
	
	do{
		menuStart();
		printf("Enter The Choice: ");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				break;
			case 2:
				
				menuAdmin();
				printf("Enter The Choice: ");
				scanf("%d", &choice);
				
				switch(choice) {
					case 1:
						addUsers(&length, users);
						break;
					case 2:
						showUsers(length, users);
						break;
					case 3: 
						break;
					case 4:
						break;
					case 5:
						break;
					case 6:
						break;
										
				}
				break;
			case 0:
				printf("Exit");
				break;		
				default:
				printf("Invalid.Try again!\n");
		}
	} while(choice!=0);
	return 0;
}
