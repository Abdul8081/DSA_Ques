#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string repeatLimitedString(string s, int repeatLimit) {
            //storing of the character with their freq. 
            unordered_map<char, int> mp;
            for(int i=0; i<s.length(); i++) {
                mp[s[i]]++;
            }
            //keeping maxHeap, which will keep lexicographical character higher at the top, and keep their freq. 
            priority_queue<pair<char, int>> pq;
            for(auto p : mp) {
                pq.push(p);
            }
    
            string result = "";
            while(pq.size()) {
                auto[lChar, lFreq] = pq.top();
                pq.pop();
                
                int len = min(lFreq, repeatLimit);
    
                for(int i=0; i<len; i++) result += lChar;
    
                pair<char, int> secondLargest;
                if(lFreq - len > 0) {
                    if(!pq.empty()) { 
                        secondLargest = pq.top();
                        pq.pop();
    
                        result += secondLargest.first;
                    }
                    else return result;
                    //if secondLargest freq. > 1, then needed to push again with updated freq. 
                    if(secondLargest.second - 1 > 0) pq.push({secondLargest.first, secondLargest.second -1});
                    pq.push({lChar, lFreq - len}); //pushing remaining largest element.
                }
            }
            return result;
        }
    };