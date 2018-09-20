#pragma once
#include <string>

enum class FuelType
{
	Diesel,
	TurboDiesel,
	EkoDiesel,
	Pb95,
	Pb98,
	N02
};

static std::string fuelString[]{
	"Diesel", "TurboDiesel", "EkoDiesel", "Pb95", "Pb98", "N02"
};

class Depot
{
public:
	//These are two types of constructors (copy and instance)
	Depot(int ID, int maxAmount, FuelType fuelType);
	Depot(const Depot& oldDepot); 

	//These methods are responsible for maintaining fuel in the depot, if there is an error they mark it by returning special integer value
	//Depots cannot be overfueled or underfueled thus we can return different integer value to differ between these two states (for now 1 is overfuel -1 is underfuel)
	int ReFuel(int amount);
	int DeFuel(int amount);

	//These methods are responsible for repairing and breaking the depot 
	//they are used to simulate real life events that can cause the depot to malfunction
	void Repair();
	void Break();

	//This boolean function tells us whether the current depot is working or not
	bool IsWorking()const;

	//Returns the ID of the depot instance
	int GetID()const;
	//Returns the capacitance of this particular fuel depot
	int GetMaxFuelAmount()const;
	//Returns the current fuel amount in depot
	int GetCurrentFuelAmount()const;
	//Returns the FuelType of this particular fuel depot
	FuelType GetFuelType()const;

	std::string GetFuelTypeString()const;

private:
	int ID;
	int maxFuelAmount;
	int currentFuelAmount;
	FuelType type;
	bool isWorking = true;
};