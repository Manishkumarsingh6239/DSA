#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> window_f(26,0);
        vector<int> s1_f(26,0);

        for (int i=0;i<s1.size();i++){
            s1_f[s1[i]-'a']++;
            window_f[s2[i]-'a']++;
        }
        if (s1_f==window_f) return true;

        for(int i=s1.size();i<s2.size();i++){
            window_f[s2[i-s1.size()]-'a']--;
            window_f[s2[i]-'a']++;
            if (s1_f==window_f) return true;
        }
        return false;
    }
};