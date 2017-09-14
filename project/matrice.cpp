#include <cassert>

#include "matrice.h"

using namespace std;

/* Destructor */
Matrice::~Matrice(){}

/* Contructors */
Matrice::Matrice(const Tab& arg): Tab(arg) {}
Matrice::Matrice(int n): Tab(n, n, 0) {}
Matrice::Matrice(const char* name): Tab(name) {}

/* Sets */
void Matrice::operator=(double value) {Tab::operator=(value);}
void Matrice::operator=(const Tab& arg) {Tab::operator=(arg);}

/* Math */
double Matrice::determinant() const {
  double ans = 1;

  char jobvl = 'N';
  char jobvr = 'N';
  int n = sX;
  Matrice tmp(*this);
  int lda = sX;
  double* wr = new double[sX];
  double* wi = new double[sX];
  double* vl = new double[sX * sX];
  int ldvl = sX;
  double* vr = new double[sX * sX];
  int ldvr = sX;
  double* work = new double[sX * sX];
  int lwork = 3*sX;
  int info = 0;

  dgeev_(&jobvl, &jobvr, &n, tmp.val, &lda,
         wr, wi, vl, &ldvl, vr,
         &ldvr, work, &lwork, &info);

  for (int j = 0; j < sX ; j++){
    cout << wr[j] << " " << wi[j] << endl;
  }

  int i = 0;
  while(i < sX){
    if (*(wi + i) == 0.){
      ans *= *(wr + i);
      i = i + 1;
    }
    else {
      ans *= wr[i] * wr[i] + wi[i] * wi[i];
      i = i + 2;
    }
  }

  delete [] wr;
  delete [] wi;
  delete [] vl;
  delete [] vr;
  delete [] work;
  return ans;
}

Tab Matrice::resout(const Tab& Y) const {
	
	assert(Y.sX == sX && Y.sY * Y.sZ == 1);

	Matrice mat(*this);
	int* vec = new int[Y.sX];
	Tab sol(Y);
	int info = 0;
	int col = 1;
	int info2 = 0;
	char a = 'N';
	int taille = mat.sX;
	dgetrf_(&taille, &taille, mat.val, &taille, vec, &info);
	dgetrs_(&a, &taille, &col, mat.val, &taille, vec, sol.val, &taille, &info2);
	
	delete [] vec;
	
	return sol;

}


/* Arithmetic */
Tab Matrice::operator*(const Tab& vec) const {
  assert(vec.sX == sX && vec.sY == 1 && vec.sZ == 1);
  Tab ans(sX);
  for (int i = 0; i < sX; i++)
    for (int j = 0; j < sX; j++)
      ans.set(i) += (*this)(i, j) * vec(j);

  return ans;
}
 
Matrice Matrice::operator*(const Matrice& arg) const {
  assert(sX == arg.sY && sY == arg.sX);
  Matrice ans(sX);
  for (int i = 0; i < sX; i++)
    for (int j = 0; j < sX; j++)
      for (int k = 0; k < sX; k++)
        ans.set(i, j) += (*this)(i, k) * arg(k, j);

  return ans;
}
