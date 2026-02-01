
#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size()!=t.size()) return false;

        unordered_map<char,int> mp;
        for (auto ch : s) mp[ch]++;
        for (auto ch : t) mp[ch]--;

        for (auto it : mp){
            if(it.second!=0) return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    bool result = sol.isAnagram(s, t);
    cout << (result ? "Anagrams" : "Not Anagrams") << endl;
    return 0;
}