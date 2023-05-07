//Zuzanna Poznanska gr 2

#include <iostream>
#include <math.h>
#include "vectalg.h"
using namespace std;

Vector f(Matrix & A, Vector &p, Vector & b, double  eps);

Vector solveEquations(const Matrix & A, const Vector & b, double  eps) {

  int size = A.size();
  Vector p = Vector(size);
  Vector s = Vector(size);
  Vector bb = Vector(size);
  bb = b;
  Matrix AA = Matrix(size);
  AA = A;
  double max = 0.0;
  for(int i = 0; i < size; i++) {
    p[i] = i;
    for(int j = 0; j < size; j++) {
      if(abs(AA(i,j)) > max) {
        max = abs(AA(i,j));
      }
    }
    s[i] = max;
  }

  for(int k = 0; k < size-1; k++) {
    for(int j = k; j < size; j++) {
      bool ok = false;
      for(int i = k; i < size; ++i) {
        if(abs(AA(p[j],k)) / s[(int)p[j]] < abs(AA(p[i],k)) / s[(int) p[i]]) {
          ok = true;
          break;
        }
      }
      if(ok) continue;
      double tmp = p[k];
      p[k] = p[j];
      p[j] = tmp;
    }


    for(int i = k+1; i < size; i++) {
      double z = AA(p[i],k) / AA(p[k],k);
      AA(p[i],k) = z;

      for(int l = k+1; l < size; l++) {
        AA(p[i],l) = AA(p[i],l) - z * AA(p[k],l);
      }
    }
  }

  return f(AA,p,bb,eps);

}

Vector f(Matrix & A, Vector &p, Vector & b, double  eps) {
  int size = A.size();
  Vector x = Vector(size);
  for(int k = 0; k < size-1; k++) {
    for(int i = k+1; i < size; i++) {
      b[p[i]] = b[p[i]] - A(p[i],k) * b[p[k]];
    }
  }

  for(int i = size - 1; i >= 0; i--) {
    double bpi = 0.0;
    for(int j = i+1; j < size; j++) {
      bpi = bpi + A(p[i],j) * x[j];
    }
    x[i] = (b[p[i]] - bpi) / A(p[i],i);
  }
  return x;
} /*
int main(){
    cout.precision(17);
    int n = 0;
    double eps = 0;
    //cout << "dupa 000 ";

    // wczytywanie danych
    cin >> n;
    //cout << "dupa 001 ";
    Matrix a = Matrix(n);
    //cout << "dupa 002 ";
    Vector b = Vector(n);
    //cout << "dupa 003 ";
    cin >> a;
    //cout << "po a ";
    cin >> b;
    //cout << "po b ";
    cin >> eps;
    //cout << "dupa 00 ";

    Vector x = solveEquations(a, b, eps);

    auto residual = residual_vector(a, b, x);
    cout << "rozwiazanie = " << x << endl;
    cout << "rezydualny = " << residual << endl;
    cout << "blad = " << residual.max_norm()
         << " limit = " << eps << endl ;
    cout << "Test " << (residual.max_norm() < eps ? "":"nie ") << "zaliczony" << endl;
    return 0;
}
*/
