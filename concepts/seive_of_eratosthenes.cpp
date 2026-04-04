#include <bits/stdc++.h>
using namespace std;

// T.C : O(n log(log(n)));
// because when we actually calculate then it goes like n * sum_till_goes_on(1 / i), where is prime, so for inside become log(log(n));
int main() {
    int n; cin >> n;

    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;
    int k = sqrt(n);
    for(int fact = 2; fact <= sqrt(n); fact++) {
        if(isPrime[fact]) {
            for(int mul = fact * fact; mul < n; mul+=fact) {
                 isPrime[mul] = false;
            }
        }
    }

    for(int num = 0; num < n; num++) {
        if(isPrime[num]) cout << num <<" "; 

    }
}

//2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97