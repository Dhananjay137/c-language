#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node *prev;
  int data;
  struct node *next;
};

struct node *head = NULL;
int isEmpty(struct node *);
void traversal(struct node *);
struct node *create_doubly_ll(struct node *);
struct node *move_mid_node_to_top(struct node *);

int main() {
  head = create_doubly_ll(head);
  printf("Doubly LL is created!\n");

  head = move_mid_node_to_top(head);

  traversal(head);

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

void traversal(struct node *head){
  if (isEmpty(head))
  {
    printf("Doubly LL is empty!\n");
    return;
  }
  
  struct node *ptr;
  ptr = head;
  printf("NULL <-> ");
  
  while (ptr != NULL)
  {
    printf("%d <-> ",ptr->data);
    ptr = ptr->next;
  }
  
  printf("NULL");
  return;
}

int isEmpty(struct node *head){
  return head == NULL;
}

struct node *move_mid_node_to_top(struct node *head){
  if (head == NULL || head->next == NULL)
    return head;
  
  struct node *slow_ptr, *fast_ptr, *mid_node;
  slow_ptr = fast_ptr = head;

  // Find the middle node
  while (fast_ptr != NULL && fast_ptr->next != NULL)
  {
    slow_ptr = slow_ptr->next;
    fast_ptr = fast_ptr->next->next;
  }

  // If middle is already at head, do nothing
  if(slow_ptr == head)
    return head;

  // Remove middle node from its current position
  if(slow_ptr->prev != NULL)
    slow_ptr->prev->next = slow_ptr->next;

  if(slow_ptr->next != NULL)
    slow_ptr->next->prev = slow_ptr->prev;

  // Insert middle node at the beginning
  slow_ptr->next = head;
  slow_ptr->prev = NULL;
  head->prev = slow_ptr;
  head = slow_ptr;

  return head;
}
