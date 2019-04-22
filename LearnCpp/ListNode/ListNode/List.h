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
protected:
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
#endif // _LIST
