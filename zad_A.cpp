//Zuzanna Poznańska gr 2

#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

double equation(int n, double x0, double x1) {

  double result;
  double d = 48.0/7.0;
  double c1 = (7*x0 - x1)/(d);
  double c2 = x0 - c1;


  result = c1 / pow(7,n) + c2 * pow(7,n);

  return result;

}

int main() {

  int z;

  cin >> z;

  for(int j = 0; j<z; j++) {

      double x0, x1;
      int n;

      cin >> x0;
      cin >> x1;
      cin >> n;

      int k[n+1];

      for(int i = 1; i <= n; i++) {
        cin >> k[i];
      }

      double xi;

      for(int i = 1; i<=n; i++) {
        xi = equation(k[i],x0,x1);
        printf("%.15e\n",xi);
      }
  }

}
