#ifndef HEAPH_H
#define HEAPH_H
#include <vector>
#include <iostream>


template <typename Priority, typename Data>
class Heap {
public:
	class item {
	public:
		item(Priority priority, Data data) : data_(data), priority_(priority) {}
		Data & data() { return data_; }
		Priority& priority() { return priority_; }
	private:
		Data data_;
		Priority priority_;
	};
	
	void sortDown(int a);
	void sortUp(int a);
	void push(Priority priority, Data data);
	item& pop();
	bool is_empty();
private:
	std::vector<item> heap;
};




template<typename Priority, typename Data>
inline void Heap<Priority, Data>::sortDown(int a)
{
	// a*2 is right child, a*2-1 is left child
	if(heap[a*2] && heap[a*2-1])
	{
		if(heap[a*2].priority() > heap[a*2-1].priority())
		{
			if(heap[(a-1)].priority() > heap[(a*2)-1].priority())
			{
				swap(heap[a-1],heap[(a*2)-1]);
				sortDown(a*2);
				return;
			}
		} else if(heap[a-1].priority() > heap[a*2].priority())
		{
				swap(heap[a-1],heap[a*2]);
				sortDown(a*2+1);
				return;
		}
	}
	if(!heap[a*2-1] && heap[a*2-1].priority() < heap[a-1].priority()){
		swap(heap[a-1],heap[(a*2)-1]);
		sortDown(a*2);
		return;
	}
	return;
}

template<typename Priority, typename Data>
inline void Heap<Priority, Data>::sortUp(int a)
{
	if(heap[(a-1)/2])
		return;
	if(heap[(a-1)/2].priority() > heap[a-1].priority()){
		swap(heap[(a-1)/2], heap[a-1]);
		sortUp((a-1)/2);
	}
	return;
}

// Add sorting
template<typename Priority, typename Data>
inline void Heap<Priority, Data>::push(Priority priority, Data data)
{
	item itm(priority, data);
	heap.push_back(itm);
	sortUp(1);
}


template<typename Priority, typename Data>
inline typename Heap<Priority, Data>::item& Heap<Priority, Data>::pop()
{
	if (!heap.empty()) {
		item temp = heap.front();
		heap.front() = heap.back();
		heap.pop_back();
		sortDown(1);
		return temp;
	}
	std::cerr << "No items in heap" << std::endl;
}

template<typename Priority, typename Data>
inline bool Heap<Priority, Data>::is_empty()
{
	if (heap.empty())
		return true;
	return false;
}



#endif
