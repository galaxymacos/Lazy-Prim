#include <iostream>
#include "PrimMST.h"
#include "LazyPrimMST.h"
#include "SparseGraph.h"
#include "Edge.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "KruskalMST.h"
using namespace std;
int main(int argc, char* argv[])
{
	const string filename = "testG1.txt";
	int V = 8;

	SparseGraph<double> g{ 8, false };
	ReadGraph<SparseGraph<double>, double> read_graph{ g,filename };
	LazyPrimMST<SparseGraph<double>, double> lazy_prim_mst{ g };
	vector<Edge<double>> mini_tree = lazy_prim_mst.mstEdge();
	for (const auto i : mini_tree)
	{
		cout << i << endl;
	}
	cout << "The MST weight is: " << lazy_prim_mst.result() << endl;

	DenseGraph<double> g2{ V,false };
	ReadGraph<DenseGraph<double>, double> g2_graph{ g2,filename };
	LazyPrimMST<DenseGraph<double>, double> lazyPrimDense{ g2 };
	vector<Edge<double>> g2_tree = lazyPrimDense.mstEdge();
	for (const Edge<double> i : g2_tree)
	{
		cout << i << endl;
	}
	cout << "The MST weight is: " << lazyPrimDense.result() << endl;

	DenseGraph<double> g3{ V,false };
	ReadGraph<DenseGraph<double>, double> read_prim{ g3,filename };
	PrimMST<DenseGraph<double>, double> prim_mst{ g3 };
	vector<Edge<double>> g3_edges = prim_mst.mstEdges();
	for (const Edge<double> i : g3_edges)
	{
		cout << i << endl;
	}
	cout << "The MST weight is: " << prim_mst.result() << endl;

	DenseGraph<double> g4{ V,false };
	ReadGraph<DenseGraph<double>, double> read_to_krusk{ g4,filename };
	KruskalMST<DenseGraph<double>, double> kruskal_mst{ g4 };
	vector<Edge<double>> g4_edges = kruskal_mst.mstEdge();
	for(const Edge<double> i:g4_edges)
	{
		cout << i << endl;
	}
	cout << "The MST weight is: " << kruskal_mst.result() << endl;
	cin.get();
}
