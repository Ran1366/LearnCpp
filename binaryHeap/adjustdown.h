#pragma once 
//二叉堆建小堆,向下调整法
void adjustdown(int arr[], int size, int rootIdx)
{
  int leftIdx = 2 * rootIdx + 1;
  int rightIdx = 2 * rootIdx + 2;
  //如果是叶子结点则直接返回
  if(leftIdx >= size)
  {
    return;
  }
  int minIdx = leftIdx;
  //如果右孩子存在,则比较其与左孩子的大小,较小则更新最小结点下标
  if(rightIdx < size && arr[minIdx] > arr[rightIdx])
  {
    minIdx = rightIdx;
  }
  //如果根节点已经是最小的,则满足小堆的条件,直接返回
  if(arr[rootIdx] <= arr[minIdx])
  {
    return;
  }
  int temp = arr[rootIdx];
  arr[rootIdx] = arr[minIdx];
  arr[minIdx] = temp;
  //如果发生了交换,树的结构可能发生改变,需要再次调整
  adjustdown(arr, size, minIdx);
}
