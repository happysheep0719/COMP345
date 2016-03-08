#include "stdafx.h"
#include "PowerPlantsMarket.h"


PowerPlantsMarket::PowerPlantsMarket()
{
	InitializeAllCards();
	InitializePowerPlantsMarket();
}

PowerPlantsMarket::~PowerPlantsMarket()
{
}

void PowerPlantsMarket::InitializeAllCards(){
	PowerPlantCard *card03 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::OilCard, 3, 2, 1);
	PowerPlantCard *card04 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::CoalCard, 4, 2, 1);
	PowerPlantCard *card05 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::HybridCard, 5, 2, 1);
	PowerPlantCard *card06 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::GarbageCard, 6, 1, 1);
	PowerPlantCard *card07 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::OilCard, 7, 3, 2);
	PowerPlantCard *card08 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::CoalCard, 8, 3, 2);
	PowerPlantCard *card09 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::OilCard, 9, 1, 1);
	PowerPlantCard *card10 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::CoalCard, 10, 2, 2);
	PowerPlantCard *card11 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::UraniumCard, 11, 1, 2);
	PowerPlantCard *card12 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::HybridCard, 12, 2, 2);
	PowerPlantCard *card13 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::EcoCard, 13, 0, 1);
	PowerPlantCard *card14 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::GarbageCard, 14, 2, 2);
	PowerPlantCard *card15 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::CoalCard, 15, 2, 3);
	PowerPlantCard *card16 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::OilCard, 16, 2, 3);
	PowerPlantCard *card17 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::UraniumCard, 17, 1, 2);
	PowerPlantCard *card18 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::EcoCard, 18, 0, 2);
	PowerPlantCard *card19 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::GarbageCard, 19, 2, 3);
	PowerPlantCard *card20 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::CoalCard, 20, 3, 5);
	PowerPlantCard *card21 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::HybridCard, 21, 2, 4);
	PowerPlantCard *card22 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::EcoCard, 22, 0, 2);
	PowerPlantCard *card23 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::UraniumCard, 23, 1, 3);
	PowerPlantCard *card24 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::GarbageCard, 24, 2, 4);
	PowerPlantCard *card25 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::CoalCard, 25, 2, 5);
	PowerPlantCard *card26 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::OilCard, 26, 2, 5);
	PowerPlantCard *card27 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::EcoCard, 27, 0, 3);
	PowerPlantCard *card28 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::UraniumCard, 28, 1, 4);
	PowerPlantCard *card29 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::HybridCard, 29, 1, 4);
	PowerPlantCard *card30 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::GarbageCard, 30, 3, 6);
	PowerPlantCard *card31 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::CoalCard, 31, 3, 6);
	PowerPlantCard *card32 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::OilCard, 32, 3, 6);
	PowerPlantCard *card33 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::EcoCard, 33, 0, 4);
	PowerPlantCard *card34 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::UraniumCard, 34, 1, 5);
	PowerPlantCard *card35 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::OilCard, 35, 1, 5);
	PowerPlantCard *card36 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::CoalCard, 36, 3, 7);
	PowerPlantCard *card37 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::EcoCard, 37, 0, 4);
	PowerPlantCard *card38 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::GarbageCard, 38, 3, 7);
	PowerPlantCard *card39 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::UraniumCard, 39, 1, 6);
	PowerPlantCard *card40 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::OilCard, 40, 2, 6);

	PowerPlantCard *card42 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::CoalCard, 42, 2, 6);
	PowerPlantCard *card44 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::EcoCard, 44, 0, 5);
	PowerPlantCard *card46 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::HybridCard, 46, 3, 7);
	PowerPlantCard *card50 = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::EcoCard, 50, 0, 6);

	PowerPlantCard *step3Card = new PowerPlantCard(PowerPlantCard::TypeOfPowerPlantCard::Step3Card, 41, 0, 0); // step 3 card number is 41

	drawStack.push_back(*card03);
	drawStack.push_back(*card04);
	drawStack.push_back(*card05);
	drawStack.push_back(*card06);
	drawStack.push_back(*card07);
	drawStack.push_back(*card08);
	drawStack.push_back(*card09);
	drawStack.push_back(*card10);
	drawStack.push_back(*card11);
	drawStack.push_back(*card12);
	drawStack.push_back(*card13);
	drawStack.push_back(*card14);
	drawStack.push_back(*card15);
	drawStack.push_back(*card16);
	drawStack.push_back(*card17);
	drawStack.push_back(*card18);
	drawStack.push_back(*card19);
	drawStack.push_back(*card20);
	drawStack.push_back(*card21);
	drawStack.push_back(*card22);
	drawStack.push_back(*card23);
	drawStack.push_back(*card24);
	drawStack.push_back(*card25);
	drawStack.push_back(*card26);
	drawStack.push_back(*card27);
	drawStack.push_back(*card28);
	drawStack.push_back(*card29);
	drawStack.push_back(*card30);
	drawStack.push_back(*card31);
	drawStack.push_back(*card32);
	drawStack.push_back(*card33);
	drawStack.push_back(*card34);
	drawStack.push_back(*card35);
	drawStack.push_back(*card36);
	drawStack.push_back(*card37);
	drawStack.push_back(*card38);
	drawStack.push_back(*card39);
	drawStack.push_back(*card40);

	drawStack.push_back(*card42);
	drawStack.push_back(*card44);
	drawStack.push_back(*card46);
	drawStack.push_back(*card50);

	drawStack.push_back(*step3Card); // step3 card

}

