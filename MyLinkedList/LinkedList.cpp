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
		cout << "������ : " << size << "/ ���� ����� Value : " << HeadNode->value << "/���� ����� �ּ� : " << &HeadNode << "/ ���� ����� �ּ� : " << &HeadNode->nextNode << endl;
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
	
	cout << "������ : " << size << "/ ���� ����� Value : " << NewNode->value<< "/���� ����� �ּ� : "<< &TempNode->nextNode <<"/ ���� ����� �ּ� : " << &NewNode->nextNode << endl;

}

void LinkedList::Insert(int _index, int _value)
{
}

Node* LinkedList::FindNode(int _index)
{
	return nullptr;
}
