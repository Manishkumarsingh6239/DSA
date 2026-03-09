#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> map;
        int start=0,end=0;
        int res=INT_MIN;
        while(end<fruits.size()){
            map[fruits[end++]]++;

            while(map.size()>2){
                if(map[fruits[start++]]--==1){
                    map.erase(fruits[start-1]);
                }
            }
            res=max(res,end-start+1);
        }
        return res-1;
    }
};

int main(){
    Solution s;
    vector<int> fruits={1,2,1};
    cout<<s.totalFruit(fruits);
}