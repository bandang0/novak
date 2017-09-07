#include<cstdlib>

//Declarations of the class rational
#include "rational.h"

int main(){

    rational p(420,315);   // 420/315, simplified 
                            // by the constructor
    rational inf(2, 0);
    rational moinsinf(-1, 0);
    rational q(840, 630);
    rational zero(0, 3);
    rational dezero(0, 5);
    cout << p + 5 << endl;   // call to operator+ 
                            //and operator<< 

    cout << "\n1 " << inf + moinsinf;
    cout << "\n2 " << (inf == moinsinf);
    cout << "\n3 " << inf + 1;
    cout << "\n4 " << inf - inf;

    cout << "\n5 " << (p == q);
    cout << "\n6 " << p + inf;
    cout << "\n7 " << p - inf;

    cout << "\n8 " << (zero == dezero);
    cout << "\n9 " << zero * inf;
    cout << "\n10 " << zero * p;
    cout << "\n11 " << p - q;
    cout << "\n12 " << p/q;
    cout << "\n13 " << p * q;
    cout << "\n14 " << ((p * p) == (q * q));

  return 0;
}
