#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node *prev;
  int data;
  struct node *next;
};

struct node *head =NULL;

struct node *create_doubly_ll(struct node *);
int traversal(struct node *);
struct node *interchange_val(struct node *);

int main() {

  head = create_doubly_ll(head);
  printf("Doubly LL is created !\n");

  head = interchange_val(head);

  int isEmpty = traversal(head);
  if (isEmpty)
  {
    printf("\nDoubly LL is empty!\n");
  }
  else
  {
    printf("\nAbove Doubley LL is displayed !\n");
  }
  
  return 0;
}

struct node *create_doubly_ll(struct node *head){
  struct node *new_node, *ptr;
  int num;

  printf("Enter -1 to end\n");
  printf("Enter the data: ");
  scanf("%d",&num);

  while(num != -1){
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;

    if(head == NULL){
      head = new_node;
      head->next = NULL;
      head->prev = NULL;
    } else {
      ptr = head;
      while(ptr->next != NULL)
        ptr = ptr->next;

      ptr->next = new_node;
      new_node->prev = ptr;

      new_node->next = NULL;
    }

    printf("Enter the data: ");
    scanf("%d",&num);
  }

  return head;
}

int traversal(struct node *head){
  if(head == NULL)
    return 1;
  
  struct node *ptr;
  ptr = head;
  printf("NULL <-> ");
  
  while (ptr != NULL)
  {
    printf("%d <-> ",ptr->data);
    ptr = ptr->next;
  }
  
  printf("NULL");
  return 0;
}

struct node *interchange_val(struct node *head){
  if (head == NULL)
    return head;

  struct node *end = head;
  struct node *start = head;
  int temp;

  while (end->next != NULL)
    end = end->next;
  
  while (start != end && start->prev != end)
  {
    temp = start->data;
    start->data = end->data;
    end->data = temp;

    start = start->next;
    end = end->prev;
  }
  return head;
}
