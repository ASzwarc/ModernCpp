#pragma once
#include "Employee.h"

class Client
{
public:
	//Constructor and Destructor
	Client();
	Client(int ID, int fueled);
	
	//Returns the total amount of fuel this particular client has bought 
	int GetFueledAmount()const;

	//Adds to the amount of the fuel this client has bought
	int AddFueledAmount(int amount);

	//Returns the total amount of clients instantiated - it returns static variable
	int GetTotalCount()const;

	//Returns the ID of this particular client
	int GetID()const;
private:
	static int count;
	int ID;
	int fueled;
};