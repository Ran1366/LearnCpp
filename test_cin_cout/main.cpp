#include <iostream>
//using namespace std;
namespace ran
{
  int cout;
}
//using namespace ran;

using std::cout;
using std::cin;
using std::endl;
int main()
{
  //std::cout << "enter tow numbers" << std::endl;
  //int a, b;
  //std::cin >> a >> b;
  //std::cout << a << "+" << b << "is" << a + b << std::endl;
  
  //std::cout << "the sum of " << 1;
  //std::cout << " and " << 2;
  //std::cout << " is " << 1 + 2 << std::endl;
  
  //std::cout << "/*" << std::endl;
  //std::cout << "*/" << std::endl;
  //std::cout << /* "*" */  std::endl;
  //std::cout << /* "*/" /* "/*" */;
  ran::cout = 10; 
  cout << ran::cout << endl;
}
