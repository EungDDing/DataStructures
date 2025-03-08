#include <iostream>
#include <cstring>
#include "CirckeLinkedList.h"
#include "Employee.h"
using namespace std;

char* ShowDutyEmployee(CircleLinkedList<Employee*>& list, const char* empName, int day)
{
	char* name = new char[strlen(empName) + 1];
	strcpy(name, empName);
	Employee* data;

	int i;
	int num = list.LCount();

	list.LFirst(data);

	if (strcmp(data->GetName(), name) != 0)
	{
		for (i = 0; i < num - 1; i++)
		{
			list.LNext(data);

			if (strcmp(data->GetName(), name) == 0)
				break;
		}
		if (i >= num - 1)
			return nullptr;
	}

	for (i = 0; i < day; i++)
		list.LNext(data);

	return data->GetName();
}

int main(void)
{
	CircleLinkedList<Employee*> list;
	Employee* data;

	data = new Employee("유재석", 12345);
	list.LInsert(data);
	data = new Employee("강호동", 42639);
	list.LInsert(data);
	data = new Employee("신동엽", 53806);
	list.LInsert(data); 
	data = new Employee("이경규", 87536);
	list.LInsert(data);

	if (list.LFirst(data))
	{
		cout << data->GetName() << ", " << data->GetNumber() << endl;
		for (int i = 0; i < list.LCount() * 3 - 1; i++)
		{
			if (list.LNext(data))
				cout << data->GetName() << ", " << data->GetNumber() << endl;
		}
	}
	cout << endl;

	cout << ShowDutyEmployee(list, "이경규", 7);
	return 0;
}