#include <iostream>
#include <pthread.h>
//懒汉单例模式, 该方式线程安全
pthread_mutex_t lock;
class man
{
  private:
    volatile static man* male;
  public:
    man(){}
    volatile static man* bulid_man() 
    {
      //执行前加锁
      if(male == NULL)
      {
        //两次判断
        pthread_mutex_lock(&lock); 
        if(male == NULL)
        {
          //male = new man();
          //在执行male = new T()时，可能 类man还没有初始化完成，male就已经有值了。
          //这样会导致另外一个调用bulid_man()方法的线程，获取到还未初始化完成的male指针，
          //如果去使用它，会有意料不到的后果。其实，解决方法也很简单，用一个局部变量过渡下即可
          
          man *temp = new man();
          male = temp;
        }
      }
      //返回前解锁
      pthread_mutex_unlock(&lock); 
      return male;
    }
};
int main()
{
  pthread_mutex_init(&lock, NULL);
  return 0;
}
