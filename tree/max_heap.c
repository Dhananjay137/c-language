#include<stdio.h>

#define MAX 10

int max_heap[MAX];
int heap_index = -1;

void insert_ele(int max_heap[], int val);
int delete_ele(int max_heap[], int heap_index);
void traverse(int max_heap[]);
int isEmpty(int heap_index);

int main() {
  int num, count = 0;

  while (count != 10) {
    printf("Enter number you want to add: ");
    scanf("%d",&num);

    insert_ele(max_heap, num);
    count++;
  }
  
  
  traverse(max_heap);
  

  return 0;
}

int isEmpty(int heap_index) {
  return heap_index == -1;
}

void insert_ele(int max_heap[], int val) {
  int isHeap = 0; // 0 = not heap, 1 = heap

  max_heap[++heap_index] = val;

  int pos = heap_index;
  int par = (pos-1)/2;

  while (!isHeap) {
    if (max_heap[pos] <= max_heap[par]) {
      isHeap = 1;
    } else {
      int temp = max_heap[pos];
      max_heap[pos] = max_heap[par];
      max_heap[par] = temp;
    }
    pos = par;
    par = (pos-1)/2;
  }
  
  return;
}

int delete_ele(int max_heap[], int heap_index) {}

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
