#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue();
void traversal();
int isEmpty();

void calculate_no_of_items();

int main() {
  int choice,num;
  printf("\n1.Enqueue\t2.Dequeue\t3.Traversal\t4.Details\t5.Calculate no. of item\t6.Exit\n");
  do {
    printf("Choose action: ");
    scanf("%d",&choice);
    printf("--------------------------\n");

    switch (choice)
    {
    case 1: enqueue(); break;
    
    // case 2: dequeue(); break;

    case 3: traversal(); break;

    // case 4: show_details(); break;

    case 5: calculate_no_of_items(); break;

    case 6: printf("Exiting...\n"); break;

    default:
      break;
    }
  } while (choice != 6);

  return 0;
}

void enqueue() {
  int value;
  printf("Enter number: ");
  scanf("%d",&value);

  // Allocate memory for new node
  struct node *new_node = (struct node*)malloc(sizeof(struct node));

  if (new_node == NULL) {
    printf("Memory allocation failed!\n");
    return;
  }

  new_node->data = value;
  new_node->next = NULL;

  // If Queue is empty.
  if (front == NULL && rear == NULL) {
    front = rear = new_node;
    printf("--> Enqueued: %d\n", value);
    return;
  }

  rear->next = new_node;
  rear = new_node;
  printf("Enqueued: %d\n", value);
  
}

void traversal() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }

  struct node *ptr = front;
  printf("\nTraversal (front to rear)\n");
  while (ptr != NULL) {
    printf("%d\t",ptr->data);
    ptr = ptr->next;
  }
  printf("\n");
}

int isEmpty() {
  return (front == NULL && rear == NULL);
}

void calculate_no_of_items() {
  if (isEmpty()) {
    printf("Queue is empty\n");
    return;
  }

  int count=0;
  struct node *ptr = front;
  while (ptr != NULL) {
    count++;
    ptr = ptr->next;
  }

  printf("--> Number of items: %d\n",count);
}
