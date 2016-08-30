//Updated 12/6/11 12:19pm
/*
*  user.cpp
*  Final Project
*
*  Created by Charmaine on 12/4/11.
*  Copyright 2011 __MyCompanyName__. All rights reserved.
*
*/

#include <iostream>
#include "holdem.h"
using namespace std;
// NEED FOR SLP FUNCTION
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#define SLP(n) (Sleep(n*1000))
#define isWIN 1 // for possibly auto resizing the command screen
#else
#define SLP(n) (sleep(n))
#define isWIN 0
#endif
// END SLP FUNCTION DEFINE
char Main_Menu(){
	char I;
	string temp;
	for (int i=0; i<50; i++) { // portable clear screen
    	cout << endl;
	}
	for (int i=0; i<50; i++) { // portable clear screen
    	cout << endl;
	}
	splashTexas();
	for (int i=0; i<8; i++) { // vert align text
    	cout << endl;
	}
	cout.flush();
	SLP(1);
	for (int i=0; i<50; i++) { // portable clear screen
    	cout << endl;
	}
	splashHoldem();
	for (int i=0; i<8; i++) { // vert align text
    	cout << endl;
	}
	cout.flush();
	SLP(1);
	for (int i=0; i<50; i++) { // portable clear screen
    	cout << endl;
	}
	splashHoldem();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                              	MAIN MENU";
	cout << endl << " 	";
	cout << "(1) New User (2) Existing User (3) Best Scores (4) Rules (5) Quit ";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl << ">> ";
	//cout.flush();
	//cin.get();
	getline(cin, temp);
	while (temp[0]!='1' && temp[0]!='2' && temp[0]!='3' && temp[0]!='4' && temp[0]!='5') {
    	cout << "Invalid Entry, Try Again";
    	cout << endl << ">> ";
    	getline(cin, temp);
	}
	I=temp[0];
	return I;
}
void bankUser(char I) {
	string temp;
	bool valid=true;
	Bank user;
	
	do {
    	// INITALIZE YOUR GAME PLAY FUNCTIONS HERE!
    	switch (I) {
        	case '1':
    valid=true;
            	user.CREATEuser();
            	start_game(user);
user.SETnum(-1);
    I=Main_Menu();
            	break;
        	case '2':
    valid=true;
           		if ( user.FINDuser() == 1 )
   			{
   				 start_game(user);
 user.SETnum(-1);
   			}
    I=Main_Menu();
            	break;
        	case '3':
    valid=true;
   		user.INPUTuser_all();
            	user.DISPLAYscores();
    I=Main_Menu();
            	break;
        	case '4':
    valid=true;
            	rules();
             
    I=Main_Menu();
            	break;
        	case '5':
            	valid=false;
            	break;
        	default :
            	break;
    	}  
	}while (valid);
}
void rules(){
	for (int i=0; i<50; i++) { // portable clear screen
    	cout << endl;
	}
	cout << "   TEXAS HOLD'EM RULES: \n\n";
	cout << "1) Player places a bet \n";
	cout << "2) Player is dealt two cards and are to place another bet. \n"
     	<< "   Player can either bet more money or fold\n";
	cout << "3) After decision is made, dealer deals three cards face \n"
     	<< "   up. There are community cards and player may use this as part of \n"
     	<< "   his/her final hand\n";
	cout << "4) Player can either bet more money or fold\n";
	cout << "5) Dealer deals a fourth card into community cards\n";
	cout << "6) Player can either bet more money or fold\n";
	cout << "7) Dealer deals a fifth card into community cards, the final card \n"
     	<< "   Then a final bet or a fold can be made.\n";
	cout << "8) If players hand is better than dealers hand you win and \n"
     	<< "   money will be added into your account\n\n\n";
	sysPause(); // multi IOS compatible pause.
}