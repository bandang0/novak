#include <cmath>

#include "tab.h"
#include "matrice.h"
#include "maths.h"

Tab sin(const Tab& tab){
  Tab ans(tab);
  for (int i = 0; i < ans.sX * ans.sY * ans.sZ; i++){
    *(ans.val + i) = sin(*(ans.val + i));
  }
  return ans;
}

Tab abs(const Tab& tab){
  Tab ans(tab);
  for (int i = 0; i < ans.sX * ans.sY * ans.sZ; i++){
    *(ans.val + i) = fabs(*(ans.val + i));
  }
  return ans;
}

Tab exp(const Tab& tab){
  Tab ans(tab);
  for (int i = 0; i < ans.sX * ans.sY * ans.sZ; i++){
    *(ans.val + i) = exp(*(ans.val + i));
  }
  return ans;
}

double max(const Tab& tab){
  return tab.get_max();
}

double tcheb(int n, double x){
  if (n == 0) {return 1.;}
  if (n == 1) {return x;}
  return 2. * x * tcheb(n - 1, x) - tcheb(n - 2, x);
}

Tab _grille(int n) {
  Tab ans(n + 1);
  for (int k = 0; k < ans.get_taille1(); k++){
    ans.set(k) = 0. - cos(k * M_PI / n);
  }
  return ans;
}

Matrice passage(int n) {
  Matrice ans(n + 1);
  double* w = new double[n + 1];
  double* gamma = new double[n + 1];
  Tab X = _grille(n);

  int i;
  int k;

  w[0] = M_PI / (2 * n);
  w[n] = M_PI / (2 * n);
  for (k = 1; k < n; k ++) {w[k] = k * M_PI / n;}

  for (i = 0; i < n + 1; i++){
    for (k = 0; k < n + 1; k++){
      gamma[i] += pow(tcheb(i, X(k)), 2) * w[k];
    }
  }

  for (i = 0; i < n + 1; i++){
    for (k = 0; k < n + 1; k ++){
      ans.set(i, k) = tcheb(i, X(k)) * w[k] / gamma[i];
    }
  }
  return ans;
}
