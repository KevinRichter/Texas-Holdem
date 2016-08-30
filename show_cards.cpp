// Comments are not done yet!

#include<cstdlib>
#include<ctime>
#include<iomanip>
#include<iostream>
using namespace std;

#define HEART   ((char)0x03)
#define DIAMOND ((char)0x04)
#define CLUB	((char)0x05)
#define SPADE   ((char)0x06)

#define ROW 7
#define COLUMN 2

void display_card(int [][COLUMN],int);	// Calling symbol-number functions based on 
						// number of cards has to be displayed
void symbol_number2(int,int [][COLUMN]);	// Display 2 cards 
void symbol_number3(int,int [][COLUMN]);	// Display 3 cards
void symbol_number4(int,int [][COLUMN]);	// Display 4 cards
void symbol_number5(int,int [][COLUMN]);	// Display 5 cards

int main0(){   
   int player[ROW][COLUMN];

   srand(time(0));			// Generating random numbers to check my code
   for(int i=0;i<ROW;i++){
  	 player[i][0]=rand()%13+2;
  	 player[i][1]=rand()%4+1;
  	 cout<<"Num:"<<player[i][0]<<"Sym: "<<player[i][1]<<endl;
   }

	display_card(player,2);
   display_card(player,3);
   display_card(player,1);
	display_card(player,4);
	display_card(player,5);
	system("pause");
	return 0;
}

void display_card(int card[][COLUMN],int number){

   switch (number){
  	 case 2:
  		 cout<<" ---------"<<setw(15)<<" ---------"<<endl;
  		 for(int i=0; i<6;i++){
  			 if(i==0)
  				 symbol_number2(1, card);
  			 else if(i==5)
  				 symbol_number2(2, card);
  			 else
  				 cout<<"|     	|"<<setw(15)<<"|     	|"<<endl;
  		 }
  		 cout<<" ---------"<<setw(15)<<" ---------"<<endl;
  		 break;
  	 case 3:
  		 cout<<" --------"<<setw(15)<<" --------"<<setw(15)<<" --------"<<endl;
  		 for(int i=0; i<6;i++){
  			 if(i==0)
  				 symbol_number3(1, card);
  			 else if(i==5)
  				 symbol_number3(2, card);
  			 else
  				 cout<<"|     	|"<<setw(15)<<"|     	|"<<setw(15)<<"|     	|"<<endl;
  		 }
  		 cout<<" --------"<<setw(15)<<" --------"<<setw(15)<<" --------"<<endl;
  		 break;
  	 case 4:
  		 cout<<" --------"<<setw(15)<<" --------"<<setw(15)<<" --------"<<setw(15)<<" --------"<<endl;
  		 for(int i=0; i<6;i++){
  			 if(i==0)
  				 symbol_number4(1, card);
  			 else if(i==5)
  				 symbol_number4(2, card);
  			 else
  				 cout<<"|     	|"<<setw(15)<<"|     	|"<<setw(15)<<"|     	|"<<setw(15)<<"|     	|"<<endl;
  		 }
  		 cout<<" --------"<<setw(15)<<" --------"<<setw(15)<<" --------"<<setw(15)<<" --------"<<endl;
  		 break;
  	 case 5:
  		 cout<<" --------"<<setw(15)<<" --------"<<setw(15)<<" --------"<<setw(15)<<" --------"<<setw(15)<<" --------"<<endl;
  		 for(int i=0; i<6;i++){
  			 if(i==0)
  				 symbol_number5(1, card);
  			 else if(i==5)
  				 symbol_number5(2, card);
  			 else
  				 cout<<"|     	|"<<setw(15)<<"|     	|"<<setw(15)<<"|     	|"<<setw(15)<<"|     	|"<<setw(15)<<"|     	|"<<endl;
  		 }
  		 cout<<" --------"<<setw(15)<<" --------"<<setw(15)<<" --------"<<setw(15)<<" --------"<<setw(15)<<" --------"<<endl;
  		 break;
   }
}

void symbol_number2(int num,int card[][COLUMN]){
   char person[4]={'J','Q','K','A'};
   char symbol[4]={HEART,DIAMOND,CLUB,SPADE};

  if(num==1){
 	cout<<"|";
     card[0][0]<11 ? cout<<card[0][0] : cout<<person[card[0][0]-11];
 	cout<<"   	"<<symbol[card[0][1]-1]<<"|"<<setw(5)<<"|";
     card[1][0]<11 ? cout<<card[1][0] : cout<<person[card[1][0]-11];
 	cout<<"   	"<<symbol[card[1][1]-1]<<"|"<<endl;
  }
  else{
  	cout<<"|"<<symbol[card[0][1]-1]<<"   	";
  	card[0][0]<11 ? cout<<card[0][0] : cout<<person[card[0][0]-11];
  	cout<<"|"<<setw(5)<<"|"<<symbol[card[1][1]-1]<<"   	";
  	card[1][0]<11 ? cout<<card[1][0] : cout<<person[card[1][0]-11];
     cout<<"|"<<endl;
  }
}

