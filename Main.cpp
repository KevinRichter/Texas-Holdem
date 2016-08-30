/* The idea is to have a functional running program (beta build), that we can compile and debug.

To compile:
 simply add the files to visual studio and compile...
*/

#include <iostream>
using namespace std;

// BEGIN FIX SLEEP PROGRAM FOR UNIX/WINDOWS/OSX COMPATABILITY
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>
#define SLP(n) (Sleep(n*1000))
#define isWIN 1 // for possibly auto resizing the command screen

#else
#include <unistd.h>
#define SLP(n) (sleep(n))
#define isWIN 0

#endif
// END FIX SLEEP PROGRAM FOR UNIX/WINDOWS/OSX COMPATABILITY


#include "holdem.h" // add your prototypes to this file 


int main () {
	
	char I; // var for splash screen menu
	
	fstream input("userstats.txt"); // need this here to create database file
	if (!input) {
		ofstream one ("userstats.txt"); // alternate open file for ios compatability.
		one.close();
		input.clear();
		fstream input("userstats.txt");
		input.close();
	}
	if (!input) {
		cout <<"\nError Opening File!";
	}
	
	Bank user; // After fstream input declaration to get rid of initial make user before program begins
	
	// Begin Show Enterance Screen
	gameFirstRun (); // resize window instructions
	I=beginGame();
	// End Show Enterance Screen
	
	
	
	//build_arrays(player_all, player, dealer_all, dealer, house); // shuffle cards, rebuild arrays
	
	bankUser(I); 
	
	
	// Show Exit Screen
	for (int i=0; i<50; i++) { // portable clear screen
		cout << endl;
	}
	cout << "                              Thank You For Playing";
	for (int i=0; i<9; i++) { // vert align text
		cout << endl;
	}
	cout.flush();
	SLP(3);
	return 0;
}