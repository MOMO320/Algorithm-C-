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
	void Reserve(int DesiredSize);// 메모리 선할당

private:
	void NewAlloc(int DesiredSize = 0);
	void TryNewAllocate();

private:
	T* Arr;
	int Size;			// 현재 벡터 사이즈
	int AllocatedSize;	// 현재 할당된 사이즈

	static const int BasicAllocateSize = 10;
};
