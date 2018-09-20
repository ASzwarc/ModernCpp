#pragma once
#include "Depot.h"
#include "Client.h"
#include "TillList.h"
#include <vector>

class PetrolStation
{
public:
	PetrolStation(std::string name, int ID);
	~PetrolStation();
	//Functions responsible for adding and removing employees from employeevec associated with this instance of PetrolStation
	//There are two Add functions because we can add either by creating a new employee or adding a copy of already existent one
	void AddEmployee(std::string name, int salary, int bonusSalary, int workingDaysCount, int ID);
	void AddEmployee(const Employee& emp);
	//Removing is performed by ID only, the corresponding employee is looked up in the employeevec and then removed
	int RemoveEmployee(int ID);
	//Returns the current amount of employees assigned to this particular station
	int GetEmployeeCount() const;
	//Functions that make possible to perform operations on employee
	//int value of -1 means there is no such employee, 0 means success
	int GetEmployeeSalary(int ID);
	int SetEmployeeSalary(int ID, int amount);
	int GetEmployeeBonusSalary(int ID);
	int SetEmployeeBonusSalary(int ID, int amount);
	std::string GetEmployeeName(int ID);
	int ChangeEmployeeName(int ID, std::string name);
	int GetEmployeeWorkingDaysCount(int ID);
	int SetEmployeeWorkingDaysCount(int ID, int count);
	//Pays employee his monthly salary + bonussalary
	int PayEmployee(int ID);
	int PayAllEmployees();

	//These functions are responsible for adding and removing Depots from the depotMap, similarly as with employees they can be constructed in two distinct ways
	void AddDepot(const Depot& depot);
	void AddDepot(int ID, int maxAmount, FuelType fuelType);
	//Removes a depot from depotMap by its ID
	int removeDepot(int ID);
	bool isDepotWorking(int ID);
	std::string GetDepotFuelType(int ID);
	//Returns the capacitance of this particular fuel depot
	int GetDepotMaxFuelAmount(int ID);
	//Returns the current fuel amount in depot
	int GetDepotCurrentFuelAmount(int ID);


	//Returns the station's name
	std::string GetName() const;
	//Returns the station's ID
	int GetID()const;
	//Returns total balance of this instance of PetrolStation
	long unsigned int GetBalance() const;
	//Returns current amount of open tills in tillList
	int GetCurrentOpenTillsCount() const;
	//Returns total amount of tills assigned to this station (both open and closed)
	int GetMaximumTills() const;

	//These methods are responsible for managing(adding and removing tills from the TillList)
	void AddTill(int ID, int maxCash, int currentCash);
	void AddTill(const Till& till);
	int RemoveTill(int ID);

	//These functions are called to open/close or checkout a till of particular ID
	int OpenTill(int ID);
	int CloseTill(int ID);
	int CheckoutTill(int ID);
	int GetMoneyInTill(int ID);
	int CheckoutAllTills();
	int CloseAllTills();

	//Most prominent function - it performs purchasing of fuel by a Client and adequately calls all other functions responsible for fuel/money management
	//It searches for the first open till and performs cash operations on it, it also searches for first open depot of the required FuelType
	//It returns integer value because we may be unable to perform required fuel withdrawal operation due to lack of fuel (1 for failure and 0 for success)
	int SellFuel(const Client& client, int amount, FuelType type);

	//This function is the counterpart of SellFuel function, it is responsible for refuelling empty depots, it's integer return value (1 for failure and 0 for success), because
	//we may be unable to perform that operation, due to lack of particular fuel type depots or volume in our depots
	//this function substracts the special amount of money required to buy fuel from our total balance (we assume that prices are constant and perform a switch statement on fuelType)
	int AddFuel(FuelType fuelType, int amount);
	//Refuels all depots
	int RefuellAll();

	//These functions return the cost of deemed type of fuel dependent on current course of petrol type
	int GetSellCost(const FuelType type)const;
	int GetBuyCost(const FuelType type)const;
	


private:
	int ID;
	int employeeCount = 0;
	std::string name;
	std::vector<Client> clientvec;
	std::vector<Employee> employeevec;
	std::vector<Depot> depotvec;
	TillList* tillList = nullptr;
	int currentOpenTillsCount;
	long unsigned int balance = 10000; //they start with some balance
	int totalFuel = 0; 
	int sellPrices[6] = { 4, 5, 6, 3, 4, 10 };
	int buyPrices[6] = { 2, 3, 4 , 1, 1, 6 };
	//Returns index of given employee in the vector or returns -1 to indicate there is no such employee
	int GetEmployeeIndex(int ID);
	int GetDepotIndex(int ID);
	//Returns employee under given index, or if there is none we change data of the arbitrary 0th employee
	//Employee& GetEmployeeUnderIndex(int index);
};