#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
class String
{
  typedef char* iterator;
  public:
  String(char *str = "")
  {
    _size = _capacity = strlen(str);
    _str = new char[_size + 1];
    strcpy(_str, str);


  }

  ~String()
  {
    delete[]_str;
    _str = nullptr;

  }

  String(const String &s)
  {
    _size = _capacity = strlen(s._str);
    _str = new char[_capacity + 1];
    strcpy(_str, s._str);

  }
    char *c_str()
    {
      return _str;
    }

  void push_back(const char c)
  {
    if (_size == _capacity)
    {
      _capacity *= 2;
    }
    String tmp = *this;
    delete[]_str;
    _str = new char[_capacity + 1];
    strcpy(_str, tmp._str);
    _str[_size++] = c;
    _str[_size] = '\0';
  }
  //to do
  //insert;
  //erase;
  //reverse;
  //<<
  //>>
  iterator begin()
  {
    return _str;
  }

  iterator end()
  {
    return _str + _size;
  }

  String &operator=(const String &s)
  {
    if (this != &s)
    {
      _size = s._size;
      _capacity = s._capacity;
      delete[]_str;
      _str = new char[strlen(s._str) + 1];
      strcpy(_str, s._str);
    }
    return *this;
  }

  char &operator[](size_t i)
  {
    return _str[i];
  }

  private:
  char *_str;
  size_t _size;
  size_t _capacity;
};
int main()
{
  String s;
  String s1("string");
  String s2 = s1;
  s = s1;
  s[1] = 'x';
  s.push_back('c');
  printf("%s\n", s.c_str());
  printf("%s\n", s1.c_str());
  printf("%s\n", s2.c_str());
  for (auto c : s)
  {
    printf("%c ", c);
  }

  //printf("%s", s1.c_str());
  system("pause");
  return 0;
}
