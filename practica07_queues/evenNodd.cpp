#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> arr;
    stack<int> odd;
    int n=0,x=0;
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    for(int i=0; i<n;i++){
        if(arr[i]%2==0){
            cout<<arr[i]<<"\n";
        }
        else odd.push(arr[i]);
    }
    while(!odd.empty()){
        cout<<odd.top()<<"\n";
        odd.pop();
    }
    return 0;
}