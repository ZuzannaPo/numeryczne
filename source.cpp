//Zuzanna Poznanska gr 2

#include <iostream>
#include <vector>
#include "source.h"

using namespace std;

spline::spline(int n) {
    this->n = n - 1;
    this->h = new double[n - 1];
    this->b = new double[n - 1];
    this->u = new double[n - 1];
    this->v = new double[n - 1];
    this->z = new double[n];
}

void spline::set_points(double *t_, double *y_) {

    this->t = t_;
    this->y = y_;

    for (int i = 0; i < n; ++i) {
        h[i] = t[i + 1] - t[i];
        b[i] = 6 * (y[i + 1] - y[i]) / h[i];
    }

    u[1] = 2 * (h[0] + h[1]);
    v[1] = b[1] - b[0];

    for (int i = 2; i < n; ++i) {
        u[i] = 2 * (h[i - 1] + h[i]) - pow(h[i - 1], 2) / u[i - 1];
        v[i] = b[i] - b[i - 1] - h[i - 1] * v[i - 1] / u[i - 1];
    }

    z[n] = 0.;
    for (int i = n - 1; i >= 1; --i) {
        z[i] = (v[i] - h[i] * z[i + 1]) / u[i];
    }
    z[0] = 0.;

}

double spline::operator()(double Z) const {
    int i = n - 1;
    while (i >= 0 && Z - t[i] < 0) {
        i--;
    }

    double A = (z[i + 1] - z[i]) / (6.0 * h[i]);
    double B = z[i] / 2.0;
    double C = (y[i + 1] - y[i]) / (h[i]) - (h[i] * (z[i + 1] + 2.0 * z[i])) / 6.;
    double S = y[i] + (Z - t[i]) * (C + (Z - t[i]) * (B + ((Z - t[i]) * A)));

    return S;
}
/*
int main(int argc, char** argv) {

   cout.precision(15);
   cout << fixed;

   int size = 6;
   double X[] = {0, 0.2, 0.4, 0.6, 0.8, 1};
   double Y[] = {-3,-2.56,-2.04,-1.44,-0.76,0};

   spline s(size);
   s.set_points(X, Y);

   for(int i=0; i < size - 1; i++) {
     std::cout << s(X[i]) << "  " << s(X[i]+0.02) << "  "<< s(X[i]+0.07) <<  std::endl;
   }

   return 0;
}*/
