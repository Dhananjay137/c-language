#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *create_ll(struct node *);
int isAsc(struct node *);

int main() {

  head = create_ll(head);
  printf("Linked List Created!\n");

  int flag = isAsc(head);
  if (flag)
  {
    printf("LL is in ascending order !\n");
  } else {
    printf("LL is not in ascending order !\n");
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

    if(head == NULL){
      new_node->next = NULL;
      head = new_node;
    } else {
      ptr = head;
      while(ptr->next != NULL)
        ptr = ptr->next;

      ptr->next = new_node;
      new_node->next = NULL;
    }

    printf("Enter the data: ");
    scanf("%d",&num);
  }

  return head;
}

int isAsc(struct node *head){
  int flag=1; // ll is in ascending order
  struct node *ptr;
  ptr = head;

  while (ptr->next != NULL)
  {
    if(ptr->data > ptr->next->data){
      flag = 0; // ll is in not ascending order
    }
    ptr = ptr -> next;
  }
  return flag;
}
