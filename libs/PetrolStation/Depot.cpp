#include "Depot.h"

Depot::Depot(int ID, int maxAmount, FuelType fuelType) : ID(ID), maxFuelAmount(maxAmount), currentFuelAmount(0), type(fuelType)
{
	
}

Depot::Depot(const Depot & oldDepot) : ID(oldDepot.ID), maxFuelAmount(oldDepot.maxFuelAmount), currentFuelAmount(0), type(oldDepot.type)
{
}

int Depot::ReFuel(int amount)
{
	if (currentFuelAmount + amount <= maxFuelAmount)
	{
		currentFuelAmount += amount; 
		return 0;
	}
	else
	{
		return -1;
	}
}

int Depot::DeFuel(int amount)
{
	if (currentFuelAmount - amount >= 0)
	{
		currentFuelAmount -= amount;
		return 0;
	}
	else
	{
		return -1;
	}
}

void Depot::Repair()
{
	isWorking = true;
}

void Depot::Break()
{
	isWorking = false;
}

bool Depot::IsWorking() const
{
	return isWorking;
}

int Depot::GetID() const
{
	return ID;
}

int Depot::GetMaxFuelAmount() const
{
	return maxFuelAmount;
}

int Depot::GetCurrentFuelAmount() const
{
	return currentFuelAmount;
}

FuelType Depot::GetFuelType() const
{
	return type;
}

std::string Depot::GetFuelTypeString() const
{
	switch (type)
	{
	case FuelType::Diesel:
		return "Diesel";
	case FuelType::EkoDiesel:
		return "EkoDiesel";
	case FuelType::Pb95:
		return "Pb95";
	case FuelType::Pb98:
		return "Pb98";
	case FuelType::TurboDiesel:
		return "TurboDiesel";
	case FuelType::N02:
		return "N02";
	}
}
