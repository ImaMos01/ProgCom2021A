#include <bits/stdc++.h>
using namespace std;
char arr[1000][1001];
pair<int,int> BFS[1000000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cas,cs,wd,h,i,j,i2,j2,d,crr,l,ds,sc;
    int x[4]={0,0,1,-1},y[4]={1,-1,0,0};
    bool opc;
    pair<int,int> start,loc;
    cin>>cas;
    for (cs=1;cs<=cas;cs++){
        cin>>wd>>h;
        for(int i=0;i<h;i++){
            cin>>arr[i];
        }
        l=0;
        for(i=0;i<h;i++){
            for(j=0;j<wd;j++){
                if(arr[i][j]=='*') {
                    BFS[l++]=make_pair(i,j);
                }
                else if(arr[i][j]=='@') {
                    start=make_pair(i,j);
                }
            }
        }
        ds=0;
        BFS[l++]=start;
        sc=l;
        opc=false;
        for(crr=0;!opc && crr<l;crr++){
            if(crr==sc){
                sc=l;
                ds++;
            }
            loc=BFS[crr];
            j=loc.second;
            i=loc.first;
            for(d=0;d<4;d++){
                i2=i+x[d];
                j2=j+y[d];
                if(i2<0 || i2>=h || j2<0||j2>=wd){
                    if(arr[i][j]=='@'){ 
                        opc=true;
                    }
                }
                else if(arr[i2][j2]=='.'){
                    arr[i2][j2]=arr[i][j];
                    BFS[l++]=make_pair(i2,j2);
                }
            }
        }
        if(opc){ 
            cout<<ds+1<<"\n";
        }
        else {
            cout<<"IMPOSSIBLE\n";
        }
    }

    return 0;
}
