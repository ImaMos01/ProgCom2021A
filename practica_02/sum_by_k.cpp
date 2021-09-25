#include <bits/stdc++.h>
using namespace std;

int subarraysSum(vector<int>& nums,int k){
    int cont=0;
    vector<int> sum = nums;
    for(int i=0; i<nums.size();i++){
        if(i==0);
        else sum[i]+=sum[i-1];
        
        if(sum[i]==k)cont++;
        int acu=0,temp=sum[i];
        while(acu<i){
            temp-=nums[acu];
            if(temp==k) cont++;
            acu++;
        }
    }
    return cont;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums{4,5,0,-2,-3,1};
    int k=5;
    //int out=sub_array(nums,k);
    //std::cout<<out<<"\n";

    return 0;
}
