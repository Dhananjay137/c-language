#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *create_ll(struct node *);
int occurrence(struct node *, int);

int main() {

  head = create_ll(head);
  printf("Linked List created !\n");

  int num;
  printf("Enter number: ");
  scanf("%d",&num);

  int occur = occurrence(head,num);
  printf("\n%d occurrence in the LL: %d times\n",num,occur);


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
      new_node->next = NULL;
      head = new_node;
    } else {
      ptr = head;
      while(ptr->next != NULL)
        ptr = ptr->next;

      ptr->next = new_node;
      new_node->next = NULL;
    }

    printf("Enter the data: ");
    scanf("%d",&num);
  }

  return head;
}

int occurrence(struct node *head, int num){
  struct node *ptr;
  int count = 0;
  ptr = head;

  while (ptr!=NULL)
  {
    if(ptr->data == num){
      count++;
    }
    ptr = ptr->next;
  }
  return count;
}
