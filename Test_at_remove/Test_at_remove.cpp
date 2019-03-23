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
		char data_char_1 = ' ', data_char_2 = '!', data_char_3 = 'q';
		string at_1, at_2;
		int size_of_chars;
		char at_char_1, at_char_2;
	public:
		
		TEST_METHOD(Test_at_all_good)
		{
			list_of_strings.push_back(data_string_1);
			list_of_strings.push_back(data_string_2);
			
			at_1 = list_of_strings.at(1);
			Assert::AreEqual(data_string_1, at_1);
			at_2 = list_of_strings.at(2);
			Assert::AreEqual(data_string_2, at_2);
		}
		TEST_METHOD(Test_at_wrong_index)
		{
			list_of_strings.push_back(data_string_1);
			try
			{
				at_2 = list_of_strings.at(2);
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
		TEST_METHOD(Test_at_head_is_null)
		{
			try
			{
				at_1 = list_of_strings.at(1);
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
		TEST_METHOD(Test_remove_head_is_null)
		{
			try
			{
				list_of_chars.remove(1);
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
		TEST_METHOD(Test_remove_wrong_index)
		{
			list_of_chars.push_back(data_char_1);
			try
			{
				list_of_chars.remove(3);
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
		TEST_METHOD(Test_remove_all_is_good)
		{
			list_of_chars.push_back(data_char_1);
			list_of_chars.push_back(data_char_2);
			list_of_chars.push_back(data_char_3);
			try
			{
				list_of_chars.remove(2);
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
			catch (Head_is_null error)
			{
				error.what();
			}
			Assert::AreEqual(2, list_of_chars.get_size());
			Assert::AreEqual(data_char_1, list_of_chars.at(1));
			Assert::AreEqual(data_char_3, list_of_chars.at(2));
		}
	};
}