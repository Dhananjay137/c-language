#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *create_ll(struct node *);
int traversal(struct node *);
struct node *del_kth_ele(struct node *);

int main() {

  head = create_ll(head);
  printf("LL is created!\n");

  head = del_kth_ele(head);

  int isEmpty = traversal(head);
  if (isEmpty)
  {
    printf("\nLL is empty!\n");
  } else {
    printf("\nLL show above!\n");
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

struct node *del_kth_ele(struct node *head){
  if (head == NULL) {
    printf("The LL is empty!\n");
    return head;
  }

  int k;
  printf("Enter Position of element you want to delete (1-based index): ");
  scanf("%d", &k);

  // 1. Handle invalid positions less than 1
  if (k < 1) {
    printf("Invalid position!\n");
    return head;
  }

  // 2. Special case: Handle deleting the very first node (k = 1)
  if (k == 1) {
    struct node *temp = head;
    head = head->next; // Move head to the second node
    free(temp);        // Delete old head from memory
    return head;
  }

  // 3. Move ptr to the (k-1)-th node (the node right before the one we want to delete)
  struct node *ptr = head;
  for (int i = 1; ptr != NULL && i < k - 1; i++) {
    ptr = ptr->next;
  }

  // 4. Check if position k is out of bounds
  // (Either ptr is NULL or ptr->next is NULL, meaning k-th node doesn't exist)
  if (ptr == NULL || ptr->next == NULL) {
    printf("Linked list is not long enough to have a position %d!\n", k);
    return head;
  }
  
  // 5. Unlink the k-th node and free its memory safely
  struct node *temp = ptr->next; // temp is now the k-th node
  ptr->next = temp->next;        // Link (k-1)-th node to (k+1)-th node
  free(temp);                    // Free the k-th node
  
  return head;
}