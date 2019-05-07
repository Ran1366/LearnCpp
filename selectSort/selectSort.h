#pragma once     
void selectSort(int arr[], int size)    
{    
  if(!arr || !size)    
  {    
    return; 
  }    
  int i;    
  for(i = 0; i < size; ++i)    
  {    
    int minIdx = i;    
    int j;    
    for(j = i; j < size; ++j)    
    {    
      if(arr[j] <= arr[minIdx])    
      {    
        minIdx = j;    
      }    
    }    
    int temp = arr[i];    
    arr[i] = arr[minIdx];    
    arr[minIdx] = temp;    
  }    
}
