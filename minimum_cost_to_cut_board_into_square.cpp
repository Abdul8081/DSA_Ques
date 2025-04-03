#include<bits/stdc++.h>
using namespace std;
#define ll long long int
/*
Problem : A board of lenth M and width N is given. The task is to break this board llo M * N square such that cost of breaking is minimum. The cutting cost for each edge will be given for the board in two array x[] and y[], In short you need to choose such that const is minimized. Return the minimised cost

Test Case : 
Input : 
M : 6, N : 4
X[] = {2, 1, 3, 1, 4}
Y[] = {4, 1, 2}

Ouput : 42
*/

/*
logic : cut the larger cost first, as number of the pieces will be less initially ,because on each cut, either horizontal or vetical required cut will increase
*/

ll minCostToBreakGrid(vector<ll> horizontal, vector<ll> vertical) {
    ll ans = 0;
    sort(horizontal.begin(), horizontal.end(), [](ll x, ll y) {
        return x > y;
    });

    sort(vertical.begin(), vertical.end(), [](ll x, ll y) {
        return x > y;
    });

    ll h = 0, v = 0; 
    ll hc = 1, vc = 1; 
    while(v < vertical.size() and h < horizontal.size()) {
        if(vertical[v] < horizontal[h]) {
            ans += horizontal[h] * hc;
            h++;
            vc++;
        }
        else {
            ans += vertical[v] * vc;
            v++;
            hc++;
        }
    }

    //Case of earlier completion of the any vector
    while(h < horizontal.size()) {
        ans += horizontal[h] * vc;
        h++;
        hc++;
    }
    while(v < vertical.size()) {
        ans += vertical[v] * hc;
        v++;
        vc++;
    }

    return ans;
}
int main() {
    ll m, n; 
    cin>>m>>n;

    vector<ll> horizontal, vertical;
    for(ll i=0; i<m-1; i++) {
        ll x; cin>>x;
        horizontal.push_back(x);
    }

    for(ll i=0; i<n-1; i++) {
        ll x; cin>>x;
        vertical.push_back(x);
    }

    cout<<minCostToBreakGrid(horizontal, vertical);

    
}