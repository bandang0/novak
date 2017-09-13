#include <cassert>

#include "tab.h"
#include "fonc.h"

/* Destructor */
Fonction::~Fonction(){}

/* Copy */
Fonction::Fonction(const Fonction& arg):
  n(arg.n), X(arg.X), Phi(arg.Phi), C(arg.C) {
}

/* Constructors */
Fonction::Fonction(int m): n(m), X(Tab(m)), Phi(Tab(m)), C(Tab(m)) {}

Fonction::Fonction(const Tab& arg):
  n(arg.get_taille1()), X(arg), Phi(Tab(arg.get_taille1())),
  C(Tab(arg.get_taille1())) {}

/* Assignment */
void Fonction::operator=(const Fonction& f){
  n = f.n;
  X = f.X;
  Phi = f.Phi;
  C = f.c;
} 
