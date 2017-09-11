#include <cstdlib>
#include <iostream>
#include "matrice.h"
#include "tab_math.h"

using namespace std;

int main() {

    Tab rhs("memb_droite.dat") ;
    Matrice mat("matrice.dat") ;

    double max_rhs = max(abs(rhs)) ;
    cout << "Maximum du membre de droite: " <<  max_rhs << endl ;

    // Le calcul suivant est optionnel (a faire pour les plus forts!)
    cout << "Determinant de la matrice: " << mat.determinant() << endl ;

    Tab solu = mat.resout(rhs) ;

    cout << "Solution: " << solu ;

    Tab lhs = mat*solu ;
    double err = max(abs(lhs - rhs)) ;

    cout << "Erreur absolue: " <<  err << endl ;
    cout << "Erreur relative: " << err / max_rhs << endl ;

  return EXIT_SUCCESS ; 
}
