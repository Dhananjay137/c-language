#include<stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void create_graph(Node *Graph[], int total_no_of_nodes, int total_no_of_edges);
void display_adj_list(Node *Graph[], int no_of_nodes);
void add_edge(Node *Graph[], int source, int destination);
Node *create_node(int data);          // returns pointer

int isCycle(Node* Graph[], int no_of_nodes);
int dfs(int u, int parent, Node* Graph[], int visited[]);

int main() {
  int total_no_of_nodes, total_no_of_edges;

  printf("Enter total nodes in graph: ");
  scanf("%d", &total_no_of_nodes);

  printf("Enter total edges in graph: ");
  scanf("%d", &total_no_of_edges);

  // 0-based indexing: Graph[0] ... Graph[n-1]
  Node *Graph[total_no_of_nodes];

  // Create Graph (Undirected)
  create_graph(Graph, total_no_of_nodes, total_no_of_edges);
  
  // Print Adjacency List
  printf("\nAdjacency List:\n");
  display_adj_list(Graph, total_no_of_nodes);

  // Check Cycle
  int flag = isCycle(Graph, total_no_of_edges);

  if (flag) printf("Cycle found!\n");
  else printf("Cycle not found!\n");

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

void create_graph(Node *Graph[], int total_no_of_nodes, int total_no_of_edges) {
  int source, destination;

  for (int i = 0; i < total_no_of_nodes; i++) {
    Graph[i] = NULL;
  }

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

}

void add_edge(Node *Graph[], int source, int destination) {
  // 1. Add edge from source to destination
  Node *new_node1 = create_node(destination);
  new_node1->next = Graph[source];
  Graph[source] = new_node1;

  // 2. Add edge from destination to source
  Node *new_node2 = create_node(source);
  new_node2->next = Graph[destination];
  Graph[destination] = new_node2;
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

int isCycle(Node* Graph[], int no_of_nodes) {
  // 1. Create visited array and initialize with 0
  int visited[no_of_nodes];
  for (int i=0; i<no_of_nodes; i++)
    visited[i] = 0;

  // 2. Call DFS for every unvisited node
  // (Graph may be disconnected)
  for (int i=0; i<no_of_nodes; i++) {
    if (visited[i] == 0) {
      // For starting node, parent is -1 (no parent)
      if (dfs(i, -1, Graph, visited)) return 1; // Cycle found
    }
  }

  // 3. No cycle in any component
  return 0;
}

// u = current node
int dfs(int u, int parent, Node* Graph[], int visited[]) {
  // 1. Mark the current node as visited
  visited[u] = 1;

  // 2. Traverse all neighbors of u using adjacency list
  Node* ptr = Graph[u];
  while (ptr != NULL) {
    int v = ptr->data; // neighbor

    // 3. If neighbor is not visited → call DFS
    if (visited[v] == 0) {
      if (dfs(v, u, Graph, visited)) return 1;
    }

    // 4. If neighbor is already visited AND it is not the parent → Cycle exists
    else if (v != parent) return 1;

    ptr = ptr->next;
  }

  // 5. No cycle found from this node
  return 0;
}
