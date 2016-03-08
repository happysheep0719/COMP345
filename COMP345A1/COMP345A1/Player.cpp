#include "stdafx.h"
#include "Player.h"


Player::Player(){
	Player("no name");
}

Player::Player(string inputName){
	name = inputName;
	myPossession = new playerPossession();

	for (int i = 0; i < NumTypeOfResource; i++){
		resourceNum[i] = 0;
	}
}

Player::~Player()
{// destructor only used to eliminate new
	delete myPossession;
	myPossession = NULL;
}

playerPossession* Player::GetPossession(){
	return myPossession;
}

string Player::GetName(){
	return name;
}

void Player::display(){
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout << "Name: " << name << endl;
	cout << "has money: " << myPossession->GetMoney() << endl;
	cout << "has " << myPossession->GetNumHouse() << " house" << endl;
	displayAllPowerPlantCards();
	displayAllResources();
	cout << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
}

void Player::displayAllPowerPlantCards(){
	cout << "has PowerPlantCards: " << endl;
	for (int i = 0; i < mPowerPlants.size(); i++){
		mPowerPlants[i].displayACard();
	}
	cout << endl;
}

void Player::displayAllResources(){
	string stringOfResource[] = { "Coal", "Oil", "Garbage", "Uranium" };

	cout << "has Resources " << endl;
	for (int i = 0; i < NumTypeOfResource; i++){
		cout << stringOfResource[i] << ": " << resourceNum[i] << endl;
	}
}

void Player::buyPowerPlant(PowerPlantCard aPowerPlant, int pay){
	if (myPossession->SpendMoney(pay)){
		mPowerPlants.push_back(aPowerPlant);
		display();
	}
}

int Player::BuyResource(TypeOfResource type, int quantity){
	int total = 0;
	int canBuy = 0;

	for (int i = 0; i < mPowerPlants.size(); i++){
		if (mPowerPlants[i].getCardType() == type){
			total += mPowerPlants[i].getMaxStore();
		}
	}

	canBuy = total - resourceNum[type];

	if (quantity > canBuy){
		quantity = canBuy;
	}
	return quantity;

}

void Player::AddResource(TypeOfResource type, int quantity){
	resourceNum[type] += quantity;
}