#pragma once
#include <iostream>

template <typename T>
class MyVector
{
public:
	MyVector();
	~MyVector();

	int GetSize();
	int GetAllocatedSize();

	void PushBack(const T & value);
	void Insert(int index, T value);
	void Delete(int index);
	void Reserve(int DesiredSize);// �޸� ���Ҵ�

private:
	void NewAlloc(int DesiredSize = 0);
	void TryNewAllocate();

private:
	T* Arr;
	int Size;			// ���� ���� ������
	int AllocatedSize;	// ���� �Ҵ�� ������

	static const int BasicAllocateSize = 10;
};
