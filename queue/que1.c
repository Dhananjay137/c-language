#include<stdio.h>

#define MAX 10

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int);
void enqueue_at_front(int);
void dequeue();
int isEmpty();
void traversal();
void show_details();

void calculate_no_of_item();

int main() {

  int choice,num;
  printf("\n1.Enqueue\t2.Enqueue at front\t3.Dequeue\t4.Traversal\t5.Details\t6.Calculate no. of item\t7.Exit\n");
  do {
    printf("Choose action: ");
    scanf("%d",&choice);
    printf("--------------------------\n");

    switch (choice)
    {
    case 1:
      printf("Enter number: ");
      scanf("%d",&num);

      enqueue(num);
      break;

    case 2:
      printf("Enter number: ");
      scanf("%d",&num);

      enqueue_at_front(num);
      break;
    
    case 3: dequeue(); break;

    case 4: traversal(); break;

    case 5: show_details(); break;

    case 6: calculate_no_of_item(); break;

    case 7: printf("Exiting...\n"); break;

    default:
      break;
    }
  } while (choice != 7);

  return 0;
}

int isEmpty() {
  return (front == -1 && rear == -1);
}

void enqueue(int num) {
  if (rear == MAX-1) {
    printf("Queue Overflow\n");
    return;
  } else if (isEmpty()) {
    front = rear = 0;
  } else {
    rear++;
  }
  queue[rear] = num;
}

void enqueue_at_front(int num) {
  if (front == 0) {
    printf("Unable to add at front\n");
    return;
  }
  if (isEmpty()) {
    rear = front = 0;
  } else {
    front--;
  }
  queue[front] = num;
}

void dequeue() {
  int num;
  if (isEmpty()) {
    printf("Queue is empty\n");
  } else {
    num = queue[front++];

    printf("Dequeue number: %d\n",num);

    if (front > rear) {
      front = rear = -1;
    }
    
  }
  
}

void traversal() {
  if (isEmpty()) {
    printf("Queue is empty\n");
  } else {
    for (int i = front; i <= rear; i++) {
      printf("%d\t",queue[i]);
    }
    printf("\n");
  }
  
}

void show_details(){
  printf("\nFront = %d,\tRear = %d,\tMAX = %d\n",front,rear,MAX);
}

void calculate_no_of_item(){
  int count=0;
  if (isEmpty()) {
    printf("Queue is empty\n");
  } else {
    for (int i = front; i <= rear; i++) {
      count++;
    }
    printf("Number of items: %d\n",count);
  }
}
