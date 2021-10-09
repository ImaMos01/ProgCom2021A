#include <bits/stdc++.h>
using namespace std;

int minAvg(vector<int>& nums){
    double pre = (nums[0]+nums[1])/2;
    int in=0;
    double min=pre;
    int outt=in;
    for(int i=2;i<nums.size();i++){
        double curr=(pre*(i-in)+nums[i])/(i-in+1);
        if(nums[i]+nums[i-1]>=curr*2){
            pre=curr;
        }
        else{
            pre=(nums[i]+nums[i-1])/2;
            in=i-1;
        }
        if(pre<min){
            min=pre;
            outt=in;
        }
    }
    return outt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums; 
    int n=0,x=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    return 0;
}