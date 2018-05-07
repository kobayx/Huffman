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

	void push(Priority priority, Data data);
	item& pop();
	bool is_empty();
private:
	std::vector<item> heap;
};


#endif

template<typename Priority, typename Data>
inline void Heap<Priority, Data>::push(Priority priority, Data data)
{
	item itm(priority, data);
	heap.push_back(itm);
}

template<typename Priority, typename Data>
inline typename Heap<Priority, Data>::item& Heap<Priority, Data>::pop()
{
	if (!heap.empty()) {
		item temp = heap.front();
		heap.front() = heap.back();
		heap.pop_back();
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
