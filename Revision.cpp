#include <stdio.h> // main head
#include <stdlib.h> // for system cls statement
#include <string.h> // for space creating string prevention
#include <unistd.h> // for usleep statement
#include <iostream> // for special character symbols
#include <conio.h> // for color coding statement and input 	
#include <windows.h> // for text background

using namespace std; // for loading and color statement

void green() {
    printf("\033[0;32m");
}

void yellow() {
    printf("\033[0;33m");
}

void red() {
    printf("\033[0;31m");
}

void cyan() {
    printf("\033[0;36m");
}

void white() {
    printf("\033[0;37m");
}

#define MAX_USERS 10
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_ID_LENGTH 16
#define DATA_FILE "Accounts.txt" // Name of the file to store user data
#define MAX_LENGTH 256

// Define roles
#define STUDENT 1
#define ADMIN 2
#define TEACHER 3
#define ADMINISTRATOR 4
#define REGISTRAR 5

// Global variables
char usernames[MAX_USERS][MAX_USERNAME_LENGTH];
char passwords[MAX_USERS][MAX_PASSWORD_LENGTH];
char ids[MAX_USERS][MAX_ID_LENGTH];
int roles[MAX_USERS];
int specificRoles[MAX_USERS];
int userCount = 0;

int signup() {
    printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
    printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
    printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n");
    printf("\t\t\t\t\t  [] >>====================<< []\n");
    printf("\t\t\t\t\t  [] >>       SIGN UP      << []\n");
    printf("\t\t\t\t\t  [] >>====================<< []\n");
    printf("\n\n");

    printf("\t\t\t >>  Enter username: ");
    scanf("%s", usernames[userCount]);
    printf("\n\n");

    char id[MAX_ID_LENGTH];
    int validId = 0;
    while (!validId) {
        printf("\t\t\t >>  Enter user ID number (max 15 digits): ");
        scanf("%15s", id);

        // Consume newline left-over
        int c;
        while ((c = getchar()) != '\n' && c != EOF);

        // Check ID length
        if (strlen(id) > 15) {
            printf("\n\t\t\t >>  ID number too long. Please enter a valid ID number (max 15 digits).\n");
        } else {
            int isValid = 1;
            for (int i = 0; i < strlen(id); i++) {
                if (!isdigit(id[i])) {
                    isValid = 0;
                    break;
                }
            }
            if (isValid) {
                validId = 1;
                strcpy(ids[userCount], id);
            } else {
                printf("\n\t\t\t >>  Invalid ID number. Please enter only digits.\n");
            }
        }
    }
    printf("\n\n");

    printf("\t\t\t >>  Enter password: ");
    scanf("%s", passwords[userCount]);
    printf("\n");

    printf("\t\t\t\t\t     >>  Choose your occupation: <<  \n");
    printf("\n");
    printf("\t\t\t\t\t  [] >>====================<< []\n");
    printf("\t\t\t\t\t  || (1) Student  (2) Admin || \n");
    printf("\t\t\t\t\t  [] >>====================<< []\n");
    printf("\t\t\t\t\t         >> CHOICE: ");
    int choice;
    scanf("%d", &choice);

    // Consume newline left-over
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (choice == 1) {
        roles[userCount] = STUDENT;
    } else if (choice == 2) {
        roles[userCount] = ADMIN;
        printf("\n");
        printf("\t\t\t\t\t     >>  Choose your specific occupation: <<  \n");
        printf("\n");
        printf("\t\t\t\t\t  [] >>====================<< []\n");
        printf("\t\t\t\t\t  || (1) Teacher  (2) Administrator  (3) Registrar || \n");
        printf("\t\t\t\t\t  [] >>====================<< []\n");
        printf("\t\t\t\t\t         >> CHOICE: ");
        scanf("%d", &specificRoles[userCount]);

        if (specificRoles[userCount] == 1) {
            specificRoles[userCount] = TEACHER;
        } else if (specificRoles[userCount] == 2) {
            specificRoles[userCount] = ADMINISTRATOR;
        } else if (specificRoles[userCount] == 3) {
            specificRoles[userCount] = REGISTRAR;
        }
    }
    
    FILE *file = fopen(DATA_FILE, "a");
    if (file == NULL) {
        perror("Unable to open the file!");
        exit(EXIT_FAILURE);
    }

    // Save user data with userCount as the index
    fprintf(file, "%d,%s,%s,%s,%d,%d\n", userCount, usernames[userCount], ids[userCount], passwords[userCount], roles[userCount], specificRoles[userCount]);
    fclose(file);

    userCount++;

    system("cls");
    printf("\t\t\t\t\t  [] >>====================<< []\n");
    printf("\t\t\t\t\t  [] >>REGISTRATION SUCCESS<< []\n");
    printf("\t\t\t\t\t  [] >>====================<< []\n");
    printf("\n");

    return 0;
}

