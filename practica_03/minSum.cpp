//size of the smallest contigous subarray with a sum greater than or equal to S
#include <bits/stdc++.h>
using namespace std;

void smallSize(vector<int>& nums,int k){
    queue<int> sum;
    int sm=0, minSize=nums.size();
    for(int i=0; i<nums.size();i++){
        sum.push(nums[i]);
        sm+=nums[i];
        if(sm>k){
            sm-=sum.front();
            sum.pop();
        }
        if(sm==k){
            if(sum.size()<minSize) minSize=sum.size();
        }
    }
    if(minSize==nums.size()){
        cout<<"No exist";
    }
    else cout<<minSize;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums {2,4,2,5,1}; //2
    int k=7;
    smallSize(nums,k);
    return 0;
}