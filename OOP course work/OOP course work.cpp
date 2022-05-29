#include"functions.h"
#include"Deck.h"
#include<iostream>
using namespace std;

Deck deck;
string copied_deck[4][9];
string cards_on_table[2][6];
string player_cards[36];
string bot_cards[36];
bool flag1;
bool flag2;


void copy_deck()
{
	deck.creation_pointer_deck();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			copied_deck[i][j] = deck.pointer_deck[i][j];
		}
	}
}


void fill_cards()
{
	srand(time(NULL));
	copy_deck();
	bool check = false;

	//player

	for (int i = 0; i < 6; i++)
	{
		if (player_cards[i] == "")
		{
			short unsigned int num1 = 0;
			short unsigned int num2 = 0;
			num1 = rand() % 4;
			num2 = rand() % 9;
			while (copied_deck[num1][num2] == "" and *deck.pointer_amount_of_cards != 0)
			{
				num1 = rand() % 4;
				num2 = rand() % 9;
			}
			player_cards[i] = copied_deck[num1][num2];
			copied_deck[num1][num2].clear();
			(*deck.pointer_amount_of_cards)--;
		}
		if (i == 6)
		{
			check = true;
		}
	}


	//bot

	if (check = true)
	{
		for (int i = 0; i < 6; i++)
		{
			if (bot_cards[i] == "")
			{
				short unsigned int num1 = 0;
				short unsigned int num2 = 0;
				num1 = rand() % 4;
				num2 = rand() % 9;
				while (copied_deck[num1][num2] == "" and *deck.pointer_amount_of_cards != 0)
				{
					num1 = rand() % 4;
					num2 = rand() % 9;
				}
				bot_cards[i] = copied_deck[num1][num2];
				copied_deck[num1][num2].clear();
				(*deck.pointer_amount_of_cards)--;
			}
		}
	}
}


void show_cards_on_table()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << cards_on_table[i][j] << "  ";
		}
		cout << endl;
	}
}


void clear_table()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cards_on_table[i][j].clear();
		}
	}
}


bool first_move_player()
{
	char ch;
	string copy_str1[6], copy_str2[6];
	bool check = false;
	string answer;
	string card;
	string num1;
	string num2;
	string suit1;
	string suit2;
	cout << "\nPlayer is moving!\n";
	fill_cards();
	for (int i = 0; i < 6; i++)
	{
		cout << endl << "Trump is: " << *deck.pointer_trump << endl;
		flag1 = false;

		//moving plyer

		show_cards_on_hands(player_cards);
		cout << "Choose a card: ";
		int num;
		cin >> num;
		num--;
		if (i > 0)
		{
			for (int j = 0; j < 6; j++)
			{
				copy_str1[j] = cards_on_table[0][j];
				copy_str2[j] = cards_on_table[1][j];
			}
			ch = player_cards[num][0];
		}
		while (i > 0 and (find_symbol(ch, copy_str1) == false and find_symbol(ch, copy_str2) == false))
		{
			cout << "\nIncorrect card! Please, choose another card!\n";
			cin >> num;
			num--;
		}
		cards_on_table[0][i] = player_cards[num];
		card = player_cards[num];
		player_cards[num].clear();
		if (isdigit(card[0]) and isdigit(card[1]))
		{
			for (int k = 0; k < 2; k++)
			{
				num1 += card[k];
			}
			suit1 = card[2];
		}
		else
		{
			num1 = card[0];
			suit1 = card[1];
		}

		//bot logic

		for (int j = 0; j < 36; j++)
		{
			card = bot_cards[j];
			if (isdigit(card[0]) and isdigit(card[1]) and card != "")
			{
				for (int k = 0; k < 2; k++)
				{
					num2 += card[k];
				}
				suit2 = card[2];
			}
			else if (card != "")
			{
				num2 = card[0];
				suit2 = card[1];
			}
			if (deck.real_value_of_card(num2) > deck.real_value_of_card(num1) and suit2 == suit1 and card != "")
			{
				cards_on_table[1][i] = bot_cards[j];
				check = true;
				bot_cards[j].clear();
				break;
			}
		}
		for (int j = 0; j < 36; j++)
		{
			card = bot_cards[j];
			if (isdigit(card[0]) and isdigit(card[1]) and card != "" and check != true)
			{
				for (int k = 0; k < 2; k++)
				{
					num2 += card[k];
				}
				suit2 = card[2];
			}
			else if (card != "" and check != true)
			{
				num2 = card[0];
				suit2 = card[1];
			}
			if (suit2 != suit1 and card != "" and check != true and suit2 == *deck.pointer_trump)
			{
				cards_on_table[1][i] = bot_cards[j];
				check = true;
				bot_cards[j].clear();
				break;
			}
		}
		if (check != true)
		{
			cout << "Bot takes cards!\n";
			for (int k = 0; k < 2; k++)
			{
				for (int j = 0; j < 6; j++)
				{
					for (int n = 0; n < 36; n++)
					{
						if (bot_cards[n] == "")
						{
							bot_cards[n] = cards_on_table[k][j];
							flag1 = true;
							clear_table();
							break;
						}
					}
				}
			}
			clear_table();
			break;
		}
		flag1 = false;
		check = false;
		cout << "\nCards on table:\n";
		show_cards_on_table();
		cout << "Do you want to continue?\n";
		cin >> answer;
		while (answer != "no" and answer != "yes")
		{
			cout << "Please repeat the answer: ";
			cin >> answer;
		}
		if (answer == "no")
		{
			break;
		}
		system("cls");
		cout << "\nCards on table:\n";
		show_cards_on_table();
	}
	system("cls");
	clear_table();
	return true;
}



