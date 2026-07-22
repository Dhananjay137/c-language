#include<stdio.h>
#include<stdlib.h>
// Linked Representation of Queue
struct node
{
  int data;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue();
void enqueue_at_front();
void dequeue();
void dequeue_at_rear();
void traversal();
int isEmpty();

void calculate_no_of_items();

int main() {
  int choice,num;
  printf("\n1.Enqueue\t2.Enqueue at front\n3.Dequeue\t4.Dequeue at rear\n5.Traversal\t6.Calculate no. of item\t\t7.Exit\n");
  do {
    printf("Choose action: ");
    scanf("%d",&choice);
    printf("--------------------------\n");

    switch (choice)
    {
    case 1: enqueue(); break;

    case 2: enqueue_at_front(); break;
    
    case 3: dequeue(); break;

    case 4: dequeue_at_rear(); break;

    case 5: traversal(); break;

    // case 4: show_details(); break;

    case 6: calculate_no_of_items(); break;

    case 7: printf("Exiting...\n"); break;

    default:
      break;
    }
  } while (choice != 7);

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

void enqueue_at_front() {
  int value;
  printf("Enter number: ");
  scanf("%d",&value);

  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = value;
  
  if (isEmpty()) {
    new_node->next = NULL;
    front = rear = new_node;
  } else {
    new_node->next = front;
    front = new_node;
  }
  printf("--> Enqueued: %d\n", value);
}

void dequeue() {
  if (isEmpty()) {
    printf("Queue is empty!\n");
    return;
  }

  // Store front in Temparary variable and move to next node
  struct node *temp = front;
  front = front->next;

  // If Queue is empty set front & rear to NULL
  if (front == NULL) {
    front = rear = NULL;
  }

  printf("--> Dequeued: %d\n",temp->data);

  free(temp);
}

void dequeue_at_rear() {
  if (isEmpty()) {
    printf("Queue is empty!\n");
    return;
  }
  
  // Find the node before rear
  struct node *ptr = front;

  if (front == rear) {
    front = rear = NULL;
    free(ptr);
    return;
  }
  
  while (ptr->next != rear)
    ptr = ptr->next;

  free(rear);

  if (ptr == NULL) {
    // If queue is empty set front & rear to NULL
    front = rear = NULL;
  } else {
    // Assign ptr as rear node
    ptr->next = NULL;
    rear = ptr;
  }
  
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
