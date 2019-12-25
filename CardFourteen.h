#pragma once
#include "card.h"
class Player;
class CardFourteen : public Card
{
	static int card_price;
	static int  fees;
	static int exists;
	static Player *owner;

	static bool has_been_saved_with_parameters ;
	static bool has_been_loaded_with_parameters ;

public:
	CardFourteen(const CellPosition & pos);
	CardFourteen();
	void ReadCardParameters(Grid *);

	void Apply(Grid* pGrid, Player* pPlayer); 

	static void setExists(int);
	static int getExists();

	static void SetOwner(Player*);
	static Player* GetOwner();

	static void SetSaveFlagToFalse();

	void Save(ofstream &OutFile) ;
	void Load(ifstream &Infile,Grid* pGrid) ;

	~CardFourteen(void);
};
