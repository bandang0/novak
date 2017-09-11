#include "matrice.h"

/* Destructor */
Matrice::~Matrice(){}

/* Contructors */
Matrice::Matrice(const Tab& arg): Tab(arg) {}
Matrice::Matrice(int n): Tab(n, n, 0) {}
Matrice::Matrice(const char* name): Tab(name) {}

/* Sets */
void operator=(double value) {Tab::operator=(value);}
void operator=(const Tab& arg) {Tab::operator=(arg);}

/* Math */
double Matrice::determinant() const { return 1.;}
Tab resout(const Tab& Y) const {return Y;}

/* Arithmetic */
Tab operator*(const Tab& vec) const {
  Tab ans(sX, 0, 0);
  for (int i = 0; i < sX; i++)
    for (int j = 0; j < sX; j++)
      ans.set(i) += set(i, j) * vec.set(j);

  return ans;
}
 
Matrice operator*(const Matrice& arg) const {
  Matrice ans(sX);
  for (int i = 0; i < sX; i++)
    for (int j = 0; j < sX; j++)
      for (int k = 0; k < sX; k++)
        ans.set(i, j) += set(i, k) * arg.set(k, j);

  return ans;
}
