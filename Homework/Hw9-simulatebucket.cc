/*The program will simulate to pour water to bucket,and print the high of the water in the bucket*/
#include <iostream>
using namespace std;

class Bucket{
private :
  int max_height; //max high of water 
  int water_height; //high of water
public :
  //if bucket is filled¡then ture.
  Bucket( int m , bool fill = false ){
    max_height=m;
    if( fill == true )
      water_height=max_height;
    else
      water_height=0;
  };
  friend Bucket& operator>> ( Bucket& x,Bucket& y){  //def pour the water
    int h=y.max_height-y.water_height;
    if( x.water_height > h ){
      x.water_height-=h;
      y.water_height=y.max_height;
    }else{
      
      y.water_height+=x.water_height;
      x.water_height=0;
    }
    return x;
  }

  friend Bucket& operator<< ( Bucket& y, Bucket& x ){
    int h=y.max_height-y.water_height;
    if(x.water_height>h){
      x.water_height-=h;
      y.water_height=y.max_height;
    }else{     
      y.water_height+=x.water_height;
      x.water_height=0;
    }
    return y;
  }
  
  
  friend ostream& operator<< ( ostream& out , Bucket& foo ){
    out << foo.water_height;
    return out ;
  }

 
};

int main(){
  const bool FILL_UP = true;
  Bucket a(5),b(3),c(100);
  Bucket f(100,FILL_UP);
  
  
  f  >> a >> b;
  a >> ( b >> c);
  a >> ( b >> c);
  ( a << f ) >> b;
   
  //print the high of water in the bucket of a,b,c.
   cout  << a << " " << b << " " << c << endl;
   
}

