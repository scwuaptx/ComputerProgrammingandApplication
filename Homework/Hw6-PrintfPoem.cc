/*There are two chinese poem,we want to print them with some format*/
/*You need to set the coding to Big5 first*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std ;

enum { N = 5 ,CS=3} ;


void  setup1( int (*p)[N] ) {    //the function of left poem
  int i , j ;
  for ( i = 1 ; i <= N ; ++i ) {
    for ( j = 1 ; j <= N ; ++j ) {
      if ( i+j<=N+1 ) {
	p[i-1][j-1] = (N-j)*(N-j) + i ;
      } else {
	p[i-1][j-1] = i*i - (N-j) ;
      }
    }
  }
}

void  setup2( int (*p)[N] ) {   //the function of right poem
  int i , j ;
  for ( i = 1 ; i <= N ; ++i ) {
    for ( j = 1 ; j <= N ; ++j ) {
      if ( i >= j ) {
	p[i-1][j-1] = (i-1)*(i-1) + j ;
      } else {
	p[i-1][j-1] = j*j - i + 1 ;
      }
    }
  }
}

void color1( int (*p)[N] ){    //the function of left color
  int i , j;
  for ( i = 1 ; i <= N ; ++i ) {
    for ( j = 1 ; j <= N ; ++j ) {
      if(i+j<=N+1){
	p[i-1][j-1]=31+N-j;     
      }else{
        p[i-1][j-1]=30+i;
      }
    }
  }
}


void color2( int (*p)[N] ){     //the function of right color
  int i , j;
  for ( i = 1 ; i <= N ; ++i ) {
    for ( j = 1 ; j <= N ; ++j ) {
      if(j>=i){
	p[i-1][j-1]=30+j;     
      }else{
        p[i-1][j-1]=30+i;
      }
    }
  }
}


int main() {
  int i , j ;
  int p[N][N] , q[N][N] ,r[N][N] , c[N][N];
  string  pleft  = "游赤縣遠鷺嶺寒風起既喜朝聞日復日已畢耆山本願誠難在" ;
  string  pright = "愁丹思抽龍河激水流不覺季頹秋更秋終望持經振錫往揚州" ;
  setup1( p ) ;
  setup2( q ) ;
  color1( r ) ;
  color2( c ) ;
  
  for ( i = 0 ; i < N ; ++i ) {
    for ( j = 0 ; j < N ; ++j ){                               //print the left poem
      cout << "\x1b[" << r[i][j] << "m" ;
      cout << pleft[(p[i][j]-1)*CS] << pleft[(p[i][j]-1)*CS+1] << pleft[(p[i][j]-1)*CS+2];
      cout << "\x1b[m";
    }
    for ( j = 0 ; j < N ; ++j ){                               //print the right poem
      cout << "\x1b[" << c[i][j] << "m" ;
      cout << pright[(q[i][j]-1)*CS] << pright[(q[i][j]-1)*CS+1] << pright[(q[i][j]-1)*CS+2];
      cout << "\x1b[m";
    }
    cout << endl ;
  }
  
  return 0 ;
}
