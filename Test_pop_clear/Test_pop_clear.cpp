#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\User\source\repos\Laba1\Laba1\Errors.h"
#include "C:\Users\User\source\repos\Laba1\Laba1\Class_List.h"
#include <string.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test_pop_clear
{		
	TEST_CLASS(UnitTest1)
	{
	private:
		list<int> list_of_ints;
		list<char> list_of_chars;
		list<bool> list_of_bools;
		int data_int = 7;
		bool data_bool_1 = false, data_bool_2 = true;
		char data_char = 'a';
	public:
		TEST_METHOD(Test_pop_back_head_is_null)
		{
			try
			{
				list_of_ints.pop_back();
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
			catch (Head_is_null error)
			{
				error.what();
			}
		}
		TEST_METHOD(Test_pop_back_all_is_good)
		{
			try
			{
				list_of_chars.push_back(data_char);
				list_of_chars.pop_back();
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
			catch (Head_is_null error)
			{
				error.what();

			}
			Assert::AreEqual(0,list_of_chars.get_size());
		}
		TEST_METHOD(Test_pop_front_head_is_null)
		{
			try
			{
				list_of_bools.pop_front();
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
			catch (Head_is_null error)
			{
				error.what();
			}
		}
		TEST_METHOD(Test_pop_front_all_is_good)
		{
			try
			{
				list_of_bools.push_back(data_bool_1);
				list_of_bools.push_back(data_bool_2);
				list_of_bools.pop_front();
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
			catch (Head_is_null error)
			{
				error.what();
			}
			Assert::AreEqual(true, list_of_bools.at(1));
			Assert::AreEqual(1, list_of_bools.get_size());
		}
		TEST_METHOD(Test_clear_head_is_null)
		{
			try
			{
				list_of_chars.clear();
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
			catch (Head_is_null error)
			{
				error.what();
			}
		}
		TEST_METHOD(Test_clear_all_is_good)
		{
			try
			{
				list_of_bools.push_back(data_bool_1);
				list_of_bools.push_back(data_bool_2);
				list_of_bools.clear();
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
			catch (Head_is_null error)
			{
				error.what();
			}
			Assert::AreEqual(0, list_of_bools.get_size());
		}

	};
}