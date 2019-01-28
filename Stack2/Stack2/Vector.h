
#ifndef _VECTOR
#define _VECTOR
typedef int Rank;
template<class T>
class Vector
{
private:
	Rank _size;//��ģ
	int _capacity;//����
	T* elem;//������
public:
	Vector(int c = 10) { elem = new T[_capacity = c]; _size = 0; };
	~Vector() { delete[]elem; };
	Rank size() { return _size; };//ȡ������Ч���ݳ���
	void insertTrail(T const &e);//������Ԫ��֮������µ�Ԫ��
	T removeTrail();//�Ƴ�������ЧԪ��
	int empty();//�ж������Ƿ�Ϊ��
	T * getElem() { return elem; };//�õ�������
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
