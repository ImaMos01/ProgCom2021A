#include <bits/stdc++.h>
using namespace std;

int n=0;
double l,w;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    while(cin>>n>>l>>w){
        int r=0,x=0,m=0;

        vector<pair<double,double>> sprink;

        for(int i=0; i<n;i++){
            cin>>x>>r;
            if(2*r<=w)continue;
            double temp=sqrt(r*r-w*w/4);
            sprink.push_back(make_pair((x-temp),(x+temp)));
            m++;
        }
        sort(sprink.begin(),sprink.end());

        int j=0, ans=0, flg=0;
        if(sprink[0].first>0){
            cout<<"-1\n";
            continue;
        }
        double p=0,q=0;
        while(j<m){
            int k=j;
            while(k<m && p>sprink[k].first){
                if(sprink[k].second > q){
                    q=sprink[k].second;
                }
                k++;
            }
            if(k==j) break;
            ans++;
            p=q;
            j=k;
            if(p>l){
                flg=1;
                break;
            }
        }
        if(flg){
                cout<<ans<<"\n";
            }
        else{
            cout<<"-1\n";
        }
    }
    return 0;
}

