/* Main file for TP1. */

#include <iostream>

using namespace std;

int main(void) {
  cout << "Welcome to TP1." << endl;

  /* Ask for array size */
  int size;
  cout << "Enter a size for the array:";
  cin >> size;

  /* Allocate size for array */
  int* tab;
  tab = new int[size];

  /* Print random stuff */
  cout << "Here's what's in the array:\n";
  for (int i = 0; i < size ; i++){
    cout << "At " << tab + i << ": " << *(tab + i) << endl;
  }

  delete[] tab;

  return 0;
}