void symbol_number3(int num,int card[][COLUMN]){
   char person[4]={'J','Q','K','A'};
   char symbol[4]={HEART,DIAMOND,CLUB,SPADE};

   if(num==1){
 	cout<<"|";
     card[2][0]<11 ? cout<<card[2][0] : cout<<person[card[2][0]-11];
 	cout<<"   	"<<symbol[card[2][1]-1]<<"|"<<setw(5)<<"|";
     card[3][0]<11 ? cout<<card[3][0] : cout<<person[card[3][0]-11];
 	cout<<"   	"<<symbol[card[3][1]-1]<<"|"<<setw(5)<<"|";
     card[4][0]<11 ? cout<<card[4][0] : cout<<person[card[4][0]-11];
 	cout<<"   	"<<symbol[card[4][1]-1]<<"|"<<endl;
   }
   else{
  	cout<<"|"<<symbol[card[2][1]-1]<<"   	";
  	card[2][0]<11 ? cout<<card[2][0] : cout<<person[card[2][0]-11];
  	cout<<"|"<<setw(5)<<"|"<<symbol[card[3][1]-1]<<"   	";
  	card[3][0]<11 ? cout<<card[3][0] : cout<<person[card[3][0]-11];
  	cout<<"|"<<setw(5)<<"|"<<symbol[card[4][1]-1]<<"   	";
  	card[4][0]<11 ? cout<<card[4][0] : cout<<person[card[4][0]-11];
  	cout<<"|"<<endl;
  }
}

void symbol_number4(int num,int card[][COLUMN]){
   char person[4]={'J','Q','K','A'};
   char symbol[4]={HEART,DIAMOND,CLUB,SPADE};

   if(num==1){
 	cout<<"|";
     card[2][0]<11 ? cout<<card[2][0] : cout<<person[card[2][0]-11];
 	cout<<"   	"<<symbol[card[2][1]-1]<<"|"<<setw(5)<<"|";
     card[3][0]<11 ? cout<<card[3][0] : cout<<person[card[3][0]-11];
 	cout<<"   	"<<symbol[card[3][1]-1]<<"|"<<setw(5)<<"|";
     card[4][0]<11 ? cout<<card[4][0] : cout<<person[card[4][0]-11];
 	cout<<"   	"<<symbol[card[4][1]-1]<<"|"<<setw(5)<<"|";
     card[5][0]<11 ? cout<<card[5][0] : cout<<person[card[5][0]-11];
 	cout<<"   	"<<symbol[card[5][1]-1]<<"|"<<endl;
   }
   else{
  	cout<<"|"<<symbol[card[2][1]-1]<<"   	";
  	card[2][0]<11 ? cout<<card[2][0] : cout<<person[card[2][0]-11];
  	cout<<"|"<<setw(5)<<"|"<<symbol[card[3][1]-1]<<"   	";
  	card[3][0]<11 ? cout<<card[3][0] : cout<<person[card[3][0]-11];
  	cout<<"|"<<setw(5)<<"|"<<symbol[card[4][1]-1]<<"   	";
  	card[4][0]<11 ? cout<<card[4][0] : cout<<person[card[4][0]-11];
  	cout<<"|"<<setw(5)<<"|"<<symbol[card[5][1]-1]<<"   	";
  	card[5][0]<11 ? cout<<card[5][0] : cout<<person[card[5][0]-11];
  	cout<<"|"<<endl;
  }
}

void symbol_number5(int num,int card[][COLUMN]){
   char person[4]={'J','Q','K','A'};
   char symbol[4]={HEART,DIAMOND,CLUB,SPADE};

   if(num==1){
 	cout<<"|";
     card[2][0]<11 ? cout<<card[2][0] : cout<<person[card[2][0]-11];
 	cout<<"   	"<<symbol[card[2][1]-1]<<"|"<<setw(5)<<"|";
     card[3][0]<11 ? cout<<card[3][0] : cout<<person[card[3][0]-11];
 	cout<<"   	"<<symbol[card[3][1]-1]<<"|"<<setw(5)<<"|";
     card[4][0]<11 ? cout<<card[4][0] : cout<<person[card[4][0]-11];
 	cout<<"   	"<<symbol[card[4][1]-1]<<"|"<<setw(5)<<"|";
     card[5][0]<11 ? cout<<card[5][0] : cout<<person[card[5][0]-11];
 	cout<<"   	"<<symbol[card[5][1]-1]<<"|"<<setw(5)<<"|";
     card[6][0]<11 ? cout<<card[6][0] : cout<<person[card[6][0]-11];
 	cout<<"   	"<<symbol[card[6][1]-1]<<"|"<<endl;
   }
   else{
  	cout<<"|"<<symbol[card[2][1]-1]<<"   	";
  	card[2][0]<11 ? cout<<card[2][0] : cout<<person[card[2][0]-11];
  	cout<<"|"<<setw(5)<<"|"<<symbol[card[3][1]-1]<<"   	";
  	card[3][0]<11 ? cout<<card[3][0] : cout<<person[card[3][0]-11];
  	cout<<"|"<<setw(5)<<"|"<<symbol[card[4][1]-1]<<"   	";
  	card[4][0]<11 ? cout<<card[4][0] : cout<<person[card[4][0]-11];
  	cout<<"|"<<setw(5)<<"|"<<symbol[card[5][1]-1]<<"   	";
  	card[5][0]<11 ? cout<<card[5][0] : cout<<person[card[5][0]-11];
  	cout<<"|"<<setw(5)<<"|"<<symbol[card[6][1]-1]<<"   	";
  	card[6][0]<11 ? cout<<card[6][0] : cout<<person[card[6][0]-11];
  	cout<<"|"<<endl;
  }
}