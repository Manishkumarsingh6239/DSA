#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if (s.size()==0) return true;
        stack<char> st;
        for(auto ch: s){
            if(ch=='(' || ch=='{' || ch=='[') st.push(ch);
            else{
                if (st.empty()) return false;
                if(ch==')' && st.top()!='(') return false;
                if(ch==']' && st.top()!='[') return false;
                if(ch=='}' && st.top()!='{') return false;
                st.pop();
        }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    string s = "{[()]}";
    cout << (sol.isValid(s) ? "true" : "false") << endl; // Output: true
    return 0;
}