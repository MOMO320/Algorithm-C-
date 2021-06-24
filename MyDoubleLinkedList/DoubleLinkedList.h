#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
	int value;

	Node* Next  = nullptr;
	Node* Prev = nullptr;
};


class DoubleLinkedList
{
public:
	DoubleLinkedList();
	void Apend(int _value);
	void Insert(int _index, int _value);
	void Delete(int _index);

	Node* IteratorNode(int _index);

	void Print();

private:
	int size;
	Node* Head;
};

