#pragma once

class Till
{
public:
	//These are two types of constructors (copy and instance)
	//all Tills are by default open when they are created thus we do not have to explicitly specify if it is open or not
	Till(int ID, int maxCash, int currentCash);
	Till(const Till& oldTill);
	//Upon being destroyed, destructor transfers all the cash to the PetrolStation instance
	~Till();

	//These functions are responsible for managing the cash in this instance of till, they return special integer value to tell us which type of error we are facing (if any)
	//Tills cannot be cashed out below their current cash amount or overfilled with cash thus we can return different integer value to differ between these two states (for now 1 is overcash -1 is undercash)
	int DepositCash(int amount);
	int DrawCash(int amount);
	//Returns current cash amount in the particular Till
	int GetCurrentCash()const;
	//Returns max cash
	int GetMaxCash()const;
	//Returns the ID
	int GetID()const;
	
	//Tells us whether this till is open or not
	bool IsOpen()const;

	//these functions are responsible for closing and opening the Till
	void Open();
	void Close();

	void SetNext(Till* ptr);
	Till* GetNext(); 


private:
	int ID;
	int maxCash;
	int currentCash;
	bool isOpen;
	Till* next = nullptr;
};