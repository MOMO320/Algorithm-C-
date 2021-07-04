#include "TemplateVectorAgain.h"

int main()
{
	MyVector<Point> v;
	v.Emplace_Back();
	v.Emplace_Back(1, 3);
	v.Emplace_Back(1);
}