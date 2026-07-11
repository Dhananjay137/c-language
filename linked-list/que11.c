#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *new_head=NULL;

struct node *create_ll(struct node *);
int traversal(struct node *);
struct node *new_ll(struct node *);

int main() {

  head = create_ll(head);
  printf("LL created !\n");

  new_head = new_ll(head);

  int isEmpty = traversal(new_head);
  if (isEmpty)
  {
    printf("\nLL is Empty!\n");
  } else {
    printf("\nLL shown above!\n");
  }
  
  return 0;
}

struct node *create_ll(struct node *head){
  struct node *new_node, *ptr;
  int num;

  printf("Enter -1 to end\n");
  printf("Enter the data: ");
  scanf("%d",&num);

  while(num != -1){
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;

    if(head == NULL){
      head = new_node;
    } else {
      ptr = head;
      while(ptr->next != NULL)
        ptr = ptr->next;

      ptr->next = new_node;
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
  while (ptr != NULL)
  {
    printf("%d -> ",ptr->data);
    ptr = ptr->next;
  }
  printf("NULL");
  return 0;
}

struct node *new_ll(struct node *head){
  struct node *ptr = head;
  struct node *new_node;
  struct node *new_ptr=NULL;

  while (ptr != NULL)
  {
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = ptr->data;
    new_node->next = NULL;

    if (new_head == NULL)
    {
      new_head = new_node;
      new_ptr = new_head;
    } else {
      new_ptr->next = new_node;
      new_ptr = new_ptr->next;
    }
    
    if (ptr->next == NULL)
    {
      ptr = NULL;
    } else {
      ptr = ptr->next->next;
    }
  }
  
  return new_head;
}
