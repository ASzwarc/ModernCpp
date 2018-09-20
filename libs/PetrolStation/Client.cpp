#include "Client.h"

int Client::count = 0;

Client::Client(): ID(count)
{
	count++;
}

Client::Client(int ID, int fueled) : ID(ID), fueled(fueled)
{

}

int Client::GetFueledAmount() const
{
	return fueled;
}

int Client::AddFueledAmount(int amount)
{
	if (amount < 0) { return -1; }
	fueled += amount;
	return 0;
}

int Client::GetTotalCount() const
{
	return count;
}

int Client::GetID() const
{
	return ID;
}


