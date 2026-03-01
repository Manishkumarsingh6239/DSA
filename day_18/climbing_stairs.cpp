#include <iostream>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        int a=0,b=1;
        for(int i=0;i<n-1;i++){
            int temp=b;
            b+=a;
            a=temp;
        }
        return a+b;
    }
};

int main(){
    Solution s;
    cout<<s.climbStairs(5);
}