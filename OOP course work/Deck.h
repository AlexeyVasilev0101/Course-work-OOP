#pragma once
#include<iostream>
#include<map>
#include<ctime>
using namespace std;
class Deck
{
private:
    string deck[4][9] =
    {
        {"6\3", "7\3", "8\3", "9\3", "10\3", "J\3", "Q\3", "K\3", "A\3"},
        {"6\4", "7\4", "8\4", "9\4", "10\4", "J\4", "Q\4", "K\4", "A\4"},
        {"6\5", "7\5", "8\5", "9\5", "10\5", "J\5", "Q\5", "K\5", "A\5"},
        {"6\6", "7\6", "8\6", "9\6", "10\6", "J\6", "Q\6", "K\6", "A\6"}
    };
    string trumps[4] = { "\3","\4","\5","\6" };
    map<string, int> real_value =
    {
        {"6",6},
        {"7",7},
        {"8",8},
        {"9",9},
        {"10",10},
        {"J",11},
        {"Q",12},
        {"K",13},
        {"A",14}
    };
    int amount_of_cards = 36;
    string* trump_choice();
public:
    string* pointer_deck[4];
    string* pointer_trump = trump_choice();
    int* pointer_amount_of_cards = &amount_of_cards;
    void creation_pointer_deck();
    void show_cards();
    int real_value_of_card(string str);
};
