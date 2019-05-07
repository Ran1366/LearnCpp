#pragma once

int Swap(int arr[], int low, int high)
{
  int begain = low;
  int end = high;
  int mid = arr[low];
  while(end > begain)
  {
    while(end > begain && arr[end] >= mid)
    {
      end--;
    }
    arr[begain] = arr[end];
    while(end > begain && arr[begain] <= mid)
    {
      begain++;
    }
    arr[end] = arr[begain];
  }
  arr[begain] = mid;
  return begain;
}
void quickSort(int arr[], int low, int high)
{
  if(low >= high)
  {
    return;
  }
  int mid = Swap(arr, low, high);
  quickSort(arr, low, mid - 1);
  quickSort(arr, mid + 1, high);
}
