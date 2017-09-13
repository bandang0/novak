#include <cstdlib>
#include <cmath>
#include <fstream>
#include "equadiff.h"

int main() {

    int np = 10 ;
    cout << "Entrer le nombre de points: " << endl ;
    cin >> np ;
    Fonction fi(np) ;
    Fonction x(fi.grille()) ;
    
    fi = exp(x)/(1+x*x) ;
    fi.calcule_coef() ;
    
    Fonction nulle(np) ;
    nulle = 0 ;
    nulle.calcule_coef() ;

    Equa_un ode(np, 1, -1) ;
    ode.impose_condition_bord_0(0., 1.) ;
    cout << ode.operateur ;
    Fonction sol = ode.resout(fi) ;

    ofstream sortie("dessin.dat") ;
    int ndessin = 1000 ;
    double err = -1. ;
    for (int i=0; i<ndessin; i++) {
	double t = 2*double(i)/double(ndessin-1) - 1.;
	double diff = sol.calcule_en_x(t) - exp(t)*(1+atan(t)) ;
	if (fabs(diff) > err)
	    err = fabs(diff) ;
	sortie << t << '\t' <<  diff << endl ;
    }
    cout << "Equa_un : Erreur maximum sur la resolution: " << err << endl ;
    system("xmgrace dessin.dat") ;

    Equa_deux ode2(np, 1, 1, 1) ;
    ode2.impose_condition_bord_0(0., 1.) ;
    ode2.impose_condition_bord_1(0., -0.5) ;
    Fonction sol2 = ode2.resout(nulle) ;

    ofstream sortie2("dessin2.dat") ;
    err = -1. ;
    for (int i=0; i<ndessin; i++) {
	double t = 2*double(i)/double(ndessin-1) - 1.;
	double diff = sol2.calcule_en_x(t) - exp(-0.5*t)*cos(0.5*sqrt(3.)*t);
	if (fabs(diff) > err)
	    err = fabs(diff) ;
	sortie2 << t << '\t' <<  diff << endl ;
    }
    cout << "Equa_deux : Erreur maximum sur la resolution: " << err << endl ;
    system("xmgrace dessin2.dat") ;


  return EXIT_SUCCESS ; 
}
