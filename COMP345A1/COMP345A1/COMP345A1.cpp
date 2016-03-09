// COMP345A1.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Player.h"
#include "SummaryCard.h"
#include "PowerPlantsMarket.h"
#include "ResourceMarket.h"


int HowManyPlayers(){
	cout << "How many players? " << endl;
	int num;
	cin >> num;
	cout << "There are " << num << " players. " << endl << endl;
	return num;

}
Player* SetUpPlayers(int index){
	cout << "Please input player" << index << "'s name: " << endl;
	string tempName;
	cin >> tempName;
	Player* aPlayer = new Player(tempName);
	aPlayer->GetPossession()->AddMoney(50);
	return aPlayer;
}

vector<Player*> determineOrderForFirstTurn(vector<Player*> originPlayers){
	srand(time(NULL));	// for rand() // cannot put into while loop
	vector<Player*> newPlayers;

	while(originPlayers.size() > 0){
		int turn = rand() % originPlayers.size();
		Player* selectedPlayer = originPlayers.at(turn);
		originPlayers.erase(originPlayers.begin() + turn);
		newPlayers.push_back(selectedPlayer);
	}
	
	return newPlayers;
}

void AuctionPowerPlants(vector<Player*> thePlayers, PowerPlantsMarket* aPowerPlantsMarket, bool isFirstTurn){
	vector<bool> alreadyBuyFlags;
	for (int i = 0; i < thePlayers.size(); i++){
		alreadyBuyFlags.push_back(false);
	}

	for (int i = 0; i < thePlayers.size(); i++){
		bool passOrChoose = true; // true for choose, false for pass

		if (isFirstTurn){
			cout << "You must buy a Power Plant in 1st round. " << endl;
			passOrChoose = true;
		}
		else{
			int chooseOrPass = 0;
			while (chooseOrPass != 1 && chooseOrPass != 2){
				cout << thePlayers[i]->GetName() << " enter 1 for pass or 2 for choose to Auction Power Plants: " << endl;
				cin >> chooseOrPass;
			}
			if (chooseOrPass == 1){ // pass
				passOrChoose = false; //false for pass
			}
			else{
				passOrChoose = true; // true for choose
			}
		}

		if (passOrChoose == false){
			continue;
		}

		// auction power plants
		int auctionWhichPowerPlant = 0;
		cout << thePlayers[i]->GetName() << " enter a number between 1 and 4: " << endl;
		cin >> auctionWhichPowerPlant;
		while (auctionWhichPowerPlant < 1 || auctionWhichPowerPlant > 4){
			cout << thePlayers[i]->GetName() << " enter a number between 1 and 4: " << endl;
			cin >> auctionWhichPowerPlant;
		}

		PowerPlantCard theChosenForAuction = aPowerPlantsMarket->ChooseAPowerPlantForAuction(auctionWhichPowerPlant);
		cout << "Now auction for: " << endl;
		theChosenForAuction.displayACard();

		int bid_i = 0;
		cout << thePlayers[i]->GetName() << " enter a price no less than " << theChosenForAuction.getCardNumber() << endl;
		cin >> bid_i;
		while (bid_i < theChosenForAuction.getCardNumber() || bid_i > thePlayers[i]->GetPossession()->GetMoney())
		{
			cout << thePlayers[i]->GetName() << " enter a price no less than " << theChosenForAuction.getCardNumber() << endl;
			cin >> bid_i;
		}	

		int hightestBid = bid_i;
		int bid_winner = i;
		for (int j = 0; j < thePlayers.size(); j++){
			bool bid = false;  // true for bid, false for pass
			if (j != i){
				int bidbid = 0;
				while (bidbid != 1 && bidbid != 2){
					cout << thePlayers[j]->GetName() << " enter 1 for pass or 2 for bid for a price higher than " << hightestBid << endl;
					cin >> bidbid;
				}
				if (bidbid == 1){// 1 for pass
					continue;
				}

				int bid_j = 0;
				cout << thePlayers[j]->GetName() << " enter a price higher than " << hightestBid << endl;
				cin >> bid_j;
				while (bid_j <= hightestBid || bid_j > thePlayers[j]->GetPossession()->GetMoney()){
					cout << thePlayers[j]->GetName() << " enter a price higher than " << hightestBid << endl;
					cin >> bid_j;					
				}
				hightestBid = bid_j;
				bid_winner = j;
			}
		}

		cout << thePlayers[bid_winner]->GetName() << " has won the bid and will pay " << hightestBid << " to buy No." << theChosenForAuction.getCardNumber() << " Power Plant Card" << endl;

		// buy the chosen auction power plant card
		thePlayers[bid_winner]->buyPowerPlant(theChosenForAuction, hightestBid);
		thePlayers[bid_winner]->display();

		// re-supply the Power Plant Market
		aPowerPlantsMarket->ReSupplyPowerPlantsMarket();
		aPowerPlantsMarket->displayDrawStack();
		aPowerPlantsMarket->displayPowerPlantsMarket();
	}

	/*
	PowerPlantCard theChosenForAuction = aPowerPlantsMarket->ChooseAPowerPlantForAuction(2);
	aPowerPlantsMarket->displayPowerPlantsMarket();
	p1->buyPowerPlant(theChosenForAuction, 10);

	aPowerPlantsMarket->ReSupplyPowerPlantsMarket();
	aPowerPlantsMarket->displayDrawStack();
	aPowerPlantsMarket->displayPowerPlantsMarket();
	*/
}

