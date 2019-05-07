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
//递归分割数组时,下标范围左闭右开[)
void merge_seg(int arr[], int left, int right, int extra[])
{
  //当数组只有一个元素或没有元素时,返回
  if(right == left + 1 || left > right)
  {
    return;
  }
  int mid = left + (right - left) / 2;
  //分割数组
  merge_seg(arr, left, mid, extra);
  merge_seg(arr, mid, right, extra);
  //合并数组
  merge(arr, left, mid, right, extra);
}
void mergeSort(int arr[], int size) 
{
  int *extra = (int*)malloc(sizeof(int) * size);
  merge_seg(arr, 0, size, extra);
  free(extra);
}
