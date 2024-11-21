#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <unistd.h>



int main(){
	
	int leaderboards,atktype1,atktype2;
	int score,wins,loses;
	int command1,command2,command3,checker;
	int player1score = 0;
	int player2score = 0;
	int round = 0;
	
	
	
	system ("color 30");
	printf("\n\n");
	printf("\t\t\t\t\t   ROCK | PAPER | SCISSORS\n");
	printf("\n");
	printf("\t\t\t\t\t    [ The Championships ]\n");
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t=-----------=\n");
	printf("\t\t\t\t\t\t|   START   |\n");
	printf("\t\t\t\t\t\t=-----------=\n");
	printf("\n");
	printf("\t\t\t\t\t\t=-----------=\n");
	printf("\t\t\t\t\t\t|   EXIT.   |\n");
	printf("\t\t\t\t\t\t=-----------=\n");
	printf("\n\n\n");
	printf("\t\t\t\t\t    (1) START || (2) EXIT\n");
	command1 = getch();
	system("cls");
	
	if(command1 == '2'){
		printf("\n\n");
		printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
		printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
		printf("\t\t\t|=||==||==||            0              0          ||==||==||=|\n");
		printf("\t\t\t|=||==||==||             _            _           ||==||==||=|\n");
		printf("\t\t\t|=||==||==||              -__________-            ||==||==||=|\n");
		printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
		printf("\t\t\t|=||==||==||     THANKYOU FOR PLAYING THIS GAME   ||==||==||=|\n");
		printf("\t\t\t|=||==||==||                GOODBYE!!             ||==||==||=|\n");
		printf("\t\t\t|=||==||==||                                      ||==||==||=|\n");
		printf("\t\t\t[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]\n");
		return 0;
	}
	
	printf("\n\n\n\n\n");
	printf("\t\t\t\t\t\tENTER PLAYER TYPE:\n");
	printf("\n\n");
	printf("\t\t\t\t\t\t  (1) PLAYER 1.\n");
	printf("\t\t\t\t\t\t  (2) PLAYER 2.\n");
	printf("\n\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	command2 = getch();
	
	if (command2 == '1'){
		printf("\n\n");
		printf("\t\t\t\t\t");
		printf("     YOU HAVE CHOSEN PLAYER 1\n");
		printf("\n\n");
		printf("\t\t\t\t\t\t  LOADING");
	}
	if (command2 == '2'){
		printf("\n\n");
		printf("\t\t\t\t\t");
		printf("     YOU HAVE CHOSEN PLAYER 2\n");
		printf("\n\n");
		printf("\t\t\t\t\t\t  LOADING");
	}
	
	system("cls");
	
while (round <= 4) {
	attack:

	printf("\n\n\n");
	printf("\t\t\t\t\t       FIRST PLAYER TURN\n");
	printf("\t\t\t\t\t    CHOOSE YOUR ATTACK TYPE:");
	printf("\n\n");
	printf("\t\t\t\t (1) ROCK\n");
	printf("\t\t\t\t (2) PAPER\n");
	printf("\t\t\t\t (3) SCISSOR\n");
	printf("\n\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	atktype1 = getch();
	printf("\n\n");
	printf("\t\t\t\t   ");
	switch (atktype1) {
		case '1':
			printf("PLAYER HAS CHOSEN THE ATTACK TYPE [ ROCK ]\n");
			break;
		case '2':
			printf("PLAYER HAS CHOSEN THE ATTACK TYPE [ PAPER ]\n");
			break;
		case '3':
			printf("PLAYER HAS CHOSEN THE ATTACK TYPE [ SCISSOR ]\n");
			break;
		default:
			system("cls");
			printf("\t\t\t\t  [ ERROR, USER ATTACK CHOICE IS NOT IN THE LIST ]\n");
			goto attack;
			break;
	}
	printf("\n\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\n");
	printf("\t\t\t\t\tYOUR OPPONENT IS NEXT TO CHOOSE\n");
	printf("\t\t\t\t\tARE YOU SURE ABOUT YOUR ATTACK?\n");
	printf("\t\t\t\t\t      (1) YES || (2) NO\n");
	checker = getch();
	
	if (checker == '2'){
		system("cls");
		goto attack;
		return 0;
	}
	
	system("cls");
	opponent:
	printf("\n\n\n");
	printf("\t\t\t\t\t         OPPONENT PLAYER TURN\n");
	printf("\t\t\t\t\t    CHOOSE THE OPPONENT ATTACK TYPE:");
	printf("\n\n");
	printf("\t\t\t\t (1) ROCK\n");
	printf("\t\t\t\t (2) PAPER\n");
	printf("\t\t\t\t (3) SCISSOR\n");
	printf("\n\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	atktype2 = getch();
	printf("\n\n");
	printf("\t\t\t\t   ");
	switch (atktype2) {
		case '1':
			printf("OPPONENT HAS CHOSEN THE ATTACK TYPE [ ROCK ]\n");
			break;
		case '2':
			printf("OPPONENT HAS CHOSEN THE ATTACK TYPE [ PAPER ]\n");
			break;
		case '3':
			printf("OPPONENT HAS CHOSEN THE ATTACK TYPE [ SCISSOR ]\n");
			break;
		default:
			system("cls");
			printf("\t\t\t\t  [ ERROR, USER ATTACK CHOICE IS NOT IN THE LIST ]\n");
			goto attack;
			break;
	}
	printf("\n\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	printf("\n\n");
	printf("\t\t\t\t\tYOUR OPPONENT IS NEXT TO CHOOSE\n");
	printf("\t\t\t\t\tARE YOU SURE ABOUT YOUR ATTACK?\n");
	printf("\t\t\t\t\t      (1) YES || (2) NO\n");
	checker = getch();
	
	if (checker == '2'){
		system("cls");
		goto opponent;
		return 0;
	}
	
	system("cls");
	
	if (atktype1 == '1'){
		switch (atktype2){
			case '1':
				printf("DRAW\n");
				break;
			case '2':
				printf("OPPONENT WON WITH THE PAPER TYPE ATTACK\n");
				player2score++;
				break;
			case '3':
				printf("FIRST PLAYER WON THE MATCH WITH THE ROCK TYPE ATTACK\n");
				player1score++;
				break;
				
		}
	}
		if (atktype1 == '2'){
		switch (atktype2){
			case '1':
				printf("FIRST PLAYER WON THE MATCH WITH THE PAPER TYPE ATTACK\n");
				player1score++;
				break;
			case '2':
				printf("DRAW\n");
				break;
			case '3':
				printf("OPPONENT WON WITH THE SCISSOR TYPE ATTACK\n");
				player2score++;
				break;
		}
	}
	
		if (atktype1 == '3'){
		switch (atktype2){
			case '1':
				printf("FIRST PLAYER WON THE MATCH WITH THE SCISSOR TYPE ATTACK\n");
				player1score++;
				break;
			case '2':
				printf("OPPONENT WON WITH THE ROCK TYPE ATTACK\n");
				player2score++;
				break;
			case '3':
				printf("DRAW\n");
				break;
		}
	}
	
	printf("SCORES:\n");
	printf("PLAYER 1 = %d\n",player1score);
	printf("PLAYER 2 = %d\n",player2score);
	
	printf("READY? PRESS ANY INPUT");
	command3 = getch();
	
	round++;
	
	system("cls");
	
}

printf("TOTAL SCORES:\n");
printf("PLAYER 1 = %d\n",player1score);
printf("PLAYER 2 = %d\n",player2score);
printf("\n\n\n");
	
	
}
