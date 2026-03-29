#include<bits/stdc++.h>
using namespace std;

/*
In the set, every operation is used to happen in the log(n), it is also implemented internally by Red-Black-Tree. and in this also
when we do any operation like insert, erase, delete then fist comparision is done internally then we get the iterator and then we delete

IMP : there is difference between erasing with these two approach
set<string> st;
st.insert("abd");

auto it = st.find("abd")

here basically iterator find out the key abd, and then it return last st.end() if it not able to find, and it return the actual iterator
if it found that. 


if(it != st.end()) {
    st.erase(it)
}

and

st.erase("abd");

in this also it first try to find all the iterator and then delete that iterator, it may not make sense, like all the iterator here, because
since this is set, then unique index will be there, then we can use this directly st.erase("abd"), well, this makes sense here, but in teh case
of the multiset, we will have some problem with this, so basically in the multiset, everything implemented in the same way, only difference is 
we can store the duplicate key as well, well people say this could be helpfull in the case of the priority queue, well I don't know about this 
right now, I will explore later about this. 

so in the multiset
multiset<int> mst;

mst.insert("abd");
mst.insert("abd");
mst.insert("ads");

if we do like
mst.erase("abd") -> it will delete all the abd, mst.size() => 1

if we do like

auto it = mst.find("abd");
if(it != mst.end()) {
    mst.erase(it);
}

it will delete the first iterator it found, like it iwill delete the first "abd", -> after this ops -> mst.size() = 2, with "abd", "ads" value
*/

int main() {
    int n; cin>>n;
    set<string> st;
    for(int i = 0; i < n; i++) {
        string str; cin>>str;
        st.insert(str);
    }

    int q; cin>>q;
    for(auto &str: st) {
        cout<<str<<endl;
        q--;
        if(!q) break;
    }
}

// Qn find the first k lexiographical string