#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    vector<vector<int>> fin;
    sort(nums.begin(),nums.end());
    
    if(nums.size()<3) return{};
    
    for (int i = 0; i < nums.size(); i++){
        if(i==0 || nums[i-1]!=nums[i]){
            int j = i + 1, k = nums.size() - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                } else if (sum > 0) {
                    k--;
                } else {
                    fin.push_back({nums[i], nums[j], nums[k]});
                    while ((j + 1) < nums.size() && nums[j] == nums[j+1]) j++;
                    j++;
                    while ((k - 1) >= 0 && nums[k] == nums[k - 1]) k--;
                    k--;
                }
            }
        }
    }
    
    return fin;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums; 
    int n=0,x=0,a=0;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a;
    }
    vector<vector<int>> outt = threeSum(nums);
    for (int i = 0; i < outt.size(); i++){
        for (int j = 0; j < outt[i].size(); j++)
        {
            cout << outt[i][j] << " ";
        }   
        cout << "\n";
    }
    return 0;
}