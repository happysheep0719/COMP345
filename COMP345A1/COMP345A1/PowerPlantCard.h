#pragma once
#include "stdafx.h"

class PowerPlantCard
{
public:
	enum TypeOfPowerPlantCard{ CoalCard, OilCard, GarbageCard, UraniumCard, EcoCard, HybridCard, Step3Card };

	PowerPlantCard();
	PowerPlantCard(TypeOfPowerPlantCard mType, int cardNumberValue, int resourceNumOnCardValue, int powerHouseNumValue);

	~PowerPlantCard();
	void displayACard();

	TypeOfPowerPlantCard getCardType();
	int getCardNumber();
	int getResourceNumOnCard();
	int getPowerHouseNum();
	int getMaxStore();

	// sort Power Plant Cards in market by card number 
	//bool SortByCardNumber(PowerPlantCard lhs,PowerPlantCard rhs){ return lhs.cardNumber < rhs.cardNumber; }
	friend bool operator < (PowerPlantCard &lhs, PowerPlantCard &rhs){ return lhs.cardNumber < rhs.cardNumber; }

private:
	// attributes of PowerPlant Card
	TypeOfPowerPlantCard cardType;
	int cardNumber;
	int resourceNumOnCard;
	int powerHouseNum;

	int MaxStore = 2 * resourceNumOnCard;
	bool isHybridCard;
	bool isStep3Card;
	bool isEcoCard;

};

