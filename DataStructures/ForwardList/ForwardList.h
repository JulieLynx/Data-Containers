#pragma once

#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"





class ForwardList
{
	class Element
	{
		int Data;		//Значение элемента
		Element* pNext;	//Адрес следующего элемента
		static int count;
	public:
		Element(int Data, Element* pNext = nullptr);
		~Element();
		operator const int&()const;
		operator int&();
		friend class ForwardList;
	};
	Element* Head;	//Указатель на начало списка
	unsigned int size;
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr);
		~Iterator();
		Iterator& operator++();
		Iterator operator++(int);
		const int& operator*()const;
		int& operator*();
		bool operator==(const Iterator& other);
		bool operator!=(const Iterator& other);

	};
	const int get_size()const;

	const Iterator begin()const;

	Iterator begin();


	const Iterator end() const;

	Iterator end();


	ForwardList();

	ForwardList(int size);

	ForwardList(initializer_list<int> il);

	ForwardList(const ForwardList& other);

	~ForwardList();


	//			Operators:
	ForwardList& operator=(const ForwardList& other);

	int& operator[](int index);

	//			Добавление элементов в список:
	void push_front(int Data);
	void push_back(int Data);

	void insert(int index, int data);

	//Удаление элементов:
	void pop_front();

	void pop_back();

	void erase(int index);

	void print();
};
