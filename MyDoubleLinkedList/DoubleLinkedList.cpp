#include "DoubleLinkedList.h"

DoubleLinkedList::DoubleLinkedList()
{
	size = 0;
	Head = new Node;
}

void DoubleLinkedList::Apend(int _value)
{
	if (size == 0)
	{
		Head->value = _value;
		Head->Prev = nullptr;
		Head->Next = nullptr;
		size+=1;
	
		cout << "===================================" << endl;
		cout << "HeadNodex 의 Value : " << Head->value << "/ NextNode 의 주소 : " << &Head->Next << endl;
		return;
	}

	Node* NewNode = new Node;
	Node* PrevNode = IteratorNode(size);

	NewNode->value = _value;
	NewNode->Next = nullptr;
	NewNode->Prev = PrevNode;
	PrevNode->Next = NewNode;
	

	cout << "===================================" << endl;
	cout << " NewNode 의 주소 : " << &PrevNode->Next << "/ NewNode 의 Prev 의 Value : " << NewNode->Prev->value <<"/PrevNode 의 주소 : "<< &NewNode->Prev <<" / NewNode 의 NextNode 의 주소  : " << &NewNode->Next << endl;


	size += 1;
}

void DoubleLinkedList::Insert(int _index, int _value)
{
	Node* NewNode = new Node;
	Node* CurrentNode = IteratorNode(_index);
	Node* PrevNode = IteratorNode(_index - 1);

	NewNode->value = _value;
	NewNode->Next = CurrentNode;
	NewNode->Prev = CurrentNode->Prev;
	PrevNode->Next = NewNode;
	CurrentNode->Prev = NewNode;

	size += 1;

}

void DoubleLinkedList::Delete(int _index)
{
	Node* DeleteNode = IteratorNode(_index);
	Node* PrevNode = DeleteNode->Prev;
	Node* NextNode = DeleteNode->Next;

	PrevNode->Next = DeleteNode->Next;
	NextNode->Prev = PrevNode;
	
	delete DeleteNode;

	size -= 1;

}

Node* DoubleLinkedList::IteratorNode(int _index)
{
	int index = _index - 1;

	if (index == 0)
	{
		return Head;
	}

	if (index > size)
	{
		cout << " 사이즈 오버 " << endl;
		return nullptr;
	}

	Node* TempNode = Head;

	for (int i = 0; i < index; i++)
	{
		TempNode = TempNode->Next;
	}

	return TempNode;
}

void DoubleLinkedList::Print()
{
	cout << "-------------------- Print -------------------" << endl;

	Node* TempNode = Head;

	while (TempNode->Next != nullptr)
	{
		if (TempNode->Prev == nullptr)
		{
			cout << "===================================" << endl;
			cout << "HeadNodex 의 Value : " << TempNode->value << "/ NextNode 의 주소 : " << &TempNode->Next << endl;
		}
		else
		{
			cout << "===================================" << endl;
			cout << " NewNode 의 주소 : " << &TempNode->Prev->Next << "현재 Value : " << TempNode->value << "/ NewNode 의 Prev 의 Value : " << TempNode->Prev->value << "/PrevNode 의 주소 : " << &TempNode->Prev << " / NewNode 의 NextNode 의 주소  : " << &TempNode->Next << endl;
		}

		TempNode = TempNode->Next;
	}
	cout << "===================================" << endl;
	cout << " NewNode 의 주소 : " << &TempNode->Prev->Next << "현재 Value : " <<TempNode->value << "/ NewNode 의 Prev 의 Value : " << TempNode->Prev->value << "/PrevNode 의 주소 : " << &TempNode->Prev << " / NewNode 의 NextNode 의 주소  : " << &TempNode->Next << endl;

}
