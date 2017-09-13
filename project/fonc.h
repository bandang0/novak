#ifndef FONC
#define FONC

#include <iostream>

#include "tab.h"

class Fonction {
  protected:
    int n;
    Tab X;
    Tab Phi;
    Tab C;

  public:
    ~Fonction();/* Destructor */
    Fonction(const Fonction&);  /* Copy */
    Fonction(int);  /* Integer */
    Fonction(const Tab&); /* Par grille */
    
    Fonction operator=(const Fonction&);  /* Assignment */
    Fonction operator=(const Tab&); /* Assignment by tab of values */

    /* Gets */  
    Tab grille() const;

    /* Sets */
    void set_coef(const Tab&);
    void calcule_coef();
    double calcule_en_x(double) const;
    double operator()(double) const;

    /* Arithmetic */
    Fonction derivee() const;
    /* Output */
    friend ostream& operator<<(ostream& o, const Fonction&);
    void sauve(const char*) const;

#endif
