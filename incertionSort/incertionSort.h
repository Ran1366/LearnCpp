#pragma once 
int* incertionSort(int arr[], int size)
{
  int i;
  for(i = 0; i < size; ++i)
  {
    int k = arr[i];
    int j;
    for(j = i - 1; j >= 0; --j)
    {
      if(k >= arr[j])
      {
        break;
      }
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = k;
  }
  return arr;
}
