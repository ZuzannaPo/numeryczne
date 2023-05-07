//Zuzanna Poznanska gr 2

#include <iostream>
#include <iomanip>
#include <math.h>
#include "funkcja.h"
using namespace std;

class coefs{

public:
  double f;
  double fx;
  double fy;
  double fxx;
  double fxy;
  double fyy;

  coefs(){
    this->f = 0;
    this->fx = 0;
    this->fy = 0;
    this->fxx = 0;
    this->fxy = 0;
    this->fyy = 0;
  }

  coefs(double f, double fx, double fy, double fxx, double fxy, double fyy) {
    this->f = f;
    this->fx = fx;
    this->fy = fy;
    this->fxx = fxx;
    this->fxy = fxy;
    this->fyy = fyy;
  }

  coefs(double v, int is) {
    this->f = v;
    this->fxy = 0;
    this->fxx = 0;
    this->fyy = 0;
    if(is == 0){
      this->fx = 1;
      this->fy = 0;
    }
    else {
      this->fx = 0;
      this->fy = 1;
    }
  }

  coefs(const coefs &v) {
    this->f = v.f;
    this->fx = v.fx;
    this->fy = v.fy;
    this->fxx = v.fxx;
    this->fxy = v.fxy;
    this->fyy = v.fyy;
  }

  coefs &operator =(const coefs &v) {
    this->f = v.f;
    this->fx = v.fx;
    this->fy = v.fy;
    this->fxx = v.fxx;
    this->fxy = v.fxy;
    this->fyy = v.fyy;
    return *this;
  }


  void print() {
    cout << this->f << " " << this->fx << " " << this->fy << " " << this->fxx << " " << this->fxy << " " << this->fyy << " " << endl;
  }


  ~coefs(){}
};

coefs operator -(const coefs &v) {
  coefs h;
  h.f = v.f * (-1);
  h.fx = v.fx * (-1);
  h.fy = v.fy * (-1);
  h.fxx = v.fxx * (-1);
  h.fxy = v.fxy * (-1);
  h.fyy = v.fyy * (-1);
  return h;
}

coefs operator +(const coefs &u, const coefs &v) {
    coefs h;
    h.f = u.f + v.f;
    h.fx = u.fx + v.fx;
    h.fy = u.fy + v.fy;
    h.fxx = u.fxx + v.fxx;
    h.fxy = u.fxy + v.fxy;
    h.fyy = u.fyy + v.fyy;
    return h;
}

coefs operator -(const coefs &u, const coefs &v) {
    coefs h;
    h.f = u.f - v.f;
    h.fx = u.fx - v.fx;
    h.fy = u.fy - v.fy;
    h.fxx = u.fxx - v.fxx;
    h.fxy = u.fxy - v.fxy;
    h.fyy = u.fyy - v.fyy;
    return h;
}

coefs operator *(const coefs &u, const coefs &v) {
    coefs h;
    h.f = u.f * v.f;
    h.fx = u.fx * v.f + u.f * v.fx;
    h.fy = u.fy * v.f + u.f * v.fy;
    h.fxx = 2 * u.fx * v.fx + u.fxx * v.f + u.f * v.fxx;
    h.fyy = 2 * u.fy * v.fy + u.fyy * v.f + u.f * v.fyy;
    h.fxy = u.fx * v.fy + u.fy * v.fx + u.fxy * v.f + u.f * v.fxy;
    return h;
}

coefs operator /(const coefs &u, const coefs &v) {
    coefs h;
    h.f = u.f / v.f;
    h.fx = (u.fx - u.f * v.fx / v.f) / v.f;
    h.fy = (u.fy - u.f * v.fy / v.f) / v.f;
    h.fxx = (u.fxx - 2 * v.fx * h.fx - h.f * v.fxx) / v.f;
    h.fyy = (u.fyy - 2 * v.fy * h.fy - h.f * v.fyy) / v.f;
    h.fxy = (u.fxy - h.fy * v.fx - h.fx * v.fy - h.f * v.fxy) / v.f;
    return h;
}

coefs operator +(const double &u, const coefs &v) {
  coefs h;
  h.f = u + v.f;
  h.fx = v.fx;
  h.fy = v.fy;
  h.fxx = v.fxx;
  h.fxy = v.fxy;
  h.fyy = v.fyy;
  return h;
}

coefs operator +(const coefs &v, const double &u) {
  coefs h;
  h.f = u + v.f;
  h.fx = v.fx;
  h.fy = v.fy;
  h.fxx = v.fxx;
  h.fxy = v.fxy;
  h.fyy = v.fyy;
  return h;
}

