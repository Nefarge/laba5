#include <iostream>
#include "Header.h"
using namespace std;
Deque::Deque()
{
	head = tail = NULL;
	count = 0;
}
Deque::Deque(const Deque& other)
{
	head = tail = NULL;
	count = 0;
	Elem* temp = other.head;
	while (temp != 0)
	{
		PushBack(temp->data);
		temp = temp->next;
	}
}
Deque::~Deque()
{
	DelAll();
}
void Deque::PushFront(int n)
{
	Elem* temp = new Elem;
	temp->prev = 0;
	temp->data = n;
	temp->next = head;
	if (head != 0)
		head->prev = temp;
	if (count == 0)
		head = tail = temp;
	else
		head = temp;
	count++;
}
void Deque::PushBack(int n)
{
	Elem* temp = new Elem;
	temp->next = 0;
	temp->data = n;
	temp->prev = tail;
	if (tail != 0)
		tail->next = temp;
	if (count == 0)
		head = tail = temp;
	else
		tail = temp;
	count++;
}
void Deque::Insert(int pos)
{
	setlocale(LC_ALL, "Russian");
	if (pos == 0)
	{
		cout << "������� ������� �������� ���������������� ������: ";
		cin >> pos;
	}
	if (pos < 1 || pos > count + 1)
	{
		cout << "�������� �������!\n";
		return;
	}
	if (pos == count + 1)
	{
		int data;
		cout << "������� �������� ������ �������� ���������������� ������: ";
		cin >> data;
		PushBack(data);
		return;
	}
	else if (pos == 1)
	{
		int data;
		cout << "������� �������� ������ �������� ���������������� ������: ";
		cin >> data;
		PushFront(data);
		return;
	}
	int i = 1;
	Elem* Ins = head;
	while (i < pos)
	{
		Ins = Ins->next;
		i++;
	}
	Elem* PrevIns = Ins->prev;
	Elem* temp = new Elem;
	cout << "������� �������� ������ �������� ���������������� ������: ";
	cin >> temp->data;
	if (PrevIns != 0 && count != 1)
		PrevIns->next = temp;
	temp->next = Ins;
	temp->prev = PrevIns;
	Ins->prev = temp;
	count++;
}
void Deque::Del(int pos)
{
	setlocale(LC_ALL, "Russian");
	if (pos == 0)
	{
		cout << "������� ������� �������� ���������������� ������: ";
		cin >> pos;
	}
	if (pos < 1 || pos > count)
	{
		cout << "�������� �������!\n";
		return;
	}
	int i = 1;
	Elem* Del = head;
	while (i < pos)
	{
		Del = Del->next;
		i++;
	}
	Elem* PrevDel = Del->prev;
	Elem* AfterDel = Del->next;
	if (PrevDel != 0 && count != 1)
		PrevDel->next = AfterDel;
	if (AfterDel != 0 && count != 1)
		AfterDel->prev = PrevDel;
	if (pos == 1)
		head = AfterDel;
	if (pos == count)
		tail = PrevDel;
	delete Del;
	count--;
}
void Deque::Print()
{
	if (count != 0)
	{
		Elem* temp = head;
		cout << "( ";
		while (temp->next != 0)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << " )\n";
	}
}
void Deque::Print(int pos)
{
	setlocale(LC_ALL, "Russian");
	if (pos < 1 || pos > count)
	{
		cout << "�������� �������!\n";
		return;
	}
	Elem* temp;
	if (pos <= count / 2)
	{
		temp = head;
		int i = 1;
		while (i < pos)
		{
			temp = temp->next;
			i++;
		}
	}
	else
	{
		temp = tail;
		int i = 1;

		while (i <= count - pos)
		{
			temp = temp->prev;
			i++;
		}
	}
	cout << pos << " �������: ";
	cout << temp->data << endl;
}
void Deque::DelAll()
{
	while (count != 0)
		Del(1);
}
int Deque::GetSize()
{
	return count;
}
Deque::Elem* Deque::GetElem(int pos)
{
	setlocale(LC_ALL, "Russian");
	Elem* temp = head;
	if (pos < 1 || pos > count)
	{
		cout << "�������� �������!\n";
		return 0;
	}
	int i = 1;
	while (i < pos && temp != 0)
	{
		temp = temp->next;
		i++;
	}
	if (temp == 0)
		return 0;
	else
		return temp;
}
Deque& Deque::operator = (const Deque& other) //�������� �������� ������������
{
	if (this == &other)
	{
		return *this;
	}
	this->~Deque(); // DelAll();
	Elem* temp = other.head;
	while (temp != 0)
	{
		PushBack(temp->data);
		temp = temp->next;
	}
	return *this;
}
Deque& Deque::operator = (Deque&& other) //�������� �������� ������������ � ������������ 
{
	if (this == &other)
	{
		return *this;
	}
	delete[] head;
	delete[] tail;
	head = other.head;
	tail = other.tail;
	count = other.count;
	other.head = nullptr;
	other.tail = nullptr;
}
void Deque::PeekFront()
{
	Elem* temp = head;
	cout << temp->data << endl;
}
void Deque::PeekBack()
{
	Elem* temp = tail;
	cout << temp->data << endl;
}
Deque::Deque(Deque&& other)//����������� �����������
{
	head = other.head;
	tail = other.tail;
	count = other.count;
	other.head = nullptr;
	other.tail = nullptr;
}
