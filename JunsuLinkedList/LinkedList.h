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
        //����ó�� ���ͷ��̼� ī��Ʈ�� size ���� Ŭ������!
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

//Erase(index)����� - �����Ҵ� �ݵ�� ���!
//Clear() ����� - ����带 ���ֱ�(Begin, End �� �״��)
//Empty() ����� - ������ 0���� üũ, bool�� ����
//Pop_back() ����� - ������ ��� ����

//����ũ�� ����Ʈ �ݵ��!

int main()
{

}