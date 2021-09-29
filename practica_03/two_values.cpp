#include <bits/stdc++.h>
using namespace std;

void TwoValues(vector<pair<int,int>>& nums,int k){
    int i = 0, j = n - 1;
	
	while (i < j) {
		// adjust left and right pointers.
		if(nums[i].first + nums[j].first > k)
			j--;
		else if (nums[i].first + nums[j].first < k)
			i++;
		else if (nums[i].first + nums[j].first == k) {
			cout << nums[i].second << " " << nums[j].second;
			return;
		}
	}
	cout << "IMPOSSIBLE" << endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<pair<int,int>> nums; //implementamos un vector de pares
    int n=0,x=0,a=0;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a;
        nums.push_back({a,i+1});
    }
    sort(nums.begin(), nums.end()); //ordenamos el vector
    TwoValues(nums,x);
    return 0;
}
