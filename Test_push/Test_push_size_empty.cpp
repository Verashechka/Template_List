#include "stdafx.h"
#include "CppUnitTest.h"
#include "C:\Users\User\source\repos\Laba1\Laba1\Errors.h"
#include "C:\Users\User\source\repos\Laba1\Laba1\Class_List.h"
#include <string.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test_push
{		
	TEST_CLASS(Test_push_size_empty)
	{
	private:
		list<double> list_of_doubles;
		list<char> list_of_chars;
		double data_double_1 = 7.7, data_double_2 = 6.4;
		char data_char_1 = ' ', data_char_2 = '!';
		int size_of_doubles, size_of_chars;
		bool is_empty_doubles, is_empty_chars;
	public:
		TEST_METHOD(Test_push_back)
		{
			list_of_doubles.push_back(data_double_1);
			list_of_doubles.push_back(data_double_2);
			double at_1, at_2;
			at_1=list_of_doubles.at(1);
			at_2 = list_of_doubles.at(2);
			Assert::AreEqual(7.7, at_1);
			Assert::AreEqual(6.4, at_2);
		}
		TEST_METHOD(Test_push_front)
		{
			list_of_chars.push_front(data_char_1);
			list_of_chars.push_front(data_char_2);
			char at_1, at_2;
			at_1 = list_of_chars.at(1);
			at_2 = list_of_chars.at(2);
			Assert::AreEqual('!', at_1);
			Assert::AreEqual(' ', at_2);
		}
		TEST_METHOD(Test_get_size)
		{
			list_of_doubles.push_back(data_double_1);
			list_of_doubles.push_back(data_double_2);
			size_of_doubles = list_of_doubles.get_size();
			size_of_chars = list_of_chars.get_size();
			Assert::AreEqual(2, size_of_doubles);
			Assert::AreEqual(0, size_of_chars);
		}
		TEST_METHOD(Test_is_empty)
		{
			list_of_doubles.push_back(data_double_1);
			is_empty_doubles = list_of_doubles.is_empty();
			is_empty_chars = list_of_chars.is_empty();
			Assert::AreEqual(false, is_empty_doubles);
			Assert::AreEqual(true, is_empty_chars);
		}
	};
}