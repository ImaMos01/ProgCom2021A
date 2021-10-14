#include <bits/stdc++.h>
using namespace std;

int minAvg(vector<int>& A){
    int n=A.size();
    int ind = -1, minsum = INT_MAX;
    int ind0 = -1, minsum0=INT_MAX;

    for(int i=0;i<n-1;i++){
        int val0=A[i],val1=A[i+1];
        int sum=val0+val1;
        if(sum<minsum){
            minsum=sum;
            ind=i;
        }
        if(i<n-2){
            int val2 = A[i+2];
            int sum1 = val0+val1+val2;
            if(sum1<minsum0){
                minsum0=sum1;
                ind0 = i;
            }
        }
    }
    if(ind0 == -1){
        return ind;
    }
    double a = minsum/.2;
    double b = minsum0/.3;

    if(a<b){
        return ind;
    }
    if(a>b){
        return ind0;
    }
    return min(ind0,ind);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums; 
    int n=0,x=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        nums.push_back(x);
    }
    return 0;
}
