#ifndef _STACK
#define _STACK
#include "Vector.h"
template<class T>
class Stack : public Vector<T>
{
public:
	void push(T const &e) { insertTrail(e); };//��ջ
	T pop() { return removeTrail(); };//��ջ
	T & top() { return (getElem())[size() - 1]; };//�õ�ջ��Ԫ��
	friend void convert(Stack<char> &s, __int64 n, int base);
};
#endif
