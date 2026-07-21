#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *push(struct node *, int);
void traversal(struct node *);
int isEmpty(struct node *);
struct node *createStack();
int compareStacks(struct node *, struct node *);

int main() {
  printf("=== INPUT FOR STACK 1 ===\n");
  struct node *top1 = createStack();

  printf("\n=== INPUT FOR STACK 2 ===\n");
  struct node *top2 = createStack();

  printf("\n--- Stack 1 Contents ---\n");
  traversal(top1);

  printf("\n--- Stack 2 Contents ---\n");
  traversal(top2);

  printf("\n-----------------------------------------\n");
  if (compareStacks(top1, top2)) {
    printf("RESULT: Both Stacks are IDENTICAL!\n");
  } else {
    printf("RESULT: Stacks are DIFFERENT.\n");
  }
  printf("-----------------------------------------\n");

  return 0;
}

// Function to push data into a stack
struct node *push(struct node *top, int val) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = val;

  if (top == NULL) {
    top = new_node;
    top->next = NULL;
  } else {
    new_node->next = top;
    top = new_node;
  }
  return top;
}

// Helper function to build a stack from user input
struct node *createStack() {
  struct node *top = NULL;
  int n, val;

  printf("How many elements do you want to enter? ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter element %d: ", i + 1);
    scanf("%d", &val);
    top = push(top, val);
  }
  return top;
}

// Function to compare two stacks
int compareStacks(struct node *top1, struct node *top2) {
  struct node *ptr1 = top1;
  struct node *ptr2 = top2;

  // Traverse both linked lists simultaneously from TOP to BASE
  while (ptr1 != NULL && ptr2 != NULL) {
    if (ptr1->data != ptr2->data) {
      return 0; // Data mismatch found
    }
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }

  // If both pointers reached NULL at the same time, sizes are equal
  if (ptr1 == NULL && ptr2 == NULL) {
    return 1; // Stacks are identical
  }

  return 0; // One stack has more elements than the other
}

void traversal(struct node *ptr) {
  if (ptr == NULL) {
    printf("Stack is empty!\n");
    return;
  }

  printf("(TOP) ");
  while (ptr != NULL) {
    printf("%d -> ", ptr->data);
    ptr = ptr->next;
  }
  printf("BASE(NULL)\n");
}

int isEmpty(struct node *top) {
  return (top == NULL);
}