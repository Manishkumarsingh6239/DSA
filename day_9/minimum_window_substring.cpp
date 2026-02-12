#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
       if(s.empty() || t.empty() || s.size()<t.size()) return "";

       vector<int> map(128,0);
       for(auto ch:t){
        map[ch]++;
       }
       int count = t.length(), start = 0, end=0, minlength=INT_MAX, startIndex=0;

       while(end<s.length()){
        if(map[s[end++]]-->0){
            count--;
        }

        while(count==0){
            if(end-start < minlength){
                startIndex = start;
                minlength=end-start;
            }

            if(map[s[start++]]++==0){
                count++;
            }
        }
       }
       return minlength==INT_MAX ? "" : s.substr(startIndex,minlength);
    }
};