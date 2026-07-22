#include<stdio.h>
// Priority Queue using array

#define ROW 5 // Priority level
#define COL 4 // Length of each queue

int queue[ROW][COL];
int key[ROW][2]; // key[priority][0] = front, key[priority][1] = rear

void enqueue();
void dequeue();
void traversal();
void show_details();
void load();

int isEmpty();
int isFull();

int main() {
  load();

  printf("1. Enqueue\t2. Dequeue\t3. Traversal\t4. Details\t5. Exit\n");
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
    
      default: printf("Not valid choice\n"); break;
    }
  } while (choice != 5);
  
  return 0;
}

void enqueue() {
  int num,priority;
  printf("Enter number & priority(0-4): ");
  scanf("%d %d",&num,&priority);

  int front = key[priority][0];
  int rear = key[priority][1];

  if (isFull(front,rear)) {
    printf("Priority Queue is Full(Priority %d)\n",priority);
    return;
  }
  
  if (isEmpty(front,rear)) {
    key[priority][0] = key[priority][1] = 0;
    printf("-->empty\n");
  } else if (rear == COL-1 && front != 0) {
    printf("-->start from front\n");
    key[priority][1] = 0; // Set rear = 0
  } else {
    printf("-->regular\n");
    key[priority][1] = rear+1;
  }
  
  rear = key[priority][1];
  queue[priority][rear] = num;
}

void dequeue() {
  int front,rear,temp;
  for (int i = 0; i < ROW; i++) {
    front = key[i][0];
    rear = key[i][1];

    if (isEmpty(front,rear))
      continue;

    if (front == rear) {
      temp = queue[i][front];
      queue[i][front] = 0;
      printf("Dequeued: %d\n",temp);

      key[i][0] = key[i][1] = -1;
      break;
    } else {
      temp = queue[i][front];
      queue[i][front] = 0;

      if (front == COL-1) {
        key[i][0] = 0;
      } else {
        key[i][0] = front + 1;
      }
      printf("Dequeued: %d\n",temp);
      break;
    }
  }
  
}

void show_details() {
  printf("\n");
  for (int i = 0; i < ROW; i++) {
    printf("Priority %d: front(%d), rear(%d), MAX(%d)\n",i,key[i][0],key[i][1],COL);
  }
  printf("\n");
}

int isEmpty(int front, int rear) {
  return (front == -1 && rear == -1);
}

// Because it is cricular also
int isFull(int front, int rear) {
  return ((front == 0 && rear == COL-1) || front == rear+1);
}

void traversal() {
  
  for (int i = 0; i < ROW; i++)
  {
    printf("Priority %d: [",i);
    for (int j = 0; j < COL; j++)
    {
      printf("%d\t",queue[i][j]);
    }
    printf("]\n");
  }
}

void load() {
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < 2; j++) {
      key[i][j] = -1;
    }
  }
}
