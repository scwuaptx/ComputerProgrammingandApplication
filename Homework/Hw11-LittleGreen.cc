/*  littlegreen
0x180f0180 0x0f03e0e8 0x16499070 0x05023881 0x082c0000
0x0c0780c0 0x0c0781e0 0x2d0320e0 0x16048110 0x110c4000
0x180f0180 0x0c0781d0 0x2d0300e0 0x0902c088 0x090e8000
0x0301e030 0x060782f0 0x2c8b21c0 0x1e044108 0x20882000
0x0180f018 0x0703c178 0x16418078 0x04811042 0x08412000
*/

/*Your need to save above date to a file which is named littlegreen */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main(){
  ofstream outfile("green",ios_base::out|ios_base::binary);
  int i,g=0,j,k,n=1;
  ifstream infile("littlegreen");    //input the file
  
while(infile >> hex >> i){   //convert the file to binary
  outfile.write( reinterpret_cast<char*>(&i) , sizeof(i) ) ;
 }
 
 outfile.close();

 while(1){
   ifstream infile1("green",ios_base::in|ios_base::binary);  //input the binary code
   cout << "\x1b[2J" ;
   cout << "\x1b[1;1H";
   
  while(infile1.read(reinterpret_cast<char*>(&i),sizeof(i))){   //output the little green
    n=0;
    for(k=6;k>=0;k--){
      for(j=3;j>=0;j--){
	cout << (i&(1<<4*k+j+4)? "*" : " " );
       if(n%10==0) cout << endl;
       n++;
      }
    }
    infile.clear();
    g++;
      if(g==5) {
	cout << flush;
	cout << usleep(200000);
	cout << "\x1b[2J" ;
	g=0;
    cout << "\x1b[1;1H";
      }
      
  }
  infile.clear();
 }
 return 0;
}

