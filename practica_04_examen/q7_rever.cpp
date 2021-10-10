#include <bits/stdc++.h>
using namespace std;

void reverSum(vector<long long int>& nums,long long int m){
    vector<long long int> sums;
    long long int n=nums.size(), opc=0,x=0,y=0;
    sums.push_back(nums[0]);

    for(long long int i=1;i<n;i++){
        sums.push_back(nums[i]+sums[i-1]);
    }

    for(long long int i=0; i<m; i++){
        cin>>opc>>x>>y;
        if(opc==1){
            long long int p=x-1, q=y-1,c=0;
            while(p<q){ 
                int tem=nums[p];
                nums[p]=nums[q];
                nums[q]=tem;

                sums[p]=nums[p]+sums[p-1];
                
                p++;
                q--;
            }
            for(int j=p;j<n;j++){
                sums[j]=nums[j]+sums[j-1];
            }
        }
        else{
            long long int sum=0;
            if(x==y){
            sum=nums[x-1];
            }
            else if(x>=2){
                sum=sums[y-1]-sums[x-2];
            }
            else if(x==1){
                sum=sums[y-1];
            }
            cout<<sum<<"\n";

        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<long long int> nums; 
    long long int n=0,x=0,m=0;
    cin>>n>>m;
    for(long long int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    reverSum(nums,m);
 
    return 0;
}
