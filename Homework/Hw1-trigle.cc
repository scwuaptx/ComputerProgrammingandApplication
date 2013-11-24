#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int i , j , n , k ;
    char c ;
    while ( 1 ) {
       cin >> n ;
       for ( i = 1 ; i <= n ; ++i ) {   //print upper triangle             
          c = 'A' ;
          for ( j = 1 ; j <= n-i ; ++j ) cout << ' ' ;
          for ( j = 1 ; j <= 2*i-1 ; ++j ) {      //print the first 
             if ( j <= i-1 ) cout << char(c++) ;
             else cout << char(c--) ;
          }
          for ( k = 0 ; k < (n-1)/2 ; ++k ){ 
             c = 'A' ;
             for ( j = 1 ; j <= 2*(n-i)+2*n-1 ; ++j ) cout << ' ' ;
             for ( j = 1 ; j <= 2*i-1 ; ++j ) {
                if ( j <= i-1 ) cout << char(c++) ;
                else cout << char(c--) ;
             }
          }
          cout << endl ;
       }
       for ( i = n ; i >= 1 ; --i ) {         //print lower triangle  
          if ( n == 1 ) break ; 
          c = 'A' ;
          for ( j = 1 ; j <= n-i+2*n-1 ; ++j ) cout << ' ' ;
          for ( j = 1 ; j <= 2*i-1 ; ++j ) {         //print the first
             if ( j <= i-1 ) cout << char(c++) ;
             else cout << char(c--) ;
          }
          for ( k = 0 ; k < (n-2)/2 ; ++k ){ 
             c = 'A' ;
             for ( j = 1 ; j <= 2*(n-i)+2*n-1 ; ++j ) cout << ' ' ;
             for ( j = 1 ; j <= 2*i-1 ; ++j ) {
                if ( j <= i-1 ) cout << char(c++) ;
                else cout << char(c--) ;
             }
          }
          cout << endl ;
       }
 
       

    }
	return 0;
}
