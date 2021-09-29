//maximum sum od any contigous subarray of size k
#include <bits/stdc++.h>
using namespace std;

void maxSum(vector<int>& nums,int k){
    queue<int> sum;
    int sm=0,mayor=0;
    for(int i=0; i<nums.size();i++){
        sum.push(nums[i]);
        sm+=nums[i];
        if(sum.size()>k){
            sm-=sum.front();
            sum.pop();
        }
        if(sum.size()==k){
            if(sm>mayor) mayor=sm;
        }
    }
    cout<<mayor;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums {2,3,4,1,5}; //10
    int k=3;
    maxSum(nums,k);
    return 0;
}