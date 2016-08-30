#include<iostream>
#include<iomanip>
#include<string>
#include <clocale>
using namespace std;

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#define HEART   ((char)0x03)
#define DIAMOND ((char)0x04)
#define CLUB	((char)0x05)
#define SPADE   ((char)0x06)

#else
#define HEART 'H' 
#define DIAMOND 'D' 
#define CLUB 'C' 
#define SPADE 'S'

#endif

void display_cards(string hand[], int num_cards)
{
	string temp;
	string suit[7];
	string number[7];
	for(int i=0; i < num_cards; i++)//loading suits into seperate array
	{
		suit[i] = hand[i].substr(0,1);
		if(suit[i] == "H")
			suit[i] = '\x03';
		if(suit[i] == "D")
			suit[i] = '\x04';
		if(suit[i] == "C")
			suit[i] = '\x05';
		if(suit[i] == "S")
			suit[i] = '\x06';
	}
	for(int i=0; i < num_cards; i++)//loading card values into seperate array
	{
		number[i] = hand[i].substr(1,2);
		temp = number[i];
			if(atoi(temp.c_str()) == 11)//checking for face cards
				number[i] = "J";
			if(atoi(temp.c_str()) == 12)
				number[i] = "Q";
			if(atoi(temp.c_str()) == 13)
				number[i] = "K";
			if(atoi(temp.c_str()) == 14)
				number[i] = "A";
	}			

	for(int i=0; i < num_cards; i++)
		cout << "__________    ";
	cout << endl;
	for(int i=0; i < num_cards; i++)
		cout << "|" <<  left << setw(2) << number[i] << "    " << right << setw(2) << suit[i] << "|    ";
	cout << endl;
	for(int i=0; i < num_cards; i++)
		cout << "|        |    ";
	cout << endl;
	for(int i=0; i < num_cards; i++)
		cout << "|        |    ";
	cout << endl;
	for(int i=0; i < num_cards; i++)
		cout << "|        |    ";
	cout << endl;
	for(int i=0; i < num_cards; i++)
		cout << "|        |    ";
	cout << endl;
	for(int i=0; i < num_cards; i++)
		cout << "|        |    ";
	cout << endl;
	for(int i=0; i < num_cards; i++)
		cout << "|" << left << setw(2) << suit[i] << "    " << right << setw(2) << number[i] << "|    ";
	cout << endl;
	for(int i=0; i < num_cards; i++)
		cout << "|________|    ";
	cout << endl;
}

