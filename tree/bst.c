#include<stdio.h>
#include<stdlib.h>

struct node
{
  struct node *left;
  int data;
  struct node *right;
};

struct node *tree;

void create_tree(struct node *);
struct node *insert_ele(struct node *);
struct node *delete_node(struct node *, int);
struct node *find_min(struct node *);
int total_nodes(struct node *);

void preorder_traversal(struct node *);
void inorder_traversal(struct node *);
void postorder_traversal(struct node *);

int main() {
  create_tree(tree);
  printf("Tree are created!\n");

  tree = insert_ele(tree);
  printf("Elements are successfully instered into Tree!\n");

  int count = total_nodes(tree);
  printf("Total nodes: %d\n",count);

  tree = delete_node(tree,2);
  printf("\nNode deleted successfully!\n");

  printf("\n+-------------------------------+\n");
  printf("|\tTRAVERSAL OF BST\t|");
  printf("\n+-------------------------------+\n");

  printf("Preorder  : ");
  preorder_traversal(tree);

  printf("\nInorder   : ");
  inorder_traversal(tree);

  printf("\nPostorder : ");
  postorder_traversal(tree);

  count = total_nodes(tree);
  printf("\nTotal nodes: %d\n",count);

  return 0;
}

void create_tree(struct node *tree){
  tree = NULL;
}

struct node* insert_ele(struct node *tree){
  struct node *new_node, *ptr, *parent_node;
  int val;
  printf("Enter value(enter -1 to terminate): ");
  scanf("%d",&val);

  while (val != -1)
  {
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;

    if (tree == NULL) {
      
      tree = new_node;
      tree->left = NULL;
      tree->right = NULL;
    } else {

      parent_node = NULL;
      ptr = tree;
      while (ptr != NULL)
      {
        parent_node = ptr;
        if (val < ptr->data)
          ptr = ptr->left;

        else
          ptr = ptr->right;
      }
      if (val < parent_node->data)
        parent_node->left = new_node;
      else
        parent_node->right = new_node;
      
    }
    
    printf("Enter value(enter -1 to terminate): ");
    scanf("%d",&val);
  }
  return tree;
}

struct node *delete_node(struct node *tree,int key){

  if (tree == NULL)
    return tree;
  
  // Find node to delete
  if (key < tree->data)
  {
    tree->left = delete_node(tree->left, key);
  } else if (key > tree->data)
  {
    tree->right = delete_node(tree->right, key);
  } else {
    // Node found - 3 case

    // Case 1: No child (Leaf Node)
    if (tree->left == NULL && tree->right == NULL)
    {
      free(tree);
      return NULL;
    }

    // Case 2: One Child
    else if(tree->left == NULL){

      struct node *temp = tree->right;
      free(tree);
      return temp;
    } else if(tree->right == NULL){

      struct node *temp = tree->left;
      free(tree);
      return temp;
    }

    // Case 3: two child
    else {
      // Finde inorder successor (smallest in right subtree)
      struct node *temp = find_min(tree->right);

      // Copy successor's data to this node
      tree->data = temp->data;

      // Delete the successor
      tree->right = delete_node(tree->right,temp->data);
    }
    
  }
  return tree;
}

struct node *find_min(struct node *tree){
  while (tree->left != NULL)
  {
    tree = tree->left;
  }
  return tree;
}

void preorder_traversal(struct node *tree){
  if (tree != NULL)
  {
    printf("%d\t",tree->data);
    preorder_traversal(tree->left);
    preorder_traversal(tree->right);
  }
  
}

void inorder_traversal(struct node *tree){
  if (tree != NULL)
  {
    inorder_traversal(tree->left);
    printf("%d\t",tree->data);
    inorder_traversal(tree->right);
  }
  
}

void postorder_traversal(struct node *tree){
  if (tree != NULL)
  {
    postorder_traversal(tree->left);
    postorder_traversal(tree->right);
    printf("%d\t",tree->data);
  }
  
}

int total_nodes(struct node *tree){
  if(tree == NULL)
    return 0;
  else
    return (total_nodes(tree->left) + total_nodes(tree->right) + 1);
}
