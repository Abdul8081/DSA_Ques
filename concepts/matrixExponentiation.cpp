#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
typedef long long int ll;
typedef vector<vector<ll>> Matrix;

Matrix MatrixMultiplication(Matrix &A, Matrix & B) {
    Matrix result(2, (vector<ll> (2, 0)));
    for(int r = 0; r < 2; r++) {
        for(int c = 0; c < 2; c++) {
            for(int k = 0; k < 2; k++) {
                result[r][c] =(result[r][c] +  A[r][k] * B[k][c]) % M;
            }
        }
    }

    return result;

}

Matrix MatrixExponentiation(Matrix &base, int exponent) {
    if(exponent == 0) {
        // make identity matrix, because on squaring the t, it gives us identity matrix
        Matrix identity(2, (vector<ll> (2, 0)));

        for(int i = 0; i < 2; i++) {
            identity[i][i] = 1;
        }

        return identity;
    }

    Matrix half = MatrixExponentiation(base, exponent / 2);
    Matrix result = MatrixMultiplication(half, half);
    if(exponent & 1) {
        result = MatrixMultiplication(result, base);
    }
    return result;
}
int FibonacciWithMatrixMultiplication(int n) {
    // this is there for 2 * 2 matrix, this is t, if we wanted to T of 3 * 3 then see online how can we get that, 
    // so basically this T will be of deg * deg dimention, where deg = no or linear dependency in the linear recurrence 
    //like there are two in the case of the fibonacci, f(n-1) & f(n-2), similary we can't decide the degree of the t

    if (n == 0) {
        return 0;
    }
    
    Matrix T = {{1, 1}, {1, 0}};

    Matrix mat = {{1}, {0}};  // f(1), f(0)
    // eqn is : fn = tn * {mat}

    Matrix Tn = MatrixExponentiation(T, n - 1);

    Matrix result = MatrixMultiplication(Tn, mat);

    return result[0][0];
}

int Fibonacci(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    int n; cin>>n;

    for(int i = 0; i < n; i++) {
        cout << Fibonacci(i) << " ";
    }

    cout << endl;

    for(int i = 0; i < n; i++) {
        cout << FibonacciWithMatrixMultiplication(i) << " ";
    }

}