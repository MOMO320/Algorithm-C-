#include "LinkedList.h"

LinkedList::LinkedList()
{
	HeadNode = new Node;
	size = 0;
}

void LinkedList::Append(int _value)
{
	if (size == 0)
	{
		HeadNode->value = _value;
		HeadNode->nextNode = nullptr;
		
		size += 1;
		cout << "사이즈 : " << size << "/ 현재 노드의 Value : " << HeadNode->value << "/현재 노드의 주소 : " << &HeadNode << "/ 다음 노드의 주소 : " << &HeadNode->nextNode << endl;
		return;
	}

	Node* TempNode = HeadNode;

	while (TempNode->nextNode != nullptr)
	{
		TempNode = TempNode->nextNode;
	}

	Node* NewNode = new Node;
	Node* NextNode = new Node;

	TempNode->nextNode = NewNode;
	NewNode->value = _value;
	NewNode->nextNode = nullptr;
	
	size += 1;
	
	cout << "사이즈 : " << size << "/ 현재 노드의 Value : " << NewNode->value<< "/현재 노드의 주소 : "<< &TempNode->nextNode <<"/ 다음 노드의 주소 : " << &NewNode->nextNode << endl;

}

void LinkedList::Insert(int _index, int _value)
{
	if (_index > size)
		return;
	Node* newNode = new Node;

	newNode->value = _value;
	newNode->nextNode = FindNode(_index)->nextNode;
	FindNode(_index)->nextNode = newNode;

	size += 1;

	cout << _index << " 번째 인덱스에 삽입 노드를 삽입했습니다." << endl;

	Node* TempNode = HeadNode;
	cout << "==================================" << endl;
	
	int count = 0;
	while (TempNode->nextNode != nullptr)
	{
		count++;
		cout << count << " 번째 인덱스 의 Value : " << TempNode->value << endl;
		TempNode = TempNode->nextNode;
	}
}

Node* LinkedList::FindNode(int _index)
{
	if (size < _index)
	{
		cout << " 인덱스 범위를 초과 했습니다." << endl;
		return nullptr;
	}

	Node* TempNode = HeadNode;
	
	if (_index == 1)
		return TempNode;

	for (int i = 0; i < _index-1; i++)
	{
		TempNode = TempNode->nextNode;
	}

	cout << "찾으시는 Index : " << _index << "/ Value : " << TempNode->value << endl;

	return TempNode;
}

void LinkedList::Erase(int _index)
{
	if (size < _index)
	{
		cout << "out of range" << endl;
		return;
	}

	Node * prevNode = new Node;
	Node* deleteNode = new Node;

	prevNode = FindNode(_index - 1);
	deleteNode = FindNode(_index);

	prevNode->nextNode = deleteNode->nextNode;

	delete deleteNode;

	size--;

	PrintNode();
}

void LinkedList::PrintNode()
{
	int index = 0;
	cout << "================================================" << endl;
	Node* TempNode = HeadNode;

	while (TempNode->nextNode != nullptr)
	{
		index++;
		cout << " Index : " << index << "/ Value : " << TempNode->value << endl;
		TempNode = TempNode->nextNode;
	}
}
