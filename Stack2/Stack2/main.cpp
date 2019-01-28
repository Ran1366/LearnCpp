#include <iostream>
#include "Stack.h"
using namespace std;

//�������ת��,��ԭ���Ƕ̳���
void convert(Stack<char> &s, __int64 n, int base)
{
	//�µĽ�����,ÿһλ�ķ���
	static int digit[] = {
		'0','1','2','3','4','5','6','7','8','9','A','B',
		'C','D','E','F'
	};
	while (n > 0)
	{
		s.push(digit[n % base]);//������ջ
		n /= base;//������,����һ�μ���
	}
}
//����ƥ��
bool parenthese(const char p[], int lo, int hi)
{
	Stack<char> s;
	for (int i = lo; i < hi; ++i)
	{
		//���������ž���ջ
		if (p[i] == '(' || p[i] == '[' || p[i] == '{')
		{
			s.push(p[i]);
		}
		else//����������
		{
			if (!s.empty())//��ջ��Ϊ���򵯳�
			{
				s.pop();
			}
			else//��ջ��ǰΪ�������Ų�ƥ��
			{
				return false;
			}
		}
	}
	return s.empty();
}
//�ж��Ƿ�Ϊջ��ϴ
bool Mixed_wash(const int p[], int n)
{
	//Ϊ��ģ��ջ��ϴ��p[]����Ŀ��ջ
	Stack<int> src;//ԭջ
	Stack<int> tem;//��תջ
	for (int i = n; i > 0; --i)//����ԭջ��ջ����ջ��Ϊ1,2,3...n;
	{
		src.push(i);
	}
	int j = 0;//��λĿ��ջ��Ԫ���±�
	while (j < n)
	{
		//Ŀ��ջ��Ԫ�ش���ԭջ��Ԫ����ԭջ�ǿ�
		//��ԭջԪ��������תջ
		while (src.top() <= p[j] && !src.empty())
		{
			tem.push(src.pop());
		}
		//����תջ��Ԫ�ص���Ŀ��ջ
		//ģ�������תջԪ�س�ջ
		if (tem.top() == p[j])
		{
			tem.pop();
		}
		//����,��ζ����תջ��Ԫ�ز�����Ŀ��ջ��ǰ
		//�����Ԫ��,ͬʱԭջ��Ҳû������Ŀ��ջ��ǰ�����
		//Ԫ��,�����ж������в���ջ��ϴ
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
	printf("�����������ת��(173)D->(?)B:\n");
	Stack<char> s;
	convert(s, 173, 2);
	while (!s.empty())
	{
	printf("%c ", s.pop());
	}
	printf("\n\n");
	//***********************************************
	printf("��������ƥ��'{','[','(',')',']','[','(',')',']','}':\n");
	char a[] = {'{','[','(',')',']','[','(',')',']','}'};
	printf("%d\n",(int)parenthese(a,0,sizeof(a)));
	printf("\n\n");
	//***********************************************
	printf("���������Ƿ�Ϊջ��ϴ\n:int p1[] = { 3,4,5,2,1 };");
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

