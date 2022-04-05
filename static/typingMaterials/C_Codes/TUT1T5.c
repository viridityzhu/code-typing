#include <stdio.h> 
#define MAX 10

int readArray(int [], int);
void printArray(int [], int);
void reverseArray(int [], int);
void reverseArray_recursive(int [], int);
void recursiver(int [], int, int);

int main(void) {
  int array[MAX], numElements;

  numElements = readArray(array, MAX);
  printArray(array, numElements);
  reverseArray(array, numElements);
  printArray(array, numElements);
  reverseArray_recursive(array, numElements);
  printArray(array, numElements);

  return 0; 
}


int readArray(int arr[], int limit) {
    // read data into an integer array (with at most 10 elements
    printf("Enter up to %d integers, terminating with a negative integer.\n", limit);
    int m, size = 0;
    // int l[10];
    while(size < limit){
        scanf("%d",&m);
        if (m < 0) break;
        printf("Entered %d \n", m);
        arr[size++] = m;
    }
    return size;
}


void reverseArray(int arr[], int size) {
   // iterative version
  for(int i = 0; i < size - i - 1; i++){
    int temp = arr[i];
    arr[i] = arr[size-i - 1];
    arr[size - i - 1] = temp;
  }

}

void reverseArray_recursive(int arr[], int size) {
   // recursive version
  recursiver(arr, 0, size - 1);
}

void recursiver(int arr[], int left, int right){
  if(right - left < 1) return;
  int temp = arr[left];
  arr[left] = arr[right];
  arr[right] = temp;
  recursiver(arr, left + 1, right - 1);

}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i<size; i++) {
    printf("%d ", arr[i]); }
    printf("\n"); 
}