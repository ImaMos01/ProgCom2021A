#include <bits/stdc++.h>
using namespace std;

void slidingCost(vector<int>& nums,int k){
    deque<int> window;
    int n=nums.size();
    for(int i=0;i<n;i++){
        window.push_back(nums[i]);
        if(window.size()==k){
            long long int max=0, min=INT_MAX,med=0,equal=0;
            int j=0;
            if(k<=2){
                med=window[0];
            }
            else{
                while(j<k){
                    if(window[j]>max){
                        med=max;
                        max=window[j];
                    }
                    else if(window[j]<min){
                        med=min;
                        min=window[j];
                    }
                    else {med = window[j];}
                    j++;
                }
            }

            int p=0,q=window.size()-1;
            while(p<q){
                int opc=window[p]-med;
                int opc1=window[q]-med;
                if(opc<0){
                    opc*=-1;
                }
                if(opc1<0){
                    opc1*=-1;
                }
                equal=equal+opc+opc1;
                p++;
                q--;
            }
            cout<<equal<<" ";
            window.pop_front();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> nums; 
    int n=0,k=0,a=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a;
        nums.push_back(a);
    }
    slidingCost(nums,k);
    return 0;
}