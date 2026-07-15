#include<stdio.h>
#include<stdlib.h>
// Write a program to multiply a polynomial with a given number.

struct node
{
  int coff;
  int num;
  struct node *next;
};

struct node *head = NULL;
struct node *create_ll(struct node *);
int traversal(struct node *);
struct node *multi_poly_with_num(struct node *, int);

int main() {
  head = create_ll(head);

  head = multi_poly_with_num(head,3);

  int isEmpty = traversal(head);
  if (isEmpty)
  {
    printf("\nLL is empty!\n");
  } else {
    printf("\nLL shown above!\n");
  }
  

  return 0;
}

struct node *create_ll(struct node *head){
  struct node *new_node, *ptr;
  int num,coff;

  printf("Enter coff & num (-1 to terminate): \n");
  scanf("%d%d",&coff,&num);

  while(num != -1){
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->coff = coff;
    new_node->num = num;
    new_node->next = NULL;

    if(head == NULL){
      head = new_node;
    } else {
      ptr = head;
      while(ptr->next != NULL)
        ptr = ptr->next;

      ptr->next = new_node;
    }

    printf("Enter coff & num (-1 to terminate): \n");
    scanf("%d%d",&coff,&num);
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
    printf("%dx^%d -> ",ptr->coff,ptr->num);
    ptr = ptr->next;
  }
  printf("NULL");
  return 0;
}

struct node *multi_poly_with_num(struct node *head, int num){
  struct node *ptr = head;

  while (ptr != NULL){
    ptr->coff = ptr->coff * num;
    ptr = ptr->next;
  }

  return head;
}
