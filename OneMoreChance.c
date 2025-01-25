#include <stdio.h>
#include <stdlib.h>
#include <string.h>







typedef struct node
{
    int ID;
    char name[200];
    char Major[200];
    float cgpa;
}data;

typedef struct node
{
    data d;
    node* next;
}node;

void menu(void) {
    printf("\n\t\t----------------------------------------\n");
    printf("\t\t1. Create an Initial List\n");
    printf("\t\t2. Add a New Student\n");
    printf("\t\t3. Drop a Student\n");
    printf("\t\t4. Traverse LL\n");
    printf("\t\t5. Sort by gpa in the LL\n");
    printf("\t\t6. Quit\n");
    printf("\n\t\t----------------------------------------\n");
    printf("\n\t\tYour choice please: ");
}

node* createLL(FILE* infp){
    
}

int main() {
                                        int choice, id;
                                        node *head = NULL;
                            FILE *infp = fopen("Section07_Data.txt", "r");

    if (infp == NULL) {
        printf("Failed to open the file\n");
        return 0;
    }

    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = createLL(infp);
                break;
            case 2:
                addstudent(&head);
                break;
            case 3:
                printf("Please give the ID of the student you want to drop: ");
                scanf("%d", &id);  // Corrected: use %d
                int status = drop(&head, id);
                if (status) {
                    printf("The student was successfully dropped\n");
                } else {
                    printf("The student was not found\n");
                }
                break;
            case 4:
                traverse(head);
                break;
            case 5:
                sortbygpa(head);
                break;
            case 6:
                printf("\n\t\tYou decided to QUIT\n\n\t\tBYE!\n\n\t\t");
                break;
            default:
                printf("\n\t\tThat was an INVALID CHOICE!\n");
        }
    } while (choice != 6);

    fclose(infp);
    return 0;
}