#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
	int value;

	Node* nextNode = nullptr;
};

class LinkedList
{
public:
	LinkedList();
	void Append(int _value);
	void Insert(int _index, int _value);
	Node* FindNode(int _index);

private:
	Node* HeadNode = nullptr;

	int size;
};

