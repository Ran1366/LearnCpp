#include <iostream>
#include <cstdio>

using namespace std;

int main(){
  //freopen("1.in","r",stdin);
  int arr[4];
  for(int i = 0; i < 4; ++i)
  {
    cin >> arr[i];
  }
  int double_A = arr[0] + arr[2];
  int double_B = arr[1] + arr[3];
  if(double_A >= 0 && 
      double_B >= 0 &&
      (double_A % 2 == 0) && 
      (double_B % 2 == 0))
  {
    int A = double_A / 2;
    int B = double_B / 2;
    int C = arr[3] - B;
    if(B - C == arr[1])
    {
      cout << A << " " << B << " " << C << endl;
    }
    else
    {
      cout << "No" << endl;
    }
  }
  else
  {
    cout << "No" << endl;
  }
  return 0;
}
