#pragma once
#include <iostream>
//#define MALLOC			// malloc Test Define


template <typename T>
class MyVector
{
public:
	MyVector()
	{
#ifdef MALLOC
		Arr = (T*)malloc(sizeof(T) * BasicAllocateSize);
#else
		Arr = new T[BasicAllocateSize];
#endif
		Size = 0;
		AllocatedSize = BasicAllocateSize;
	}
	~MyVector()
	{
#ifdef MALLOC
		free(Arr);
#else
		delete[] Arr;
#endif 
	}

	void PushBack(const T& value)
	{
		TryNewAllocate();
		Arr[Size] = value;
		Size++;
	}

	template<typename ...Args>
	void Emplace_Back(Args&&... args)
	{
		TryNewAllocate();
		
		new(&Arr[Size]) T(std::forward<Args>(args)...);

		Size++;
	}


private:
	void TryNewAllocate()
	{
		if (AllocatedSize <= Size)
		{
			NewAlloc();
		}
	}

	void NewAlloc(int DesiredSize = 0)
	{
		if (DesiredSize == 0)
		{
			AllocatedSize = AllocatedSize * 2;
		}
		else
		{
			if (AllocatedSize >= DesiredSize)
				return;

			AllocatedSize = DesiredSize;
		}

#ifdef MALLOC
		T* NewArr = (T*)malloc(sizeof(T) * AllocatedSize);
#else
		T* NewArr = new T[AllocatedSize];
#endif // MALLOC

		for (int i = 0; i < Size; ++i)
		{
			NewArr[i] = Arr[i];
		}

#ifdef MALLOC
		free(Arr);
#else
		delete[] Arr;
#endif 
		Arr = NewArr;
	}

private:
	T* Arr;
	int Size;
	int AllocatedSize;

	static const int BasicAllocateSize = 10;

};

class Point
{
public:
	Point()
	{
		std::cout << " Point::기본 생성자! " << std::endl;
	}

	Point(int _x)
		:X(_x), Y(0)
	{
		std::cout << "Point::int 형 생성자! " << std::endl;
	}

	Point(int _x, int _y)
		:X(_x) , Y(_y)
	{
		std::cout << " Point:: int, int 형 생성자! " << std::endl;
	}

	void operator=(Point other)
	{
		X = other.X;
		Y = other.Y;

		std::cout << "Point::대입연산자!" << std::endl;
	}

private:
	int X;
	int Y;
};