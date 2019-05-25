#pragma once
template <class T>
class list_element
{
public:
	list_element* next;
	T data;
	list_element() {}
	~list_element()
	{
		next = nullptr;
	}
};