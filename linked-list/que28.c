#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int ID;
    char first_name[30];
    char last_name[30];
    int age;
    char designation[30];
    double salary;
    struct node *next;
};

// Function Declarations
struct node *create_data(void);
struct node *create_ll(struct node *head);
struct node *insert_employee(struct node *head);
void traversal(struct node *head);
void search_employee(struct node *head);
struct node *delete_employee(struct node *head);
void free_list(struct node *head);
int is_empty(struct node *head);

int main(void) {
    struct node *head = NULL;
    int choice;

    printf("\033[1;32m=== Employee Management System ===\033[0m\n");

    do {
        printf("\n--- Menu ---\n");
        printf("1. Add employees (multiple)\n");
        printf("2. Insert one new employee\n");
        printf("3. Display all employees\n");
        printf("4. Search employee by ID\n");
        printf("5. Delete employee by ID\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        switch(choice) {
            case 1: head = create_ll(head); break;
            case 2: head = insert_employee(head); break;
            case 3: traversal(head); break;
            case 4: search_employee(head); break;
            case 5: head = delete_employee(head); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while(choice != 6);

    free_list(head);
    return 0;
}

// ====================== CREATE MULTIPLE ======================
struct node *create_ll(struct node *head) {
    struct node *new_node;
    int ch = 0;

    do {
        printf("\nAdd new employee? (1 = Yes, 0 = No): ");
        scanf("%d", &ch);
        while(getchar() != '\n');

        if (ch == 1) {
            new_node = create_data();
            if (new_node == NULL) return head;

            if (head == NULL) {
                head = new_node;
            } else {
                struct node *ptr = head;
                while (ptr->next != NULL) ptr = ptr->next;
                ptr->next = new_node;
            }
        }
    } while (ch == 1);

    return head;
}

// ====================== INSERT ONE ======================
struct node *insert_employee(struct node *head) {
    struct node *new_node = create_data();
    if (new_node == NULL) return head;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *ptr = head;
        while (ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = new_node;
    }
    printf("Employee added successfully!\n");
    return head;
}

// ====================== CREATE DATA ======================
struct node *create_data(void) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) return NULL;
    ptr->next = NULL;

    printf("\n----- Enter Employee Details -----\n");
    
    printf("ID Number: ");
    scanf("%d", &ptr->ID);
    while(getchar() != '\n');

    printf("First Name: ");
    fgets(ptr->first_name, sizeof(ptr->first_name), stdin);
    ptr->first_name[strcspn(ptr->first_name, "\n")] = '\0';

    printf("Last Name: ");
    fgets(ptr->last_name, sizeof(ptr->last_name), stdin);
    ptr->last_name[strcspn(ptr->last_name, "\n")] = '\0';

    printf("Age: ");
    scanf("%d", &ptr->age);
    while(getchar() != '\n');

    printf("Designation: ");
    fgets(ptr->designation, sizeof(ptr->designation), stdin);
    ptr->designation[strcspn(ptr->designation, "\n")] = '\0';

    printf("Salary: ");
    scanf("%lf", &ptr->salary);
    while(getchar() != '\n');

    return ptr;
}

// ====================== DISPLAY ALL ======================
void traversal(struct node *head) {
    if (is_empty(head)) {
        printf("List is empty!\n");
        return;
    }

    struct node *ptr = head;
    printf("\033[1;32mID\tFirst Name\tLast Name\tAge\tDesignation\t\tSalary\033[0m\n");
    printf("----------------------------------------------------------------------\n");

    while (ptr != NULL) {
        printf("%-4d\t%-12s\t%-12s\t%-3d\t%-25s\t%.2lf\n",
               ptr->ID, ptr->first_name, ptr->last_name,
               ptr->age, ptr->designation, ptr->salary);
        ptr = ptr->next;
    }
}

// ====================== SEARCH ======================
void search_employee(struct node *head) {
    if (is_empty(head)) {
        printf("List is empty!\n");
        return;
    }

    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    struct node *ptr = head;
    while (ptr != NULL) {
        if (ptr->ID == id) {
            printf("\nEmployee Found!\n");
            printf("ID: %d\n", ptr->ID);
            printf("Name: %s %s\n", ptr->first_name, ptr->last_name);
            printf("Age: %d\n", ptr->age);
            printf("Designation: %s\n", ptr->designation);
            printf("Salary: %.2lf\n", ptr->salary);
            return;
        }
        ptr = ptr->next;
    }
    printf("Employee with ID %d not found!\n", id);
}

// ====================== DELETE ======================
struct node *delete_employee(struct node *head) {
    if (is_empty(head)) {
        printf("List is empty!\n");
        return head;
    }

    int id;
    printf("Enter Employee ID to delete: ");
    scanf("%d", &id);

    struct node *ptr = head, *prev = NULL;

    while (ptr != NULL) {
        if (ptr->ID == id) {
            if (prev == NULL) {        // Deleting first node
                head = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            free(ptr);
            printf("Employee with ID %d deleted successfully!\n", id);
            return head;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    printf("Employee with ID %d not found!\n", id);
    return head;
}

int is_empty(struct node *head) {
    return head == NULL;
}

void free_list(struct node *head) {
    struct node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}