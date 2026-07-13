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
int traversal(struct node *);
struct node *del_first_set_last(struct node *);

int main() {
  head = create_doubly_ll(head);
  printf("Doubly LL is created!\n");

  head = del_first_set_last(head);

  int isEmpty = traversal(head);
  if (isEmpty)
  {
    printf("\nDoubly LL is empty!\n");
  } else {
    printf("\nDoubly LL is shown above!\n");
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

struct node *del_first_set_last(struct node *head){
  // Handle empty list or single-node list (no rotation needed)
  if (head == NULL || head->next == NULL)
    return head;
  
  struct node *ptr, *temp;

  // Save the address of the first node before updating the head pointer
  temp = head;

  // Move head to the second node and disconnect its back link
  head = head->next;
  head->prev = NULL;

  // Traversal pointer to find the current last node
  ptr = head;
  while (ptr->next != NULL)
    ptr = ptr->next;
  
  // Attach the original first node (temp) to the end of the list
  ptr->next = temp;
  temp->prev = ptr;
  temp->next = NULL; // Mark the new end of the list

  return head;
}
