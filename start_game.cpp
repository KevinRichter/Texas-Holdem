#include <iostream>
using namespace std;

#include "holdem.h"
void folding(Bank stats, double total_bet);

double	//returns the money the player made during the round
start_game(Bank stats)
{
	string dump;//dumps bad user input into this
	char again;
	int winnings;
	bool rematch = false;
	char answer; //decision of increasing bet or folding
	double bet_amount, total_bet = 0.0;
	double player_hand, dealer_hand;
	string player_all[7], player[2], dealer_all[7], dealer[2], house[5];
   
	do
	{
	build_arrays(player_all, 7, player, 2, dealer_all, 7, dealer, 2, house, 5);
	stats.IFfunds_0();//checks to see if player has available funds before starting game
	cout << "You have $" << stats.GETfunds() << " in your bank\n";
	cout << "*****STARTING GAME*****\n\n" << endl;
	cout << "Place your bet: $";
	cin >> bet_amount;
	//data validation
    while ( (bet_amount < 0)||(cin.fail())||(bet_amount + total_bet > stats.GETfunds()) )
    {
   	 if ( (bet_amount < 0)||(cin.fail()) )
   	 {
   		 cin.clear();
   		 cin.ignore(200, '\n');
   		 cout << "Please enter a non-negative number for your bet: ";
   		 cin >> bet_amount;
   	 }
   	 if ( (bet_amount + total_bet > stats.GETfunds()) )
   	 {
   		 do
   		 {
   			 cout << "Please enter an amount less than what's in your bank. $" << stats.GETfunds()-total_bet <<endl;
   			 cin >> bet_amount;
   		 }
   		 while(bet_amount + total_bet > stats.GETfunds());
   	 }
    }
	total_bet = total_bet + bet_amount;
	cout << "YOUR HAND:" << endl;
	display_cards(player, 2); // displays two cards for player
	cout << "Place your bet" << endl;
	cout << "Bet Amount: $";
	cin >> bet_amount;
	//data validation
    while ( (bet_amount < 0)||(cin.fail())||(bet_amount + total_bet > stats.GETfunds()) )
    {
   	 if ( (bet_amount < 0)||(cin.fail()) )
   	 {
   		 cin.clear();
   		 cin.ignore(200, '\n');
   		 cout << "Please enter a non-negative number for your bet: ";
   		 cin >> bet_amount;
   	 }
   	 if ( (bet_amount + total_bet > stats.GETfunds()) )
   	 {
   		 do
   		 {
   			 cout << "Please enter an amount less than what's in your bank. $" << stats.GETfunds()-total_bet <<endl;
   			 cin >> bet_amount;
   		 }
   		 while(bet_amount + total_bet > stats.GETfunds());
   	 }
    }
	total_bet = total_bet + bet_amount;
	cout << "Dealer will now deal 3 cards" << endl;
	cout <<"YOUR HAND:\n";
	display_cards(player, 2);
	cout << "\n\nTABLE:\n";
	display_cards(house, 3); //displays three cards for community pile
	cout << "Would you like to place another bet or fold \n"
   	<< "(B = bet / F = Fold): ";
	cin >> answer;
    //data validation
	while( ((answer != 'B') && (answer != 'b') && (answer != 'F') && (answer != 'f')) || cin.fail())
	{
    	cin.clear();
    	cin.ignore(200, '\n');
    	cout << "Please enter either a 'B' or an 'F'.\n";
    	cin >> answer;
	}
	if (answer == 'F' || answer == 'f')
	{
    	folding(stats, total_bet);

       	cout << "Would you like to play again? (Y/N)";
       	cin >> again;
       	if(again == 'Y' || again == 'y')
          	rematch = true;
       	continue;
	}
	cout << "Enter Bet Amount: $";
	cin >> bet_amount;
	//data validation
    while ( (bet_amount < 0)||(cin.fail())||(bet_amount + total_bet > stats.GETfunds()) )
    {
   	 if ( (bet_amount < 0)||(cin.fail()) )
   	 {
   		 cin.clear();
   		 cin.ignore(200, '\n');
   		 cout << "Please enter a non-negative number for your bet: ";
   		 cin >> bet_amount;
   	 }
   	 if ( (bet_amount + total_bet > stats.GETfunds()) )
   	 {
   		 do
   		 {
   			 cout << "Please enter an amount less than what's in your bank. $" << stats.GETfunds()-total_bet <<endl;
   			 cin >> bet_amount;
   		 }
   		 while(bet_amount + total_bet > stats.GETfunds());
   	 }
    }
	total_bet = total_bet + bet_amount;
	cout << "Dealer will now deal another card" << endl;
	cout <<"YOUR HAND:\n";
	display_cards(player, 2);
	cout << "\n\nTABLE:\n";
	display_cards(house, 4); //displays four cards for community pile
	cout << "Would you like to place another bet or fold \n"
    	<< "(B = bet / F = Fold):";
	cin >> answer;
    //data validation
	while( ((answer != 'B') && (answer != 'b') && (answer != 'F') && (answer != 'f')) || cin.fail())
	{
    	cin.clear();
    	cin.ignore(200, '\n');
    	cout << "Please enter either a 'B' or an 'F'.\n";
    	cin >> answer;
	}
	if (answer == 'F' || answer == 'f')
	{
    	folding(stats, total_bet);
       	cout << "Would you like to play again? (Y/N)";
       	cin >> again;
       	if(again == 'Y' || again == 'y')
          	rematch = true;
       	continue;
	}
	cout << "Enter Bet Amount: $";
	cin >> bet_amount;
	//data validation
    while ( (bet_amount < 0)||(cin.fail())||(bet_amount + total_bet > stats.GETfunds()) )
    {
   	 if ( (bet_amount < 0)||(cin.fail()) )
   	 {
   		 cin.clear();
   		 cin.ignore(200, '\n');
   		 cout << "Please enter a non-negative number for your bet: ";
   		 cin >> bet_amount;
   	 }
   	 if ( (bet_amount + total_bet > stats.GETfunds()) )
   	 {
   		 do
   		 {
   			 cout << "Please enter an amount less than what's in your bank. $" << stats.GETfunds()-total_bet <<endl;
   			 cin >> bet_amount;
   		 }
   		 while(bet_amount + total_bet > stats.GETfunds());
   	 }
    }
	total_bet = total_bet + bet_amount;
	cout << "Dealer will now deal the final card" << endl;
	cout <<"YOUR HAND:\n";
	display_cards(player, 2);
	cout << "\n\nTABLE:\n";
	display_cards(house, 5); //displays five cards (final card display)
	cout << "Would you like to place a final bet or fold \n"
        	<< "(B = bet / F = Fold): ";
	cin >> answer;
    //data validation
	while( ((answer != 'B') && (answer != 'b') && (answer != 'F') && (answer != 'f')) || cin.fail())
	{
    	cin.clear();
    	cin.ignore(200, '\n');
    	cout << "Please enter either a 'B' or an 'F'.\n";
    	cin >> answer;
	}
	if (answer == 'F' || answer == 'f')
	{
    	folding(stats, total_bet);
       	cout << "Would you like to play again? (Y/N)";
       	cin >> again;
       	if(again == 'Y' || again == 'y')
          	rematch = true;
       	continue;
	}
	cout << "Enter Final Bet: $";
	cin >> bet_amount;
	//data validation
    while ( (bet_amount < 0)||(cin.fail())||(bet_amount + total_bet > stats.GETfunds()) )
    {
   	 if ( (bet_amount < 0)||(cin.fail()) )
   	 {
   		 cin.clear();
   		 cin.ignore(200, '\n');
   		 cout << "Please enter a non-negative number for your bet: ";
   		 cin >> bet_amount;
   	 }
   	 if ( (bet_amount + total_bet > stats.GETfunds()) )
   	 {
   		 do
   		 {
   			 cout << "Please enter an amount less than what's in your bank. $" << stats.GETfunds()-total_bet <<endl;
   			 cin >> bet_amount;
   		 }
   		 while(bet_amount + total_bet > stats.GETfunds());
   	 }
    }
	cout <<"YOUR HAND:\n";
	display_cards(player, 2);
	cout << "\n\nTABLE:\n";
	display_cards(house, 5);
	cout <<"\n\nDEALERS HAND:\n";
	display_cards(dealer, 2);
	total_bet = total_bet + bet_amount;
	player_hand = best_hand(player_all, 7); // determines best hand for player
	dealer_hand = best_hand(dealer_all, 7); // determines best hand for dealer
	winnings = hand_compare(player_hand, dealer_hand); // compares the two values
	if(winnings == 1)
	{
    	stats.SETfunds(stats.GETfunds()+total_bet);//adds winnings to bank funds
    	cout << "You just won $" << total_bet << " !!\n";
	}
	if(winnings == -1)
	{
    	stats.SETfunds(stats.GETfunds()-total_bet);//deducts winnings from bank funds
    	cout << "You just lost $" << total_bet << " !! ;(\n";
	}
	stats.OUTPUTuser_all(); //to take down the stats of the user (i think)
	cout << "Would you like to play again? (Y/N)";
	cin >> again;
	rematch = false;
	if(again == 'Y' || again == 'y')
	{
    	rematch = true;
    	total_bet = 0.00;
	}
	}while(rematch == true);
   

	
	cin.clear();
	cin.ignore();
	return 0;
}

   

void
folding(Bank stats, double total_bet)
{
	cout << "You have decided to fold. Your bet will now be subtracted from \n"
        	<< "your account." << endl;
	stats.SETfunds(stats.GETfunds() - total_bet);
	cout << "Your current account balance is: $" << stats.GETfunds() << endl;
}