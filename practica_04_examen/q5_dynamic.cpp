#include <bits/stdc++.h>
using namespace std;

void dynamicRange(vector<long long int>& nums,long long int q){
    vector<long long int> sums;
    long long int opc=0,x=0,y=0;
    sums.push_back(nums[0]);
    for(long long int i=1;i<nums.size();i++){
        sums.push_back(nums[i]+sums[i-1]);
    }

    for(long long int i=0; i<q; i++){
        cin>>opc>>x>>y;
        if(opc==1){
            long long int c=0;
            long long int p=x-1,q=sums.size()-1;
            if(y>nums[x-1]){
                c=y-nums[x-1];
                while(p<q){
                    sums[p]+=c;
                    sums[q]+=c;
                    p++;
                    q--;
                    if(p==q){
                        sums[p]+=c;
                    }
                }
            }
            else if(y<nums[x-1]){
                c=nums[x-1]-y;
                while(p<q){
                    sums[p]-=c;
                    sums[q]-=c;
                    p++;
                    q--;
                    if(p==q){
                        sums[p]-=c;
                    }
                }
            }
            nums[x-1]=y;
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
    long long int n=0,x=0,q=0;
    cin>>n>>q;
    for(long long int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    dynamicRange(nums,q);
 
    return 0;
}