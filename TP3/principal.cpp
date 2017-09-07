#include <cstdlib>
#include <cmath>
#include <iostream>
#include "tab.h"

int main() {
  Tab tab3d(2, 3, 4) ;
  tab3d = M_PI ;
  cout << tab3d ;
  cout << sin(tab3d) ;

  Tab mon_tab(5,6) ;
  for (int i=0; i<mon_tab.get_taille1(); i++) 
    for (int j=0; j<mon_tab.get_taille2(); j++)
      mon_tab.set(i,j) = double(i-j)/double(i+j+1) ;
  
  Tab aut_tab(5,6) ;
  aut_tab = 1 ;
  cout << aut_tab ;

  Tab vec0(6) ;
  vec0 = 1./3. ;
  vec0.sauve("tab_sauve.dat") ;

  Tab vec("tab_sauve.dat") ;
  cout << vec ;
  cout << mon_tab / aut_tab ;
  cout << vec + 1 ;
  cout << max(mon_tab) << endl  ;
  return EXIT_SUCCESS ; 
}
