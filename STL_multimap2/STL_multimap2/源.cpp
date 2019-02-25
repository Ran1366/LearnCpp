#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
	//编写一个程序，从键盘输入一个个单词，
	//每接收到一个单词后，输出该单词曾经出现过的次数，
	//接收到“QUIT”单词后程序直接退出
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
		cout << iter->first << "出现" << iter->second << "次"<<endl;
	}
	system("pause");
	return 0;
}