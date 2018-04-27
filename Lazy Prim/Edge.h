#pragma once

#include <iostream>
#include <cassert>
using namespace std;

template <class Weight>
class Edge
{
	int a{}, b{};
	Weight weight{};
public:
	Edge(int a, int b, Weight weight) : a(a), b(b), weight(move(weight))
	{
	}

	Edge() = default;

	~Edge() = default;	// TODO normal destructor will affect the speed, don't know why

	int v() const { return a; }
	int w() const { return b; }
	Weight wt() const { return weight; }

	int other(int x) const
	{
		assert(a == x || b == x);
		return x == a ? b : a;
	}

	friend ostream& operator<<(ostream& os, const Edge<Weight>& e)
	{
		os << e.v() << "-" << e.w() << ": " << e.wt();
		return os;
	}

	bool operator<(const Edge<Weight>& e)
	{
		return wt() < e.wt();
	}

	bool operator<=(const Edge<Weight>& e)
	{
		return wt() <= e.wt();
	}

	bool operator>(const Edge<Weight>& e)
	{
		return wt() > e.wt();
	}

	bool operator>=(const Edge<Weight>& e)
	{
		return wt() >= e.wt();
	}

	bool operator==(const Edge<Weight>& e)
	{
		return wt() == e.wt();
	}
};
