#include "PetrolStation.h"
using namespace std;
int main()
{
	//TESTING

	//Create a couple of stations - they should
	PetrolStation* petrol1 = new PetrolStation("Benzin1", 1);
	PetrolStation* petrol2 = new PetrolStation("Octan2", 2);

	//Testing empty cases
	cout << "Empty cases" << endl;
	cout << petrol2->GetBalance() << endl;
	cout <<petrol2->CloseTill(2) << endl;
	cout <<petrol2->CheckoutTill(23) << endl;
	cout <<petrol2->GetCurrentOpenTillsCount() << endl;
	cout <<petrol2->GetMaximumTills() << endl;
	cout <<petrol2->GetMoneyInTill(234) << endl;
	cout <<petrol2->RemoveTill(13) << endl;
	cout << petrol2->GetEmployeeCount() << endl;
	cout << petrol2->GetEmployeeName(1) << endl;
	cout << petrol2->GetEmployeeBonusSalary(2) << endl;
	cout << petrol2->GetEmployeeSalary(100) << endl;
	cout << petrol2->GetDepotFuelType(2) << endl;
	cout << petrol2->GetEmployeeWorkingDaysCount(234) << endl;
	cout << petrol2->ChangeEmployeeName(2, "Bob") << endl;



	//PETROL1 BLOCK
	//Adding Employees
	cout << endl << endl << endl << "Adding Employees" << endl;
	petrol1->AddEmployee("John", 100, 200, 3, 1);
	petrol1->AddEmployee("Barbara", 200, 300, 4, 2); //test selling buying logic!~!!!!!!!!!!!!!! add cout everywhere and make it coherent plox jacob ju ken du it
	petrol1->AddEmployee("Tadeus", 130, 560, 4, 3);
	cout << petrol1->RemoveEmployee(1) << endl;
	cout << "Removing nonexistent Employee: " << petrol1->RemoveEmployee(4) << endl;
	//Removing nonexistent Employee
	//Change Employee's parameters
	cout << "Change name from " << petrol1->GetEmployeeName(2) << " to: ";
	petrol1->ChangeEmployeeName(2, "Stepan");
	cout << petrol1->GetEmployeeName(2) << endl;
	petrol1->SetEmployeeBonusSalary(2, 200);
	petrol1->SetEmployeeWorkingDaysCount(2, 4);
	petrol1->SetEmployeeSalary(2, 100);

	//Get the data
	cout << endl << "Get all the data for employee ID: 2" << endl;
	cout << "Name: " << petrol1->GetEmployeeName(2) << endl;
	cout << "Salary: "<<petrol1->GetEmployeeSalary(2) << endl;
	cout << "BonusSalary: "<<petrol1->GetEmployeeBonusSalary(2) << endl;
	cout << "Working Days count: " << petrol1->GetEmployeeWorkingDaysCount(2) << endl;

	cout << endl<<endl<<"Adding and removing depots " << endl;
	//Adding different depots to the station
	petrol1->AddDepot(1, 300, FuelType::Diesel);
	petrol1->AddDepot(2, 400, FuelType::EkoDiesel);
	petrol1->AddDepot(3, 400, FuelType::Pb95);
	petrol1->AddDepot(4, 300, FuelType::Pb98);
	petrol1->AddDepot(5, 500, FuelType::TurboDiesel);
	petrol1->AddDepot(6, 100, FuelType::N02);
	//Removing one depot to make some restrictions
	cout << "Removing existing depot: "<<petrol1->removeDepot(3) << endl;
	cout << "Checking if nonexistent depot is open: " << petrol1->isDepotWorking(3) << endl;
	cout << "Balance after Adding fuel: " << endl;
	petrol1->AddFuel(FuelType::Diesel, 300); //DIESEL = 300
	petrol1->AddFuel(FuelType::EkoDiesel, 400); //EKODIESEL = 400
	cout << petrol1->GetBalance() << endl;
	//Adding nonexistent fuel type
	cout << "Balance after Adding nonexistent fuel type: " << endl;
	petrol1->AddFuel(FuelType::Pb95, 100);
	cout << petrol1->GetBalance() << endl;
	
	cout << endl << endl << "Adding tills" << endl;
	petrol1->AddTill(1, 10000, 500);
	petrol1->AddTill(2, 3000, 300); 
	petrol1->AddTill(4, 2000, 0);
	petrol1->AddTill(3, 10000, 2000);

	cout << "Removing an existing till: " << petrol1->RemoveTill(2) << endl;
	//removing nonexistent
	cout << "Removing nonexistent till: " << petrol1->RemoveTill(0) << endl;

	petrol1->AddTill(2, 3000, 500);



	//Get all the data
	cout << endl << endl << "Getting data from petrolstation 1: " << endl;
	cout << "Balance: "<<petrol1->GetBalance() << endl;
	cout << "EkoDiesel buy cost: " << petrol1->GetBuyCost(FuelType::EkoDiesel) << endl;
	cout <<"Current open tills count: " << petrol1->GetCurrentOpenTillsCount() << endl;
	cout << "Employee count: " <<petrol1->GetEmployeeCount() << endl;
	cout << "Station's ID: " <<petrol1->GetID() << endl;
	cout << "Maximum tills count :" <<petrol1->GetMaximumTills() << endl;
	cout << "NO2 sell cost: " <<petrol1->GetSellCost(FuelType::N02) << endl;
	cout << "Name :" << petrol1->GetName() << endl;

	//Creating Clients
	cout << endl<<endl<< "Creating and testing clients data: " << endl;
	Client* client1 = new Client(1, 0);
	Client* client2 = new Client(2, 0);
	Client* client3 = new Client(*client2);
	cout << "Client1 ID: " << client1->GetID() << endl;
	cout << "Client2 totalClientcount: " << client2->GetTotalCount() << endl;
	cout << "Client3 fueledamount: " << client3->GetFueledAmount() << endl;

	//Getting data about Depots
	cout << endl << endl << "Getting data about Depots" << endl;
	cout << "Current fuel amount Depot1 : " << petrol1->GetDepotCurrentFuelAmount(1) << endl;
	cout << "Max fuel amount Depot1 : " << petrol1->GetDepotMaxFuelAmount(1) << endl;
	cout << "Is it working Depot1 : " << petrol1->isDepotWorking(1) << endl;
	cout << "FuelType Depot1 : " << petrol1->GetDepotFuelType(1) << endl;

	//Emptying empty tills
	cout << endl<<endl<<"Emptying empty Tills" << endl;
	cout << petrol1->CheckoutTill(0) << endl; 
	cout << petrol1->CheckoutTill(100) << endl;

	//Performing cash operations
	cout << endl << endl << "Performing cash operations" << endl;
	cout << "Selling fuel to client1: " << petrol1->SellFuel(*client1, 400, FuelType::EkoDiesel) << endl;
	cout << "Balance after operation: " << petrol1->GetBalance() << endl;
	cout << "Cash in till after operation :" << petrol1->GetMoneyInTill(1) << endl;
	//Try to buy from an empty fuel depot
	cout << "Trying to sell fuel from empty depot to client1: " << petrol1->SellFuel(*client1, 100, FuelType::EkoDiesel) << endl;
	cout << "Balance after operation: " << petrol1->GetBalance() << endl;
	cout << "Cash in till after operation :" << petrol1->GetMoneyInTill(1) << endl;
	cout << "Trying to sell Diesel to client3: " << petrol1->SellFuel(*client3, 200, FuelType::Diesel)<< endl;
	cout << "Balance after operation: " << petrol1->GetBalance() << endl;
	cout << "Cash in till after operation :" << petrol1->GetMoneyInTill(1) << endl;
	cout << "Trying to sell fuel from empty depot to client1: " << petrol2->SellFuel(*client1, 400, FuelType::Pb95) << endl;
	cout << "Balance after operation: " << petrol1->GetBalance() << endl;
	cout << "Cash in till after operation :" << petrol1->GetMoneyInTill(1) << endl;
	//Try to sell fuel station does not currently have
	cout << "Try to sell fuel station does not currently have: " << petrol1->SellFuel(*client2, 200, FuelType::N02) << endl;
	cout << "Balance after operation: " << petrol1->GetBalance() << endl;
	cout << "Cash in till after operation :" << petrol1->GetMoneyInTill(1) << endl;	
	//Try to buy fuel amout above capacitance of a fuel depot
	cout << "Try to buy fuel amout above capacitance of a fuel depot: " << petrol2->AddFuel(FuelType::N02, 1000) << endl;
	cout << "Balance after operation: " << petrol1->GetBalance() << endl;
	cout << "Cash in till after operation :" << petrol1->GetMoneyInTill(1) << endl;

	cout << endl << "Checking out till 1" << endl;
	cout << petrol1->CheckoutTill(1) << endl << endl;

	cout << "Refuelling Diesel depot " << endl;
	cout << petrol1->AddFuel(FuelType::Diesel, 200) << endl << endl;
	cout << "Selling fuel from diesel depot to client1: " << petrol1->SellFuel(*client2, 200, FuelType::Diesel) << endl;
	cout << "Balance after operation: " << petrol1->GetBalance() << endl;
	cout << "Cash in till after operation :" << petrol1->GetMoneyInTill(1) << endl;
	
	//Removing an existing till
	cout << endl<<endl<<"Removing an existing till: " << petrol1->RemoveTill(1) << endl;
	cout << "Balance after closing a till: " << petrol1->GetBalance() << endl;

	//refuel all depots
	cout << endl << endl << "Refuelling all depots: " << petrol1->RefuellAll() << endl;
	cout << "Balance after refuelling all depots: " << petrol1->GetBalance() << endl;
	//checkout all tills
	cout << endl << endl << "Checking out all tills: " << petrol1->CheckoutAllTills()<< endl;
	cout << "Balance after checking out all tills: " << petrol1->GetBalance() << endl;

	//closing all tills
	cout << endl << endl << "Closing all tills:  " << petrol1->CloseAllTills() << endl;
	cout << "Balance after closing all tills:  " << petrol1->GetBalance() << endl;
	//pay employees their salary
	cout << endl << endl << "Paying all employees: " << petrol1->PayAllEmployees() << endl;
	cout << "Balance after paying all employees: " << petrol1->GetBalance() << endl;


	delete petrol1; 
	delete petrol2;
	delete client1;
	delete client2;
	delete client3;
	return 0;
}