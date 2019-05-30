#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int codeLength(const string &code)
{
  int size = (int)code.size();
  if (size <= 4)
  {
    return 5;
  }
  else if (size > 5 && size < 7)
  {
    return 10;
  }
  else
  {
    return 25;
  }
}

int haveAlfa(const string &code)
{
  int bigAlfa = 0;
  int smallAlfa = 0;
  for (int i = 0; i < (int)code.size(); ++i)
  {
    if (code[i] >= 'a' && code[i] <= 'z')
    {
      ++smallAlfa;
    }
    else if (code[i] >= 'A' && code[i] <= 'Z')
    {
      ++bigAlfa;
    }
  }
  if (bigAlfa == 0 && smallAlfa == 0)
  {
    return 0;
  }
  else if ((bigAlfa == 1 && smallAlfa == 0) || (bigAlfa == 0 && smallAlfa == 1))
  {
    return 10;
  }
  else
  {
    return 20;
  }
}

int haveNum(const string &code)
{
  int num = 0;
  for (int i = 0; i < (int)code.size(); ++i)
  {
    if (code[i] >= '0' && code[i] <= '9')
    {
      ++num;
    }
  }
  if (num == 0)
  {
    return 0;
  }
  else if (num == 1)
  {
    return 10;
  }
  else
  {
    return 20;
  }
}

int haveSingbel(const string &code)
{
  int sigbel = 0;
  for (int i = 0; i < (int)code.size(); ++i)
  {
    if ((code[i] >= '!' && code[i] <= '/')
        || (code[i] >= ':' && code[i] <= '@')
        || (code[i] >= '[' && code[i] <= '`')
        || (code[i] >= '{' && code[i] <= '~'))
    {
      ++sigbel;
    }
  }
  if (sigbel == 0)
  {
    return 0;
  }
  else if (sigbel == 1)
  {
    return 10;
  }
  else
  {
    return 25;
  }
}
const char* safeLev(int num, const string safeLevel[])
{
  int level = num / 10;
  if (num >= 25)
  {
    return safeLevel[level].c_str();
  }
  else
  {
    return safeLevel[0].c_str();
  }
}
int main() {
  string safeLevel[] = { "VERY_WEAK", "VERY_WEAK", "WEAK", "WEAK", "WEAK",
    "AVERAGE","STRONG", "VERY_STRONG", "SECURE", "VERY_SECURE" };
  string code;
  getline(cin, code);
  int lengthCode = codeLength(code);
  int alfaCode = haveAlfa(code);
  int numCode = haveNum(code);
  int singbelCode = haveSingbel(code);
  int gift = 0;
  if (alfaCode == 25 && numCode > 0 && singbelCode > 0)
  {
    gift += 10;
  }
  else if (alfaCode > 0 && numCode > 0 && singbelCode > 0)
  {
    gift += 5;
  }
  else if (alfaCode > 0 && numCode > 0)
  {
    gift += 2;
  }
  int sum = lengthCode + alfaCode + numCode + singbelCode + gift;
  cout << safeLev(sum, safeLevel) << endl;
  return 0;
}
