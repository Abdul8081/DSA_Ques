#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;

    for (int i = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == 2 * n - 2) cout << "*";
            else if (i % 2) cout << " ";
            else if ((i % 2 == 0 && j == 0) || (i % 2 == 0 && j == n - 1)) cout << "*";
            else if ((i % 2 == 0 && j != 0) || (i % 2 == 0 && j != n - 1)) cout << " ";
        }
        cout << endl;
    }
}