bool first_move_bot()
{
	char ch;
	string card;
	string card2;
	string num_card1;
	string num_card2;
	string copy_str1[6], copy_str2[6];
	string answer;
	string suit1;
	string suit2;
	cout << "\nBot is moving!\n";
	fill_cards();
	for (int i = 0; i < 6; i++)
	{
		cout << endl << "Trump is: " << *deck.pointer_trump << endl;
		flag2 = false;
		//bot moving 

		int num1 = rand() % 36;
		while (bot_cards[num1] == "")
		{
			num1 = rand() % 36;
		}
		if (i > 0)
		{
			for (int j = 0; j < 6; j++)
			{
				copy_str1[j] = cards_on_table[0][j];
				copy_str2[j] = cards_on_table[1][j];
			}
			ch = bot_cards[num1][0];
		}
		if (i > 0 and (find_symbol(ch, copy_str1) == false and find_symbol(ch, copy_str2) == false))
		{
			clear_table();
			system("cls");
			break;
		}
		else if(i > 0)
		{
			num1 = pos_of_symbol(ch, bot_cards);
		}
		cards_on_table[0][i] = bot_cards[num1];
		bot_cards[num1].clear();
		cout << "\nCards on table:\n";
		show_cards_on_table();

		//player moving 

		show_cards_on_hands(player_cards);
		cout << "Do you want to take cards?\n";
		cin >> answer;
		while (answer != "yes" and answer != "no")
		{
			cout << "Please repeat the answer: ";
			cin >> answer;
		}
		if (answer == "yes")
		{
			for (int k = 0; k < 2; k++)
			{
				for (int j = 0; j < 6; j++)
				{
					for (int n = 0; n < 36; n++)
					{
						if (player_cards[n] == "")
						{
							player_cards[n] = cards_on_table[k][j];
							flag2 = true;
							clear_table();
							break;
						}
					}
				}
			}
			break;
		}
		else
		{
			card = bot_cards[num1];
			if (isdigit(card[0]) and isdigit(card[1]) and card != "")
			{
				for (int k = 0; k < 2; k++)
				{
					num_card1 += card[k];
				}
				suit1 = card[2];
			}
			else if (card != "")
			{
				num_card1 = card[0];
				suit1 = card[1];
			}
			flag2 = false;
			cout << "Choose a card!\n";
			int num2;
			cin >> num2;
			num2--;
			card2 = player_cards[num2];
			if (isdigit(card2[0]) and isdigit(card2[1]) and card2 != "")
			{
				for (int k = 0; k < 2; k++)
				{
					num_card2 += card2[k];
				}
				suit2 = card2[2];
			}
			else
			{
				num_card2 = card2[0];
				suit2 = card2[1];
			}
			while ((deck.real_value_of_card(num_card1) >= deck.real_value_of_card(num_card2) and suit2==suit1) or (suit2!=suit1 and suit2!=*deck.pointer_trump))
			{
				cout << "\nIncorrect card! Please, choose another card!\n";
				cin >> num2;
				num2--;
				card2 = player_cards[num2];
				if (isdigit(card2[0]) and isdigit(card2[1]) and card2 != "")
				{
					for (int k = 0; k < 2; k++)
					{
						num_card2 += card2[k];
					}
					suit2 = card2[2];
				}
				else
				{
					num_card2 = card2[0];
					suit2 = card2[1];
				}
			}
			cards_on_table[1][i] = player_cards[num2];
			player_cards[num2].clear();
			show_cards_on_table();
		}

		//bot give answer

		if (rand() % 2 == 0)
		{
			break;
		}
		system("cls");
	}
	clear_table();
	system("cls");
	return true;
}


void main()
{
	deck.show_cards();
	if (choice_of_move() == "Player")
	{
		while (*deck.pointer_amount_of_cards != 0)
		{
			while (first_move_player() != true or flag1 == true)
			{
				first_move_player();
			}
			if (*deck.pointer_amount_of_cards == 0 and first_move_player() == true)
			{
				cout << "\n\nPLAYER IS WINNER!!!";
			}
			while (first_move_bot() != true or flag2 == true)
			{
				first_move_bot();
			}
			if (*deck.pointer_amount_of_cards == 0 and first_move_bot() == true)
			{
				cout << "\n\nBOT IS WINNER!!!";
			}
		}
	}
	else
	{
		while (*deck.pointer_amount_of_cards != 0)
		{
			while (first_move_bot() != true or flag2 == true)//bot logic
			{
				first_move_bot();
			}
			if (*deck.pointer_amount_of_cards == 0 and first_move_bot() == true)
			{
				cout << "\n\nBOT IS WINNER!!!";
			}
			while (first_move_player() != true or flag1 == true)//player logic
			{
				first_move_player();
			}
			if (*deck.pointer_amount_of_cards == 0 and first_move_player() == true)
			{
				cout << "\n\nPLAYER IS WINNER!!!";
			}
		}
	}

}
