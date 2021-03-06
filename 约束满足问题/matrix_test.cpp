#include <iostream>
#include <armadillo>
using namespace std;
using namespace arma;

int main() {
    mat A = randu<mat>(5,10);
    mat C = randu<mat>(10,5);
    mat U = A * C;
    U.print("U:");
    mat V = inv(U);
    V.print("V:");
    double D = det(U);
    cout<<"det(U)="<<D<<endl;
    return 0;
}