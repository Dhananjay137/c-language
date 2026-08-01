#include<stdio.h>

int heap_index = -1;

void insert_ele(int max_heap[], int val);
int delete_ele(int max_heap[]);
void traverse(int max_heap[]);
int isEmpty();

int main() {
  int num, no_of_nodes;

  printf("Enter number of nodes are in Heap: ");
  scanf("%d",&no_of_nodes);

  int max_heap[no_of_nodes];

  for (int i=0; i<no_of_nodes; i++) {
    printf("Enter number you want to add: ");
    scanf("%d",&num);

    insert_ele(max_heap, num);
  }
  
  traverse(max_heap);

  int deleted_node = delete_ele(max_heap);
  printf("Deleted Node is %d\n",deleted_node);

  traverse(max_heap);

  return 0;
}

int isEmpty() {
  return heap_index == -1;
}

void insert_ele(int max_heap[], int val) {

  max_heap[++heap_index] = val;

  int current = heap_index;
  int par = (current-1)/2;

  while (current != 0) {
    if (max_heap[current] <= max_heap[par]) {
      return;
    } else {
      int temp = max_heap[current];
      max_heap[current] = max_heap[par];
      max_heap[par] = temp;
    }
    current = par;
    par = (current-1)/2;
  }
  
  return;
}

int delete_ele(int max_heap[]) {
  if (isEmpty()) {
    printf("Heap Underflow! Cannot delete.\n");
    return -1;
  }

  // 1. Save the root element to return later
  int root_val = max_heap[0];

  // 2. Move the last element to the root position & Reduce heap size
  max_heap[0] = max_heap[heap_index--];

  // 3. Max-Heapify Down (Bubble Down)
  int current = 0;
  while (1) {
    int left = (2 * current) + 1;
    int right = (2 * current) + 2;
    int largest = current;

    // Check if left child exists and is larger than current largest
    if (left <= heap_index && max_heap[left] > max_heap[largest]) {
      largest = left;
    }

    // Check if right child exists and is larger than current largest
    if (right <= heap_index && max_heap[right] > max_heap[largest]) {
      largest = right;
    }

    // If largest is still current, heap property is restored
    if (largest == current) {
      break;
    }

    // Swap current with the larger child
    int temp = max_heap[current];
    max_heap[current] = max_heap[largest];
    max_heap[largest] = temp;

    current = largest; // Move down to child index
  }

  return root_val;
}

void traverse(int max_heap[]) {
  if (isEmpty(heap_index)) {
    printf("Max Heap is empty!\n");
    return;
  }

  printf("heap index: %d\n",heap_index);
  for (int i = 0; i <= heap_index; i++) {
    printf("%d ",max_heap[i]);
  }
  
  
}
