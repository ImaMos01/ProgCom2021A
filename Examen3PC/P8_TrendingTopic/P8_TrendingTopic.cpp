#include <bits/stdc++.h>

using namespace std;

class obj{
    public:
    string word;
    int time;
} Ob[20001];

string text;
string wma[20001];
vector<bool> vis;
int arr[20001];
vector<int> y[11];
vector<vector<int>> ds(11,vector<int>(20001));
map<string,int> rep;

bool comp(obj x, obj y){
    if(x.time!=y.time){
        return x.time>y.time;
    }
    else{
        return x.word<y.word;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=0,n=9,p=0,id=1,cont=0,s=0,r=0;
    while(cin>>text){
        if(text=="<text>"){
            p=n;
            n=(n+1)%10;
            y[n]=y[p];
            ds[n]=ds[p];
            while(cin>>text){
                if(text[0]=='<')break;
                if(text.length()<4) continue;
                if(rep[text]==0){
                    wma[id]=text;
                    rep[text]=id;
                    id++;
                }
                int temp=rep[text];
                if(ds[p][temp]==0){
                    y[n].push_back(temp);
                }
                ds[n][temp]++;
            }
        }
        else if(text=="<top"){
            cin>>t>>text;
            int tam=y[n].size();
            cont=0;
            int days=(n+3)%10;
            vis.assign(20001,false);
            for(int i=0; i<tam;i++){
                if(vis[y[n][i]]==false){
                    arr[cont]=ds[n][y[n][i]]-ds[days][y[n][i]];
                    vis[y[n][i]]=true;
                    cont++;
                }
            }
            sort(arr,arr+cont);
            s=arr[max(0,cont-t)];
            r=0;
            vis.assign(20001,false);
            for(int i=0; i<tam;i++){
                int temp=ds[n][y[n][i]]-ds[days][y[n][i]];
                if(temp>=s && vis[y[n][i]]==false){
                    Ob[r].time=temp;
                    Ob[r].word=wma[y[n][i]];
                    vis[y[n][i]]=true;
                    r++;
                }
            }
            sort(Ob,Ob+r,comp);
            cout<<"<top "<<t<<">\n";
            for(int i=0; i<r;i++){
                cout<<Ob[i].word<<" "<<Ob[i].time<<"\n";
            }
            cout<<"</top>\n";
        }
    }
    return 0;
}