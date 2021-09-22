#include <bits/stdc++.h>
using namespace std;

int findMiddleIndex(vector<int>& nums){
    int tam = nums.size();
    int sumTotal=0, sumTem=0, midd=0;
    
    for(int i=0; i<tam;i++){
        sumTotal+=nums[i];
    }
    for(int i=0; i<tam;i++){
        if(sumTem==sumTotal-sumTem-nums[i]){
            return i;
        }
        sumTem+=nums[i];
    }
    return -1;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int middle=0;
    //caso 1:
    //Entrada: 2,3,-1,8,4
    //Salida 3
    vector<int> nums {2,3,-1,8,4};
    middle=findMiddleIndex(nums);
    cout<<middle<<"\n";

    //caso 2:
    //Entrada: 1,-1,4
    //Salida 2
    vector<int> nums1 {1,-1,4};
    middle=findMiddleIndex(nums1);
    cout<<middle<<"\n";

    //caso 3:
    //Entrada: 2,5
    //Salida -1
    vector<int> nums2 {2,5};
    middle=findMiddleIndex(nums2);
    cout<<middle<<"\n";
    return 0;
}