#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for (auto x:strs){
            string word = x;
            sort(word.begin(),word.end());
            mp[word].push_back(x);
        }
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = s.groupAnagrams(strs);
    for (auto x: ans){
        for (auto y: x){
            cout << y << " ";
        }
        cout << endl;
    }
}