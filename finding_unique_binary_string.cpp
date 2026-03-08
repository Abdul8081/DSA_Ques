class Solution {
public:
    string to_binary(long long n){
        string temp = "";
        while(n){
            temp += (n & 1) + '0';
            n >>= 1;
        }
        reverse(begin(temp), end(temp));
        return temp;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<long long> st;
        for(int i = 0; i < nums.size(); i++) {
            /*
            here nums[i] : string which we wanted to convert
            nullptr : it this case it does not matter, but if we needed to deal with string of type 101ab, then we would take only 101 then : corresponding in that case nullptr will come into the picture. in that case nullptr will be like below syntax

            string s = "123abc456";
            size_t pos;

            long long num = stoll(s, &pos, n);
            so it will also tell how many position has been parse, 
            here pos = 3; basically it will store length of the string which has been coverted

            n : can be 2 - 16, so it can be base 2, 3, 4,  . . . 16 

            */
            st.insert(stoll(nums[i], nullptr, 2));
        }
        for(long long i = 0; i < (1 << n); i++) {
            if(!st.count(i)) {
                string ans = to_binary(i);
                int len = ans.size();
                if(len == n) return ans;
                else {
                    while(ans.length()!=n){
                        ans = "0" + ans;
                    }
                    return ans;
                }
                
            }
        }
        return "";
    }
};

// 1 : 0, 1
// 2 : 0, 1, 2, 3
// 000 001 010 011 100 101 110 111 1000 1001 1010 1011 1100 1101 1110 1111
// 3: 0, 1, 2, 3, 4, 5, 6, 7
// 4: 0 to 15

// for any n : it would be all from 0 to (2 pow n) - 1