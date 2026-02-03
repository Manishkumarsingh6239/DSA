#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
 int characterReplacement(string s, int k) {
    int n = s.size();
    int l = 0;
    int maxi = 0;
    int maxfreq = 0;
    int hash[26] ={0};

    for (int r = 0; r < n; r++) {
        hash[s[r] - 'A']++;
        maxfreq = max(maxfreq, hash[s[r] - 'A']);

        if ((r - l + 1 - maxfreq) > k) {
            hash[s[l] - 'A']--;
            l++;
        }

        maxi = max(maxi, r - l + 1);
    }

    return maxi;
    }
};

int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 2;
    cout << sol.characterReplacement(s, k) << endl; // Output: 5
    return 0;
}