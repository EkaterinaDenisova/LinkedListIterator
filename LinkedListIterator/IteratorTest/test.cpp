#include "pch.h"

#include "../LinkedListIterator/LinkedList.h"

// author: Денисова Екатерина
// тестирование класса итератора для односвязного списка

/*LinkedList<int> CreateList1() {
	LinkedList<int> l;
	l.addNode(2);
	l.addNode(5);
	l.addNode(12);
	l.addNode(-3);
	l.addNode(8);
	return l;
}*/

// тестирование метода begin
TEST(TestListIterator, TestBegin) {

	LinkedList<int> l;
	l.addNode(2);
	l.addNode(5);
	l.addNode(12);
	l.addNode(-3);
	l.addNode(8);

	//LinkedList<int> l = CreateList1();

	LinkedList<int>::LinkedListIterator<int> it1 = l.begin();



	EXPECT_EQ(*it1, 2);
	//EXPECT_TRUE(true);
}

// тестирование оператора *
TEST(TestListIterator, TestData) {

	LinkedList<int> l;
	l.addNode(2);
	l.addNode(5);
	l.addNode(12);
	l.addNode(-3);
	l.addNode(8);

	//LinkedList<int> l = CreateList1();

	LinkedList<int>::LinkedListIterator<int> it1 = l.begin();

	std::vector<int> arr, arr1 = { 2 , 5, 12, -3, 8 };

	for (LinkedList<int>::LinkedListIterator<int> it1 = l.begin(); it1 != l.end(); ++it1) {
		arr.push_back(*it1);
	}


	EXPECT_EQ(arr, arr1);
	//EXPECT_TRUE(true);
}

// тестирование оператора ==
TEST(TestListIterator, TestEqual) {

	LinkedList<int> l;
	l.addNode(2);
	l.addNode(5);
	l.addNode(12);
	l.addNode(-3);
	l.addNode(8);

	//LinkedList<int> l = CreateList1();

	LinkedList<int>::LinkedListIterator<int> it1 = l.begin();
	LinkedList<int>::LinkedListIterator<int> it2 = l.begin();

	EXPECT_TRUE(it1 == it2);
	++it1;
	++it2;
	EXPECT_TRUE(it1 == it2);

}

// тестирование оператора !=
TEST(TestListIterator, TestNotEqual) {

	LinkedList<int> l;
	l.addNode(2);
	l.addNode(5);
	l.addNode(12);
	l.addNode(-3);
	l.addNode(8);

	//LinkedList<int> l = CreateList1();

	LinkedList<int>::LinkedListIterator<int> it1 = l.begin();
	LinkedList<int>::LinkedListIterator<int> it2 = l.begin();

	EXPECT_TRUE(!(it1 != it2));
	++it1;

	EXPECT_TRUE(it1 != it2);

}

// тестирование оператора ++
TEST(TestListIterator, TestInc) {

	LinkedList<int> l;
	l.addNode(2);
	l.addNode(5);
	l.addNode(12);
	l.addNode(-3);
	l.addNode(8);

	//LinkedList<int> l = CreateList1();

	LinkedList<int>::LinkedListIterator<int> it1 = l.begin();


	EXPECT_EQ(*it1, 2);
	++it1;

	EXPECT_EQ(*it1, 5);
	++it1;
	EXPECT_EQ(*it1, 12);
	++it1;
	EXPECT_EQ(*it1, -3);
	++it1;
	EXPECT_EQ(*it1, 8);
	++it1;
	EXPECT_EQ(it1, l.end());


}