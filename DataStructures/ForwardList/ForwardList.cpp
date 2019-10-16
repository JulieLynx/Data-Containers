#include"ForwardList.h"




ForwardList::Element::Element(int Data, Element* pNext)
{
	this->Data = Data;
	this->pNext = pNext;
	count++;
	cout << "EConstructor:\t" << this << endl;
}
ForwardList::Element::~Element()
{
	count--;
	cout << "EDestructor:\t" << this << endl;
}
ForwardList::Element::operator const int&()const
{
	return this->Data;
}
ForwardList::Element::operator int&()
{
	return this->Data;
}

ForwardList::Iterator::Iterator(Element* Temp) :Temp(Temp)
{
	cout << "ItConstructor:\t" << this << endl;
}
ForwardList::Iterator::~Iterator()
{
	cout << "ItDestructor:\t" << this << endl;
}
ForwardList::Iterator& ForwardList::Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
ForwardList::Iterator ForwardList::Iterator::operator++(int)
{
	Iterator old = *this;
	Temp = Temp->pNext;
	return old;
}
const int& ForwardList::Iterator::operator*()const
{
	return Temp->Data;
}
int& ForwardList::Iterator::operator*()
{
	return Temp->Data;
}
bool ForwardList::Iterator::operator==(const Iterator& other)
{
	return this->Temp == other.Temp;
}
bool ForwardList::Iterator::operator!=(const Iterator& other)
{
	return this->Temp != other.Temp;
}


int ForwardList::Element::count = 0;

const int ForwardList::get_size()const
{
	return this->size;
}

const ForwardList::Iterator ForwardList::begin()const
{
	return Head;
}
ForwardList::Iterator ForwardList::begin()
{
	return Head;
}

const ForwardList::Iterator ForwardList::end() const
{
	return nullptr;
}
ForwardList::Iterator ForwardList::end()
{
	return nullptr;
}

ForwardList::ForwardList()
{
	this->Head = nullptr;
	this->size = 0;
	cout << "LConstructor:\t" << this << endl;
}
ForwardList::ForwardList(int size) :ForwardList()
{
	/*this->Head = nullptr;
	this->size = 0;*/
	while (size--)push_front(0);
}
ForwardList::ForwardList(initializer_list<int> il) :ForwardList()
{
	cout << typeid(il.begin()).name() << endl;
	for (int const* it = il.begin(); it != il.end(); it++)
		push_back(*it);
}
ForwardList::ForwardList(const ForwardList& other) :ForwardList()
{
	for (Element* Temp = other.Head; Temp != nullptr; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "LCopyConstruct:\t" << this << endl;
}
ForwardList::~ForwardList()
{
	while (Head)pop_front();
	cout << "LDestructor:\t" << this << endl;
}

//			Operators:
ForwardList& ForwardList::operator=(const ForwardList& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	for (Element* Temp = other.Head; Temp != nullptr; Temp = Temp->pNext)
		push_back(Temp->Data);
	cout << "LCopyAssignment:\t" << this << endl;
	return *this;
}
int& ForwardList::operator[](int index)
{
	Element* Temp = Head;
	for (int i = 0; i < index; i++)Temp = Temp->pNext;
	return Temp->Data;
}

//			Добавление элементов в список:
void ForwardList::push_front(int Data)
{
	//Data - добавляемое значение.
	//1) Создаем элемент, в который можно положить добавляемое значение:
	/*Element* New = new Element(Data);
	New->pNext = Head;
	Head = New;*/
	Head = new Element(Data, Head);
	size++;
}
void ForwardList::push_back(int Data)
{
	if (Head == nullptr)
	{
		push_front(Data);
		return;
	}
	Element* Temp = Head;
	while (Temp->pNext != nullptr)Temp = Temp->pNext;
	Temp->pNext = new Element(Data);
	size++;
}

void ForwardList::insert(int index, int data)
{
	if (index == 0)
	{
		push_front(data);
		return;
	}
	if (index > size)
	{
		cout << "Error: Out of range." << endl;
		return;
	}
	Element* Temp = Head;
	for (int i = 0; i < index - 1; i++)
	{
		Temp = Temp->pNext;
	}
	/*Element* New = new Element(data);
	New->pNext = Temp->pNext;
	Temp->pNext = New;*/
	Temp->pNext = new Element(data, Temp->pNext);
	size++;
}

//Удаление элементов:
void ForwardList::pop_front()
{
	Element* buffer = Head;
	Head = Head->pNext;
	delete buffer;
	size--;
}

void ForwardList::pop_back()
{
	Element* Temp = Head;
	while (Temp->pNext->pNext != nullptr)
	{
		Temp = Temp->pNext;
	}
	delete Temp->pNext;
	Temp->pNext = nullptr;
	size--;
}

void ForwardList::erase(int index)
{
	if (index == 0)
	{
		pop_front();
		return;
	}
	if (index >= size)
	{
		cout << "Error: out of range" << endl;
		return;
	}
	Element* Temp = Head;
	for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
	Element* buffer = Temp->pNext;

	Temp->pNext = Temp->pNext->pNext;
	delete buffer;
	size--;
}

void ForwardList::print()
{
	//Element* Temp = Head;//Temp - Итератор.
	////Итератор - это указатель, при помощи которого можно получить доступ
	////к элементам структуры данных.
	//while (Temp != nullptr)
	//{
	//	cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	//	Temp = Temp->pNext;	//Переход на следующий элемент.
	//}

	for (Element* Temp = Head; Temp != nullptr; Temp = Temp->pNext)
		cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
	cout << "Количество элементво списка: " << size << endl;
}


ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList op = left;
	for (ForwardList::Iterator it = right.begin(); it != right.end(); it++)
		op.push_back(*it);
	return op;
}



