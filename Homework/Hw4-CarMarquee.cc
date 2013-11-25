/*
There is a Car of dynamic marquee in 60*7 LED screen.
*/

#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;
int main(){
  const int S=6;           //high of car
  const int N=60;          //width of screen
  int i,j,n,r,c,v=0;
  unsigned int b[S]={262128,131088,131103,131073,212943,49200};  //draw down the car
  
  cout << "\x1b[2J" << flush ;
  int d;
  int k=0;
  
  for( d = 0 ; d <= N+18 ; ++d ){   //draw the car,then clear the screen
    if( d > 60 )v++;
    for( i = 0 ; i < S ; ++i ){  //print the column of the car
      if( d < 18 )  //car appear
      { 
	r=i+3;
	c=1;
	cout << "\x1b[" << r << ";" << c << "H" ; 
	for( j = d-1 ; j >= 0 ; --j ){
	  cout << (b[i]&(1<<j)? "*" : " " );
	}
      }else if( d > 42+17 ){     //car disappear
      r=i+3;
      c=d-17;
      cout << "\x1b[" << r << ";" << c << "H" ;
      for ( j = 17 ; j >= v ; --j ){
        cout << (b[i]&(1<<j)? "*" : " " );
      }
      
      }else{                    //the car is running
      r=i+3;
      c=d-17;
      cout << "\x1b[" << r << ";" << c << "H" ;
      for ( j = 17 ; j >= 0 ; --j ){
        cout << (b[i]&(1<<j)? "*" : " " );                
      }   
    }      
    cout << flush ;             
  } 
  usleep(100000);
  cout << "\x1b[2J" << flush ;         //clear the screen
  
  
  cout<<"\x1b[10;1H";
 
 cout << "21" ;
 for(int i = 0 ; i < 14 ; i++ ){        //print the number of ground
   for(int j = 4 ; j > 0 ; j-- ){
     cout<<j;
   }
 }
 cout<< "43" ;
 
 cout<<"\x1b[1;1H";
 
 cout << "21" ;
 for(int i = 0 ; i < 14 ; i++ ){       //print the number of ceiling
   for(int j = 4 ; j > 0 ; j-- ){
     cout<<j;
   }
 }
 cout<< "43" ;
 
 cout << "\x1b[2;1H";                 //print the ceiling
 for(int i=0;i<60;i++){
   cout  <<  "=" ;
 }
 

 cout << "\x1b[9;1H";                //print the ground
 for(int i=0;i<60;i++){
   cout  <<  "=" ;
 }
  }
  
  return 0;
}

