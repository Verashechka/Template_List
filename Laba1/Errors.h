#pragma once

#include <exception>
using namespace std;
class Wrong_index_of_element: public exception
{public:
	Wrong_index_of_element() : exception("The index is wrong!\n")
	{
	}
};
class Head_is_null :public exception
{
public:
	Head_is_null() :exception("The list is not exist!\n")
	{
	}
};