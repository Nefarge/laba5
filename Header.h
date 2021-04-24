#pragma once
class Deque
{
private:
	struct Elem
	{
		int data;
		Elem* next, * prev;
	};
	Elem* head, * tail;
	int count;
public:
	Deque(); //конструктор инициализации
	Deque(const Deque& other); //конструктор копирования
	Deque(Deque&& other); //конструктор перемещения
	~Deque(); //деструктор

	int GetSize();
	Elem* GetElem(int);
	void Del(int pos = 0);
	void Insert(int pos = 0);
	void PushFront(int n);
	void PushBack(int n);
	void Print();
	void Print(int pos);
	void DelAll();
	void PeekFront();
	void PeekBack();
	Deque& operator = (const Deque& other); //перегруз операции присваивания
	Deque& operator = (Deque&& other); //перегруз операции присваивания с перемещением 
};