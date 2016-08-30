/*
 *  calc_winner.cpp
 *  Splash
 *
 *  Created by Kevin on 12/4/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

struct card
{
   int Num;
   string Suit;
};

string high_card(int card);

double
best_hand (string hand[], int ar_size)
{
	card N[7];
	int spade=0, diamond=0, heart=0, club=0;
	int spade_high[7];
	int diamond_high[7];
	int heart_high[7];
	int club_high[7];
	string temp;
	for(int i = 0; i < 7; i++)
	{
		N[i].Suit = hand[i].substr(0,1);
		temp = hand[i].substr(1,2);
		N[i].Num = atoi(temp.c_str());
	}
   string tempS;
   int tempN;
   double hand_value = 0.00; //this is the return value that is used in the compare_hand function
   for (int j =0; j < 7; j++)
   {
  	 for (int i = 0; i < 6; i++)//sorting numbered cards from highest to lowest
  	 {
  		 if (N[i].Num < N[i+1].Num)//sorting in descending order, keeping the suits paired with the correct number card
  		 {
  			 tempN = N[i].Num;
  			 tempS = N[i].Suit;
  			 N[i].Num = N[i+1].Num;
  			 N[i].Suit = N[i+1].Suit;
  			 N[i+1].Num = tempN;
  			 N[i+1].Suit = tempS;
  		 }
  	 }
   }
   for (unsigned int i = 0; i < 3; i++)//checking for 'Straight Flush' or 'Royal Flush'
   {
  	 if(((N[i].Suit[0] == N[i+1].Suit[0]) && (N[i+1].Suit[0] == N[i+2].Suit[0]) && (N[i+2].Suit[0] == N[i+3].Suit[0]) &&
  		 (N[i+3].Suit[0] == N[i+4].Suit[0]))&&(N[i].Num == (N[i+1].Num+1) && (N[i+1].Num) == (N[i+2].Num+1) && (N[i+2].Num)
  		 == (N[i+3].Num+1) && (N[i+3].Num) == (N[i+4].Num+1)))
  	 {
  		 hand_value = 9 + (N[i].Num * .01);//This adds a decimel value to the hand_value to determined tie-breaking situations using high card
  		 if(N[i].Num == 14)
  			 hand_value = 10;//If high card is an Ace, then it's a royal flush
  		 return (hand_value);
  	 }
   }
   for (unsigned int i = 0; i < 4; i++)//checking for 'Four of a Kind'
   {
  	 if(N[i].Num == N[i+1].Num && N[i+1].Num == N[i+2].Num && N[i+2].Num == N[i+3].Num)
  	 {
  		 hand_value = 8 + (N[i].Num * .01);//This adds a decimel value to the hand_value to determined tie-breaking situations using high card
  		 return (hand_value);
  	 }
   }
   for (unsigned int i = 0; i < 5; i++)//checking for 'Full House' part 1
   {
  	 if(N[i].Num == N[i+1].Num && N[i+1].Num == N[i+2].Num)
  	 {
		 for(int j= i+3; j < 6; j++)
		 {
			 if(N[j].Num == N[j+1].Num)
			 {
  				hand_value = 7 + (N[i].Num * .01);//This adds a decimel value to the hand_value to determined tie-breaking situations using high card
  				return (hand_value);
			 }
		 }
  	 }
   }
	for (unsigned int i = 0; i < 6; i++)//checking for 'Full House' part 2
   {
  	 if(N[i].Num == N[i+1].Num)
  	 {
		 for(int j= i+2; j < 5; j++)
		 {
			 if(N[j].Num == N[j+1].Num && N[i+1].Num == N[i+2].Num)
			 {
  				hand_value = 7 + (N[i].Num * .01);//This adds a decimel value to the hand_value to determined tie-breaking situations using high card
  				return (hand_value);
			 }
		 }
  	 }
   }
   for (unsigned int i = 0; i < 7; i++)//checking for 'Flush'
   {
  	 if(N[i].Suit == "S")
	   {
		 spade_high[spade] = N[i].Num;
		 spade++;
	   }
	 if(N[i].Suit == "H")
	   {
		 heart_high[heart] = N[i].Num;
		 heart++;
	   }
	 if(N[i].Suit == "D")
	   {
		 diamond_high[diamond] = N[i].Num;
		 diamond++;
	   }
	 if(N[i].Suit == "C")
	   {
		 club_high[club] = N[i].Num;
		 club++;
	   }
	 if(spade == 5)	
  	   {
  		 hand_value = 6 + (spade_high[0] * .01 + spade_high[1]*.0001);//This adds a decimel value to the hand_value to determined tie-breaking situations using high card
  		 return (hand_value);
  	   }
	 if(heart == 5)	
  	   {
  		 hand_value = 6 + (heart_high[0] * .01 + heart_high[1]*.0001);//This adds a decimel value to the hand_value to determined tie-breaking situations using high card
  		 return (hand_value);
  	   }
	 if(diamond == 5)	
  	   {
  		 hand_value = 6 + (diamond_high[0] * .01 + diamond_high[1]*.0001);//This adds a decimel value to the hand_value to determined tie-breaking situations using high card
  		 return (hand_value);
  	   }
	 if(club == 5)	
  	   {
  		 hand_value = 6 + (club_high[0] * .01 + club_high[1]*.0001);//This adds a decimel value to the hand_value to determined tie-breaking situations using high card
  		 return (hand_value);
  	   }
   }

   for (unsigned int i = 0; i < 3; i++)//checking for 'Straight'
   {
  	 if(N[i].Num == (N[i+1].Num+1) && (N[i+1].Num) == (N[i+2].Num+1) && (N[i+2].Num)
  		 == (N[i+3].Num+1) && (N[i+3].Num) == (N[i+4].Num+1))
  	 {
  		 hand_value = 5 + (N[i].Num * .01 + .001);//This adds a decimel value to the hand_value to determined tie-breaking situations using high card
  		 return (hand_value);
  	 }
   }
   for (unsigned int i = 0; i < 5; i++)//checking for 'Three of a Kind'
   {
  	 if(N[i].Num == N[i+1].Num && N[i+1].Num == N[i+2].Num)
  	 {
  		 hand_value = 4 + (N[i].Num * .01 + N[0].Num *.0001);//This adds a decimel value to the hand_value to determined tie-breaking situations using high card
  		 return (hand_value);
  	 }
   }
   for (unsigned int i = 0; i < 6; i++)//checking for a 'Pair'
   {
  	 if(N[i].Num == N[i+1].Num)
  	 {
  		 hand_value = 2 + (N[i].Num * .01 + N[0].Num * .000001);//This adds a decimel value to the hand_value to determined tie-breaking situations using high card
  		 for(unsigned int j = i+2; j < 6; j++)
  		 {
  			 if(N[j].Num == N[j+1].Num)
  				 hand_value = 3 + (N[i].Num * .01 + N[j].Num * .0001 + N[0].Num * .000001);//This checks for 2 pair
  		 }
  		 return (hand_value);
  	 }
   }
   hand_value = 1 + (N[0].Num * .01 + .001);//Assigns value for high card, if that is the best hand.
   return (hand_value);
}

int
hand_compare(double player, double dealer)
{
	int winning_value;//use this value (-1:dealer, 0:tie, 1:player) to determine who gets money
   double winner;
   if (player > dealer)
   {
  	 winner = player;
	 winning_value = 1;
  	 cout << "Congratulations! You Win!! You won with a ";
   }
   else if(player < dealer)
   {
  	 winner = dealer;
	 winning_value = -1;
  	 cout << "Sorry, you lose. The dealer won with a ";
   }
	else
	{
		winner = player;
		winning_value = 0;
		cout << "You tied with the dealer. You both had a ";
	}
   if(winner < 2)
   {
  	 cout << high_card((winner-1)*100) << " High!\n";
  	 return winning_value;
   }
   if(winner < 3)
   {
  	 cout <<"Pair of " << high_card((winner-2.00)*100) << "'s\n";
  	 return winning_value;
   }
   if(winner < 4)
   {
  	 cout << "Two Pair!\n";
  	 return winning_value;
   }
   if(winner < 5)
   {
  	 cout << "Three of a Kind!\n";
  	 return winning_value;
   }
   if(winner < 6)
   {
  	 cout << high_card((winner-5.00)*100) << " high Straight!\n";
  	 return winning_value;
   }
   if(winner < 7)
   {
  	 cout << high_card((winner-6.00)*100) << " high Flush!\n";
  	 return winning_value;
   }
   if(winner < 8)
   {
  	 cout << "Full House!\n";
  	 return winning_value;
   }
   if(winner < 9)
   {
  	 cout << "Four of a Kind!\n";
  	 return winning_value;
   }
   if(winner < 10)
   {
  	 cout << high_card((winner-9)*100) << " high Straight Flush!\n";
  	 return winning_value;
   }
   if(winner < 11)
   {
  	 cout << "Royal Flush!\n";
  	 return winning_value;
   }
}
string
high_card(int card)
{
	string card_type;
	switch(card)
{
case 2:
	card_type = "Two";
	break;
case 3:
	card_type = "Three";
	break;
case 4:
	card_type = "Four";
	break;
case 5:
	card_type = "Five";
	break;
case 6:
	card_type = "Six";
	break;
case 7:
	card_type = "Seven";
	break;
case 8:
	card_type = "Eight";
	break;
case 9:
	card_type = "Nine";
	break;
case 10:
	card_type = "Ten";
	break;
case 11:
	card_type = "Jack";
	break;
case 12:
	card_type = "Queen";
	break;
case 13:
	card_type = "King";
	break;
case 14:
	card_type = "Ace";
	break;
default:
	card_type = "NoCard";
	break;
}
return card_type;
}