#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <deque>
#include <list>
using namespace std;
//排序
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
//打印容器内容
template<class T>
void PrintCotainer(const char* dsc, const T& s)
{
	cout << dsc << ":";
	copy(s.begin(), s.end(), ostream_iterator<int>(cout, " ")); 
	cout << endl;
}
//将容器内容两两交换
template<class T>
void Exchange(T& s)
{
	list<int>::iterator iter = s.begin();
	while (iter != s.end())
	{
		int temp = *iter;
		iter = s.erase(iter);//擦除iter指向的那个元素的值,返回指向下一个元素的迭代器
		s.insert(++iter,temp);//在迭代器指向的地方插入值,其位置及以后的元素向后移动一个单位
	}
}
//奇偶排序
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

	//istream_iterator<int> x1(cin), x2;//x1从标准输入设备输入,x2表示输入结束位置
	//vector<int> s(x1, x2);//通过输入流迭代器从标准输入流中输入数据
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
	////依次从键盘得到数据,排序后从标准输出流输出
	//Mysort<int>(
	//	istream_iterator<int>(cin), istream_iterator<int>(),
	//	ostream_iterator<int>(cout, "\t")
	//	);

	
	



	system("pause");
	return 0;
}