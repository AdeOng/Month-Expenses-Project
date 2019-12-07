#include <iostream>
#include "Expenseslist.h"
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
item::item()
{
	next = 0;
}
Expenseslist::Expenseslist()
{
	head = tail = 0;
	size = 0;
}
Expenseslist::~Expenseslist()
{
	item* current = head;
	while (current != 0) {
		item* next = current->next;
		delete current;
		current = next;
	}
	head = tail = 0;
}

//Done by ME //TESTED
void Expenseslist::Generate_all()
{
	int i = 0;
	ifstream file, sizefile;
	file.open("items.txt", ios::in);
	sizefile.open("sizefile.txt", ios::in);
	char tmpsizearr[30];
	sizefile.getline(tmpsizearr, 30, '|');
	size = atoi(tmpsizearr);
	sizefile.close();
	while (!file.eof())
	{
		item* newnode = new item;
		
		file.getline(newnode->name, 100, '|');
		file.getline(newnode->category, 100, '|');
		file.getline(newnode->ddate, 5, '|');
		file.getline(newnode->mdate, 5, '|');
		file.getline(newnode->ydate, 5, '|');
		file.getline(newnode->price, 100, '|');
		file.getline(newnode->spent, 100, '|');
		file.getline(newnode->remaining, 100);
		if (i == 0)
		head = tail = newnode;
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		i++;
	}
	file.close();
}

//Done by ME //TESTED
void Expenseslist::Return_all()
{
	item* temp = head;
	int i = 0;
	ofstream file, sizefile;
	file.open("items.txt", ios::out);
	while (!file.eof())
	{
		if (i == size)
			break;
		if (i == size - 1)
		{
			file << temp->name << '|' << temp->category << '|' << temp->ddate << '|' <<
				temp->mdate << '|' << temp->ydate << '|' << temp->price << '|' << temp->spent <<
				'|' << temp->remaining;
			temp = temp->next;
			i++;
			continue;
		}
		file <<temp->name << '|' << temp->category << '|' << temp->ddate << '|' <<
			temp->mdate << '|' << temp->ydate << '|' << temp->price << '|' << temp->spent <<
			'|' << temp->remaining<<'\n';
		temp = temp->next;
		i++;
	}
	file.close();

	string r = to_string(size);
	sizefile.open("sizefile.txt");
	sizefile << r << '|';
	sizefile.close();
}

//Done by ME //TESTED
void Expenseslist::Add_new_expense()
{
	item* newnode = new item;
	cout << "Please enter the name of item: ";
	cin >> newnode->name;
	//cin.ignore();
	cout << "Please enter the category of item: ";
	cin >> newnode->category;
	//cin.ignore();
	cout << "Please enter the Date that you bought this item"<<endl;
	cout << "Day: "; cin >> newnode->ddate; 
	cout << "Month: "; cin >> newnode->mdate; 
	cout << "Year: "; cin >> newnode->ydate; 
	cout << "Please enter the Price of item: ";
	cin >> newnode->price; 
	cout << "Please enter What you payed in this item: ";
	cin >> newnode->spent;
	int pric = atoi(newnode->price);
	int spen = atoi(newnode->spent);
	int rem = pric - spen;
	string r = to_string(rem);
	strcpy_s(newnode->remaining, r.c_str());
	if (size == 0)
	{
		head = tail = newnode;
	}
	else
	{
		tail->next = newnode;
		tail = newnode;
	}
	size++;
	cout << endl;
	cin.ignore();
}

//Done by ME //TESTED
void Expenseslist::Edit_expense()
{	
	item* temp = head;
	int choice;
	cout << "If you want to change the Name press---> 1" << endl;
	cout << "If you want to change the Category press---> 2" << endl;
	cout << "If you want to change the Date press---> 3" << endl;
	cout << "If you want to change the Price press---> 4" << endl;
	cout << "If you want to change the Spent press---> 5" << endl;
	cout << "please enter the chosen number: ";
	cin >> choice;
	bool flag = false;
	char nametmp[100];
	cout << "Please enter the name of the expense you'd like to edit: ";
	cin >> nametmp;
	if (choice == 1)
	{
		for (int i=0; i<size; i++)
		{
			if (strcmp(temp->name, nametmp) == 0)
			{
				cout << "Please enter the new name: ";
				cin >> temp->name;
				cout << "The name has been changed successfully!";
				return;
			}
			temp = temp->next;
		}		
		cout << "There is no such item with that name!";
	}
	else if (choice == 2)
	{
		for (int i = 0; i < size; i++)
		{
			if (strcmp(temp->name, nametmp) == 0)
			{
				cout << "Please enter the new category: ";
				cin >> temp->category;
				cout << "The category has been changed successfully!";
				return;
			}
			temp = temp->next;
		}
		cout << "There is no such item with that name!";
	}
	else if (choice == 3)
	{
		for (int i = 0; i < size; i++)
		{
			if (strcmp(temp->name, nametmp) == 0)
			{
				cout << "Please enter the new date: ";
				cout << "Day: "; cin>>temp->ddate;
				cout << "Month: "; cin >> temp->mdate;
				cout << "Year: "; cin >> temp->ydate;
				cout << "The date has been changed successfully!";
				return;
			}
			temp = temp->next;
		}
		cout << "There is no such item with that name!";
	}
	else if (choice == 4)
	{
		for (int i = 0; i < size; i++)
		{
			if (strcmp(temp->name, nametmp) == 0)
			{
				cout << "Please enter the new price: ";
				cin >> temp->price;
				cout << "The price has been changed successfully!";
				return;
			}
			temp = temp->next;
		}
		cout << "There is no such item with that name!";
	}
	else if (choice == 5)
	{
		for (int i = 0; i < size; i++)
		{
			if (strcmp(temp->name, nametmp) == 0)
			{
				cout << "Please enter the new spent amount: ";
				cin >> temp->spent;
				cout << "The category has been changed successfully!";
				int pric = atoi(temp->price);
				int spen = atoi(temp->spent);
				int rem = pric - spen;
				string r = to_string(rem);
				strcpy_s(temp->remaining, r.c_str());
				return;
			}
			temp = temp->next;
		}
		cout << "There is no such item with that name!";
		
	}
	else
	cout << "You entered a wrong number!";
}

