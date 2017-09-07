#include <iostream>

#include "rational.h"
#include "gcd.h"

/* Default constructor*/
rational::rational(int a, int b): num(1), denom(1) {
  if (a == 0) {
    num = 0;
  } else if (b == 0) {
    denom = 0;
  } else{
    int g = gcd(a, b);
    num = a / g;
    denom = b / g;
  }
}

/* Copy constructor*/
rational::rational(const rational& r_arg):
  num(r_arg.get_num()), denom(r_arg.get_denom()) {
  /* Nothing to do! */
}

/* Destructor */
rational::~rational(void) {}

/* Assignment */
void rational::operator=(const rational& r_arg) {
  num = r_arg.get_num();
  denom = r_arg.get_denom();
}

/* Equality test */
bool rational::operator==(const rational& r_arg) const {
  return (num == r_arg.get_num()) && (denom == r_arg.get_denom());
}

/* Arithmetic */
rational operator+(const rational& r1, const rational& r2) {
  return rational(r1.num * r2.denom + r1.denom * r2.num, r1.denom * r2.denom);
}

rational operator+(const rational& r1, const int& a) {
  return r1 + rational(a, 1);
}

rational operator+(const int& a, const rational& r1) {
  return r1 + rational(a, 1);
}

rational operator-(const rational& r1, const rational& r2) {
  return rational(r1.num * r2.denom - r1.denom * r2.num, r1.denom * r2.denom);
}

rational operator*(const rational& r1, const rational& r2) {
  return rational(r1.num * r2.num, r1.denom * r2.denom);
}

rational operator/(const rational& r1, const rational& r2) {
  return rational(r1.num * r2.denom, r1.denom * r2.num);
}

ostream& operator<<(ostream& o, const rational& r){
  o << r.num << "/" << r.denom;
  return o;
}
