#pragma once
#include "stdafx.h"
#include "Player.h"


class ResourceMarket
{
public:
	

	ResourceMarket();
	~ResourceMarket();

	void buyResource(Player * aPlayer, TypeOfResource type, int quantity); // actually buy resources here

	void reSupplyResourceMarket(int coal, int oil, int garbage, int uranium);

	void displayResourceMarket();


private:
	int resourceNum[NumTypeOfResource];

	int getPriceOfCoal();
	int getPriceOfOil();
	int getPriceOfGarbage();
	int getPriceOfUranium();

	int getResourcePrice(TypeOfResource type);

	void checkReSupplyValidity(int &coal, int &oil, int &garbage, int &uranium);
};

