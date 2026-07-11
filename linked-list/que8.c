#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node *prev;
  int data;
  struct node *next;
};

struct node *head = NULL;

struct node *create_doubly_ll(struct node *);
struct node *sort(struct node *);
int traversal(struct node *);

int main() {

  head = create_doubly_ll(head);
  printf("Doubly LL is created !\n");

  int isEmpty = traversal(head);

  if (isEmpty)
  {
    printf("\nDoubly LL is empty !\n");
  } else {
    printf("\nAbove show doubly LL !\n");
  }

  head = sort(head);

  printf("\nDoubly LL after sorting!\n");
  isEmpty = traversal(head);

  if (isEmpty)
  {
    printf("\nDoubly LL is empty !\n");
  } else {
    printf("\nAbove show doubly LL !\n");
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
      head->next = head;
      head->prev = head;
    } else {
      ptr = head;
      while(ptr->next != head)
        ptr = ptr->next;

      ptr->next = new_node;
      new_node->prev = ptr;

      new_node->next = head;
      head->prev = new_node;
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
  printf("end <-> ");
  
  do {
    printf("%d <-> ",ptr->data);
    ptr = ptr->next;
  } while (ptr != head);

  printf("head");
  return 0;
}

struct node *sort(struct node *head){
  struct node *ptr1 = head;
  struct node *ptr2 = NULL;
  struct node *pre_ptr = NULL;
  int temp;

  do
  {
    ptr2 = head;
    while (ptr2->next != head)
    {
      pre_ptr = ptr2;
      ptr2 = ptr2->next;

      if (pre_ptr->data > ptr2->data)
      {
        temp = pre_ptr->data;
        pre_ptr->data = ptr2->data;
        ptr2->data = temp;
      }
    }
    
    ptr1 = ptr1 -> next;
  } while (ptr1 != head);
  
  
  return head;
}
