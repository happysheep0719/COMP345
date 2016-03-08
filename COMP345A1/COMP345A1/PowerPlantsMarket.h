#pragma once
#include "stdafx.h"
#include "PowerPlantCard.h"
#include "Player.h"

class PowerPlantsMarket
{
public:
	PowerPlantsMarket();
	~PowerPlantsMarket();

	void InitializePowerPlantsMarket();
	PowerPlantCard ChooseAPowerPlantForAuction(int index); // return the chosen PowerPlantCard
	
	void ReSupplyPowerPlantsMarket();


	void displayDrawStack();	
	void displayPowerPlantsMarket();

	

private:
	vector<PowerPlantCard> powerPlantsMarket;
	vector<PowerPlantCard> drawStack;
	
	void InitializeAllCards();
	
};

