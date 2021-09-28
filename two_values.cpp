#include <bits/stdc++.h>
using namespace std;

void TwoValues(vector<int>& nums,int k){
    bool isValues=false;
    int mayor=0,m=0,p=0,q=nums.size()-1;
    for(int i=0; i<nums.size();i++){
        if(nums[i]>mayor && nums[i]<k){
            mayor=nums[i];
            m=i;
        }
    }

    while(p<q){
        if(p==m) p++;
        if(q==m) q--;
        
        if(nums[p]+nums[m]==k){
            if(p>m) cout<<m+1<<" "<<p+1<<"\n";
            else cout<<p+1<<" "<<m+1<<"\n";
            isValues=true;
        }
        if(nums[q]+nums[m]==k){
            if(q>m) cout<<m+1<<" "<<q+1<<"\n";
            else cout<<q+1<<" "<<m+1<<"\n";
            isValues=true;
        }
        if(nums[p]+nums[q]==k){
            if(p>q) cout<<q+1<<" "<<p+1<<"\n";
            else cout<<p+1<<" "<<q+1<<"\n";
            isValues=true;
        }
        if(nums[p]>nums[q]){
            q--;
        }
        else p++;
    }
    if(!isValues) cout<<"IMPOSSIBLE\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums;
    int n=0,x=0,a=0;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a;
        nums.push_back(a);
    }
    TwoValues(nums,x);
    return 0;
}