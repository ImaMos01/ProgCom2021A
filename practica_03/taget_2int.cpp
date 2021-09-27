#include <bits/stdc++.h>
using namespace std;

//ordenados
void two_integers(vector<int>& nums,int k){
    int tam = nums.size();
    int pos[2]={0,0};
    int mayor=0;
    
    for(int i=tam-1; i>=0;i--){
        if(nums[i]<k){
            if(nums[i]>mayor){
                mayor=nums[i];
                pos[1]=i;   
            }
            if(mayor+nums[i]==k){
                pos[0]=i;
            }
        }
    }
    std::cout<<"["<<pos[0]<<", "<<pos[1]<<"] positions\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums {1,2,7,9,11,15};
    two_integers(nums,11);
    vector<int> nums1 {-1,1,2,3,5};
    two_integers(nums1,5);
    return 0;
}