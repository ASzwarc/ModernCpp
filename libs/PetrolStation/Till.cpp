#include "Till.h"

Till::Till(int ID, int maxCash, int currentCash) : ID(ID), maxCash(maxCash), currentCash(currentCash)
{
	
}

Till::Till(const Till & oldTill) : ID(oldTill.ID), maxCash(oldTill.maxCash), currentCash(0)
{
	
}


Till::~Till()
{
	DepositCash(currentCash);
}

int Till::DepositCash(int amount)
{
	if (currentCash + amount <= maxCash)
	{
		currentCash += amount;
		return 0;
	}
	else
	{
		return -1;
	}
}

int Till::DrawCash(int amount)
{
	if (currentCash - amount >= 0)
	{
		currentCash -= amount;
		return 0;
	}
	else
	{
		return -1;
	}
}

int Till::GetCurrentCash() const
{
	return currentCash;
}

int Till::GetMaxCash() const
{
	return maxCash;
}

int Till::GetID() const
{
	return ID;
}

bool Till::IsOpen() const
{
	return isOpen;
}

void Till::Open()
{
	isOpen = true;
}

void Till::Close()
{
	isOpen = false;
}

void Till::SetNext(Till * ptr)
{
	next = ptr;
}

Till * Till::GetNext()
{
	return next;
}
