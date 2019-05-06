#pragma once 
#include "adjustdown.h"
void buildTree(int arr[], int size)
{
  int i = (size - 2) / 2;
  for(; i >= 0; --i)
  {
    adjustdown(arr, size, i);
  }
}
