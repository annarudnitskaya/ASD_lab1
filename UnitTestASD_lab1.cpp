#include "pch.h"
#include "CppUnitTest.h"
#include "../ASD_lab1/ASD_lab1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestASDlab1
{
	TEST_CLASS(UnitTestASDlab1)
	{
	public:

		TEST_METHOD(TestConstructor)
		{
			List WorkList;
			Assert::IsTrue(WorkList.get_size() == 0);
		}
		TEST_METHOD(TestConstructorWithDate)
		{
			List WorkList(2);
			Assert::IsTrue(WorkList.get_size() == 1);
			Assert::IsTrue(WorkList.at(0) == 2);
		}
		TEST_METHOD(TestDestructor)
		{
			List WorkList;
			WorkList.push_back(5);
			WorkList.push_front(8);
			WorkList.push_front(1);
			Assert::IsTrue(WorkList.get_size() == 3);
			WorkList.~List();
			Assert::IsTrue(WorkList.get_size() == 0);
		}
		TEST_METHOD(TestGetSize)
		{
			List WorkList;
			Assert::IsTrue(WorkList.get_size() == 0);
			WorkList.push_back(3);
			Assert::IsTrue(WorkList.get_size() == 1);
			WorkList.push_front(2);
			Assert::IsTrue(WorkList.get_size() == 2);
			WorkList.insert(9, 1);
			Assert::IsTrue(WorkList.get_size() == 3);
			WorkList.remove(1);
			Assert::IsTrue(WorkList.get_size() == 2);
		}
		TEST_METHOD(TestIsEmpty)
		{
			List WorkList;
			Assert::IsTrue(WorkList.isEmpty() == 1);
			WorkList.push_back(5);
			Assert::IsTrue(WorkList.isEmpty() == 0);
		}

		TEST_METHOD(TestPushBack)
		{
			List WorkList;
			Assert::IsTrue(WorkList.isEmpty() == 1);
			WorkList.push_back(2);
			Assert::IsTrue(WorkList.at(0) == 2);
			Assert::IsTrue(WorkList.get_size() == 1);
			Assert::IsTrue(WorkList.isEmpty() == 0);
			WorkList.push_back(3);
			Assert::IsTrue(WorkList.get_size() == 2);
			Assert::IsTrue(WorkList.at(1) == 3);
		}
		TEST_METHOD(TestPushFront)
		{
			List WorkList;
			Assert::IsTrue(WorkList.isEmpty() == 1);
			WorkList.push_front(2);
			Assert::IsTrue(WorkList.at(0) == 2);
			Assert::IsTrue(WorkList.get_size() == 1);
			Assert::IsTrue(WorkList.isEmpty() == 0);
			WorkList.push_front(1);
			Assert::IsTrue(WorkList.get_size() == 2);
			Assert::IsTrue(WorkList.at(0) == 1);
		}
		TEST_METHOD(TestPopFront)
		{
			List WorkList;
			Assert::IsTrue(WorkList.isEmpty() == 1);
			try {
				WorkList.pop_front();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty, so first element can't be deleted", error.what());
			}
			WorkList.push_back(10);
			WorkList.push_front(1);
			Assert::IsTrue(WorkList.isEmpty() == 0);
			Assert::IsTrue(WorkList.get_size() == 2);
			try {
				WorkList.pop_front();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty, so first element can't be deleted", error.what());
			}
			Assert::IsTrue(WorkList.at(0) == 10);
			Assert::IsTrue(WorkList.get_size() == 1);
		}
		TEST_METHOD(TestPopBack)
		{
			List WorkList;
			Assert::IsTrue(WorkList.isEmpty() == 1);
			try {
				WorkList.pop_back();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty, so last element can't be deleted", error.what());
			}
			WorkList.push_back(10);
			WorkList.push_front(1);
			Assert::IsTrue(WorkList.isEmpty() == 0);
			Assert::IsTrue(WorkList.get_size() == 2);
			try {
				WorkList.pop_back();
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("List is empty, so last element can't be deleted", error.what());
			}
			Assert::IsTrue(WorkList.at(0) == 1);
			Assert::IsTrue(WorkList.get_size() == 1);
		}
		TEST_METHOD(TestInsert)
		{
			List WorkList;
			try {
				WorkList.insert(5, 0);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is greater than the maximum index of the List", error.what());
			}
			WorkList.push_back(2);
			WorkList.push_front(1);
			Assert::IsTrue(WorkList.at(1) == 2);
			Assert::IsTrue(WorkList.get_size() == 2);
			try {
				WorkList.insert(7, 10);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is greater than the maximum index of the List", error.what());
			}
			try {
				WorkList.insert(7, 1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is greater than the maximum index of the List", error.what());
			}
			Assert::IsTrue(WorkList.at(1) == 7);
			Assert::IsTrue(WorkList.at(WorkList.get_size() - 1) == 2);
			Assert::IsTrue(WorkList.get_size() == 3);
			try {
				WorkList.insert(5, 0);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is greater than the maximum index of the List", error.what());
			}
			Assert::IsTrue(WorkList.get_size() == 4);
			Assert::IsTrue(WorkList.at(0) == 5);
		}
		TEST_METHOD(TestAt)
		{
			List WorkList;
			WorkList.push_back(2);
			try {
				WorkList.at(5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index\n", error.what());
			}
			WorkList.push_back(3);
			try {
				WorkList.at(1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index\n", error.what());
			}
			Assert::IsTrue(WorkList.at(0) == 2);
			Assert::IsTrue(WorkList.at(1) == 3);
		}
		TEST_METHOD(TestRemove)
		{
			List WorkList;
			WorkList.push_back(4);
			WorkList.push_front(3);
			WorkList.push_front(2);
			WorkList.push_front(1);
			Assert::IsTrue(WorkList.get_size() == 4);
			try {
				WorkList.remove(5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}
			Assert::IsTrue(WorkList.get_size() == 4);
			try {
				WorkList.remove(3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}
			Assert::IsTrue(WorkList.at(WorkList.get_size() - 1) == 3);
			Assert::IsTrue(WorkList.at(0) == 1);
			Assert::IsTrue(WorkList.get_size() == 3);
			try {
				WorkList.remove(0);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}
			Assert::IsTrue(WorkList.get_size() == 2);
			WorkList.push_back(4);
			Assert::IsTrue(WorkList.get_size() == 3);
			try {
				WorkList.remove(1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}
			Assert::IsTrue(WorkList.get_size() == 2);
			Assert::IsTrue(WorkList.at(0) == 2);
		}
		TEST_METHOD(TestClear)
		{
			List WorkList;
			WorkList.push_back(2);
			WorkList.push_front(1);

			Assert::IsTrue(WorkList.get_size() == 2);
			WorkList.clear();
			Assert::IsTrue(WorkList.get_size() == 0);
		}
		TEST_METHOD(TestSet)
		{
			List WorkList;
			WorkList.push_back(32);
			WorkList.push_front(11);
			WorkList.push_back(22);
			try {
				WorkList.set(0, 1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}
			try {
				WorkList.set(1, 2);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}
			try {
				WorkList.set(2, 3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}
			try {
				WorkList.set(100, 55);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("The position of the element is out of range List index", error.what());
			}

			Assert::IsTrue(WorkList.at(0) == 1);
			Assert::IsTrue(WorkList.at(1) == 2);
			Assert::IsTrue(WorkList.at(WorkList.get_size() - 1) == 3);
		}

		TEST_METHOD(TestSwap)
		{
			List WorkList;
			WorkList.push_back(3);
		    WorkList.push_front(1);
		    WorkList.insert(2, 1);
		    WorkList.swap(1,2);
			Assert::IsTrue(WorkList.at(0) == 1);
			Assert::IsTrue(WorkList.at(1) == 3);
			Assert::IsTrue(WorkList.at(WorkList.get_size() - 1) == 2);
		}
	};
}
