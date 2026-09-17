#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    int cnt = 1;

    for (int i = n - 1; i >= 0; i--) {
        for (int k = 1; k <= cnt; k++) {
            cout << "*";
        }
        cnt += 1;
        cout << endl;
    }

    cnt = n - 1;
    for (int i = 0; i < n - 1; i++) {
        for (int k = 1; k <= cnt; k++) {
            cout << "*";
        }
        cnt -= 1;
        cout << endl;
    }
}