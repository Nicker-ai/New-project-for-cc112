#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int subjectChoice;

 while (1) {
        printf("\n== College SUbject Table ==\n");
        printf("1. BS Computer Science\n");
        printf("2. BS Office Administration\n");
        printf("3. BTVTED - EDUC\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &subjectChoice);

        switch (subjectChoice) {
            case 1:
                goto bscs;
                break;
            case 2:
                goto bsoa;
                break;
            case 3:
                goto btvted;
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

return 0;
	bscs:
	system("cls");
	printf("[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][[][][][][][][][][][][][][][][][][][][][][]\n");
	printf("[]                                BACHELOR OF SCIENCE IN COMPUTER SCIENCE                                  []\n");
	printf("[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][[][][][][][][][][][][][][][][][][][][][][]\n");
	printf("[]                                      FIRST YEAR - FIRST SEMESTER                                        []\n");
	printf("[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][[][][][][][][][][][][][][][][][][][][][][]\n");
	printf("[] COURSE CODE []     COURSE DESCRIPTION    [] UNIT []  ASSESSMENT OF FEES    []    CASH    []  INSTALL... []\n");
	printf("[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][[][][][][][][][][][][][][][][][][][][][]\n");
	printf("[]     GE1     []  UNDERSTANDING THE SELF   []   3  []     NUMBER OD UNITS    []    20.00   []     20.00   []\n");
	printf("[]     GE2     []  MATHEMATICS IN THE MO..  []   3  []     AMOUNT PER UNIT    []   400.00   []    460.00   []\n");
	printf("[]    CC111    [] INTRODUCTION TO COMPUT... []   2  []       TUTION FEE       []  8,000.00  []   9,200.00  []\n");
	printf("[]    CC112    [] FUNDAMENTALS OF PROGRA... []   2  []       ENERGY FEE       []  1,000.00  []   1,000.00  []\n");
	printf("[]     PLS     [] PHILTECH LIFE AND SPIRIT  []   2  []    COM/PSY - 1,200 /   []  1,200.00  []   1,200.00  []\n");
	printf("[]             []                           []      []       UNIT LAB (2)     []            []             []\n");
	printf("[]     GE3     [] READINGS IN THE PHILIP... []   3  []        OTHER FEES      []  4,100.00  []   4,100.00  []\n");
	printf("[]     PE1     []    PHYSICAL FITNESS 1     []   2  []      MISCELLENEOUS     []    850.00  []    850.00   []\n");
	printf("[]    NSTP1    [] NATIONAL SERVICE TRAIN... []   3  []          TOTAL         []  15,150.00 []  16,350.00  []\n");
	printf("[]             []                           []  21  []       50%% DISCOUNT     []  4,000.00  []   4,600.00  []\n");
	printf("[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][[][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\n\n");
	printf("[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][[][][][][][][][][][][][][][][][][][][][][]\n");
	printf("[]                                     FIRST YEAR - SECOND SEMESTER                                        []\n");
	printf("[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][[][][][][][][][][][][][][][][][][][][][][]\n");
	printf("[] COURSE CODE []     COURSE DESCRIPTION    [] UNIT []  ASSESSMENT OF FEES    []    CASH    []  INSTALL... []\n");
	printf("[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][[][][][][][][][][][][][][][][][][][][][]\n");
	printf("[]     GE4     []           ETHICS          []   3  []     NUMBER OD UNITS    []    TBA     []     TBA     []\n");
	printf("[]     WST     []  WEB SYSTEM AND TECHN...  []   2  []     AMOUNT PER UNIT    []    TBA     []     TBA     []\n");
	printf("[]     GE5     []      ART APPRECIATION     []   3  []       TUTION FEE       []    TBA     []     TBA     []\n");
	printf("[]    CC123    [] INTERMEDIATE PROGRAMM...  []   2  []       ENERGY FEE       []    TBA     []     TBA     []\n");
	printf("[]    CSS121   [] COMPUTER SYSTEM SERVICING []   2  []    COM/PSY - 1,200 /   []    TBA     []     TBA     []\n");
	printf("[]             []                           []      []       UNIT LAB (2)     []            []             []\n");
	printf("[]     PE2     []    PHYSICAL FITNESS 2     []   2  []        OTHER FEES      []    TBA     []     TBA     []\n");
	printf("[]    NSTP2    [] NATIONAL SERVICE TRAIN... []   3  []      MISCELLENEOUS     []    TBA     []     TBA     []\n");
	printf("[]     VGD     []   VISUAL GRAPHICS DESIGN  []   2  []          TOTAL         []    TBA     []     TBA     []\n");
	printf("[]             []                           []   19 []                        []            []             []\n");
	printf("[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][[][][][][][][][][][][][][][][][][][][][][]\n");
	printf("\n\n");
	return 0;
	bsoa:
	printf("hellobsoa");
	return 0;
	btvted:
	printf("hellobtvted");
return 0;
}
