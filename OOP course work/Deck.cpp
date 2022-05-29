#include"deck.h"


void Deck::creation_pointer_deck()
{
	for (int i = 0; i < 4; i++)
	{
		pointer_deck[i] = deck[i];
	}
}


string* Deck::trump_choice()
{
    srand(time(NULL));
    int num = rand() % 4;
    string* ch = &trumps[num];
    return ch;
}


void Deck::show_cards()
{
	cout << "Cards on deck:\n\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << deck[i][j] << " ";
		}
		cout << endl;
	}
}


int Deck::real_value_of_card(string str)
{
    int real_value_of_card = real_value[str];
    return real_value_of_card;
}
