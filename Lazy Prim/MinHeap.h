#pragma once
#include <cassert>
#include <iostream>
using namespace std;
template <class Item>
class MinHeap
{
	Item* data;
	int count;
	int capacity;


	void shift_down(int k)
	{
		assert(k >= 0 && k <= count+1);
		Item unsorted_element = data[k];
		while (2 * k <= count)
		{
			int j = 2 * k;	
			if (j + 1 < count && data[j + 1] < data[j])
				j++;
			if (unsorted_element <= data[j])
				break;
			data[k] = data[j];
			k = j;
		}
		data[k] = unsorted_element;
	}

	void shift_up(int k)
	{
		assert(k >= 0 && k <= count);
		Item unsorted_element = data[k];
		while (k > 1 && data[k / 2] > unsorted_element)
		{
			data[k] = data[k / 2];
			k /= 2;
		}
		data[k] = unsorted_element;
	}

public:
	MinHeap(int capacity) : count(0), capacity(capacity)
	{
		data = new Item[capacity + 1];
	}

	MinHeap(const Item arr[], int count):count(count)
	{
		capacity = count + 1;
		data = new Item[count + 1];
		for (int i = 0; i < count; i++)
		{
			data[i + 1] = arr[i];
		}
		for (int i = count / 2; i >= 1; i--)
		{
			shift_down(i);
		}
	}

	~MinHeap()
	{
		delete data;
	}

	int size() const
	{
		return count;
	}

	bool isEmpty() const
	{
		return count == 0;
	}

	void insert(Item newItem)
	{
		assert(count + 1 <= capacity);
		data[++count] = newItem;
		shift_up(count);
	}

	Item extractMin()
	{
		assert(count > 0);
		Item min_item = data[1];
		swap(data[1], data[count]);
		// count-- must be ahead of shift_down(1)
		count--;
		shift_down(1);
		return min_item;
	}


};
