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
		list<bool> list_of_bools;
	public:
		// INSERT TESTS
		TEST_METHOD(insert_wrong_index)
		{// list has 1 element, index for inserting is wrong, insert(...) must catch Wrong_index error 
			list_of_ints.push_back(1);
			try
			{
				list_of_ints.insert(2, 7);
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
		}
		TEST_METHOD(insert_first_element_Is_size_correct)
		{// list has 1 element, after insert(..., 1) get_size() must return 2
			list_of_bools.push_back(false);
			list_of_bools.insert(true, 1);
			Assert::AreEqual(size_t(2), list_of_bools.get_size());
		}
		TEST_METHOD(insert_first_element_Is_data_correct)
		{// list has 2 elements, after insert(3, 1) at(1) must return 3
			list_of_ints.push_back(1);
			list_of_ints.push_back(2);
			list_of_ints.insert(3, 1);
			Assert::AreEqual(3, list_of_ints.at(1));
		}
		TEST_METHOD(insert_last_element_Is_size_correct)
		{// list has 2 elements, after insert(..., 3) get_size() must return 3
			list_of_bools.push_back(false);
			list_of_bools.push_back(true);
			list_of_bools.insert(true, 3);
			Assert::AreEqual(size_t(3), list_of_bools.get_size());
		}
		TEST_METHOD(insert_last_element_Is_data_correct)
		{// list has 2 elements, after insert(5, 3) at(3) must return 5
			list_of_ints.push_back(1);
			list_of_ints.push_back(2);
			list_of_ints.insert(5, 3);
			Assert::AreEqual(5, list_of_ints.at(3));
		}
		TEST_METHOD(insert_middle_element_Is_size_correct)
		{// list has 2 elements, after insert(..., 2) get_size() must return 3
			list_of_bools.push_back(false);
			list_of_bools.push_back(false);
			list_of_bools.insert(true, 2);
			Assert::AreEqual(size_t(3), list_of_bools.get_size());
		}
		TEST_METHOD(insert_middle_element_Is_data_correct)
		{// list has 2 elements, after insert(7, 2) at(2) must return 7
			list_of_ints.push_back(1);
			list_of_ints.push_back(2);
			list_of_ints.insert(7, 2);
			Assert::AreEqual(7, list_of_ints.at(2));
		}
		// SET TESTS
		TEST_METHOD(set_empty_list)
		{// list is empty, set(...) must catch Head_is_null error
			try
			{
				list_of_ints.set(5, 1);
			}
			catch (Head_is_null error)
			{
				error.what();
			}
		}
		TEST_METHOD(set_wrong_index)
		{// list has 1 element, index is wrong, set(..., 4) must catch Wrong_index error
			list_of_bools.push_back(true);
			try
			{
				list_of_bools.set(false, 4);
			}
			catch (Wrong_index_of_element error)
			{
				error.what();
			}
		}
		TEST_METHOD(set_middle_element_Is_data_correct)
		{// list has 3 element, after insert(4,2) at(2) must return 4
			list_of_ints.push_back(1);
			list_of_ints.push_back(2);
			list_of_ints.push_back(3);
			list_of_ints.insert(4, 2);
			Assert::AreEqual(4, list_of_ints.at(2));
		}
	};
}