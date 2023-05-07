// Zuzanna Poznańska gr 2

#include <iostream>
#include <iomanip>

using namespace std;

int silnia(int n) {
	int x = 1;
	while (n) {
		x = x * n;
		n--;
	}
	return x;
}

void Hermit(int m, long double *x, long double *y, long double *a) {
  int *K = new int[m+1];
  K[0] = 0;

  for(int i = 1; i< m; i++) {
    if(x[i] == x[i-1]) K[i] = K[i-1] +1;
    else K[i] = 0;
  }

  long double  *A = new long double[m+1];
  long double b;
  int ind;
  for(int i=0; i<m; i++){
    if (K[i] == 0) {
      A[i] = y[i];
      b = y[i];
      ind = i;
    }
    else A[i] = b;

    for(int k = i-1; k>=0; k--) {
      if(x[i] != x[k]) A[k] = (A[k+1] - A[k]) / (x[i] - x[k]);
      else A[k] = y[ind +i -k]/silnia(K[ind+i-k]);
    }
    a[i] = A[0];
  }
  delete []A;
  delete []K;
}

long double polynomial(int n, long double t, long double *a, long double *x) {
	long double pt = a[0];
	long double xx = (t - x[0]);

	for(int i=1; i<n; i++) {
		pt += a[i] * xx;
		xx *= (t - x[i]);
	}

	return pt;
}

int main() {


  int M, N;
  cin >> M;
  cin >> N;

  long double *X = new long double[M];
  long double *Y = new long double[M];
  long double *T = new long double[N];

  for(int i=0; i<M; i++) {
    cin >> X[i];
  }

  for(int i=0; i<M; i++) {
    cin >> Y[i];
  }

  for(int i=0; i<N; i++) {
    cin >> T[i];
  }

  long double *A = new long double[M];

  Hermit(M,X,Y,A);

	cout << setprecision(17) << fixed;
  for(int i = 0; i<M; i++) {
    cout << A[i] << " ";
  }
  cout << endl;

	long double *W = new long double[N];
	for(int i=0; i<N; i++) {
		W[i] = polynomial(M,T[i],A,X);
		cout << W[i] << " ";
	}

  delete []X;
  delete []Y;
  delete []T;
  delete []A;
	delete []W;


}
