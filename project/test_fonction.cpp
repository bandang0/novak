#include <cstdlib>
#include <cmath>
#include <fstream>
#include "fonc.h"

using namespace std;

int main() {

    int np = 10 ;
    cout << "Entrer le nombre de points: " << endl ;
    cin >> np ;
    Fonction fi(np) ;
    Tab x(fi.grille()) ;
    
    fi = exp(-x*x) ;
    fi.calcule_coef() ;
    //fi.sauve("fi.dat") ;

    ofstream sortie("dessin.dat") ;
    int ndessin = 1000 ;
    double err = -1. ;
    for (int i=0; i<ndessin; i++) {
	    double t = 2*double(i)/double(ndessin-1) - 1.;
	    double diff = fi.calcule_en_x(t) - exp(-t*t) ;
	    if (fabs(diff) > err)
	      err = fabs(diff) ;
	    sortie << t << '\t' <<  fi.calcule_en_x(t) << endl ;
    }
    cout << "Erreur maximum sur l'interpolation: " << err << endl ;
    system("xmgrace dessin.dat &") ;

    /*Tab cc(np) ;
    cc = 0 ;
    cc.set(2) = 1 ; 
    Fonction g(np) ;
    g.set_coef(cc) ;
    
    cout << g ;
    g = fi.derivee() ;

    ofstream der("derivee.dat") ;
    err = -1 ;
    for (int i=0; i<ndessin; i++) {
	double t = 2*double(i)/double(ndessin-1) - 1.;
	double diff = g.calcule_en_x(t)  + 2*t*exp(-t*t) ;
	if (fabs(diff) > err)
	    err = fabs(diff) ;
	der << t << '\t' <<  diff << endl ;
    }
    cout << "Erreur maximum sur la derivee: " << err << endl ;
    system("xmgrace derivee.dat") ;*/

  return EXIT_SUCCESS ; 
}
