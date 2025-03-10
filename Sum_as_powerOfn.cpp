class Solution {
    public:
        
        bool checkPowersOfThree(int n) {
            //here for any k, we can do this. 
            int k = 3; 
            while(n) {
                if(n%k>1) return false;
                n/=k; 
            }
            return true;
        }
    };