#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        long long atleast(string word, int k) {
            unordered_map<char, int> VowelCount; // for the tracking of the each vowel frequency. Basically using two pointer approach, expansion and srinking
            // 1. when we have found out vowel and atleast k, then we are counting valid answer. 2. and then shrinking from start if we can get other valid answer while decresing the frequency of the vowels or constonant keep cheking the condition, as done int the second while loop, at the end, we will continue expantion untill we find out the valid (vowel + consonant) , {and go till last of the word}  when we will found again vowel + consonant with condition,  2nd loop will do its work, shrinking start, and get all validAns
            long long validAns = 0;
            int start = 0, end = 0;
            int consonantCount = 0;
            while(end < word.length()) {
                char new_ch = word[end];
                if(isVowel(new_ch)) VowelCount[new_ch]++;
                else consonantCount++;
                //shrinking of the window
                while(VowelCount.size()==5 and consonantCount >=k) {
                    validAns+= word.length() - end;
                    char startLetter = word[start];
                    if(isVowel(startLetter)) {
                        if(--VowelCount[startLetter] == 0) VowelCount.erase(startLetter);
                    }
                    else consonantCount--;
                    start++;
                }
                end++;
            }
            return validAns;
        }
        bool isVowel(char c){
            return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
        }
        long long countOfSubstrings(string word, int k) {
            // k, k+1, K+2...   - k+1,k+2... -> we will find exactly k
            return atleast(word, k) - atleast(word, k+1);
        }
    };