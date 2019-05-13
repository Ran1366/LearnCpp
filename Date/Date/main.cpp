#include <iostream>;
#include "date.h";
using std::cout;
using std::endl;

int main()
{
	Date today(2019, 5, 13);
	Date longlongAgo(1910, 3, 4);
	Date future(3125, 6, 1);
	cout << future - today << endl;
	future -= future - today;
	future.Print();
	system("pause");
	return 0;
}