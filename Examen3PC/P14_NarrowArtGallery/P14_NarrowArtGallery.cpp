#include <bits/stdc++.h>
using namespace std;

int x=0,y=0;
vector<vector<int>> arr(201,vector<int>(2));

vector<vector<vector<int>>> gall(201,(vector<vector<int>>(3,vector<int>(201,INT_MIN))));

int dfs(){
    gall[0][0][0]=arr[0][0]+arr[0][1];
    gall[0][1][1]=arr[0][1];
    gall[0][2][1]=arr[0][0];
    for(int i=1;i<x;i++){
        for(int j=0;j<=y;j++){
            int f=max(gall[i-1][1][j],gall[i-1][2][j]);
            gall[i][0][j]=max(gall[i-1][0][j],f)+arr[i][0]+arr[i][1];
            if(j==0){
                gall[i][1][j]=gall[i][2][j]=INT_MIN;
            }
            else{
                gall[i][1][j]=max(gall[i-1][0][j-1],gall[i-1][1][j-1])+arr[i][1];
				gall[i][2][j]=max(gall[i-1][0][j-1],gall[i-1][2][j-1])+arr[i][0];
            }
        }
    }
    int op=max(gall[x-1][1][y],gall[x-1][2][y]);
    return max(gall[x-1][0][y],op);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int id=0,tot=0;
    while(cin>>x>>y){
        if(x==y && y==0) break;
        
        for(int i=0; i<x;i++){
            cin>>arr[i][0]>>arr[i][1];
        }
        cout<<dfs()<<"\n";
    }
    
    return 0;
}
