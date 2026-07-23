#include<stdio.h>
#include<stdlib.h>

struct tree {
  int data;
  struct tree *left;
  struct tree *right;
  int left_thread; // 1 = thread to predecessor
  int right_thread; // 1 = thread to successor
};

struct tree *root = NULL;

struct tree* create_new_node();
struct tree* insert_node(struct tree* root, struct tree* new_node);
void inorder_traversal(struct tree* root);

int main() {
  int choice, num;
  struct tree *new_node;

  printf("\n1. Insert Node\t2. Inorder Traversal\t3. Exit\n");

  do {
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
    case 1:
      new_node = create_new_node();
      root = insert_node(root, new_node);
      break;
    
    case 2: inorder_traversal(root); break;

    case 3: printf("Exting....\n"); break;

    default: printf("Invalid Choice\n"); break;
    }
  } while (choice != 3);
  
  return 0;
}

struct tree* insert_node(struct tree* root, struct tree* new_node) {
  if (root == NULL)
    return new_node;

  if (new_node->data < root->data) {
    if (root->left_thread == 1) {         // Left position is available (thread)
      new_node->left = root->left;        // Set predecessor
      new_node->right = root;             // Set successor
      root->left = new_node;
      root->left_thread = 0;              // Now it's a real child
    } else {
      root->left = insert_node(root->left, new_node);
    }
  } else if (new_node->data > root->data) {
    if (root->right_thread == 1) {        // Right position is available
      new_node->left = root;              // Predecessor
      new_node->right = root->right;      // Successor
      root->right = new_node;
      root->right_thread = 0;
    } else {
      root->right = insert_node(root->right, new_node);
    }
    
  } else {
    printf("Duplicate key %d!\n", new_node->data);
    free(new_node);   // Don't leak memory
  }
  
  return root;
}

// In-order Traversal
void inorder_traversal(struct tree* root) {
  if (root == NULL) {
    printf("Tree is empty!\n");
    return;
  }

  struct tree* curr = root;
  while (curr->left_thread == 0) {
    curr = curr->left;
  }

  while (curr != NULL) {
    printf("%d ", curr->data);
        
    if (curr->right_thread) {
      curr = curr->right;
    } else {
      curr = curr->right;
      while (curr && curr->left_thread == 0) {
        curr = curr->left;
      }
    }
  }
  printf("\n");
}

struct tree* create_new_node() {

  int val;
  printf("Enter number: ");
  scanf("%d",&val);

  struct tree *new_node = (struct tree *)malloc(sizeof(struct tree));
  new_node->data = val;
  new_node->left = NULL;
  new_node->right = NULL;
  new_node->left_thread = 1;
  new_node->right_thread = 1;

  return new_node;
}
