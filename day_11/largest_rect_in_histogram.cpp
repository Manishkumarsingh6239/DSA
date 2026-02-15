#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        int maxArea = 0;
        int n = h.size();

        for(int i = 0; i < n; i++) {
            while(!st.empty() && h[i] < h[st.top()]) {
                int element = st.top();
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                int width = i - pse - 1;
                maxArea = max(maxArea, h[element] * width);
            }
            st.push(i);
        }

        while(!st.empty()) {
            int element = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            int width = n - pse - 1;
            maxArea = max(maxArea, h[element] * width);
        }

        return maxArea;
    }
};
