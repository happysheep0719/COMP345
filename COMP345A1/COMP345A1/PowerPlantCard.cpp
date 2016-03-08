#include "stdafx.h"
#include "PowerPlantCard.h"


PowerPlantCard::PowerPlantCard()
{
}

PowerPlantCard::PowerPlantCard(TypeOfPowerPlantCard mType, int cardNumberValue, int resourceNumOnCardValue, int powerHouseNumValue){
	cardType = mType;

	switch (cardType){
	case Step3Card:
		cardNumber = 41; // step 3 card number is 41
		resourceNumOnCard = 0;
		powerHouseNum = 0;

		MaxStore = 0;
		isHybridCard = false;
		isStep3Card = true;
		isEcoCard = false;

		break;
	case HybridCard:
		cardNumber = cardNumberValue;
		resourceNumOnCard = resourceNumOnCardValue;
		powerHouseNum = powerHouseNumValue;

		MaxStore = 2 * resourceNumOnCard;
		isHybridCard = true;
		isStep3Card = false;
		isEcoCard = false;

		break;

	case CoalCard:
		cardNumber = cardNumberValue;
		resourceNumOnCard = resourceNumOnCardValue;
		powerHouseNum = powerHouseNumValue;

		MaxStore = 2 * resourceNumOnCard;
		isHybridCard = false;
		isStep3Card = false;
		isEcoCard = false;

		break;

	case OilCard:
		cardNumber = cardNumberValue;
		resourceNumOnCard = resourceNumOnCardValue;
		powerHouseNum = powerHouseNumValue;

		MaxStore = 2 * resourceNumOnCard;
		isHybridCard = false;
		isStep3Card = false;
		isEcoCard = false;

		break;

	case GarbageCard:
		cardNumber = cardNumberValue;
		resourceNumOnCard = resourceNumOnCardValue;
		powerHouseNum = powerHouseNumValue;

		MaxStore = 2 * resourceNumOnCard;
		isHybridCard = false;
		isStep3Card = false;
		isEcoCard = false;

		break;

	case UraniumCard:
		cardNumber = cardNumberValue;
		resourceNumOnCard = resourceNumOnCardValue;
		powerHouseNum = powerHouseNumValue;

		MaxStore = 2 * resourceNumOnCard;
		isHybridCard = false;
		isStep3Card = false;
		isEcoCard = false;

		break;

	case EcoCard:
		cardNumber = cardNumberValue;
		resourceNumOnCard = 0;
		powerHouseNum = powerHouseNumValue;

		MaxStore = 0;
		isHybridCard = false;
		isStep3Card = false;
		isEcoCard = true;

		break;

	default:
		break;
	}
}

PowerPlantCard::~PowerPlantCard()
{
}

void PowerPlantCard::displayACard(){
	switch (cardType){
	case Step3Card:
		cout << "It's Step 3 card. " << endl;
		break;
	case HybridCard:
		cout << "Hybrid Power Plant Card No. " << cardNumber << " Can use any combination of " << resourceNumOnCard << " coal and/or oil to power " << powerHouseNum << " houses. " << endl;
		break;
	case CoalCard:
		cout << "Coal Power Plant Card No. " << cardNumber << " Can use " << resourceNumOnCard << " coal to power " << powerHouseNum << " houses. " << endl;
		break;
	case OilCard:
		cout << "Oil Power Plant Card No. " << cardNumber << " Can use " << resourceNumOnCard << " oil to power " << powerHouseNum << " houses. " << endl;
		break;
	case GarbageCard:
		cout << "Garbage Power Plant Card No. " << cardNumber << " Can use " << resourceNumOnCard << " garbage to power " << powerHouseNum << " houses. " << endl;
		break;
	case UraniumCard:
		cout << "Uranium Power Plant Card No. " << cardNumber << " Can use " << resourceNumOnCard << " uranium to power " << powerHouseNum << " houses. " << endl;
		break;
	case EcoCard:
		cout << "Eco Power Plant Card No. " << cardNumber << " Use nothing to power " << powerHouseNum << " houses. " << endl;
		break;
	}

}

PowerPlantCard::TypeOfPowerPlantCard PowerPlantCard::getCardType(){
	return cardType;
}

int PowerPlantCard::getCardNumber(){
	return cardNumber;
}

int PowerPlantCard::getResourceNumOnCard(){
	return resourceNumOnCard;
}

int PowerPlantCard::getPowerHouseNum(){
	return powerHouseNum;
}

int PowerPlantCard::getMaxStore(){
	return MaxStore;
}
