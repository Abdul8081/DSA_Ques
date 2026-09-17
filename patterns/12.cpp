#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int cnt = 2 * n - 2;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout <<j;
        }
        for (int k = 1; k <= cnt; k++) {
            cout <<" ";
        }
        cnt -= 2;

        for (int j = i; j >= 1; j--) {
            cout <<j;
        }
        cout << endl;
    }
}