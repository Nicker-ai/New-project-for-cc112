#include <stdio.h>
#include <string.h>

int main(){
	
	int choice;

    while (1) {
        printf("\n== College Student Enrollment System ==\n");
        printf("1. Enrollment Form\n");
        printf("2. Subject Table\n");
        printf("3. Enrollees List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                goto enrollmentForm;
                break;
            case 2:
                goto subjectTable;
                break;
            case 3:
                goto enrolleesList;
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
	
    char name[100], address[100], email[100], contact[100];
    int age, courseChoice, editChoice;
    char confirm;

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

    printf("Select Course (1-3): \n");
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

    printf("\nIs the information correct? (y/n): ");
    scanf(" %c", &confirm);
    
    loopconfirmation:

    if (confirm == 'n' || confirm == 'N') {
        printf("What would you like to edit? (1-6)\n");
        printf("1. Name\n");
        printf("2. Age\n");
        printf("3. Address\n");
        printf("4. Email\n");
        printf("5. Contact\n");
        printf("6. Course\n");
        scanf("%d", &editChoice);
        getchar();

        switch (editChoice) {
            case 1:
                printf("Enter new name: ");
                scanf(" %[^\n]", name);
                break;
            case 2:
                printf("Enter new age: ");
                scanf("%d", &age);
                break;
            case 3:
                printf("Enter new address: ");
                scanf(" %[^\n]", address);
                break;
            case 4:
                printf("Enter new email: ");
                scanf(" %[^\n]", email);
                break;
            case 5:
                printf("Enter new contact: ");
                scanf(" %[^\n]", contact);
                break;
            case 6:
                printf("Select new course (1-3): \n");
                printf("1. BSCS\n");
                printf("2. BTVTLED\n");
                printf("3. EDUC\n");
                scanf("%d", &courseChoice);
                break;
            default:
                printf("Invalid choice.\n");
        }
        

        printf("\n=== Updated Enrollment Details ===\n");
        printf("Name: %s\n", name);
        printf("Age: %d\n", age);
        printf("Address: %s\n", address);
        printf("Email: %s\n", email);
        printf("Contact: %s\n", contact);
        
        printf("\nIs the information correct? (y/n): ");
    	scanf(" %c", &confirm);
    
    	if (confirm == 'n' || confirm == 'N') {
    		goto loopconfirmation;
   		}
    }
    
    

    // Store enrollment data in file
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
            return 1;
    }

    file = fopen(courseFile, "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(file, "Name: %s\n", name);
    fprintf(file, "Age: %d\n", age);
    fprintf(file, "Address: %s\n", address);
    fprintf(file, "Email: %s\n", email);
    fprintf(file, "Contact: %s\n\n", contact);

    fclose(file);
    printf("Enrollment data saved to %s.\n", courseFile);

    return 0;

enrolleesList:
    char fileName[100];

    printf("Select course to view enrollees (1-3):\n");
    printf("1. BSCS\n");
    printf("2. BTVTLED\n");
    printf("3. EDUC\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcpy(fileName, "bscs_enrollees.txt");
            break;
        case 2:
            strcpy(fileName, "btvtled_enrollees.txt");
            break;
        case 3:
            strcpy(fileName, "educ_enrollees.txt");
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    file = fopen(fileName, "r");
    if (file == NULL) {
        printf("No enrollees found.\n");
    } else {
        char line[200];
        printf("Enrollees List:\n");
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
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
