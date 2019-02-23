#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <deque>
#include <list>
using namespace std;
//����
template<class T, class InputIterator,class OutputIterator>
void Mysort(InputIterator fist, InputIterator last, OutputIterator result)
{
	vector<T> s;
	for (;fist != last; ++fist)
	{
		s.push_back(*fist);
	}
	sort(s.begin(), s.end());
	copy(s.begin(), s.end(), result);
}
//��ӡ��������
template<class T>
void PrintCotainer(const char* dsc, const T& s)
{
	cout << dsc << ":";
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " ")); 
	cout << endl;
}
//������������������
template<class T>
void Exchange(T& s)
{
	list<int>::iterator iter = s.begin();
	while (iter != s.end())
	{
		int temp = *iter;
		iter = s.erase(iter);//����iterָ����Ǹ�Ԫ�ص�ֵ,����ָ����һ��Ԫ�صĵ�����
		s.insert(++iter,temp);//�ڵ�����ָ��ĵط�����ֵ,��λ�ü��Ժ��Ԫ������ƶ�һ����λ
	}
}
//��ż����
template<class T>
void paritySort(T &s)
{
	sort(s.begin(), s.end());
	deque<int> s2;
	for (vector<int>::iterator iter = s.begin(); iter != s.end(); ++iter)
	{
		if (*iter % 2 == 0)
		{
			s2.push_back(*iter);
		}
		else
		{
			s2.push_front(*iter);
		}
	}
	s.assign(s2.begin(), s2.end());
}
int main()
{
	vector<int> s;
	s.clear();
	int cap = s.capacity();
	cout << cap << endl;
	s.reserve(10);
	int cap2 = s.capacity();
	cout << cap2 << endl;

	//istream_iterator<int> x1(cin), x2;//x1�ӱ�׼�����豸����,x2��ʾ�������λ��
	//vector<int> s(x1, x2);//ͨ���������������ӱ�׼����������������
	//paritySort(s);
	//PrintCotainer("vector at fist", s);


	/*deque<int> s;
	for (int i = 0; i < 4; ++i)
	{
		int x = 0;
		cin >> x;
		s.push_front(x);
	}
	PrintCotainer("deque at fist", s);
	list<int> ls(s.rbegin(),s.rend());
	PrintCotainer("list at fist", ls);
	Exchange(ls);
	PrintCotainer("list at fist", ls);
	s.assign(ls.begin(), ls.end());
	PrintCotainer("deque at fist", ls);*/


	//double a[6] = { 1.2, 2.7, 3.8, 4.9, 5.3, 6.1 };
	//Mysort<double>(a, a + 6, ostream_iterator<double>(cout, "\t"));
	//cout << endl;
	////���δӼ��̵õ�����,�����ӱ�׼��������
	//Mysort<int>(
	//	istream_iterator<int>(cin), istream_iterator<int>(),
	//	ostream_iterator<int>(cout, "\t")
	//	);

	
	



	system("pause");
	return 0;
}