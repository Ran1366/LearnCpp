#ifndef _LISTNODE
#define _LISTNODE
#define  Posi(T) ListNode<T>*
#include "ListNode.h"
template <class T>
struct ListNode
{
	T data;//����
	Posi(T) pred;//ǰ��
	Posi(T) succ;//���

	ListNode() {};//Ĭ�Ϲ��캯��
	ListNode(T e, Posi(T) p = NULL, Posi(T) s = NULL)
		:data(e),pred(p),succ(s) {};

	T getdata();
	Posi(T) getpred();
	Posi(T) getsucc();
	Posi(T) insertAsPred(T const &e);
	Posi(T) insertAsSucc(T const &e);
};
template <class T>
Posi(T) ListNode<T>::getpred()
{
	return pred;
}
template <class T>
Posi(T) ListNode<T>::getsucc()
{
	return succ;
}
template <class T>
T ListNode<T>::getdata()
{
	return data;
}
template <class T>
Posi(T) ListNode<T>::insertAsPred(T const &e)
{
	Posi(T) x = new ListNode(e,pred,this);
	pred->succ = x;
	pred = x;
	return x;
}
template <class T>
Posi(T) ListNode<T>::insertAsSucc(T const &e)
{
	Posi(T) x = new ListNode(e, pred, this);
	succ->pred = x;
	succ = x;
	return x;
}
#endif // _LISTNODE
