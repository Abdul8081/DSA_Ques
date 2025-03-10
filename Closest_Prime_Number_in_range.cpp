#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        //filling of the seive vector
        vector<int> seive(int upperLimit){
            vector<int> seive(upperLimit+1, 1); // initially assuming every digit is prime number
            seive[0] = 0;
            seive[1] = 0;
    
            for(int num = 2; num*num <=upperLimit; num++) {
                if(seive[num]==1) {
                    for(int multiple = num*num; multiple<=upperLimit; multiple+= num){
                        seive[multiple] = 0;
                    }
                }
            }
            return seive;
        }
        vector<int> closestPrimes(int left, int right) {
            vector<int>sieveArray = seive(right); // storing seive array
            vector<int> prime;
            for(int i=left; i<=right; i++) {
                if(sieveArray[i]==1) prime.push_back(i); //checking each i, prime based on seive array.
            }
            pair<int,int> closestPair;
            if(prime.size() < 2) return {-1, -1};
            else{
                int mindiff = INT_MAX;
                for(int i=0; i<prime.size()-1; i++) {
                    if((prime[i+1]-prime[i]) < mindiff){
                        mindiff = min(mindiff, (prime[i+1]-prime[i]));
                        closestPair.first = prime[i];
                        closestPair.second = prime[i+1];
                    }
                }
                return {closestPair.first, closestPair.second}; 
            }
        }
    };