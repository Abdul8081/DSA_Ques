#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int cnt = 2 * n - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout <<" ";
        }
        for (int k = 1; k <= cnt; k++) {
            cout << "*";
        }
        cnt -= 2;
        cout << endl;
    }
}