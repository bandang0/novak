#include <iostream>
#include <fstream>
#include "tab.h"

using namespace std;

/* Destructor */
Tab::~Tab(){
  delete[] val;
}

/* Copy */
Tab::Tab(const Tab& tab):
  dim(tab.dim), sX(tab.sX), sY(tab.sY), sZ(tab.sZ), val(NULL) {
    val = new double[sX * sY * sZ];
    for (int i = 0; i < sX * sY * sZ; i++){
      *(val + i) = tab.val[i];
    }
} 

/* Default */
Tab::Tab(int sX_arg, int sY_arg, int sZ_arg):
  dim(1), sX(sX_arg), sY(sY_arg), sZ(sZ_arg), val(NULL) {

    if (sY_arg == 0 && sZ_arg == 0){
      dim = 1;
      sY = 1;
      sZ = 1;
    } else if (sY_arg != 0 and sZ_arg == 0){
      dim = 2;
      sZ = 1;
    } else {
      dim = 3;
    }

    val = new double[sX * sY * sZ];
}

/* Read file */
Tab::Tab(char* file_name):
  dim(1), sX(1), sY(1), sZ(1), val(NULL) {

  ifstream file(file_name);
  file >> dim >> sX >> sY >> sZ;
  val = new double[sX * sY * sZ];
    for (int i = 0; i < sX * sY * sZ; i++){
      file >> *(val + i);
    }
}

/* Sets */
double& Tab::set(int i, int j, int k){
  return val[i + sX * j + sX * sY * k];
}

void Tab::operator=(double value){
  for (int i = 0; i < sX * sY * sZ; i++){ *(val + i) = value;}
}

void Tab::operator=(const Tab& tab){
  if (dim != tab.dim || sX != tab.sX || sY != tab.sY || sZ != tab.sZ){
    cout << "Dimensions to not match, affectation aborted";
  }
  for (int i = 0; i < sX * sY * sZ; i++){
    *(val + i) = tab.val[i];
  }
}

/* Arithmetic */
Tab Tab::operator/(const Tab& tab) const {
  Tab ans(*this);
  for (int i = 0; i < sX * sY * sZ; i++){
    *(ans.val + i) /= tab.val[i];
  }
  return ans;
}

Tab Tab::operator+(const Tab& tab) const {
  Tab ans(*this);
  for (int i = 0; i < sX * sY * sZ; i++){
    *(ans.val + i) += tab.val[i];
  }
  return ans;
}

Tab Tab::operator+(double k) const {
  Tab ans(*this);
  for (int i = 0; i < sX * sY * sZ; i++){
    *(ans.val + i) += k;
  }
  return ans;
}
Tab Tab::operator-(const Tab& tab) const {
  Tab ans(*this);
  for (int i = 0; i < sX * sY * sZ; i++){
    *(ans.val + i) -= tab.val[i];
  }
  return ans;
}

Tab Tab::operator*(const Tab& tab) const {
  Tab ans(*this);
  for (int i = 0; i < sX * sY * sZ; i++){
    *(ans.val + i) *= tab.val[i];
  }
  return ans;
}

/* Gets */
double Tab::get_max() const {
  double ans = val[0];
  for (int i = 1; i < sX * sY * sZ; i++){
    if (*(val + i) > ans) ans = *(val + i);
  }
  return ans;
}

/* Output */
void Tab::sauve(char* name) const {
  ofstream file(name);
  file << dim << ' ' << sX << ' ' << sY << ' ' << sZ << ' ';
  for (int i = 0; i < sX * sY * sZ; i++){
    file << *(val + i) << ' ';
  }
}

ostream& operator<<(ostream& o, const Tab& tab){
  o << tab.dim << ' ' << tab.sX << ' ' << tab.sY << ' ' << tab.sZ << "\n";
  for (int i = 0; i < tab.sX * tab.sY * tab.sZ; i++){
    o << *(tab.val + i) << ' ';
  }
  return o;
}
