#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

void create_graph(Node *Graph[], int total_no_of_nodes, int total_no_of_edges);
void display_adj_list(Node *Graph[], int no_of_nodes);
void add_edge(Node *Graph[], int source, int destination);
Node *create_node(int data);          // returns pointer

void bfs(Node *Graph[], int no_of_nodes);
void dfs(Node *Graph[], int no_of_nodes);

void cal_indegree(Node* Graph[], int no_of_nodes, int indegree_arr[]);
void kahns_algo(Node *Graph[], int no_of_nodes);

void enqueue(int *front, int *rear, int arr[], int val);

int main() {
  int total_no_of_nodes, total_no_of_edges;

  printf("Enter total nodes in graph: ");
  scanf("%d", &total_no_of_nodes);

  printf("Enter total edges in graph: ");
  scanf("%d", &total_no_of_edges);

  // 0-based indexing: Graph[0] ... Graph[n-1]
  Node *Graph[total_no_of_nodes];

  // Create Graph
  create_graph(Graph, total_no_of_nodes, total_no_of_edges);
  
  // Print Adjacency List
  printf("\nAdjacency List:\n");
  display_adj_list(Graph, total_no_of_nodes);
  
  // Traversal
  // bfs(Graph, total_no_of_nodes);
  // dfs(Graph, total_no_of_nodes);

  // Topological Sort
  kahns_algo(Graph, total_no_of_nodes);

  // for (int i = 0; i < total_no_of_nodes ; i++)
  //   printf("indegree[%d] = %d\n",i,indegree_arr[i]);
  

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

void cal_indegree(Node* Graph[], int no_of_nodes, int indegree_arr[]) {
  Node* ptr;

  for (int i=0; i<no_of_nodes; i++)
    indegree_arr[i] = 0;

  for (int i=0; i<no_of_nodes; i++) {
    ptr = Graph[i];
    while (ptr != NULL) {
      indegree_arr[ptr->data]++;
      ptr = ptr->next;
    }
    
  }
}

void kahns_algo(Node *Graph[], int no_of_nodes) {
  int queue[no_of_nodes], front = -1, rear = -1;
  int indegree_arr[no_of_nodes], topological_order[no_of_nodes], top = -1;

  // 1. Calculate indegeree
  cal_indegree(Graph, no_of_nodes,indegree_arr);

  // 2. ENQUEUE all vertex-i with indegree = 0 in queue
  for (int i=0; i<no_of_nodes; i++) {
    if (indegree_arr[i] == 0) {
      enqueue(&front, &rear, queue, i);
    }
  }

  // 3. Loop runs until the queue is completely empty
  while (front <= rear && front != -1) {

    // Take out vertex from front of the queue
    int current_vertex = queue[front++];

    // Add current vertex to topological order
    topological_order[++top] = current_vertex;

    // Reduce the indegree by 1 of neighbor's
    Node* ptr = Graph[current_vertex];
    while (ptr != NULL) {
      indegree_arr[ptr->data]--;

      if (indegree_arr[ptr->data] == 0) {
        // If any neighbor’s indegree becomes 0, ENQUEUE it into the queue.
        enqueue(&front, &rear, queue, ptr->data);
      }
      ptr = ptr->next;
    }
  }

  int processed_vertex = 0;
  for (int i=0; i<=top; i++)
    processed_vertex++;

  if (processed_vertex < no_of_nodes) {
    printf("Cycle exists!\n");
    return;
  }
  
  printf("Topological Order\n");
  for (int i=0; i<=top; i++) {
    printf("%d -> ",topological_order[i]);
  }
  printf("NULL\n");
}

void enqueue(int *front, int *rear, int arr[], int val) {
  if (*front == -1 && *rear == -1)
    *front = *rear = 0;
  else
    (*rear)++;

  arr[*rear] = val;
}

void bfs(Node *Graph[], int no_of_nodes) {
  int source = 0, destination;
  int queue[no_of_nodes], front = -1, rear = -1;
  int visited[no_of_nodes];

  // Initalize Visited array
  for (int i = 0; i < no_of_nodes; i++)
    visited[i] = 0;

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

void dfs(Node *Graph[], int no_of_nodes) {
  int source = 0, destination;
  int stack[no_of_nodes], top = -1;
  Node *ptr;
  int visited[no_of_nodes];

  // Initalize Visited array
  for (int i = 0; i < no_of_nodes; i++)
    visited[i] = 0;

  printf("Enter destination (0 to %d): ",no_of_nodes-1);
  scanf("%d",&destination);

  // 1. PUSH source in stack
  stack[++top] = source;

  // 2. Loop runs until the stack is completely empty
  while (top != -1) {
    
    // POPPED the current vertex
    int current_vertex = stack[top--];
    visited[current_vertex] == 1;

    // Check current vertex == destination
    if (current_vertex == destination) {
      printf("\nFound destination %d!\n", destination);
      return;
    }

    // 3. Move ptr to the neighbors of the POPPED node
    ptr = Graph[current_vertex];

    while (ptr != NULL) {
      // PUSH neighobur on stack
      if (visited[ptr->data] == 0) {
        stack[++top] = ptr->data;
      }
      ptr = ptr->next;
    }
  }

  printf("\nDestination %d not reachable from source.\n", destination);

  return;
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