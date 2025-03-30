#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
            int n = heights.size();
            int i = 0, brickUsed = 0; 
            priority_queue<int> pq; //this is for the keeping track of the number of the brick used, and current uses comparasion. 
            for(; i<n-1; i++) {
                if(heights[i] >= heights[i+1]) continue;
                int heightDiff = heights[i+1] - heights[i];
                if(brickUsed + heightDiff <= bricks) {
                    brickUsed += heightDiff;
                    pq.push(heightDiff);
                }
                else if(ladders > 0) { // here checking if, ladder used, then if we can go more furthure. 
                    if(!pq.empty() and pq.top() > heightDiff) {
                        brickUsed = brickUsed - pq.top() + heightDiff; //restoring initial brick used. instead of that, here uses of ladder will be done. 
                        pq.pop(); 
                        pq.push(heightDiff);
                    }
                    ladders--;
                }
                else break;
            }
            return i;
        }
    };