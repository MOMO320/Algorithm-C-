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
	if (_index > size)
		return;
	Node* newNode = new Node;

	newNode->value = _value;
	newNode->nextNode = FindNode(_index)->nextNode;
	FindNode(_index)->nextNode = newNode;

	size += 1;

	cout << _index << " ��° �ε����� ���� ��带 �����߽��ϴ�." << endl;

	Node* TempNode = HeadNode;
	cout << "==================================" << endl;
	
	int count = 0;
	while (TempNode->nextNode != nullptr)
	{
		count++;
		cout << count << " ��° �ε��� �� Value : " << TempNode->value << endl;
		TempNode = TempNode->nextNode;
	}
}

Node* LinkedList::FindNode(int _index)
{
	if (size < _index)
	{
		cout << " �ε��� ������ �ʰ� �߽��ϴ�." << endl;
		return nullptr;
	}

	Node* TempNode = HeadNode;
	
	if (_index == 1)
		return TempNode;

	for (int i = 0; i < _index-1; i++)
	{
		TempNode = TempNode->nextNode;
	}

	cout << "ã���ô� Index : " << _index << "/ Value : " << TempNode->value << endl;

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
