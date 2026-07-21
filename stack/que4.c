#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10
#define NAME_LEN 50

// 2D Array: Up to 10 names, each up to 50 characters long
char stack[MAX][NAME_LEN];
int top = -1;

void push();
char *pop();
char *peek();
void traversal();

int main() {
  int choice;
  char *returned_name;

  do {
    printf("\n--------------------------------------------------\n");
    printf("1.Push\t2.Pop\t3.Peek\t4.Traversal\t5.Exit");
    printf("\n--------------------------------------------------\n");
    printf("\nEnter your choice: ");
    // The space before %d clears leftover newline characters from stdin
    scanf(" %d", &choice);

    switch (choice) {
      case 1: 
        push(); 
        break;
      case 2: 
        returned_name = pop(); 
        if (returned_name != NULL) {
          printf("Popped name: %s\n", returned_name); 
        }
        break;
      case 3: 
        returned_name = peek(); 
        if (returned_name != NULL) {
          printf("Peek name: %s\n", returned_name); 
        }
        break;
      case 4: 
        traversal(); 
        break;
      case 5: 
        printf("Exiting.....\n"); 
        break;
      default:
        printf("Invalid choice!\n");
        break;
    }
  } while(choice != 5);

  return 0;
}

void push() {
  if (top >= MAX - 1) {
    printf("Stack Overflow\n");
    return;
  }

  char name[NAME_LEN];
  printf("Enter name of student: ");
  
  // Consume any stray newline character remaining in buffer
  getchar(); 
  fgets(name, NAME_LEN, stdin);

  // Remove trailing newline character left by fgets
  name[strcspn(name, "\n")] = '\0';

  top++;
  strcpy(stack[top], name); // Copy string into stack array row
}

char *pop() {
  if (top < 0) {
    printf("Stack Underflow\n");
    return NULL;
  }
  // Return pointer to current top row, then decrement top
  return stack[top--];
}

char *peek() {
  if (top < 0) {
    printf("Stack is empty\n");
    return NULL;
  }
  return stack[top];
}

void traversal() {
  if (top < 0) {
    printf("Stack is empty\n");
    return;
  }

  printf("Stack Contents (Top to Bottom):\n");
  for (int i = top; i >= 0; i--) {
    printf("%s\n", stack[i]);
  }
}