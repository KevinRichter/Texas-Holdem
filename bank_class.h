/*

***UPDATE*** 12/6/2011
-Fixed issues when combining the bank class with game.


 *  bank_class.h
 *  Splash
 *
 *  Created by Brendan on 12/4/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
/*
 // added a fix to pause after displaying scores
 //   Team**UPDATE Bank class is finished
 //   Instructions on how to use the Bank Class
 
 -If user selects create account, call var.CREATEuser() where ‘var’ is:
 int main()
 {
 Bank var;
 (…)
 return 0;
 }
 The function will already ask user to input a name and set their starting money so if they choose to create a new user, just call the function.
 
 -If user selects to log in, call var.FINDuser(). The function will already ask user to input a name to log in with.
 
 -If user is done playing, call var.OUTPUTuser_all(). The function will save and rewrite the text file with new user data.
 
 -Any changes to the account amount will need to use var.SETfunds(x), where x is the amount you want to set it to. For example, if you want to add $50:
 var.SETfunds(GETfunds() + 50);
 This will GET the current amount in the account and add 50 to it, and then set it to funds.
 
 If something else is needed from the bank class, let me know ASAP so I can get it done!
 Good work team!
 --Brendan

***UPDATE*** 12/5/2011

//NEW FUNCTION
-If user wants to see top 5 scores, call var.DISPLAYscores().

//NOTES
-By the way, using var.OUTPUTuser_all() does not display any data on the screen. Call this function when you want to save all current data to “userstats.txt”.

-New changes to bank class also save the file sorted with lowest score at the top and highest score at the bottom, when the game quits.

--Brendan


 
 */

#ifndef BANK_CLASS_H
#define BANK_CLASS_H


/*************************************************
//CISP400 FINAL PROJECT
//Bank Class
*************************************************/
#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>
#include<fstream>
    using namespace std;
