/*Write down the Chinese sentence step by step.*/
/*You need to set the coding to Big5 first*/
#include <iostream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

int main(){

  srand(time(NULL));
  enum { N = 10 , W = 14 , C = 10 , R = 5 , MAX = 50 , S = 50000 , CS = 2 };

  
 string p[N] = {
    "           ¢w¢s¢w¢w   ¢u¢w¢}   ¢u¢w¢w   ¢r ¢s¢w¢¡  ¢r ¢q¢s ¡¹     ¢u¢w¢{",
    " ¢~¢s¢£ ¡ñ   ¢x¢~¢¡ ¢w¢|¢w¢}  ¢x¢z¢s¢{  ¢w ¡´  ¢x  ¢w ¢r¢r¢q  ¢q¢q  ¢x  ",
    " ¢w¢q¢w¢q  ¢¬¢x¢¢¢£ ¢s ¢w¢¡ ¢x¢x¢q¢q¢q  ¢w ¢}¢w¢}  ¢w ¢z¢{¢x  ¢x¢x¢x¢x  ",
    " ¢~¢q¢£¢q    ¢x     ¢x  ¢®  ¢x¢u¢|¢r¢q ¢z¢{¢s¡ã¡´ ¢z¢{¢u¢t¢q  ¢|¢q¢x¢x¡ð",
    "   ¢}  ¢|                     ¢}    ¢} ¢|¢}¢|¢w¢} ¢|¢}¢|¢}¢|        ¢}  ",
    "       ¢s¢{          ¢u¢w¢}    ¢u¢w¢w     ¢z¢s¢{                        ",
    " ¢¬  ¢­¢x¢x  ¢~¢¡  ¢w¢|¢w¢}   ¢x¢z¢s¢{  ¢z¢w¢s¢s¢{            ¢u¢w¢{    ",
    " ¢¬  ¢­¢x¢}  ¢¢¢£  ¢s ¢w¢¡  ¢x¢x¢q¢q¢q   ¢r¢w¢w¢t   ¢u    ¢q¢q  ¢x      ",
    "  ¢z¢{ ¢x          ¢x  ¢®   ¢x¢u¢|¢r¢q   ¢z¢s¢w¢{   ¢r¢w  ¢|¢q¡þ¢x¡ð    ",
    "  ¢|¢}                        ¢}    ¢}   ¢u¢r¢w¢q               ¢}      "};
  //The stroke of the chinese word in the chinese sentence.
  int  draw[W] = { 18 , 12 , 12 , 22 , 21 , 23 , 16 , 15 , 4 , 12 ,
		   22 , 20 ,  3 , 12 } ;
  
    // the order of the word in the sentence.
    //It is three digitï¼Œthe first digit is rowï¼Œthe other two are column.
    // if the number is negativeï¼Œthen the word will be color.
  int  ord[W][MAX] = {
    { 105 , 103 , 101 , 201 , 203 , 205 , 207 , 103 , 203 , 303 ,
          403 , 301 , 303 , 305 , 207 , 307 , 407 , -108 } ,
    
    {  11 ,  13 ,  15 ,  17 , 113 , 213 , 313 , 211 , 115 , 215 ,
       117 , 217 } ,
    
    { 120 , 220 , 320 ,  22 , 122 ,  24 ,  26 , 124 , 126 , 223 ,
      225 , 324 } ,
    
    { 228 , 328 , 130 , 230 , 330 , 430 ,  31 ,  33 ,  35 , 132 ,
      232 , 332 , 334 , 336 , 134 , 136 , 236 , 336 , 436 , 232 ,
      234 , 236 } ,
    
    {  40 , 140 , 240 , 339 , 341 , 439 , 441 ,  43 ,  45 ,  47 ,
       147, 247 , 245 , -143 , 243 , 343 , 443 , 445 , 447 , 345 ,
       -347 },
    
    { 51  , 151 , 251 , 350 , 352 , 450 , 452 ,  54 ,  56 , 154 ,
      156 , 158 , 254 , 256 , 354 , 356 , 454 , 456 , 158 , 258 ,
      358 , 458 ,-59 },
    
    { 162 , 164 , 262 , 362 , 264 , 364 ,  66 ,  68 ,  70 , 168 ,
      268 , 368 , 468 , 266 , 366 ,-370 },
    
    { 601 , 701 , 605 , 705 , 802 , 804 , 902 , 904 , 507 , 509 ,
      609 , 709 , 607 , 707 , 807 },
    
    { 613 , 615 , 713 , 715 },
    
    { 619 , 719 , 819 , 521 , 523 , 525 , 621 , 623 , 625 , 722 ,
      724 , 823 },
    
    { 728 , 828 , 630 , 730 , 830 , 930 , 531 , 533 , 535 , 632 ,
      732 , 832 , 834 , 836 , 634 , 636 , 736 , 836 , 936 , 732 ,
      734 , 736 },
    
    { 542 , 544 , 546 , 640 , 642 , 644 , 646 , 648 , 741 , 743 ,
      745 , 747 , 841 , 843 , 845 , 847 , 941 , 943 , 945 , 947 },

    { 752 , 852 , 854 },
    
    { 758 , 760 , 858 , 860 , 662 , 664 , 666 , 764 , 864 , 964 ,
      862 ,-866 }

  };
  
  int i,u,g,q,j,k,r,c,n,m[W],x;
  cout << "\x1b[2J" << flush;    //clear the screen
   
  for(g=0;g<W;g++){           //rand of the array
    n=rand()%W;         
      x=g;
      for(q=0;q<g;q++){
        if(m[q]==n)
	  g-=1;
      }
      if(x==g)
	m[g]=n;
  } 
  
 
  
  
  for(i=0;i<W;i++){   
    x=m[i];
    for(j=0;j<draw[x];j++){ 
      if(ord[x][j]<0){                //if the number is negative,the color the word.
	  ord[x][j]=-ord[x][j];
	  cout << "\x1b[" << 31+rand()%7  << "m";  //color of the word
	}             
	r=((ord[x][j]+100)-ord[x][j]%100)/100;
	c=(ord[x][j])%100;
	
	cout << "\x1b[" <<  r  << ";" << c << "H" << flush;  //location of the cursor
	
	cout << p[r-1][c] << p[r-1][c+1];
	cout << "\x1b[m";
	cout << "\x1b[2;1H" << flush;   //Fix the location of the cursor
	usleep(S);
    }
    
  }
  
  
  cout << "\x1b[11;1H" << flush;
  return 0;
  
}

