#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <time.h>
using namespace std;
const int SPLIT_TIME_MIN  = 500;//细胞分裂最短时间
const int SPLIT_TIME_MAX = 2000;//细胞分裂最长时间
class Cell;
priority_queue<Cell> cellQueue;
class Cell
{
public:
	Cell(int birth);
	int getId() const;
	int getSplit_time() const;
	bool operator < (const Cell& c) const;
	void split() const;
private:
	static int count;//细胞总数
	int id;//细胞编号
	int split_time;//细胞分裂时间
};
Cell::Cell(int birth)
{
	id = count++;
	split_time = birth + (rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN)) + SPLIT_TIME_MIN;
}
int Cell::getId() const
{
	return id;
}
int Cell::getSplit_time() const
{
	return split_time;
}
bool Cell::operator < (const Cell& c) const
{
	return split_time > c.split_time;
}
void Cell::split() const
{
	Cell c1(split_time),c2(split_time);
	cout << split_time << "s: Cell #" << id << " splits to #"
		<< c1.getId() << " and #" << c2.getId() << endl;
	cellQueue.push(c1);
	cellQueue.push(c2);
}
int Cell::count = 0;
int main()
{
	srand(static_cast<unsigned>(time(0)));
	int watch_time = 0;
	cin >> watch_time;
	cellQueue.push(Cell(0));
	while (cellQueue.top().getSplit_time() < watch_time)
	{
		cellQueue.top().split();
		cellQueue.pop();
	}
	system("pause");
	return 0;
}
