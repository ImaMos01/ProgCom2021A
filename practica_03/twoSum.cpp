#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums,int target){
    unordered_map<int,int> subNums;
    vector<int> fin;
    int equalMin=0; 
    for(int i=0;i<nums.size();i++){
        equalMin=target-nums[i];
        auto opc = subNums.find(nums[i]);
        if(opc!=subNums.end()){
            fin.push_back(opc->second);
            fin.push_back(i);
        }
        subNums.insert({equalMin,i});
    }
    return fin;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums; 
    int n=0,x=0,a=0;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a;
    }
    vector<int> outt = twoSum(nums,x);
    for(auto l : outt) cout<<l<<" ";
    return 0;
}