#include <iostream>

struct Node
{
    int Value;
    Node* NextNode;
};

class LinkedList
{
public:
    LinkedList()
    {
        Begin = new Node;
        End = new Node;

        Begin->NextNode = End;
        End->NextNode = nullptr;

        size = 0;
    }

    Node* GetIteration(int count)
    {
        //예외처리 이터레이션 카운트는 size 보다 클수없다!
        if (count > size)
        {
            std::cout << "out of range" << std::endl;
            return nullptr;
        }

        Node* atNode = Begin;
        for (int i = 0; i < count; ++i)
        {
            atNode = atNode->NextNode;
        }
        return atNode;
    }

    void Apend(int value)
    {
        Node* PrevLastNode = GetIteration(size);

        Node* newNode = new Node;
        newNode->Value = value;
        newNode->NextNode = End;

        PrevLastNode->NextNode = newNode;

        size += 1;
    }

    unsigned int GetSize()
    {
        return size;
    }

    void Insert(int index, int value)
    {
        Node* CurrentNode = GetIteration(index);
        if (CurrentNode = nullptr)
        {
            std::cout << "out of range" << std::endl;
            return;
        }

        Node* newNode = new Node;

        newNode->Value = value;
        newNode->NextNode = CurrentNode->NextNode;

        CurrentNode->NextNode = newNode;

        size += 1;
    }


private:
    Node* Begin = nullptr;
    Node* End = nullptr;

    unsigned int size;
};

//Erase(index)만들기 - 동적할당 반드시 고려!
//Clear() 만들기 - 모든노드를 없애기(Begin, End 는 그대로)
//Empty() 만들기 - 사이즈 0인지 체크, bool로 리턴
//Pop_back() 만들기 - 마지막 노드 제거

//더블링크드 리스트 반드시!

int main()
{

}