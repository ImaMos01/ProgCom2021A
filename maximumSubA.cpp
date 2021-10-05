#include <bits/stdc++.h>
using namespace std;

void maximumSub(vector<int>& nums){
    //implementando el algoritmo de kadane
    long long int s=nums.size(),localMax=0, globalMax=INT_MIN;

    for(int i=0;i<s;i++){
        
        localMax=localMax+nums[i];
        
        if(globalMax<localMax) globalMax=localMax;
        if(localMax<=0)localMax=0;
    }
    cout<<globalMax;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums; 
    int n=0,a=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        nums.push_back(a);
    }
    maximumSub(nums);
    return 0;
}