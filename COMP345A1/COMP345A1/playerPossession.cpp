#include "stdafx.h"
#include "playerPossession.h"


playerPossession::playerPossession()
{
	numHouse = 0;
	money = 0;
}

playerPossession::~playerPossession()
{
}

bool playerPossession::BuyHouse(int spendMoney){
	if (SpendMoney(spendMoney)){
		numHouse++;
		return true;
	}

	cout << "fail to buy, no enough money!" << endl;
	return false;
}

void playerPossession::AddMoney(int num){
	money += num;
}


bool playerPossession::SpendMoney(int num)
{
	if (num > money){
		cout << "fail to buy, no enough money!" << endl;
		return false;
	}

	money -= num;
	cout << "Thanks for your payment." << endl;
	return true;
}

int playerPossession::GetNumHouse(){
	return numHouse;
}

int playerPossession::GetMoney(){
	return money;
}
