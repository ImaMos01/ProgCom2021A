#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n=nums.size();
    if(n<=1){
        return n;
    }
    int cont=-1;      
    vector<int> sum(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                sum[i] = max(sum[i],sum[j]+1);
            }
        }
        cont=max(cont,sum[i]);
    }
    return cont;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}