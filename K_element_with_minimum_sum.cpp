#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        //generate first K sorted list, then Keep going filling answer, see K sorted list
        vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
            auto compare = [&](const vector<int> & a, const vector<int> &b){
                return a[0] + a[1]> b[0] + b[1]; //this is creting here asending order.
            };
            priority_queue<vector<int> , vector<vector<int>>, decltype(compare)> pq(compare); //min heap vector, elemnts sum
    
            vector<vector<int>> res;
    
            //this are the base cases, not required
            if(nums1.empty() or nums2.empty() or k==0) {
                return res;
            }
    
            for (int i=0; i<nums1.size(); i++) {
                //pushing elements in pq, of first vector along with the element of second vector and index of second vector, with the pattern follow here, we are able to reach all the element of second vector     
                pq.push({nums1[i], nums2[0], 0});
            }
            while(k-- and !pq.empty()) {
                vector<int> curr = pq.top();
                pq.pop();
    
                res.push_back({curr[0], curr[1]});
                if(curr[2] == nums2.size()-1) {
                    continue;
                }
    
                pq.push({curr[0], nums2[curr[2]+1], curr[2]+1});
            }
    
            return res;
        }
    };