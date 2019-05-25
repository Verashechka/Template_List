#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\User\source\repos\Laba1\Laba1\Errors.h"
#include "C:\Users\User\source\repos\Laba1\Laba1\Class_List.h"
#include <string.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test_at_remove
{		
	TEST_CLASS(Test_at_remove)
	{
		list<string> list_of_strings;
		list<char> list_of_chars;
		string data_string_1 = "Hello", data_string_2 = "Bye";
		char data_char;
		string data_string;
	public:
		// AT TESTS
		TEST_METHOD(at_2_elements_Is_data2_correct)
		{// list has 2 elements, at(2) must return "Bye"
			list_of_strings.push_back(data_string_1);
			list_of_strings.push_back(data_string_2);
			Assert::AreEqual(data_string_2, list_of_strings.at(2));
		}
		TEST_METHOD(at_2_elements_Is_data1_correct)
		{// list has 2 elements, at(1) must return "Hello"
			list_of_strings.push_back(data_string_1);
			list_of_strings.push_back(data_string_2);
			Assert::AreEqual(data_string_1, list_of_strings.at(1));
		}
		TEST_METHOD(at_wrong_index)
		{// list has 1 element, index is wrong, at(...) must catch Wrong_index error
			list_of_chars.push_back('q');
			try
			{
				data_char = list_of_chars.at(2);
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
		}
		TEST_METHOD(at_empty_list)
		{// list is empty, at(...) must catch Head_is_null error
			try
			{
				data_string = list_of_strings.at(1);
			}
			catch (Head_is_null error)
			{
				error.what();
			}
		}
		// REMOVE TESTS
		TEST_METHOD(remove_empty_list)
		{//list is empty, remove(...) must catch Head_is_null error
			try
			{
				list_of_chars.remove(1);
			}
			catch (Head_is_null error)
			{
				error.what();
			}
		}
		TEST_METHOD(remove_wrong_index)
		{//list has 2 elements, index is wrong, remove(...) must catch Wrong_index error
			list_of_strings.push_back(data_string_1);
			list_of_strings.push_back(data_string_2);
			try
			{
				list_of_strings.remove(3);
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
		}
		TEST_METHOD(remove_one_element)
		{//list has 1 element, after remove(1) list must become empty
			list_of_chars.push_back('w');
			list_of_chars.remove(1);
			Assert::AreEqual(true, list_of_chars.is_empty());
		}
		TEST_METHOD(remove_first_element_Is_size_correct)
		{//list has 2 elements, after remove(1) get_size() must return 1
			list_of_strings.push_back(data_string_1);
			list_of_strings.push_back(data_string_2);
			list_of_strings.remove(1);
			Assert::AreEqual(size_t(1), list_of_strings.get_size());
		}
		TEST_METHOD(remove_last_element_Is_size_correct)
		{//list has 3 elements, after remove(3) get_size() must return 2
			list_of_chars.push_back('e');
			list_of_chars.push_back('r');
			list_of_chars.push_back('t');
			list_of_chars.remove(3);
			Assert::AreEqual(size_t(2), list_of_chars.get_size());
		}
		TEST_METHOD(remove_second_from_3_elements_Is_size_correct)
		{//list has 3 elements, after remove(2) get_size() must return 2
			list_of_chars.push_back('a');
			list_of_chars.push_back('s');
			list_of_chars.push_back('d');
			list_of_chars.remove(2);
			Assert::AreEqual(size_t(2), list_of_chars.get_size());
		}
		TEST_METHOD(remove_first_element_Is_data_correct)
		{//list has 2 elements, after remove(1) at(1) must return data_string_2 
			list_of_strings.push_back(data_string_1);
			list_of_strings.push_back(data_string_2);
			list_of_strings.remove(1);
			Assert::AreEqual(data_string_2, list_of_strings.at(1));
		}
		TEST_METHOD(remove_last_element_Is_data_correct)
		{//list has 2 elements, after remove(2) at(1) must return ' '
			list_of_chars.push_back(' ');
			list_of_chars.push_back('z');
			list_of_chars.remove(2);
			Assert::AreEqual(' ', list_of_chars.at(1));
		}
		TEST_METHOD(remove_second_from_3_elements_Is_data1_correct)
		{//list has 3 elements, after remove(2) at(1) must return ' '
			list_of_chars.push_back(' ');
			list_of_chars.push_back('v');
			list_of_chars.push_back('q');
			list_of_chars.remove(2);
			Assert::AreEqual(' ', list_of_chars.at(1));
		}
		TEST_METHOD(remove_second_from_3_elements_Is_data2_correct)
		{//list has 3 elements, after remove(2) at(1) must return 'q'
			list_of_chars.push_back('t');
			list_of_chars.push_back('y');
			list_of_chars.push_back('q');
			list_of_chars.remove(2);
			Assert::AreEqual('q', list_of_chars.at(2));
		}
};
}