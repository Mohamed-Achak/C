#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tag {
    char student_name[20];
    int student_id;
    struct tag* next;
} student_node;

// Function prototypes
void menu(void);
void add_student(student_node**, student_node*, int);
student_node* delete_student(student_node**, int, int);
char* search_student(student_node**, int, int);
void display_students(student_node**, int);
student_node* create_initialize_node();
void initialize_hash_table(student_node**, int);
int hash_function(int, int);
int check_empty_hash_table(student_node**, int);

int main() {
    student_node* hash_table[10];
    student_node* node;
    char name[20];
    int choice, index, size, id;
    size = 10;

    initialize_hash_table(hash_table, size);
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                node = create_initialize_node();
                index = hash_function(node->student_id, size);
                add_student(hash_table, node, index);
                break;

            case 2:
                printf("\n\tYou are deleting a student!\n\t");
                printf("\n\tPlease input the student ID: ");
                scanf("%d", &id);
                index = hash_function(id, size);
                node = delete_student(hash_table, id, index);
                if (node == NULL)
                    printf("\n\t Student with ID: %d is not found in the Hash Table\n", id);
                else {
                    printf("\n\t%s with ID: %d is removed from the Hash Table\n", node->student_name, node->student_id);
                    free(node);
                }
                break;

            case 3:
                printf("\n\tPlease input the student ID: ");
                scanf("%d", &id);
                index = hash_function(id, size);
                strcpy(name, search_student(hash_table, id, index));
                if (strcmp(name, "not_found") == 0)
                    printf("\n\tStudent with ID:%d is not found in the Hash Table!\n", id);
                else
                    printf("\n\tStudent %s with ID: %d is found in the Hash Table\n", name, id);
                break;

            case 4:
                display_students(hash_table, size);
                break;

            case 5:
                printf("\n\tDone!\n");
                break;

            default:
                printf("\n\tWrong Choice\n");
                break;
        }
    } while (choice != 5);

    printf("\n\tBye\n");
    return 0;
}

void menu(void) {
    printf("\n\t-------------Menu To Use----------------\n");
    printf("\n\t1. Add a student to Hash Table\n");
    printf("\n\t2. Delete a student from Hash Table\n");
    printf("\n\t3. Search for a student in Hash Table\n");
    printf("\n\t4. Display list of students in Hash Table\n");
    printf("\n\t5. Quit\n");
    printf("\n\t Your choice:");
}

void initialize_hash_table(student_node** hash_table, int size) {
    for (int i = 0; i < size; i++) {
        hash_table[i] = NULL;
    }
}

int hash_function(int student_id, int size) {
    return student_id % size;
}

student_node* create_initialize_node() {
    student_node* new_node = (student_node*)malloc(sizeof(student_node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("\nEnter student name: ");
    scanf("%s", new_node->student_name);
    printf("Enter student ID: ");
    scanf("%d", &new_node->student_id);
    new_node->next = NULL;
    return new_node;
}

void add_student(student_node** hash_table, student_node* node, int index) {
    if (hash_table[index] == NULL) {
        hash_table[index] = node;
    } else {
        student_node* temp = hash_table[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    printf("\nStudent added successfully.\n");
}

student_node* delete_student(student_node** hash_table, int student_id, int index) {
    student_node* temp = hash_table[index];
    student_node* prev = NULL;

    while (temp != NULL && temp->student_id != student_id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return NULL;
    }

    if (prev == NULL) {
        hash_table[index] = temp->next;
    } else {
        prev->next = temp->next;
    }

    return temp;
}

char* search_student(student_node** hash_table, int student_id, int index) {
    student_node* temp = hash_table[index];

    while (temp != NULL) {
        if (temp->student_id == student_id) {
            return temp->student_name;
        }
        temp = temp->next;
    }

    return "not_found";
}

void display_students(student_node** hash_table, int size) {
    for (int i = 0; i < size; i++) {
        printf("\nHash Table[%d]: ", i);
        student_node* temp = hash_table[i];
        if (temp == NULL) {
            printf("Empty");
        } else {
            while (temp != NULL) {
                printf(" -> %s(ID: %d)", temp->student_name, temp->student_id);
                temp = temp->next;
            }
        }
    }
    printf("\n");
}
