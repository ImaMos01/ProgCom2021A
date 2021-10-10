#include <bits/stdc++.h>
using namespace std;
 
void maximumSub(vector<long long>& nums, long long a,long long b){
    set<pair<long long,int>> subArr;
    vector<long long> sums;
	sums.push_back(nums[0]);
	long long sumMax=INT_MIN;
	int s=nums.size();
	for(int i=1;i<s;i++){
		sums.push_back(nums[i]+sums[i-1]);
	}
 
    for(int i=(a-1);i<b;i++){
        subArr.insert({sums[i],i});
    }
	for(int i=0;i<s-a+1;i++){
		sumMax = max(sumMax,subArr.rbegin()->first-sums[i-1]);
		subArr.erase({sums[i+a-1],i+a-1});
		if(i+b<s){
			subArr.insert({sums[i+b],i+b});
		}
	}
 
    cout<<sumMax;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long> nums; 
    long long n=0,x=0,a=0,b=0;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    maximumSub(nums,a,b);
    return 0;
}
