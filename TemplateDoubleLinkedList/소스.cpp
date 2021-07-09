#include "Çì´õ.h"

int main()
{
	TemplateLinkedList<char>* IntLinkedList = new TemplateLinkedList<char>;

	IntLinkedList->Apend('a');
	IntLinkedList->Apend('b');
	IntLinkedList->Apend('c');
	IntLinkedList->Apend('d');
	IntLinkedList->Apend('e');
	IntLinkedList->Apend('f');
	IntLinkedList->Apend('g');

	IntLinkedList->PrintNode();
}