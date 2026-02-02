#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string ns;
        for(auto ch : s){
            if(isalnum(ch)){
                ns+=tolower(ch);
            }
        }
        int n = ns.size();
        cout<<ns<<endl<<n<<endl;
        if(ns.size()==0) return true;
        
        for(int i=0; i<=n/2; i++){
            if(ns[i]!=ns[n-i-1]) return false;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isPalindrome(string s) {
//        int start=0;
//        int end=s.size()-1;
//        while(start<=end){
//            if(!isalnum(s[start])){start++; continue;}
//            if(!isalnum(s[end])){end--;continue;}
//            if(tolower(s[start])!=tolower(s[end]))return false;
//            else{
//                start++;
//                end--;
//            }
//        }
//        return true;
// }
// };

int main(){
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    bool result = sol.isPalindrome(s);
    cout << "Is Palindrome: " << (result ? "true" : "false") << endl;
    return 0;
}