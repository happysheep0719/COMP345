#include "stdafx.h"
#include "ResourceMarket.h"


ResourceMarket::ResourceMarket()
{
	resourceNum[TypeOfResource::Coal] = CoalMaxNumInResourceMarket;
	resourceNum[TypeOfResource::Oil] = 18;
	resourceNum[TypeOfResource::Garbage] = 6;
	resourceNum[TypeOfResource::Uranium] = 2;
}

ResourceMarket::~ResourceMarket()
{
}

void ResourceMarket::buyResource(Player* aPlayer, TypeOfResource type, int quantity){
	if (quantity > resourceNum[type]){
		quantity = resourceNum[type];
	}

	// buy one by one, one for each time
	for (int i = 0; i < quantity; i++){
		int pay = getResourcePrice(type);
		if (aPlayer->GetPossession()->SpendMoney(pay)){
			resourceNum[type]--;
			aPlayer->AddResource(type, 1);
		}
	}
}

int ResourceMarket::getPriceOfCoal(){
	switch (resourceNum[TypeOfResource::Coal]){
		case 1:
			return 8;
		case 2:
			return 8;
		case 3:
			return 8;
		case 4:
			return 7;
		case 5:
			return 7;
		case 6:
			return 7;
		case 7:
			return 6;
		case 8:
			return 6;
		case 9:
			return 6;
		case 10:
			return 5;
		case 11:
			return 5;
		case 12:
			return 5;
		case 13:
			return 4;
		case 14:
			return 4;
		case 15: 
			return 4;
		case 16:
			return 3;
		case 17:
			return 3;
		case 18:
			return 3;
		case 19:
			return 2;
		case 20:
			return 2;
		case 21:
			return 2;
		case 22:
			return 1;
		case 23:
			return 1;
		case 24:
			return 1;
		default:
			return 0;
	}
}

int ResourceMarket::getPriceOfOil(){
	switch (resourceNum[TypeOfResource::Oil]){
		case 1:
			return 8;
		case 2:
			return 8;
		case 3:
			return 8;
		case 4:
			return 7;
		case 5:
			return 7;
		case 6:
			return 7;
		case 7:
			return 6;
		case 8:
			return 6;
		case 9:
			return 6;
		case 10:
			return 5;
		case 11:
			return 5;
		case 12:
			return 5;
		case 13:
			return 4;
		case 14:
			return 4;
		case 15:
			return 4;
		case 16:
			return 3;
		case 17:
			return 3;
		case 18:
			return 3;
		case 19:
			return 2;
		case 20:
			return 2;
		case 21:
			return 2;
		case 22:
			return 1;
		case 23:
			return 1;
		case 24:
			return 1;
		default:
			return 0;
	}

}

int ResourceMarket::getPriceOfGarbage(){
	switch (resourceNum[TypeOfResource::Garbage]){
		case 1:
			return 8;
		case 2:
			return 8;
		case 3:
			return 8;
		case 4:
			return 7;
		case 5:
			return 7;
		case 6:
			return 7;
		case 7:
			return 6;
		case 8:
			return 6;
		case 9:
			return 6;
		case 10:
			return 5;
		case 11:
			return 5;
		case 12:
			return 5;
		case 13:
			return 4;
		case 14:
			return 4;
		case 15:
			return 4;
		case 16:
			return 3;
		case 17:
			return 3;
		case 18:
			return 3;
		case 19:
			return 2;
		case 20:
			return 2;
		case 21:
			return 2;
		case 22:
			return 1;
		case 23:
			return 1;
		case 24:
			return 1;
		default:
			return 0;
	}
}

int ResourceMarket::getPriceOfUranium(){
	switch (resourceNum[TypeOfResource::Uranium]){
		case 1:
			return 16;
		case 2:
			return 14;
		case 3:
			return 12;
		case 4:
			return 10;
		case 5:
			return 8;
		case 6:
			return 7;
		case 7:
			return 6;
		case 8:
			return 5;
		case 9:
			return 4;
		case 10:
			return 3;
		case 11:
			return 2;
		case 12:
			return 1;
		default:
			return 0;
	}
}

int ResourceMarket::getResourcePrice(TypeOfResource type){
	switch (type)
	{
	case TypeOfResource::Coal:
		return getPriceOfCoal();
		break;
	case TypeOfResource::Oil:
		return getPriceOfOil();
		break;
	case TypeOfResource::Garbage:
		return getPriceOfGarbage();
		break;
	case TypeOfResource::Uranium:
		return getPriceOfUranium();
		break;
	default:
		break;
	}
}

void ResourceMarket::reSupplyResourceMarket(int coal, int oil, int garbage, int uranium){

}

void ResourceMarket::checkReSupplyValidity(int &coal, int &oil, int &garbage, int &uranium){

}

void ResourceMarket::displayResourceMarket(){
	cout << "Now Resource Market has: " << "Coal: " << resourceNum[TypeOfResource::Coal] << ", " << "Oil: " << resourceNum[TypeOfResource::Oil] << ", " << "Garbage: " << resourceNum[TypeOfResource::Garbage] << ", " << "Uranium: " << resourceNum[TypeOfResource::Uranium] << endl;
}