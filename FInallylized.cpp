#include <stdio.h> // main head
#include <stdlib.h> // for system cls statement
#include <string.h> // for space creating string prevention
#include <unistd.h> // for usleep statement
#include <iostream> // for special character symbols
#include <conio.h> // for color coding statement and input 	
using namespace std; // for loading and color statement

void green () {
	printf("\033[0;32m");
}
void yellow () {
	printf("\033[0;33m");
}
void red () {
	printf("\033[0;31m");
}
void cyan () {
	printf("\033[0;36m");
}
void white () {
	printf("\033[0;37m");
}

#define MAX_USERS 10
#define MAX_EMAIL_LENGTH 50
#define MAX_PASSWORD_LENGTH 20
#define MAX_USERNAME_LENGTH 20

// Define roles
#define STUDENT 1
#define TEACHER 2

// Global variables
char usernames[MAX_USERS][MAX_USERNAME_LENGTH];
char emails[MAX_USERS][MAX_EMAIL_LENGTH];
char passwords[MAX_USERS][MAX_PASSWORD_LENGTH];
int roles[MAX_USERS];
int userCount = 0;

int checkGmail(char email[]) {
    int length = strlen(email);
    const char* target = "@gmail.com";
    int targetLength = strlen(target);

    // Check if "@gmail.com" is present at the end of the email
    if (length >= targetLength) {
        int match = 1;
        for (int i = 1; i <= targetLength; i++) {
            if (email[length - i] != target[targetLength - i]) {
                match = 0;
                break;
            }
        }
        return match;
    }
    return 0;
}

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
    printf("\t\t\t >>  Enter email: ");
    scanf("%s", emails[userCount]);
    while (!checkGmail(emails[userCount])) {
        printf("\n\t\t\t >>  Invalid Gmail address. Please enter a valid Gmail address. \n\t\t\t >>  Enter email:");
        scanf("%s", emails[userCount]);
    }
    printf("\n\n");
    printf("\t\t\t >>  Enter password: ");
    scanf("%s", passwords[userCount]);
    printf("\n");
    printf("\t\t\t\t\t     >>  Choose your role: <<  \n");
    printf("\n");
    printf("\t\t\t\t\t  [] >>====================<< []\n");
    printf("\t\t\t\t\t  || (1) Student  (2) Teacher || \n");
    printf("\t\t\t\t\t  [] >>====================<< []\n");
    printf("\t\t\t\t\t         >> CHOICE: ");
    scanf("%d", &roles[userCount]);
    userCount++;
    system("cls");
    printf("\t\t\t\t\t  [] >>====================<< []\n");
	printf("\t\t\t\t\t  [] >>REGISTRATION SUCCESS<< []\n");
	printf("\t\t\t\t\t  [] >>====================<< []\n");
	printf("\n");
    return 0;
}

