#include <stdio.h> // main head
#include <stdlib.h> // for system cls statement
#include <string.h> // for space creating string prevention
#include <unistd.h> // for usleep statement
#include <iostream> // for special character symbols
#include <conio.h> // for color coding statement and input key ( getch ) command
#include <windows.h> // for text background
#include <time.h> // for time statements

using namespace std; // for loading and color statement

void green() {
    printf("\033[0;32m");
}


// define max variables
#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_ID_LENGTH 16
#define DATA_FILE "users.txt"
#define MAX_LENGTH 256
#define MAX_SUBJECTS 50
#define MAX_ENROLLEES 100
#define MAX_NAME 100

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
int choice;

int loadUsers() {
    FILE *file = fopen(DATA_FILE, "r");
    if (file == NULL) {
        // If file doesn't exist, create it
        file = fopen(DATA_FILE, "w");
        if (file == NULL) {
            printf("Error: Unable to create data file!\n");
            return 0;
        }
        fclose(file);
        return 1; // Return success as this is first run
    }

    char line[MAX_LENGTH];
    userCount = 0;  // Reset userCount before loading

    while (fgets(line, sizeof(line), file) && userCount < MAX_USERS) {
        // Remove newline if present
        line[strcspn(line, "\n")] = 0;
        
        // Parse the line
        char tempUsername[MAX_USERNAME_LENGTH];
        char tempId[MAX_ID_LENGTH];
        char tempPassword[MAX_PASSWORD_LENGTH];
        int tempRole;
        int tempSpecificRole;
        
        if (sscanf(line, "%[^,],%[^,],%[^,],%d,%d",
                   tempUsername,
                   tempId,
                   tempPassword,
                   &tempRole,
                   &tempSpecificRole) == 5) {
            
            // Copy data to arrays
            strncpy(usernames[userCount], tempUsername, MAX_USERNAME_LENGTH - 1);
            strncpy(ids[userCount], tempId, MAX_ID_LENGTH - 1);
            strncpy(passwords[userCount], tempPassword, MAX_PASSWORD_LENGTH - 1);
            roles[userCount] = tempRole;
            specificRoles[userCount] = tempSpecificRole;
            
            // Ensure null termination
            usernames[userCount][MAX_USERNAME_LENGTH - 1] = '\0';
            ids[userCount][MAX_ID_LENGTH - 1] = '\0';
            passwords[userCount][MAX_PASSWORD_LENGTH - 1] = '\0';
            
            userCount++;
        }
    }

    fclose(file);
    printf("\nDebug: Loaded %d users from file\n", userCount);
    return 1;
}

// Function to save all users to file
int saveUsers() {
    FILE *file = fopen(DATA_FILE, "w");  // Open in write mode to overwrite entire file
    if (file == NULL) {
        printf("Error: Unable to open file for writing!\n");
        return 0;
    }

    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s,%s,%s,%d,%d\n",
                usernames[i],
                ids[i],
                passwords[i],
                roles[i],
                specificRoles[i]);
    }

    printf("\nDebug: Saved %d users to file\n", userCount);
    fclose(file);
    return 1;
}

// Function to check if username already exists
int usernameExists(const char *username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(usernames[i], username) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to check if ID already exists
int idExists(const char *id) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(ids[i], id) == 0) {
            return 1;
        }
    }
    return 0;
}

// Complete signup function
int signup() {
    char tempUsername[256], tempId[256], tempPassword[256];
    int validInput = 0;
    char choice;
    
    do {
        system("cls");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
        printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("\t\t\t\t\t  [] >>====================<< []\n");
        printf("\t\t\t\t\t  [] >>       SIGN UP      << []\n");
        printf("\t\t\t\t\t  [] >>====================<< []\n");
        printf("\n\n");

        // Username input
        printf("\t\t\t >>  Enter username: ");
        // Clear input buffer before getting username
        fflush(stdin);
        if (fgets(tempUsername, sizeof(tempUsername), stdin) != NULL) {
            size_t len = strlen(tempUsername);
            if (len > 0 && tempUsername[len-1] == '\n') {
                tempUsername[len-1] = '\0';
                len--;
            }
            if (len >= MAX_USERNAME_LENGTH) {
                printf("\n\t\t\t >>  Error: Username is too long. Maximum length is %d characters.\n", MAX_USERNAME_LENGTH - 1);
                printf("\n\t\t\t >>  Press any key to try again...");
                getch();
                continue;
            }
            
            // Check if username already exists
            if (usernameExists(tempUsername)) {
                printf("\n\t\t\t >>  Error: Username already exists.\n");
                printf("\n\t\t\t >>  Press any key to try again...");
                getch();
                continue;
            }
        }

        // ID input
        printf("\n\t\t\t >>  Enter user ID number (max 15 digits): ");
        if (fgets(tempId, sizeof(tempId), stdin) != NULL) {
            size_t len = strlen(tempId);
            if (len > 0 && tempId[len-1] == '\n') {
                tempId[len-1] = '\0';
                len--;
            }
            
            if (len > 15) {
                printf("\n\t\t\t >>  Error: ID number must not exceed 15 digits.\n");
                printf("\n\t\t\t >>  Press any key to try again...");
                getch();
                continue;
            }
            
            int isValid = 1;
            for (int i = 0; i < len; i++) {
                if (!isdigit(tempId[i])) {
                    isValid = 0;
                    break;
                }
            }
            
            if (!isValid) {
                printf("\n\t\t\t >>  Error: ID must contain only digits.\n");
                printf("\n\t\t\t >>  Press any key to try again...");
                getch();
                continue;
            }
            
            // Check if ID already exists
            if (idExists(tempId)) {
                printf("\n\t\t\t >>  Error: ID already exists.\n");
                printf("\n\t\t\t >>  Press any key to try again...");
                getch();
                continue;
            }
        }

        // Password input
        printf("\n\t\t\t >>  Enter password: ");
        if (fgets(tempPassword, sizeof(tempPassword), stdin) != NULL) {
            size_t len = strlen(tempPassword);
            if (len > 0 && tempPassword[len-1] == '\n') {
                tempPassword[len-1] = '\0';
                len--;
            }
            
            if (len < 6) {
                printf("\n\t\t\t >>  Error: Password must be at least 6 characters long.\n");
                printf("\n\t\t\t >>  Press any key to try again...");
                getch();
                continue;
            }
        }

        // Role selection
        system("cls");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
        printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n\n");

        int selectedRole = -1;
        int selectedSpecificRole = -1;

        do {
            printf("\t\t\t\t\t  >>  Choose your occupation: <<  \n");
            printf("\n");
            printf("\t\t\t\t\t  [] >>====================<< []\n");
            printf("\t\t\t\t\t  || (1) Student   (2) Admin  || \n");
            printf("\t\t\t\t\t  [] >>====================<< []\n");
            
            choice = getch();
            
            if (choice == '1') {
                selectedRole = STUDENT;
                selectedSpecificRole = 0; // No specific role for students
            } else if (choice == '2') {
                selectedRole = ADMIN;
                
                printf("\n");
                printf("\t\t\t\t      >>  Choose your specific occupation: <<  \n");
                printf("\n");
                printf("\t\t\t\t[] >>=========================================<< []\n");
                printf("\t\t\t\t|| (1) Teacher  (2) Administrator  (3) Registrar || \n");
                printf("\t\t\t\t[] >>=========================================<< []\n");
                
                char specificChoice = getch();
                
                if (specificChoice == '1') {
                    selectedSpecificRole = TEACHER;
                } else if (specificChoice == '2') {
                    selectedSpecificRole = ADMINISTRATOR;
                } else if (specificChoice == '3') {
                    selectedSpecificRole = REGISTRAR;
                } else {
                    selectedRole = -1;  // Invalid choice
                }
            }
        } while (selectedRole == -1);

        // Display confirmation
        system("cls");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
        printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("\t\t\t\t\t  [] >>====================<< []\n");
        printf("\t\t\t\t\t  [] >>    CONFIRM INFO    << []\n");
        printf("\t\t\t\t\t  [] >>====================<< []\n");
        printf("\n\n");
        printf("\t\t\t >>  Username: %s\n", tempUsername);
        printf("\t\t\t >>  User ID: %s\n", tempId);
        printf("\t\t\t >>  Password: %s\n", tempPassword);
        printf("\t\t\t >>  Role: %s\n", selectedRole == STUDENT ? "Student" : "Admin");
        if (selectedRole == ADMIN) {
            printf("\t\t\t >>  Specific Role: %s\n", 
                selectedSpecificRole == TEACHER ? "Teacher" : 
                selectedSpecificRole == ADMINISTRATOR ? "Administrator" : "Registrar");
        }
        printf("\n\t\t\t >>  Is this information correct? (Y/N): ");
        
        choice = getch();
        if (toupper(choice) == 'Y') {
            // Check if we have space for new user
            if (userCount >= MAX_USERS) {
                printf("\n\t\t\t >>  Error: Maximum number of users reached.\n");
                printf("\n\t\t\t >>  Press any key to continue...");
                getch();
                return 0;
            }
            
            // Save the information to arrays
            strncpy(usernames[userCount], tempUsername, MAX_USERNAME_LENGTH - 1);
            strncpy(ids[userCount], tempId, MAX_ID_LENGTH - 1);
            strncpy(passwords[userCount], tempPassword, MAX_PASSWORD_LENGTH - 1);
            roles[userCount] = selectedRole;
            specificRoles[userCount] = selectedSpecificRole;
            
            // Ensure null termination
            usernames[userCount][MAX_USERNAME_LENGTH - 1] = '\0';
            ids[userCount][MAX_ID_LENGTH - 1] = '\0';
            passwords[userCount][MAX_PASSWORD_LENGTH - 1] = '\0';
            
            userCount++;
            
            // Save all users to file
            if (!saveUsers()) {
                printf("\n\t\t\t >>  Error: Could not save user data.\n");
                printf("\n\t\t\t >>  Press any key to continue...");
                getch();
                return 0;
            }
            
            validInput = 1;

            system("cls");
            printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
            printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
            printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\n");
            printf("\t\t\t\t\t  [] >>====================<< []\n");
            printf("\t\t\t\t\t  [] >>REGISTRATION SUCCESS<< []\n");
            printf("\t\t\t\t\t  [] >>====================<< []\n");
            printf("\n");
            printf("\t\t\t >>  Press any key to continue...");
            getch();
            system("cls");
        }
    } while (!validInput);

    return 1;
}

int saveEOGRequest(const char* requestType, const char* studentID, const char* purpose, const char* requestDate, const char* additionalNotes) {
    FILE *file;
    char filename[50];
    
    if (strcmp(requestType, "Certification") == 0) {
        strcpy(filename, "certification_requests.txt");
    } else {
        strcpy(filename, "clearance_requests.txt");
    }
    
    file = fopen(filename, "a");
    if (file == NULL) {
        printf("\t\t\t Error saving request!\n");
        return -1;
    }
    
    fprintf(file, "Request Type: %s\n", requestType);
    fprintf(file, "Student ID: %s", studentID);
    fprintf(file, "Purpose: %s", purpose);
    fprintf(file, "Request Date: %s", requestDate);
    fprintf(file, "Additional Notes: %s", additionalNotes);
    fprintf(file, "Status: Pending\n\n");
    
    fclose(file);
    return 0;
}

int viewEnrollees(const char* courseFile) {
    FILE* file = fopen(courseFile, "r");
    char line[256];
    int studentCount = 0;

    if (file == NULL) {
        printf("\t\t\tNo enrollees found for this course.\n");
        return -1;
    }

    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||          ENROLLED STUDENTS           ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n");
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;
        
        if (strstr(line, "Name:") != NULL) {
            studentCount++;
            printf("\n\t\t\tStudent %d:\n", studentCount);
        }
        printf("\t\t\t%s\n", line);
    }
    
    printf("\n\t\t\tTotal Students: %d\n", studentCount);
    fclose(file);
    return studentCount;
}

int deleteEnrollee(const char* courseFile, const char* nameToDelete) {
    FILE* file = fopen(courseFile, "r");
    FILE* tempFile = fopen("temp.txt", "w");
    char line[256];
    int deletingStudent = 0;
    int found = 0;
    
    if (file == NULL || tempFile == NULL) {
        if (file) fclose(file);
        if (tempFile) fclose(tempFile);
        printf("\t\t\tError accessing files.\n");
        return -1;
    }

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Name:") != NULL) {
            char currentName[100];
            sscanf(line + 6, "%[^\n]", currentName);
            
            if (strcmp(currentName, nameToDelete) == 0) {
                deletingStudent = 1;
                found = 1;
                continue;
            } else {
                deletingStudent = 0;
            }
        }
        
        if (!deletingStudent) {
            fputs(line, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        if (remove(courseFile) == 0 && rename("temp.txt", courseFile) == 0) {
            printf("\t\t\tStudent successfully removed.\n");
            return 1;
        } else {
            printf("\t\t\tError updating the file.\n");
            return -1;
        }
    } else {
        remove("temp.txt");
        printf("\t\t\tStudent not found.\n");
        return 0;
    }
}

