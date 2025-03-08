#pragma once
#include <cstring>

class Employee
{
private:
	char* name;
	int number;
public:
	Employee()
	{
		name = nullptr;
		number = 0;
	}
	Employee(const char* str, int num) : number(num)
	{
		name = new char[strlen(str) + 1];
		strcpy(name, str);
	}
	char* GetName() const
	{
		return name;
	}
	int GetNumber() const
	{
		return number;
	}
	~Employee()
	{
		delete[] name;
	}
};