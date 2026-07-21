#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node *prev;
  int data;
  struct node *next;
};

struct node *head = NULL;

struct node *create_c_doubly_ll(struct node *);
void traversal(struct node *);
int isEmpty(struct node *);
struct node *interchange_node(struct node *, int);

int main() {
  head = create_c_doubly_ll(head);
  traversal(head);

  head = interchange_node(head, 1);
  printf("\nAfter interchange\n");
  traversal(head);

  return 0;
}

struct node *create_c_doubly_ll(struct node *head){
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
      head->prev = head;
    } else {
      ptr = head;
      while(ptr->next != head)
        ptr = ptr->next;

      ptr->next = new_node;
      new_node->prev = ptr;

      new_node->next = head;
      head->prev = new_node;
    }

    printf("Enter the data: ");
    scanf("%d",&num);
  }

  return head;
}

void traversal(struct node *head){
  if (isEmpty(head))
  {
    printf("\nCicruler Doubly LL is empty!\n");
    return;
  }
  
  struct node *ptr;
  ptr = head;
  printf("end <-> ");
  
  do
  {
    printf("%d <-> ",ptr->data);
    ptr = ptr->next;
  } while (ptr != head);
  
  printf("start");
  return;
}

int isEmpty(struct node *head){
  return head == NULL;
}

struct node *interchange_node(struct node *head, int k) {
    if (head == NULL || head->next == head) 
        return head;

    // Find the k-th node
    struct node *kth = head;
    for (int i = 1; i < k; i++) {
        kth = kth->next;
        if (kth == head) return head;  // k is invalid
    }

    struct node *k1th = kth->next;   // (k+1)th node

    // Special Case: k is last node, so k+1 is head
    if (k1th == head) {
        // Swap last node and head
        struct node *last = kth;
        struct node *first = head;

        // Update head to last node
        head = last;

        // Adjust links
        last->next = first->next;
        first->next->prev = last;

        first->prev = last->prev;
        last->prev->next = first;

        first->next = last;
        last->prev = first;

        return head;
    }

    // Normal Case: Swap two adjacent nodes in middle
    struct node *prev = kth->prev;
    struct node *next = k1th->next;

    prev->next = k1th;
    k1th->prev = prev;

    k1th->next = kth;
    kth->prev = k1th;

    kth->next = next;
    next->prev = kth;

    // If head was involved (k==1)
    if (k == 1) {
        head = k1th;
    }

    return head;
}
