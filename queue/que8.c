#include<stdio.h>
#include<stdlib.h>

// Priority Queue (Using LL)

struct node {
  int data;
  int priority;
  struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue();
void dequeue();
void traversal();

int isEmpty();

int main() {
  printf("\n1. Enqueue\t2. Dequeue\t3. Traversal\t4. Exit\n");
  int choice;

  do {
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch (choice) {
    case 1: enqueue(); break;
    case 2: dequeue(); break;
    case 3: traversal(); break;
    case 4: printf("Exiting...."); break;
    
    default: printf("Invalid choice\n"); break;
    }
  } while (choice != 4);

  return 0;
}

void enqueue() {
  int num,priority;
  printf("Enter number & priority: ");
  scanf("%d %d",&num,&priority);

  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;
  new_node->priority = priority;
  new_node->next = NULL;

  if (isEmpty()) {
    front = rear = new_node;
  } else {
    struct node *ptr = front, *temp;

    // Case: Set Highst priority element at front
    if (front->priority > new_node->priority) {
      new_node->next = front;
      front = new_node;

      return;
    }

    while (ptr->next != NULL) {
      // Case (Middle Priority element): If current next has high priority then add new node as current next
      if (new_node->priority < ptr->next->priority) {
        temp = ptr->next;
        ptr->next = new_node;
        new_node->next = temp;

        break;
      }
      ptr = ptr->next;
    }

    // set lowest priority element 
    if (ptr == rear) {
      ptr->next = new_node;
      rear = new_node;
    }
    
  }
  
}

void dequeue() {
  if (isEmpty()) {
    printf("Priority Queue is empty\n");
    return;
  }

  struct node *temp = front;
  front = front->next;

  printf("--> Dequeued: %d\n",temp->data);
  free(temp);

  // If Priority Queue become empty then set front & rear to NULL
  if (front == NULL) {
    front = rear = NULL;
  }
}

void traversal() {
  if (isEmpty()) {
    printf("Priority Queue is empty\n");
    return;
  }
  
  struct node *ptr = front;
  printf("\nTraverse Priority Queue from High to Low Priority\n");
  while (ptr != NULL) {
    printf("%d (Priority %d)\t",ptr->data,ptr->priority);
    ptr = ptr->next;
  }
  printf("\n");
  
}

int isEmpty() {
  return (front == NULL && rear == NULL);
}
