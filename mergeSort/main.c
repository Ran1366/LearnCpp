#include <stdio.h>
#include "mergeSort.h"

void pArr(int arr[], int size, char *commit)
{
  int i;
  printf("%s : ", commit);
  for(i = 0; i < size; ++i)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
int main()
{
  int arr[] = {6, 9, 13, 7, 1, 8, 2, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  pArr(arr, size, "排序前");
  mergeSort(arr, size);
  pArr(arr, size, "排序后");
  return 0;
}
