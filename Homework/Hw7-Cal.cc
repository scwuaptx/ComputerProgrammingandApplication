/*Cal.cc just like the command cal,but there are add a parameter to decide the number of column*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;
string int2str(int &k);

int main(){
  enum{MON=12,WK=7};
  int i,s,c,n,g,j,y,p,m,d,w,r,k,Y,M,wk;
  int days[MON]={31,28,31,30,31,30,31,31,30,31,30,31};
  string wkdays[WK]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
  string cal[MON][9]={};
  string mon[MON]={"一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月"};
  
  cin >>y;        //Enter a number for year
  cin >> n;       //Enter of the column which you want show
  days[1]=28;
  if(y%4==0){     //check leap year
    if(y%400==0||y%100!=0) days[1]=29; 
  }
  
  for(m=1;m<=MON;m++){  //calculate  the week of the day
    g=0;
    p=0;
    if(m<=2){
      Y=y-1;
      M=m+10;
    }else{
      Y=y;
      M=m-2;
    }
    wk = (Y + Y/4 - Y/100 +Y/400 +static_cast<int>(2.6*M-0.2)+1)%7;
                   
    cal[m-1][p]+="               ";   //arrange the month
    cal[m-1][p]+=mon[m-1];
    cal[m-1][p]+="               ";
    
    p++;
    for(i=0;i<WK;i++){                //arrange the week 
      cal[m-1][p]+="  "+wkdays[i];      
    }
    
    p++;

    
    for(j=0;j<wk;j++){               //separate every month
      cal[m-1][p]+="     ";      
      g++;
    }
    
    for(d=1;d<=days[m-1];++d){       //arrange the days
      if(d<10)
	cal[m-1][p]+="    "+int2str(d);
      else
	cal[m-1][p]+="   "+int2str(d);
      
      g++;
      
      if(d==days[m-1]){
	c = (Y + Y/4 - Y/100 +Y/400 +static_cast<int>(2.6*M-0.2)+days[m-1])%7;
	for(int o=0;o<5*(7-c-1);o++)
	  cal[m-1][p]+=" ";
      }
      
      if(g%7==0){
	p++;	
      }    
    }
    
    if(g%7!=0) p++;
    while(p<=8){
      for(int o=0;o<35;o++)         //add a blank,when print a number
	cal[m-1][p]+=" ";
      p++;
    }
  }
  s=12/n;
  r=12%n;
  for(int f=0;f<s;f++){            //print the cal
    for(int k=0;k<8;k++){
      for(int u=1;u<=n;u++){
	cout << cal[n*f+u-1][k]<< " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  if(r!=0){
    for(int k=0;k<8;k++){
      for(int u=s*n;u<=11;u++){
	cout << cal[u][k]<< " ";
      }
      cout << endl;
    }
  } 
  cout << endl;
  return 0;
}


string int2str(int &s){          //把數字變成字串
  std::stringstream ss;
  std::string str;
  ss << s;
  ss >> str;  
  return str;
}
