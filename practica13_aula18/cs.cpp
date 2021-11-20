#include <bits/stdc++.h>
using namespace std;

void dfs (vector<vector<char>>& image,int r1,int s1){
    if(r1<0 || r1>=image.size() || s1<0 || s1>=image[r1].size() ||image[r1][s1]!='-'){
        return;
    }

    image[r1][s1]='#';
    dfs(image, r1+1, s1);
    dfs(image, r1-1, s1);
    dfs(image, r1, s1+1);
    dfs(image, r1, s1-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m=0,n=0;
    char a;
    int id=1;
    while(cin>>m>>n){
        int cont=0;
        vector<vector<char>>stars;

        for(int i=0;i<m;i++){
            vector<char> op;
            for(int j=0; j<n;j++){
                cin>>a;
                op.push_back(a);
            }
            stars.push_back(op);
        }
        for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
                if(stars[i][j]=='-'){
                    dfs(stars,i,j);
                    cont++;
                }
            }
        }
        cout<<"Case "<<id<<": "<<cont<<"\n";
        id++;
    }
}