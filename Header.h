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
	Deque(); //����������� �������������
	Deque(const Deque& other); //����������� �����������
	Deque(Deque&& other); //����������� �����������
	~Deque(); //����������

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
	Deque& operator = (const Deque& other); //�������� �������� ������������
	Deque& operator = (Deque&& other); //�������� �������� ������������ � ������������ 
};