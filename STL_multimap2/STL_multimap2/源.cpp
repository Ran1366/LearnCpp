#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	//��дһ�����򣬴Ӽ�������һ�������ʣ�
	//ÿ���յ�һ�����ʺ�����õ����������ֹ��Ĵ�����
	//���յ���QUIT�����ʺ����ֱ���˳�
	string word;
	map<string, int> countWord;
	do 
	{
		cin >> word;
		if (word != "QUIT")
		{
			countWord[word]++;
		}
		
	} while (word != "QUIT");
	map<string, int>::iterator iter;
	for (iter = countWord.begin(); iter != countWord.end(); ++iter)
	{
		cout << iter->first << "����" << iter->second << "��"<<endl;
	}
	system("pause");
	return 0;
}