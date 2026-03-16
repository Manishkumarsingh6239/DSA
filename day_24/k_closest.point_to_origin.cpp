#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int calculateEucdist(int x, int y)
    {
        return x*x+y*y;
    }
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int n = points.size(); 
        priority_queue<pair<int, vector<int>>> pq; 

        for(auto& point : points)
        {
            int x = point[0];
            int y = point[1];

            int dist = calculateEucdist(x,y);

            pq.push({dist,point});
            
            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        vector<vector<int>> result;
        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};

int main(){
    Solution s;
    vector<vector<int>> points = {{1,3},{-2,2}};
    int k = 1;
    vector<vector<int>> result = s.kClosest(points,k);
    for(auto& point:result){
        cout<<"["<<point[0]<<","<<point[1]<<"] ";
    }
}