// Zuzanna Poznanska gr 2

#include <iostream>
using namespace std;

void sor(int N, int M, int mid, double **A, double *y, double *x, double w, int L) {

  mid -= 1;
  int buff = 1;
  for (int iter = 0; iter < L; iter++) {
      for (int i = 0; i < N; i++) {
          auto s = y[i];
          if (i - mid > 0) {
              buff = i - mid;
          } else {
              buff = 0;
          }
          for (int m = buff; m < i; m++) {
              if (abs(i - m) <= mid) {
                  s -= A[i - m + mid][i] * x[m];
              }
          }
          for (int m = i + 1; m < i + M - 1; m++) {
              if (abs(i - m) <= mid) {
                  s -= A[i - m + mid][i] * x[m];
              }
          }
          x[i] = (1 - w) * x[i] + w * s / A[mid][i];
      }
  }
  for(int i=0;i<N;i++)
      printf("%17.17f ",x[i]);
  printf("\n");
}

int main() {
  int N, M;
  cin >> N;
  cin >> M;
  int mid = ((M + 1) / 2);
  int low = N - mid + 1;

  double **A = new double*[M];
  for (int i= 0; i<M; i++) {
    A[i] = new double[N];
  }
  double y[N];
  double x[N];
  double w;
  int L;

  for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
          A[i][j] = 0;
      }
  }

  for (int i = 0; i < mid; i++) {
      int curr = low + i;
      for (int j = 0; j < curr; j++) {
          cin >> A[i][j];
      }
  }
  int num = 1;
  for (int i = mid; i < M; i++) {

      int curr = N - num;
      for (int j = 0; j < curr; j++) {
          cin >> A[i][j + num];
      }
      num++;
  }


  for (int i = 0; i < N; i++) {
      cin >> y[i];
  }
  for (int i = 0; i < N; i++) {
      cin >> x[i];
  }

  cin >> w;
  cin >> L;

  sor(N,M,mid,A,y,x,w,L);

  for(int i=0; i<M; i++) delete [] A[i];
  delete [] A;
}
