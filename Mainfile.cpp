#include <iostream>
#include "Expenseslist.h"
using namespace std;
int main()
{
	Expenseslist x1;
	x1.Generate_all();
	x1.Display();
	x1.Delete_expense();
	x1.Delete_expense();
	x1.Return_all();
}