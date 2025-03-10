#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        
        bool checkPowersOfThree(int n) {
            //similarly for the number,if there is other than 3, we can also do here for 4, 5, 6, 7, 
            //idea is : if cofficient is coming > 1 then it will not correct, as we have to take distinct powers, and if cofficint is coming other than 0,1 than it means that power has been added by more than 1. 
            while(n) {
                if(n%3==2) return false;
                n/=3; 
            }
            return true;
        }
    };