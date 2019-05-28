#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;
class Parenthesis {
  public:
    bool chkParenthesis(string A, int n) {
      stack<char> s;
      s.push('x');//填充
      string::iterator it = A.begin();
      while (it != A.end())
      {
        cout << "while" << endl;
        if (*it == '(')
        {
          s.push(*it);
          cout << "push" << endl;
        }
        else
        {
          s.pop();
          cout << "pop" << endl;
        }
        if(s.empty())
        {
          break;
        }
        ++it;
      }
      cout << "break" << endl;
      if (s.empty())
      {
        return false;
      }
      else if (s.top() == 'x')
      {
        return true;
      }
      return false;
    }
};
int main()
{
  Parenthesis p;
  string a; 
  int n;
  while (cin >> a >> n)
  {
    cout << p.chkParenthesis(a, n) << endl;

  }
  system("pause");
  return 0;

}
