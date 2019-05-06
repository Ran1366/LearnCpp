#include <stdio.h>
#include "buildHeap.h"

void pArr(int arr[], int size, char *commit)
{
  printf("%s : ", commit);
  int i = 0;
  for(; i < size; ++i)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main()
{
  int arr[] = {6, 9, 13, 7, 8, 2, 4, 5};
  int size = sizeof(arr)/sizeof(arr[0]);
  pArr(arr, size, "调整前"); 
  buildTree(arr, size);
  pArr(arr, size, "调整后");
  return 0;
}
