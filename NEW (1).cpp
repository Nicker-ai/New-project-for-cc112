#include <stdio.h> // main head
#include <stdlib.h> // for system cls statement
#include <string.h> // for space creating string prevention
#include <unistd.h> // for usleep statement
#include <iostream> // for special character symbols
#include <conio.h> // for color coding statement
using namespace std; // for color coding

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

int main(){
	
	int menuchoice;
	char decision;
	char x=219;
	
	system("color 30");
	printf("\n\n\n\n\n");
	printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
	printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
	printf("\t\t\t|=||==||==||     PROGRAM LOADING IS IN PROCESS    ||==||==||=|\n");
	printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
	printf("\t\t\t|=||==||==||            PLEASE WAIT...            ||==||==||=|\n");
	printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");	
	printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
	printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t");
	
	printf("\n\n");
	printf("\n\t\t\t\t\t");
	for(int i=1; i<=30; i++)
	{
		green();
		cerr<<x;
		usleep(99990);
	}
	system("cls");
	
	main_menu: // jump option of main menu of the program
		system("color 30");
		printf("\n");
		printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\t\t\t|=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
		printf("\t\t\t|=||==||==||==||==||==||==||==||==||==||==||==||==||==||==||=|\n");
		printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\n\t\t\t\t   [] Philtech School Management System []\n");
		printf("\t\t\t\t   [][]  Choose what you want to use  [][]\n");
		printf("\n\n");
		printf("\t\t\t\t\t[1] Student's attendance [1]\n");
		printf("\t\t\t\t\t[2] Teacher's attendance [2]\n");
		printf("\t\t\t\t\t[3]      Enrollment      [3]\n");
		printf("\t\t\t\t\t[4]      EOG Request     [4]\n");
		printf("\t\t\t\t\t[5] Classroom management [5]\n");;
		printf("\n\n\n");
		printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\t\t\t|=||==||      ENTER THE NUMBER YOU WANT TO CHECK      ||==||=|\n");
		printf("\t\t\t|=||==||        ENTER ( 6 ) KEY TO END PROGRAM        ||==||=|\n");
		printf("\t\t\t|=||==|| ENTERING OTHER INPUT TERMINATES THE PROGRAM  ||==||=|\n");
		printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\n");
		printf("\n\t\t\t\t\t\tDECISION == ");
		scanf(" %d", &menuchoice);
		system ("cls"); 
		
		if ( menuchoice == 1){
			goto studentattendance;
		}
		if ( menuchoice == 2){
			goto teachersattendance;
		}
		if ( menuchoice == 3){
			goto enrollment;
		}
		if ( menuchoice == 4){
			goto eogrequest;
		}
		if ( menuchoice == 5){
			goto classroommanagement;
		}
		if ( menuchoice >= 7){
			goto numberlimit;
		}
		if ( menuchoice <= 0){
			goto errorcommand;
		}
		if ( menuchoice == 6){
			goto endprogram;
		}
		else{
			goto errorcommand;	
		}
		return 0; // serves as barrier to section of codes
		
		
		studentattendance:
			printf("hello studentattendance");
			return 0;
		teachersattendance:
			printf("hello teachersattendance");
			return 0;
		enrollment:
			printf("hello enrollment");
			return 0;
		eogrequest:
			printf("hello eogrequest");
			return 0;
		classroommanagement:
			printf("hello classroommanagement");
			return 0;
		
		
		
		
		numberlimit: // acts as jumping point if the user input exceeds the highest number in the choice
			system ("color 75");
			printf("\n\n\n");
			printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
			printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
			printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
			printf("\t\t\t|=||==||==||           XX             XX          ||==||==||=|\n");
			printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
			printf("\t\t\t|=||==||==||              ___________             ||==||==||=|\n");
			printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
			printf("\t\t\t|=||==||==||    INPUT CHOICE IS NOT ON THE LIST   ||==||==||=|\n");
			printf("\t\t\t|=||==||==||    ENTER (Y) KEY TO RETURN TO MENU   ||==||==||=|\n");
			printf("\t\t\t|=||==||==||     ENTER (X) KEY TO END PROGRAM     ||==||==||=|\n");
			printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
			printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
			printf("\n");
			printf("\t\t\t==============================================================\n");
			printf("\t\t\t[][][] > ENTERING OTHER INPUT TERMINATES THE PROGRAM  [][][][]\n");
			printf("\t\t\t==============================================================\n");
			printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
			printf("\n\t\t\t\t\t\tDECISION == ");
			
			scanf("%s", &decision);
			system("cls");
			
			if (decision == 'Y' || decision == 'y'){
					goto main_menu;
				}
			else if
				(decision == 'x' || decision == 'X'){
					goto endprogram;
				}
			else {
					goto errorcommand;
			}
			return 0;
			
		
		
		errorcommand: // serves as jumping point if the user input didn't meet the conditions
			system("color C0");
			printf("\n");
			printf("\t\t           &&&&&&&               ########################                 &&&&&&&\n");
			printf("\t\t         &&&&&&&&&              ############################             &&&&&&&&&\n");
			printf("\t\t           &&&&&&&&&&        #################################        &&&&&&&&&&\n");
			printf("\t\t       &&&&&&&&&&&&&&&&&&&& ################################### &&&&&&&&&&&&&&&&&&&&\n");
			printf("\t\t        &&&&&&&&&&&&&&&&&& #################################### &&&&&&&&&&&&&&&&&&\n");
			printf("\t\t         &&&&&     &&&&&&& #######      ############      ###### &&&&&&&    &&&&&\n");
			printf("\t\t                        && ######        ##########        ##### &&\n");
			printf("\t\t                           ######        ##########        ##### \n");
			printf("\t\t                           #######      ############      ###### \n");
			printf("\t\t                            ################   ################ \n");
			printf("\t\t                             ##############     ############## \n");
			printf("\t\t                              #############  #  ############# \n");
			printf("\t\t                            &&& ########################### &&& \n");
			printf("\t\t                        &&&&&&&& ######################## &&&&&&&& \n");
			printf("\t\t                    &&&&&&&&&&&&  ### ### ## ### ### ###  &&&&&&&&&&&& \n");
			printf("\t\t           &&&  &&&&&&&&&&&&&&    ### ### ## ### ### ###    &&&&&&&&&&&&&&  &&&  \n");
			printf("\t\t          &&&&&&&&&&&&&&&         ### ### ## ### ### ###         &&&&&&&&&&&&&&& \n");
			printf("\t\t           &&&&&&&&&&&           ########################           &&&&&&&&&&& \n");
			printf("\t\t             &&&&&&&             ########################             &&&&&&& \n");
			printf("\t\t           &&&&&&&&                ####################                &&&&&&&& \n");
			printf("\t\t             &&&&                                                        &&&&  \n"); 
			printf("\n");
			printf("\t\t              [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
			printf("\t\t              |=||==||==||    INPUT CHOICE IS NOT ON THE LIST   ||==||==||=|\n");
			printf("\t\t              [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
			return 0; // serves as barrier to section of codes
			
			
		endprogram: // activates if the user decides to end the program
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

			return 0; // serves as barrier to section of codes
		
	}
	
	
		
