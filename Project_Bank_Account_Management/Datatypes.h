#include<stdbool.h>

struct Date{
	int month, day, year;
};

struct Transaction{
	char transferId[10];
	char receivingId[10];
	double amount;
	char type[10]; // deposit / transfer / withdraw
	char message[50];
	struct Date transactionDate;	
};

struct AccountInfo{
	char userId[20];
	float balance;
	bool status;
	struct Transaction transactionHistory[];
};

struct User{
	char userId[11];//10+\0
	char name[20];
	bool gender;
	char phone[11];
	char email[20];
	char password[15];
	char status[10];
};
struct User users[100];	
struct User temp;
