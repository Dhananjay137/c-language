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
void bfs(Node *Graph[], int no_of_nodes, int visited[]);
void enqueue(int *front, int *rear, int arr[], int val);

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

  int visited[total_no_of_nodes];
  for (int i = 0; i < total_no_of_nodes; i++)
    visited[i] = 0;
  
  bfs(Graph, total_no_of_nodes, visited);

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

void enqueue(int *front, int *rear, int arr[], int val) {
  if (*front == -1 && *rear == -1)
    *front = *rear = 0;
  else
    (*rear)++;

  arr[*rear] = val;
}

void bfs(Node *Graph[], int no_of_nodes, int visited[]) {
  int source = 0;
  int queue[no_of_nodes], front = -1, rear = -1;
  int destination;

  printf("Enter destination (0 to %d): ",no_of_nodes-1);
  scanf("%d",&destination);

  // 1. Enqueue source and mark visited
  enqueue(&front,&rear,queue,source);
  visited[source] = 1;
  
  // 2. Loop runs until the queue is completely empty
  while (front <= rear && front != -1) {

    // Get and dequeue Current Vertex
    int current_vertex = queue[front++];

    // Check current node == destination
    if (current_vertex == destination) {
      printf("\nFound destination %d!\n", destination);
      return;
    }

    // 3. Move ptr to the neighbors of the DEQUEUED node
    Node *ptr = Graph[current_vertex];

    while (ptr != NULL) {
      // Enqueue unvisited node & mark them visited
      if (visited[ptr->data] == 0) {
        enqueue(&front,&rear,queue,ptr->data);
        visited[ptr->data] = 1;
      }
    
      ptr = ptr->next;
    }
  }

  // printf("front: %d, rear: %d\n",front,rear);
  // for(int i=0; i<no_of_nodes; i++)
  //   printf("%d ",queue[i]);
  printf("\nDestination %d not reachable from source.\n", destination);

  return;
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