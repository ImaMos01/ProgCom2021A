#include <bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums,int k){
    
}
/*
int arrays(vector<int>& nums,int tam,int k){
    int cont=0,i=0,f=0,sumTem=0;
    while(i<nums.size()-(tam-1)){
        f=i+tam;
        sumTem=0;
        for(int j=i;j<f;j++){
            sumTem+=nums[j];
        }
        if(sumTem%k==0){
            cont++;
        }
        i++;
    }
    return cont;
}

int sub_array(vector<int>& nums,int k){
    int suba=0;
    for(int i=0; i<nums.size();i++){
        suba+=arrays(nums,i+1,k);
    }
    
    return suba;
}
*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums{4,5,0,-2,-3,1};
    int k=5;
    //int out=sub_array(nums,k);
    //std::cout<<out<<"\n";

    return 0;
}