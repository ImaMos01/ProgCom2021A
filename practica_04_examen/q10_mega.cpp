#include <bits/stdc++.h>
using namespace std;

void destroy(vector<long long int>& nums,int p,long long int m){
    long long sum=0,planets=0, min=INT_MAX;
    long long finPla=0,j=0;

    for(int i=0; i<p;i++){
        sum+=nums[i];
        planets++;
        if((sum<min && planets==finPla)||(planets>finPla && sum<=m)){
            finPla=planets;
            min=sum;
        }
        while(sum>m){
            planets--;
            sum-=nums[j];
            j++;
        }
   
        if((sum<min && planets==finPla)||(planets>finPla && sum<=m)){
            finPla=planets;
            min=sum;
        }
  
    }
    printf("%lld %lld\n", min, finPla);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=0,x=0,p=0;
    long long int m;
    cin>>t;
    while(t!=0){
        vector<long long int> nums; 
        cin>>p>>m;
        for(int i=0;i<p;i++){
            cin>>x;
            nums.push_back(x);
        }
        destroy(nums,p,m);
        t--;
    }
 
    return 0;
}