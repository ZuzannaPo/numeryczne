//Zuzanna Poznańska gr 2
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;


typedef void (*FuncPointer)(const double* x, double* y, double* Df);

void printVector(const double* x, unsigned N){
  for(unsigned i=0;i<N;++i)
    printf("%17.17f ",x[i]);
  printf("\n");
}

int findCurve(FuncPointer f, double* x, unsigned k, double h) {

  double y[2];
  double Df[6];
  int g = 100;

  for(int i = 0; i < k; i++) {
    x[2] += h;
    f(x,y,Df);

    while(g && (fabs(y[0]) > 10e-14 || fabs(y[1]) > 10e-14) && (Df[0] * Df[4] - Df[1] * Df[3]) != 0 ) {
      double df = (Df[0] * Df[4] - Df[1] * Df[3]);
      double dfx = (-1 * y[0] * Df[4]) - (-1 * y[1] * Df[1]);
      double dfy = Df[0] * (-1 * y[1]) - Df[3] * (-1 * y[0]);
      double D0 = dfx / df;
      double D1 = dfy / df;
      x[0] += D0;
      x[1] += D1;
      f(x,y,Df);
      g--;
      if(g == 0) return i+1;
    }
    g = 100;
    if(Df[0] * Df[4] - Df[1] * Df[3] != 0) {
      printVector(x,3);
    }

    else return i + 1;
  }
  printf("\n");
  return 0;

}

int findSurface(FuncPointer f, double* x, unsigned k1, unsigned k2, double h1, double h2) {

  double y[1];
  double Df[6];
  f(x,y,Df);
  double x1 = x[1];
  double x2 = x[2];
  int g = 100;
  for(int i = 1; i <= k1; i++) {
    x[1] = x1 + i*h1;
    for(int j = 1; j <= k2; j++) {
      x[2] = x2 + j*h2;
      f(x,y,Df);
      while(g && (abs(y[0]) > 10e-14) && Df[0] != 0) {
        double df = (-1 * y[0]) / Df[0];
        x[0] += df;
        f(x,y,Df);
        g--;
        if(g == 0) return i*k1 + j;
      }
      g = 100;
      if(Df[0] != 0) {
        printVector(x,3);
      }

      else return i*k1 + j;
    }
    printf("\n");
  }
  return 0;

}

int findFixedPoints(FuncPointer f, double* x, unsigned k1, unsigned k2, double h1, double h2) {
  double y[2];
  double Df[8];
  f(x,y,Df);
  double x2 = x[2];
  double x3 = x[3];
  int g = 100;
  for(int i = 1; i <= k1; i++) {
    x[2] = x2 + i*h1;
    //f(x,y,Df);
    for(int j = 1; j <= k2; j++) {
      x[3] = x3 + j*h2;
      f(x,y,Df);
      while(g && (abs(y[0] - x[0]) > 10e-14 || abs(y[1] - x[1]) > 10e-14) && (Df[0] * Df[5] - Df[1] * Df[4]) != 0) {
        y[0] -= x[0];
        y[1] -= x[1];
        Df[0]--;
        Df[5]--;
        double df = Df[0] * Df[5] - Df[1] * Df[4];
        if(df == 0 || Df[1] == 0) return j+1;
        double dfx = ( y[0] * Df[5] - y[1] * Df[1]) / df;
        double dfy = ( y[0] - Df[0] * dfx) / Df[1];
        double D0 = dfx / df;
        double D1 = dfy / df;
        x[0] -= dfx;
        x[1] -= dfy;
        f(x,y,Df);
        g--;
        if(g == 0) return i*k1 + j;
      }
      g = 100;
      if(Df[0] * Df[5] - Df[1] * Df[4] != 0) {
        printVector(x,4);
      }

      else return i*k1 + j;
    }
    printf("\n");
  }
  return 0;
}
