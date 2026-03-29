#include <bits/stdc++.h>
using namespace std;

/*
Multiset is an associative container similar to a set, but it can store mulitiple
elements with the same value. it is sorted in increasing order by default,
but it can be changed to any desired order using a custom comparator.

IMP
1. allows duplicate elements, unlike a set,
2. Support standard set operations like insert(), erase(), count(), and find()
3. It also internally seems to be using a Self-Balancing Binary Seach Tree (like set), 
basically has been implemented with the red-black tree, handling duplicates by making a ruler
to either insert in the left or right subtree to ensure O(log n) time 
complexity of operations
*/

int main(){
    int n; cin >> n;
    multiset<int> mst;

    for(int i = 0; i < n; ++i) {
        int k; cin>>k;
        mst.insert(k);
    }

    for(auto &el: mst) {
        cout << el << " ";
    }
}