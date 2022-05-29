#include"functions.h"

void show_cards_on_hands(string* cards_on_hands)
{
	cout << "\nCards on hands:\t";
	for (int i = 0; i < 36; i++)
	{
		cout << cards_on_hands[i] << " ";
	}
	cout << endl;
}

bool find_symbol(char ch, string* str2)
{
	string str[6];
	char symbol = ch;
	bool b = false;
	for (int i = 0; i < 6; i++)
	{
		str[i] = str2[i];
	}
	for (int i = 0; i < 6; i++)
	{
		if (symbol == str[i][0] and str[i] != "")
		{
			b = true;
		}
	}
	return b;
}

int pos_of_symbol(char ch, string *str)
{
	int num;
	for (int i = 0; i < 36; i++)
	{
		if (ch == str[i][0])
		{
			num = i;
		}
	}
	return num;
}

string choice_of_move()
{
	srand(time(NULL));
	map<int, string> move =
	{
		{0,"Player"},
		{1,"Bot"}
	};
	short int num = rand() % 2;
	return move[num];
}
