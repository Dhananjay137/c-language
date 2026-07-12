#include<stdio.h>
#include<stdlib.h>

struct node *create_ll(struct node *);
int traversal(struct node *);
struct node *first_as_last_ele(struct node *);

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;


int main() {
  head = create_ll(head);
  printf("LL is created !\n");

  head = first_as_last_ele(head);

  int isEmpty = traversal(head);
  if (isEmpty)
  {
    printf("\nLL is Empty!\n");
  }
  else
  {
    printf("\nLL is displayed above!\n");
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

struct node *first_as_last_ele(struct node *head){
  if (head == NULL || head->next == NULL)
    return head;
  
  struct node *ptr = head;
  struct node *temp;

  while (ptr->next != NULL)
    ptr = ptr->next;
  
  temp = head;
  head = head->next;

  ptr->next = temp;
  temp->next = NULL;

  return head;
}
