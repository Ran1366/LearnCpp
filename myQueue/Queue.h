#pragma once
#include <queue>
#include <iostream>

template<class T, class Container = std::deque<int>>
class Queue
{
public:
	void Push(const T& x)
	{
		_con.push_back(x);
	}

	void Pop()
	{
		_con.pop_front();
	}

	size_t Size()
	{
		_con.size();
	}

	bool Empty()
	{
		return _con.empty();
	}

	const T& Front()
	{
		return _con.front();
	}

	const T& Back()
	{
		return _con.back();
	}
private:
	Container _con;
};

