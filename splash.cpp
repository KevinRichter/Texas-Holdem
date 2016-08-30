// Updated
/*
 *  splash.cpp
 *  Splash
 *
 *  Created by Aaron Feldman on 12/3/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

// BEGIN FIX SLEEP PROGRAM FOR UNIX/WINDOWS/OSX COMPATABILITY
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#define SLP(n) (Sleep(n*1000))
#define isWIN 1 // for possibly auto resizing the command screen

#else
#define SLP(n) (sleep(n))
#define isWIN 0

#endif
// END FIX SLEEP PROGRAM FOR UNIX/WINDOWS/OSX COMPATABILITY

void sysPause() { // cross platform compatible pause
    cout <<"Press ENTER to continue ...";
    cin.get();
   getchar;
}
void gameFirstRun (){
	// ########### Begin only for first run  ##################
	//if (!isWIN) {
		for (int i=0; i<50; i++) { // portable clear screen
			cout << endl;
		}
		cout << endl << "                              For Best Experience";
		cout << endl << "                          Please Increase Window Size";
		cout << endl;
		for (int i=0; i<9; i++) { // vert align text
			cout << endl;
		}
		sysPause();
	//}
	
	// ########### End only for first run  ##################
	
	// ########### Begin Windows Only Resize Window #########
	/*
	if (isWIN) {
		for (int i=0; i<50; i++) { // portable clear screen
			cout << endl;
		}
		cout << endl << "                                Resizing Window";
		cout << endl << "                              For Best Experience";
		cout << endl;
		for (int i=0; i<9; i++) { // vert align text
			cout << endl;
		}
		
		HWND console = GetConsoleWindow();
		RECT r;
		GetWindowRect(console, &r); //stores the console's current dimensions
		 
		//MoveWindow(window_handle, x, y, width, height, redraw_window);
		MoveWindow(console, r.left, r.top, 800, 600, TRUE);
		for (int j = 0; j < 100; ++j)
		{
		for (int i = 0x41; i < 0x5B; ++i)
		cout << (char)i;
		}
		cout << endl;
		SLP(1);
		MoveWindow(console, r.left, r.top, r.right - r.left, r.bottom - r.top, TRUE);
	}
	 */
	// ########### End Windows Only Resize Window #########
} 

void splashTexas(){
	cout << endl << "               ::::::::::: :::::::::: :::    :::     :::      ::::::::";
	cout << endl << "                  :+:     :+:        :+:    :+:   :+: :+:   :+:    :+:";
	cout << endl << "                 +:+     +:+         +:+  +:+   +:+   +:+  +:+ ";
	cout << endl << "                +#+     +#++:++#     +#++:+   +#++:++#++: +#++:++#++";
	cout << endl << "               +#+     +#+         +#+  +#+  +#+     +#+        +#+";
	cout << endl << "              #+#     #+#        #+#    #+# #+#     #+# #+#    #+#";
	cout << endl << "             ###     ########## ###    ### ###     ###  ########";
}
void splashHoldem(){
	cout << endl << "          :::    :::  ::::::::  :::        :::::::::  ::::::::::   :::   :::";
	cout << endl << "         :+:    :+: :+:    :+: :+:        :+:    :+: :+:         :+:+: :+:+:";
	cout << endl << "        +:+    +:+ +:+    +:+ +:+        +:+    +:+ +:+        +:+ +:+:+ +:+";
	cout << endl << "       +#++:++#++ +#+    +:+ +#+        +#+    +:+ +#++:++#   +#+  +:+  +#+";
	cout << endl << "      +#+    +#+ +#+    +#+ +#+        +#+    +#+ +#+        +#+       +#+";
	cout << endl << "     #+#    #+# #+#    #+# #+#        #+#    #+# #+#        #+#       #+#";
	cout << endl << "    ###    ###  ########  ########## #########  ########## ###       ###";
}

void splashCredits(string t){
	splashHoldem();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl << "                            ";
	cout << t;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout.flush();
	SLP(1);
	for (int i=0; i<50; i++) { // portable clear screen
		cout << endl;
	}
}
char splashNewGame(){
	char I;
	string temp;
	splashHoldem();
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                                  MAIN MENU";
	cout << endl << "     ";
	cout << "(1) New User (2) Existing User (3) Best Scores (4) Rules (5) Quit ";
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl << ">> ";
	//cout.flush();
	getline(cin, temp);
	while (temp[0]!='1' && temp[0]!='2' && temp[0]!='3' && temp[0]!='4' && temp[0]!='5') {
		cout << "Invaild Entry, Try Again";
		cout << endl << ">> ";
		getline(cin, temp);
	}
	I=temp[0];
	return I;
}

char beginGame(){
	char I='a';
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
	SLP(3);
	for (int i=0; i<50; i++) { // portable clear screen
		cout << endl;
	}
	splashHoldem();
	for (int i=0; i<8; i++) { // vert align text
		cout << endl;
	}
	cout.flush();
	SLP(3);
	for (int i=0; i<50; i++) { // portable clear screen
		cout << endl;
	}
	splashCredits("Produced by Team Recursion");
	splashCredits("     Charmaine Ching");
	splashCredits("      Aaron Feldman");
	splashCredits("      Negin Kialoni");
	splashCredits("       Brendan Ly");
	splashCredits("      Farin Namdari");
	splashCredits("      Kevin Richter");
	I=splashNewGame();
	return I;
}