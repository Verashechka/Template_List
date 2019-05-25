#pragma once
#include "Class_List_element.h"
template <class T>
class list
{
private:
	list_element<T>*head;
	list_element<T>*tail;
	size_t size_of_list;
public:
	template<class T>	friend ostream& operator<< <T> (ostream&, list<T>&);//comparison operator overloading 
	list();//constructor
	~list(){this->clear();}//destructor
	void push_back(T user_data);// creates new element at the end of list
	void push_front(T user_data);// creates new element at the top of list
	void pop_back();// removes last element of the list
	void pop_front();// removes first element of the list
	void insert(T user_data, size_t index);//inserts new element at user-specified place
	T at(size_t index);//returns data from user-specified element
	void remove(size_t index);//removes element from user-specified place
	size_t get_size();//returns size of list
	void clear();//clears all list
	void set(T user_data, size_t index);//sets user-specified data at user-specified place
	bool is_empty();//returns true if list is empty else returns false
};

template <class T> //constructor
list<T>::list()
{
	head = nullptr; 
	tail = nullptr; 
}

template <class T>// creates new element at the end of list
void list<T>::push_back(T user_data)
{
	list_element<T>* new_element = new list_element<T>;
	new_element->data = user_data;
	if (!head)
		head = new_element;
	else
		tail->next = new_element;
	size_of_list++;
	tail = new_element;
}

template <class T>// creates new element at the top of list
void list<T>::push_front(T user_data)
{
	list_element<T>* new_element = new list_element<T>;
	new_element->data = user_data;
	new_element->next = head;
	head = new_element;
	size_of_list++;
	if (!tail)
		tail = new_element;
}

template <class T>// removes last element of the list
void list<T>::pop_back()
{
	if (!head)
		throw Head_is_null();
	if (!(head->next))
		this->clear();
	else
	{
		list_element<T>* current = head,*temp=tail;
		while (current->next->next)
			current = current->next;
		delete temp;
		current->next = nullptr;
		tail = current;
		size_of_list--;
	}
}

template <class T>// removes first element of the list
void list<T>::pop_front()
{
	if (!head)
		throw Head_is_null();
	size_of_list--;
	list_element<T>* temporary = head;
	if (head == tail)
		tail = nullptr;
	head = head->next;
	delete temporary;
}

template <class T>//inserts new element at user-specified place
void list<T>::insert(T user_data, size_t index)
{
	if (index > (size_of_list+1))
		throw Wrong_index_of_element();
	list_element<T>* new_element = new list_element<T>;
	new_element->data = user_data;
	if (index==1)
		this->push_front(user_data);
	else
		if (index == size_of_list + 1)
			this->push_back(user_data);
		else
		{
			list_element<T>* temporary = head;
			for (size_t i = 0; i < index - 2; ++i)
				temporary = temporary->next;
			size_of_list++;
			new_element->next = temporary->next;
			temporary->next = new_element;
		}
}

template <class T>//returns data from user-specified element
T list<T>::at(size_t index)
{
	if (!head)
		throw Head_is_null();
	if (index > size_of_list)
		throw Wrong_index_of_element();
	list_element<T>* current = head;
	for (size_t i = 0; i < index - 1; ++i)
		current = current->next;
	return current->data;
}

template <class T>//removes element from user-specified place
void list<T>::remove(size_t index)
{
	if (!head)
		throw Head_is_null();
	if (index > size_of_list)
		throw Wrong_index_of_element();
	if (index==1)
		this->pop_front();
	else
		if (index==size_of_list)
			this->pop_back();
		else
		{
			list_element<T>* current = head;
			list_element<T>* temporary = head;
			for (size_t i = 0; i < index - 2; ++i)
				current = current->next;
			temporary = current->next->next;
			delete current->next;
			current->next = temporary;
			size_of_list--;
		}
}

template <class T>//returns size of list
size_t list<T>::get_size()
{
	return size_of_list;
}

template <class T>//clears all list
void list<T>::clear()
{
	if (head)
	{
		while (head)
		{
			list_element<T>* temporary = head;
			head = head->next;
			delete temporary;
		}
		head = nullptr;
		tail = nullptr;
		size_of_list = 0;
	}
	
}

template <class T>//sets user-specified data at user-specified place
void list<T>::set(T user_data, size_t index)
{
	if (!head)
		throw Head_is_null();
	if (index > size_of_list)
		throw Wrong_index_of_element();
	list_element<T>* temporary = head;
	for (size_t i = 0; i < index - 1; ++i)
		temporary = temporary->next;
	temporary->data = user_data;
}

template <class T>
bool list<T>::is_empty()
{
	return(!head);
}

template<class T>//comparison operator overloading 
ostream& operator<< (ostream& output_stream, list<T> &lis)
{
	if (!lis.head)
		cout << "The list is empty\n";
	else 
	{
		int i = 1;
		list_element<T>*current = lis.head;
		cout << "\n\nList:\n";
		while (current)
		{
			cout << i++ << ": " << current->data << "\n";
			current = current->next;
		}
		cout << endl;
	}
	return output_stream;
}