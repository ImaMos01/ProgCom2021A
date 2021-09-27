#include <bits/stdc++.h>
using namespace std;

void Square(vector<int>& nums){
    vector<int> fn;
    int temp=0;

    for(int i=0; i<nums.size();i++){
        temp=nums[i];
        if(temp<0){
            temp*=-1;
        }
        temp*=temp;
        fn.push_back(temp);
    }

    //insertion sort
    int k, key, j;
    for (k = 1; k < fn.size(); k++){
        key = fn[k];
        j = k - 1;
        while (j >= 0 && fn[j] > key){
            fn[j + 1] = fn[j];
            j = j - 1;
        }
        fn[j + 1] = key;
    }

    for (k = 0; k < fn.size(); k++)
        cout << fn[k] << " ";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums {-4,-3,1,2,3};
    Square(nums);
    //output(1,4,9,9,16)
    return 0;
}