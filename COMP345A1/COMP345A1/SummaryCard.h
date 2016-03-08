#pragma once
#include "stdafx.h"
#include "Player.h"

using namespace std;

class SummaryCard
{
public:
	SummaryCard();
	~SummaryCard();
	void EarnMoney(Player* player, int supplyNum);

private:
	vector<int> paymentTable;
};

