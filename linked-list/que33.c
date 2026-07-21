#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;

struct node *create_ll(struct node *);
void traversal(struct node *);
int isEmpty(struct node* );
struct node *rev_ll(struct node *);

int main() {
  head =  create_ll(head);
  printf("LL Created!\n");

  head = rev_ll(head);
  traversal(head);

  return 0;
}

struct node *create_ll(struct node *head){
  struct node *new_node, *ptr;
  int num;

  printf("Enter num (-1 to terminate): ");
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

    printf("Enter num (-1 to terminate): ");
    scanf("%d",&num);
  }

  return head;
}

void traversal(struct node *head){
  if (isEmpty(head))
    return;
  
  struct node *ptr;
  ptr = head;
  while (ptr != NULL)
  {
    printf("%d -> ",ptr->data);
    ptr = ptr->next;
  }
  printf("NULL");
  return;
}

int isEmpty(struct node* head){
  if (head == NULL)
  {
    printf("\nLL is empty!\n");
    return 1;
  }
  return 0;
}

struct node *rev_ll(struct node *head){
  struct node *new_head;

  // Base Case: If list is empty or has only one node, it is already reversed
  if(head == NULL || head->next == NULL){
    return head;
  }

  // Recursively reverse the rest of the list
  new_head = rev_ll(head->next);

  // Reverse the link: Make next node point back to current node
  // This is the key step of reversal
  head->next->next = head;

  // Break the forward link: Current node becomes the new tail
  head->next = NULL;

  // Return the new head of the reversed list
  return new_head;
}
