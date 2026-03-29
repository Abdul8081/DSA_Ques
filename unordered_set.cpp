#include<bits/stdc++.h>
using namespace std;

/*
So this is implemented internally with hash table, we can't provide the duplicate key, and also we can't provide
complex data structure as the key, like the pair<int, int> or set<int> or something like that.

since this uses hash table it's almost all the basic operation used to completed in O(1), like insert, erase, find etc

we use this when we wanted to store the unique key and we don't needed to maintain
*/
int main() {
    unordered_set<string> st;

    int n; cin>>n;

    for(int i = 0; i < n; i++) {
        string str; cin>>str;

        st.insert(str);
    }

    int k, q;
    cin>>q>>k;

    while(q--) {
        int m = k;
        for(auto &str: st){
            cout << str << endl;
            m--;
            if(!m) break;
        }
    }
}

// Qn find the k lexico graphically smallest string for q querry