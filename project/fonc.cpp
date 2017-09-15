#include <cassert>

#include "tab.h"
#include "fonc.h"
#include "maths.h"

/* Destructor */
Fonction::~Fonction(){}

/* Copy */
Fonction::Fonction(const Fonction& arg):
  P(arg.P), X(arg.X), n(arg.n), Phi(arg.Phi), C(arg.C) {
}

/* Constructors */
Fonction::Fonction(int m):
  P(passage(m)), X(_grille(m)), n(m), Phi(Tab(m + 1)), C(Tab(m + 1)) {
}

Fonction::Fonction(const Tab& arg):
  P(passage(arg.get_taille1() - 1)), X(_grille(arg.get_taille1())),
  n(arg.get_taille1() - 1),
  Phi(arg), C(Tab(arg.get_taille1())) {
}

/* Assignment */
void Fonction::operator=(const Fonction& f){
  n = f.n;
  P = f.P;
  X = f.X;
  Phi = f.Phi;
  C = f.C;
}

/* Sets */
double Fonction::calcule_en_x(double x) const {
  double ans = 0.;
  for (int i = 0; i < n + 1; i++){
    ans += C(i) * tcheb(i, x);
  }
  return ans;
}

/* Arithmetic */
Fonction Fonction::derivee() const {return *this; }

