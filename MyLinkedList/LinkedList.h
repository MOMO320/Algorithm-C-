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

//Erase(index)만들기 - 동적할당 반드시 고려!
//Clear() 만들기 - 모든노드를 없애기(Begin, End 는 그대로)
//Empty() 만들기 - 사이즈 0인지 체크, bool로 리턴
//Pop_back() 만들기 - 마지막 노드 제거

//더블링크드 리스트 반드시!