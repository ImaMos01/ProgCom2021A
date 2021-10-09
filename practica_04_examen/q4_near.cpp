#include <bits/stdc++.h>
using namespace std;

void nearestSmaller(vector<int>& nums){
    stack<pair<int,int>> small;
    int n=nums.size();
    for(int i=0; i<n;i++){
        while(!small.empty() && small.top().first>=nums[i]){
            small.pop();
        }
        if(small.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<small.top().second<<" ";
        }
        small.push({nums[i],i+1});
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums; 
    long long int n=0,x=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    nearestSmaller(nums);
    return 0;
}