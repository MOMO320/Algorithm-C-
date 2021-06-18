// MyLinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "LinkedList.h"


int main()
{
    LinkedList* List = new LinkedList;

    List->Append(1);
    List->Append(2);
    List->Append(3);
    List->Append(4);
    List->Append(5);

}

