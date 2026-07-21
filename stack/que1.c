#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *top = NULL;
struct node *push(struct node *);
struct node *pop(struct node *);
void peek(struct node *);
void traversal(struct node *);
int isEmpty(struct node *);
void starter();

int main() {
  starter();

  return 0;
}

struct node *push(struct node *top){
  int num;
  printf("Enter Number to PUSH: ");
  scanf("%d",&num);

  struct node *new_node;
  new_node = (struct node *)malloc(sizeof(struct node));
  new_node->data = num;

  if (top == NULL)
  {
    top = new_node;
    top->next = NULL;
  } else {
    new_node->next = top;
    top = new_node;
  }
  return top;
}

struct node *pop(struct node *top){
  if (isEmpty(top))
    return top;
  
  struct node *temp = top;
  top = top->next;
  free(temp);

  return top;
}

void peek(struct node *top){
  if (isEmpty(top))
    return;
  
  printf("Top Data: %d\n",top->data);
}

void traversal(struct node *ptr){
  if (isEmpty(ptr))
    return;
  
  printf("(TOP) ");
  while (ptr != NULL)
  {
    printf("%d -> ",ptr->data);
    ptr = ptr->next;
  }
  printf("BASE(-1)\n");
}

int isEmpty(struct node *top){
  if (top == NULL)
  {
    printf("\nStack is empty!\n");
    return 1;
  }
  return 0;
}

void starter(){
  int choice;
  
  do {
    printf("\n1.PUSH\t2.TRAVERSAL\t3.POP\t4.PEEK\t5.EXIT\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    printf("-----------------------------------------\n");

    switch (choice) {
      case 1: top = push(top); break;
      case 2: traversal(top); break;
      case 3: top = pop(top); break;
      case 4: peek(top); break;
      case 5: printf("\nExiting....\n"); break;
    
      default: printf("\nInvalid Choice!\n"); break;
    }
  } while(choice != 5);
  
}
