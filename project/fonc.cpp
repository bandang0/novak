#include <cassert>
#include <vector>
#include <algorithm>

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
  P(NULL), X(NULL), n(m), Phi(Tab(m + 1)), C(Tab(m + 1)) {
  int index = 0;
  int len = orders.size();
  for( ; index < len + 1; index++){
    if(orders[index]){ break;}
  }

  if (index == len) {
    Fonction::orders.push_back(m);
    Fonction::Ps.push_back(passage(n));
    Fonction::Xs.push_back(_grille(n));
  }
  P = &Fonction::Ps[index];
  X = &Fonction::Xs[index];
}
  

Fonction::Fonction(const Tab& arg):
  P(NULL), X(NULL), n(arg.get_taille1() - 1),
  Phi(Tab(arg.get_taille1())), C(Tab(arg.get_taille1())) {
    Fonction tmp(arg.get_taille1() + 1);
    *this = tmp;
    Phi = arg;
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

