#ifndef RATIONAL
#define RATIONAL

#include <iostream>

using namespace std;

class rational {
	protected:
		int num;
		int denom;
	public:
		rational(const rational&);	/* Copy */
		rational(int, int);	/* Default */
		virtual ~rational();	/* Destructor */
		void operator=(const rational&);	/* Assignment */

    /* Arithmetic */
    friend rational operator+(const rational&, const rational&);
    friend rational operator+(const rational&, const int&);
    friend rational operator+(const int&, const rational&);
    //friend rational operator-(const rational&, const rational&);
    //friend rational operator*(const rational&, const rational&);
    //friend rational operator/(const rational&, const rational&);

    /* Gets */
    int get_num(void);
    int get_denom(void);

    /* Ouput */
		friend ostream& operator<<(ostream&, const rational&) ;
};
	
#endif
