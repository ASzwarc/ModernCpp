#pragma once
#include <iostream>
//#include <string>

class Employee
{
public:
	//Constructor and destructor
	Employee(std::string name, int salary, int bonusSalary, int workingDaysCount, int ID); 
	Employee(const Employee& empl);
	~Employee();

	//Simple getters and setters
	int GetSalary() const;
	void SetSalary(int amount);

	int AddBalance(int amount);

	//Simple getters and setters
	int GetBonusSalary()const;
	void SetBonusSalary(int amount);

	//Simple getters and setters
	std::string GetName()const;
	void ChangeName(std::string name);

	//Simple getters and setters
	int GetWorkingDaysCount() const;
	void SetWorkingDaysCount(int count);

	//Returns this employee's ID
	int GetID() const;

private:
	int ID;
	int salary;
	int bonusSalary;
	int balance = 0;
	int workingDaysCount;
	std::string name;
};