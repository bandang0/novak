int gcd(int a, int b) {
  if (a<b) {
    int c = a ;
    a = b ;
    b = c ;
  }
  int reste = a%b ;
  while (reste != 0) {
    a = b ;
    b = reste ;
    reste = a%b ;
  }
  return b ;
}
