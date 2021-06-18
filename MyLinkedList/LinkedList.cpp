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
}

Node* LinkedList::FindNode(int _index)
{
	return nullptr;
}
