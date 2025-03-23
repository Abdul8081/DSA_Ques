#include<bits/stdc++.h>
using namespace std;

#define pp pair<int, string>
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for(int i=0; i<words.size(); i++) mp[words[i]]++;

        //this is for the pushing element in the min heap, while keeping fancy constrained
        auto cmp = [](const pp &a,const pp&b) {
            return (a.first==b.first) ? a.second < b.second : a.first > b.first;
            // a.second < b.second -> it means, storing with smaller word(means a, b, c,..) behaving like min Heap, since frequency is same, word which are lexicographically comes earlier will be inserted there. 
            // a.first > b.first it means, behaving like MaxHeap, maximum frequency one, will be ahed
        };

        priority_queue<pp, vector<pp>, decltype(cmp)> pq;
        for(const auto& [el, freq] : mp) {
            pq.push({freq, el});
            if(pq.size() > k) pq.pop(); //Keep In MinHeap, with No. of element = k 
        }

        vector<string> ans;
        while(pq.size()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};