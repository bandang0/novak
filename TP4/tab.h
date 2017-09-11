#ifndef TAB
#define TAB

#include <iostream>

using namespace std;

class Tab {

  protected:
    /* Data */
    int dim;
    int sX, sY, sZ;
    double* val;

  public:
    virtual ~Tab(); /* Destructor */

    /* Constructors */
    Tab(const Tab&); /* Copy */
    Tab(int sX_arg, int sY_arg = 0, int sZ_arg = 0); /* Default */
    Tab(char*); /* Read file */

    /* Sets */
    double& set(int i, int j = 0, int k = 0);
    void operator=(double);
    void operator=(const Tab&);

    /* Arithmetic*/
    Tab operator/(const Tab&) const;
    Tab operator+(const Tab&) const;
    Tab operator+(double) const;
    Tab operator-(const Tab&) const;
    Tab operator*(const Tab&) const;

    /* Gets */
    int get_taille1() const {return sX;};
    int get_taille2() const {return sY;};
    double operator()(int i, int j = 0, int k = 0) {
      return val[i + sX * j + sX * sY * k];
    };
    double get_max() const;

    /* Output */
    void sauve(char*) const;  /* Write to file */
    friend ostream& operator<<(ostream&, const Tab&); /* Stdout */

    /* Math */
    friend Tab sin(const Tab&);
};

#endif
