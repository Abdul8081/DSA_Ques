#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;

    for (int i = 0; i < 2 * n + 2; i++) cout << "*";

    cout << endl;

    int gap = 2;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }

        for (int j = 1; j <= gap; j++) {
            cout << " ";
        }
        gap += 2;

        for (int j = 0; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }

    gap = 2 * n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*";
        }

        for (int j = 1; j <= gap; j++) {
            cout << " ";
        }
        gap -= 2;

        for (int j = 0; j <= i; j++) {
            cout << "*";
        }

        cout << endl;
    }

    for (int i = 0; i < 2 * n + 2; i++) cout << "*";
}