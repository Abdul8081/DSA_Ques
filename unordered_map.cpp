#include<bits/stdc++.h>
using namespace std;

// Qn : print the frequencly of a element for given Q query.

/*
So, in the unordered map, it implies all the property of the map, but only difference is there, in the term of the
1. Time complexity
2. Ordering
3. Internal Implementation

So unlike map, it has almost O(1) TC for every basics stl implementation,

It does not give value in the ordering, means if we are applying any look like we used to do for auto,
we will not get the value in the same order as we have inserted into this.

Internal Implementation of the unordered_set is happen with the HashTable unlike red-black tree in the map, so which helps to
reduce the TC for the basics stl to O(1), also we can't give key as the complex data structure in the case of the unordered map, because
internal implementation of hash for that data structure has not been defined, so complex data structure means here the pair<int, int>, set<set> vector<int> like this.
well we can do that as well, but we will required to made the explicit hash function for that Data structure.

but in the case of the map, we can give that, because there comparison is used to happen, and we can directly compare to vector, set etc    

so it basically hash the key which we give and then store that, but if hash of a particular key is same then it do the comparing, so it's not like
it will have always O(1), because we needed to consider the collision as well, but average O(1) it gives. for insert, deleted, lookup any element

both type of these store the unique key, basically it can store duplicate key as well, when we will use the multiset, but let's ignore that for
now, so unordered_map, and map both store unique key. 

*/
int main() {
    int n; cin>>n;
    unordered_map<string, int> mp;

    for(int i = 0; i < n; i++) {
        string str;
        cin>> str;

        mp[str]++;

    }

    int Q; cin>>Q;

    while(Q--) {
        string str; cin>> str;

        cout<<mp[str]<<endl;
    }
}