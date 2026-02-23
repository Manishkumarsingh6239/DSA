#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color) return image;

        queue<pair<int,int>> q;
        int delta_row[]={-1,0,1,0};
        int delta_col[]={0,1,0,-1};
        int starting_color = image[sr][sc];
        int m = image.size();
        int n = image[0].size();

        q.push({sr,sc});
        image[sr][sc]=color;

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+delta_row[i];
                int ncol=col+delta_col[i];

                if(nrow<m && nrow>=0 && ncol<n && ncol>=0 && image[nrow][ncol]==starting_color){
                    image[nrow][ncol]=color;
                    q.push({nrow,ncol});
                }
            }
        }

        return image;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    int sr = 1, sc = 1, color = 2;
    vector<vector<int>> result = sol.floodFill(image, sr, sc, color);
    
    cout << "Flood filled image:" << endl;
    for (const auto& row : result) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }
    
    return 0;
}