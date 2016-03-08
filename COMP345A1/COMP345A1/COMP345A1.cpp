// COMP345A1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Player.h"
#include "SummaryCard.h"
#include "PowerPlantsMarket.h"
#include "ResourceMarket.h"


void BuyResource(ResourceMarket* aResourceMarket, Player* aPlayer){
	string stringOfResource[] = { "Coal", "Oil", "Garbage", "Uranium" };

	for (int i = 0; i < NumTypeOfResource; i++){
		cout << aPlayer->GetName() << ": how many " << stringOfResource[i] << " you want to buy?" << endl;
		int quantity;
		cin >> quantity;
		aResourceMarket->buyResource(aPlayer, TypeOfResource(i), aPlayer->BuyResource(TypeOfResource(i), quantity));
	}

}

void BuyPowerPlant(PowerPlantsMarket* aPowerPlantsMarket){

}



int _tmain(int argc, _TCHAR* argv[])
{
	Player *p1, *p2;

	cout << "Please input p1 name: " << endl;	
	string tempName;
	cin >> tempName;
	p1 = new Player(tempName);

	cout << "Please input p2 name: " << endl;
	cin >> tempName;
	p2 = new Player(tempName);

	p1->display();
	p2->display();

	cout << "Add money to players: " << endl;
	p1->GetPossession()->AddMoney(100);
	p2->GetPossession()->AddMoney(100);

	p1->display();
	p2->display();

	cout << "Players buy house: " << endl;
	p1->GetPossession()->BuyHouse(80);
	p2->GetPossession()->BuyHouse(150);

	p1->display();
	p2->display();

	//---------------Distinct part 2------------------------------------------------------------------------

	for (int i = 0; i < 10; i++){
		p1->GetPossession()->BuyHouse(0);
		p2->GetPossession()->BuyHouse(0);
	}

	p1->display();
	p2->display();

	SummaryCard *mySummaryCard;
	mySummaryCard = new SummaryCard();

	mySummaryCard->EarnMoney(p1, 8);
	mySummaryCard->EarnMoney(p2, 12);

	p1->display();
	p2->display();



	PowerPlantsMarket *aPowerPlantsMarket = new PowerPlantsMarket();
	aPowerPlantsMarket->displayDrawStack();
	aPowerPlantsMarket->displayPowerPlantsMarket();

	cout << endl;
	PowerPlantCard theChosenForAuction = aPowerPlantsMarket->ChooseAPowerPlantForAuction(2);
	aPowerPlantsMarket->displayPowerPlantsMarket();
	p1->buyPowerPlant(theChosenForAuction, 10);

	aPowerPlantsMarket->ReSupplyPowerPlantsMarket();
	aPowerPlantsMarket->displayDrawStack();
	aPowerPlantsMarket->displayPowerPlantsMarket();

	ResourceMarket  *aResourceMarket = new ResourceMarket();

	BuyResource(aResourceMarket, p1);
	p1->display();






	getchar();
	getchar();
	return 0;
}


