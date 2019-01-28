#include <iostream>
#include "Stack.h"
using namespace std;

//任意进制转换,其原理是短除法
void convert(Stack<char> &s, __int64 n, int base)
{
	//新的进制下,每一位的符号
	static int digit[] = {
		'0','1','2','3','4','5','6','7','8','9','A','B',
		'C','D','E','F'
	};
	while (n > 0)
	{
		s.push(digit[n % base]);//余数入栈
		n /= base;//保留商,做下一次计算
	}
}
//括号匹配
bool parenthese(const char p[], int lo, int hi)
{
	Stack<char> s;
	for (int i = lo; i < hi; ++i)
	{
		//遇到左括号就入栈
		if (p[i] == '(' || p[i] == '[' || p[i] == '{')
		{
			s.push(p[i]);
		}
		else//遇到右括号
		{
			if (!s.empty())//若栈不为空则弹出
			{
				s.pop();
			}
			else//若栈提前为空则括号不匹配
			{
				return false;
			}
		}
	}
	return s.empty();
}
//判断是否为栈混洗
bool Mixed_wash(const int p[], int n)
{
	//为了模拟栈混洗将p[]当做目标栈
	Stack<int> src;//原栈
	Stack<int> tem;//中转栈
	for (int i = n; i > 0; --i)//假设原栈从栈顶到栈底为1,2,3...n;
	{
		src.push(i);
	}
	int j = 0;//定位目标栈的元素下标
	while (j < n)
	{
		//目标栈的元素大于原栈顶元素且原栈非空
		//则将原栈元素推入中转栈
		while (src.top() <= p[j] && !src.empty())
		{
			tem.push(src.pop());
		}
		//当中转栈顶元素等于目标栈
		//模拟的让中转栈元素出栈
		if (tem.top() == p[j])
		{
			tem.pop();
		}
		//否则,意味着中转栈顶元素不满足目标栈当前
		//所需的元素,同时原栈中也没有满足目标栈当前所需的
		//元素,可以判定该序列不是栈混洗
		else
		{
			return false;
		}
		++j;
	}
	return true;
}
int main()
{
	printf("测试任意进制转换(173)D->(?)B:\n");
	Stack<char> s;
	convert(s, 173, 2);
	while (!s.empty())
	{
	printf("%c ", s.pop());
	}
	printf("\n\n");
	//***********************************************
	printf("测试括号匹配'{','[','(',')',']','[','(',')',']','}':\n");
	char a[] = {'{','[','(',')',']','[','(',')',']','}'};
	printf("%d\n",(int)parenthese(a,0,sizeof(a)));
	printf("\n\n");
	//***********************************************
	printf("测试序列是否为栈混洗\n:int p1[] = { 3,4,5,2,1 };");
	printf("\n:int p2[] = { 4,5,3,1,2 };");
	printf("\n:int p3[] = { 4,2,3,5,1 };\n");
	int p1[] = { 3,4,5,2,1 };
	int p2[] = { 4,5,3,1,2 };
	int p3[] = { 4,2,3,5,1 };
	printf("%d\n", Mixed_wash(p1, 5));
	printf("%d\n", Mixed_wash(p2, 5));
	printf("%d\n", Mixed_wash(p3, 5));
	printf("\n");
	//***********************************************
	system("pause");
	return 0;
}

