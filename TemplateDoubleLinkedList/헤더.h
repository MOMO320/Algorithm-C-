#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
	T Value;
	Node<T>* NextNode = nullptr;
	Node<T>* PrevNode = nullptr;
};

template <typename T>
class TemplateLinkedList
{
public:
	TemplateLinkedList()
	{
		HeadNode = new Node<T>;
		Size = 0;
	}
	~TemplateLinkedList()
	{
		delete HeadNode;
	}

	void Apend(T _value)
	{
		if (Size == 0)
		{
			HeadNode->Value = _value;
			HeadNode->NextNode = nullptr;
			HeadNode->PrevNode = nullptr;
		
			Size++;

			return;
		}

		Node<T>* NewNode = new Node<T>;
		Node<T>* LastNode = IEnumeratorNode(Size);

		NewNode->Value = _value;
		NewNode->NextNode = nullptr;
		NewNode->PrevNode = LastNode;
		LastNode->NextNode = NewNode;

		Size++;
	}

	void PrintNode()
	{
		Node<T>* TempNode = HeadNode;
		int count = 0;
		while (TempNode->NextNode != nullptr)
		{
			cout << " 현재 index : " << count <<"\t"
				<< "current reference : "<< TempNode << "\t"
				<<" Value : " << TempNode->Value << "\t"
				<< "NextNode 주소 : " << TempNode->NextNode << "\t" << endl;
			
			TempNode = TempNode->NextNode;
			count++;
		}

		cout << " 현재 index : " << count << "\t"
			<< "current reference : " << TempNode << "\t"
			<< " Value : " << TempNode->Value << "\t"
			<< "NextNode 주소 : " << TempNode->NextNode << "\t" << endl;
	}


private:
	Node<T> * IEnumeratorNode(int _index)
	{
		int index = _index - 1;

		if (index == 0)
		{
			return HeadNode;
		}

		if (Size < index)
		{
			cout << " ===== 사이즈 범위를 넘었습니다. =====" << endl;
			return nullptr;
		}

		Node<T>* TempNode = HeadNode;

		for (int i = 0; i < index; i++)
		{
			TempNode = TempNode->NextNode;
		}

		return TempNode;
	}

public:
	Node<T>* HeadNode;

private:
	int Size;

};

