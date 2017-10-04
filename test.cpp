#include<iostream>
#include "Deque.h"
#include <string>
using namespace std;

int main()
{
	Deque<double> A;
	cout << A.size() << endl;
	cout << A.empty() << endl;
	try
	{
		cout << A.removeBack() << endl;
	}
	catch (std::runtime_error& e)
	{
		cout << e.what() << endl;
		cout << endl;
	}
	try
	{
		cout << A.removeFront() << endl;
	}
	catch (std::runtime_error& e)
	{
		cout << e.what() << endl;
		cout << endl;
	}
	try
	{
		cout << A.peekBack() << endl;
	}
	catch (std::runtime_error& e)
	{
		cout << e.what() << endl;
		cout << endl;
	}
	try
	{
		cout << A.peekFront() << endl;
	}
	catch (std::runtime_error& e)
	{
		cout << e.what() << endl;
		cout << endl;
	}

	A.insertFront(5.4);
	cout << A.size() << endl;
	cout << A.empty() << endl;
	cout << A.peekBack() << endl;
	cout << A.peekFront() << endl << endl;

	A.insertBack(1.5);
	cout << A.size() << endl;
	cout << A.empty() << endl;
	cout << A.peekBack() << endl;
	cout << A.peekFront() << endl << endl;

	A.insertBack(4.5);
	A.insertFront(3.2);
	cout << A.size() << endl;
	cout << A.empty() << endl;
	cout << A.peekBack() << endl;
	cout << A.peekFront() << endl << endl;

	Deque<double> B = A;
	cout << A.size() << endl;
	cout << A.empty() << endl;
	cout << A.peekBack() << endl;
	cout << A.peekFront() << endl << endl;
	cout << B.size() << endl;
	cout << B.empty() << endl;
	cout << B.peekBack() << endl;
	cout << B.peekFront() << endl << endl;

	cout << B.removeBack() << endl;
	cout << B.size() << endl;
	cout << B.empty() << endl;
	cout << B.peekBack() << endl;
	cout << B.peekFront() << endl << endl;

	cout << B.removeFront() << endl;
	cout << B.size() << endl;
	cout << B.empty() << endl;
	cout << B.peekBack() << endl;
	cout << B.peekFront() << endl << endl;

	cout << B.removeFront() << endl;
	cout << B.size() << endl;
	cout << B.empty() << endl;
	cout << B.peekBack() << endl;
	cout << B.peekFront() << endl << endl;

	try
	{
		cout << B.removeBack() << endl;
		cout << B.size() << endl;
		cout << B.empty() << endl;
		cout << B.peekBack() << endl;
		cout << B.peekFront() << endl << endl;
	}
	catch (runtime_error& e)
	{
		cout << e.what()
			<< endl;
		cout << endl;
	}

	try
	{
		cout << B.removeFront() << endl;
		cout << B.size() << endl;
		cout << B.empty() << endl;
	}
	catch (runtime_error& e)
	{
		cout << e.what() << endl << endl;

	}
	return 0;
}