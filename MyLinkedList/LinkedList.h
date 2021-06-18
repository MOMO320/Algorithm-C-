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

	void Erase(int _index);
	void Clear();
	bool Empty();
	void Pop_back();

	void PrintNode();

private:
	Node* HeadNode = nullptr;

	int size;
};

//Erase(index)����� - �����Ҵ� �ݵ�� ���!
//Clear() ����� - ����带 ���ֱ�(Begin, End �� �״��)
//Empty() ����� - ������ 0���� üũ, bool�� ����
//Pop_back() ����� - ������ ��� ����

//����ũ�� ����Ʈ �ݵ��!