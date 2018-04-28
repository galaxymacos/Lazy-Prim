#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <sstream>
using namespace std;

template <class Graph,class Weight>
class ReadGraph
{
public:
	ReadGraph(Graph& graph, const string& filename)
	{
		string line;
		int V, E;
		ifstream file(filename);
		// ifstream file;
		// file.open(filename);

		assert(file.is_open());
		assert(getline(file, line));
		stringstream size_container(line);
		size_container >> V >> E;
		file.get(); // get rid of the whitespace at the end of each line
		assert(graph.V() == V);
		for (int i = 0; i < E; i++)
		{
			string data;
			assert(getline(file, data));
			stringstream dataStream(data);
			int a, b;
			Weight weight;
			dataStream >> a >> b >> weight;
			file.get();	// get rid of the whitespace at the end of each line
			assert(a >= 0 && a < V);
			assert(b >= 0 && b < V);
			graph.addEdge(a, b,weight);
		}
	}
};
