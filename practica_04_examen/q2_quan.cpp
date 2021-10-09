#include <bits/stdc++.h>
using namespace std;

vector<int> min(vector<char>& dna, vector<int> Q,vector<int> P){
    vector<vector<int>> sums;
    vector<int> nums={0,0,0,0};
    vector<int> rest;

    sums.push_back(nums);
    int n=dna.size();
     
    for(int i=0;i<n;i++){
        switch (dna[i]){
            case 'A':{
                nums[0]++;
                sums.push_back(nums);
                break;
            }
            case 'C':
                nums[1]++;
                sums.push_back(nums);
                break;
            
            case 'G':
                nums[2]++;
                sums.push_back(nums);
                break;
            
            case 'T':
                nums[3]++;
                sums.push_back(nums);
                break;
        }
    }
    
    for(int j=0; j<Q.size(); j++){
    
        vector<int> temp={sums[Q[j]+1][0]-sums[P[j]][0],
            sums[Q[j]+1][1]-sums[P[j]][1],
            sums[Q[j]+1][2]-sums[P[j]][2],
            sums[Q[j]+1][3]-sums[P[j]][3]};
        
        int k=0;
        if(P[j]==Q[j]){
            while(k<4){
                if(temp[k]==1){
                    rest.push_back((k+1));
                    break;
                }   
                k++;  
            }
        }
        else{
            while(k<4){
                if(temp[k]!=0){
                    rest.push_back((k+1));
                    break;
                }   
                k++;  
            } 
        }
       
    }

    return rest;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<char>dna={'C','A','G','C','C','T','A'};
    vector<int> P = {2,5,0};
    vector<int> Q = {4,5,6};

    vector<int> a= min(dna,Q,P);
    
    for(auto i: a){
        cout<<i<<" ";
    }
    return 0;
}