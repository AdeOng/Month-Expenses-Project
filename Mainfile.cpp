#include <iostream>
#include "Expenseslist.h"
#include<string>
#include<string.h>
#include <cstdlib>
#include <stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	Expenseslist x1;
	x1.Generate_all();
	
	string ans;
	do {

		cout << "\n\n\t\t\t" << "WELCOME TO THE MONTH'S EXPENSES PROGRAM\n\n";
		cout << "\n\nPlease Choose The Desired Operation :-\n\n";
		cout << "1-> Add a New Expense\t\t";       cout << "2-> Search for an Expense\n\n";
		cout << "3->Delete an Expense\t\t";        cout << "4-> Edit an Expense\n\n";
		cout << "5->Display an Expense\t\t\n";
		int oper;
		cout << "Number: ";
		cin >> oper;
		cin.ignore();
		switch (oper)
		{
		case 1:
			x1.Add_new_expense();
			break;
		case 2:
			x1.Search_expense();
			break;
		case 3:
			cout << "LESA" << endl;
			break;
		case 4:
			x1.Edit_expense();
			break;
		case 5:
			x1.Display();
			break;
		default:
			cout << "Sorry,You Entered Wrong Number" << endl;
			break;
		}
		cout << "\nDo You Want To Perform Another Operation ?\n";
		cin >> ans;
		transform(ans.begin(), ans.end(), ans.begin(), ::tolower);
		system("CLS");
	} while (ans == "yes");
		cout << "Thank YOU!!!!!";
	x1.Return_all();
}