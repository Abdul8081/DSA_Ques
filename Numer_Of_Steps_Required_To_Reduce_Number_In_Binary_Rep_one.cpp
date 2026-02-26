class Solution {
public:
    // Idea : if get the digit 1 (odd) -> on adding 1 over this, will leads to zero, and then again we will remove that, because that will be again become even and needed to divide by 2, hence we will increase steps by 2.
    // ans also we will set here carry = 1, becasue again adding 1 & 1 will become 2, this will send the carry for next bit. 
    int numSteps(string s) {
        int carry = 0;
        int steps = 0;

        int i = s.length()-1;
        while( i >= 1) {
            
            int lastBit = ((carry + (s[i] - '0')) & 1); // here & mean mod with 2

            if(lastBit == 0){
                s.pop_back();
                steps += 1;
            }
            else {
                steps += 2;
                carry = 1;
            }
            i--;
        }

        return steps + carry;
    }
};