#ifndef ARR_H
#define ARR_H
#include <cassert>
template <class T>
class Arr
{
public:
	Arr(int sz = 50);
	Arr(const Arr<T> &a); //���ƹ��캯��
	~Arr(); // ��������
	Arr<T> & operator = (const Arr<T> &a);  //����"="
	T & operator [] (int index); //����"[]"
	const T & operator [] (int index) const;  //����"[]��������
	operator T * ();  //���ص�T*���͵�ת��
	operator const T * ()const;
	int GetSize(); //ȡ����Ĵ�С
	void ResetSize(int sz); //�޸�����Ĵ�С
private:
	int size;
	T *arr;
};
//���캯��
template<class T>
Arr<T>::Arr(int sz)
{
	assert(sz >= 0);//��assert()�ڵ������ж�Ϊ��ʱ,�������󾯸沢��ֹ����
	size = sz;
	arr = new T[size];
}
//���ƹ��캯��
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
//��������
template<class T>
Arr<T>::~Arr()
{
	delete[]arr;
}
//����"="
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
//����"[]"
template<class T>
T & Arr<T>::operator[](int index)
{
	assert(index >= 0 && index < size);
	return arr[index];
}
//����"[]��������
template<class T>
const T& Arr<T>::operator [](int index) const
{
	assert(index >= 0 && index < size);
	return arr[index];
}
//���ص�T*���͵�ת��
template<class T>
Arr<T>::operator T *()
{
	return arr;
}
//���ص�T*���͵�ת��
template<class T>
Arr<T>::operator const T *()const
{
	return arr;
}
//��ȡ����Ĵ�С
template<class T>
int Arr<T>::GetSize()
{
	return size;
}
//�޸�����Ĵ�С
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
