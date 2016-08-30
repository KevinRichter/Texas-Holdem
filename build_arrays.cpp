// Finished
/*
 *  build_arrays.cpp
 *  Splash
 *
 *  Created by Aaron Feldman on 12/3/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 *
 * To shuffle and get new player dealer hands
 * call build_arrays func() from main or include holdem.h and call from your function
 *
 *  example: build_arrays(player_all, player, dealer_all, dealer, house);
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

using namespace std;

void build_arrays(string player_all[], int pa, string player[], int p, string dealer_all[], int da, 
				  string dealer[], int d, string house[], int h){
	string myCards[] = {"D02", "D03", "D04", "D05", "D06", "D07", "D08", "D09", "D10", "D11", "D12", "D13" , "D14",
		"H02", "H03", "H04", "H05", "H06", "H07", "H08", "H09", "H10", "H11", "H12", "H13", "H14",
		"S02", "S03", "S04", "S05", "S06", "S07", "S08", "S09", "S10", "S11", "S12", "S13", "S14",
		"C02", "C03", "C04", "C05", "C06", "C07", "C08", "C09", "C10", "C11", "C12", "C13", "C14"};
	
	vector<string> vect (myCards, myCards + sizeof(myCards) / sizeof(string) ); // create vector for shuffling
	
	srand ( time(NULL) ); // generate random number for greater randomization in random_shuffle
	int n = rand() % 10 + 1;
	
	for (int i=0; i<n; i++) {  // random shuffle vect
		random_shuffle (vect.begin(), vect.end() );
	}
	
	for (int i=0; i<5; i++) { // filling the house array
		house[i]=vect[i];
		player_all[i]=vect[i];
		dealer_all[i]=vect[i];
	}
	
	for (int i=0; i<2; i++) { // filling the player array and player_all array
		player[i]=vect[i+5];
		player_all[i+5]=vect[i+5];
	}
	for (int i=0; i<2; i++) { // filling the dealer array and dealer_all array
		dealer[i]=vect[i+7];
		dealer_all[i+5]=vect[i+7];
	}
}