#pragma once 

void Swap(int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}
//希尔插入, 使得gap == 1时, 数组基本有序
void hillInsert(int arr[], int size)
{
  if(!arr || !size)
  {
    return;
  }
  int gap = size / 2;
  while(gap)
  {
    int i;
    for(i = 0; i < size - gap; ++i)
    {
      if(arr[i] >= arr[gap + i])
      {
        Swap(&arr[i], &arr[gap + i]);
      }
    }
    gap /= 2;
  }
}
