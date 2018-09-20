#include "TillList.h"

TillList::TillList() : count(0), head(nullptr)
{
}

TillList::~TillList()
{
	RemoveAllElements();
}

TillList::TillList(const TillList & newTill)
{
	CopyAllElements(newTill);
}

TillList & TillList::operator=(const TillList & newTill)
{
	if (this == &newTill)
	{
		return *this;
	}
	RemoveAllElements();
	CopyAllElements(newTill);
	return *this;
}

Till * TillList::FindTill(int ID) const
{
	Till* tillptr = head;
	Till* tmp = head;
	while (tillptr)
	{
		if (tillptr->GetID() == ID)
		{
			return tillptr;
		}
		tmp = tillptr->GetNext();
		tillptr = tmp;
	}
	return nullptr;
}

Till * TillList::FindFirstOpenTill() const
{
	Till* tillptr = head;
	Till* tmp = head;
	while (tillptr)
	{
		if (tillptr->IsOpen())
		{
			return tillptr;
		}
		tmp = tillptr->GetNext();
		tillptr->SetNext(tmp);
	}
	return nullptr;
}

bool TillList::CheckTillIsOpen(int ID)
{
	Till* tillptr = FindTill(ID);
	return tillptr->IsOpen();
}

int TillList::OpenTill(int ID)
{
	Till* tillptr = FindTill(ID);
	if (!tillptr)
	{
		return -1;
	}
	tillptr->Open();
	return 0;
}

int TillList::CloseTill(int ID)
{
	Till* tillptr = FindTill(ID);
	if (!tillptr)
	{
		return -1;
	}
	tillptr->Close();
	return 0;
}

int TillList::CheckoutAllTills()
{
	Till* tillptr = head;
	while (tillptr)
	{
		int currcash = tillptr->GetCurrentCash();
		tillptr->DrawCash(currcash);
		tillptr = tillptr->GetNext();
	}
	return 0;
}

int TillList::CloseAllTills()
{
	Till* tillptr = head;
	while (tillptr)
	{
		tillptr->Close();
		tillptr = tillptr->GetNext();
	}
	return 0;
}

int TillList::GetTotalMoneyInTills()
{
	Till* tillptr = head;
	int money = 0;
	while (tillptr)
	{
		money += tillptr->GetCurrentCash();
		tillptr = tillptr->GetNext();
	}
	return money;
}

int TillList::AddTill(const Till & till)
{
	return AddTill(till.GetID(), till.GetMaxCash(), till.GetCurrentCash());
}

int TillList::AddTill(int ID, int maxCash, int currentCash)
{
	Till* tillptr = head;
	Till* tmp = head;
	Till* prev;
	if (!head) 
	{
		head = new Till(ID, maxCash, currentCash);
		head->SetNext(nullptr);
		count++;
		return 0;
	}
	while (tillptr)
	{
		int oldID = tillptr->GetID();
		if (oldID == ID)
		{
			return -1;
		}
		else if (ID < head->GetID()) //Insert at the beggining
		{
			head = new Till(ID, maxCash, currentCash);
			head->SetNext(tmp);
			count++;
			return 0;
		}
		else if (ID < oldID) //insert somewhere before 
		{
			tmp = new Till(ID, maxCash, currentCash);
			prev->SetNext(tmp);
			tmp->SetNext(tillptr);
			count++;
			return 0;
		}
		prev = tillptr;
		tmp = prev->GetNext();
		tillptr = tmp;
	}
	//insert at the end
	tmp = new Till(ID, maxCash, currentCash);
	prev->SetNext(tmp);
	tmp->SetNext(nullptr);
	count++;
	return 0;
}

int TillList::RemoveTill(Till * till)
{
	int statusCode = RemoveTill(till->GetID());
	return statusCode;
}

int TillList::RemoveTill(int ID)
{
	Till* prevTill = FindTill(ID - 1);
	Till* tillToRemove = FindTill(ID);
	Till* tmp = head;
	Till* tmp2 = head;
	if (!tillToRemove)
	{
		return -1;
	}
	if (tillToRemove == head)
	{
		tmp2 = head->GetNext();
		tillToRemove = head;
		head = tmp2;
		delete tillToRemove;
		count--;
		return 0;
	}
	else if (!tillToRemove->GetNext())
	{
		prevTill->SetNext(nullptr);
		delete tillToRemove;
		count--;
		return 0;
	}
	prevTill->SetNext(tillToRemove->GetNext());
	delete tillToRemove;
	count--;
	return 0;
}

void TillList::RemoveAllElements() 
{
	Till* tillptr = head;
	Till* tmp = head;
	Till* tmp2 = head;
	while (tillptr)
	{
		tmp = tillptr;
		tmp2 = tillptr->GetNext();
		tillptr = tmp2;
		delete tmp;
	}
	count = 0;
	return;
}

void TillList::CopyAllElements(const TillList & othertill)
{
	Till* tillptr = head;
	Till* otherptr = othertill.head;
	Till* tmp2 = head;
	if (othertill.head == nullptr)
	{
		this->head = nullptr;
		return;
	}
	while (otherptr)
	{
		Till* tmp = new Till(*otherptr);
		if (head == nullptr)
		{
			head = tmp;
			head = head->GetNext();
			continue;
		}
		tillptr = tmp;
		tmp2 = tillptr->GetNext();
		tillptr->SetNext(tmp2);
		otherptr = otherptr->GetNext();
	}
	return;
}

int TillList::GetTillCount() const
{
	return count;
}
