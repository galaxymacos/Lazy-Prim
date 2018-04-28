#pragma once

#include <iostream>
#include <vector>
#include <cassert>

#include "MinHeap.h";
#include "Edge.h"

using namespace std;

template <class Graph, class Weight>
class LazyPrimMST
{
	Graph& G;
	MinHeap<Edge<Weight>> heap;
	bool* marked;
	vector<Edge<Weight>> mst;
	Weight mstWeight;

	void visit(int v)
	{
		assert(!marked[v]);
		marked[v] = true;
		// iterate through the edge around it
		typename Graph::adjIterator adj(G, v);
		for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next())
		{
			if (!marked[e->other(v)])
			{
				heap.insert(*e);
			}
		}
	}

public:
	LazyPrimMST(Graph& graph) : G(graph), heap(MinHeap<Edge<Weight>>(graph.E()))
	{
		marked = new bool[G.V()]{false};
		mst.clear();
		visit(0);
		while (!heap.isEmpty())
		{
			Edge<Weight> currentEdge = heap.extractMin();
			if (marked[currentEdge.v()] == marked[currentEdge.w()])
			{
				continue;
			}
			mst.push_back(currentEdge);
			if (!marked[currentEdge.v()])
				visit(currentEdge.v());
			else
				visit(currentEdge.w());
		}

		mstWeight = mst[0].wt();
		for (int i = 1; i < mst.size(); i++)
		{
			mstWeight += mst[i].wt();
		}
	}


	~LazyPrimMST()
	{
		delete[] marked;
	}

	vector<Edge<Weight>> mstEdge()
	{
		return mst;
	}

	Weight result()
	{
		return mstWeight;
	}
};
