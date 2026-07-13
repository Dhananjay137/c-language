#include<stdio.h>
#include<stdlib.h>

struct node
{
  char data;
  struct node* next;
};

struct node *head = NULL;
struct node *create_ll(struct node *);
int traversal(struct node *);
struct node *del_first_occurrence(struct node *);
struct node *del_last_occurrence(struct node *);
struct node *del_all_occurrence(struct node *);

int main() {
  head = create_ll(head);
  printf("LL is created!\n");

  // head = del_first_occurrence(head);
  // head = del_last_occurrence(head);
  head = del_all_occurrence(head);

  int isEmpty = traversal(head);
  if (isEmpty)
  {
    printf("\nLL is empty!\n");
  } else {
    printf("\nLL is shown above!\n");
  }
  

  return 0;
}

struct node *create_ll(struct node *head){
  struct node *new_node, *ptr;
  char cha;

  printf("Enter 0 to end\n");
  printf("Enter the data: ");
  scanf(" %c",&cha);

  while(cha != '0'){
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = cha;
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
    scanf(" %c",&cha);
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
    printf("%c -> ",ptr->data);
    ptr = ptr->next;
  }
  printf("NULL");
  return 0;
}

struct node *del_first_occurrence(struct node *head){
  // 1. Handle an empty list safely
  if (head == NULL) {
    printf("The list is empty!\n");
    return head;
  }
  
  char ch;
  printf("Enter the character: ");
  scanf(" %c", &ch);

  // 2. Handle deleting the very first node (head)
  if (head->data == ch)
  {
    struct node *temp = head; // Keep track of it to free it!
    head = head->next;
    free(temp);               // Clean up memory
    return head;
  }

  // 3. Traversal for middle or end nodes
  struct node *ptr = head;
  struct node *pre_ptr = NULL;

  // Keep moving as long as we haven't found the char AND haven't reached the end
  while (ptr != NULL && ptr->data != ch)
  {
    pre_ptr = ptr;       // pre_ptr trails behind
    ptr = ptr->next;     // ptr moves forward
  }
  
  // If ptr is NULL, it means we scanned the whole list and didn't find 'ch'
  if (ptr == NULL) {
    printf("Character '%c' not found in the list.\n", ch);
    return head;
  }

  // If we found it, unlink the node and free its memory safely
  pre_ptr->next = ptr->next;
  free(ptr);
  
  return head;
}

struct node *del_last_occurrence(struct node *head) {
  // 1. Handle an empty list safely
  if (head == NULL) {
    printf("The list is empty!\n");
    return head;
  }
  
  char ch;
  printf("Enter the character: ");
  scanf(" %c", &ch);

  struct node *ptr = head;
  struct node *pre_ptr = NULL;  // Tracks the node right behind 'ptr'

  struct node *last_node = NULL;      // Will hold the absolute last matching node
  struct node *prev_to_last = NULL;   // Will hold the node right before last_node

  // 2. Scan the entire list from start to finish
  while (ptr != NULL) {
    if (ptr->data == ch) {
      last_node = ptr;         // Found a match! Remember it.
      prev_to_last = pre_ptr;  // Remember its previous node too.
    }
    pre_ptr = ptr;             // Move pre_ptr forward safely
    ptr = ptr->next;           // Move ptr forward safely
  }
  
  // 3. If last_node is still NULL, the character was never found
  if (last_node == NULL) {
    printf("Character '%c' not found in the list.\n", ch);
    return head;
  }

  // 4. Time to delete! Check if the last occurrence happens to be the head node
  if (last_node == head) {
    head = head->next;   // Shift head forward
    free(last_node);     // Free the old head
  } else {
    // It's in the middle or end: bypass last_node and free it
    prev_to_last->next = last_node->next;
    free(last_node);
  }
  
  return head;
}

struct node *del_all_occurrence(struct node *head) {
  // 1. Handle an empty list safely
  if (head == NULL) {
    printf("The list is empty!\n");
    return head;
  }
  
  char ch;
  printf("Enter the character to delete all occurrences of: ");
  scanf(" %c", &ch);

  struct node *temp;

  // 2. Clear any matches at the very beginning of the list (updating the head)
  // We use a while loop here in case the list starts with multiple matches (e.g., 'B' -> 'B' -> 'C')
  while (head != NULL && head->data == ch) {
    temp = head;
    head = head->next; // Shift head forward
    free(temp);        // Delete the matching old head
  }

  // 3. Clear matches in the middle or end of the list
  struct node *ptr = head;
  
  // As long as we have at least one node left to check
  while (ptr != NULL && ptr->next != NULL) {
    if (ptr->next->data == ch) {
      // Found a match! Look ahead and unlink it
      temp = ptr->next;
      ptr->next = ptr->next->next; // Bypass the matching node
      free(temp);                  // Delete it from memory
      
      // Note: We do NOT advance 'ptr' here because the *new* ptr->next 
      // needs to be checked on the next loop iteration!
    } else {
      ptr = ptr->next; // Only move forward if we didn't delete anything
    }
  }
  
  return head;
}