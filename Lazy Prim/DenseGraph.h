#pragma once
#include <vector>
#include <cassert>
#include <iostream>
#include "Edge.h"
using namespace std;

template <class Weight>
class DenseGraph
{
	int n, m;
	bool directed;
	vector<vector<Edge<Weight>*>> g;

public:
	DenseGraph(int n, bool directed): n(n), m(0), directed(directed)
	{
		for (int i = 0; i < n; i++)
		{
			g.emplace_back(vector<Edge<Weight>*>(n, nullptr));
		}
	}

	~DenseGraph()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (!(g[i][j]==nullptr))
					delete g[i][j];
			}
		}
	}

	int V() const { return n; }
	int E() const { return m; }

	void addEdge(int v, int w, Weight weight)
	{
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		if (hasEdge(v, w))
		{
			delete g[v][w];
			if (!directed)
				delete g[w][v];
			m--;
		}
		g[v][w] = new Edge<Weight>(v, w, weight);
		if (!directed)
			g[w][v] = new Edge<Weight>(w, v, weight);
		m++;
	}

	bool hasEdge(int v, int w)
	{
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		return g[v][w]!=nullptr;
	}

	void show()
	{
		for (vector<Edge<Weight>*> i : g)
		{
			for (Edge<Weight>* j : i)
			{
				if (j != nullptr)
					cout << j->wt() << " " ;
				else
					cout << "NULL" << " " ;
			}
			cout << endl;
		}
	}

	class adjIterator
	{
	public:
		DenseGraph& G;
		int v;
		int index;

		adjIterator(DenseGraph& graph, int v): G(graph), v(v), index(0)
		{
		}

		Edge<Weight>* begin()
		{
			index = -1;
			if (G.g[v].empty())
				return nullptr;
			return next();
		}

		Edge<Weight>* next()
		{
			for (++index; index < G.V(); index++)
			{
				if (G.g[v][index])
				{
					return G.g[v][index];
				}
			}
			return nullptr;
		}

		bool end() const
		{
			return index >= int(G.g[v].size());
		}
	};
};
