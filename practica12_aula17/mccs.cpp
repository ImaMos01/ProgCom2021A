#include <bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    cost.push_back(0);
    int n=cost.size();
    for(int i=n-3;i>=0;i--){
        cost[i]+=min(cost[i+1],cost[i+2]);
    } 
    return min(cost[0],cost[1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a={10,15,20};
    cout<<minCostClimbingStairs(a);

    return 0;
}