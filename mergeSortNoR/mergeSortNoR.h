#pragma once 
#include <stdlib.h>
void merge(int arr[], int left, int mid, int right, int extra[])
{
  int i = left;//左边数组下标起始位置
  int j = mid; //右边数组的下标起始位置
  int k = left;//extra下标的起始位置
  while(i < mid && j < right)
  {
    if(arr[i] > arr[j]) 
    {
      extra[k++] = arr[j++];
    }
    else 
    {
      extra[k++] = arr[i++];
    }
  }
  //要合并的两个数组一旦不等长
  //意味着已经各自有序,剩下的依次赋值即可
  while(i < mid)
  {
    extra[k++] = arr[i++];
  }
  while(j < right)
  {
    extra[k++] = arr[j++];
  }
  int idx;
  for(idx = left; idx < right; ++idx)
  {
    arr[idx] = extra[idx];
  }
}
//归并排序,迭代版本
void mergeSortNoR(int arr[], int size)
{
  int *extra = (int *)malloc(sizeof(int) * size);
  //递归次数成以2为底的对数形式
  int i;//有序数组的长度
  for(i = 1; i < size; i = i * 2)
  {
    //每层进行多次合并
    int j;
    for(j = 0; j < size; j = j + i*2)
    {
      int left = j;
      int mid = j + i;
      //如果mid大于数组长度说明只有一个数,无需合并
      if(mid >= size)
      {
        continue;
      }
      int right = mid + i;
      //防止越界
      if(right > size)
      {
        right = size;
      }
      merge(arr, left, mid, right, extra);
    }
  }
  free(extra);
}
