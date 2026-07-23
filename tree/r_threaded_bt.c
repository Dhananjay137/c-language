#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node *left;
  int data;
  struct node *right;
  int rightThread; // 1 = thread, 0 child
};

struct node *root = NULL;

struct node *insert_node(struct node *root, struct node *new_node, struct node *rt);
void inorder_traversal(struct node *root);
struct node *find_left_most_node(struct node *root);

struct node *create_new_node();

int main() {

  printf("\n1. Insert Node\t2. Inorder Traversal\t3. Exit\n");
  int choice;
  struct node *new_node;
  do {
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch (choice) {
    case 1: 
      new_node = create_new_node();
      root = insert_node(root, new_node, NULL);
      break;
    
    case 2: inorder_traversal(root); break;

    case 3: printf("Exting...\n"); break;
    default: printf("Invalid Choice\n"); break;
    }
  } while (choice != 3);

  return 0;
}

struct node *insert_node(struct node *root, struct node *new_node, struct node *rt) {
  if (root == NULL) {
    root = new_node;

    if (rt != NULL) {
      root->right = rt;
      root->rightThread = 1;
    }
    return root;
  }

  if (new_node->data < root->data) {
    // Going left
    root->left = insert_node(root->left, new_node, root);
  } else {
    // Going right
    if (root->rightThread == 1) { 
      // Replace thread with new node 
      new_node->right = root->right;     // Inherit old thread
      new_node->rightThread = 1; 
      root->right = new_node; 
      root->rightThread = 0; 
    } else {
      root->right = insert_node(root->right, new_node, rt);
    }
  }
  return root;
}

void inorder_traversal(struct node *root) {

  if (root == NULL) {
    printf("Tree is empty\n");
    return;
  }
  
  struct node *ptr = root;

  ptr = find_left_most_node(ptr);

  while (ptr != NULL) {
    printf("%d ",ptr->data);

    if (ptr->rightThread) {
      ptr = ptr->right;
    } else {
      ptr = find_left_most_node(ptr->right);
    }
  }
  printf("\n");
}

struct node *find_left_most_node(struct node *root) {
  if (root == NULL) return NULL;

  struct node *ptr = root;
  while (ptr->left != NULL) {
    ptr = ptr->left;
  }
  
  return ptr;
}

struct node *create_new_node() {
  int num;
  printf("Enter number: ");
  scanf("%d",&num);

  struct node *new_node = (struct node *)malloc(sizeof(struct node));

  new_node->data = num;
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->rightThread = 1;

  return new_node;
}