//Done by me //TESTED
void Expenseslist::Delete_expense()
{
	item* temp = head, *previous = head;
	int i = 0;
	char n[100];
	bool flag = false;
	cout << "Please enter the Name of the item you wish to delete: ";
	cin.getline(n, 100);
	while (i < size)
	{
		if (strcmp(temp->name, n) == 0)
		{
			if (i == 0)
			{
				head = head->next;
				delete temp;
				cout << "The item has been deleted successfully!" << endl;
				size--;
				return;
			}
			previous->next = temp->next;
			delete temp;
			cout << "The item has been deleted successfully!" << endl;
			size--;
			return;
		}
		i++;
		previous = temp;
		temp = temp->next;
	}
	
	cout << "NO item is found with that name!" << endl;
}

//Done by ME //TESTED
void Expenseslist::Search_expense()
{
	item* temp = head;
	int op;
	int i = 0;
	bool flag = false;
	cout << "IF you want to Search by Name of item,Press---> 1 " << endl;
	cout << "IF you want to Search by Month of item,Press---> 2 " << endl;
	cout << "IF you want to Search by Category of item,Press---> 3 " << endl;
	cin >> op;
	cin.ignore();
	if (op == 1)
	{
		char n[100];
		cout << "Please enter then Name of item: ";
		cin.getline(n, 100);
		while (i < size)
		{
			if (strcmp(temp->name, n) == 0)
			{
				cout << "--------------------------------------------------------------"<<endl;
				cout << "The Name of item:" << temp->name << endl;
				cout << "The Category of item:" << temp->category << endl;
				cout << "The Date of purchasing the item:" << temp->ddate << "/" << temp->mdate << "/" << temp->ydate << endl;
				cout << "The Price of item:" << temp->price << endl;
				cout << "The Spent of item:" << temp->spent << endl;
				cout << "The Remaining of item:" << temp->remaining << endl;
				cout << "--------------------------------------------------------------"<<endl;
				flag = true;
			}
			i++;
			temp = temp->next;
		}
		if(!flag)
			cout << "Sorry,NO items Was in this Month !" << endl;
	}
	else if (op == 2)
	{
		char m[30];
		cout << "Please,Enter the Month of item: ";
		cin.getline(m, 30);
		while (i < size)
		{
			if (strcmp(temp->mdate, m) == 0)
			{
				cout << "--------------------------------------------------------------"<<endl;
				cout << "The Name of item:" << temp->name << endl;
				cout << "The Category of item:" << temp->category << endl;
				cout << "The Date of purchasing the item:" << temp->ddate << "/" << temp->mdate << "/" << temp->ydate << endl;
				cout << "The Price of item:" << temp->price << endl;
				cout << "The Spent of item:" << temp->spent << endl;
				cout << "The Remaining of item:" << temp->remaining << endl;
				cout << "--------------------------------------------------------------"<<endl;
				flag = true;
			}
			i++;
			temp = temp->next;
		}
		if (!flag)
			cout << "Sorry,NO items Was in this Month !" << endl;
	}
	else if (op == 3)
	{

		char c[30];
		cout << "Please,Enter the Category of item: ";
		cin.getline(c, 30);
		while (i < size)
		{
			if (strcmp(temp->category, c) == 0)
			{
				cout << "--------------------------------------------------------------"<<endl;
				cout << "The Name of item:" << temp->name << endl;
				cout << "The Category of item:" << temp->category << endl;
				cout << "The Date of purchasing the item:" << temp->ddate << "/" << temp->mdate << "/" << temp->ydate << endl;
				cout << "The Price of item:" << temp->price << endl;
				cout << "The Spent of item:" << temp->spent << endl;
				cout << "The Remaining of item:" << temp->remaining << endl;
				cout << "--------------------------------------------------------------"<<endl;
				flag = true;
			}
			i++;
			temp = temp->next;
		}
		if(!flag)
			cout << "Sorry,NO items Was in this category !" << endl;
	}
	else
	{
		cout << "You entered a Wrong Number" << endl;
	}
}

//Done by ME //TESTED
void Expenseslist::Display() 
{
	item* temp = head;
	cout << "--------------------------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "The item name: " << temp->name << endl;
		cout << "The item's Category: " << temp->category << endl;
		cout << "The item's date of purchase: " << temp->ddate << '/' <<
			temp->mdate << '/' << temp->ydate << endl;
		cout << "The item's price: " << temp->price << endl;
		cout << "Amount of money spent: " << temp->spent << endl;
		cout <<"Amount of money remaining: "<< temp->remaining<<endl;
		cout << "--------------------------------------------------------------------------"<<endl;
		temp = temp->next;
	}
}
