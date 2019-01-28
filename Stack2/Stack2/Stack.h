#ifndef _STACK
#define _STACK
#include "Vector.h"
template<class T>
class Stack : public Vector<T>
{
public:
	void push(T const &e) { insertTrail(e); };//入栈
	T pop() { return removeTrail(); };//出栈
	T & top() { return (getElem())[size() - 1]; };//得到栈顶元素
	friend void convert(Stack<char> &s, __int64 n, int base);
};
#endif
