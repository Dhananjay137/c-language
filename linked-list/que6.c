#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head1 = NULL;
struct node *head2 = NULL;

struct node *create_ll(struct node *head);
struct node *copy_ll(struct node *, struct node *);
int traversal(struct node *);

int main() {
  head1 = create_ll(head1);
  printf("Linked List is Created!\n");

  head2 = copy_ll(head1, head2);

  int isEmpty = traversal(head2);

  if(isEmpty){
    printf("\nCopy donn't successfully done !\n");
  } else {
    printf("\nCopy LL is Succesfully done !\n");
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

    if(head == NULL){
      new_node->next = new_node;
      head = new_node;
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

struct node *copy_ll(struct node *source, struct node *target){
  if(source == NULL) return NULL;

  struct node *ptr1,*ptr2,*new_node;
  int num;
  ptr1 = source;
  ptr2 = NULL;
  
  do{
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = ptr1->data;

    if(target == NULL){
      new_node->next = new_node;
      target = new_node;
      ptr2 = target;
    } else {
      ptr2->next = new_node;
      new_node->next = target;
      ptr2 = new_node;
    }
    ptr1 = ptr1->next;
  }while(ptr1 != source);
  return target;
}

int traversal(struct node *head){
  if(head == NULL)
    return 1;
  
  struct node *ptr;
  ptr = head;

  do{
    printf("%d -> ",ptr->data);
    ptr = ptr->next;
  }while(ptr != head);

  printf("NULL");
  return 0;
}

