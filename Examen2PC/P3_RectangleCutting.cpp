#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a=0,b=0,cutt=0;
    cin>>a>>b;
    vector<vector<int>> squares(a+1,vector<int>(b+1,0));

    for(int i=1;i<=a;i++){
        for(int j=1; j<=b;j++){
            if(i!=j){
                cutt = INT_MAX;
                for(int k=1;k<j;k++){
                    cutt = min(cutt,1+squares[i][j-k]+squares[i][k]);
                }
                for(int k=1;k<i;k++){
                    cutt = min(cutt,1+squares[i-k][j]+squares[k][j]);
                }  
                squares[i][j]=cutt;
            }
        }
    }
    cout<<squares[a][b];
    return 0;
}