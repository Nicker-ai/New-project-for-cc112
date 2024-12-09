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
		printf("hello studentattendance");
		return 0;
	}
	if (choice == '2'){
		printf("hello teachersattendance");
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
	printf("\t\t\t\t\t > [2]  Manage EOG Request  [2]\n");
	printf("\t\t\t\t\t > [3]   Mark  Attendance   [3]\n");
	printf("\t\t\t\t\t > [4]  About Us (Philtech) [4]\n");
	printf("\t\t\t\t\t > [5]         Exit         [5]\n");
	printf("\n\n\n");
	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\t\t\t  |=||==||==||  PRESS THE NUMBER YOU WANT TO CHECK  ||==||==||=|\n");
	printf("\t\t\t  [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\n");
	choice = getch();
	system ("cls");

	if (choice == '1'){
		printf("hello studentattendance");
		return 0;
	}
	if (choice == '2'){
		printf("hello teachersattendance");
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