coefs operator -(const double &u, const coefs &v) {
  coefs h;
  h.f = u - v.f;
  h.fx = v.fx * -1;
  h.fy = v.fy * -1;
  h.fxx = v.fxx * -1;
  h.fxy = v.fxy * -1;
  h.fyy = v.fyy * -1;
  return h;
}

coefs operator -(const coefs &v, const double &u) {
  coefs h;
  h.f = v.f - u;
  h.fx = v.fx;
  h.fy = v.fy;
  h.fxx = v.fxx;
  h.fxy = v.fxy;
  h.fyy = v.fyy;
  return h;
}

coefs operator *(const coefs &v, const double &u) {
  coefs h;
  h.f = v.f * u;
  h.fx = v.fx * u;
  h.fy = v.fy * u;
  h.fxx = v.fxx * u;
  h.fxy = v.fxy * u;
  h.fyy = v.fyy * u;
  return h;
}

coefs operator *(const double &u, const coefs &v) {
  coefs h;
  h.f = v.f * u;
  h.fx = v.fx * u;
  h.fy = v.fy * u;
  h.fxx = v.fxx * u;
  h.fxy = v.fxy * u;
  h.fyy = v.fyy * u;
  return h;
}


coefs operator /(const coefs &v, const double &u) {
  coefs h;
  h.f = v.f / u;
  h.fx = v.fx / u;
  h.fy = v.fy / u;
  h.fxx = v.fxx / u;
  h.fxy = v.fxy / u;
  h.fyy = v.fyy / u;
  return h;
}

coefs operator /(const double &u, const coefs &v) {
  coefs h;
  h.f = u/v.f;
  h.fx = u/v.fx;
  h.fy = u/v.fy;
  h.fxx = u/v.fxx;
  h.fxy = u/v.fxy;
  h.fyy = u/v.fyy;
  return h;
}

coefs sin(const coefs &v) {
  coefs h;
  h.f = sin(v.f);
  h.fx = cos(v.f) * v.fx;
  h.fy = cos(v.f) * v.fy;
  h.fxx = ((-sin(v.f)) * v.fx * v.fx) + (v.fxx * cos(v.f));
  h.fxy = ((-sin(v.f)) * v.fy * v.fx) + (v.fxy * cos(v.f));
  h.fyy = ((-sin(v.f)) * v.fy * v.fy) + (v.fyy * cos(v.f));
  return h;
}

coefs cos(const coefs &v) {
  coefs h;
  h.f = cos(v.f);
  h.fx = -(sin(v.f)) * v.fx;
  h.fy = -(sin(v.f)) * v.fy;
  h.fxx = -(sin(v.f)) * v.fxx - v.fx * v.fx * cos(v.f);
  h.fxy = -(sin(v.f)) * v.fxy - v.fx * v.fy * cos(v.f);
  h.fyy = -(sin(v.f)) * v.fyy - v.fy * v.fy * cos(v.f);
  return h;
}

coefs exp(const coefs &v) {
  coefs h;
  h.f = exp(v.f);
  h.fx = exp(v.f) * v.fx;
  h.fy = exp(v.f) * v.fy;
  h.fxx = exp(v.f) * v.fx * v.fx + exp(v.f) * v.fxx;
  h.fxy = exp(v.f) * v.fx * v.fy + exp(v.f) * v.fxy;
  h.fyy = exp(v.f) * v.fy * v.fy + exp(v.f) * v.fyy;
  return h;
}

int main() {

/*  coefs a = coefs(1.1, 1.2, 1.3, 1.4, 1.5, 1.6);
      coefs b = coefs(1.9, 1.8, 1.7, 1.6, 1.5, 1.4);

      a.print();
      coefs c = a+b;
      c.print();
      coefs d = a - b;
      d.print();
      coefs e = a*b;
      e.print();
      coefs f = a/b;
      f.print();
      coefs g = a*2;
      g.print();
      coefs h = 2*a;
      h.print();
      coefs i = sin(a);
      i.print();
      coefs j = cos(a);
      j.print();
      coefs k = exp(a);
      k.print();

*/

  int M;
  cin >> M;
  double x,y;

  for(int i = 0; i < M; i++) {
    cin >> x;
    cin >> y;
    coefs X(x,0);
    coefs Y(y,1);
    coefs wynik = funkcja(X,Y);
    cout << setprecision(15) << fixed;
    wynik.print();
  }
}
