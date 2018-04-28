#pragma once

#include <cassert>

using namespace std;

class union_find
{
	int count_;
	int* parent_;
	int* rank_;
public:
	explicit union_find(const int count) : count_(count)
	{
		parent_ = new int[count];
		rank_ = new int[count];
		for (auto i = 0; i < count; i++)
		{
			parent_[i] = i; // self points to itself
			rank_[i] = 1;
		}
	}

	~union_find()
	{
		delete[] parent_;
		delete[] rank_;
	}

	int find(int p) const
	{
		assert(p >= 0 && p < count_);

		while (p != parent_[p])
		{
			parent_[p] = parent_[parent_[p]];
			p = parent_[p];
		}
		return p;
	}

	bool is_connected(const int p, const int q) const
	{
		return find(p) == find(q);
	}

	void union_elements(int p, int q) const
	{
		const auto p_root = find(p);
		const auto q_root = find(q);
		if (p_root == q_root)
		{
			return;
		}
		if (rank_[p_root] < rank_[q_root])
		{
			parent_[p_root] = q_root; // no need to maintain rank_ array, because rank_[q_root]>=rank_[p_root]+1
		}
		else if (rank_[q_root] < rank_[p_root])
		{
			parent_[q_root] = p_root;
		}
		else
		{
			parent_[p_root] = q_root;
			rank_[q_root]++;
		}
	}
};
