#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;

struct node *create_ll(struct node *);
int traversal(struct node *);
struct node *rev(struct node *);

int main() {

  head = create_ll(head);
  printf("LL is created !\n");

  head = rev(head);

  if (head == NULL)
  {
    printf("LL is empty! \n");
  }
  
  int isEmpty = traversal(head);

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

struct node *rev(struct node *head){
  struct node *ptr = head; // Store head pointer

  // Base case: if ptr next is null then return ptr
  if(ptr == NULL || ptr->next == NULL){
    return ptr;
  }

  // Recursively traverse to the end of the list. 
  // 'head' will hold the new head (the old last node) all the way up the call stack.
  head = rev(ptr->next);

  // The magic step: Reverse the link.
  // Make the NEXT node point back to the CURRENT node (ptr).
  ptr->next->next = ptr;

  // Isolate the current node so we don't create a cyclic loop.
  ptr->next = NULL;

  return head;
}
