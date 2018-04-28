#pragma once
#include <vector>
#include "Edge.h"
#include "MinHeap.h"
#include "UnionFind4.h"
using namespace std;

template <class Graph, class Weight>
class KruskalMST
{
	vector<Edge<Weight>> mst; // store edges
	Weight mstWeight; // store minimum distance

public:
	KruskalMST(Graph& graph)
	{
		MinHeap<Edge<Weight>> heap(graph.E()); // store edges
		for (int i = 0; i < graph.V(); i++)
		{
			typename Graph::adjIterator adj(graph, i);
			for (Edge<Weight>* e = adj.begin(); !adj.end(); e = adj.next())
			{
				if (e->v() < e->w())
					heap.insert(*e);
			}
		}

		const union_find re_checker{ graph.V() };
		while(!heap.isEmpty()&&mst.size()<graph.V()-1)
		{
			Edge<Weight> currentEdge = heap.extractMin();
			if (!re_checker.is_connected(currentEdge.v(), currentEdge.w()))
			{
				mst.push_back(currentEdge);
				re_checker.union_elements(currentEdge.v(), currentEdge.w());
			}
		}
		mstWeight = mst[0].wt();
		for(int i = 1;i<mst.size();i++)
		{
			mstWeight += mst[i].wt();
		}
		
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