void PowerPlantsMarket::InitializePowerPlantsMarket(){
	/*
	int index = rand() % drawStack.size(); // 0 - (index-1)
	for (int i = 0; i < 4; i++){// actual market has 4 cards
	powerPlantsMarket.push_back(drawStack.at((index + i) % drawStack.size()));
	}
	*/
		
	for (int i = 0; i < 4; i++){// actual market has 4 cards: 03, 04, 05, 06
		powerPlantsMarket.push_back(drawStack[i]);
	}

	// // erase the first 4 elements:
	drawStack.erase(drawStack.begin(), drawStack.begin() + 4);
}

PowerPlantCard PowerPlantsMarket::ChooseAPowerPlantForAuction(int index){
	int temp = abs(index - 1) % 4; // can only be 0, 1, 2, 3

	PowerPlantCard theChosen = powerPlantsMarket.at(temp);

	powerPlantsMarket.erase(powerPlantsMarket.begin() + temp);

	return theChosen;
}

void PowerPlantsMarket::ReSupplyPowerPlantsMarket(){
	srand(time(NULL));	// for rand() // cannot put into while loop
	int index = rand() % drawStack.size(); // 0 - (index-1)

	powerPlantsMarket.push_back(drawStack[index]);
	drawStack.erase(drawStack.begin() + index);

	// sorting Power Plants Market using card number
	sort(powerPlantsMarket.begin(), powerPlantsMarket.end());
}


void PowerPlantsMarket::displayDrawStack(){
	cout << "Power Plant Card Draw Stack: " << " size: " << drawStack.size() << endl;

	for (int i = 0; i < drawStack.size(); i++){
		drawStack[i].displayACard();

		/*
		if use: vector<PowerPlantCard> *drawStack;
		(if use * then must new)
		then use:
			drawStack->at(i).display();
			(*drawStack).at(i).display();
			(*drawStack)[i].display();
		*/		
	}
	cout << endl;
}

void PowerPlantsMarket::displayPowerPlantsMarket(){
	cout << "Power Plant  Market: " << " size: " << powerPlantsMarket.size() << endl;

	for (int i = 0; i < powerPlantsMarket.size(); i++){
		powerPlantsMarket[i].displayACard();
	}
	cout << endl;
}
