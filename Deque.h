#pragma once
#include <cstdlib>
#include <stdexcept>

template <class T>
class Node
{
public:
	T data;
	Node* front;
	Node* back;
	Node() : data(0) , front(NULL), back(NULL) {};
	Node(T newData, Node* newFront, Node* newBack) : data(newData), front(newFront), back(newBack) {};
};

template <class T>
class Deque
{
public:
	Deque();
	Deque(const Deque& copyFromMe);
	~Deque();
	void insertFront(T insertData);
	void insertBack(T insertData);
	T removeFront();
	T removeBack();
	T peekFront();
	T peekBack();
	bool empty();
	int size() const;

private:
	Node<T>* head;
	Node<T>* tail;
};



template <class T>
Deque<T>::Deque()
{
	head = NULL;
	tail = NULL;
}

template <class T>
Deque<T>::Deque(const Deque& copyFromMe)
{
	Node<T>* cursor = copyFromMe.head;
	head = new Node<T>(cursor->data, NULL, NULL);
	tail = head;
	while (cursor != copyFromMe.tail)
	{
		cursor = cursor->back;
		this->insertBack(cursor->data);
	}
}

template <class T>
Deque<T>::~Deque()
{
	while (tail != head)
	{
		tail = tail->front;
		tail->back->front = NULL;
		delete tail->back;
		tail->back = NULL;
	}
	tail = NULL;
	delete head;
	head = NULL;
}

template <class T>
void Deque<T>::insertFront(const T insertData)
{
	if (head != NULL && tail != NULL)
	{
		head->front = new Node<T>(insertData, NULL, head);
		head = head->front;
	}
	else
	{
		head = new Node<T>(insertData, NULL, NULL);
		tail = head;
	}
}

template <class T>
void Deque<T>::insertBack(const T insertData)
{
	if (tail != NULL && head != NULL)
	{
		tail->back = new Node<T>(insertData, tail, NULL);
		tail = tail->back;
	}
	else
	{
		head = new Node<T>(insertData, NULL, NULL);
		tail = head;
	}

}

template <class T>
T Deque<T>::removeFront()
{
	if (this->size() == 0) throw std::runtime_error("Deque is empty! remove front can not be processed.");
	T frontValue = head->data;

	if (this->size() == 1)
	{
		this->~Deque();
		return frontValue;
	}

	head = head->back;
	delete head->front;
	head->front = NULL;

	return frontValue;
}

template <class T>
T Deque<T>::removeBack()
{
	if (this->size() == 0) throw std::runtime_error("Deque is empty! remove back can not be processed.");
	T backValue = tail->data;
	if (this->size() == 1)
	{
		cout << "if executed" << endl;
		this->~Deque();
		return backValue;
	}
	
	tail = tail->front;
	delete tail->back; 
	tail->back = NULL;

	return backValue;
}

template <class T>
T Deque<T>::peekFront()
{

	if (this->size() == 0) throw std::runtime_error("Deque is empty!");

	return head->data;
}

template <class T>
T Deque<T>::peekBack()
{
	if (this->size() == 0) throw std::runtime_error("Deque is empty!");
	return tail->data;
}

template <class T>
bool Deque<T>::empty()
{
	if (this->size() == 0)
		return true;
	else
		return false;
}

template <class T>
int Deque<T>::size() const
{
	int count = 0;
	Node<T>* cursor = head;
	while (cursor != NULL)
	{
		count++;
		cursor = cursor->back;
	}

	return count;
}


