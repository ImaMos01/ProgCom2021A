#include <bits/stdc++.h>
using namespace std;

void TwoValues(vector<pair<int,int>>& nums,int k,int n){
    
    for(int i=0; i<n;i++){
        int p=0,q=n-1;
        while(p!=q){
            int sum=k-nums[i].first;
            if(p!=i && q!=i && nums[p].first+nums[q].first==sum){
                cout << nums[i].second << " " << nums[p].second<< " " << nums[q].second;
                return;
            }
            if(nums[p].first +nums[q].first> sum) q--;
            else p++;
            
        }
    }
	cout << "IMPOSSIBLE";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int,int>> nums; //{(1,1),(10,2),(13,5),...}
    int n=0,x=0,a=0;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a;
        nums.push_back({a,i+1});
    }
    sort(nums.begin(), nums.end());
    TwoValues(nums,x,n);
    return 0;
}