#pragma once
#include "Class_List_element.h"
template <class T>
class list
{
private:
	list_element<T>*head;
public:
	template<class T>	friend ostream& operator<< <T> (ostream&, list<T>&);
	list()
	{
		head = nullptr;
	}
	list(T user_data)
	{
		head = new list_element<T>*;
		head->data = user_data;
	}
	~list()
	{
		list_element<T>*temporary;
		while (head)
		{
			temporary = head;
			head = head->next;
			delete temporary;
		}
	}
	void push_back(T user_data)
	{
		list_element<T>* temporary = head;
		list_element<T>* new_element = new list_element<T>;
		new_element->data = user_data;
		if (!temporary)
			head = new_element;
		else
		{
			while (temporary->next != nullptr)
				temporary = temporary->next;
			temporary->next = new_element;
		}
	}
	void push_front(T user_data)
	{
		list_element<T>* new_element = new list_element<T>;
		new_element->data = user_data;
		new_element->next = head;
		head = new_element;
	}
	void pop_back()
	{
		if (!head)
			throw Head_is_null();
		if (!(head->next))
		{
			delete head;
			head = nullptr;
		}
		else
		{
			list_element<T>* temporary = head;
			while (temporary->next->next)
				temporary = temporary->next;
			delete temporary->next;
			temporary->next = nullptr;
		}
	}
	void pop_front()
	{
		if (!head)
			throw Head_is_null();
		list_element<T>* temporary = head;
		head = head->next;
		delete temporary;
	}
	void insert(T user_data, int index)
	{
		if (!head)
			throw Head_is_null();
		if (index <= 0 || index > this->get_size())
			throw Wrong_index_of_element();
		list_element<T>* temporary = head;
		for (int i = 0; i < index - 2; ++i)
			temporary = temporary->next;
		list_element<T>* new_element = new list_element<T>;
		new_element->data = user_data;
		new_element->next = temporary->next;
		temporary->next = new_element;
	}
	T at(int index)
	{
		if (!head)
			throw Head_is_null();
		if (index <= 0 || index > this->get_size())
			throw Wrong_index_of_element();
		list_element<T>* temporary = head;
		for (int i = 0; i < index - 1; ++i)
			temporary = temporary->next;
		return temporary->data;
	}
	void remove(int index)
	{
		if (!head)
			throw Head_is_null();
		if (index <= 0 || index > this->get_size())
			throw Wrong_index_of_element();
		if (!head->next)
			this->pop_front();
		else
		{
			list_element<T>* current = head;
			list_element<T>* temporary = head;
			for (int i = 0; i < index - 2; ++i)
				current = current->next;
			temporary = current->next->next;
			delete current->next;
			current->next = temporary;
		}
	}
	int get_size()
	{
		int size = 0;
		list_element<T>* current = head;
		while (current != nullptr)
		{
			current = current->next;
			++size;
		}
		return size;
	}
	void clear()
	{
		if (!head)
			throw Head_is_null();
		list_element<T>* temporary = head;
		while (temporary != nullptr)
		{
			temporary = head->next;
			delete head;
			head = temporary;
		}
		head = nullptr;
	}
	void set(T user_data, int index)
	{
		if (!head)
			throw Head_is_null();
		if (index<=0||index> this->get_size())
			throw Wrong_index_of_element();
		list_element<T>* temporary = head;
		for (int i = 0; i < index - 1; ++i)
			temporary = temporary->next;
		temporary->data = user_data;
	}
	bool is_empty()
	{
		return(!head);
	}
};
template<class T>
ostream& operator<< (ostream& output_stream, list<T> &lis)
{
	if (!lis.head)
		throw Head_is_null();

	else 
	{
		int i = 1;
		list_element<T>*temporary = lis.head;
		while (temporary)
		{
			cout << i++ << ": " << temporary->data << " \n";
			temporary = temporary->next;
		}
	}

	return output_stream;
}