int studentMenu() {
    int choice;
    char x=219;
    
    printf("\n\n\n\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||          >> STUDENT MENU <<          ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||     PROGRAM LOADING IS IN PROCESS    ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||            PLEASE WAIT...            ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");    
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t");
    
    printf("\n\n");
    printf("\n\t\t\t\t\t");
    for(int i=1; i<=30; i++)
    {
        green();
        cerr<<x;
        usleep(99999);
    }
    system("cls");
    
menu:
    printf("\n");
    printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
    printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
    printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\t\t\t\t     [] Philtech School Management System []\n");
    printf("\t\t\t\t     [][]  Choose what you want to use  [][]\n");
    printf("\n\n");
    printf("\t\t\t\t\t > [1] Enrollment           [1]\n");
    printf("\t\t\t\t\t > [2] View Subject List    [2]\n");
    printf("\t\t\t\t\t > [3] Request EOG          [3]\n");
    printf("\t\t\t\t\t > [4] About Us             [4]\n");
    printf("\t\t\t\t\t > [5] Log out              [5]\n");
    printf("\n\n\n");
    printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t  |=||==||==||  PRESS THE NUMBER YOU WANT TO CHECK  ||==||==||=|\n");
    printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n");
    choice = getch();
    system("cls");

if (choice == '1') {
    enrollmentForm:
    char name[100], address[100], email[100], contact[100];
    int age, courseChoice, editChoice;
    char confirm;

input_details:
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||            ENROLLMENT FORM           ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\n");
    
    // Name validation
    do {
        printf("\t\t\t Name (2-99 characters): ");
        scanf(" %[^\n]", name);
        if (strlen(name) < 2 || strlen(name) >= 100) {
            printf("\t\t\t Invalid name length. Please enter between 2 and 99 characters.\n");
            continue;
        }
        break;
    } while (1);

    // Age validation
    do {
        printf("\t\t\t Age (16-80): ");
        if (scanf("%d", &age) != 1) {
            printf("\t\t\t Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        if (age < 16 || age > 80) {
            printf("\t\t\t Age must be between 16 and 80.\n");
            continue;
        }
        break;
    } while (1);

    // Address validation
    do {
        printf("\t\t\t Address (5-99 characters): ");
        scanf(" %[^\n]", address);
        if (strlen(address) < 5 || strlen(address) >= 100) {
            printf("\t\t\t Invalid address length. Please enter between 5 and 99 characters.\n");
            continue;
        }
        break;
    } while (1);

    // Email validation
    do {
        int atCount = 0, dotCount = 0;
        printf("\t\t\t Email: ");
        scanf(" %[^\n]", email);
        
        // Check email length
        if (strlen(email) < 5) {
            printf("\t\t\t Email is too short. Please enter a valid email.\n");
            continue;
        }
        
        // Count @ and . symbols
        for (int i = 0; i < strlen(email); i++) {
            if (email[i] == '@') atCount++;
            if (email[i] == '.') dotCount++;
        }
        
        if (atCount != 1 || dotCount < 1) {
            printf("\t\t\t Invalid email format. Please use format: example@domain.com\n");
            continue;
        }
        break;
    } while (1);

    // Contact validation
    do {
        int validDigits = 1;
        printf("\t\t\t Contact (11 digits): ");
        scanf(" %[^\n]", contact);
        
        // Check length
        if (strlen(contact) != 11) {
            printf("\t\t\t Contact must be exactly 11 digits.\n");
            continue;
        }
        
        // Check if all characters are digits
        for (int i = 0; i < strlen(contact); i++) {
            if (!isdigit(contact[i])) {
                validDigits = 0;
                break;
            }
        }
        
        if (!validDigits) {
            printf("\t\t\t Contact must contain only digits.\n");
            continue;
        }
        break;
    } while (1);

    // Course choice validation
    do {
        printf("\t\t\t Select Course (1-3): \n");
        printf("\t\t\t 1. BSCS\n");
        printf("\t\t\t 2. BTVTLED\n");
        printf("\t\t\t 3. EDUC\n");
        if (scanf("%d", &courseChoice) != 1) {
            printf("\t\t\t Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        if (courseChoice < 1 || courseChoice > 3) {
            printf("\t\t\t Invalid choice. Please select 1-3.\n");
            continue;
        }
        break;
    } while (1);
    
    system("cls");

    // Display collected information
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||     COLLECTED ENROLLMENT  DETAILS    ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\n");
    printf("\t\t\t Name: %s\n", name);
    printf("\t\t\t Age: %d\n", age);
    printf("\t\t\t Address: %s\n", address);
    printf("\t\t\t Email: %s\n", email);
    printf("\t\t\t Contact: %s\n", contact);
    printf("\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");
    printf("\n\t\t\t Is the information correct? (y/n): ");
    scanf(" %c", &confirm);
    system("cls");
    
loopconfirmation:
    if (confirm == 'n' || confirm == 'N') {
        system("cls");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||             ENROLLMENT FORM          ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n\n");
        printf("\t\t\t What would you like to edit? (1-6)\n");
        printf("\t\t\t 1. Name\n");
        printf("\t\t\t 2. Age\n");
        printf("\t\t\t 3. Address\n");
        printf("\t\t\t 4. Email\n");
        printf("\t\t\t 5. Contact\n");
        printf("\t\t\t 6. Course\n");
        printf("\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");
        
        // Edit choice validation
        do {
            if (scanf("%d", &editChoice) != 1) {
                printf("\t\t\t Invalid input. Please enter a number (1-6): ");
                while (getchar() != '\n'); // Clear input buffer
                continue;
            }
            if (editChoice < 1 || editChoice > 6) {
                printf("\t\t\t Invalid choice. Please select 1-6: ");
                continue;
            }
            break;
        } while (1);
        
        getchar();
        system("cls");

        switch (editChoice) {
            case 1:
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||             ENROLLMENT FORM          ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\n\n");
                do {
                    printf("\t\t\t Enter new name (2-99 characters): ");
                    scanf(" %[^\n]", name);
                    if (strlen(name) < 2 || strlen(name) >= 100) {
                        printf("\t\t\t Invalid name length. Please enter between 2 and 99 characters.\n");
                        continue;
                    }
                    break;
                } while (1);
                break;
            case 2:
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||             ENROLLMENT FORM          ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\n\n");
                do {
                    printf("\t\t\t Enter new age (16-80): ");
                    if (scanf("%d", &age) != 1) {
                        printf("\t\t\t Invalid input. Please enter a number.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (age < 16 || age > 80) {
                        printf("\t\t\t Age must be between 16 and 80.\n");
                        continue;
                    }
                    break;
                } while (1);
                break;
            case 3:
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||             ENROLLMENT FORM          ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\n\n");
                do {
                    printf("\t\t\t Enter new address (5-99 characters): ");
                    scanf(" %[^\n]", address);
                    if (strlen(address) < 5 || strlen(address) >= 100) {
                        printf("\t\t\t Invalid address length. Please enter between 5 and 99 characters.\n");
                        continue;
                    }
                    break;
                } while (1);
                break;
            case 4:
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||             ENROLLMENT FORM          ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\n\n");
                do {
                    int atCount = 0, dotCount = 0;
                    printf("\t\t\t Enter new email: ");
                    scanf(" %[^\n]", email);
                    
                    if (strlen(email) < 5) {
                        printf("\t\t\t Email is too short. Please enter a valid email.\n");
                        continue;
                    }
                    
                    for (int i = 0; i < strlen(email); i++) {
                        if (email[i] == '@') atCount++;
                        if (email[i] == '.') dotCount++;
                    }
                    
                    if (atCount != 1 || dotCount < 1) {
                        printf("\t\t\t Invalid email format. Please use format: example@domain.com\n");
                        continue;
                    }
                    break;
                } while (1);
                break;
            case 5:
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||             ENROLLMENT FORM          ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\n\n");
                do {
                    int validDigits = 1;
                    printf("\t\t\t Enter new contact (11 digits): ");
                    scanf(" %[^\n]", contact);
                    
                    if (strlen(contact) != 11) {
                        printf("\t\t\t Contact must be exactly 11 digits.\n");
                        continue;
                    }
                    
                    for (int i = 0; i < strlen(contact); i++) {
                        if (!isdigit(contact[i])) {
                            validDigits = 0;
                            break;
                        }
                    }
                    
                    if (!validDigits) {
                        printf("\t\t\t Contact must contain only digits.\n");
                        continue;
                    }
                    break;
                } while (1);
                break;
            case 6:
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||             ENROLLMENT FORM          ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\n\n");
                do {
                    printf("\t\t\t Select new course (1-3): \n");
                    printf("\t\t\t 1. BSCS\n");
                    printf("\t\t\t 2. BTVTLED\n");
                    printf("\t\t\t 3. EDUC\n");
                    if (scanf("%d", &courseChoice) != 1) {
                        printf("\t\t\t Invalid input. Please enter a number.\n");
                        while (getchar() != '\n');
                        continue;
                    }
                    if (courseChoice < 1 || courseChoice > 3) {
                        printf("\t\t\t Invalid choice. Please select 1-3.\n");
                        continue;
                    }
                    break;
                } while (1);
                break;
            default:
                printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t|=||==||==||            Invalid choice!           ||==||==||=|\n");
                printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        
        system("cls");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||     COLLECTED ENROLLMENT  DETAILS    ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n\n");
        printf("\t\t\t Name: %s\n", name);
        printf("\t\t\t Age: %d\n", age);
        printf("\t\t\t Address: %s\n", address);
        printf("\t\t\t Email: %s\n", email);
        printf("\t\t\t Contact: %s\n", contact);
        printf("\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n\t\t\t Is the information correct? (y/n): ");
        scanf(" %c", &confirm);
    
        if (confirm == 'n' || confirm == 'N') {
            goto loopconfirmation;
        }
    }

    // File handling with error checking
    FILE *file;
    char courseFile[100];

    switch (courseChoice) {
        case 1:
            strcpy(courseFile, "bscs_enrollees.txt");
            break;
        case 2:
            strcpy(courseFile, "btvtled_enrollees.txt");
            break;
        case 3:
            strcpy(courseFile, "educ_enrollees.txt");
            break;
        default:
            printf("Invalid course choice.\n");
            goto menu;
    }

    file = fopen(courseFile, "a");
    if (file == NULL) {
        printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t|=||==||==||    Error: Unable to save enrollment    ||==||==||=|\n");
        printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t Press any key to continue...");
        getch();
        system("cls");
        goto menu;
    }
    
    system("cls");

    // Write to file with error checking
    if (fprintf(file, "Name: %s\n", name) < 0 ||
        fprintf(file, "Age: %d\n", age) < 0 ||
        fprintf(file, "Address: %s\n", address) < 0 ||
        fprintf(file, "Email: %s\n", email) < 0 ||
        fprintf(file, "Contact: %s\n\n", contact) < 0) {
        
        fclose(file);
        printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t|=||==||==||    Error: Failed to write to file     ||==||==||=|\n");
        printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t Press any key to continue...");
        getch();
        system("cls");
        goto menu;
    }

    fclose(file);
    printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t|=||==||      Enrollment data has been submitted.     ||==||=|\n");
    printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t Press any key to continue...");
    getch();
    system("cls");
    goto menu;  // Return to student menu after enrollment
}

else if (choice == '2') {
    char x = 219;
    printf("\n\n\n\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||        CLASSROOM  MANAGEMENT         ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t LOADING...\n\n");
    printf("\t\t\t\t");
    
    for(int i=1; i<=30; i++) {
        green();
        cerr<<x;
        usleep(99999);
    }
    system("cls");

    while(1) {
        printf("\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||        CLASSROOM  MANAGEMENT         ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("\t\t\t Choose a teacher:\n\n");
        printf("\t\t\t [1] Allan Vele       - Understanding the Self (Ge1)\n");
        printf("\t\t\t [2] Jude Rodriguez   - Mathematics in Modern World (Ge2)\n");
        printf("\t\t\t [3] Nori Lacerna     - Readings in Phil. History (Ge3)\n");
        printf("\t\t\t [4] Raiven Gordon    - Intro to Computing (Cc111)\n");
        printf("\t\t\t [5] Carl Jimenez     - Fund. of Programming 1 (Cc112)\n");
        printf("\t\t\t [6] Michael Atienza  - PATHFIT1/NSTP1/PLS\n");
        printf("\t\t\t [7] Return to menu\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t Press the corresponding number (1-7): ");

        char teacherChoice = getch();
        system("cls");

        if(teacherChoice == '1') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Allan Velle\n");
            printf("\t\t\t Schedule: Saturday 7:00 am - 10:00 am\n");
            printf("\t\t\t Subject: Understanding the Self (Ge1)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '2') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Jude Rodriguez\n");
            printf("\t\t\t Schedule: Saturday 10:00 am - 1:00 pm\n");
            printf("\t\t\t Subject: Mathematics in the Modern World (Ge2)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '3') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Nori Lacerna\n");
            printf("\t\t\t Schedule: Saturday 1:00 pm - 4:00 pm\n");
            printf("\t\t\t Subject: Readings in Philippines History (Ge3)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '4') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Raiven Gordon\n");
            printf("\t\t\t Schedule: Monday 9:00 am - 2:00 pm\n");
            printf("\t\t\t Subject: Introduction to Computing (Cc111)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '5') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Carl Joseph Jimenez\n");
            printf("\t\t\t Schedule: Thursday 7:00 am - 12:00 pm\n");
            printf("\t\t\t Subject: Fundamentals of Programming 1 (Cc112)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '6') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Michael Atienza\n");
            printf("\t\t\t Schedule:\n");
            printf("\t\t\t Tuesday 7:00 am - 8:45 am: PATHFIT1\n");
            printf("\t\t\t Wednesday 9:00 am - 12:00 pm: NSTP1\n");
            printf("\t\t\t Wednesday 12:00 pm - 1:00 pm: PLS\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '7') {
            system("cls");
            goto menu;
        }

        printf("\n\t\t\t Press 'B' to go back or any other key to return to menu: ");
        char backChoice = getch();
        system("cls");
        
        if(backChoice != 'b' && backChoice != 'B') {
            goto menu;
        }
    }
}

else if (choice == '3') {
    // EOG Request (Certification/Clearance)
    int eogChoice;
    char studentID[50];
    char purpose[100];
    char requestDate[20];
    char additionalNotes[200];
    char decision;
    
    // Loading animation
    char x = 219;
    printf("\n\n\n\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||           EOG REQUEST FORM           ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t LOADING...\n\n");
    printf("\t\t\t\t");
    
    for(int i=1; i<=30; i++) {
        green();
        cerr<<x;
        usleep(99999);
    }
    system("cls");
    
    printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t|=||==||==||         EOG Request Options         ||==||==||=|\n");
    printf("\t\t\t|=||                                                      ||=|\n");
    printf("\t\t\t|                   1. Certification                        |\n");
    printf("\t\t\t|                   2. Clearance                           |\n");
    printf("\t\t\t|=||                                                      ||=|\n");
    printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    
    eogChoice = getch();
    system("cls");
    while(getchar() != '\n');
    
    if(eogChoice != '1' && eogChoice != '2') {
        printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t|=||==||==||      Invalid choice! Please select 1 or 2   ||==||==||=|\n");
        printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        return 0;
    }

    if(eogChoice == '1') {
        Certification:
        printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t|=||==||==||        Certification Request        ||==||==||=|\n");
        printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");
        
        printf("\t\t\tEnter Student ID Number: ");
        if (!fgets(studentID, sizeof(studentID), stdin)) {
            printf("Error reading input!\n");
            goto Certification;
        }

        printf("\t\t\tEnter Purpose (e.g., Job application, transfer): ");
        if (!fgets(purpose, sizeof(purpose), stdin)) {
            printf("Error reading input!\n");
            goto Certification;
        }

        printf("\t\t\tEnter Request Date (YYYY-MM-DD): ");
        if (!fgets(requestDate, sizeof(requestDate), stdin)) {
            printf("Error reading input!\n");
            goto Certification;
        }

        printf("\t\t\tEnter Additional Notes (e.g., Urgency, preferred format): ");
        if (!fgets(additionalNotes, sizeof(additionalNotes), stdin)) {
            printf("Error reading input!\n");
            goto Certification;
        }

        printf("\n\t\t\tIs the information correct? (Y/N): ");
        decision = getch();
        system("cls");

        if (decision == 'Y' || decision == 'y') {
            // Save certification request to file
            if (saveEOGRequest("Certification", studentID, purpose, requestDate, additionalNotes) == 0) {
                printf("\n\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t|=||==||==||     Request Successfully Submitted    ||==||==||=|\n");
                printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");
                printf("\t\t\tRequest Type: Certification\n");
                printf("\t\t\tStudent ID Number: %s", studentID);
                printf("\t\t\tPurpose: %s", purpose);
                printf("\t\t\tRequest Date: %s", requestDate);
                printf("\t\t\tAdditional Notes: %s", additionalNotes);
                printf("\n\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\tPress any key to return to menu");
                getch();
                system("cls");
                goto menu;
            } else {
                printf("\t\t\tError saving request! Please try again.\n");
                goto Certification;
            }
        }
        else if (decision == 'N' || decision == 'n') {
            goto Certification;
        }
        else {
            printf("\t\t\tInvalid input! Please enter Y or N.\n");
            goto Certification;
        }
    }
    
    if(eogChoice == '2') {
        Clearance:
        printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t|=||==||==||         Clearance Request          ||==||==||=|\n");
        printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");
        
        printf("\t\t\tEnter Student ID Number: ");
        if (!fgets(studentID, sizeof(studentID), stdin)) {
            printf("Error reading input!\n");
            goto Clearance;
        }

        printf("\t\t\tEnter Purpose (e.g., Job application, transfer): ");
        if (!fgets(purpose, sizeof(purpose), stdin)) {
            printf("Error reading input!\n");
            goto Clearance;
        }

        printf("\t\t\tEnter Request Date (YYYY-MM-DD): ");
        if (!fgets(requestDate, sizeof(requestDate), stdin)) {
            printf("Error reading input!\n");
            goto Clearance;
        }

        printf("\t\t\tEnter Additional Notes (e.g., Urgency, preferred format): ");
        if (!fgets(additionalNotes, sizeof(additionalNotes), stdin)) {
            printf("Error reading input!\n");
            goto Clearance;
        }

        printf("\n\t\t\tIs the information correct? (Y/N): ");
        decision = getch();
        system("cls");

        if (decision == 'Y' || decision == 'y') {
            // Save clearance request to file
            if (saveEOGRequest("Clearance", studentID, purpose, requestDate, additionalNotes) == 0) {
                printf("\n\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t|=||==||==||     Request Successfully Submitted    ||==||==||=|\n");
                printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");
                printf("\t\t\tRequest Type: Clearance\n");
                printf("\t\t\tStudent ID Number: %s", studentID);
                printf("\t\t\tPurpose: %s", purpose);
                printf("\t\t\tRequest Date: %s", requestDate);
                printf("\t\t\tAdditional Notes: %s", additionalNotes);
                printf("\n\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\tPress any key to return to menu");
                getch();
                system("cls");
                goto menu;
            } else {
                printf("\t\t\tError saving request! Please try again.\n");
                goto Clearance;
            }
        }
        else if (decision == 'N' || decision == 'n') {
            goto Clearance;
        }
        else {
            printf("\t\t\tInvalid input! Please enter Y or N.\n");
            goto Clearance;
        }
    }
    
    return 0;
}


else if (choice == '4') {
	about:
        int about;
		printf("\n\n\n");
		printf("\t\t\t\t\t  [] >>====================<< []\n");
		printf("\t\t\t\t\t  [] >>    PHILTECH-GMA    << []\n");
		printf("\t\t\t\t\t  [] >>====================<< []\n");
		printf("\n");
		printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\t\t\t [][]                                                        [][]\n");
		printf("\t\t\t [][]          Philippine Technological Institute of         [][]\n");
		printf("\t\t\t [][]         Science, Arts, and Trade - Central INC.        [][]\n");
		printf("\t\t\t [][]                 2nd Flr. CRDM Building,                [][]\n");
    	printf("\t\t\t [][]          Congressional Road, Cor. Gov. Drive,          [][]\n");
    	printf("\t\t\t [][]             Brgy. G. Maderan, GMA, Cavite              [][]\n");
    	printf("\t\t\t [][]                                                        [][]\n");
    	printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    	printf("\n\n");
    	printf("\t\t\t\t\t     [1] About Senior High [1]\n");
    	printf("\t\t\t\t\t     [2]   About College   [2]\n");
    	printf("\n");
    	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\t\t\t  |=||==||==||  PRESS THE NUMBER YOU WANT TO CHECK  ||==||==||=|\n");
		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\n\n");
		printf(" * PRESSING OTHER KEY RETURNS TO MENU:\t\t\t\t\t\t\t\t   (P) Contact Info");
		about = getch();
		system ("cls");
		
		if (about == '1'){
			int sh;
			printf("\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\t\t\t\t\t  [] >>     SENIOR HIGH    << []\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\n");
    		printf("\t\t\t\t\t    SHS160S.2016/SHS-206S.2017\n");
    		printf("\n");
			printf("\t\t\t\t   #### ####  ###### #####     * Tuition Fee            \n");
	 		printf("\t\t\t\t   #    #   # #      #                                  \n");
	 		printf("\t\t\t\t   ###  ####  ####   ####      * Laboratory Fee         \n");
	 		printf("\t\t\t\t   #    #  #  #      #                                  \n");
			printf("\t\t\t\t   #    #   # ###### #####     * Miscellaneous Fee      \n");
			printf("\n");
   		 	printf("\t\t\t\t   Includes:\n");
   			printf("\t\t\t\t          - 1 Set of School Uniform\n");
		    printf("\t\t\t\t          - 1 SHS T-Shirt\n");
		    printf("\t\t\t\t          - 1 Set of PE Uniform\n");
		    printf("\t\t\t\t          - ID with Holder\n\n");
		    printf("\t\t\t\t   ACADEMIC TRACK\n");
		    printf("\t\t\t\t          - Humanities and Social Science\n");
		    printf("\t\t\t\t          - Accountancy, Business, and Management\n");
		    printf("\t\t\t\t          - General Academics\n\n");
	 	  	printf("\t\t\t\t   TECHNICAL VOCATIONAL LIVELIHOOD TRACK\n");
			printf("\t\t\t\t          - Information and Communications Technology\n");
		    printf("\t\t\t\t          - Home Economics\n\n");
		    printf("\t(X) MENU\t\t\t\t\t\t\t\t\t\t(ANY KEY) RETURN");
		    sh = getch();
		    system ("cls");
		    
		    if (sh == 'x' || sh == 'X'){
				goto menu;
			}
			if (sh != '0'){
				goto about;
			}
		}
		if (about == '2'){
			int cg;
			printf("\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\t\t\t\t\t  [] >>       COLLEGE      << []\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\n");
    		printf("\t\t\t\t\t     50%% DISCOUNT IN TUITION\n");
    		printf("\n");
		    printf("\t\t\t\t   Courses Offered:\n");
		    printf("\t\t\t\t      - Bachelor of Technical Vocational\n");
		    printf("\t\t\t\t        Teacher Education (BTVTEd)\n");
		    printf("\t\t\t\t      - Major in Food and Service Management\n");
	 	  	printf("\t\t\t\t         CHED Permit No. 048 Series 2021\n\n");
			printf("\t\t\t\t      - Bachelor of Science in Computer Science (BSCS)\n");
		    printf("\t\t\t\t         CHED Permit No. 035 Series 2022\n\n");
		    printf("\t\t\t\t      - Bachelor of Science in Office Administration (BSOA)\n");
		    printf("\t\t\t\t         CHED Permit No. 033 Series 2022\n\n");
		    printf("\t\t\t\t   Upcoming Courses:\n");
		    printf("\t\t\t\t      - Bachelor of Science in Psychology\n");
		    printf("\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\t\t\t\t\t  [] >>    SUNDAY CLASS    << []\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\n");
			printf("\t\t\t\t\t     50%% DISCOUNT IN TUITION\n");
    		printf("\n");
		    printf("\t\t\t\t   Courses Available:\n");
		    printf("\t\t\t\t      - Bachelor of Technical Vocational\n");
		    printf("\t\t\t\t        Teacher Education (BTVTEd)\n");
		    printf("\t\t\t\t      - Major in Food and Service Management\n");
			printf("\t\t\t\t      - Bachelor of Science in Computer Science (BSCS)\n");
		    printf("\t\t\t\t      - Bachelor of Science in Office Administration (BSOA)\n");
		    printf("\n");
		    printf("\t(X) MENU\t\t\t\t\t\t\t\t\t\t(ANY KEY) RETURN");
		    cg = getch();
		    system ("cls");
		    if (cg == 'x' || cg == 'X'){
				goto menu;
			}
			if (cg != '0'){
				goto about;
			}
		}
		if (about == 'p' || about == 'P'){
			int ci;
			printf("\n\n\n\n\n");
			printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
			printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
			printf("\t\t\t|=||==||==||          CONTACT INFORMATION         ||==||==||=|\n");
			printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
			printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
			printf("\n\n\n");
			printf("\t\t\t\t   Tel: (046) 409-94-90\n");
			printf("\t\t\t\t   Globe Mobile: 0955-135-4698\n");
			printf("\n");
			printf("\t\t\t\t   Social Media:\n");
			printf("\t\t\t\t   Facebook Page: Philtech GMA\n");
			printf("\t\t\t\t   Instagram: philtechgma\n");
			printf("\t\t\t\t   YouTube: Philtech GMA\n");
			printf("\n\n\n\n\n\n");
			printf("\t(X) MENU\t\t\t\t\t\t\t\t\t\t(ANY KEY) RETURN");
			
			ci = getch();
			system("cls");
			if (ci == 'x' || ci == 'X'){
				goto menu;
			}
			if (ci != '0'){
				goto about;
			}
			
			
		}
		if (about != '0'){
			goto menu;
		}
    }
    
else if (choice == '5') {
        printf("\n\n\n\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t |=||==||==||          Account logging off         ||==||==||=|\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t |=||==||==||            PLEASE WAIT...            ||==||==||=|\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");    
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n\n");
        printf("\t\t\t\t\t\t");
        
        printf("\n\n");
        printf("\n\t\t\t\t\t");
        for(int i=1; i<=30; i++)
        {
            green();
            cerr<<x;
            usleep(99999);
        }
        system("cls");
        return 0;
    }
    else {
        system("cls");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t  |=||     Error, Please choose from the choices below.     ||=|\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        goto menu;
    }
    return 0;
}

int teacherMenu(){
    char x=219;
    printf("\n\n\n\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||         >> TEACHERS MENU <<          ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||     PROGRAM LOADING IS IN PROCESS    ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||            PLEASE WAIT...            ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");    
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t");
    
    printf("\n\n");
    printf("\n\t\t\t\t\t");
    for(int i=1; i<=30; i++)
    {
        green();
        cerr<<x;
        usleep(99999);
    }
    system("cls");
    
menu:
    printf("\n");
    printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
    printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
    printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\t\t\t\t     [] Philtech School Management System []\n");
    printf("\t\t\t\t     [][]  Choose what you want to use  [][]\n");
    printf("\n\n");
    printf("\t\t\t\t\t > [1] Classroom Management [1]\n");
    printf("\t\t\t\t\t > [2] Mark  Attendance     [2]\n");
    printf("\t\t\t\t\t > [3] View  Attendance     [3]\n");
    printf("\t\t\t\t\t > [4] About Us (Philtech)  [4]\n");
    printf("\t\t\t\t\t > [5] Log out              [5]\n");
    printf("\n\n\n");
    printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t  |=||==||==||  PRESS THE NUMBER YOU WANT TO CHECK  ||==||==||=|\n");
    printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n");
    choice = getch();
    system ("cls");

if (choice == '1'){
	
    char x = 219;
    printf("\n\n\n\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||        CLASSROOM  MANAGEMENT         ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t LOADING...\n\n");
    printf("\t\t\t\t");
    
    for(int i=1; i<=30; i++) {
        green();
        cerr<<x;
        usleep(99999);
    }
    system("cls");

    while(1) {
        printf("\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||        CLASSROOM  MANAGEMENT         ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("\t\t\t Choose a teacher:\n\n");
        printf("\t\t\t [1] Allan Vele       - Understanding the Self (Ge1)\n");
        printf("\t\t\t [2] Jude Rodriguez   - Mathematics in Modern World (Ge2)\n");
        printf("\t\t\t [3] Nori Lacerna     - Readings in Phil. History (Ge3)\n");
        printf("\t\t\t [4] Raiven Gordon    - Intro to Computing (Cc111)\n");
        printf("\t\t\t [5] Carl Jimenez     - Fund. of Programming 1 (Cc112)\n");
        printf("\t\t\t [6] Michael Atienza  - PATHFIT1/NSTP1/PLS\n");
        printf("\t\t\t [7] Return to menu\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t Press the corresponding number (1-7): ");

        char teacherChoice = getch();
        system("cls");

        if(teacherChoice == '1') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Allan Velle\n");
            printf("\t\t\t Schedule: Saturday 7:00 am - 10:00 am\n");
            printf("\t\t\t Subject: Understanding the Self (Ge1)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '2') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Jude Rodriguez\n");
            printf("\t\t\t Schedule: Saturday 10:00 am - 1:00 pm\n");
            printf("\t\t\t Subject: Mathematics in the Modern World (Ge2)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '3') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Nori Lacerna\n");
            printf("\t\t\t Schedule: Saturday 1:00 pm - 4:00 pm\n");
            printf("\t\t\t Subject: Readings in Philippines History (Ge3)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '4') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Raiven Gordon\n");
            printf("\t\t\t Schedule: Monday 9:00 am - 2:00 pm\n");
            printf("\t\t\t Subject: Introduction to Computing (Cc111)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '5') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Carl Joseph Jimenez\n");
            printf("\t\t\t Schedule: Thursday 7:00 am - 12:00 pm\n");
            printf("\t\t\t Subject: Fundamentals of Programming 1 (Cc112)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '6') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Michael Atienza\n");
            printf("\t\t\t Schedule:\n");
            printf("\t\t\t Tuesday 7:00 am - 8:45 am: PATHFIT1\n");
            printf("\t\t\t Wednesday 9:00 am - 12:00 pm: NSTP1\n");
            printf("\t\t\t Wednesday 12:00 pm - 1:00 pm: PLS\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '7') {
            system("cls");
            goto menu;
        }

    }
}
		
if (choice == '2') {
    char x = 219;
    printf("\n\n\n\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||         ATTENDANCE  MANAGEMENT       ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t LOADING...\n\n");
    printf("\t\t\t\t");
    
    for(int i=1; i<=30; i++) {
        green();
        cerr<<x;
        usleep(99999);
    }
    system("cls");

    int teacherChoice, subjectChoice;
    char status[10];
    int statusChoice, numStudents = 30;
    char continueEditing;
    char editAttendance;
    char attendanceDate[11];
    char attendance[30];
    
    const char* teachers[] = {
        "Atienza, Michael", "Jimenez, Carl Joseph", "Lacerna, Nori", 
        "Gordon, Raiven", "Rodriguez, Jude", "Vele, Allan"
    };
    
    const char* subjects[6][3] = {
        {"PATHFIT", "NSTP", "PLS"},
        {"CC112"},
        {"GE3"},
        {"CC111"},
        {"GE2"},
        {"GE1"}
    };

    char students[30][50] = {
        "Abella, Ghanda Mar", "Abrantes, Elijah", "Alcober, Emmanuel", 
        "Angcanan, Ezyquiel", "Aspi, Samantha L.", "Baghari, Chris Thiego", 
        "Balares, Dave", "Buenaventura, Harley", "Burdeos, Johnuel", 
        "Caballero, Jhavie Jybe", "Cornejo, Marlon", "Domingo, Handrich", 
        "Gallo, Stanley John", "Genodepa, Roselle", "Ignacio, Cristine", 
        "Laynes, Christian Edmar", "Magpayo, Arwin", "Mercado, Meagan E.", 
        "Mondigo, Danilo Jr", "Olegario, Jodale Christian", "Olimba, Angel Grace", 
        "Quitilen, Joey", "Reyes, Meljine", "Rosal, Chrizyrus", 
        "Rosal, Christian", "Sano, Nathan Carl", "Silva, Andrew John", 
        "Tongko, Rafael C.", "Tuyor, Aldrin S.", "Yabut, Lorenz"
    };
    
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    
    printf("\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||        ATTENDANCE  MANAGEMENT        ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");
    
    printf("\t\t\t Enter attendance date (MM/DD/YYYY) or press Enter for today's date\n");
    printf("\t\t\t (%02d/%02d/%04d): ", t->tm_mon + 1, t->tm_mday, t->tm_year + 1900);
           
    char dateInput[20];
    fgets(dateInput, sizeof(dateInput), stdin);
    if (dateInput[0] == '\n' || dateInput[0] == '\r') {
        sprintf(attendanceDate, "%02d/%02d/%04d", 
                t->tm_mon + 1, t->tm_mday, t->tm_year + 1900);
    } else {
        dateInput[strcspn(dateInput, "\n")] = 0;
        strcpy(attendanceDate, dateInput);
    }
    
    do {
        system("cls");
        printf("\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||        ATTENDANCE  MANAGEMENT        ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("\t\t\t Choose a teacher:\n\n");
        for (int i = 0; i < 6; i++) {
            printf("\t\t\t [%d] %s\n", i + 1, teachers[i]);
        }
        printf("\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t Enter your choice (1-6): ");
        
        while (1) {
            if (scanf("%d", &teacherChoice) == 1 && teacherChoice >= 1 && teacherChoice <= 6) {
                break;
            }
            while (getchar() != '\n');
            printf("\t\t\t Invalid input. Please enter a number between 1 and 6.\n");
            printf("\t\t\t Enter your choice (1-6): ");
        }
        
        system("cls");
        printf("\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||        ATTENDANCE  MANAGEMENT        ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("\t\t\t Teacher Selected: %s\n\n", teachers[teacherChoice - 1]);
        printf("\t\t\t Choose Subject:\n\n");
        
        int numSubjects = sizeof(subjects[teacherChoice - 1]) / sizeof(subjects[teacherChoice - 1][0]);
        for (int i = 0; i < numSubjects; i++) {
            printf("\t\t\t [%d] %s\n", i + 1, subjects[teacherChoice - 1][i]);
        }
        printf("\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t Enter your choice (1-%d): ", numSubjects);

        while (1) {
            if (scanf("%d", &subjectChoice) == 1 && subjectChoice >= 1 && subjectChoice <= numSubjects) {
                break;
            }
            while (getchar() != '\n');
            printf("\t\t\t Invalid input. Please enter a number between 1 and %d.\n", numSubjects);
            printf("\t\t\t Enter your choice (1-%d): ", numSubjects);
        }

        system("cls");
        printf("\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||          RECORD ATTENDANCE           ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("\t\t\t Teacher: %s\n", teachers[teacherChoice - 1]);
        printf("\t\t\t Subject: %s\n", subjects[teacherChoice - 1][subjectChoice - 1]);
        printf("\t\t\t Date: %s\n\n", attendanceDate);

        for (int i = 0; i < numStudents; i++) {
            if ((strcmp(subjects[teacherChoice - 1][subjectChoice - 1], "NSTP") == 0 || 
                 strcmp(subjects[teacherChoice - 1][subjectChoice - 1], "PATHFIT") == 0) &&
                strcmp(students[i], "Abella, Ghanda Mar") == 0) {
                attendance[i] = 'N';
                printf("\t\t\t Skipping attendance for %s (not applicable for this subject).\n", students[i]);
                continue;
            }

            while (1) {
                printf("\t\t\t Enter attendance for %s\n", students[i]);
                printf("\t\t\t (1 = Present, 2 = Absent, 3 = Excused): ");
                if (scanf("%d", &statusChoice) == 1 && statusChoice >= 1 && statusChoice <= 3) {
                    switch (statusChoice) {
                        case 1: attendance[i] = 'P'; break;
                        case 2: attendance[i] = 'A'; break;
                        case 3: attendance[i] = 'E'; break;
                    }
                    break;
                }
                while (getchar() != '\n');
                printf("\t\t\t Invalid input. Please enter 1, 2, or 3.\n");
            }
        }

        system("cls");
        printf("\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||         ATTENDANCE  SUMMARY          ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("\t\t\t Present Students:\n");
        for (int i = 0; i < numStudents; i++) {
            if (attendance[i] == 'P') {
                printf("\t\t\t - %s\n", students[i]);
            }
        }

        printf("\n\t\t\t Absent Students:\n");
        for (int i = 0; i < numStudents; i++) {
            if (attendance[i] == 'A') {
                printf("\t\t\t - %s\n", students[i]);
            }
        }

        printf("\n\t\t\t Excused Students:\n");
        for (int i = 0; i < numStudents; i++) {
            if (attendance[i] == 'E') {
                printf("\t\t\t - %s\n", students[i]);
            }
        }

        printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t Is this attendance record correct? (y/n): ");
        scanf(" %c", &editAttendance);

        while (editAttendance == 'n' || editAttendance == 'N') {
            system("cls");
            printf("\n\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t |=||==||==||          EDIT ATTENDANCE             ||==||==||=|\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\n");
            printf("\t\t\t Student List with Current Attendance:\n\n");
            for (int i = 0; i < numStudents; i++) {
                printf("\t\t\t %2d. %-40s [%c]\n", i + 1, students[i], attendance[i]);
            }

            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Enter student number to edit (1-%d): ", numStudents);
            int studentIndex;
            scanf("%d", &studentIndex);
            studentIndex--;

            if (studentIndex >= 0 && studentIndex < numStudents) {
                printf("\t\t\t Current attendance for %s: %c\n", students[studentIndex], attendance[studentIndex]);
                printf("\t\t\t Enter new attendance (1 = Present, 2 = Absent, 3 = Excused): ");
                scanf("%d", &statusChoice);

                switch (statusChoice) {
                    case 1: attendance[studentIndex] = 'P'; break;
                    case 2: attendance[studentIndex] = 'A'; break;
                    case 3: attendance[studentIndex] = 'E'; break;
                    default: printf("\t\t\t Invalid choice!\n");
                }

                system("cls");
                printf("\n\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||      UPDATED ATTENDANCE SUMMARY      ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\n");
                printf("\t\t\t Present Students:\n");
                for (int i = 0; i < numStudents; i++) {
                    if (attendance[i] == 'P') {
                        printf("\t\t\t - %s\n", students[i]);
                    }
                }

                printf("\n\t\t\t Absent Students:\n");
                for (int i = 0; i < numStudents; i++) {
                    if (attendance[i] == 'A') {
                        printf("\t\t\t - %s\n", students[i]);
                    }
                }

                printf("\n\t\t\t Excused Students:\n");
                for (int i = 0; i < numStudents; i++) {
                    if (attendance[i] == 'E') {
                        printf("\t\t\t - %s\n", students[i]);
                    }
                }

                printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t Is the attendance record correct now? (y/n): ");
                scanf(" %c", &editAttendance);
            } else {
                printf("\t\t\t Invalid student number!\n");
            }
        }

        char filename[100];
        sprintf(filename, "attendance_%s_%s.txt", 
                teachers[teacherChoice - 1], 
                subjects[teacherChoice - 1][subjectChoice - 1]);

        FILE *file = fopen(filename, "a");
        if (file != NULL) {
            fprintf(file, "\nAttendance Date: %s\n", attendanceDate);
            fprintf(file, "----------------------------------------\n");
            for (int i = 0; i < numStudents; i++) {
                fprintf(file, "%s: %c\n", students[i], attendance[i]);
            }
            fprintf(file, "----------------------------------------\n");
            fclose(file);
            
            system("cls");
            printf("\n\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t |=||==||==||        ATTENDANCE  SAVED             ||==||==||=|\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\n");
            printf("\t\t\t Attendance record saved successfully!\n");
        } else {
            printf("\n\t\t\t Error saving attendance record!\n");
        }

        printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t Record attendance for another session? (y/n): ");
        scanf(" %c", &continueEditing);
        
        if (continueEditing == 'n' || continueEditing == 'N') {
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
            printf("\t\t\t |=||==||==||        RETURNING TO MAIN MENU        ||==||==||=|\n");
            printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\n\n");
            printf("\t\t\t\t\t\t LOADING...\n\n");
            printf("\t\t\t\t");
            
            for(int i=1; i<=30; i++) {
                green();
                cerr<<x;
                usleep(99999);
            }
            system("cls");
            goto menu;
        }
        
        system("cls");
    } while (continueEditing == 'y' || continueEditing == 'Y');

    return 0;
}

		
else if (choice == '3') {
    char x = 219;
    printf("\n\n\n\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||           VIEW  ATTENDANCE           ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t LOADING...\n\n");
    printf("\t\t\t\t");
    
    for(int i=1; i<=30; i++) {
        green();
        cerr<<x;
        usleep(99999);
    }

    system("cls");

    int teacherChoice;
    const char* teachers[] = {
        "Atienza, Michael", "Jimenez, Carl Joseph", "Lacerna, Nori", 
        "Gordon, Raiven", "Rodriguez, Jude", "Vele, Allan"
    };
    const char* subjects[6][3] = {
        {"PATHFIT", "NSTP", "PLS"},
        {"CC112"},
        {"GE3"},
        {"CC111"},
        {"GE2"},
        {"GE1"}
    };

    printf("\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||           VIEW  ATTENDANCE           ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n");
    printf("\t\t\t Choose a teacher:\n\n");
    for (int i = 0; i < 6; i++) {
        printf("\t\t\t [%d] %s\n", i + 1, teachers[i]);
    }
    printf("\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t Enter your choice (1-6): ");
    
    while (1) {
        if (scanf("%d", &teacherChoice) == 1 && teacherChoice >= 1 && teacherChoice <= 6) {
            break;
        }
        while (getchar() != '\n');
        printf("\t\t\t Invalid input. Please enter a number between 1 and 6.\n");
        printf("\t\t\t Enter your choice (1-6): ");
    }

    int subjectChoice;
    system("cls");
    printf("\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||           VIEW  ATTENDANCE           ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n");
    printf("\t\t\t Teacher Selected: %s\n\n", teachers[teacherChoice - 1]);
    printf("\t\t\t Choose Subject:\n\n");
    
    int numSubjects = sizeof(subjects[teacherChoice - 1]) / sizeof(subjects[teacherChoice - 1][0]);
    for (int i = 0; i < numSubjects; i++) {
        printf("\t\t\t [%d] %s\n", i + 1, subjects[teacherChoice - 1][i]);
    }
    printf("\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t Enter your choice (1-%d): ", numSubjects);

    while (1) {
        if (scanf("%d", &subjectChoice) == 1 && subjectChoice >= 1 && subjectChoice <= numSubjects) {
            break;
        }
        while (getchar() != '\n');
        printf("\t\t\t Invalid input. Please enter a number between 1 and %d.\n", numSubjects);
        printf("\t\t\t Enter your choice (1-%d): ", numSubjects);
    }

    char filename[100];
    sprintf(filename, "attendance_%s_%s.txt", 
            teachers[teacherChoice - 1], 
            subjects[teacherChoice - 1][subjectChoice - 1]);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        system("cls");
        printf("\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||           VIEW  ATTENDANCE           ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("\t\t\t No attendance records found for this subject.\n");
    } else {
        system("cls");
        printf("\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||           VIEW  ATTENDANCE           ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("\t\t\t Teacher: %s\n", teachers[teacherChoice - 1]);
        printf("\t\t\t Subject: %s\n\n", subjects[teacherChoice - 1][subjectChoice - 1]);
        
        char line[256];
        int inRecord = 0;
        int lineCount = 0;
        while (fgets(line, sizeof(line), file)) {
            // Remove newline character from the end of the line
            line[strcspn(line, "\n")] = 0;
            
            // Skip empty lines
            if (strlen(line) == 0) continue;
            
            // Print date headers and dividers
            if (strstr(line, "Attendance Date:") || strstr(line, "----------------------------------------")) {
                printf("\t\t\t %s\n", line);
                continue;
            }
            
            // Print student attendance records
            if (strchr(line, ':')) {  // Check if line contains attendance data
                printf("\t\t\t %s\n", line);
                lineCount++;
            }
        }
        fclose(file);
        
        if (lineCount == 0) {
            printf("\t\t\t No attendance records found for this subject.\n");
        }
    }

    printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t Press any key to return to main menu...");
    getchar();
    getchar();
    
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||        RETURNING TO MAIN MENU        ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t LOADING...\n\n");
    printf("\t\t\t\t");
    
    for(int i=1; i<=30; i++) {
        green();
        cerr<<x;
        usleep(99999);
    }
    system("color 30");
    system("cls");
    goto menu;
}
    
else if (choice == '4') {
        goto about;
        return 0;
		}
else if (choice == '5') {
        printf("\n\n\n\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t |=||==||==||          Account logging off         ||==||==||=|\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t |=||==||==||            PLEASE WAIT...            ||==||==||=|\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");    
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n\n");
        printf("\t\t\t\t\t\t");
        printf("\n\n");
        printf("\n\t\t\t\t\t");
        for(int i=1; i<=30; i++)
        {
            green();
            cerr<<x;
            usleep(99999);
        }
        system("cls");
        return 1;
}
        
    else {
        system("cls");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t  |=||     Error, Please choose from the choices below.     ||=|\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        goto menu;
    } 

	
	
	about:
		int about;
		printf("\n\n\n");
		printf("\t\t\t\t\t  [] >>====================<< []\n");
		printf("\t\t\t\t\t  [] >>    PHILTECH-GMA    << []\n");
		printf("\t\t\t\t\t  [] >>====================<< []\n");
		printf("\n");
		printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\t\t\t [][]                                                        [][]\n");
		printf("\t\t\t [][]          Philippine Technological Institute of         [][]\n");
		printf("\t\t\t [][]         Science, Arts, and Trade - Central INC.        [][]\n");
		printf("\t\t\t [][]                 2nd Flr. CRDM Building,                [][]\n");
    	printf("\t\t\t [][]          Congressional Road, Cor. Gov. Drive,          [][]\n");
    	printf("\t\t\t [][]             Brgy. G. Maderan, GMA, Cavite              [][]\n");
    	printf("\t\t\t [][]                                                        [][]\n");
    	printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    	printf("\n\n");
    	printf("\t\t\t\t\t     [1] About Senior High [1]\n");
    	printf("\t\t\t\t\t     [2]   About College   [2]\n");
    	printf("\n");
    	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\t\t\t  |=||==||==||  PRESS THE NUMBER YOU WANT TO CHECK  ||==||==||=|\n");
		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\n\n");
		printf(" * PRESSING OTHER KEY RETURNS TO MENU:\t\t\t\t\t\t\t\t   (P) Contact Info");
		about = getch();
		system ("cls");
		
		if (about == '1'){
			int sh;
			printf("\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\t\t\t\t\t  [] >>     SENIOR HIGH    << []\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\n");
    		printf("\t\t\t\t\t    SHS160S.2016/SHS-206S.2017\n");
    		printf("\n");
			printf("\t\t\t\t   #### ####  ###### #####     * Tuition Fee            \n");
	 		printf("\t\t\t\t   #    #   # #      #                                  \n");
	 		printf("\t\t\t\t   ###  ####  ####   ####      * Laboratory Fee         \n");
	 		printf("\t\t\t\t   #    #  #  #      #                                  \n");
			printf("\t\t\t\t   #    #   # ###### #####     * Miscellaneous Fee      \n");
			printf("\n");
   		 	printf("\t\t\t\t   Includes:\n");
   			printf("\t\t\t\t          - 1 Set of School Uniform\n");
		    printf("\t\t\t\t          - 1 SHS T-Shirt\n");
		    printf("\t\t\t\t          - 1 Set of PE Uniform\n");
		    printf("\t\t\t\t          - ID with Holder\n\n");
		    printf("\t\t\t\t   ACADEMIC TRACK\n");
		    printf("\t\t\t\t          - Humanities and Social Science\n");
		    printf("\t\t\t\t          - Accountancy, Business, and Management\n");
		    printf("\t\t\t\t          - General Academics\n\n");
	 	  	printf("\t\t\t\t   TECHNICAL VOCATIONAL LIVELIHOOD TRACK\n");
			printf("\t\t\t\t          - Information and Communications Technology\n");
		    printf("\t\t\t\t          - Home Economics\n\n");
		    printf("\t(X) MENU\t\t\t\t\t\t\t\t\t\t(ANY KEY) RETURN");
		    sh = getch();
		    system ("cls");
		    
		    if (sh == 'x' || sh == 'X'){
				goto menu;
			}
			if (sh != '0'){
				goto about;
			}
		}
		if (about == '2'){
			int cg;
			printf("\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\t\t\t\t\t  [] >>       COLLEGE      << []\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\n");
    		printf("\t\t\t\t\t     50%% DISCOUNT IN TUITION\n");
    		printf("\n");
		    printf("\t\t\t\t   Courses Offered:\n");
		    printf("\t\t\t\t      - Bachelor of Technical Vocational\n");
		    printf("\t\t\t\t        Teacher Education (BTVTEd)\n");
		    printf("\t\t\t\t      - Major in Food and Service Management\n");
	 	  	printf("\t\t\t\t         CHED Permit No. 048 Series 2021\n\n");
			printf("\t\t\t\t      - Bachelor of Science in Computer Science (BSCS)\n");
		    printf("\t\t\t\t         CHED Permit No. 035 Series 2022\n\n");
		    printf("\t\t\t\t      - Bachelor of Science in Office Administration (BSOA)\n");
		    printf("\t\t\t\t         CHED Permit No. 033 Series 2022\n\n");
		    printf("\t\t\t\t   Upcoming Courses:\n");
		    printf("\t\t\t\t      - Bachelor of Science in Psychology\n");
		    printf("\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\t\t\t\t\t  [] >>    SUNDAY CLASS    << []\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\n");
			printf("\t\t\t\t\t     50%% DISCOUNT IN TUITION\n");
    		printf("\n");
		    printf("\t\t\t\t   Courses Available:\n");
		    printf("\t\t\t\t      - Bachelor of Technical Vocational\n");
		    printf("\t\t\t\t        Teacher Education (BTVTEd)\n");
		    printf("\t\t\t\t      - Major in Food and Service Management\n");
			printf("\t\t\t\t      - Bachelor of Science in Computer Science (BSCS)\n");
		    printf("\t\t\t\t      - Bachelor of Science in Office Administration (BSOA)\n");
		    printf("\n");
		    printf("\t(X) MENU\t\t\t\t\t\t\t\t\t\t(ANY KEY) RETURN");
		    cg = getch();
		    system ("cls");
		    if (cg == 'x' || cg == 'X'){
				goto menu;
			}
			if (cg != '0'){
				goto about;
			}
		}
		if (about == 'p' || about == 'P'){
			int ci;
			printf("\n\n\n\n\n");
			printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
			printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
			printf("\t\t\t|=||==||==||          CONTACT INFORMATION         ||==||==||=|\n");
			printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
			printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
			printf("\n\n\n");
			printf("\t\t\t\t   Tel: (046) 409-94-90\n");
			printf("\t\t\t\t   Globe Mobile: 0955-135-4698\n");
			printf("\n");
			printf("\t\t\t\t   Social Media:\n");
			printf("\t\t\t\t   Facebook Page: Philtech GMA\n");
			printf("\t\t\t\t   Instagram: philtechgma\n");
			printf("\t\t\t\t   YouTube: Philtech GMA\n");
			printf("\n\n\n\n\n\n");
			printf("\t(X) MENU\t\t\t\t\t\t\t\t\t\t(ANY KEY) RETURN");
			
			ci = getch();
			system("cls");
			if (ci == 'x' || ci == 'X'){
				goto menu;
			}
			if (ci != '0'){
				goto about;
			}
			
			
		}
		if (about != '0'){
			goto menu;
		}
	}

int administratorMenu(){
    int choice;
    char x=219;
    
    printf("\n\n\n\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||       >> ADMINISTRATOR MENU <<       ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||     PROGRAM LOADING IS IN PROCESS    ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||            PLEASE WAIT...            ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");    
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t");
    
    printf("\n\n");
    printf("\n\t\t\t\t\t");
    for(int i=1; i<=30; i++)
    {
        green();
        cerr<<x;
        usleep(99999);
    }
    system("cls");
    
menu:
    printf("\n");
    printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
    printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
    printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\t\t\t\t     [] Philtech School Management System []\n");
    printf("\t\t\t\t     [][]  Choose what you want to use  [][]\n");
    printf("\n\n");
    printf("\t\t\t\t\t > [1] Manage Enrollees     [1]\n");
    printf("\t\t\t\t\t > [2] Manage Eog Request   [2]\n");
    printf("\t\t\t\t\t > [3] Classroom Management [3]\n");
    printf("\t\t\t\t\t > [4] About US (Philtech)  [4]\n");
    printf("\t\t\t\t\t > [5] Log out              [5]\n");
    printf("\n\n\n");
    printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t  |=||==||==||  PRESS THE NUMBER YOU WANT TO CHECK  ||==||==||=|\n");
    printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n");
    choice = getch();
    system("cls");
    
    if (choice == '1'){
    	            // Loading animation for enrollee management
            printf("\n\n\n\n\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
            printf("\t\t\t |=||==||==||      ENROLLEE MANAGEMENT SYSTEM      ||==||==||=|\n");
            printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
            printf("\t\t\t |=||==||==||            PLEASE WAIT...            ||==||==||=|\n");
            printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");    
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\n\n");
            printf("\t\t\t\t\t\t");
            
            printf("\n\n");
            printf("\n\t\t\t\t\t");
            for(int i = 1; i <= 30; i++) {
                printf("%c", x);
                usleep(99999);
            }
            system("cls");

            while(1) {
                int enrolleeChoice;
                int result;
                char nameToDelete[100];
                
                printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||      ENROLLEE MANAGEMENT SYSTEM      ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\n\t\t\t\t 1. View BSCS Enrollees\n");
                printf("\t\t\t\t 2. View BTVTLED Enrollees\n");
                printf("\t\t\t\t 3. View EDUC Enrollees\n");
                printf("\t\t\t\t 4. Remove Enrollee\n");
                printf("\t\t\t\t 5. Return to Main Menu\n");
                printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t Enter choice: ");
                
                if (scanf("%d", &enrolleeChoice) != 1) {
                    while (getchar() != '\n');
                    printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        			printf("\t\t\t|=||==||==||   Invalid choice! Please try again.  ||==||==||=|\n");
        			printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                    continue;
                }
                getchar(); // Clear input buffer
                system("cls");

                switch(enrolleeChoice) {
                    case 1:
                        printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        printf("\t\t\t |=||==||==||           BSCS ENROLLEES            ||==||==||=|\n");
                        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        result = viewEnrollees("bscs_enrollees.txt");
                        break;
                        
                    case 2:
                        printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        printf("\t\t\t |=||==||==||         BTVTLED ENROLLEES          ||==||==||=|\n");
                        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        result = viewEnrollees("btvtled_enrollees.txt");
                        break;
                        
                    case 3:
                        printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        printf("\t\t\t |=||==||==||           EDUC ENROLLEES           ||==||==||=|\n");
                        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        result = viewEnrollees("educ_enrollees.txt");
                        break;
                        
                    case 4: {
                        int courseChoice;
                        const char* courseFile = NULL;
                        
                        printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        printf("\t\t\t |=||==||==||         REMOVE ENROLLEE            ||==||==||=|\n");
                        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        printf("\n\t\t\t Select course:\n");
                        printf("\t\t\t 1. BSCS\n");
                        printf("\t\t\t 2. BTVTLED\n");
                        printf("\t\t\t 3. EDUC\n");
                        printf("\t\t\t Choice: ");
                        
                        if (scanf("%d", &courseChoice) != 1) {
                            while (getchar() != '\n');
                            printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        					printf("\t\t\t|=||==||   Invalid input! Press any key to continue.  ||==||=|\n");
        					printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                            break;
                        }
                        getchar(); // Clear input buffer
                        
                        switch(courseChoice) {
                            case 1:
                                courseFile = "bscs_enrollees.txt";
                                break;
                            case 2:
                                courseFile = "btvtled_enrollees.txt";
                                break;
                            case 3:
                                courseFile = "educ_enrollees.txt";
                                break;
                            default:
                            	printf("\n\n");
                                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        						printf("\t\t\t |=||==||          Invalid course selection.           ||==||=|\n");
        						printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                                break;
                        }
                        
                        if (courseFile != NULL) {
                            printf("\t\t\t Enter student name to remove: ");
                            if (fgets(nameToDelete, sizeof(nameToDelete), stdin)) {
                                nameToDelete[strcspn(nameToDelete, "\n")] = 0;
                                result = deleteEnrollee(courseFile, nameToDelete);
                            }
                        }
                        break;
                    }
                    
                    case 5:
                        system("cls");
                        goto menu;
                        
                    default:
                    	printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        				printf("\t\t\t|=||==||                  Invalid input!              ||==||=|\n");
        				printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                }
                
                printf("\n\t\t\t Press any key to continue...");
                getch();
                system("cls");
            }
        }
        
	else if (choice == '2'){
		    char x = 219;
    int choice;
    FILE *certFile, *clearFile;
    char line[256];
    int requestCount = 0;

    while(1) {
        // Loading animation
        printf("\n\n\n\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t |=||==||==||       EOG REQUEST MANAGEMENT         ||==||==||=|\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n\n");
        printf("\t\t\t\t\t\t LOADING...\n\n");
        printf("\t\t\t\t");
        
        for(int i=1; i<=30; i++) {
            printf("%c", x);
            usleep(99999);
        }
        
        system("cls");

        printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||       EOG REQUEST MANAGEMENT         ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n\t\t\t 1. View Certification Requests\n");
        printf("\t\t\t 2. View Clearance Requests\n");
        printf("\t\t\t 3. Process Request\n");
        printf("\t\t\t 4. Return to Main Menu\n");
        printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear input buffer
            printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        	printf("\t\t\t|=||==||     Invalid input! Please input a number.    ||==||=|\n");
        	printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Press any key to continue...");
            getch();
            system("cls");
            continue;
        }
        system("cls");

        switch(choice) {
            case 1: {
                printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||       CERTIFICATION REQUESTS         ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");
                
                certFile = fopen("certification_requests.txt", "r");
                if (certFile == NULL) {
                    printf("\t\t\t No certification requests found.\n");
                } else {
                    requestCount = 0;
                    while (fgets(line, sizeof(line), certFile)) {
                        printf("\t\t\t %s", line);
                        if (strstr(line, "Status:") != NULL) {
                            printf("\t\t\t ------------------------\n");
                            requestCount++;
                            printf("\t\t\t Request #%d\n", requestCount);
                        }
                    }
                    if (requestCount == 0) {
                        printf("\t\t\t No requests found.\n");
                    }
                    fclose(certFile);
                }
                printf("\n\t\t\t Press any key to continue...");
                getch();
                system("cls");
                break;
            }
            
            case 2: {
                printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||         CLEARANCE REQUESTS           ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");
                
                clearFile = fopen("clearance_requests.txt", "r");
                if (clearFile == NULL) {
                    printf("\t\t\t No clearance requests found.\n");
                } else {
                    requestCount = 0;
                    while (fgets(line, sizeof(line), clearFile)) {
                        printf("\t\t\t %s", line);
                        if (strstr(line, "Status:") != NULL) {
                            printf("\t\t\t ------------------------\n");
                            requestCount++;
                            printf("\t\t\t Request #%d\n", requestCount);
                        }
                    }
                    if (requestCount == 0) {
                        printf("\t\t\t No requests found.\n");
                    }
                    fclose(clearFile);
                }
                printf("\n\t\t\t Press any key to continue...");
                getch();
                system("cls");
                break;
            }
            
            case 3: {
                int requestType, requestNumber;
                char tempFile[] = "temp.txt";
                FILE *source, *temp;
                int currentRequest = 0;
                char status[20];
                int maxRequests = 0;
                
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||          PROCESS REQUEST             ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                
                do {
                    printf("\n\t\t\t Request Type (1-Certification, 2-Clearance): ");
                    if (scanf("%d", &requestType) != 1 || (requestType != 1 && requestType != 2)) {
                        while (getchar() != '\n');
                        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        				printf("\t\t\t |=||==||      Invalid input! Please enter 1 or 2.     ||==||=|\n");
        				printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        continue;
                    }
                    break;
                } while (1);

                // Count total requests
                if (requestType == 1) {
                    source = fopen("certification_requests.txt", "r");
                } else {
                    source = fopen("clearance_requests.txt", "r");
                }

                if (source != NULL) {
                    while (fgets(line, sizeof(line), source)) {
                        if (strstr(line, "Status:") != NULL) {
                            maxRequests++;
                        }
                    }
                    fclose(source);
                }

                if (maxRequests == 0) {
                	printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        			printf("\t\t\t|=||==||         No requests found to process.        ||==||=|\n");
        			printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                    printf("\t\t\t Press any key to continue...");
                    getch();
                    system("cls");
                    break;
                }

                do {
                    printf("\t\t\t Request Number (1-%d): ", maxRequests);
                    if (scanf("%d", &requestNumber) != 1 || requestNumber < 1 || requestNumber > maxRequests) {
                        while (getchar() != '\n');
                        printf("\t\t\t Invalid request number! Please enter a number between 1 and %d.\n", maxRequests);
                        continue;
                    }
                    break;
                } while (1);

                do {
                    printf("\t\t\t Status (1-Approved, 2-Denied): ");
                    int statusChoice;
                    if (scanf("%d", &statusChoice) != 1 || (statusChoice != 1 && statusChoice != 2)) {
                        while (getchar() != '\n');
                        printf("\t\t\t Invalid input! Please enter 1 or 2.\n");
                        continue;
                    }
                    strcpy(status, statusChoice == 1 ? "Approved" : "Denied");
                    break;
                } while (1);

                if (requestType == 1) {
                    source = fopen("certification_requests.txt", "r");
                } else {
                    source = fopen("clearance_requests.txt", "r");
                }

                if (source == NULL) {
                	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            		printf("\t\t\t  |=||          Error: Could not open request file.         ||=|\n");
            		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                    printf("\t\t\t Press any key to continue...");
                    getch();
                    system("cls");
                    break;
                }

                temp = fopen(tempFile, "w");
                if (temp == NULL) {
                	
                	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            		printf("\t\t\t  |=||         Error: Could not create temporary file.      ||=|\n");
            		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                    fclose(source);
                    printf("\t\t\t Press any key to continue...");
                    getch();
                    system("cls");
                    break;
                }

                currentRequest = 0;
                int found = 0;
                while (fgets(line, sizeof(line), source)) {
                    if (strstr(line, "Status:") != NULL) {
                        currentRequest++;
                        if (currentRequest == requestNumber) {
                            fprintf(temp, "Status: %s\n\n", status);
                            found = 1;
                            continue;
                        }
                    }
                    fprintf(temp, "%s", line);
                }

                fclose(source);
                fclose(temp);

                if (!found) {
                	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            		printf("\t\t\t  |=||               Error: Request not found.              ||=|\n");
            		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                    remove(tempFile);
                } else {
                    if (requestType == 1) {
                        remove("certification_requests.txt");
                        rename(tempFile, "certification_requests.txt");
                    } else {
                        remove("clearance_requests.txt");
                        rename(tempFile, "clearance_requests.txt");
                    }
                    printf("\n\t\t\t Request #%d has been %s!\n", requestNumber, status);
                }

                printf("\t\t\t Press any key to continue...");
                getch();
                system("cls");
                break;
            }
            
            case 4:
    			system("cls");
    			goto menu;  // Replace "return 0;" with "goto menu;"
    			break;  // Although not necessary after goto, included for consistency
            
            default:
            	printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        		printf("\t\t\t|=||==||  Invalid choice! Please enter a number between 1 and 4.  ||==||=|\n");
        		printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t Press any key to continue...");
                getch();
                system("cls");
        }
    }
    return 0;
	}
	
	else if (choice == '3'){
		    char x = 219;
    printf("\n\n\n\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||        CLASSROOM  MANAGEMENT         ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t LOADING...\n\n");
    printf("\t\t\t\t");
    
    for(int i=1; i<=30; i++) {
        green();
        cerr<<x;
        usleep(99999);
    }
    system("cls");

    while(1) {
        printf("\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||        CLASSROOM  MANAGEMENT         ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("\t\t\t Choose a teacher:\n\n");
        printf("\t\t\t [1] Allan Vele       - Understanding the Self (Ge1)\n");
        printf("\t\t\t [2] Jude Rodriguez   - Mathematics in Modern World (Ge2)\n");
        printf("\t\t\t [3] Nori Lacerna     - Readings in Phil. History (Ge3)\n");
        printf("\t\t\t [4] Raiven Gordon    - Intro to Computing (Cc111)\n");
        printf("\t\t\t [5] Carl Jimenez     - Fund. of Programming 1 (Cc112)\n");
        printf("\t\t\t [6] Michael Atienza  - PATHFIT1/NSTP1/PLS\n");
        printf("\t\t\t [7] Return to menu\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t Press the corresponding number (1-7): ");

        char teacherChoice = getch();
        system("cls");

        if(teacherChoice == '1') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Allan Velle\n");
            printf("\t\t\t Schedule: Saturday 7:00 am - 10:00 am\n");
            printf("\t\t\t Subject: Understanding the Self (Ge1)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '2') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Jude Rodriguez\n");
            printf("\t\t\t Schedule: Saturday 10:00 am - 1:00 pm\n");
            printf("\t\t\t Subject: Mathematics in the Modern World (Ge2)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '3') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Nori Lacerna\n");
            printf("\t\t\t Schedule: Saturday 1:00 pm - 4:00 pm\n");
            printf("\t\t\t Subject: Readings in Philippines History (Ge3)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '4') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Raiven Gordon\n");
            printf("\t\t\t Schedule: Monday 9:00 am - 2:00 pm\n");
            printf("\t\t\t Subject: Introduction to Computing (Cc111)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '5') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Carl Joseph Jimenez\n");
            printf("\t\t\t Schedule: Thursday 7:00 am - 12:00 pm\n");
            printf("\t\t\t Subject: Fundamentals of Programming 1 (Cc112)\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '6') {
            printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Teacher: Michael Atienza\n");
            printf("\t\t\t Schedule:\n");
            printf("\t\t\t Tuesday 7:00 am - 8:45 am: PATHFIT1\n");
            printf("\t\t\t Wednesday 9:00 am - 12:00 pm: NSTP1\n");
            printf("\t\t\t Wednesday 12:00 pm - 1:00 pm: PLS\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        }
        else if(teacherChoice == '7') {
            system("cls");
            goto menu;
        }

    }
	}
	
	else if (choice == '4'){
			about:
        int about;
		printf("\n\n\n");
		printf("\t\t\t\t\t  [] >>====================<< []\n");
		printf("\t\t\t\t\t  [] >>    PHILTECH-GMA    << []\n");
		printf("\t\t\t\t\t  [] >>====================<< []\n");
		printf("\n");
		printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\t\t\t [][]                                                        [][]\n");
		printf("\t\t\t [][]          Philippine Technological Institute of         [][]\n");
		printf("\t\t\t [][]         Science, Arts, and Trade - Central INC.        [][]\n");
		printf("\t\t\t [][]                 2nd Flr. CRDM Building,                [][]\n");
    	printf("\t\t\t [][]          Congressional Road, Cor. Gov. Drive,          [][]\n");
    	printf("\t\t\t [][]             Brgy. G. Maderan, GMA, Cavite              [][]\n");
    	printf("\t\t\t [][]                                                        [][]\n");
    	printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    	printf("\n\n");
    	printf("\t\t\t\t\t     [1] About Senior High [1]\n");
    	printf("\t\t\t\t\t     [2]   About College   [2]\n");
    	printf("\n");
    	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\t\t\t  |=||==||==||  PRESS THE NUMBER YOU WANT TO CHECK  ||==||==||=|\n");
		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\n\n");
		printf(" * PRESSING OTHER KEY RETURNS TO MENU:\t\t\t\t\t\t\t\t   (P) Contact Info");
		about = getch();
		system ("cls");
		
		if (about == '1'){
			int sh;
			printf("\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\t\t\t\t\t  [] >>     SENIOR HIGH    << []\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\n");
    		printf("\t\t\t\t\t    SHS160S.2016/SHS-206S.2017\n");
    		printf("\n");
			printf("\t\t\t\t   #### ####  ###### #####     * Tuition Fee            \n");
	 		printf("\t\t\t\t   #    #   # #      #                                  \n");
	 		printf("\t\t\t\t   ###  ####  ####   ####      * Laboratory Fee         \n");
	 		printf("\t\t\t\t   #    #  #  #      #                                  \n");
			printf("\t\t\t\t   #    #   # ###### #####     * Miscellaneous Fee      \n");
			printf("\n");
   		 	printf("\t\t\t\t   Includes:\n");
   			printf("\t\t\t\t          - 1 Set of School Uniform\n");
		    printf("\t\t\t\t          - 1 SHS T-Shirt\n");
		    printf("\t\t\t\t          - 1 Set of PE Uniform\n");
		    printf("\t\t\t\t          - ID with Holder\n\n");
		    printf("\t\t\t\t   ACADEMIC TRACK\n");
		    printf("\t\t\t\t          - Humanities and Social Science\n");
		    printf("\t\t\t\t          - Accountancy, Business, and Management\n");
		    printf("\t\t\t\t          - General Academics\n\n");
	 	  	printf("\t\t\t\t   TECHNICAL VOCATIONAL LIVELIHOOD TRACK\n");
			printf("\t\t\t\t          - Information and Communications Technology\n");
		    printf("\t\t\t\t          - Home Economics\n\n");
		    printf("\t(X) MENU\t\t\t\t\t\t\t\t\t\t(ANY KEY) RETURN");
		    sh = getch();
		    system ("cls");
		    
		    if (sh == 'x' || sh == 'X'){
				goto menu;
			}
			if (sh != '0'){
				goto about;
			}
		}
		if (about == '2'){
			int cg;
			printf("\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\t\t\t\t\t  [] >>       COLLEGE      << []\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\n");
    		printf("\t\t\t\t\t     50%% DISCOUNT IN TUITION\n");
    		printf("\n");
		    printf("\t\t\t\t   Courses Offered:\n");
		    printf("\t\t\t\t      - Bachelor of Technical Vocational\n");
		    printf("\t\t\t\t        Teacher Education (BTVTEd)\n");
		    printf("\t\t\t\t      - Major in Food and Service Management\n");
	 	  	printf("\t\t\t\t         CHED Permit No. 048 Series 2021\n\n");
			printf("\t\t\t\t      - Bachelor of Science in Computer Science (BSCS)\n");
		    printf("\t\t\t\t         CHED Permit No. 035 Series 2022\n\n");
		    printf("\t\t\t\t      - Bachelor of Science in Office Administration (BSOA)\n");
		    printf("\t\t\t\t         CHED Permit No. 033 Series 2022\n\n");
		    printf("\t\t\t\t   Upcoming Courses:\n");
		    printf("\t\t\t\t      - Bachelor of Science in Psychology\n");
		    printf("\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\t\t\t\t\t  [] >>    SUNDAY CLASS    << []\n");
			printf("\t\t\t\t\t  [] >>====================<< []\n");
			printf("\n");
			printf("\t\t\t\t\t     50%% DISCOUNT IN TUITION\n");
    		printf("\n");
		    printf("\t\t\t\t   Courses Available:\n");
		    printf("\t\t\t\t      - Bachelor of Technical Vocational\n");
		    printf("\t\t\t\t        Teacher Education (BTVTEd)\n");
		    printf("\t\t\t\t      - Major in Food and Service Management\n");
			printf("\t\t\t\t      - Bachelor of Science in Computer Science (BSCS)\n");
		    printf("\t\t\t\t      - Bachelor of Science in Office Administration (BSOA)\n");
		    printf("\n");
		    printf("\t(X) MENU\t\t\t\t\t\t\t\t\t\t(ANY KEY) RETURN");
		    cg = getch();
		    system ("cls");
		    if (cg == 'x' || cg == 'X'){
				goto menu;
			}
			if (cg != '0'){
				goto about;
			}
		}
		if (about == 'p' || about == 'P'){
			int ci;
			printf("\n\n\n\n\n");
			printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
			printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
			printf("\t\t\t|=||==||==||          CONTACT INFORMATION         ||==||==||=|\n");
			printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
			printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
			printf("\n\n\n");
			printf("\t\t\t\t   Tel: (046) 409-94-90\n");
			printf("\t\t\t\t   Globe Mobile: 0955-135-4698\n");
			printf("\n");
			printf("\t\t\t\t   Social Media:\n");
			printf("\t\t\t\t   Facebook Page: Philtech GMA\n");
			printf("\t\t\t\t   Instagram: philtechgma\n");
			printf("\t\t\t\t   YouTube: Philtech GMA\n");
			printf("\n\n\n\n\n\n");
			printf("\t(X) MENU\t\t\t\t\t\t\t\t\t\t(ANY KEY) RETURN");
			
			ci = getch();
			system("cls");
			if (ci == 'x' || ci == 'X'){
				goto menu;
			}
			if (ci != '0'){
				goto about;
			}
			
			
		}
		if (about != '0'){
			goto menu;
		}
	}
	
	else if (choice == '5'){
        printf("\n\n\n\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t |=||==||==||          Account logging off         ||==||==||=|\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t |=||==||==||            PLEASE WAIT...            ||==||==||=|\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");    
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n\n");
        printf("\t\t\t\t\t\t");
        printf("\n\n");
        printf("\n\t\t\t\t\t");
        for(int i=1; i<=30; i++)
        {
            green();
            cerr<<x;
            usleep(99999);
        }
        system("cls");
        return 1;
}
        
    else {
        system("cls");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t  |=||     Error, Please choose from the choices below.     ||=|\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        goto menu;
    } 

}

int registrarMenu() {
    char x = 219;
    int choice;
    // Global arrays for subject table
    char subjectCode[MAX_SUBJECTS][10];
    int units[MAX_SUBJECTS];
    float cashFees[MAX_SUBJECTS];
    int subjectCount = 0;
    FILE *file;
    
    // Initialize default subjects
    strcpy(subjectCode[0], "GE111");
    strcpy(subjectCode[1], "GE112");
    strcpy(subjectCode[2], "CC111");
    strcpy(subjectCode[3], "CC112");
    strcpy(subjectCode[4], "AS111");
    strcpy(subjectCode[5], "GE124");
    strcpy(subjectCode[6], "PE111");
    strcpy(subjectCode[7], "NSTP111");
    
    int defaultUnits[] = {3, 3, 3, 3, 2, 3, 2, 3};
    float defaultFees[] = {22.00, 400.00, 8800.00, 1000.00, 2400.00, 4100.00, 850.00, 17150.00};
    
    for(int i = 0; i < 8; i++) {
        units[i] = defaultUnits[i];
        cashFees[i] = defaultFees[i];
    }
    subjectCount = 8;

    // Loading animation
    printf("\n\n\n\n\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||         >> REGISTRAR MENU <<         ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||     PROGRAM LOADING IS IN PROCESS    ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t |=||==||==||            PLEASE WAIT...            ||==||==||=|\n");
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");    
    printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
    printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
    printf("\n\n");
    printf("\t\t\t\t\t\t");
    
    printf("\n\n");
    printf("\n\t\t\t\t\t");
    for(int i=1; i<=30; i++)
    {
        green();
        cerr<<x;
        usleep(99999);
    }
    system("cls");

menu:
    while (1) {
        printf("\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n\t\t\t\t       [] Registrar Management System []\n");
        printf("\t\t\t\t    [][]  Choose what you want to use  [][]\n");
        printf("\n\n");
        printf("\t\t\t\t\t > [1] Manage Enrollees     [1]\n");
        printf("\t\t\t\t\t > [2] Manage Subject Table [2]\n");
        printf("\t\t\t\t\t > [3] Manage EOG Requests  [3]\n");
        printf("\t\t\t\t\t > [4] Log out              [4]\n");
        printf("\n\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t  |=||==||==||  PRESS THE NUMBER YOU WANT TO CHECK  ||==||==||=|\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        choice = getch();
        system("cls");

if (choice == '1') {
            // Loading animation for enrollee management
            printf("\n\n\n\n\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
            printf("\t\t\t |=||==||==||      ENROLLEE MANAGEMENT SYSTEM      ||==||==||=|\n");
            printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
            printf("\t\t\t |=||==||==||            PLEASE WAIT...            ||==||==||=|\n");
            printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");    
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\n\n");
            printf("\t\t\t\t\t\t");
            
            printf("\n\n");
            printf("\n\t\t\t\t\t");
            for(int i = 1; i <= 30; i++) {
                printf("%c", x);
                usleep(99999);
            }
            system("cls");

            while(1) {
                int enrolleeChoice;
                int result;
                char nameToDelete[100];
                
                printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||      ENROLLEE MANAGEMENT SYSTEM      ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\n\t\t\t\t 1. View BSCS Enrollees\n");
                printf("\t\t\t\t 2. View BTVTLED Enrollees\n");
                printf("\t\t\t\t 3. View EDUC Enrollees\n");
                printf("\t\t\t\t 4. Remove Enrollee\n");
                printf("\t\t\t\t 5. Return to Main Menu\n");
                printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t Enter choice: ");
                
                if (scanf("%d", &enrolleeChoice) != 1) {
                    while (getchar() != '\n');
                    printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        			printf("\t\t\t|=||==||==||   Invalid choice! Please try again.  ||==||==||=|\n");
        			printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                    continue;
                }
                getchar(); // Clear input buffer
                system("cls");

                switch(enrolleeChoice) {
                    case 1:
                        printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        printf("\t\t\t |=||==||==||           BSCS ENROLLEES            ||==||==||=|\n");
                        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        result = viewEnrollees("bscs_enrollees.txt");
                        break;
                        
                    case 2:
                        printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        printf("\t\t\t |=||==||==||         BTVTLED ENROLLEES          ||==||==||=|\n");
                        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        result = viewEnrollees("btvtled_enrollees.txt");
                        break;
                        
                    case 3:
                        printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        printf("\t\t\t |=||==||==||           EDUC ENROLLEES           ||==||==||=|\n");
                        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        result = viewEnrollees("educ_enrollees.txt");
                        break;
                        
                    case 4: {
                        int courseChoice;
                        const char* courseFile = NULL;
                        
                        printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        printf("\t\t\t |=||==||==||         REMOVE ENROLLEE            ||==||==||=|\n");
                        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        printf("\n\t\t\t Select course:\n");
                        printf("\t\t\t 1. BSCS\n");
                        printf("\t\t\t 2. BTVTLED\n");
                        printf("\t\t\t 3. EDUC\n");
                        printf("\t\t\t Choice: ");
                        
                        if (scanf("%d", &courseChoice) != 1) {
                            while (getchar() != '\n');
                            printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        					printf("\t\t\t|=||==||   Invalid input! Press any key to continue.  ||==||=|\n");
        					printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                            break;
                        }
                        getchar(); // Clear input buffer
                        
                        switch(courseChoice) {
                            case 1:
                                courseFile = "bscs_enrollees.txt";
                                break;
                            case 2:
                                courseFile = "btvtled_enrollees.txt";
                                break;
                            case 3:
                                courseFile = "educ_enrollees.txt";
                                break;
                            default:
                            	printf("\n\n");
                                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        						printf("\t\t\t |=||==||          Invalid course selection.           ||==||=|\n");
        						printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                                break;
                        }
                        
                        if (courseFile != NULL) {
                            printf("\t\t\t Enter student name to remove: ");
                            if (fgets(nameToDelete, sizeof(nameToDelete), stdin)) {
                                nameToDelete[strcspn(nameToDelete, "\n")] = 0;
                                result = deleteEnrollee(courseFile, nameToDelete);
                            }
                        }
                        break;
                    }
                    
                    case 5:
                        system("cls");
                        goto menu;
                        
                    default:
                    	printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        				printf("\t\t\t|=||==||                  Invalid input!              ||==||=|\n");
        				printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                }
                
                printf("\n\t\t\t Press any key to continue...");
                getch();
                system("cls");
            }
        }
        
else if (choice == '2') {
        
manageSubjectTable:
    while(1) {
        int manageChoice;
        char buffer[32];  // Buffer for input validation
        
        system("cls");  // Clear screen before showing menu
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||         MANAGE SUBJECT TABLE         ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("1. Add New Subject\n");
        printf("2. Remove Subject\n");
        printf("3. Edit Subject Details\n");
        printf("4. View Subject Table\n");
        printf("5. Return to Main Menu\n");
        printf("Enter your choice: ");
        
        // Input validation for menu choice
        if (scanf("%d", &manageChoice) != 1) {
            while (getchar() != '\n');  // Clear input buffer
            printf("\nInvalid input! Please enter a number.\n");
            system("pause");
            continue;
        }
        
        if (manageChoice == 1) {
            system("cls");
            if(subjectCount >= MAX_SUBJECTS) {
                printf("Maximum number of subjects reached!\n");
            } else {
                int valid_input = 0;
                do {
                    printf("\nEnter Subject Code (max 10 characters): ");
                    scanf(" %10s", buffer);
                    
                    // Check if subject code already exists
                    int exists = 0;
                    for(int i = 0; i < subjectCount; i++) {
                        if(strcmp(buffer, subjectCode[i]) == 0) {
                            exists = 1;
                            break;
                        }
                    }
                    
                    if(exists) {
                        printf("Subject code already exists! Please enter a unique code.\n");
                    } else {
                        strcpy(subjectCode[subjectCount], buffer);
                        valid_input = 1;
                    }
                } while(!valid_input);
                
                do {
                    printf("Enter Units (1-6): ");
                    if(scanf("%d", &units[subjectCount]) != 1 || 
                       units[subjectCount] < 1 || units[subjectCount] > 6) {
                        while(getchar() != '\n');
                        printf("Invalid input! Units must be between 1 and 6.\n");
                    } else {
                        break;
                    }
                } while(1);
                
                do {
                    printf("Enter Cash Fee (0-99999): ");
                    if(scanf("%f", &cashFees[subjectCount]) != 1 || 
                       cashFees[subjectCount] < 0 || cashFees[subjectCount] > 99999) {
                        while(getchar() != '\n');
                        printf("Invalid input! Fee must be between 0 and 99999.\n");
                    } else {
                        break;
                    }
                } while(1);
                
                subjectCount++;
                printf("\nSubject added successfully!\n");
                system("pause");
            }
        }
        else if (manageChoice == 2) {
            system("cls");
            if(subjectCount == 0) {
                printf("No subjects to remove!\n");
                system("pause");
                continue;
            }
            
            int removeIndex;
            printf("\nCurrent Subjects:\n");
            for(int i = 0; i < subjectCount; i++) {
                printf("%d. %s\n", i+1, subjectCode[i]);
            }
            
            do {
                printf("Enter number of subject to remove (1-%d): ", subjectCount);
                if(scanf("%d", &removeIndex) != 1 || 
                   removeIndex < 1 || removeIndex > subjectCount) {
                    while(getchar() != '\n');
                    printf("Invalid input! Please enter a number between 1 and %d.\n", subjectCount);
                } else {
                    break;
                }
            } while(1);
            
            removeIndex--;
            for(int i = removeIndex; i < subjectCount-1; i++) {
                strcpy(subjectCode[i], subjectCode[i+1]);
                units[i] = units[i+1];
                cashFees[i] = cashFees[i+1];
            }
            subjectCount--;
            printf("Subject removed successfully!\n");
            system("pause");
        }
        else if (manageChoice == 3) {
            system("cls");
            if(subjectCount == 0) {
                printf("No subjects to edit!\n");
                system("pause");
                continue;
            }
            
            int editIndex, editChoice;
            printf("\nCurrent Subjects:\n");
            printf("No.\tCode\tUnits\tFees\n");
            printf("--------------------------------\n");
            for(int i = 0; i < subjectCount; i++) {
                printf("%d.\t%s\t%d\t%.2f\n", i+1, subjectCode[i], units[i], cashFees[i]);
            }
            
            do {
                printf("\nEnter number of subject to edit (1-%d): ", subjectCount);
                if(scanf("%d", &editIndex) != 1 || 
                   editIndex < 1 || editIndex > subjectCount) {
                    while(getchar() != '\n');
                    printf("Invalid input! Please enter a number between 1 and %d.\n", subjectCount);
                } else {
                    break;
                }
            } while(1);
            
            editIndex--;
            
            do {
                printf("\nWhat would you like to edit?\n");
                printf("1. Units\n");
                printf("2. Cash Fee\n");
                printf("3. Both\n");
                printf("Enter choice: ");
                if(scanf("%d", &editChoice) != 1 || 
                   editChoice < 1 || editChoice > 3) {
                    while(getchar() != '\n');
                    printf("Invalid input! Please enter 1, 2, or 3.\n");
                } else {
                    break;
                }
            } while(1);
            
            if (editChoice == 1 || editChoice == 3) {
                do {
                    printf("Enter new Units (1-6): ");
                    if(scanf("%d", &units[editIndex]) != 1 || 
                       units[editIndex] < 1 || units[editIndex] > 6) {
                        while(getchar() != '\n');
                        printf("Invalid input! Units must be between 1 and 6.\n");
                    } else {
                        break;
                    }
                } while(1);
            }
            
            if (editChoice == 2 || editChoice == 3) {
                do {
                    printf("Enter new Cash Fee (0-99999): ");
                    if(scanf("%f", &cashFees[editIndex]) != 1 || 
                       cashFees[editIndex] < 0 || cashFees[editIndex] > 99999) {
                        while(getchar() != '\n');
                        printf("Invalid input! Fee must be between 0 and 99999.\n");
                    } else {
                        break;
                    }
                } while(1);
            }
            
            printf("Subject updated successfully!\n");
            system("pause");
        }
        else if (manageChoice == 4) {
            system("cls");
            if(subjectCount == 0) {
                printf("No subjects to display!\n");
                system("pause");
                continue;
            }
            
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t |=||==||==||             SUBJECT TABLE            ||==||==||=|\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\n");
            printf("Subject Code\tUnits\tCash Fees\n");
            printf("----------------------------------------\n");
            for(int i = 0; i < subjectCount; i++) {
                printf("%s\t\t%d\t%.2f\n", subjectCode[i], units[i], cashFees[i]);
            }
            printf("\nPress Enter to continue...");
            while(getchar() != '\n');  // Clear any leftover newlines
            getchar();
        }
        else if (manageChoice == 5) {
            system("cls");
            goto menu;
        }
        else {
            printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
            system("pause");
        }
    }

    return 0;
}
else if (choice == '3') {
    char x = 219;
    int choice;
    FILE *certFile, *clearFile;
    char line[256];
    int requestCount = 0;

    while(1) {
        // Loading animation
        printf("\n\n\n\n\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t |=||==||==||       EOG REQUEST MANAGEMENT         ||==||==||=|\n");
        printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n\n");
        printf("\t\t\t\t\t\t LOADING...\n\n");
        printf("\t\t\t\t");
        
        for(int i=1; i<=30; i++) {
            printf("%c", x);
            usleep(99999);
        }
        system("cls");

        printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t |=||==||==||       EOG REQUEST MANAGEMENT         ||==||==||=|\n");
        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n\t\t\t 1. View Certification Requests\n");
        printf("\t\t\t 2. View Clearance Requests\n");
        printf("\t\t\t 3. Process Request\n");
        printf("\t\t\t 4. Return to Main Menu\n");
        printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n'); // Clear input buffer
            printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        	printf("\t\t\t|=||==||     Invalid input! Please input a number.    ||==||=|\n");
        	printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t Press any key to continue...");
            getch();
            system("cls");
            continue;
        }
        system("cls");

        switch(choice) {
            case 1: {
                printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||       CERTIFICATION REQUESTS         ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");
                
                certFile = fopen("certification_requests.txt", "r");
                if (certFile == NULL) {
                    printf("\t\t\t No certification requests found.\n");
                } else {
                    requestCount = 0;
                    while (fgets(line, sizeof(line), certFile)) {
                        printf("\t\t\t %s", line);
                        if (strstr(line, "Status:") != NULL) {
                            printf("\t\t\t ------------------------\n");
                            requestCount++;
                            printf("\t\t\t Request #%d\n", requestCount);
                        }
                    }
                    if (requestCount == 0) {
                        printf("\t\t\t No requests found.\n");
                    }
                    fclose(certFile);
                }
                printf("\n\t\t\t Press any key to continue...");
                getch();
                system("cls");
                break;
            }
            
            case 2: {
                printf("\n\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||         CLEARANCE REQUESTS           ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n\n");
                
                clearFile = fopen("clearance_requests.txt", "r");
                if (clearFile == NULL) {
                    printf("\t\t\t No clearance requests found.\n");
                } else {
                    requestCount = 0;
                    while (fgets(line, sizeof(line), clearFile)) {
                        printf("\t\t\t %s", line);
                        if (strstr(line, "Status:") != NULL) {
                            printf("\t\t\t ------------------------\n");
                            requestCount++;
                            printf("\t\t\t Request #%d\n", requestCount);
                        }
                    }
                    if (requestCount == 0) {
                        printf("\t\t\t No requests found.\n");
                    }
                    fclose(clearFile);
                }
                printf("\n\t\t\t Press any key to continue...");
                getch();
                system("cls");
                break;
            }
            
            case 3: {
                int requestType, requestNumber;
                char tempFile[] = "temp.txt";
                FILE *source, *temp;
                int currentRequest = 0;
                char status[20];
                int maxRequests = 0;
                
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t |=||==||==||          PROCESS REQUEST             ||==||==||=|\n");
                printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                
                do {
                    printf("\n\t\t\t Request Type (1-Certification, 2-Clearance): ");
                    if (scanf("%d", &requestType) != 1 || (requestType != 1 && requestType != 2)) {
                        while (getchar() != '\n');
                        printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        				printf("\t\t\t |=||==||      Invalid input! Please enter 1 or 2.     ||==||=|\n");
        				printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                        continue;
                    }
                    break;
                } while (1);

                // Count total requests
                if (requestType == 1) {
                    source = fopen("certification_requests.txt", "r");
                } else {
                    source = fopen("clearance_requests.txt", "r");
                }

                if (source != NULL) {
                    while (fgets(line, sizeof(line), source)) {
                        if (strstr(line, "Status:") != NULL) {
                            maxRequests++;
                        }
                    }
                    fclose(source);
                }

                if (maxRequests == 0) {
                	printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        			printf("\t\t\t|=||==||         No requests found to process.        ||==||=|\n");
        			printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                    printf("\t\t\t Press any key to continue...");
                    getch();
                    system("cls");
                    break;
                }

                do {
                    printf("\t\t\t Request Number (1-%d): ", maxRequests);
                    if (scanf("%d", &requestNumber) != 1 || requestNumber < 1 || requestNumber > maxRequests) {
                        while (getchar() != '\n');
                        printf("\t\t\t Invalid request number! Please enter a number between 1 and %d.\n", maxRequests);
                        continue;
                    }
                    break;
                } while (1);

                do {
                    printf("\t\t\t Status (1-Approved, 2-Denied): ");
                    int statusChoice;
                    if (scanf("%d", &statusChoice) != 1 || (statusChoice != 1 && statusChoice != 2)) {
                        while (getchar() != '\n');
                        printf("\t\t\t Invalid input! Please enter 1 or 2.\n");
                        continue;
                    }
                    strcpy(status, statusChoice == 1 ? "Approved" : "Denied");
                    break;
                } while (1);

                if (requestType == 1) {
                    source = fopen("certification_requests.txt", "r");
                } else {
                    source = fopen("clearance_requests.txt", "r");
                }

                if (source == NULL) {
                	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            		printf("\t\t\t  |=||          Error: Could not open request file.         ||=|\n");
            		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                    printf("\t\t\t Press any key to continue...");
                    getch();
                    system("cls");
                    break;
                }

                temp = fopen(tempFile, "w");
                if (temp == NULL) {
                	
                	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            		printf("\t\t\t  |=||         Error: Could not create temporary file.      ||=|\n");
            		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                    fclose(source);
                    printf("\t\t\t Press any key to continue...");
                    getch();
                    system("cls");
                    break;
                }

                currentRequest = 0;
                int found = 0;
                while (fgets(line, sizeof(line), source)) {
                    if (strstr(line, "Status:") != NULL) {
                        currentRequest++;
                        if (currentRequest == requestNumber) {
                            fprintf(temp, "Status: %s\n\n", status);
                            found = 1;
                            continue;
                        }
                    }
                    fprintf(temp, "%s", line);
                }

                fclose(source);
                fclose(temp);

                if (!found) {
                	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            		printf("\t\t\t  |=||               Error: Request not found.              ||=|\n");
            		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                    remove(tempFile);
                } else {
                    if (requestType == 1) {
                        remove("certification_requests.txt");
                        rename(tempFile, "certification_requests.txt");
                    } else {
                        remove("clearance_requests.txt");
                        rename(tempFile, "clearance_requests.txt");
                    }
                    printf("\n\t\t\t Request #%d has been %s!\n", requestNumber, status);
                }

                printf("\t\t\t Press any key to continue...");
                getch();
                system("cls");
                break;
            }
            
            case 4:
    			system("cls");
    			goto menu;  // Replace "return 0;" with "goto menu;"
    			break;  // Although not necessary after goto, included for consistency
            
            default:
            	printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        		printf("\t\t\t|=||==||  Invalid choice! Please enter a number between 1 and 4.  ||==||=|\n");
        		printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t Press any key to continue...");
                getch();
                system("cls");
        }
    }
    return 0;
}

else if (choice == '4') {
            printf("\n\n\n\n\n");
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
            printf("\t\t\t |=||==||==||          Account logging off         ||==||==||=|\n");
            printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
            printf("\t\t\t |=||==||==||            PLEASE WAIT...            ||==||==||=|\n");
            printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");    
            printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\n\n\t\t\t\t\t");
            
            for(int i=1; i<=30; i++) {
                printf("%c", x);
                usleep(99999);
            }
            system("cls");
            return 1;
        }
        else {
            printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            printf("\t\t\t  |=||     Error, Please choose from the choices below.     ||=|\n");
            printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
            goto menu;
        }
    }
}

int login() {
    char id[MAX_ID_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int validInput = 0;
    char choice;
    
    do {
        system("cls");
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
        
        // Clear input buffer
        fflush(stdin);
        
        printf("\t\t\t >>  Enter user ID number: ");
        if (fgets(id, sizeof(id), stdin) != NULL) {
            // Remove newline
            id[strcspn(id, "\n")] = 0;
        }

        printf("\n\t\t\t >>  Enter password: ");
        if (fgets(password, sizeof(password), stdin) != NULL) {
            // Remove newline
            password[strcspn(password, "\n")] = 0;
        }

        // Check credentials against loaded data
        for (int i = 0; i < userCount; i++) {
            if (strcmp(ids[i], id) == 0 && strcmp(passwords[i], password) == 0) {
                system("cls");
                printf("\n\n\n\n");
                printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
                printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
                printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\n");
                printf("\t\t\t  [] Welcome to PhilTech Management System \n");
                printf("\t\t\t  [] Welcome, user: %s! \n", usernames[i]);
                printf("\n");
                printf("\t\t\t  [] Press any key to continue...");
                printf("\n\n");
                printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
                printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
                printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
                getch();
                system("cls");

                // Route to appropriate menu based on role
                if (roles[i] == STUDENT) {
                    return studentMenu();
                } else if (roles[i] == ADMIN) {
                    if (specificRoles[i] == TEACHER) {
                        return teacherMenu();
                    } else if (specificRoles[i] == ADMINISTRATOR) {
                        return administratorMenu();
                    } else if (specificRoles[i] == REGISTRAR) {
                        return registrarMenu();
                    }
                }
                return 1; // Success
            }
        }
        
        system("cls");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
        printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("\t\t\t\t\t  [] >>====================<< []\n");
        printf("\t\t\t\t\t  [] >>  Invalid credentials << []\n");
        printf("\t\t\t\t\t  [] >>====================<< []\n");
        printf("\n\t\t\t >>  Try again? (Y/N): ");
        
        choice = getch();
        if (toupper(choice) != 'Y') {
            return 0; // User chose not to try again
        }
        
    } while (1);
}

int main() {
    // Set console title (Windows only)
    system("title PhilTech School Management System");
    
    // Load users at program start
    if (!loadUsers()) {
        system("cls");
        printf("\n\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
        printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("\t\t\t\t\t  [] >>====================<< []\n");
        printf("\t\t\t\t\t  [] >>  INITIALIZATION    << []\n");
        printf("\t\t\t\t\t  [] >>====================<< []\n");
        printf("\n");
        printf("\t\t\t  []  No existing user data found. Starting fresh database.  []\n");
        printf("\t\t\t  []  This is first time running or data file was deleted.  []\n");
        printf("\t\t\t  []  A new database will be created for user accounts..    []\n");
        printf("\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
        printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
        printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
        printf("\n");
        printf("\t\t\t >>  Press any key to continue...");
        getch();
    }
    
    int choice;
    while (1) {
        system("cls");
        system("color 02");
        printf("\n\n");
        printf("   ==================================================================================================================\n");
        printf("   []            #########                                                                   #########             []\n");
        printf("   []            #########                ___________________________________                #########             []\n");
        printf("   []            #########                                                                   #########             []\n");
        printf("   []            #########                 PHILTECH SCHOOL MANAGEMENT SYSTEM                 #########             []\n");
        printf("   []            #########                ___________________________________                #########             []\n");
        printf("   []            #########                                                                   #########             []\n");
        printf("   []            #########                                                                   #########             []\n");
        printf("   []            ###   ###                 PHILTECH GIVES QUALITY EDUCATION                  ###   ###             []\n");
        printf("   []            ##     ##              _______________________________________              ##     ##             []\n");
        printf("   []                                 ___________________________________________                                  []\n");
        printf("   []                                |                                           |                                 []\n");
        printf("   []                                |  [] 1. Sign Up                        []  |                                 []\n");
        printf("   []                                |                                           |                                 []\n");
        printf("   []                                |  [] 2. Log In                         []  |                                 []\n");
        printf("   []                                |                                           |                                 []\n");
        printf("   []                                |  [] 3. Exit                           []  |                                 []\n");
        printf("   []                                |___________________________________________|                                 []\n");
        printf("   []                                                                                                              []\n");
        printf("   []                                                                                                              []\n");
        printf("   []                                                                                                              []\n");
        printf("   []     >> To choose, Press the number of the key                                                                []\n");
        printf("   []                                                                                                              []\n");
        printf("   ==================================================================================================================\n");
        
        choice = getch();
        
        switch (choice) {
            case '1':
                system("cls");
                if (!signup()) {
                    printf("\n\t\t\t >>  Signup failed. Please try again.\n");
                    printf("\n\t\t\t >>  Press any key to continue...");
                    getch();
                }
                break;
                
            case '2':
                system("cls");
                if (!login()) {
                    printf("\n\t\t\t >>  Returning to main menu...\n");
                    printf("\n\t\t\t >>  Press any key to continue...");
                    getch();
                }
                break;
                
            case '3':
                system("cls");
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
                printf("\n\t\t\t >>  Invalid choice. Please try again.\n");
                printf("\n\t\t\t >>  Press any key to continue...");
                getch();
                break;
        }
    }
    return 0;
}

