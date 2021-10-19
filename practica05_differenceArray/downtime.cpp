#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=0,k=0,t=0,cont=0;
    long long max=0;
    map<long long,long long> nums;
    cin>>n>>k;
    
    for(int i=0;i<n;i++){
        cin>>t;
        if(nums[t]!=0){
            nums[t]++;
        }
        else{
            nums[t]=1;
        }

        if(nums[t+1000]!=0){
            nums[t+1000]--;
        }
        else{
            nums[t+1000]=-1;
        }
    }

    vector<long long> acc;
    acc.push_back(0); 
    
    for (map<long long,long long>::iterator it=nums.begin(); it!=nums.end(); ++it){
        acc.push_back(it->second + acc[cont]);
        cont++;
        if(acc[cont]>max){
            max=acc[cont];
        }
    }
    
    if(max < k){
        cout<<1<<"\n";
    }
    else{
        if(max%k==0){
            cout<<max/k<<"\n";
        }
        else{
            cout<<(max/k)+1<<"\n";
        }
    }
    return 0;
}
/*
7 2 
1000
1010
1500
1999
2000
2010
2999
*/