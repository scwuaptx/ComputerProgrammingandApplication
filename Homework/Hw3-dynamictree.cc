#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cstdlib>
using namespace std;

int main(){
  int i,j,k,s,m,n;
  
  cin >> n;                          
  cout << "\x1b[2J" << flush;
  for( i = 1 ; i <= n ; i++ ){                //print the i-th tree
    for( j = 1 ; j <= n ; j++ ){             //contrl the cursor location
      
      
      if( j < n ){               //print the left edge of triangle
	
	cout << "\x1b[" << j << ";" << (3*i-2)*n-j+1-i+1 << "H" << flush ;
	cout << "*" << flush ;
	usleep(20000);
      	   }else{
	for( k = 1 ; k <= 2*n-1 ; k ++ ){  //print the bottom edge of triangle
	  cout << "\x1b[" << j << ";" << (3*i-2)*n-j+k-i+1 << "H"  
	       << "*"  << flush;
	  usleep(20000);
	}
      }
      
    }
    for( s = n-1 ; s > 1 ; s -- )           //print the right edge of triangle
      {
	cout << "\x1b[" << s << ";" << (3*i-2)*n+s-1-i+1 << "H" << flush ;
	cout << "*" << flush ;  
	usleep(20000);       
      }   
    cout << "\x1b[" << n+1 << ";" << (3*i-2)*n-i+1 << "H" << flush ;
    cout << "|" << flush ;      //print the trunk
    usleep(20000);    
  }
  
  cout <<  "\x1b[" << n+2 << ";"  <<  1 << "H" <<flush ;
  for( m = 1 ; m <= 3*n*n-2*n ; m ++ ){
    cout << "-" << flush;              //print the ground
    usleep(20000);
  }   
  cout << '\n' << flush;
  return 0;
}
