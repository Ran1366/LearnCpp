
#ifndef _VECTOR
#define _VECTOR
typedef int Rank;
template<class T>
class Vector
{
private:
	Rank _size;//规模
	int _capacity;//容量
	T* elem;//数据区
public:
	Vector(int c = 10) { elem = new T[_capacity = c]; _size = 0; };
	~Vector() { delete[]elem; };
	Rank size() { return _size; };//取向量有效数据长度
	void insertTrail(T const &e);//在最后的元素之后插入新的元素
	T removeTrail();//移除最后的有效元素
	int empty();//判断向量是否为空
	T * getElem() { return elem; };//得到数据区
};
template<class T>
void Vector<T>::insertTrail(T const &e)
{
	elem[size()] = e;
	++_size;
}
template<class T>
T Vector<T>::removeTrail()
{
	if (size())
	{
		T e = elem[size() - 1];
		elem[size() - 1] = NULL;
		--_size;
		return e;
	}
	return NULL;
}
template<class T>
int Vector<T>::empty()
{
	if (elem[0] == NULL)
	{
		return 1;
	}
	return 0;
}
#endif // _VECTOR
