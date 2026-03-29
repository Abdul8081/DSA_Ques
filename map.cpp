#include<bits/stdc++.h>
using namespace std;

// write a program for finding the string in lexiographical order along with there frequency. 

/*
In the normal map: it is implemented internally with the redblac tree; 
so here, it+1 != it++; basically it it is not continuous allocation, hence we can't do it+1;

all the operation is happen in the O(log(n)), here n is the current size of the map, but in the case 
of the string, we if we are using string as the input then we can't do all the operation in O(log(n))
mine all the operation means (insert, delete, find ... basics stl)

why can't we do string in O(log(n)), because when we made key as the string in the map, then we first compare
with all other keys present there and based on that, we give place the key as the proper place. 
so for doing operation with the string, if we are making it as the key, then we will also needed to add the 
time for comparing of it as well therefore time complexity for this case will be : s.size() * O(log(n)); for any basic stl

also map store the value in the increasing order / sorted order / lexiographically smallest order / non - decreasing order
also map don't store duplicate key, means if we are giving key and value in which key alredy exit, then it will update the value
corresponding to the key, not store separate key and value.
*/
int main() {
    int n; cin>>n;
    map <string, int> mp;
    for(int i = 0; i < n; i++) {
        string str; int freq;
        cin>> str>> freq;
        mp[str]++;
    }

    for(auto &pr: mp) {
        cout<<pr.first << " " << pr.second << endl;
    }
}

