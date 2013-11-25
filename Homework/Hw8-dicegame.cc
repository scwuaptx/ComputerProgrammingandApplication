/*there is a game of dice*/
/*Two people throw three dice.If two of them are same,
then get the score which the other one dice.
If three dice are different,then it will get zero score.
That two people need to throw three dice until get the scores*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;


class My_Dice{      //class of gamblers
private:
  string dname;    //name of gambler
  int value[3];    //the value of dices
  
public:
  My_Dice(string name){
    dname=name;           //set the name of gamblers
  }
  void throw_dices(){    //throw dice
    
    for(int j = 0 ; j < 3 ; j ++ ){
      value[j]=rand()%6+1;          
	}
  }
  string name(){         //show the name of gamblers
    return dname;
  }
  void show_dices(){     //show the value of dice
    for(int i = 0 ; i < 3 ; i ++)
      cout << value[i] << " " ;
    cout << "--> " << val();
  }
  int val(){           //show the scores
    int v;
    if( value[0] == value[1] )
      v=value[2];
    else if( value[0] == value[2] )
      v=value[1];
    else if( value[1] == value[2] )
      v=value[0];
    else
      v=0;
    return v;
  }



 
};

int main(){
  srand( static_cast<unsigned>(time(NULL))) ;
My_Dice  p("Amy") , q("Tom") ;

do {
   p.throw_dices() ;
   q.throw_dices() ;

   cout << p.name() << " " ;
   p.show_dices() ;
   cout << "\n" ;

   cout << q.name() << " " ;
   q.show_dices() ;
   cout << "\n\n" ;

} while ( p.val() == 0 || q.val() == 0 || p.val() == q.val() ) ;

cout << ( p.val() > q.val() ? p.name() : q.name() ) << " wins " << endl ;


  return 0;  
}

