//Approach 1
class Solution {
public:	
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> suffixMax(n);
        vector<int> prefixMax(n);

        prefixMax[0] = height[0];
        for(int i = 1; i < n; i++) {
            prefixMax[i] = max(prefixMax[i-1], height[i]);
        }

        suffixMax[n-1] = height[n-1];
        for(int i = n - 2; i >=0; i--) {
            suffixMax[i] = max(suffixMax[i+1], height[i]);
        }
        

        int total = 0;

        for(int i = 0; i < n; i++) {
            int h = height[i];
            if(h < prefixMax[i] && h < suffixMax[i]) {
                total += min(prefixMax[i], suffixMax[i]) - h;
            }
        }
        return total;
    }
};



// Approach 2
class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lMax = height[0];
        int rMax = height[height.size()-1];

        int total = 0;
        while(l < r) {
            if(height[l] < height[r]) {
                if(lMax >= height[l]) {
                    total += lMax - height[l];
                    l++;
                }
                else lMax = height[l];
            }
            else {
                if(rMax >= height[r]) {
                    total += rMax - height[r];
                    r--;
                }
                else rMax = height[r];
            }
        }
        return total;
    }
};