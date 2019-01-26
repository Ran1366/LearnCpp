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
	int uniquify();//�����б�Ψһ��
	//�����б�Ĳ���:��P��n����ǰ�����ҵ�������e�������
	Posi(T) serch(T const &e, int n, Posi(T) p);
	//���б�����ʼ��P������n��Ԫ����ѡ������
	void selectionSort(Posi(T) p, int n);
	//���������ڵ��������
	void swapTwo(Posi(T) p1, Posi(T) p2);
protected:
	//�ҵ���ʼλ��Ϊp��n��Ԫ��������
	Posi(T) selectMax(Posi(T) p, int n);
	
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
template<class T>
int List<T>::uniquify()
{
	if (_size < 2)//����������Ԫ���б��Ȼ���ظ�
	{
		return 0;
	}
	Posi(T) p = header;//��¼���������
	Posi(T) q;//��¼��ǰ�����λ��
	int oldsize = _size;//��¼�б�ԭʼ��ģ
	int r = 1;//��λ��1��ʼ���
	while (trailer != (q = p->succ))
	{
		if (q->data != p->data)
		{
			p = q;
		}
		else
		{
			remove(q);
		}
	}
	return oldsize - _size;
}
template<class T>
Posi(T) List<T>::serch(T const &e, int n, Posi(T) p)
{
	while (n--)
	{
		if (((p = p->pred)->data) <= e)
		{
			break;
		}
	}
	return p;
}
template<class T>
Posi(T) List<T>::selectMax(Posi(T) p, int n)
{
	Posi(T) max = p;
	while (n > 1)
	{
		if (((p = p->succ)->data) >= max->data)
		{
			max = p;
		}
		--n;
	}
	return max;
}
template<class T>
void List<T>::swapTwo(Posi(T) p1, Posi(T) p2)
{
	T cont1;//���ڽ������ݵ�����1
	T cont2;//���ڽ������ݵ�����2
	T temp;//�м����
	cont1 = p1->data;
	cont2 = p2->data;
	temp = cont1;
	cont1 = cont2;
	cont2 = temp;
}
template<class T>
void List<T>::selectionSort(Posi(T) p, int n)
{
	Posi(T) head = p->pred;//����ͷ�ڱ�
	Posi(T) trail = p;
	
	for (int i = 0; i < n; ++i)//����β�ڱ�
	{
		trail = trail->succ;
	}
	while (n > 1)
	{
		swapTwo(selectMax(head, n), trail->pred);
		trail = trail->pred;
		--n;
	}
}
#endif // _LIST