void OnePlayerBuyResource(Player* aPlayer, ResourceMarket* aResourceMarket){
	string stringOfResource[] = { "Coal", "Oil", "Garbage", "Uranium" };

	for (int i = 0; i < NumTypeOfResource; i++){
		cout << aPlayer->GetName() << ": how many " << stringOfResource[i] << " you want to buy?" << endl;
		int quantity;
		cin >> quantity;
		aResourceMarket->buyResource(aPlayer, TypeOfResource(i), aPlayer->BuyResource(TypeOfResource(i), quantity));
	}
}

void PlayersBuyResources(vector<Player*> thePlayers, ResourceMarket* aResourceMarket){
	for (int i = 0; i < thePlayers.size(); i++){
		OnePlayerBuyResource(thePlayers[i], aResourceMarket);
		thePlayers[i]->display();
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<Player*> players;
	bool firstTurnFlag = true;
	int roundCount = 0;


	int numOfPlayers = HowManyPlayers();
	
	for (int i = 0; i < numOfPlayers; i++){
		cout << "It's player " << (i + 1) << "'s turn. " << endl;	
		players.push_back(SetUpPlayers(i + 1));
		cout << endl;
	}

	cout << "Players are:" << endl;
	for (int i = 0; i < players.size(); i++){
		cout << players[i]->GetName() << endl;
	}

	// Determin Players order for 1st turn 
	if (firstTurnFlag){// the 1st turn
		players = determineOrderForFirstTurn(players);
		firstTurnFlag = false;
	}

	cout << "Now Players are: " << endl;
	for (int i = 0; i < players.size(); i++){
		players[i]->display();
	}

	// Auction Power Plants
	PowerPlantsMarket *aPowerPlantsMarket = new PowerPlantsMarket(); // build PowerPlantsMarket
	aPowerPlantsMarket->displayDrawStack();
	aPowerPlantsMarket->displayPowerPlantsMarket();

	AuctionPowerPlants(players, aPowerPlantsMarket, firstTurnFlag);


	// Buy resources
	ResourceMarket  *aResourceMarket = new ResourceMarket(); // build ResourceMarket

	PlayersBuyResources(players, aResourceMarket);


	/*
	while (true){
		cout << "Now is No." << (roundCount + 1) << " round. " << endl;


		

		roundCount += 1;
	}

	*/
	/*
	Player *p1, *p2;

	cout << "Please input p1 name: " << endl;	
	string tempName;
	cin >> tempName;
	p1 = new Player(tempName);

	cout << "Please input p2 name: " << endl;
	cin >> tempName;
	p2 = new Player(tempName);

	p1->display();
	p2->display();

	cout << "Add money to players: " << endl;
	p1->GetPossession()->AddMoney(100);
	p2->GetPossession()->AddMoney(100);

	p1->display();
	p2->display();

	cout << "Players buy house: " << endl;
	p1->GetPossession()->BuyHouse(80);
	p2->GetPossession()->BuyHouse(150);

	p1->display();
	p2->display();

	//---------------Distinct part 2------------------------------------------------------------------------

	for (int i = 0; i < 10; i++){
		p1->GetPossession()->BuyHouse(0);
		p2->GetPossession()->BuyHouse(0);
	}

	p1->display();
	p2->display();

	SummaryCard *mySummaryCard;
	mySummaryCard = new SummaryCard();

	mySummaryCard->EarnMoney(p1, 8);
	mySummaryCard->EarnMoney(p2, 12);

	p1->display();
	p2->display();



	PowerPlantsMarket *aPowerPlantsMarket = new PowerPlantsMarket();
	aPowerPlantsMarket->displayDrawStack();
	aPowerPlantsMarket->displayPowerPlantsMarket();

	cout << endl;
	PowerPlantCard theChosenForAuction = aPowerPlantsMarket->ChooseAPowerPlantForAuction(2);
	aPowerPlantsMarket->displayPowerPlantsMarket();
	p1->buyPowerPlant(theChosenForAuction, 10);

	aPowerPlantsMarket->ReSupplyPowerPlantsMarket();
	aPowerPlantsMarket->displayDrawStack();
	aPowerPlantsMarket->displayPowerPlantsMarket();

	ResourceMarket  *aResourceMarket = new ResourceMarket();

	BuyResource(aResourceMarket, p1);
	p1->display();

	*/




	getchar();
	getchar();
	return 0;
}


