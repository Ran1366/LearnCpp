#ifndef _LIST
#define _LIST
#include "ListNode.h"
template<class T>
class List
{
private:
	int _size;//规模
	Posi(T) header;//头哨兵
	Posi(T) trailer;//尾哨兵
public:
	~List();//析构函数
	void init();//初始化
	Posi(T) find(T const &e, int n, Posi(T) p);//查找
	Posi(T) insertBefore(Posi(T) p, T const &e);//在p节点之前插入一个新节点
	void insertLast(T const &e);//在p节点之后插入一个新节点
	void copyNodes(Posi(T) p, int n);//复制列表
	T remove(Posi(T) p);//删除节点
	int clear();//清空列表
	int deduplicate();//删除列表的重复元素
	int uniquify();//有序列表唯一化
	//有序列表的查找:在P的n个真前驱中找到不大于e的最后者
	Posi(T) serch(T const &e, int n, Posi(T) p);
	//对列表中起始于P的连续n个元素做选择排序
	void selectionSort(Posi(T) p, int n);
	//交换两个节点的数据域
	void swapTwo(Posi(T) p1, Posi(T) p2);
protected:
	//找到起始位置为p的n个元素中最大的
	Posi(T) selectMax(Posi(T) p, int n);
	
};
template<class T>
void List<T>::init()
{
	header = new Posi(T);//创建头哨兵
	trailer = new Posi(T);//创建尾哨兵
	header->succ = trailer;//链接
	trailer->pred = header;//链接
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
	T x = p->data;//备份将要被删除的结点的数据
	p->pred->succ = p->succ;//p节点当前的后继赋给p的前驱的后继
	p->succ->pred = p->pred;//p节点当前的前驱赋给p的后继的前驱
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
	if (_size < 2)//不超过两个元素列表必然无重复
	{
		return 0;
	}
	Posi(T) p = header;//获取列表首节点
	int oldsize = _size;//记录列表原始规模
	int r = 1;//从位置1开始检查
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
	if (_size < 2)//不超过两个元素列表必然无重复
	{
		return 0;
	}
	Posi(T) p = header;//记录各区段起点
	Posi(T) q;//记录当前起点后继位置
	int oldsize = _size;//记录列表原始规模
	int r = 1;//从位置1开始检查
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
	T cont1;//用于交换数据的容器1
	T cont2;//用于交换数据的容器2
	T temp;//中间变量
	cont1 = p1->data;
	cont2 = p2->data;
	temp = cont1;
	cont1 = cont2;
	cont2 = temp;
}
template<class T>
void List<T>::selectionSort(Posi(T) p, int n)
{
	Posi(T) head = p->pred;//设置头哨兵
	Posi(T) trail = p;
	
	for (int i = 0; i < n; ++i)//设置尾哨兵
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
