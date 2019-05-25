#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\User\source\repos\Laba1\Laba1\Errors.h"
#include "C:\Users\User\source\repos\Laba1\Laba1\Class_List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test_push
{
	TEST_CLASS(Test_empty_size_push)
	{
	private:
		list<double> list_of_doubles;
		list<char> list_of_chars;
	public:
		// IS_EMPTY TESTS
		TEST_METHOD(Is_empty_full_list)
		{//list has 1 element, is_empty() must return FALSE
			list_of_doubles.push_back(1.2);
			Assert::AreEqual(false, list_of_doubles.is_empty());
		}
		TEST_METHOD(Is_empty_list_is_empty)
		{//list is empty, is_empty() must return TRUE
			Assert::AreEqual(true, list_of_chars.is_empty());
		}
		// GET_SIZE TESTS
		TEST_METHOD(Get_size_empty_list)
		{//list is empty, get_size() must return 0
			Assert::AreEqual(size_t(0), list_of_chars.get_size());
		}
		TEST_METHOD(Get_size_4_elements)
		{//list has 4 elements, get_size() must return 4
			list_of_doubles.push_back(1.2);
			list_of_doubles.push_back(3.4);
			list_of_doubles.push_back(5.6);
			list_of_doubles.push_back(7.8);
			Assert::AreEqual(size_t(4), list_of_doubles.get_size());
		}
		//PUSH_BACK TESTS
		TEST_METHOD(Push_back_one_element_Is_data_correct)
		{//list is empty, after push_back(7.7) at(1) must return 7.7
			list_of_doubles.push_back(7.7);
			Assert::AreEqual(7.7, list_of_doubles.at(1));
		}
		TEST_METHOD(Push_back_one_element_Is_size_correct)
		{//list is empty, after push_back(...) get_size() must return 1
			list_of_chars.push_back('!');
			Assert::AreEqual(size_t(1), list_of_chars.get_size());
		}
		TEST_METHOD(Push_back_2_elements_Is_2_data_correct)
		{//list has 2 elements, at(2) must return '!'
			list_of_chars.push_back(' ');
			list_of_chars.push_back('!');
			Assert::AreEqual('!', list_of_chars.at(2));
		}
		TEST_METHOD(Push_back_3_elements_Is_size_correct)
		{//list has 3 elements, get_size() must return 3 after push_backs(...)
			list_of_doubles.push_back(1.2);
			list_of_doubles.push_back(2.3);
			list_of_doubles.push_back(3.4);
			Assert::AreEqual(size_t(3), list_of_doubles.get_size());
		}
		//push_front tests
		TEST_METHOD(Push_front_one_element_Is_data_correct)
		{//list is empty, after push_front(' ') at(1) must return ' '
			list_of_chars.push_front(' ');
			Assert::AreEqual(' ', list_of_chars.at(1));
		}
		TEST_METHOD(Push_front_one_list_Is_size_correct)
		{//list is empty, after push_front(...) get_size() must return 1
			list_of_doubles.push_front(1.2);
			Assert::AreEqual(size_t(1), list_of_doubles.get_size());
		}
		TEST_METHOD(Push_front_2_elements_Is_data_correct)
		{//list has 2 elements, at(1) must return ' '
			list_of_chars.push_front('!');
			list_of_chars.push_front(' ');
			Assert::AreEqual(' ', list_of_chars.at(1));
		}
		TEST_METHOD(Push_front_4_elements_Is_size_correct)
		{//list has 4 elements, get_size() must return 4
			list_of_doubles.push_front(1.2);
			list_of_doubles.push_front(3.4);
			list_of_doubles.push_front(5.6);
			list_of_doubles.push_front(7.8);
			Assert::AreEqual(size_t(4), list_of_doubles.get_size());
		}
	};
}