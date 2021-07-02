#include "MyVector.h"

template<typename T>
MyVector<T>::MyVector()
{
	Arr = new T[BasicAllocateSize];
	Size = 0;
	AllocatedSize = BasicAllocateSize;
}

template<typename T>
MyVector<T>::~MyVector()
{
	delete[] Arr;
}

template<typename T>
int MyVector<T>::GetSize()
{
	return Size;
}

template<typename T>
int MyVector<T>::GetAllocatedSize()
{
	return AllocatedSize;
}

template<typename T>
void MyVector<T>::PushBack(T value)
{
	TryNewAllocate();
	Arr[Size] = value;
	Size++;
}

template<typename T>
void MyVector<T>::Insert(int index, T value)
{
	if (index > Size)
	{
		std::cout << "Out of Range" << std::endl;
		return;
	}

	TryNewAllocate();

	for (int i = Size; i > index; --i)
	{
		Arr[i] = Arr[i - 1];
	}

	Arr[index] = value;
	Size++;
}

template<typename T>
void MyVector<T>::Delete(int index)
{
	if (index < Size)
	{
		std::cout << "Out Of Range" << std::endl;
		return;
	}

	for (int i = index; i < Size - 1; ++i)
	{
		Arr[i] = Arr[i + 1];
	}
	Size--;
}

template<typename T>
void MyVector<T>::Reserve(int DesiredSize)
{
	NewAlloc(DesiredSize);
}

template<typename T>
void MyVector<T>::NewAlloc(int DesiredSize)
{
	if (DesiredSize == 0)
	{
		AllocatedSize = AllocatedSize * 2;	
	}
	else
	{
		if (AllocatedSize >= DesiredSize)
		{
			return;
		}
		AllocatedSize = DesiredSize;
	}

	T* NewArr = new T[AllocatedSize];

	for (int i = 0; i < Size; ++i)
	{
		NewArr[i] = Arr[i];
	}

	delete[] Arr;
	Arr = NewArr;
}

template<typename T>
void MyVector<T>::TryNewAllocate()
{
	if (AllocatedSize <= Size)
	{
		NewAlloc();
	}
}
