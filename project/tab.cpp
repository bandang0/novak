#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>

#include "tab.h"

using namespace std;

/* Destructor */
Tab::~Tab(){
  delete[] val;
}

/* Copy */
Tab::Tab(const Tab& tab): sX(tab.sX), sY(tab.sY), sZ(tab.sZ), val(NULL) {
    val = new double[sX * sY * sZ];
    for (int i = 0; i < sX * sY * sZ; i++){
      *(val + i) = tab.val[i];
    }
} 

/* Default */
Tab::Tab(int sX_arg, int sY_arg, int sZ_arg):
  sX(sX_arg), sY(sY_arg), sZ(sZ_arg), val(NULL) {

    if (sY_arg == 0 && sZ_arg == 0){
      sY = 1;
      sZ = 1;
    } else if (sY_arg != 0 and sZ_arg == 0){
      sZ = 1;
    }

    val = new double[sX * sY * sZ];
}

/* Read file */
Tab::Tab(const char* file_name): sX(1), sY(1), sZ(1), val(NULL) {

  ifstream file(file_name);
  file >> sX >> sY >> sZ;
  val = new double[sX * sY * sZ];
    for (int i = 0; i < sX * sY * sZ; i++){
      file >> *(val + i);
    }
}

/* Sets */
double& Tab::set(int i, int j, int k) const{
  assert(i < sX);
  assert(j < sY);
  assert(k < sZ);
  return val[i + sX * j + sX * sY * k];
}

void Tab::operator=(double value){
  for (int i = 0; i < sX * sY * sZ; i++){ *(val + i) = value;}
}

void Tab::operator=(const Tab& tab){
  if (sX != tab.sX || sY != tab.sY || sZ != tab.sZ){
    throw "Dimensions to not match, assignement aborted";
  }
  for (int i = 0; i < sX * sY * sZ; i++){
    *(val + i) = tab.val[i];
  }
}

/* Arithmetic */
Tab Tab::operator/(const Tab& tab) const {
  if (sX != tab.sX || sY != tab.sY || sZ != tab.sZ){
    throw "Dimensions to not match, / operation aborted";
  }
  Tab ans(*this);
  for (int i = 0; i < sX * sY * sZ; i++){
    *(ans.val + i) /= tab.val[i];
  }
  return ans;
}

Tab Tab::operator+(const Tab& tab) const {
  if (sX != tab.sX || sY != tab.sY || sZ != tab.sZ){
    throw "Dimensions to not match, + operation aborted";
  }
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
  if (sX != tab.sX || sY != tab.sY || sZ != tab.sZ){
    throw "Dimensions to not match, - operation aborted";
  }
  Tab ans(*this);
  for (int i = 0; i < sX * sY * sZ; i++){
    *(ans.val + i) -= tab.val[i];
  }
  return ans;
}

Tab Tab::operator-() const {
  Tab ans(*this);
  for (int i = 0; i < sX * sY * sZ; i++){
    *(ans.val + i) = -ans.val[i];
  }
Tab Tab::operator*(const Tab& tab) const {
  if (sX != tab.sX || sY != tab.sY || sZ != tab.sZ){
    throw "Dimensions to not match, * operation aborted";
  }
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
void Tab::sauve(const char* name) const {
  ofstream file(name);
  file << sX << ' ' << sY << ' ' << sZ << ' ';
  for (int i = 0; i < sX * sY * sZ; i++){
    file << *(val + i) << ' ';
  }
}

ostream& operator<<(ostream& o, const Tab& tab){
  o << "Sizes: " << tab.sX << ", " << tab.sY << ", " << tab.sZ << "\n";
  for (int k = 0; k < tab.sZ; k++){
    o << "-------\n";
    for (int i = 0; i < tab.sX; i++){
      for (int j = 0; j < tab.sY; j++){
        o << setw(10) << tab.set(i, j, k) << ' ';
      }
      o << '\n';
    }
  }
  o << endl;
  return o;
}
