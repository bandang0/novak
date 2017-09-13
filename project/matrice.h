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
    Tab operator*(const Tab&) const;
    Matrice operator*(const Matrice&) const;
};
#endif
