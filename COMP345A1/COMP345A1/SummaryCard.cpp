#include "stdafx.h"
#include "SummaryCard.h"


SummaryCard::SummaryCard()
{
	paymentTable.push_back(10);
	paymentTable.push_back(22);
	paymentTable.push_back(33);
	paymentTable.push_back(44);
	paymentTable.push_back(54);
	paymentTable.push_back(64);
	paymentTable.push_back(73);
	paymentTable.push_back(82);
	paymentTable.push_back(90);
	paymentTable.push_back(98);
	paymentTable.push_back(105);
	paymentTable.push_back(112);
	paymentTable.push_back(118);
	paymentTable.push_back(124);
	paymentTable.push_back(129);
	paymentTable.push_back(134);
	paymentTable.push_back(138);
	paymentTable.push_back(142);
	paymentTable.push_back(145);
	paymentTable.push_back(148);
	paymentTable.push_back(150);
}


SummaryCard::~SummaryCard()
{
}

void SummaryCard::EarnMoney(Player* player, int supplyNum){
	int num = 0;

	num = min(supplyNum, player->GetPossession()->GetNumHouse());

	if (num > 20){
		num = 20;
	}

	int earnMoney = 0;
	earnMoney = paymentTable[num];
	player->GetPossession()->AddMoney(earnMoney);
	cout << player->GetName() <<" can supply " << supplyNum << " houses, actually supply " << num << " houses and earn " << earnMoney << " money. " << endl;
}
