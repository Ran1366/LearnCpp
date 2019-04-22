#include <iostream>
#include <string>
using namespace std;
class Arrays
{
public:
	Arrays(int x) :pArr(new int[x]), size(x) { cout << "����..." << endl; };//���캯��
	Arrays(const Arrays &x) :pArr(new int(x.size)),size(x.size){ cout << "���ƹ���..." << endl; };//���ƹ��캯��
	~Arrays() 
	{
		delete []pArr;
		cout << "����" << endl;
	};
	void SetElements(int *elem);
	int SumOfMaxSub();
private:
	int *pArr;
	int size;
};
int Arrays::SumOfMaxSub()
{
	int sum = 0;
	int i = 0;
	int max = -9999;
	while (i < size)
	{
		if (*(pArr + i) >= 0)
		{
			sum += *(pArr + i);
			++i;
		}
		if (*(pArr + i) < 0)
		{
			if (*(pArr + i) > max)
			{
				max = *pArr;
				++i;
			}
		}
	}
	if (sum == 0)
	{
		return max;
	}
	else
	{
		return sum;
	}
}
void Arrays::SetElements(int *elem)
{
	for (int i = 0; i < size; ++i)
	{
		*(pArr + i) = elem[i];
	}
}
void SetArr()
{
	cout << "��������Ҫ���ɵ�����ĳ���" << endl;
	int size;
	cin >> size;
	if (size >=1)
	{
		Arrays arr(size);
		int *elem = new int[size];
		cout << "���������������ÿ��Ԫ��[-5000~5000]" << endl;
		for (int i = 0 ; i < size ; ++i)
		{
			cin >> *(elem + i);
		}
		arr.SetElements(elem);
		cout << "����Ӵ���:" << arr.SumOfMaxSub() << endl;
	}
}
int main()
{
	//����һ������a[0, ..., n - 1], �������������(���� >= 1)��
	//��һ��һ������n(1<=n<=5000)��Ȼ����������n��������ÿ��������Χ[-5000, 5000]��
	//���һ��������ʾ����������
	//new ������T����ʼ�������б�
	//���ܣ��ڳ���ִ���ڼ䣬�������ڴ��T���Ͷ�����ڴ�ռ䣬������ֵ�б��Գ�ֵ
	//delete ָ��p
	//���ܣ��ͷ�ָ��p��ָ����ڴ档p������new�����ķ���ֵ
	//���䣺new ������T [ ���鳤�� ]
	//���鳤�ȿ������κα��ʽ��������ʱ����
	//�ͷţ�delete[] ������p
	//�ͷ�ָ��p��ָ������顣
	//p��������new����õ��������׵�ַ��
	SetArr();
	system("pause");
	return 0;
}