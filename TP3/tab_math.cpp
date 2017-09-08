#include <cmath>
#include "tab.h"
#include "tab_math.h"

Tab sin(const Tab& tab){
  Tab ans(tab);
  for (int i = 0; i < ans.sX * ans.sY * ans.sZ; i++){
    *(ans.val + i) = sin(*(ans.val + i));
  }
  return ans;
}

double max(const Tab& tab){
  return tab.get_max();
}
