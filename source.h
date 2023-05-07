// Zuzanna Poznanska gr 2

#include <vector>
#include <cmath>

using namespace std;

class spline {
public:
    int n;
    double *t, *y, *h, *b, *u, *v, *z;
public:
    spline(int n);

    void set_points(double t[], double y[]);

    double operator()(double z) const;
};
