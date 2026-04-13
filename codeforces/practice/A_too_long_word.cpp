#include<bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >>n;
    int k = n;
    vector<string> v;
    while(n--) {
        string s; cin>>s;
        v.push_back(s);
    }

    for(int i = 0; i < k; i++) {
        string s = v[i];
        if(s.length() <= 10) cout << s << endl;
        else cout << s[0]<<s.length()-2<<s[s.length()-1]<<endl;
    }
}