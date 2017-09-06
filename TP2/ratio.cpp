#include<cstdlib>

//Declarations of the class rational
#include "rational.h" 

int main(){

    rational p(420,315);   // 420/315, simplified 
                            // by the constructor
    cout<< p + 5 << endl;   // call to operator+ 
                            //and operator<< 
  return 0;
}
