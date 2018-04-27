#pragma once
#include <vector>
using namespace std;

template <class Weight>
class SparseGraph
{
	int n, m;
	bool directed;
	vector<vector<Edge<Weight>*>> g;
public:
	SparseGraph(int n, bool directed): n(n), m(0), directed(directed)
	{
		for (int i = 0; i < n; i++)
			g.emplace_back(vector<Edge<Weight>*>());
	}

	~SparseGraph()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < g[i].size(); j++)
			{
				delete g[i][j];
			}
		}
	}

	int V() const { return n; }
	int E() const { return m; }

	void addEdge(int v, int w, Weight weight)
	{
		g[v].push_back(new Edge<Weight>(v, w, weight));
		if (v != w && !directed)
		{
			g[w].push_back(new Edge<Weight>(w, v, weight));
		}
		m++;
	}

	bool hasEdge(int v, int w)
	{
		for (int i = 0; i < g[v].size(); i++)
		{
			if (g[v][i]->other(v) == w)
				return true;
		}
		return false;
	}

	void show()
	{
		for (int i = 0; i < n; i++)
		{
			cout << "vertec " << i << " ";
			for (int j = 0; j < g[i].size(); j++)
				cout << "( to:" << g[i][j]->w() << ",wt:" << g[i][j]->wt() << ") ";
			cout << endl;
		}
	}

	class adjIterator
	{
	public:
		SparseGraph& G;
		int v;
		int index;

		adjIterator(SparseGraph& graph, int v) : G(graph), v(v), index(0)
		{
		}

		Edge<Weight>* begin()
		{
			index = 0;
			if (!G.g[v].empty())
				return G.g[v][index];
			return nullptr;
		}

		Edge<Weight>* next()
		{
			if (++index < int(G.g[v].size()))
				return G.g[v][index];
			return nullptr;
		}

		bool end() const
		{
			return index >= int(G.g[v].size());
		}
	};
};
