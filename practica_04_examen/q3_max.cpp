#include <bits/stdc++.h>
using namespace std;

void maximumSub(vector<int>& nums, int a,int b){
    //implementando el algoritmo de kadane
    deque<int> subLenB;
    deque<int> subLenA;
    long long int s=nums.size(),localMaxB=0, globalMax=INT_MIN,lenB=b;
    long long int lenA=a, localMaxA=0;

    for(int i=0;i<s;i++){
        subLenB.push_back(nums[i]);
        subLenA.push_back(nums[i]);
        
        localMaxB=localMaxB+nums[i];
        localMaxA=localMaxA+nums[i];
        
        if(subLenB.size()>=lenB){
            if(globalMax<localMaxB) globalMax=localMaxB;
            localMaxB-=subLenB.front();
            subLenB.pop_front();
        }
        if(subLenA.size()>lenA){
            if(globalMax<localMaxA) globalMax=localMaxA;
            localMaxA-=subLenA.front();
            subLenA.pop_front();
        }
    }
    cout<<globalMax;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums; 
    long long int n=0,x=0,a=0,b=0;
    cin>>n>>a>>b;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    maximumSub(nums,a,b);
    return 0;
}