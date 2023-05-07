//Zuzanna Poznanska gr 2

#include <iostream>
#include <math.h>
#include <cmath>
#include <stdlib.h>
using namespace std;

double sieczne(double (*f)(double), double fa, double fb, double a, double b, int M, double eps, double delta) {

  double xn, fn;

  while(--M) {
    xn = b - (fb*(b-a))/(fb-fa);
    fn = f(xn);
    if(abs(xn-b) < delta || abs(fn) < eps) {
      return xn;
    }
    a = b;
    b = xn;
    fa = fb;
    fb = fn;
  }
  return xn;

}

double findZero(double (*f)(double), double a, double b, int M, double eps, double delta) {

  double c, fa, fb, fc, e, s = 0.1;

  fa = f(a);
  fb = f(b);
  if(fa == 0) return a;
  if(fb == 0) return b;
  e = b - a;

  if(fa*fb <= 0) {
    for(int k=M-2; k>0; k--) {
      if(abs(e) < s) return sieczne(f,fa,fb,a,b,k,eps,delta);
      e = e/2;
      c = a+e;
      fc = f(c);

      if(abs(e) < delta || abs(fc) < eps) return c;
      if(fc*fa <= 0) {
        b = c;
        fb = fc;
      }
      else {
        a = c;
        fa = fc;
      }
    }
    return c;
  }

  else return sieczne(f,fa,fb,a,b,M-2,eps,delta);

}