/*************************************************
//CLASS
//
*************************************************/
class Bank
{
private:
    string name;
    int num;
    double funds;
    vector<double> scores;

public:
    vector<string> user_all;
    Bank()
    {
   	 SETname("");
   	 SETnum(-1);
   	 SETfunds(0);

   	 INPUTuser_all();
    }
/*************************************************
//SET FUNCTIONS
//
*************************************************/
    void SETname(string in_string)
    {
   	 name = in_string;
    }
    void SETnum(int in_int)
    {
   	 num = in_int;
    }
    void SETfunds(double in_double)
    {
   	 funds = in_double;
    }
/*************************************************
//GET FUNCTIONS
//
*************************************************/
    string GETname()
    {
   	 return name;
    }
    int GETnum()
    {
   	 return num;
    }
    double GETfunds()
    {
   	 return funds;
    }
/*************************************************
//IF FUNDS EQUAL 0
//Asks user if they want to borrow another 5000
*************************************************/
    void IFfunds_0()
    {
   	 int choice;
   	 if (funds == 0)
   	 {
   		 cout << endl;
   		 cout << "You have ran out of money." << endl;
   		 cout << "Would you like to borrow another $5000.00?" << endl;
   		 cout << "(1: Yes, 0: No): ";
   		 cin >> choice;
   		 while ( (choice != 1) && (choice != 0) || cin.fail() )
   		 {
   			 cin.clear();
   			 cin.ignore(200, '\n');
   			 cout << endl;
   			 cout << "Would you like to borrow another $5000.00?" << endl;
   			 cout << "(1: Yes, 0: No): ";
   			 cin >> choice;
   		 }
   		 if ( choice == 1 )
   		 {
   			 cout << endl;
   			 cout << "$5000.00 have been added to your account.";
   			 funds += 5000;
   		 }

   	 }
    }
/*************************************************
//INPUT ALL USERS
//Initialization and inputs all user stats
*************************************************/
    void INPUTuser_all()
    {
   	 int i = 0,
   		 choice;
   	 double num;
   	 string temp,
   		 temp2;
   	 ifstream input;
   	 input.open("userstats.txt");
   	 if ( !input.is_open() )
   	 {
   		 cout << endl;
   		 cout << "File \"userstats.txt\" was not found. Create new user?" << endl;
   		 cout << "(1: Yes, 0: No): ";
   		 cin >> choice;
   		 if (choice == 1)
   		 {
   			 CREATEuser();
   		 }
   		 else
   		 {
   			 exit(777);
   		 }
   	 }
   	 else
   	 {
   		 user_all.clear();
   		 scores.clear();
   		 while ( !input.eof() )
   		 {
   			 user_all.resize(user_all.size() + 1);
   			 getline(input, user_all[i]);
   			 i++;
   		 }
   		 for (i = 0; i < (int)user_all.size(); i++)
   		 {
   			 temp = user_all[i];
   			 temp2 = "";
   			 for (int j = 1; j < (int)temp.size(); j++)
   			 {
   				 if ( temp[j-1] == '$' )
   				 {
   					 for (int k = j; k < (int)temp.size(); k++)
   					 {
   						 temp2 += temp[k];
   					 }
   					 j = temp.size();
   				 }
   			 }
   			 scores.push_back(strtod(temp2.c_str(), NULL));
   		 }
   		 i = 1;
   		 while (i == 1)
   		 {
   			 i = 0;
   			 for (int j = 0; j < (int)scores.size()-1; j++)
   			 {
   				 if ( scores[j] > scores[j+1] )
   				 {
   					 num = scores[j+1];
   					 temp = user_all[j+1];
   					 scores[j+1] = scores[j];
   					 user_all[j+1] = user_all[j];
   					 scores[j] = num;
   					 user_all[j] = temp;
   					 i = 1;
   				 }
   			 }
   		 }
   	 }
   	 if ( user_all[0] == "" )
   	 {
   		 user_all.erase(user_all.begin());
   	 }
   	 if ( user_all.size() == 0 )
   	 {
   		 num = -2;
   	 }
   	 input.close();
   	 return;
    }
/*************************************************
//CREATE USER
//Creates a new user
*************************************************/
    void CREATEuser()
    {
   	 string temp;
   	 cout << "Enter a user name: ";
   	 getline(cin, temp);
   	 cout << endl;
   	 for (int i = 0; i < (int)temp.size(); i++)
   	 {
   		 temp[i] = toupper(temp[i]);
   	 }
   	 SETname(temp);
   	 SETfunds(5000);
   	 num = user_all.size();
   	 user_all.resize(user_all.size() + 1);
   	 return;
    }
/*************************************************
//FIND USER
//Finds a user with user input and sets name and funds to its values
*************************************************/
    int FINDuser()
    {
   	 int yes = 1;
   	 string temp,
   		 temp_comp,
   		 in_user;

   	 if ( num == -2 )
   	 {
   		 cout << "No user data was found. Please create a new user." << endl;
   		 yes = 0;
   		 cout <<"Press ENTER to continue ...";
   		 cin.get();
   	 }
   	 else
   	 {
   		 cout << "Enter your user name: ";
   		 getline(cin, in_user);
   		 cout << endl;
   		 
   		 //Prepares string compare by capitolizing all letters of user input
   		 for (int i = 0; i < (int)in_user.size(); i++)
   		 {
   			 in_user[i] = toupper(in_user[i]);
   		 }

   		 //Seperates string's user name from its money amount and then sets name
   		 for ( int i = 0; i < (int)user_all.size(); i++ )
   		 {
   			 temp = user_all[i];
   			 temp_comp = "";
   			 for ( int j = 0; j < (int)temp.size(); j++)
   			 {
   				 if ( (temp[j+1] != '$') )
   				 {
   					 temp_comp += temp[j];
   				 }
   				 else
   				 {
   					 j = temp.size();
   				 }
   			 }
   			 if ( temp_comp.compare(in_user) == 0 )
   			 {
   				 //Sets name
   				 name = temp_comp;
   				 num = i;
   				 i = user_all.size();
   				 temp_comp = "";
   				 
   				 //Seperate money from user name and sets funds
   				 for (int j = 1; j < (int)temp.size(); j++)
   				 {
   					 //After dollar sign is "detected", sets everything after it to be money
   					 if (temp[j-1] == '$')
   					 {
   						 for (int k = j; k < (int)temp.size(); k++)
   						 {
   							 temp_comp += temp[k];
   						 }
   						 j = temp.size();
   					 }
   				 }

   				 //Sets funds
   				 funds = strtod(temp_comp.c_str(), NULL);
   			 }
   		 }
   	 }
   	 if ( (num == -1)&&(yes == 1) )
   	 {
   		 cout << "User was not found." << endl;
   		 yes = 0;
   		 cout <<"Press ENTER to continue ...";
   		 cin.get();
   	 }
   	 return yes;
    }
/*************************************************
//DISPLAY SCORES
//Displays top 5 scores
*************************************************/
    void DISPLAYscores()
    {
   	 int i;
   	 int j = 1;
   	 int got_in = 0;
   	 cout << endl;
   	 cout << "----------" << endl;
   	 cout << "TOP SCORES" << endl;
   	 cout << "----------" << endl;
   	 for (i = user_all.size()-1; i > (int)user_all.size() - 6; i--)
   	 {
   		 if ( (i >= 0)&&(user_all[i] != "") )
   		 {
   			 cout << j << ". " << user_all[i] << endl;
   			 j++;
   			 got_in = 1;
   		 }
   	 }
   	 if (got_in == 0)
   	 {
   		 cout << "No scores available to display." << endl << endl;
   	 }
   	 cout <<"Press ENTER to continue ...";
   	 cin.get();
   	 return;
    }
/*************************************************
//OUTPUT USER
//Outputs all data
*************************************************/
    void OUTPUTuser_all()
    {
   	 ofstream output;
   	 output.open("userstats.txt");
   	 user_all[num] = "";
   	 user_all[num] += name;
   	 user_all[num] += " $";
   	 for ( int i = 0; i < (int)user_all.size(); i++)
   	 {
   		 if (i != num)
   		 {
   			 if ( i == user_all.size()-1 )
   			 {
   				 output << user_all[i];
   			 }
   			 else
   			 {
   				 output << user_all[i] << endl;
   			 }
   				 
   		 }
   		 else
   		 {
   			 if ( i == user_all.size()-1 )
   			 {
   				 output << user_all[num] << funds;
   			 }
   			 else
   			 {
   				 output << user_all[num] << funds << endl;
   			 }

   		 }
   	 }
   	 output.close();
   	 return;
    }

};
#endif