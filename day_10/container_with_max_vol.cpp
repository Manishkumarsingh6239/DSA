#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0, l=0, r=height.size()-1;
        while(l<r){
            int curr_area = min(height[l],height[r])*(r-l);
            max_area = max(max_area,curr_area);

            height[l]>height[r] ? r-- : l++;
        }
        
        return max_area;
    }
};