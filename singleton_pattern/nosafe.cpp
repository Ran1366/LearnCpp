#include <iostream>
class man
{
  private:
    volatile static man* male;
  public:
    man(){}
    volatile static man* bulid_man() 
    {
      if(male == NULL)
      {
        male = new man();
      }
      return male;
    }
};
int main()
{
  //该方式线程不安全
  return 0;
}
