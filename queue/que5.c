#include<stdio.h>
// Circular Queue
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue();
void dequeue();
void traversal();
void show_details(); // Print front, rear index and MAX

int isEmpty();
int isFull();

int main() {
  printf("1. Enqueue\t2. Dequeue\t3. Traversal\t4. Show Details\t5. Exit\n");
  int choice;

  do {
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch (choice) {
    case 1: enqueue(); break;
    case 2: dequeue(); break;
    case 3: traversal(); break;
    case 4: show_details(); break;
    case 5: printf("Exting....\n"); break;
    
    default: printf("Not Valid Choice !\n"); break;
    }
  } while (choice != 5);

  return 0;
}

void enqueue() {
  int value;
  printf("Enter the number: ");
  scanf("%d",&value);

  if (isFull()) {
    printf("Queue is Full!\n");
    return;
  }

  if (isEmpty()) {
    front = rear = 0;
  } else {
    if (rear == MAX-1 && front != 0) {
      // Main part of circular queue (it use wastage space of queue)
      rear = 0;
    } else {
      rear++;
    }
  }
  
  queue[rear] = value;
  printf("--> Enqueued: %d\n",value);
}

void dequeue() {
  if (isEmpty()) {
    printf("Queue is empty!\n");
    return;
  }

  int val;
  if (front == rear) {
    // Case: Only one element avilable
    val = queue[front];
    front = rear = -1;
  } else {
    // Case: More than one element in queue

    // Stroe the front value to val
    val = queue[front];

    if (front == MAX-1) {
      // If Front element on end then set front to 0
      front = 0;
    } else {
      // Just increment front
      front++;
    }

  }
  printf("--> Dequeued: %d\n",val);
}

void traversal() {
  if (isEmpty()) {
    printf("Queue is empty!\n");
    return;
  }

  if (front <= rear) {
    // Case: Regular
    for (int i = front; i <= rear; i++) {
      printf("%d\t",queue[i]);
    }
    printf("\n");
  } else {
    // Traverse front to MAX
    for (int i = front; i < MAX; i++)
      printf("%d\t",queue[i]);

    // Traverse 0 to rear
    for (int j = 0; j <= rear; j++)
      printf("%d\t",queue[j]);
    
    printf("\n");
  }
  
}

int isEmpty() {
  return (front == -1 && rear == -1);
}

int isFull() {
  return ((front == 0 && rear == MAX-1) || front == rear+1);
}

void show_details() {
  printf("\nFront = %d,\tRear = %d,\tMAX = %d\n",front,rear,MAX);
}
