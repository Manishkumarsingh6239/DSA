#include <bits/stdc++.h>
using namespace std;
// int calc_mean(vector<int> arr){
// 	return (arr[0]+arr[1]+arr[2])/3;
// }
int main()
{    
    int number;
    cin >> number;
		vector<int> arr;
		for(int i=0;i<number;i++){
			int ip;
			cin >> ip;
			arr.push_back(ip);
		}
	int minabs=INT_MAX;
    sort(arr.begin(),arr.end());
	for(int i=7;i<(1<<number);i++){
		vector<int> helper;
		int len=0;
		for(int j=0;j<number;j++){
			if(i&1<<j){
				helper.push_back(arr[j]);
			}
		}
		if(helper.size()==3){
			// minabs=min(minabs,abs(calc_mean(helper)-helper[1]));

			// int sum = helper[0]+helper[1]+helper[2];
			// minabs= min(minabs,abs(sum-3*helper[1]));

			minabs=min(minabs,abs(helper[0]+helper[2]-2*helper[1]));
		}
	}
	cout<<minabs<<endl;
    return 0;
}

