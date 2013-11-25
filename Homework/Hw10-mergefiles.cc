/*Enter some filename,then merge them in a new file*/
/*Such as ./a.out filename1 filename2 fimename. then merger filename1 filename2 to fimename*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc,char* argv[]){
  int n,i;
  string line;
  ifstream infile[argc-1]; //product object array
  ofstream outfile; //output file object
  outfile.open(argv[argc-1],ios_base::out|ios_base::app);
  for( i = 1 ; i < argc-1 ; i ++ ){
    infile[i].open(argv[i]); //open the file
    while( getline(infile[i] , line )){    
      outfile << line << '\n';  //save the files to last file
    } 
  }
  outfile.close();

  return 0;
}

