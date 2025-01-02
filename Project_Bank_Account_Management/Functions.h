#include "Datatypes.h"
// Nguyen mau ham
void menuStart();
void login();
void menuAdmin();
void addUsers(struct User users[], int *length);
void showUsersData(struct User users[], int length);
void showDigitalUsersData(struct User users[], int length);
void softUsersByName(struct User users[], int length);
void searchUsersByName(struct User users[], int length);
void searchUsersById(struct User users[], int length);
void lockUnlockUsers(struct User users[], int length);
void saveUsersToFile(struct User users[], int length);
void loadUsersFromFile(struct User users[], int *length);
