#ifndef ARR_H
#define ARR_H
#include <cassert>
template <class T>
class Arr
{
public:
	Arr(int sz = 50);
	Arr(const Arr<T> &a); //复制构造函数
	~Arr(); // 析构函数
	Arr<T> & operator = (const Arr<T> &a);  //重载"="
	T & operator [] (int index); //重载"[]"
	const T & operator [] (int index) const;  //重载"[]”常函数
	operator T * ();  //重载到T*类型的转换
	operator const T * ()const;
	int GetSize(); //取数组的大小
	void ResetSize(int sz); //修改数组的大小
private:
	int size;
	T *arr;
};
//构造函数
template<class T>
Arr<T>::Arr(int sz)
{
	assert(sz >= 0);//当assert()内的条件判断为假时,发出错误警告并终止程序
	size = sz;
	arr = new T[size];
}
//复制构造函数
template<class T>
Arr<T>::Arr(const Arr<T> &a)
{
	size = a.size;
	arr = new T[size];
	for (int i = 0; i < size; ++i)
	{
		arr[i] = a.arr[i];
	}
}
//析构函数
template<class T>
Arr<T>::~Arr()
{
	delete[]arr;
}
//重载"="
template<class T>
Arr<T> & Arr<T>::operator=(const Arr &a)
{
	if (a != this)
	{
		if (size != a.size)
		{
			size = a.size;
			arr = new T[size];
		}
		for (int i = 0; i < size; ++i)
		{
			arr[i] = a.arr[i];
		}
	}
	return *this;
}
//重载"[]"
template<class T>
T & Arr<T>::operator[](int index)
{
	assert(index >= 0 && index < size);
	return arr[index];
}
//重载"[]”常函数
template<class T>
const T& Arr<T>::operator [](int index) const
{
	assert(index >= 0 && index < size);
	return arr[index];
}
//重载到T*类型的转换
template<class T>
Arr<T>::operator T *()
{
	return arr;
}
//重载到T*类型的转换
template<class T>
Arr<T>::operator const T *()const
{
	return arr;
}
//获取数组的大小
template<class T>
int Arr<T>::GetSize()
{
	return size;
}
//修改数组的大小
template<class T>
void Arr<T>::ResetSize(int sz)
{
	assert(sz >= 0);
	T *a = new T[sz];
	if (size != sz)
	{
		int n = (size < sz) ? size : sz;
		for (int i = 0; i < n; ++i)
		{
			a[i] = arr[i];
		}
		delete[]arr;
		arr = a;
		size = sz;
	}
}
#endif // ARR_H
