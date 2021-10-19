#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> haybale;
    int n=0,k=0,a=0,b=0;
    
    cin>>n>>k;

    vector<int> nums(n,0);
    for(int i=0;i<k;i++){
        cin>>a>>b;
        nums[a-1]++;
        if(b!=n) nums[b]--;
    }
    haybale.push_back(nums[0]);
    for(int j=1;j<n;j++){
        haybale.push_back(nums[j]+haybale[j-1]);
    }
    sort(haybale.begin(),haybale.end());
    int x=(n/2);
    /*
    for(auto& l : haybale){
        cout<<l<<" ";
    }
    */
    cout<<haybale[x];
    return 0;
}