int studentMenu() {
    int choice;
	char x=219;
	
	
	system("color 30");
	printf("\n\n\n\n\n");
	printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
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
	system("color 30");
	printf("\n");
	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
	printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\n\t\t\t\t     [] Philtech School Management System []\n");
	printf("\t\t\t\t     [][]  Choose what you want to use  [][]\n");
	printf("\n\n");
	printf("\t\t\t\t\t > [1]      Enrollment      [1]\n");
	printf("\t\t\t\t\t > [2]  Submit EOG Request  [2]\n");
	printf("\t\t\t\t\t > [3] Classroom management [3]\n");
	printf("\t\t\t\t\t > [4]  About Us (Philtech) [4]\n");
	printf("\t\t\t\t\t > [5]        Log out       [5]\n");
	printf("\n\n\n");
	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\t\t\t  |=||==||==||  PRESS THE NUMBER YOU WANT TO CHECK  ||==||==||=|\n");
	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\n");
	choice = getch();
	system ("cls");

	if (choice == '1'){
	int choice;

    while (1) {
        printf("\n== College Student Enrollment System ==\n");
        printf("1. About Us\n");
        printf("2. Enrollment Form\n");
        printf("3. Subject Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Philtech provides quality education.\n");
                break;
            case 2:
                goto enrollmentForm;
                break;
            case 3:
                goto subjectTable;
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

return 0;


enrollmentForm:
    char name[50], address[100], email[50], contact[15];
    int age, courseChoice;

    printf("=== Enrollment Form ===\n");
    printf("Name: ");
    scanf(" %[^\n]", name);
    printf("Age: ");
    scanf("%d", &age);
    printf("Address: ");
    scanf(" %[^\n]", address);
    printf("Email: ");
    scanf(" %[^\n]", email);
    printf("Contact: ");
    scanf(" %[^\n]", contact);

    printf("Select Course (1-3): ");
    printf("1. BSCS\n");
    printf("2. BTVTLED\n");
    printf("3. EDUC\n");
    scanf("%d", &courseChoice);

    printf("\n=== Enrollment Details ===\n");
    printf("Name: %s\n", name);
    printf("Age: %d\n", age);
    printf("Address: %s\n", address);
    printf("Email: %s\n", email);
    printf("Contact: %s\n", contact);

    printf("Chosen Course: ");
    switch(courseChoice) {
        case 1:
            printf("BSCS\n");
            break;
        case 2:
            printf("BTVTLED\n");
            break;
        case 3:
            printf("EDUC\n");
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;


subjectTable:
    char subjectCode[10][10] = {"GE111", "GE112", "CC111", "CC112", "AS111", "GE124", "PE111", "NSTP111"};
    int units[8] = {3, 3, 3, 3, 2, 3, 2, 3};
    float cashFees[8] = {22.00, 400.00, 8800.00, 1000.00, 2400.00, 4100.00, 850.00, 17150.00};

    printf("Subject Code\tUnits\tCash Fees\n");
    for (int i = 0; i < 8; i++) {
        printf("%s\t%d\t%.2f\n", subjectCode[i], units[i], cashFees[i]);
    }
    return 0;
	}
	if (choice == '2'){
		
	int choice;
	char none[50];
	char studentID[50];
    char purpose[100];
    char requestDate[20];
    char additionalNotes[200];
	char decision;
	system("cls");
	
	
	printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
	printf("\t\t\t|=||                                                      ||=|\n");
	printf("\t\t\t|                       REQUEST CHOICES:                     |\n");
	printf("\t\t\t|                                                            |\n");
	printf("\t\t\t|                      (1) TRANSCRIPT                        |\n");
	printf("\t\t\t|                      (2) CERTIFICATION                     |\n");
	printf("\t\t\t|                      (3) CLEARANCE                         |\n");
	printf("\t\t\t|=||                                                      ||=|\n");
	printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
	printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	
	choice = getch();
	system("cls");
	
		if(choice == '1'){
			goto Transcript;
	}
		if(choice == '2'){
			goto Certification;
	}
		if(choice == '3'){
			goto Clearance;
	}
	
	return 0;
	
	Transcript: // transcript section
    	
	printf("Enter Student ID Number: ");
    fgets(studentID, sizeof(studentID), stdin);
    
   	printf("Enter Purpose (e.g., Job application, transfer): ");
    fgets(purpose, sizeof(purpose), stdin);

    printf("Enter Request Date (YYYY-MM-DD):  ");
    fgets(requestDate, sizeof(requestDate), stdin);

    printf("Enter Additional Notes (e.g., Urgency, preferred format): ");
    fgets(additionalNotes, 			sizeof(additionalNotes), stdin);
    	
    printf("is the statement is correct? ( Y | N ):");
	decision = getch();
	system("cls");
	
	if (decision == 'Y' || decision == 'y'){
	printf("\n>> Collected Student Request Details:\n");
  	printf("* Request Type: Transcript\n");
  	printf("* Student ID Number: %s", studentID);
	printf("* Purpose: %s", purpose);
	printf("* Request Date: %s", requestDate);
	printf("* Additional Notes: %s", additionalNotes);
	printf("\n\nPress any key to return to menu");
    int stopper = getch();
    system("cls");
	}
	else if (decision == 'n' || decision == 'N'){
		goto Transcript;
	}
	else if (decision != 'n' || decision != 'y'){
		printf("!!! Error, User decision cannot be identified, Please repeat the process !!!\n\n");
		goto Transcript;
	}
	return 0;
	
	
	Certification: // certification section
		 
	printf("Enter Student ID Number: ");
    fgets(studentID, sizeof(studentID), stdin);
    
 	printf("Enter Purpose (e.g., Job application, transfer): ");
  	fgets(purpose, sizeof(purpose), stdin);
  	
  	printf("Enter Request Date (YYYY-MM-DD): ");
  	fgets(requestDate, sizeof(requestDate), stdin);
  	
   	printf("Enter Additional Notes (e.g., Urgency, preferred format): ");
    fgets(additionalNotes, sizeof(additionalNotes), stdin);
    
	printf("is the statement is correct? ( Y | N ):");
	decision = getch();
	system("cls");
	
	if (decision == 'Y' || decision == 'y'){
	printf("\nCollected Student Request Details:\n");
  	printf("Request Type: Certification\n");
  	printf("Student ID Number: %s", studentID);
	printf("Purpose: %s", purpose);
	printf("Request Date: %s", requestDate);
	printf("Additional Notes: %s", additionalNotes);
	printf("Press any key to return to menu");
	}
	else if (decision == 'n' || decision == 'N'){
		goto Certification;
	}
	else if (decision != 'n' || decision != 'y'){
		printf("!!! Error, User decision cannot be identified, Please repeat the process !!!\n\n");
		goto Certification;
	}
	
	
	Clearance: // clearance section
	 
	printf("Enter Student ID Number: ");
   	fgets(studentID, sizeof(studentID), stdin);
   	
    printf("Enter Purpose (e.g., Job application, transfer): ");
	fgets(purpose, sizeof(purpose), stdin);
	
  	printf("Enter Request Date (YYYY-MM-DD): ");
  	fgets(requestDate, sizeof(requestDate), stdin);
  	
  	printf("Enter Additional Notes (e.g., Urgency, preferred format): ");
 	fgets(additionalNotes, sizeof(additionalNotes), stdin);
 	
    printf("is the statement is correct? ( Y | N ):");
	decision = getch();
	system("cls");
	
	if (decision == 'Y' || decision == 'y'){
    printf("\nCollected Student Request Details:\n");
    printf("Request Type: Transcript\n");
    printf("Student ID Number: %s", studentID);
    printf("Purpose: %s", purpose);
    printf("Request Date: %s", requestDate);
    printf("Additional Notes: %s", additionalNotes);
    printf("Press any key to return to menu");
	}
	else if (decision == 'n' || decision == 'N'){
		goto Clearance;
	}
	else if (decision != 'n' || decision != 'y'){
		printf("!!! Error, User decision cannot be identified, Please repeat the process !!!\n\n");
		goto Clearance;
	}
	return 0;
	}
	if (choice == '3'){
		printf("hello enrollment");
		return 0;
	}
	if (choice == '4'){
		goto about;
		return 0;
	}
	if (choice == '5'){
		system("color 30");
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
		}
	else {
		system("cls");
		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\t\t\t  |=||     Error, Please choose from the choices below.     ||=|\n");
		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		goto menu;
	} 
	return 0;

	
	
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

int teacherMenu() {
int choice;
	char x=219;
	
	
	system("color 30");
	printf("\n\n\n\n\n");
	printf("\t\t\t [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\t\t\t |=||==||==||                                      ||==||==||=|\n");
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
	system("color 30");
	printf("\n");
	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
	printf("\t\t\t  |=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\n\t\t\t\t     [] Philtech School Management System []\n");
	printf("\t\t\t\t     [][]  Choose what you want to use  [][]\n");
	printf("\n\n");
	printf("\t\t\t\t\t > [1] Classroom Management [1]\n");
	printf("\t\t\t\t\t > [2]   Mark  Attendance   [2]\n");
	printf("\t\t\t\t\t > [3]  About Us (Philtech) [3]\n");
	printf("\t\t\t\t\t > [4]        Log out       [4]\n");
	printf("\n\n\n");
	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\t\t\t  |=||==||==||  PRESS THE NUMBER YOU WANT TO CHECK  ||==||==||=|\n");
	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\n");
	choice = getch();
	system ("cls");

	if (choice == '1'){
		
	int choice;

    do {
        printf("\nChoose a teacher (or 0 to finish):\n");
        printf("1. Allan Velle\n");
        printf("2. Jude Rodriguez\n");
        printf("3. Nori Lacer\n");
        printf("4. Raiven Gordon\n");
        printf("5. Carl Joseph\n");
        printf("6. Michael Atienza\n");
        printf("7. Return to menu\n");
        printf("Enter your choice number: ");

        scanf("%d", &choice);

        #ifdef _WIN32
            system("cls"); 
        #else
            system("clear");
        #endif


        if (choice == 1) {
            printf("Allan Velle - Saturday 7:00 am - 10:00 am\n");
            printf("Understanding the Self (Ge1)\n");
        } else if (choice == 2) {
            printf("Jude Rodriguez - Saturday 10:00 am - 1:00 pm\n");
            printf("Mathematics in the modern world (Ge2)\n");
        } else if (choice == 3) {
            printf("Nori Lacer - Saturday 1:00 pm - 4:00 pm\n");
            printf("Readings in the Philippines History (Ge3)\n");
        } else if (choice == 4) {
            printf("Raiven Gordon - Monday 9:00 am - 2:00 pm\n");
            printf("Introduction to computing with Productivity Tool (Cc111)\n");
        } else if (choice == 5) {
            printf("Carl Joseph - Thursday 7:00 am - 12:00 pm\n");
            printf("Fundamentals of Programming 1 (Cc112)\n");
        } else if (choice == 6) {
            printf("Michael Atienza - Tuesday/Wednesday\n");
            printf("Tuesday 7:00 am - 8:45 am: Physical activities towards health and fitness 1 (Pathfit1)\n");
            printf("Wednesday 9:00 am - 12:00 pm: National service training Program 1 (Nstp1)\n");
            printf("Wednesday 12:00 pm - 1:00 pm:  Philtech Life and spirit (Pls)\n");
        } else if (choice == 7) {
        	system("cls");
        	goto menu;
        } else if (choice != 0) {
            printf("Invalid choice.\n");
        }

    } while (choice != 0);

    printf("\nFinished.\n"); 
    return 0;
}
		
	if (choice == '2'){
		
    int teacherChoice, subjectChoice;
    char status[10];
    int statusChoice, numStudents = 30;

    // Teacher's names
    char* teachers[] = {
        "Atienza, Michael", "Jimenez, Carl Joseph", "Lacer, Nori Ann", 
        "Gordon, Raiven Neil", "Rodriguez, Jude Alfonso", "Vele, Allan"
    };
    
    // List of subjects per teacher
    char* subjects[6][3] = {
        {"PATHFIT", "NSTP", "PLS"},
        {"CC112"},
        {"GE3"},
        {"CC111"},
        {"GE2"},
        {"GE1"}
    };

    // List of students
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
    
    // Step 1: Teacher selection
    printf("Choose Teacher:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d. %s\n", i + 1, teachers[i]);
    }
    
    while (1) {
        printf("Enter your choice (1-6): ");
        if (scanf("%d", &teacherChoice) == 1 && teacherChoice >= 1 && teacherChoice <= 6) {
            break;
        }
        while (getchar() != '\n'); // Clear invalid input
        printf("Invalid input. Please enter a number between 1 and 6.\n");
    }
    
    printf("You selected: %s\n", teachers[teacherChoice - 1]);

    // Step 2: Choose subject based on teacher
    printf("\nChoose Subject:\n");

    int numSubjects = sizeof(subjects[teacherChoice - 1]) / sizeof(subjects[teacherChoice - 1][0]);
    for (int i = 0; i < numSubjects; i++) {
        printf("%d. %s\n", i + 1, subjects[teacherChoice - 1][i]);
    }

    while (1) {
        printf("Enter your choice (1-%d): ", numSubjects);
        if (scanf("%d", &subjectChoice) == 1 && subjectChoice >= 1 && subjectChoice <= numSubjects) {
            break;
        }
        while (getchar() != '\n'); // Clear invalid input
        printf("Invalid input. Please enter a number between 1 and %d.\n", numSubjects);
    }
    
    printf("You selected: %s\n", subjects[teacherChoice - 1][subjectChoice - 1]);
    
    // Step 3: Record student attendance for the selected subject
    printf("\nAttendance for Teacher: %s - Subject: %s\n", teachers[teacherChoice - 1], subjects[teacherChoice - 1][subjectChoice - 1]);

    for (int i = 0; i < numStudents; i++) {
        if ((strcmp(subjects[teacherChoice - 1][subjectChoice - 1], "NSTP") == 0 || strcmp(subjects[teacherChoice - 1][subjectChoice - 1], "PATHFIT") == 0) &&
            strcmp(students[i], "Abella, Ghanda Mar") == 0) {
            printf("Skipping attendance for %s (not applicable for this subject).\n", students[i]);
            continue;
        }

        while (1) {
            printf("Enter attendance for %s (1 = present, 2 = absent, 3 = excused): ", students[i]);
            if (scanf("%d", &statusChoice) == 1 && statusChoice >= 1 && statusChoice <= 3) {
                switch (statusChoice) {
                    case 1: strcpy(status, "present"); break;
                    case 2: strcpy(status, "absent"); break;
                    case 3: strcpy(status, "excused"); break;
                }
                printf("%s is marked as %s under teacher %s - Subject: %s.\n", students[i], status, teachers[teacherChoice - 1], subjects[teacherChoice - 1][subjectChoice - 1]);
                break;
            }
            while (getchar() != '\n'); // Clear invalid input
            printf("Invalid input. Please enter a number (1, 2, or 3).\n");
        }
    }

    return 0;
}


		
	if (choice == '3'){
		goto about;
		return 0;
	}
	if (choice == '4'){
		system("color 30");
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
		}
	else {
		system("cls");
		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\t\t\t  |=||     Error, Please choose from the choices below.     ||=|\n");
		printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		goto menu;
	} 
	return 0;

	
	
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



int login() {
    char email[MAX_EMAIL_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int role = 0;

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
    printf("\t\t\t >>  Enter email: ");
    scanf("%s", email);
    while (!checkGmail(email)) {
        printf("\n\t\t\t >>  Invalid Gmail address. Please enter a valid Gmail address. \n\t\t\t >>  Enter email:");
        scanf("%s", email);
    }

    printf("\n\n");
    printf("\t\t\t >>  Enter password: ");
    scanf("%s", password);
    
    system("cls");

    for (int i = 0; i < userCount; i++) {
        if (strcmp(emails[i], email) == 0 && strcmp(passwords[i], password) == 0) {
            printf("\t\t\t\t\t   >> Welcome, %s! <<\n", usernames[i]);
            role = roles[i];
            break;
        }
    }

    if (role == 0) {
        printf("Invalid credentials!\n");
        return 0;
    }

    if (role == STUDENT) {
        studentMenu();
    } else if (role == TEACHER) {
        teacherMenu();
    }
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
    }

