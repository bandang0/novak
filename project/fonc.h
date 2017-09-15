#ifndef FONC
#define FONC

#include <iostream>
#include <vector>

#include "tab.h"
#include "matrice.h"

class Fonction {
  protected:
    Matrice P;
    Tab X;
    int n;
    Tab Phi;
    Tab C;

  public:
    ~Fonction();/* Destructor */
    Fonction(const Fonction&);  /* Copy */
    Fonction(int);  /* Integer */
    Fonction(const Tab&); /* Par grille */
    
    void operator=(const Fonction&);  /* Assignment */
    void operator=(const Tab& arg){Phi = arg;}; /* Assignment by values */
    void operator=(double x) {Phi = x;};

    /* Gets */  
    Tab grille() const {return X;};

    /* Sets */
    void set_coef(const Tab& tab){C = tab;};
    void calcule_coef(){ C = P * Phi;};
    double calcule_en_x(double) const;
    double operator()(double x0) const {return calcule_en_x(x0);};

    /* Arithmetic */
    Fonction derivee() const;

    /* Output */
    friend std::ostream& operator<<(std::ostream& o, const Fonction&);
    void sauve(const char*) const;
};

#endif
