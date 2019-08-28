#include<iostream>
using namespace std;

#define tab "\t"

class Element
{
	int Data;		//�������� ��������
	Element* pNext;	//����� ���������� ��������
	static int count;
public:
	Element(int Data, Element* pNext = nullptr)
	{
		this->Data = Data;
		this->pNext = pNext;
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};

int Element::count = 0;

class ForwardList
{
	Element* Head;	//��������� �� ������ ������
	unsigned int size;
public:
	ForwardList()
	{
		this->Head = nullptr;
		this->size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//			���������� ��������� � ������:
	void push_front(int Data)
	{
		//Data - ����������� ��������.
		//1) ������� �������, � ������� ����� �������� ����������� ��������:
		Element* New = new Element(Data);
		New->pNext = Head;
		Head = New;
		size++;
	}
	void push_back(int Data)
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

	void insert(int index, int data)
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
		Element* New = new Element(data);
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}

	//�������� ���������:
	void pop_front()
	{
		Element* buffer = Head;
		Head = Head->pNext;
		delete buffer;
		size--;
	}

	void pop_back()
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

	void print()
	{
		Element* Temp = Head;//Temp - ��������.
		//�������� - ��� ���������, ��� ������ �������� ����� �������� ������
		//� ��������� ��������� ������.
		while (Temp != nullptr)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//������� �� ��������� �������.
		}
		cout << "���������� ��������� ������: " << size << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int n;		//���������� ���������
	cout << "������� ���������� ���������: ";
	cin >> n;
	ForwardList fl;
	for (int i = 0; i < n; i++)
	{
		fl.push_front(rand() % 100);
	}
	fl.push_back(123);	fl.print();
	fl.pop_back();	fl.print();

	int index;
	int data;
	cout << "������� ������ ������������ ��������: "; cin >> index;
	cout << "������� �������� ������������ ��������: "; cin >> data;
	fl.insert(index, data);
	fl.print();

	ForwardList fl2;
	fl2.push_back(3);
	fl2.push_back(5);
	fl2.push_back(8);
	fl2.print();
}