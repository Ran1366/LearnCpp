#ifndef _LIST
#define _LIST
#include "ListNode.h"
template<class T>
class List
{
private:
	int _size;//��ģ
	Posi(T) header;//ͷ�ڱ�
	Posi(T) trailer;//β�ڱ�
public:
	~List();//��������
	void init();//��ʼ��
	Posi(T) find(T const &e, int n, Posi(T) p);//����
	Posi(T) insertBefore(Posi(T) p, T const &e);//��p�ڵ�֮ǰ����һ���½ڵ�
	void insertLast(T const &e);//��p�ڵ�֮�����һ���½ڵ�
	void copyNodes(Posi(T) p, int n);//�����б�
	T remove(Posi(T) p);//ɾ���ڵ�
	int clear();//����б�
	int deduplicate();//ɾ���б���ظ�Ԫ��
protected:
};
template<class T>
void List<T>::init()
{
	header = new Posi(T);//����ͷ�ڱ�
	trailer = new Posi(T);//����β�ڱ�
	header->succ = trailer;//����
	trailer->pred = header;//����
	header->pred = NULL;
	trailer->succ = NULL;
	_size = 0;
}
template<class T>
Posi(T) List<T>::find(T const &e, int n, Posi(T) p)
{
	while (n--)
	{
		if (e == (p = p->pred)->data)
		{
			return p;
		}
	}
	return NULL;
}
template<class T>
Posi(T) List<T>::insertBefore(Posi(T) p, T const &e)
{
	++_size;
	return p->insertAsPred(e);
}
template<class T>
void List<T>::insertLast(T const &e)
{
	insertBefore(trailer, e);
}
template<class T>
void List<T>::copyNodes(Posi(T) p, int n)
{
	init();
	while (n--)
	{
		insertLast(p->data);
		p = p->succ;
	}
}
template<class T>
T List<T>::remove(Posi(T) p)
{
	T x = p->data;//���ݽ�Ҫ��ɾ���Ľ�������
	p->pred->succ = p->succ;//p�ڵ㵱ǰ�ĺ�̸���p��ǰ���ĺ��
	p->succ->pred = p->pred;//p�ڵ㵱ǰ��ǰ������p�ĺ�̵�ǰ��
	delete p;
	--_size;
	return x;
}
template<class T>
int List<T>::clear()
{
	int oldsize = _size;
	while (_size--)
	{
		remove(header->succ);
	}
	return oldsize;
}
template<class T>
List<T>::~List()
{
	clear();
	delete header;
	delete trailer;
}
template<class T>
int List<T>::deduplicate()
{
	if (_size < 2)//����������Ԫ���б��Ȼ���ظ�
	{
		return 0;
	}
	Posi(T) p = header;//��ȡ�б��׽ڵ�
	int oldsize = _size;//��¼�б�ԭʼ��ģ
	int r = 1;//��λ��1��ʼ���
	while (trailer != (p = p->succ))
	{
		Posi(T) q = find(p->data, r, p);
		if (q != NULL)
		{
			remove(q);
		}
		else
		{
			++r;
		}
	}
	return oldsize - _size;
}
#endif // _LIST
