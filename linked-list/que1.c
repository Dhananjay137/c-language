#include<stdio.h>
#include<stdlib.h>
// Write a program that removes all nodes that have duplicate information.

struct node
{
  int data;
  struct node *next;
  
};

struct node *start = NULL;

void removeDuplicates(struct node *);
struct node *create_ll(struct node *);
int traversal(struct node *);

int main() {

  start = create_ll(start);
  printf("Linked List created!\n");

  int flag = traversal(start);

  if(flag == -1){
    printf("Linked List is empty !\n");
  }

  removeDuplicates(start);

  printf("\nAfter the removing duplicate!\n");
  flag = traversal(start);


  return 0;
}

void removeDuplicates(struct node *start){
  struct node *current = start;
  struct node *index = NULL;

  while (current != NULL)
  {
    index = current;
    while (index -> next!=NULL)
    {
      if(current->data == index->next->data){
        struct node *dup = index->next;
        index->next = index->next->next;
        free(dup);
      } else {
        index = index -> next;
      }
      
    }
    current = current -> next;
    
  }
  
}

struct node *create_ll(struct node *start){
  struct node *new_node, *ptr;
  int num;

  printf("Enter -1 to end\n");
  printf("Enter the data: ");
  scanf("%d",&num);

  while(num != -1){
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;

    if(start == NULL){
      new_node->next = NULL;
      start = new_node;
    } else {
      ptr = start;
      while(ptr->next != NULL)
        ptr = ptr->next;

      ptr->next = new_node;
      new_node->next = NULL;
    }

    printf("Enter the data: ");
    scanf("%d",&num);
  }

  return start;
}

int traversal(struct node *start){
  if(start == NULL)
    return (-1);
  
  struct node *ptr;
  ptr = start;
  while (ptr != NULL)
  {
    printf("%d -> ",ptr->data);
    ptr = ptr->next;
  }
  printf("NULL");
  return 0;
}
