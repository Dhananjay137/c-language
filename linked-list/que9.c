#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *merge_head = NULL;
struct node *head1 = NULL;
struct node *head2 = NULL;

struct node *create_ll(struct node *);
struct node *merge(struct node *,struct node *);
int traversal(struct node *);

int main() {
  head1 = create_ll(head1);
  printf("First LL is created !\n");

  head2 = create_ll(head2);
  printf("Second LL is created !\n");

  merge_head = merge(head1,head2);

  int isEmpty = traversal(merge_head);
  if (isEmpty)
  {
    printf("\nLL is empty !\n");
  } else {
    printf("\nAbove shown merge LL!");
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

struct node *merge(struct node *head1,struct node *head2){
  struct node *ptr1 = head1;
  struct node *ptr2 = head2;
  struct node *ptr = NULL;
  struct node *new_node;

  while(ptr1 != NULL && ptr2 != NULL){
    new_node = (struct node*)malloc(sizeof(struct node));
    if (ptr1->data <= ptr2->data)
    {
      new_node->data = ptr1 ->data;

      ptr1 = ptr1->next;
      
    } else {
      new_node->data = ptr2->data;
      ptr2 = ptr2->next;
    }

    if (merge_head == NULL)
    {
      merge_head = new_node;
      merge_head->next = NULL;

      ptr = merge_head;
    } else {
      
      ptr->next = new_node;
      new_node->next = NULL;

      ptr = ptr->next;
    }
  
  }

  if (ptr1 != NULL) {
    if (ptr == NULL) merge_head = ptr1;
    else ptr->next = ptr1;
  } else if (ptr2 != NULL) {
    if (ptr == NULL) merge_head = ptr2;
    else ptr->next = ptr2;
  }
  return merge_head;
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

