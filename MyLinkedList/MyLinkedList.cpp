// MyLinkedList.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include "LinkedList.h"


int main()
{
    LinkedList* List = new LinkedList;

    List->Append(10);
    List->Append(15);
    List->Append(20);
    List->Append(25);
    List->Append(30);

    List->FindNode(3);
    
    List->Insert(3, 100);

}

