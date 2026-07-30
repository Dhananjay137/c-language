#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void create_graph(Node *Graph[], int no_of_nodes);
void display_adj_list(Node *Graph[], int no_of_nodes);
void add_edge(Node *Graph[], int source, int destination);
Node *create_node(int data);          // returns pointer

int main() {
  int total_no_of_nodes, total_no_of_edges;
  int source, destination;

  printf("Enter total nodes in graph: ");
  scanf("%d", &total_no_of_nodes);

  printf("Enter total edges in graph: ");
  scanf("%d", &total_no_of_edges);

  // 0-based indexing: Graph[0] ... Graph[n-1]
  Node *Graph[total_no_of_nodes];

  create_graph(Graph, total_no_of_nodes);

  for (int i = 0; i < total_no_of_edges; i++) {
    printf("Enter Source & Destination (0-based): ");
    scanf("%d %d", &source, &destination);

    // basic range check
    if (source < 0 || source >= total_no_of_nodes ||
      destination < 0 || destination >= total_no_of_nodes) {
      printf("Invalid node number! Skipping this edge.\n");
      continue;
    }

    add_edge(Graph, source, destination);
  }

  printf("\nAdjacency List:\n");
  display_adj_list(Graph, total_no_of_nodes);

  // Free memory
  for (int i = 0; i < total_no_of_nodes; i++) {
    Node *curr = Graph[i];
    while (curr != NULL) {
      Node *temp = curr;
      curr = curr->next;
      free(temp);
    }
  }

  return 0;
}

Node *create_node(int data) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    printf("Memory allocation failed!\n");
    exit(1);
  }
  new_node->data = data;
  new_node->next = NULL;

  return new_node;
}

void create_graph(Node *Graph[], int no_of_nodes) {
  for (int i = 0; i < no_of_nodes; i++) {
    Graph[i] = NULL;
  }
}

void add_edge(Node *Graph[], int source, int destination) {
  // Insert at the beginning (O(1))
  Node *new_node = create_node(destination);
  new_node->next = Graph[source];
  Graph[source] = new_node;
}

void display_adj_list(Node *Graph[], int no_of_nodes) {
  for (int i = 0; i < no_of_nodes; i++) {
    printf("%d: ", i);
    Node *ptr = Graph[i];
    while (ptr != NULL) {
      printf("%d -> ", ptr->data);
      ptr = ptr->next;
    }
    printf("NULL\n");
  }
}