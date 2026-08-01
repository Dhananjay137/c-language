#include <stdio.h>

int heap_index = -1;

void insert_ele(int min_heap[], int val, int max_size); 
int delete_ele(int min_heap[]); 
void traverse(int min_heap[]);
int isEmpty(); 

int main() {
  int num, no_of_nodes;

  printf("Enter number of nodes in Heap: ");
  if (scanf("%d", &no_of_nodes) != 1 || no_of_nodes <= 0) return 1;

  int min_heap[no_of_nodes];

  for (int i = 0; i < no_of_nodes; i++) {
    printf("Enter number you want to add: ");
    scanf("%d", &num);
    insert_ele(min_heap, num, no_of_nodes);
  }
  
  printf("\nInitial Min-Heap: ");
  traverse(min_heap);

  // Example Deletion (Extracts the minimum element)
  if (!isEmpty()) {
    int deleted = delete_ele(min_heap);
    printf("\nDeleted minimum element: %d\n", deleted);
    printf("Heap after deletion: ");
    traverse(min_heap);
  }

  return 0;
}

int isEmpty() {
  return heap_index == -1;
}

// INSERTION: Bubbles UP if the current element is SMALLER than its parent
void insert_ele(int min_heap[], int val, int max_size) {
  if (heap_index >= max_size - 1) {
    printf("Heap Overflow! Cannot insert %d\n", val);
    return;
  }

  min_heap[++heap_index] = val;

  int current = heap_index;
  int par = (current - 1) / 2;

  while (current != 0) {
    // Swap if current is SMALLER than parent
    if (min_heap[current] >= min_heap[par]) {
      return;
    } else {
      int temp = min_heap[current];
      min_heap[current] = min_heap[par];
      min_heap[par] = temp;
    }
    current = par;
    par = (current - 1) / 2;
  }
}

// DELETION: Bubbles DOWN to find the SMALLEST child
int delete_ele(int min_heap[]) {
  if (isEmpty()) {
    printf("Heap Underflow! Cannot delete.\n");
    return -1;
  }

  int root_val = min_heap[0];
  min_heap[0] = min_heap[heap_index];
  heap_index--; 

  int current = 0;
  while (1) {
    int left = (2 * current) + 1;
    int right = (2 * current) + 2;
    int smallest = current; // Track the smallest index

    // Check if left child is SMALLER
    if (left <= heap_index && min_heap[left] < min_heap[smallest]) {
      smallest = left;
    }

    // Check if right child is SMALLER
    if (right <= heap_index && min_heap[right] < min_heap[smallest]) {
      smallest = right;
    }

    if (smallest == current) {
      break;
    }

    int temp = min_heap[current];
    min_heap[current] = min_heap[smallest];
    min_heap[smallest] = temp;

    current = smallest; 
  }

  return root_val;
}

void traverse(int min_heap[]) {
  if (isEmpty()) {
    printf("Min Heap is empty!\n");
    return;
  }

  for (int i = 0; i <= heap_index; i++) {
    printf("%d ", min_heap[i]);
  }
  printf("\n");
}