int studentMenu(){
	printf("Studentmenu");
	return 0;
}

int teacherMenu(){
	printf("Teachermenu");
	return 0;
}

int administratorMenu(){
	printf("Administratormenu");
	return 0;
}

int registrarMenu(){
	printf("Registrarmenu");
	return 0;
}

int login() {
    char id[MAX_ID_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char line[MAX_LENGTH];

    printf("\n\n");
	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
	printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\n");
	printf("\t\t\t\t\t  [] >>====================<< []\n");
	printf("\t\t\t\t\t  [] >>       LOG  IN      << []\n");
	printf("\t\t\t\t\t  [] >>====================<< []\n");
    printf("\n\n");
    printf("\t\t\t >>  Enter user ID number: ");
    scanf("%15s", id);

    printf("\n\n");
    printf("\t\t\t >>  Enter password: ");
    scanf("%s", password);
    
    
    system("cls");

    for (int i = 0; i < userCount; i++) {
        if (strcmp(ids[i], id) == 0 && strcmp(passwords[i], password) == 0) {
            printf("\t\t\t\t\t >> Welcome, %s! <<\n", usernames[i]);
            if (roles[i] == STUDENT) {
                studentMenu();
            } else if (roles[i] == ADMIN) {
                if (specificRoles[i] == TEACHER) {
                    teacherMenu();
                } else if (specificRoles[i] == ADMINISTRATOR) {
                    administratorMenu();
                } else if (specificRoles[i] == REGISTRAR) {
                    registrarMenu();
                }
            }
            exit(0); // Exit the program
        }
    }
    
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL) {
        perror("Unable to open the file!");
        exit(EXIT_FAILURE);
    }

    int index, role, specificRole;
    char storedUsername[MAX_USERNAME_LENGTH], storedId[MAX_ID_LENGTH], storedPassword[MAX_PASSWORD_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        if (sscanf(line, "%d,%99[^,],%99[^,],%99[^,],%d,%d", &index, storedUsername, storedId, storedPassword, &role, &specificRole) != 6) {
            continue;
        }

        if (strcmp(storedId, id) == 0 && strcmp(storedPassword, password) == 0) {
            printf("\t\t\t\t\t >> Welcome, %s! <<\n", storedUsername);

            if (role == STUDENT) {
                studentMenu();
            } else if (role == ADMIN) {
                if (specificRole == TEACHER) {
                    teacherMenu();
                } else if (specificRole == ADMINISTRATOR) {
                    administratorMenu();
                } else if (specificRole == REGISTRAR) {
                    registrarMenu();
                }
            }
            fclose(file);
            exit(0); // Exit the program
        }
    }
    fclose(file);
    printf("Invalid credentials!\n");
    return 0;
}

int main() {
    int choice;
    while (1) {
        system ("color 30");
    	printf("\n\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
		printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\n\t\t\t\t     [] Philtech School Management System []\n");
		printf("\t\t\t\t     [][]   Choose what you want to do  [][]\n");
		printf("\n\n");
		printf("\t\t\t                    [1]      Sign up      [1]\n");
		printf("\t\t\t                    [2]      Log in       [2]\n");
		printf("\t\t\t                    [3]       Exit        [3]\n");
		printf("\n\n\n");
		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\t\t\t  |=||==||==||   PRESS THE NUMBER YOU WANT TO USE   ||==||==||=|\n");
		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        choice = getch();
        system("cls");
        
        switch (choice) {
            case '1':
            	system("cls");
                signup();
                break;
            case '2':
                system("cls");
				login();
                break;
            case '3':
                system("color A5");
				printf("\n\n");
				printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
				printf("\t\t\t|=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
				printf("\t\t\t|=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
				printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
				printf("\n\n");
				printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
				printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
				printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
				printf("\t\t\t|=||==||==||            0              0          ||==||==||=|\n");
				printf("\t\t\t|=||==||==||             _            _           ||==||==||=|\n");
				printf("\t\t\t|=||==||==||              -__________-            ||==||==||=|\n");
				printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
				printf("\t\t\t|=||==||==||    THANKYOU FOR USING THIS PROGRAM   ||==||==||=|\n");
				printf("\t\t\t|=||==||==||                GOODBYE!!             ||==||==||=|\n");
				printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
				printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
				printf("\n\n");
				printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
				printf("\t\t\t|=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
				printf("\t\t\t|=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
				printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
				return 0;
            default:
				main();
				system("cls");
				}
				
        }
		return 0; 
    }

