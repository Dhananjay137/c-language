#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;
int count = 0;

struct node *create_ll(struct node *);
void traversal(struct node *);
int isEmpty(struct node* );
void print_nth_data_from_last(struct node *, int);

int main() {
  head = create_ll(head);
  traversal(head);

  print_nth_data_from_last(head,2);

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

void print_nth_data_from_last(struct node *head, int position){
  if (head == NULL)
    return;
  
  // Go to the end first
  print_nth_data_from_last(head->next, position);

  // Count while coming back
  count++;

  if (count == position)
  {
    printf("\nData form last node to %dth position is %d\n",position, head->data);
  }
  
}
