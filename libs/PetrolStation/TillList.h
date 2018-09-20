#pragma once
#include "Till.h"
class TillList
{
public:
	//TillList has its own 
	TillList();
	~TillList();
	TillList(const TillList& newTill);
	TillList& operator=(const TillList& newTill);

	//Returns pointer to the Till of particular ID
	Till* FindTill(int ID)const;
	//Returns a pointer to a first open till
	Till* FindFirstOpenTill()const;
	//Tells us whether the Till of current ID is open, if a till of particular ID does not exist it returns false
	bool CheckTillIsOpen(int ID);

	//These functions are called by the owning PetrolStation instance to operate on particular Till, i.e. close it/ open
	int OpenTill(int ID);
	int CloseTill(int ID);
	int CheckoutAllTills();
	int CloseAllTills();

	int GetTotalMoneyInTills();
	//These functions are responsible for managing the tills in the List
	//They keep the list sorted by ID for convenience
	//If we add Till by the same ID they return int value -1
	int AddTill(const Till& till);
	int AddTill(int ID, int maxCash, int currentCash);

	//Removes a Till of particular ID from the list, returns an integer value which tells us whether we successfully removed the till or not (1 for an error, 0 for a success)
	int RemoveTill(Till* till);
	int RemoveTill(int ID);

	//These functions are for making the assignment operator more simple
	void RemoveAllElements();
	void CopyAllElements(const TillList& othertill);

	//Returns the total amount of Tills associated with this list
	int GetTillCount()const;

	
private:
	Till* head = nullptr;
	int count;
};