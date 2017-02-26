#include "Function.h"
#include <iostream>
#include <fstream>
using namespace std;

void read_data(const string file, double *arr) {
    ifstream infile(file.c_str());
    string s = "";
    infile >> s >> s;
    int i = 0;
    while (infile >> s >> arr[i++]);
}

double* daily_return(const double a[], const int n) {
    double *dailyReturn = new double[n-1];
    for (int i = 0; i < n - 1; i++) {
        dailyReturn[i] = (a[i + 1] - a[i]) / a[i];
    }
    return dailyReturn;
}

double getCovariance(const double *a, const double *b, const int n) {
    double sumA = 0, sumB = 0, total = 0;
    for (int i = 0; i < n; i++) {
        sumA += a[i];
        sumB += b[i];
    }
    double meanA = sumA/n, meanB = sumB/n;
    for (int i = 0; i < n; total += (a[i] - meanA) * (b[i] - meanB), i++);
    return total / (n - 1);
}

