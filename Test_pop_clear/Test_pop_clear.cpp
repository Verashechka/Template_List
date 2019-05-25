#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\User\source\repos\Laba1\Laba1\Errors.h"
#include "C:\Users\User\source\repos\Laba1\Laba1\Class_List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test_pop_clear
{		
	TEST_CLASS(Test_pop_clear)
	{
	private:
		list<int> list_of_ints;
		list<char> list_of_chars;
	public:
		// POP_BACK TESTS
		TEST_METHOD(pop_back_empty_list)
		{//list is empty, pop_back() must catch Head_is_null error
			try
			{
				list_of_ints.pop_back();
			}
			catch (Head_is_null error)
			{
				error.what();
			}
		}
		TEST_METHOD(pop_back_1_element)
		{//list has 1 element, after pop_back() is_empty() must return true
			list_of_ints.push_back(1);
			list_of_ints.pop_back();
			Assert::AreEqual(true, list_of_ints.is_empty());
		}
		TEST_METHOD(pop_back_3_elements_Is_size_correct)
		{//list has 3 elements, after pop_back() get_size() must return 2
			list_of_ints.push_back(1);
			list_of_ints.push_back(2);
			list_of_ints.push_back(3);
			list_of_ints.pop_back();
			Assert::AreEqual(size_t(2), list_of_ints.get_size());
		}
		TEST_METHOD(pop_back_4_elements_Is_data_of_last_correct)
		{//list has 4 elements, after pop_back() at(2) must return 'w'
			list_of_chars.push_back('q');
			list_of_chars.push_back('a');
			list_of_chars.push_back('w');
			list_of_chars.push_back('e');
			list_of_chars.pop_back();
			Assert::AreEqual('w', list_of_chars.at(3));
		}
		// POP_FRONT TESTS
		TEST_METHOD(pop_front_empty_list)
		{//list is empty, pop_front() must catch Head_is_null error
			try
			{
				list_of_ints.pop_front();
			}
			catch (Head_is_null error)
			{
				error.what();
			}
		}
		TEST_METHOD(pop_front_1_element)
		{//list has 1 element, after pop_front() is_empty() must return true
			list_of_ints.push_front(1);
			list_of_ints.pop_front();
			Assert::AreEqual(true, list_of_ints.is_empty());
		}
		TEST_METHOD(pop_front_3_elements_Is_size_correct)
		{//list has 3 elements, after pop_front() get_size() must return 2
			list_of_ints.push_back(1);
			list_of_ints.push_back(2);
			list_of_ints.push_back(3);
			list_of_ints.pop_front();
			Assert::AreEqual(size_t(2), list_of_ints.get_size());
		}
		TEST_METHOD(pop_front_4_elements_Is_data_of_first_correct)
		{//list has 4 elements, after pop_front() at(2) must return 't'
			list_of_chars.push_back('r');
			list_of_chars.push_back('t');
			list_of_chars.push_back('q');
			list_of_chars.push_back('y');
			list_of_chars.pop_front();
			Assert::AreEqual('t', list_of_chars.at(1));
		}
		// CLEAR TESTS
		TEST_METHOD(clear_3_elements_Is_empty_after)
		{//list has 3 elements, after clear() is_empty() must return true
			list_of_ints.push_back(1);
			list_of_ints.push_back(2);
			list_of_ints.push_back(3);
			list_of_ints.clear();
			Assert::AreEqual(true, list_of_ints.is_empty());
		}
		TEST_METHOD(clear_3_elements_Is_size_0_after)
		{//list has 3 elements, after clear() get_size() must return 0
			list_of_chars.push_back('a');
			list_of_chars.push_back('1');
			list_of_chars.push_back(' ');
			list_of_chars.clear();
			Assert::AreEqual(size_t(0), list_of_chars.get_size());
		}
	};
}