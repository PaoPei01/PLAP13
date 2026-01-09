#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << fixed << setprecision(2);
    cout << "Arithmetic Mean = " << B[0] << endl;
    cout << "Standard Deviation = " << B[1] << endl;
    cout << "Geometric Mean = " << B[2] << endl;
    cout << "Harmonic Mean = " << B[3] << endl;
    cout << "Max = " << B[4] << endl;
    cout << "Min = " << B[5];
    return 0;
}

void stat(const double a[], int n, double b[]) {
    double sum = 0;
    double sum_sq = 0;
    double pd = 1;
    double sum_inv = 0;
    double max = a[0];
    double min = a[0];

    for (int i = 0; i < n; i++) {
        sum += a[i];
        sum_sq += pow(a[i], 2);
        pd *= a[i];
        sum_inv += 1.0 / a[i];
        
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }

    b[0] = sum / n;
    b[1] = sqrt((sum_sq / n) - pow(b[0], 2));
    b[2] = pow(pd, 1.0 / n);
    b[3] = n / sum_inv;
    b[4] = max;
    b[5] = min;
}