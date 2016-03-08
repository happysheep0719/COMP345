#pragma once
class playerPossession
{
public:
	playerPossession();
	~playerPossession();
	bool BuyHouse(int spendMoney); // buy house
	void AddMoney(int num);
	bool SpendMoney(int num); // buy power plant and resources
	int GetNumHouse();
	int GetMoney();

private:
	int numHouse;
	int money;
	
};

