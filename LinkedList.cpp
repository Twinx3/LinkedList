#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Node
{
private:

public:
	T data;
	Node<T>* _next;
	Node<T>* _prev;
};

template <typename T>
class List
{
private:
	Node<T>* _begin;
public:

	List()
	{
		_begin = nullptr;
	}
	~List()
	{
		Node<T>* node = _begin;
		Node<T>* tempnode;

		while (node != nullptr)
		{
			tempnode = node;
			node = node->_next;
			delete tempnode;
		}
	}

	void push_front(T node)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = node;

		if (_begin == nullptr)
		{
			_begin = newNode;
			newNode->_next = nullptr;
			newNode->_prev = nullptr;
			return;
		}
		newNode->_next = _begin;
		_begin->_prev = newNode;
		_begin = newNode;
	}

	void push_back(T some)
	{
		Node<T>* newNode = new Node<T>();
		newNode->data = some;
		if (_begin == nullptr)
		{
			_begin = newNode;
			return;
		}
		Node<T>* temp = _begin;
		while (temp->_next != nullptr)
		{
			temp = temp->_next;
		}
		temp->_next = newNode;
		newNode->_prev = temp;
	}

	void ShowList()
	{
		cout << "<----------------------------------->" << endl;
		Node<T>* temp = _begin;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->_next;
		}
		cout << endl << "<----------------------------------->" << endl;
	}
};

int main()
{
	List<int> list;
	list.push_back(50);
	list.push_back(40);
	list.push_back(30);
	list.push_back(20);
	list.push_front(60);
	list.ShowList();
}