#pragma once
class item
{
public:
	char name[100], ddate[5], mdate[5], ydate[5], category[100], price[100], spent[100], remaining[100];
	item* next;
	item();
};
class Expenseslist
{
	item* head, * tail;
	int size;
public:
	Expenseslist();
	~Expenseslist();
	void Generate_all();
	void Return_all();
	void Add_new_expense();
	void Edit_expense();
	void Delete_expense();
	void Search_expense();
	void Display();
};

