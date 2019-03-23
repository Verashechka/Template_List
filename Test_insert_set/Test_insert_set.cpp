#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\User\source\repos\Laba1\Laba1\Errors.h"
#include "C:\Users\User\source\repos\Laba1\Laba1\Class_List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test_insert_set
{		
	TEST_CLASS(Test_insert_set)
	{
	private:
		list<int> list_of_ints;
		list<char> list_of_chars;
		list<bool> list_of_bools;
		int data_int = 7;
		bool data_bool = false; 
		char data_char = 'a';
	public:
		TEST_METHOD(Test_insert_int)
		{
			int index_int = 1;
			try
			{
				list_of_ints.insert(data_int, index_int);
			}
			catch (Head_is_null error)
			{
				error.what();
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
		}
		TEST_METHOD(Test_insert_char)
		{
			int index_char = -1;
			list_of_chars.push_back(data_char);
			try
			{
				list_of_chars.insert(data_char, index_char);
			}
			catch (Head_is_null error)
			{
				error.what();
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
		}
		TEST_METHOD(Test_insert_bool)
		{
			int index_bool = 1;
			list_of_bools.push_back(data_bool);
			try
			{
				list_of_bools.insert(data_bool, index_bool);
			}
			catch (Head_is_null error)
			{
				error.what();
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
		}
		TEST_METHOD(Test_set_int)
		{
			int index_int = 1;
			try
			{
				list_of_ints.set(data_int, index_int);
			}
			catch (Head_is_null error)
			{
				error.what();
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
		}
		TEST_METHOD(Test_set_char)
		{
			int index_char = -1;
			list_of_chars.push_back(data_char);
			try
			{
				list_of_chars.set(data_char, index_char);
			}
			catch (Head_is_null error)
			{
				error.what();
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
		}
		TEST_METHOD(Test_set_bool)
		{
			int index_bool = 1;
			list_of_bools.push_back(data_bool);
			try
			{
				list_of_bools.set(data_bool, index_bool);
			}
			catch (Head_is_null error)
			{
				error.what();
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
		}
	};
}