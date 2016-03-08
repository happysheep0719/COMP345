#pragma once
#include "stdafx.h"
#include "playerPossession.h"
#include "PowerPlantCard.h"


class Player
{
public:
	Player();
	Player(string inputName);
	~Player();
	playerPossession* GetPossession();
	string GetName();
	void display();
	void displayAllPowerPlantCards();
	void displayAllResources();

	void buyPowerPlant(PowerPlantCard aPowerPlant, int pay);
	
	int BuyResource(TypeOfResource type, int quantity);

	void AddResource(TypeOfResource type, int quantity);
	

private:
	// char* name; // string name // *(name+2)=name[2]
	string name;
	playerPossession *myPossession; // own house num, money
	vector<PowerPlantCard> mPowerPlants; // power plant cards

	int resourceNum[NumTypeOfResource];
};


