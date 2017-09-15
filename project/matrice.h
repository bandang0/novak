#ifndef MATRICE
#define MATRICE

#include "tab.h"

class Matrice: public Tab {
  public:
    virtual ~Matrice(); /* Destructor */

    /* Constructors */
    Matrice(const Tab&); /* Copy */
    Matrice(int); /* Default (square) */
    Matrice(const char*); /* Read file */

    /* Sets */
    void operator=(double);
    void operator=(const Tab&);
  
    /* Math */
    double determinant() const;
    Tab resout(const Tab&) const;

    /* Arithmetic */
    virtual Tab operator*(const Tab&) const;
    virtual Matrice operator*(const Matrice&) const;
};

/* Fortran interface */
extern "C" {
  void dgeev_(char* jobvl, char* jobvr, int* n, double* a, int* lda,
              double* wr, double* wi, double* vl, int* ldvl, double* vr,
              int* ldvr, double* work, int* lwork, int* info);

  void dgetrf_(int*, int*, double*, int*, int*, int*);
	void dgetrs_( char*, int*, int*, double*, int*,
                int*, double*, int*, int*);
}

#endif
