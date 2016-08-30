/*
*  holdem.h
*  Holdem
*
*  Created by Team Recursion on 12/3/11.
*  Copyright 2011 __Team Recursion__. All rights reserved.
*
*	DIRECTIONS:
*	
*	STEP 1: ADD FUNCTION PROTOTYPES
*
*	NOTE: BRENDAN SINCE YOU USED A CLASS I MADE A SEPARATE
*	HEADER FILE FOR YOU AND YOU DON'T NEED TO ADD PROTOTYPES
*/

#ifndef HOLDEM_H
#define HOLDEM_H

#include "bank_class.h"
// NOTE: CREATE FUNCTION PROTOTYPES LIKE THESE IN THIS HEADER FILE FOR >> ALL << YOUR FUNCTIONS
#define COLUMN 2
// BEGIN SPLASH.CPP PROTOTYPES (AARON)
void sysPause();
void gameFirstRun ();
void splashTexas();
void splashHoldem();
void splashCredits(string t);
char splashNewGame();
char beginGame();
// END SPLASH.CPP PROTOTYPES
// BEGIN USER.CPP PROTOTYPES (CHARMAINE)
char Main_Menu();
void bankUser(char);
void rules();
// END USER.CPP PROTOTYPES
// BEGIN START_GAME.CPP PROTOTYPES (CHARMAINE)
double start_game();
void folding();
// END START_GAME.CPP PROTOTYPES
// BEGIN SHOW_CARDS.CPP PROTOTYPES (FARIN)
void show_Cards(int n);
void display_card(int card[][COLUMN],int number);
void symbol_number2(int num,int card[][COLUMN]);
void symbol_number3(int num,int card[][COLUMN]);
void symbol_number4(int num,int card[][COLUMN]);
void symbol_number5(int num,int card[][COLUMN]);
// END SHOW_CARDS.CPP PROTOTYPES

// BEGIN BUILD_ARRAYS.CPP PROTOTYPES (AARON)
void build_arrays(string player_all[], int pa, string player[], int p, string dealer_all[], int da, string dealer[], int d, string house[], int h);
// END YOURS.CPP PROTOTYPES 
// BEGIN CALC_WINNER.CPP PROTOTYPES (KEVIN)
string high_card(int card);
double best_hand (string hand[], int ar_size);
int hand_compare(double player, double dealer);
string high_card(int card);
void display_cards(string hand[], int num_cards);
// END CALC_WINNER.CPP
// BEGIN START_GAME.CPP PROTOTYPES (CHARMAINE)
double start_game(Bank stats);
// END SHOW_CARDS.CPP PROTOTYPES (CHARMAINE)

#endif