#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

struct node{
  int data;
  struct node *next;
};

struct node *head = NULL;

struct node *create_ll(struct node *);
int traversal(struct node *);
void print_max_min_val(struct node *);

int main() {
  head = create_ll(head);
  print_max_min_val(head);

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

void print_max_min_val(struct node *head){
  if (head == NULL) {
    printf("The list is empty. No MAX or MIN values exist.\n");
    return;
  }
  
  struct node *ptr = head;
  int max = INT_MIN;
  int min = INT_MAX;

  // Traverse the LL to the null pointer 
  while (ptr != NULL)
  {
    // if find min value than assign it to min
    if (ptr->data < min)
      min = ptr->data;

      // if find max value than assign it to max
    if(ptr->data > max)
      max = ptr->data;
    
    ptr = ptr->next;
  }
  
  printf("MAX value: %d\nMIN value: %d\n",max,min);
}
