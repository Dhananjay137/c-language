#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;

struct node *create_circular_ll(struct node *);
void traversal(struct node *);
struct node *del_at_beg(struct node *);
struct node *del_at_end(struct node *);
struct node *del_after(struct node *);
struct node *del_list(struct node *);
int isEmpty(struct node *);

int main() {
  head = create_circular_ll(head);
  printf("\nCircular LL is created!\n");
  printf("\nCircular LL before deletation!");
  traversal(head);

  // head = del_at_beg(head);
  // head = del_at_end(head);
   head = del_after(head);
  // head = del_list(head);

  printf("\n\nCircular LL after deletation!");
  traversal(head);

  return 0;
}

struct node *create_circular_ll(struct node *head){
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
    } else {
      ptr = head;
      while(ptr->next != head)
        ptr = ptr->next;

      ptr->next = new_node;
      new_node->next = head;
    }

    printf("Enter the data: ");
    scanf("%d",&num);
  }

  return head;
}

void traversal(struct node *head){
  if(isEmpty(head))
    return;
  
  struct node *ptr;
  ptr = head;
  
  printf("\n");
  do
  {
    printf("%d -> ",ptr->data);
    ptr = ptr->next;
  } while (ptr != head);
  
  printf("HEAD");
  return;
}

int isEmpty(struct node *head){
  if (head != NULL)
    return 0;

  printf("\nLL is Empty!\n");
  return 1;
}

struct node *del_at_beg(struct node *head){
  // Check NULL case.
  if (isEmpty(head))
    return head;
  
  // Store head in temparary pointer and point to next head as new head.
  struct node *temp = head;
  head = head->next;

  // Handle single node case.
  if (head == temp)
  {
    free(temp);
    head = NULL;
    return head;
  }

  // Set ptr as last node of circular LL.
  struct node *ptr = head;
  while (ptr->next != temp)
    ptr = ptr->next;

  // Complete the circular LL by pointing last node to new head.
  ptr->next = head;

  // Free space of the temparay old head from memory.
  free(temp);

  return head;
}

struct node *del_at_end(struct node *head){
  // Check NULL case.
  if (isEmpty(head))
    return head;

  struct node *ptr = head;
  struct node *pre_ptr = NULL;

  // Handle one node case.
  if (head->next == head)
  {
    head = NULL;
    free(ptr);
    return head;
  }

  // Set pre_ptr as last to second node.
  while (ptr->next != head)
  {
    pre_ptr = ptr;
    ptr = ptr->next;
  }
  
  // Pointing to head from before the last node & free last node from memory space.
  pre_ptr->next = head;
  free(ptr);
  
  return head;
}

struct node *del_after(struct node *head){
  if (isEmpty(head))
    return head;
  
  int val;
  printf("\nEnter number you want to delete form the LL: ");
  scanf("%d",&val);

  struct node *ptr = head;
  struct node *pre_ptr = ptr;
  
  while (pre_ptr->data != val){
    pre_ptr = ptr;
    ptr = ptr->next;
  }

  pre_ptr->next = ptr->next;
  if(ptr == head)
    head = pre_ptr->next;
  
  free(ptr);
  return head; 
}

struct node *del_list(struct node *head) {
    // 1. Handle empty list case
    if (isEmpty(head))
      return head;

    struct node *current = head;
    struct node *next_node = NULL;

    // 2. Traverse and free nodes until we loop back to the start
    while (current->next != head) {
        next_node = current->next;
        free(current);
        current = next_node;
    }

    // 3. Free the very last remaining node
    free(current);

    // 4. Return NULL because the list is now entirely gone
    return NULL; 
}